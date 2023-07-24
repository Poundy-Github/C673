/*****************************************************************************/
/*                            Target Test Script                            */
/*****************************************************************************/
/*
*    Filename: test_cml_exp.cpp
*    Author: uid22555
*    Generated on: 09-Feb-2018 
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
extern float32 CML_f_PowToDB(float32 f_ratio);
extern float32 GDBexp_power(float32 f_base, uint32 u_power);
extern float32 GDBexp_100s(float32 f_power);
extern float32 GDBexp_100(float32 f_power);
extern float32 GDBexp(float32 f_power);
extern float32 CML_f_fastlog10(float32 f_value);
extern float32 CML_f_fastlog(float32 f_value);
extern float32 CML_f_PowerOfTwo(float32 f_value);
extern float32 CML_f_XPowY(const float32 f_Base, const float32 f_Exponent);

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
class TEST_CLASS_CML_EXP
{
public:
    
    /* Prototypes for test functions */
    void run_tests_cml_exp();
    void test_GDBexp_power(int);
    void test_GDBexp_100s(int);
    void test_GDBexp_100(int);
    void test_GDBexp(int);
    void test_CML_f_fastlog10(int);
    void test_CML_f_XPowY(int); 
    void test_CML_f_PowerOfTwo(int); 
    void test_CML_f_PowToDB(int);
    void test_CML_f_MagToDB(int);
    void test_CML_f_fastlog(int); 
    void test_CML_f_log10(int); 
    void test_CML_f_log2(int);
    void test_CML_f_ln(int); 
    void test_CML_Exp_VeryFast(int);
    void test_CML_Ln_VeryFast(int);
    
};
/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_exp(void)
       {
    TEST_CLASS_CML_EXP test_object;

    std::cout << "******** Start Testing: CML Exp functions ********\n\n";
    fprintf(fpTest, "******** Start Testing: CML Exp functions ********\n\n");

    test_object.run_tests_cml_exp();

    std::cout << "End of Testing: CML Exp functions\n\n";
    fprintf(fpTest, "End of Testing: CML Exp functions\n\n");

    return;

}

/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS_CML_EXP::run_tests_cml_exp()
{
    test_GDBexp(1);
    test_GDBexp_power(1);
    //test_GDBexp_100s(1);
    test_GDBexp_100(1);	   
    test_CML_Ln_VeryFast(1);
    test_CML_Exp_VeryFast(1);
    test_CML_f_MagToDB(1);
    test_CML_f_PowToDB(1);
    test_CML_f_fastlog(1);
    test_CML_f_fastlog10(1);
    test_CML_f_log10(1);
    test_CML_f_log2(1);
    test_CML_f_ln(1);	
    test_CML_f_PowerOfTwo(1);
    test_CML_f_XPowY(1);
 
}

/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/

void TEST_CLASS_CML_EXP::test_GDBexp(int doIt)
{
    if (doIt) 
    {
        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_GDBexp_1   "test_001_GDBexp_out_target.csv"
        #define TEST_CML_VECTOR_CSVOUT_GDBexp_2   "test_002_GDBexp_out_target.csv"
#else		
        #define TEST_CML_VECTOR_CSVOUT_GDBexp_1   "test_001_GDBexp_out_msvc.csv"
        #define TEST_CML_VECTOR_CSVOUT_GDBexp_2   "test_002_GDBexp_out_msvc.csv"
#endif

        csv_data_float_t *current_p_CsvDataOut = NULL;
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDBexp_1, "w+");
        float32 f_angle;

        float32 f_power;
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
        for ( f_angle = -1; f_angle <= 1; f_angle += 0.0001)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);
            *(temp_p_CsvDataOut->value) = GDBexp(f_angle);
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
        std::cout << "GDBexp Test case 1 \n";		
        fprintf(fpTest, "GDBexp Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

        for ( f_angle = -1; f_angle <= 1; f_angle += 0.0001)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);
            float32 ref_fout = exp(f_angle);
    
#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
            float32 test_out = GDBexp(f_angle);

#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
        p_CsvDataOut.value[dataIndex]  = test_out;
        float32 abs_err = abs(ref_fout - test_out);
        rel_err = abs(abs_err/ref_fout);
        if (rel_err >= max_err)
        {
            max_err = rel_err;
            input_err = f_angle;
        }
#ifdef ENABLE_PROFILER
        fprintf(fpTest, "GDBexp ---> ");
        fprintf(fpTest, "Test case 1 ---> ");
        total_cycles = stop_clock - start_clock - overhead;
        check__PrintValue_to_File(f_angle, fpTest);
        fprintf(fpTest, "\t");
        check__PrintValue_to_File(total_cycles, fpTest);
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
        fp = fopen (TEST_CML_VECTOR_CSVOUT_GDBexp_2, "w+");

#ifdef LINKED_LIST_PARSER
        p_CsvDataOut = NULL;
        for ( f_angle = -100; f_angle <= 75; f_angle += 1)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);
            *(temp_p_CsvDataOut->value) = GDBexp(f_angle);
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
        std::cout << "GDBexp Test case 2 \n";		
        fprintf(fpTest, "GDBexp Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */
        for ( f_angle = -100; f_angle <= 75; f_angle += 1)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            p_CsvDataOut.value[dataIndex] = GDBexp(f_angle);

#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
        fprintf(fpTest, "GDBexp ---> ");
        fprintf(fpTest, "Test case 2 ---> ");
        total_cycles = stop_clock - start_clock - overhead;
        check__PrintValue_to_File(f_angle, fpTest);
        fprintf(fpTest, "\t");
        check__PrintValue_to_File(total_cycles, fpTest);
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


void TEST_CLASS_CML_EXP::test_GDBexp_100(int doIt)
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
        float32 f_power;
        float32 expected_returnValue;
        float32 returnValue;
        float32 tolerance = 0.00001f;
        uint8 index;
        
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_GDBexp_100_TestCase_1  "test_001_GDBexp_100_out_target.csv"
        #define TEST_CML_VECTOR_CSVOUT_GDBexp_100_TestCase_2  "test_002_GDBexp_100_out_target.csv"
#else
        #define TEST_CML_VECTOR_CSVOUT_GDBexp_100_TestCase_1  "test_001_GDBexp_100_out_msvc.csv"
        #define TEST_CML_VECTOR_CSVOUT_GDBexp_100_TestCase_2  "test_002_GDBexp_100_out_msvc.csv"
#endif

        csv_data_float_t *current_p_CsvDataOut = NULL;
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDBexp_100_TestCase_1, "w+");
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
            *(temp_p_CsvDataOut->value) = GDBexp_100(f_angle);
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
        std::cout << "GDBexp_100 Test case 1 \n";		
        fprintf(fpTest, "GDBexp_100 Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

    for ( f_angle = -1; f_angle <= 1; f_angle += 0.0001F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);

            float32 ref_fout = exp(f_angle);
#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

        float32 test_out = GDBexp_100(f_angle);

#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

        p_CsvDataOut.value[dataIndex] = test_out;

        float32 abs_err = abs(ref_fout - test_out);
        rel_err = abs(abs_err/ref_fout);
        if (rel_err >= max_err)
        {
            max_err = rel_err;
            input_err = f_angle;
        }

#ifdef ENABLE_PROFILER
        fprintf(fpTest, "GDBexp_100 ---> ");
        fprintf(fpTest, "Test case 1 ---> ");
        total_cycles = stop_clock - start_clock - overhead;
        check__PrintValue_to_File(f_angle, fpTest);
        fprintf(fpTest, "\t"); 
        check__PrintValue_to_File(total_cycles, fpTest);
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
        fp = fopen (TEST_CML_VECTOR_CSVOUT_GDBexp_100_TestCase_2, "w+");

#ifdef LINKED_LIST_PARSER
        p_CsvDataOut = NULL;
        for ( f_angle = -100; f_angle <= 75; f_angle += 1)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);
            *(temp_p_CsvDataOut->value) = GDBexp_100(f_angle);
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
        std::cout << "GDBexp_100 Test case 2 \n";		
        fprintf(fpTest, "GDBexp_100 Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */
        /* The test range is limited such that e^x should not cross the range of single precision floating point which is 3.4e38f   */
        for ( f_angle = -86.95F; f_angle <= 88.7F; f_angle += 1.0F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);

            float32 ref_fout = exp(f_angle);
#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

        float32 test_out = GDBexp_100(f_angle);

#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
        p_CsvDataOut.value[dataIndex] = test_out;

        float32 abs_err = abs(ref_fout - test_out);
        rel_err = abs(abs_err/ref_fout);
        if (rel_err >= max_err)
        {
            max_err = rel_err;
            input_err = f_angle;
        }

#ifdef ENABLE_PROFILER
        fprintf(fpTest, "GDBexp_100 ---> ");
        fprintf(fpTest, "Test case 2 ---> ");
        total_cycles = stop_clock - start_clock - overhead;
        check__PrintValue_to_File(f_angle, fpTest);
        fprintf(fpTest, "\t");
        check__PrintValue_to_File(total_cycles, fpTest);
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

void TEST_CLASS_CML_EXP::test_GDBexp_power(int doIt)
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
        uint32 index;
        /* Test case data declarations */
        float32 f_base;
        uint32 u_power = 0;
        float32 expected_returnValue;
        float32 returnValue;
        float32 tolerance = 0.001f; 
                
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_GDBexp_power_TestCase_1  "test_001_GDBexp_power_out_target.csv"
        #define TEST_CML_VECTOR_CSVOUT_GDBexp_power_TestCase_2  "test_002_GDBexp_power_out_target.csv"
#else
        #define TEST_CML_VECTOR_CSVOUT_GDBexp_power_TestCase_1  "test_001_GDBexp_power_out_msvc.csv"
        #define TEST_CML_VECTOR_CSVOUT_GDBexp_power_TestCase_2  "test_002_GDBexp_power_out_msvc.csv"
#endif

        csv_data_float_t *current_p_CsvDataOut = NULL;
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDBexp_power_TestCase_1, "w+");
        float32 f_angle;

        /* **********************************************************************
           *                         Test case 1                                *
           ********************************************************************** */

#ifdef LINKED_LIST_PARSER
        p_CsvDataOut = NULL;
        for ( f_angle = -1; f_angle <= 1; f_angle += 0.0001)
        {
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
        std::cout << "GDBexp_power Test case 1 \n";		
        fprintf(fpTest, "GDBexp_power Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

        for ( f_angle = -1; f_angle <= 1; f_angle += 0.001)
        for ( u_power = 0; u_power <= 10; u_power += 1)		
        {	
          /* inputs are limited such that x^y should not cross the range of single precision floating point which is 3.4e38f   */
          if ((f_angle >= 1.0e-3f ) || (f_angle <= -1.0e-3f))
           {
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            p_CsvDataOut.value[dataIndex] = GDBexp_power(f_angle, u_power);

#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
        fprintf(fpTest, "GDBexp_power ---> ");
        fprintf(fpTest, "Test case 1 ---> ");
        total_cycles = stop_clock - start_clock - overhead;
        check__PrintValue_to_File(f_angle, fpTest);
        fprintf(fpTest, "\t");
        check__PrintValue_to_File(total_cycles, fpTest);
        fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */
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


        /* **********************************************************************
           *                         Test case 2                                *
           ********************************************************************** */

        current_p_CsvDataOut = NULL;
        fp = fopen (TEST_CML_VECTOR_CSVOUT_GDBexp_power_TestCase_2, "w+");

#ifdef LINKED_LIST_PARSER
        p_CsvDataOut = NULL;
        for ( f_angle = -500; f_angle <= 500; f_angle += 10)
        {
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
        std::cout << "GDBexp_power Test case 2 \n";		
        fprintf(fpTest, "GDBexp_power Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */
        for ( f_angle = -500; f_angle <= 500; f_angle += 10)
        for ( u_power = 0; u_power <= 10; u_power += 1)		
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            p_CsvDataOut.value[dataIndex] = GDBexp_power(f_angle, u_power);

#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
        fprintf(fpTest, "GDBexp_power ---> ");
        fprintf(fpTest, "Test case 2 ---> ");
        total_cycles = stop_clock - start_clock - overhead;
        check__PrintValue_to_File(f_angle, fpTest);
        fprintf(fpTest, "\t");
        check__PrintValue_to_File(total_cycles, fpTest);
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

void TEST_CLASS_CML_EXP::test_CML_Ln_VeryFast(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_Ln_VeryFast_1   "test_001_CML_Ln_VeryFast_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_Ln_VeryFast_1   "test_001_CML_Ln_VeryFast_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_Ln_VeryFast_1, "w+");	

        /* input CSV data, linked list node*/
        /* CSV parser return value for result values file */
        sint32 i_CsvRetOut = -1;
        /* CSV parser return value for input values file */
        sint32 i_CsvRetIn = -1;
        float32 angle_x,angle_y, sine_result, Expected_sine_result;

        {
            /* Set global data */
        initialise_global_data();
        /* Set expected values for global data checks */
        initialise_expected_global_data();

        /* **********************************************************************
           *                         Test case 1                                *
           ********************************************************************** */
                
#ifdef LINKED_LIST_PARSER
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_Ln_VeryFast(angle_x);
            
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
        i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

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
#ifdef ENABLE_PROFILER
        std::cout << "CML_Ln_VeryFast Test case \n";		
        fprintf(fpTest, "CML_Ln_VeryFast Test case \n");
#endif /* #ifdef ENABLE_PROFILER */
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
            p_CsvDataOut.value[dataIndex] = CML_Ln_VeryFast(angle_x);			

#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
            dataIndex++;
        }

#ifdef ENABLE_PROFILER
        fprintf(fpTest, "CML_Ln_VeryFast ---> ");
        fprintf(fpTest, "Test case 1 ---> ");
        total_cycles = stop_clock - start_clock - overhead;
        check__PrintValue_to_File(angle_x, fpTest);
        fprintf(fpTest, "\t");
        check__PrintValue_to_File(total_cycles, fpTest);
        fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

        p_CsvDataOut.dataBufferSize = dataIndex;

        /* parse CSV values for expected results */
        //i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
        i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif
        fclose(fp);

        /* Checks on global data */
        check_global_data();			
            
        }

    }
}

void TEST_CLASS_CML_EXP::test_CML_Exp_VeryFast(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_Exp_VeryFast_1   "test_001_CML_Exp_VeryFast_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_Exp_VeryFast_1   "test_001_CML_Exp_VeryFast_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_Exp_VeryFast_1, "w+");	

        /* input CSV data, linked list node*/
        /* CSV parser return value for result values file */
        sint32 i_CsvRetOut = -1;
        /* CSV parser return value for input values file */
        sint32 i_CsvRetIn = -1;
        float32 angle_x,angle_y, sine_result, Expected_sine_result;

        {
            /* Set global data */
        initialise_global_data();
        /* Set expected values for global data checks */
        initialise_expected_global_data();

        /* **********************************************************************
           *                         Test case 1                                *
           ********************************************************************** */
                
#ifdef LINKED_LIST_PARSER
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_Exp_VeryFast(angle_x);
            
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
        i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

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
#ifdef ENABLE_PROFILER
        std::cout << "CML_Exp_VeryFast Test case 1 \n";		
        fprintf(fpTest, "CML_Exp_VeryFast Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01f)
        {	
            if (angle_x <= 88.7F)
            {
                p_CsvDataOut.value = data_log_buffer;
                p_CsvDataOut.len = sizeof(float32);			

#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
                p_CsvDataOut.value[dataIndex] = CML_Exp_VeryFast(angle_x);
#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
#ifdef ENABLE_PROFILER
        fprintf(fpTest, "CML_Exp_VeryFast ---> ");
        fprintf(fpTest, "Test case 1---> ");
        total_cycles = stop_clock - start_clock - overhead;
        check__PrintValue_to_File(angle_x, fpTest);
        fprintf(fpTest, "\t");
        check__PrintValue_to_File(total_cycles, fpTest);
        fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

        dataIndex++;
            }
        }

        p_CsvDataOut.dataBufferSize = dataIndex;

        /* parse CSV values for expected results */
        //i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
        i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif

        fclose(fp);

        /* Checks on global data */
        check_global_data();			
            
        }
    }	
}

void TEST_CLASS_CML_EXP::test_CML_f_MagToDB(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_f_MagToDB_1   "test_001_CML_f_MagToDB_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_f_MagToDB_1   "test_001_CML_f_MagToDB_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_f_MagToDB_1, "w+");	

        /* input CSV data, linked list node*/
        /* CSV parser return value for result values file */
        sint32 i_CsvRetOut = -1;
        /* CSV parser return value for input values file */
        sint32 i_CsvRetIn = -1;
        float32 angle_x,angle_y, sine_result, Expected_sine_result;

        {
            /* Set global data */
        initialise_global_data();
        /* Set expected values for global data checks */
        initialise_expected_global_data();

        /* **********************************************************************
           *                         Test case 1                                *
           ********************************************************************** */
                
#ifdef LINKED_LIST_PARSER
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);
            
            *(temp_p_CsvDataOut->value) = CML_f_MagToDB(angle_x);
            
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
        i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

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
        double rel_err = 0;
        double max_err = 0;
        double input_err = 0;
        double ref_out = 0;
#ifdef ENABLE_PROFILER
        std::cout << "CML_f_MagToDB Test case 1 \n";		
        fprintf(fpTest, "CML_f_MagToDB Test case 1\n");
#endif /* #ifdef ENABLE_PROFILER */

        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);		

            ref_out = 20 * log10(angle_x);
#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            float32 test_out = CML_f_MagToDB(angle_x);	

#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
#ifdef ENABLE_PROFILER
        fprintf(fpTest, "CML_f_MagToDB ---> ");
        fprintf(fpTest, "Test case 1 ---> ");
        total_cycles = stop_clock - start_clock - overhead;
        check__PrintValue_to_File(angle_x, fpTest);
        fprintf(fpTest, "\t");
        check__PrintValue_to_File(total_cycles, fpTest);
        fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

            p_CsvDataOut.value[dataIndex] = test_out;

            double abs_err = abs(ref_out - test_out);
            rel_err = abs(abs_err/ref_out);
            if (rel_err >= max_err)
            {
                max_err = rel_err;
                input_err = angle_x;
            }

            dataIndex++;
        }

        p_CsvDataOut.dataBufferSize = dataIndex;

        /* parse CSV values for expected results */
        //i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
        i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif
        fclose(fp);

        /* Checks on global data */
        check_global_data();			
            
        }
    }	
}

void TEST_CLASS_CML_EXP::test_CML_f_fastlog(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_f_fastlog_1   "test_001_CML_f_fastlog_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_f_fastlog_1   "test_001_CML_f_fastlog_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_f_fastlog_1, "w+");	

        /* input CSV data, linked list node*/
        /* CSV parser return value for result values file */
        sint32 i_CsvRetOut = -1;
        /* CSV parser return value for input values file */
        sint32 i_CsvRetIn = -1;
        float32 angle_x,angle_y, sine_result, Expected_sine_result;

        {
            /* Set global data */
        initialise_global_data();
        /* Set expected values for global data checks */
        initialise_expected_global_data();

        /* **********************************************************************
           *                         Test case 1                                *
           ********************************************************************** */
                
#ifdef LINKED_LIST_PARSER
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_f_fastlog(angle_x);
            
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
        i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

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
        float32 rel_err;
        float32 max_err = 0;
        float32 input_err = 0;

#ifdef ENABLE_PROFILER
        std::cout << "CML_f_fastlog Test case 1 \n";		
        fprintf(fpTest, "CML_f_fastlog Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);	
            float32 ref_fout = log(angle_x);
          
#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
        float32 test_out= CML_f_fastlog(angle_x);	

#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
        p_CsvDataOut.value[dataIndex] = test_out;

        float32 abs_err = abs(ref_fout - test_out);
        rel_err = abs(abs_err/ref_fout);
        if (rel_err >= max_err)
        {
            max_err = rel_err;
            input_err = angle_x;
        }
#ifdef ENABLE_PROFILER
        fprintf(fpTest, "CML_f_fastlog ---> ");
        fprintf(fpTest, "Test case 1 ---> ");
        total_cycles = stop_clock - start_clock - overhead;
        check__PrintValue_to_File(angle_x, fpTest);
        fprintf(fpTest, "\t");
        check__PrintValue_to_File(total_cycles, fpTest);
        fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */
            dataIndex++;
        }

        p_CsvDataOut.dataBufferSize = dataIndex;

        /* parse CSV values for expected results */
        //i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
        i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif

        fclose(fp);

        /* Checks on global data */
        check_global_data();			
            
        }
    }	
}

void TEST_CLASS_CML_EXP::test_CML_f_fastlog10(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_f_fastlog10_1   "test_001_CML_f_fastlog10_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_f_fastlog10_1   "test_001_CML_f_fastlog10_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_f_fastlog10_1, "w+");	

        /* input CSV data, linked list node*/
        /* CSV parser return value for result values file */
        sint32 i_CsvRetOut = -1;
        /* CSV parser return value for input values file */
        sint32 i_CsvRetIn = -1;
        float32 angle_x,angle_y, sine_result, Expected_sine_result;

        {
            /* Set global data */
        initialise_global_data();
        /* Set expected values for global data checks */
        initialise_expected_global_data();

        /* **********************************************************************
           *                         Test case 1                                *
           ********************************************************************** */
                
#ifdef LINKED_LIST_PARSER
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_f_fastlog10(angle_x);
            
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
        i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

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
        float32 rel_err;
        float32 max_err = 0;
        float32 input_err = 0;

#ifdef ENABLE_PROFILER
        std::cout << "CML_f_fastlog10 Test case  1\n";		
        fprintf(fpTest, "CML_f_fastlog10 Test case  1\n");
#endif /* #ifdef ENABLE_PROFILER */
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			
            float32 ref_out = log(angle_x);
#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
        float32 test_out = CML_f_fastlog10(angle_x);	

#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
        p_CsvDataOut.value[dataIndex] = test_out;

        float32 abs_err = abs(ref_out - test_out);
        rel_err = abs(abs_err/ref_out);
        if (rel_err >= max_err)
        {
            max_err = rel_err;
            input_err = angle_x;
        }
#ifdef ENABLE_PROFILER
        fprintf(fpTest, "CML_f_fastlog10 ---> ");
        fprintf(fpTest, "Test case 1 ---> ");
        total_cycles = stop_clock - start_clock - overhead;
        check__PrintValue_to_File(angle_x, fpTest);
        fprintf(fpTest, "\t");
        check__PrintValue_to_File(total_cycles, fpTest);
        fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */
            dataIndex++;
        }

        p_CsvDataOut.dataBufferSize = dataIndex;

        /* parse CSV values for expected results */
        //i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
        i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif

        fclose(fp);

        /* Checks on global data */
        check_global_data();			
            
        }
    }	
}

void TEST_CLASS_CML_EXP::test_CML_f_log10(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_f_log10_1   "test_001_CML_f_log10_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_f_log10_1   "test_001_CML_f_log10_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_f_log10_1, "w+");	

        /* input CSV data, linked list node*/
        /* CSV parser return value for result values file */
        sint32 i_CsvRetOut = -1;
        /* CSV parser return value for input values file */
        sint32 i_CsvRetIn = -1;
        float32 angle_x,angle_y, sine_result, Expected_sine_result;

        {
            /* Set global data */
        initialise_global_data();
        /* Set expected values for global data checks */
        initialise_expected_global_data();

        /* **********************************************************************
           *                         Test case 1                                *
           ********************************************************************** */
                
#ifdef LINKED_LIST_PARSER
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_f_log10(angle_x);
            
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
        i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

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
#ifdef ENABLE_PROFILER
        std::cout << "CML_f_log10 Test case 1\n";		
        fprintf(fpTest, "CML_f_log10 Test case 1\n");
#endif /* #ifdef ENABLE_PROFILER */

        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			
            
#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            p_CsvDataOut.value[dataIndex] = CML_f_log10(angle_x);	

#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
#ifdef ENABLE_PROFILER
        fprintf(fpTest, "CML_f_log10 ---> ");
        fprintf(fpTest, "Test case 1 ---> ");
        total_cycles = stop_clock - start_clock - overhead;
        check__PrintValue_to_File(angle_x, fpTest);
        fprintf(fpTest, "\t");
        check__PrintValue_to_File(total_cycles, fpTest);
        fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */
            dataIndex++;
        }

        p_CsvDataOut.dataBufferSize = dataIndex;

        /* parse CSV values for expected results */
        //i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
        i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif

        fclose(fp);

        /* Checks on global data */
        check_global_data();			
            
        }
    }	
}

void TEST_CLASS_CML_EXP::test_CML_f_log2(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_f_log2_1   "test_001_CML_f_log2_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_f_log2_1   "test_001_CML_f_log2_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_f_log2_1, "w+");	

        /* input CSV data, linked list node*/
        /* CSV parser return value for result values file */
        sint32 i_CsvRetOut = -1;
        /* CSV parser return value for input values file */
        sint32 i_CsvRetIn = -1;
        float32 angle_x,angle_y, sine_result, Expected_sine_result;

        {
            /* Set global data */
        initialise_global_data();
        /* Set expected values for global data checks */
        initialise_expected_global_data();

        /* **********************************************************************
           *                         Test case 1                                *
           ********************************************************************** */
                
#ifdef LINKED_LIST_PARSER
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_f_log2(angle_x);
            
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
        i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

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
#ifdef ENABLE_PROFILER
        std::cout << "CML_f_log2 Test case 1\n";		
        fprintf(fpTest, "CML_f_log2 Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			
#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            p_CsvDataOut.value[dataIndex] = CML_f_log2(angle_x);	

#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
        fprintf(fpTest, "CML_f_log2 ---> ");
        fprintf(fpTest, "Test case 1 ---> ");
        total_cycles = stop_clock - start_clock - overhead;
        check__PrintValue_to_File(angle_x, fpTest);
        fprintf(fpTest, "\t");
        check__PrintValue_to_File(total_cycles, fpTest);
        fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */
            dataIndex++;
        }

        p_CsvDataOut.dataBufferSize = dataIndex;

        /* parse CSV values for expected results */
        //i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
        i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif

        fclose(fp);

        /* Checks on global data */
        check_global_data();			
            
        }
    }	
}

void TEST_CLASS_CML_EXP::test_CML_f_ln(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_f_ln_1   "test_001_CML_f_ln_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_f_ln_1   "test_001_CML_f_ln_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_f_ln_1, "w+");	

        /* input CSV data, linked list node*/
        /* CSV parser return value for result values file */
        sint32 i_CsvRetOut = -1;
        /* CSV parser return value for input values file */
        sint32 i_CsvRetIn = -1;
        float32 angle_x,angle_y, sine_result, Expected_sine_result;

        {
            /* Set global data */
        initialise_global_data();
        /* Set expected values for global data checks */
        initialise_expected_global_data();

        /* **********************************************************************
           *                         Test case 1                                *
           ********************************************************************** */
                
#ifdef LINKED_LIST_PARSER
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_f_ln(angle_x);
            
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
        i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

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

#ifdef ENABLE_PROFILER
        std::cout << "CML_f_ln Test case 1  \n";		
        fprintf(fpTest, "CML_f_ln Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            p_CsvDataOut.value[dataIndex] = CML_f_ln(angle_x);	

#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
#ifdef ENABLE_PROFILER
        fprintf(fpTest, "CML_f_ln ---> ");
        fprintf(fpTest, "Test case 1 ---> ");
        total_cycles = stop_clock - start_clock - overhead;
        check__PrintValue_to_File(angle_x, fpTest);
        fprintf(fpTest, "\t");
        check__PrintValue_to_File(total_cycles, fpTest);
        fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */
            dataIndex++;
        }

        p_CsvDataOut.dataBufferSize = dataIndex;

        /* parse CSV values for expected results */
        //i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
        i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif

        fclose(fp);

        /* Checks on global data */
        check_global_data();			
            
        }
    }	
}

void TEST_CLASS_CML_EXP::test_CML_f_PowerOfTwo(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_f_PowerOfTwo_1   "test_001_CML_f_PowerOfTwo_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_f_PowerOfTwo_1   "test_001_CML_f_PowerOfTwo_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_f_PowerOfTwo_1, "w+");	

        /* input CSV data, linked list node*/
        /* CSV parser return value for result values file */
        sint32 i_CsvRetOut = -1;
        /* CSV parser return value for input values file */
        sint32 i_CsvRetIn = -1;
        float32 angle_x,angle_y, sine_result, Expected_sine_result;

        {
            /* Set global data */
        initialise_global_data();
        /* Set expected values for global data checks */
        initialise_expected_global_data();

        /* **********************************************************************
           *                         Test case 1                                *
           ********************************************************************** */
                
#ifdef LINKED_LIST_PARSER
        for ( angle_x = 0.001; angle_x <= 100; angle_x += 0.1)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_f_PowerOfTwo(angle_x);
            
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
        i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

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
        double rel_err = 0;
        double max_err = 0, abs_err = 0;
        double input_err = 0;
#ifdef ENABLE_PROFILER
        std::cout << "CML_f_PowerOfTwo Test case 1 1\n";		
        fprintf(fpTest, "CML_f_PowerOfTwo Test case 1\n");
#endif /* #ifdef ENABLE_PROFILER */
        for ( angle_x = -10.5; angle_x <= 100; angle_x += 1.05F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);	

            double ref_fout = pow(2.0, (double)angle_x);
#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            float32 test_out = CML_f_PowerOfTwo(angle_x);	
        
#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
            p_CsvDataOut.value[dataIndex] = test_out;
#ifdef ENABLE_PROFILER
        fprintf(fpTest, "CML_f_PowerOfTwo ---> ");
        fprintf(fpTest, "Test case 1 ---> ");
        total_cycles = stop_clock - start_clock - overhead;
        check__PrintValue_to_File(angle_x, fpTest);
        fprintf(fpTest, "\t");
        check__PrintValue_to_File(total_cycles, fpTest);
        fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

            abs_err = abs(ref_fout - (double)test_out);	
            rel_err = abs(abs_err/ref_fout);
            if (rel_err >= max_err)
            {
                max_err = rel_err;
                input_err = angle_x;
            }
            dataIndex++;
        }

        p_CsvDataOut.dataBufferSize = dataIndex;

        /* parse CSV values for expected results */
        //i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
        i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif
        fclose(fp);

        /* Checks on global data */
        check_global_data();			
            
        }
    }	
}

void TEST_CLASS_CML_EXP::test_CML_f_XPowY(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_f_XPowY_1   "test_001_CML_f_XPowY_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_f_XPowY_1   "test_001_CML_f_XPowY_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_f_XPowY_1, "w+");	

        /* input CSV data, linked list node*/
        /* CSV parser return value for result values file */
        sint32 i_CsvRetOut = -1;
        /* CSV parser return value for input values file */
        sint32 i_CsvRetIn = -1;
        float32 f_Base,f_Exponent, sine_result, Expected_sine_result;

        {
            /* Set global data */
        initialise_global_data();
        /* Set expected values for global data checks */
        initialise_expected_global_data();

        /* **********************************************************************
           *                         Test case 1                                *
           ********************************************************************** */
                
#ifdef LINKED_LIST_PARSER
        for ( f_Base = 0.0000001; f_Base <= 10000000; f_Base *= 2)
        for ( f_Exponent = 0.0000001; f_Exponent <= 10000000; f_Exponent *= 2)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_f_XPowY(f_Base,f_Exponent);
            
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
        i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

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
#ifdef ENABLE_PROFILER
        std::cout << "CML_f_XPowY Test case 1 \n";		
        fprintf(fpTest, "CML_f_XPowY Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

        for ( f_Base = 0.0000001; f_Base <= 10000000; f_Base *= 2)
        for ( f_Exponent = 0.0000001; f_Exponent <= 10000000; f_Exponent *= 2)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			
#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            p_CsvDataOut.value[dataIndex] = CML_f_XPowY(f_Base,f_Exponent);	

#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
#ifdef ENABLE_PROFILER
        fprintf(fpTest, "CML_f_XPowY Test case 1---> ");
        total_cycles = stop_clock - start_clock - overhead;
        check__PrintValue_to_File(f_Base, fpTest);
        fprintf(fpTest, "\t");
        check__PrintValue_to_File(total_cycles, fpTest);
        fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */
        dataIndex++;
        }

        p_CsvDataOut.dataBufferSize = dataIndex;

        /* parse CSV values for expected results */
        //i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
        i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif

        fclose(fp);

        /* Checks on global data */
        check_global_data();			
            
        }
    }
}

void TEST_CLASS_CML_EXP::test_CML_f_PowToDB(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_f_PowToDB_1   "test_001_CML_f_PowToDB_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_f_PowToDB_1   "test_001_CML_f_PowToDB_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_f_PowToDB_1, "w+");	

        /* input CSV data, linked list node*/
        /* CSV parser return value for result values file */
        sint32 i_CsvRetOut = -1;
        /* CSV parser return value for input values file */
        sint32 i_CsvRetIn = -1;
        float32 angle_x,angle_y, sine_result, Expected_sine_result;

        {
            /* Set global data */
        initialise_global_data();
        /* Set expected values for global data checks */
        initialise_expected_global_data();

        /* **********************************************************************
           *                         Test case 1                                *
           ********************************************************************** */
                
#ifdef LINKED_LIST_PARSER
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_f_PowToDB(angle_x);
            
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
        i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

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

#ifdef ENABLE_PROFILER
        std::cout << "CML_f_PowToDB - Test case 1 \n";		
        fprintf(fpTest, "CML_f_PowToDB - Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            p_CsvDataOut.value[dataIndex] = CML_f_PowToDB(angle_x);		

#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
        fprintf(fpTest, "CML_f_PowToDB Test case 1---> ");
        fprintf(fpTest, "CML_f_PowToDB Test case 1 ---> ");
        total_cycles = stop_clock - start_clock - overhead;
        check__PrintValue_to_File(angle_x, fpTest);
        fprintf(fpTest, "\t");
        check__PrintValue_to_File(total_cycles, fpTest);
        fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */
            dataIndex++;
        }

        p_CsvDataOut.dataBufferSize = dataIndex;

        /* parse CSV values for expected results */
        //i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
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
