/*****************************************************************************/
/*                            CML Target Test Script                         */
/*****************************************************************************/
/*
*    Filename: test_cml_misc.cpp
*    Author: uidp1547

*    Generated on: 31-Aug-2016 15:43:28
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
extern float32 CML_f_Mod(float32 f_value, float32 f_modulo);
extern float32 CML_f_Rem(float32 f_dividend, float32 f_divisor);
extern float32 CML_f_ModReciprocal(float32 f_dividend, float32 f_reciprocal, float32 f_divisor);
extern sint32 CML_s_CountNrOfBitsSet(uint32 u_PruefBits);
extern void CML_v_CalculateCOFEgomotionMatrices(CML_t_TrafoMatrix2D* p_TrafoMatrix2DCOFForwardRaw, CML_t_TrafoMatrix2D* p_TrafoMatrix2DCOFBackwardRaw, fVelocity_t f_SpeedCorrected, fAccel_t f_EgoAcceleration, fYawRate_t f_YawRate_e, fTime_t f_CycleTime);
extern void CML_v_CalcCOFEgomotionMatrices(CML_t_TrafoMatrix2D* p_TrafoMatrix2DCOFForwardTgtSync, CML_t_TrafoMatrix2D* p_TrafoMatrix2DCOFForJitTgtSync, fVelocity_t f_EgoSpeedXTgtSync, fVelocity_t f_EgoAccelXTgtSync, fYawRate_t f_YawRateTgtSync, fVariance_t f_YawRateVarTgtSync, fYawRate_t f_YawRateMaxJitterTgtSync, fDistance_t f_SensorXPosition, fDistance_t f_SensorYPosition, fAngle_t f_SlipAngleTgtSync, fVariance_t f_SlipAngleVarTgtSync, fTime_t f_CycleTime);
extern float32 CML_f_GetPickupDist(float32 f_ObjRelSpeed, float32 f_EgoSpeed, float32 f_EgoDeceleration, float32 f_GapTime, float32 f_LatencyTime);
extern float32 CML_f_ComputeClothoidLateralDistance(float32 f_Xpos, float32 f_C0, float32 f_C1, float32 f_Angle);
extern void CML_f_LowPassFilter2(float32* f_Old, float32 f_New, float32 f_Alpha);
extern sint32 CML_s_GetLutIndex(const float32 f_InputValue, const float32 f_LutMinInputValue, const float32 f_LutRes, const sint32 s_LutMinInd, const sint32 s_LutMaxInd);
extern sint32 CML_s_GetLutIndexBackwards(const float32 f_InputValue, const float32* a_LUT, const sint32 s_LutMinInd, const sint32 s_LutMaxInd);
extern boolean CML_b_IsPointInsidePolygon(const float32* a_Xarray, const float32* a_Yarray, uint32 u_size, float32 f_Xpoint, float32 f_Ypoint);
extern CML_t_TrajRefPoint CML_CalculateDistancePoint2Circle(float32 f_X, float32 f_Y, float32 f_C0);
extern float32 ACCESS_FUNCTION_cml_misc_CML_f_ApproximateRefpoint(float32 f_X, float32 f_Y, float32 f_C0, float32 f_C1, float32 f_RefX);
extern CML_t_TrajRefPoint CML_CalculateDistancePoint2Clothoid(float32 f_X, float32 f_Y, float32 f_C0, float32 f_C1);
CML_t_TrafoMatrix2D CML_TrafoMatrix2DMult(CML_t_TrafoMatrix2D A, CML_t_TrafoMatrix2D B);
float32 GDBatan2_66(float32 y, float32 x);
float32 GDBcos_52(float32 x);
float32 GDBexp(float32 x);
float32 GDBexp_power(float32 x, uint32 n);
float32 GDBsin_52(float32 x);
void GDBsincos(float32 x, float32* s, float32* c);

/* Global data */
/* None */
typedef union
{
    float32 expected_f_val;  /*!< float representation */
    uint32  expected_u_val;  /*!< hexadecimal representation */
} expected_t_floatAccess; 
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


static void check__PrintValue_to_File(int Value, FILE *fpTest)
{
    fprintf(fpTest, ",%i,", Value);
}


/*****************************************************************************/
/* Test class declaration                                                    */
/*****************************************************************************/
class TEST_CLASS_CML_MISC
{
public:
    /* Prototypes for test functions */
    void run_tests_cml_misc();
    void test_CML_s_CountNrOfBitsSet(int);
    void test_CML_b_IsPointInsidePolygon(int);	
    void test_CML_s_GetLutIndex(int);
    void test_CML_s_GetLutIndexBackwards(int);
    void test_CML_f_Sign(int);
    void test_CML_f_Mod(int);
    void test_CML_f_Rem(int);
    void test_CML_f_ModReciprocal(int);
    void test_CML_InvSqrt14(int);
    void test_CML_InvSqrt27(int);
    void test_CML_InvSqrt53(int);
    void test_CML_InvSqrt69(int);
    void test_CML_Sqrt14(int);
    void test_CML_Sqrt27(int);
    void test_CML_Sqrt53(int);
    void test_CML_Sqrt69(int);
    void test_CML_FastInv69(int);
    void test_CML_FastDiv69(int);
    void test_CML_FastInv47(int);
    void test_CML_FastInv23(int);	
    void test_CML_FastestInv(int);
    void test_CML_Sqrt_VeryFast(int);
    void test_CML_AlphaMaxBetaMin(int);
    void test_CML_s_AlphaMaxBetaMinInt(int);
    void test_CML_f_Hypot(int);
};


/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_misc(void)
{
    TEST_CLASS_CML_MISC test_object;

    std::cout << "******** Start Testing: CML Miscellaneous functions ********\n\n";
    fprintf(fpTest, "******** Start Testing: CML Miscellaneous functions ********\n\n");

    test_object.run_tests_cml_misc();

    std::cout << "End of Testing: CML Miscellaneous functions\n\n";
    fprintf(fpTest, "End of Testing: CML Miscellaneous functions\n\n");

    return;

}

/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS_CML_MISC::run_tests_cml_misc()
{
    test_CML_AlphaMaxBetaMin(1);
    test_CML_s_AlphaMaxBetaMinInt(1);
    test_CML_f_Hypot(1);
    test_CML_Sqrt_VeryFast(1);
    test_CML_InvSqrt53(1);
    test_CML_InvSqrt27(1);
    test_CML_InvSqrt14(1);
    test_CML_InvSqrt69(1);
    test_CML_Sqrt53(1);
    test_CML_Sqrt27(1);
    test_CML_Sqrt14(1);
    test_CML_Sqrt69(1);
    test_CML_FastDiv69(1);
    test_CML_FastInv69(1);
    test_CML_FastInv47(1);
    test_CML_FastInv23(1);
    test_CML_FastestInv(1);
    test_CML_f_Sign(1);
    test_CML_f_Mod(1);
    test_CML_f_Rem(1);
    test_CML_f_ModReciprocal(1);
    test_CML_s_CountNrOfBitsSet(1);
    test_CML_s_GetLutIndex(1);
    test_CML_s_GetLutIndexBackwards(1);
    test_CML_b_IsPointInsidePolygon(1);	
    test_CML_Sqrt69(1);
    test_CML_FastDiv69(1);

}

/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/
void TEST_CLASS_CML_MISC::test_CML_s_AlphaMaxBetaMinInt(int doIt)
{
    if (doIt) 
    {
        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_s_AlphaMaxBetaMinINT_1   "test_001_CML_s_AlphaMaxBetaMinINT_out_target.csv"	
        #define TEST_CML_VECTOR_CSVOUT_CML_s_AlphaMaxBetaMinINT_2   "test_002_CML_s_AlphaMaxBetaMinINT_out_target.csv"	
        #define TEST_CML_VECTOR_CSVOUT_CML_s_AlphaMaxBetaMinINT_3   "test_003_CML_s_AlphaMaxBetaMinINT_out_target.csv"	
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_s_AlphaMaxBetaMinINT_1   "test_001_CML_s_AlphaMaxBetaMinINT_out_msvc.csv"	
        #define TEST_CML_VECTOR_CSVOUT_CML_s_AlphaMaxBetaMinINT_2   "test_002_CML_s_AlphaMaxBetaMinINT_out_msvc.csv"
        #define TEST_CML_VECTOR_CSVOUT_CML_s_AlphaMaxBetaMinINT_3   "test_003_CML_s_AlphaMaxBetaMinINT_out_msvc.csv"
#endif
        /* result CSV data, linked list node*/
#ifdef LINKED_LIST_PARSER
        csv_data_float_t *p_CsvDataOut = NULL;
#else
        csv_data_float_t p_CsvDataOut;
#endif

        csv_data_float_t *current_p_CsvDataOut = NULL;
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_s_AlphaMaxBetaMinINT_1, "w+");	

        /* input CSV data, linked list node*/
        /* CSV parser return value for result values file */
        sint32 i_CsvRetOut = -1;
        /* CSV parser return value for input values file */
        sint32 i_CsvRetIn = -1;
        //float32 angle_x,angle_y, sine_result, Expected_sine_result;

        {
            /* Set global data */
        initialise_global_data();
        /* Set expected values for global data checks */
        initialise_expected_global_data();

        /* **********************************************************************
           *                         Test case 1                                *
           ********************************************************************** */
                
#ifdef LINKED_LIST_PARSER
        int testin_s_x, testin_s_y ; 
        for ( testin_s_x = 1; testin_s_x <= 16777216; testin_s_x *= 2)
        for ( testin_s_y = 1; testin_s_y <= 16777216; testin_s_y *= 2)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_s_AlphaMaxBetaMinInt(testin_s_x,testin_s_y);	
            
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
        int testin_s_x_1 = 0, testin_s_y_1 = 0;

#ifdef ENABLE_PROFILER
        std::cout << "Test case 1 \n";		
        fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

        for ( testin_s_x_1 = 1; testin_s_x_1 <= 16777216 ; testin_s_x_1 *= 2)
        for ( testin_s_y_1 = 1; testin_s_y_1 <= 16777216 ; testin_s_y_1 *= 2)
        {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32); 

#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
        p_CsvDataOut.value[dataIndex] = CML_s_AlphaMaxBetaMinInt(testin_s_x_1,testin_s_y_1);			

#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
        fprintf(fpTest, "CML_s_AlphaMaxBetaMinINT---> ");
        fprintf(fpTest, "Test case 1 ---> ");
        total_cycles = stop_clock - start_clock - overhead;
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
        

        /* **********************************************************************
         *                         Test case 2                                 *
         ********************************************************************** */
    
        current_p_CsvDataOut = NULL;
        fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_s_AlphaMaxBetaMinINT_2, "w+");	

#ifdef LINKED_LIST_PARSER
        int testin_s_x, testin_s_y ; 
        for ( testin_s_x = 1; testin_s_x <= 16777216; testin_s_x *= 2)
        for ( testin_s_y = 1; testin_s_y <= 16777216; testin_s_y *= 2)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_s_AlphaMaxBetaMinInt(testin_s_x,testin_s_y);	
            
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
        int testin_s_x_2 = 0, testin_s_y_2 = 0;
        dataIndex = 0;

#ifdef ENABLE_PROFILER
        std::cout << "Test case 2 \n";		
        fprintf(fpTest, "Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */

        for ( testin_s_x_2 = -1; testin_s_x_2 >= -16777216 ; testin_s_x_2 *= 2)
        for ( testin_s_y_2 = -1; testin_s_y_2 >= -16777216; testin_s_y_2 *= 2)
        {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
        p_CsvDataOut.value[dataIndex] = CML_s_AlphaMaxBetaMinInt(testin_s_x_2,testin_s_y_2);			

#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
        fprintf(fpTest, "CML_AlphaMaxBetaMinINT---> ");
        fprintf(fpTest, "Test case 2 ---> ");
        total_cycles = stop_clock - start_clock - overhead;
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

        /* **********************************************************************
         *                         Test case 3                                  *
         ********************************************************************** */
    
        current_p_CsvDataOut = NULL;
        fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_s_AlphaMaxBetaMinINT_3, "w+");	

#ifdef LINKED_LIST_PARSER
        for ( s_x_count3 = 1; s_x_count3 <= 16777216 ; s_x_count3 *= 2)
        for ( s_y_count3 = 1; s_y_count3 <= 16777216; s_y_count3 *= 2)
        {
            if (s_x_count3 <= 1024)
            {
                testin_s_x_3 = s_x_count3;
                testin_s_y_3 = -s_y_count3;
            }
            else
            {
                testin_s_x_3 = -s_x_count3;
                testin_s_y_3 = s_y_count3;
            }
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_s_AlphaMaxBetaMinInt(testin_s_x,testin_s_y);	
            
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
        int testin_s_x_3 = 0, testin_s_y_3 = 0, s_x_count3 = 0, s_y_count3 = 0;
        dataIndex = 0;

#ifdef ENABLE_PROFILER
        std::cout << "Test case 3 \n";		
        fprintf(fpTest, "Test case 3 \n");
#endif /* #ifdef ENABLE_PROFILER */

        for ( s_x_count3 = 1; s_x_count3 <= 16777216 ; s_x_count3 *= 2)
        for ( s_y_count3 = 1; s_y_count3 <= 16777216; s_y_count3 *= 2)
        {
            if (s_x_count3 <= 1024)
            {
                testin_s_x_3 = s_x_count3;
                testin_s_y_3 = -s_y_count3;
            }
            else
            {
                testin_s_x_3 = -s_x_count3;
                testin_s_y_3 = s_y_count3;
            }

        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
        p_CsvDataOut.value[dataIndex] = CML_s_AlphaMaxBetaMinInt(testin_s_x_3,testin_s_y_3);			

#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
        fprintf(fpTest, "CML_AlphaMaxBetaMinINT---> ");
        fprintf(fpTest, "Test case 3 ---> ");
        total_cycles = stop_clock - start_clock - overhead;
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

void TEST_CLASS_CML_MISC::test_CML_AlphaMaxBetaMin(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_AlphaMaxBetaMin_1   "test_001_CML_AlphaMaxBetaMin_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_AlphaMaxBetaMin_1   "test_001_CML_AlphaMaxBetaMin_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_AlphaMaxBetaMin_1, "w+");	

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
        for ( angle_x = 0.0000001; angle_x <= 10000000; angle_x *= 2)
        for ( angle_y = 0.0000001; angle_y <= 10000000; angle_y *= 2)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_AlphaMaxBetaMin(angle_x,angle_y);
            
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
        for ( angle_x = 0.0000001; angle_x <= 10000000; angle_x *= 2)
        for ( angle_y = 0.0000001; angle_y <= 10000000; angle_y *= 2)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

            p_CsvDataOut.value[dataIndex] = CML_AlphaMaxBetaMin(angle_x,angle_y);			

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

void TEST_CLASS_CML_MISC::test_CML_f_Hypot(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_f_Hypot_1   "test_001_CML_f_Hypot_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_f_Hypot_1   "test_001_CML_f_Hypot_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_f_Hypot_1, "w+");	

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
        for ( angle_x = 0.0000001; angle_x <= 10000000; angle_x *= 2)
        for ( angle_y = 0.0000001; angle_y <= 10000000; angle_y *= 2)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_f_Hypot(angle_x,angle_y);
            
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
        float32 rel_err =0;
        float32 max_err = 0;
        float32 input_err_x = 0;
        float32 input_err_y = 0;

#ifdef ENABLE_PROFILER
        std::cout << "Test case 1 \n";		
        fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */
        for ( angle_x = 0.0000001; angle_x <= 10000000; angle_x *= 2)
        for ( angle_y = 0.0000001; angle_y <= 10000000; angle_y *= 2)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);		
            double ref_fout = sqrt(angle_x * angle_x + angle_y * angle_y);
#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
            float32 test_out = CML_f_Hypot(angle_x,angle_y);			

#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
            
            p_CsvDataOut.value[dataIndex] = test_out;
            float32 abs_err = abs(ref_fout - test_out);
            rel_err = abs(abs_err/ref_fout);
            if (rel_err >= max_err)
            {
                max_err = rel_err;
                input_err_x = angle_x;
                input_err_y = angle_y;
            }

#ifdef ENABLE_PROFILER
        fprintf(fpTest, "CML_f_Hypot ---> ");
        fprintf(fpTest, "Test case 1 ---> ");
        total_cycles = stop_clock - start_clock - overhead;
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


void TEST_CLASS_CML_MISC::test_CML_Sqrt_VeryFast(int doIt)
{
        if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_Sqrt_VeryFast_1   "test_001_CML_Sqrt_VeryFast_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_Sqrt_VeryFast_1   "test_001_CML_Sqrt_VeryFast_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_Sqrt_VeryFast_1, "w+");	

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

            *(temp_p_CsvDataOut->value) = CML_Sqrt_VeryFast(angle_x);
            
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
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

            p_CsvDataOut.value[dataIndex] = CML_Sqrt_VeryFast(angle_x);			

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

void TEST_CLASS_CML_MISC::test_CML_InvSqrt53(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_InvSqrt53_1   "test_001_CML_InvSqrt53_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_InvSqrt53_1   "test_001_CML_InvSqrt53_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_InvSqrt53_1, "w+");	

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

            *(temp_p_CsvDataOut->value) = CML_InvSqrt53(angle_x);
            
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
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

            p_CsvDataOut.value[dataIndex] = CML_InvSqrt53(angle_x);			

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

void TEST_CLASS_CML_MISC::test_CML_InvSqrt27(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_InvSqrt27_1   "test_001_CML_InvSqrt27_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_InvSqrt27_1   "test_001_CML_InvSqrt27_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_InvSqrt27_1, "w+");	

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

            *(temp_p_CsvDataOut->value) = CML_InvSqrt27(angle_x);
            
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
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

            p_CsvDataOut.value[dataIndex] = CML_InvSqrt27(angle_x);			

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

void TEST_CLASS_CML_MISC::test_CML_InvSqrt14(int doIt)
{	
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_InvSqrt14_1   "test_001_CML_InvSqrt14_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_InvSqrt14_1   "test_001_CML_InvSqrt14_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_InvSqrt14_1, "w+");	

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

            *(temp_p_CsvDataOut->value) = CML_InvSqrt14(angle_x);
            
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
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

            p_CsvDataOut.value[dataIndex] = CML_InvSqrt14(angle_x);			

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

void TEST_CLASS_CML_MISC::test_CML_InvSqrt69(int doIt)
{	
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_InvSqrt67_1   "test_001_CML_InvSqrt67_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_InvSqrt67_1   "test_001_CML_InvSqrt67_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_InvSqrt67_1, "w+");	

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

            *(temp_p_CsvDataOut->value) = CML_InvSqrt67(angle_x);
            
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

#ifdef ENABLE_PROFILER
        std::cout << "CML_InvSqrt67 Test case 1 \n";		
        fprintf(fpTest, "CML_InvSqrt67 Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

        for ( angle_x = 0.0000001; angle_x <= 100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);					
            double ref_fout = 1.0F/(float32)sqrt((double)angle_x);
            float32 test_out;

#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

         test_out  =  CML_InvSqrt67(angle_x);	

#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
#ifdef ENABLE_PROFILER
        total_cycles = stop_clock - start_clock - overhead;
        check__PrintValue_to_File(angle_x, fpTest);
        fprintf(fpTest, "\t");
        check__PrintValue_to_File(total_cycles, fpTest);
        fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

            p_CsvDataOut.value[dataIndex] = test_out;
            double abs_err = abs(ref_fout - (double)test_out);
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

#if 1
void TEST_CLASS_CML_MISC::test_CML_FastDiv69(int doIt)
{	
    if (doIt) 
    {
        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_FastDiv69_1   "test_001_CML_FastDiv69_out_target.csv"
        #define TEST_CML_VECTOR_CSVOUT_CML_FastDiv69_2   "test_002_CML_FastDiv69_out_target.csv"	
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_FastDiv69_1   "test_001_CML_FastDiv69_out_msvc.csv"
        #define TEST_CML_VECTOR_CSVOUT_CML_FastDiv69_2   "test_002_CML_FastDiv69_out_msvc.csv"	
#endif

        float32 f_power;
        float32 expected_returnValue;
        float32 returnValue;
        /* result CSV data, linked list node*/

        csv_data_float_t p_CsvDataOut;

        csv_data_float_t *current_p_CsvDataOut = NULL;
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_FastDiv69_1, "w+");	

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
            
        int dataIndex = 0;
        float32 f_divout = 0;
        float32 f_reldiverr;
        float32 f_maxerr = 0;
        float32 f_inputmaxerr_x = 0;
        float32 f_inputmaxerr_y = 0;
        float32 f_outputmaxerr = 0;
        float32 angle_y = 0;

#ifdef ENABLE_PROFILER
        std::cout << "Test case 1 \n";		
        fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

        for ( angle_y = 0.00000001; angle_y <= 3.4e27; angle_y *= 1000.0f)
        for ( angle_x = 0.00000001; angle_x <= 3.4e27; angle_x *= 5000.0F)
        {	
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);	

#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            p_CsvDataOut.value[dataIndex] = CML_f_fastDiv69(angle_y, angle_x);	

#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


            f_divout = angle_y/angle_x;
            f_reldiverr = (f_divout - p_CsvDataOut.value[dataIndex])/f_divout;
            f_reldiverr = f_reldiverr < 0.0F ? -f_reldiverr : f_reldiverr;	
            if (f_reldiverr > f_maxerr ) 
            {
                f_maxerr = f_reldiverr;
                f_inputmaxerr_x = angle_x;
                f_inputmaxerr_y = angle_y;
                f_outputmaxerr = p_CsvDataOut.value[dataIndex];
            }
#ifdef ENABLE_PROFILER
        fprintf(fpTest, "CML_f_fastDiv69---> ");
        fprintf(fpTest, "Test case 1 ---> ");
        total_cycles = stop_clock - start_clock - overhead;
        check__PrintValue_to_File(total_cycles, fpTest);
        fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */
            dataIndex++;
        }

        p_CsvDataOut.dataBufferSize = dataIndex;

        /* parse CSV values for expected results */
        //i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
        i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
        printf("CML_FastInv69 : Test case 1:  maximum error = %g \n", f_maxerr);
        printf("CML_FastInv69 : Test case 1: input for max error = %g \n", f_inputmaxerr_x);
        printf("CML_FastInv69 : Test case 1: output for max error = %f \n\n\n", f_outputmaxerr);
        fclose(fp);

          /* **********************************************************************
           *                         Test case 2                                *
           ********************************************************************** */
        current_p_CsvDataOut = NULL;
        fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_FastDiv69_2, "w+");	

         dataIndex = 0;
         f_divout = 0;
         f_reldiverr;
         f_maxerr = 0;
         f_inputmaxerr_x = 0;
         f_inputmaxerr_y = 0;
         f_outputmaxerr = 0;
         float32 tmp1, tmp2;
        for ( tmp1 = 0.00000001; tmp1 <= 3.4e27; tmp1 *= 1000.0f)
        for ( tmp2 = 0.00000001; tmp2 <= 3.4e27; tmp2 *= 5000.0F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);	
                
            angle_y  = tmp1;
            angle_x  = -tmp2;

            p_CsvDataOut.value[dataIndex] = CML_f_fastDiv69(angle_y, angle_x);	
            f_divout = angle_y/angle_x;
            f_reldiverr = (f_divout - p_CsvDataOut.value[dataIndex])/f_divout;
            f_reldiverr = f_reldiverr < 0.0F ? -f_reldiverr : f_reldiverr;	
            if (f_reldiverr > f_maxerr ) 
            {
                f_maxerr = f_reldiverr;
                f_inputmaxerr_x = angle_x;
                f_inputmaxerr_y = angle_y;
                f_outputmaxerr = p_CsvDataOut.value[dataIndex];
            }
            dataIndex++;
        }

        p_CsvDataOut.dataBufferSize = dataIndex;

        /* parse CSV values for expected results */
        //i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
        i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
        printf("CML_FastDIv69 : Test case 2: maximum error = %f \n", f_maxerr);
        printf("CML_FastDiv69 : Test case 2: input for max error = %g \n", f_inputmaxerr_x);
        printf("CML_FastDiv69 : Test case 2: output for max error = %f \n\n\n", f_outputmaxerr);

        fclose(fp);
        /* Checks on global data */
        check_global_data();			
            
        }
    }	
}

#endif

void TEST_CLASS_CML_MISC::test_CML_FastInv69(int doIt)
{	
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_FastInv69_1   "test_001_CML_FastInv69_out_target.csv"
        #define TEST_CML_VECTOR_CSVOUT_CML_FastInv69_2   "test_002_CML_FastInv69_out_target.csv"	
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_FastInv69_1   "test_001_CML_FastInv69_out_msvc.csv"
        #define TEST_CML_VECTOR_CSVOUT_CML_FastInv69_2   "test_002_CML_FastInv69_out_msvc.csv"	
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_FastInv69_1, "w+");	

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

            *(temp_p_CsvDataOut->value) = CML_FastInv69(angle_x);
            
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
        float32 f_divout = 0;
        float32 f_reldiverr;
        float32 f_maxerr = 0;
        float32 f_inputmaxerr = 0;
        float32 f_outputmaxerr = 0;
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

            p_CsvDataOut.value[dataIndex] = CML_FastInv69(angle_x);	
            f_divout = 1/angle_x;
            f_reldiverr = 100 * (f_divout - p_CsvDataOut.value[dataIndex])/f_divout;
            f_reldiverr = f_reldiverr < 0.0F ? -f_reldiverr : f_reldiverr;	
            if (f_reldiverr > f_maxerr ) 
            {
                f_maxerr = f_reldiverr;
                f_inputmaxerr = angle_x;
                f_outputmaxerr = p_CsvDataOut.value[dataIndex];
            }
            dataIndex++;
        }

        p_CsvDataOut.dataBufferSize = dataIndex;

        /* parse CSV values for expected results */
        //i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
        i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
        printf("CML_FastInv69 : Test case 1:  maximum error = %g \n", f_maxerr);
        printf("CML_FastInv69 : Test case 1: input for max error = %g \n", f_inputmaxerr);
        printf("CML_FastInv69 : Test case 1: output for max error = %f \n\n\n", f_outputmaxerr);
#endif
        fclose(fp);

          /* **********************************************************************
           *                         Test case 2                                *
           ********************************************************************** */
        current_p_CsvDataOut = NULL;
        fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_FastInv69_2, "w+");	

#ifdef LINKED_LIST_PARSER
        for ( angle_x = -0.00000001; angle_x >= -100000000; angle_x *= 1.01)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_FastInv69(angle_x);
            
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
         dataIndex = 0;
         f_divout = 0;
         f_reldiverr;
         f_maxerr = 0;
         f_inputmaxerr = 0;
         f_outputmaxerr = 0;
        for ( angle_x = -0.00000001; angle_x >= -100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);		

            
            p_CsvDataOut.value[dataIndex] = CML_FastInv69(angle_x);	
            f_divout = 1/angle_x;
            f_reldiverr = 100 * (f_divout - p_CsvDataOut.value[dataIndex])/f_divout;
            f_reldiverr = f_reldiverr < 0.0F ? -f_reldiverr : f_reldiverr;	
            if (f_reldiverr > f_maxerr ) 
            {
                f_maxerr = f_reldiverr;
                f_inputmaxerr = angle_x;
                f_outputmaxerr = p_CsvDataOut.value[dataIndex];
            }
            dataIndex++;
        }

        p_CsvDataOut.dataBufferSize = dataIndex;

        /* parse CSV values for expected results */
        //i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
        i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
        printf("CML_FastInv69 : Test case 2: maximum error = %f \n", f_maxerr);
        printf("CML_FastInv69 : Test case 2: input for max error = %g \n", f_inputmaxerr);
        printf("CML_FastInv69 : Test case 2: output for max error = %f \n\n\n", f_outputmaxerr);
#endif
        fclose(fp);
        /* Checks on global data */
        check_global_data();			
            
        }
    }	
}

void TEST_CLASS_CML_MISC::test_CML_FastInv47(int doIt)
{	
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_FastInv47_1   "test_001_CML_FastInv47_out_target.csv"
        #define TEST_CML_VECTOR_CSVOUT_CML_FastInv47_2   "test_002_CML_FastInv47_out_target.csv"	
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_FastInv47_1   "test_001_CML_FastInv47_out_msvc.csv"	
        #define TEST_CML_VECTOR_CSVOUT_CML_FastInv47_2   "test_002_CML_FastInv47_out_msvc.csv"	
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_FastInv47_1, "w+");	

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

            *(temp_p_CsvDataOut->value) = CML_FastInv47(angle_x);
            
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
        float32 f_divout = 0;
        float32 f_reldiverr;
        float32 f_maxerr = 0;
        float32 f_inputmaxerr = 0;
        float32 f_outputmaxerr = 0;

        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

            //angle_x = 0.00000122345;
            p_CsvDataOut.value[dataIndex] = CML_FastInv47(angle_x);			
            f_divout = 1/angle_x;
            f_reldiverr = 100 * (f_divout - p_CsvDataOut.value[dataIndex])/f_divout;
            f_reldiverr = f_reldiverr < 0.0F ? -f_reldiverr : f_reldiverr;	
            if (f_reldiverr > f_maxerr ) 
            {
                f_maxerr = f_reldiverr;
                f_inputmaxerr = angle_x;
                f_outputmaxerr = p_CsvDataOut.value[dataIndex];
            }
            dataIndex++;
        }

        p_CsvDataOut.dataBufferSize = dataIndex;

        /* parse CSV values for expected results */
        //i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
        i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
        printf("CML_FastInv47 :Test case 1: maximum error = %g \n", f_maxerr);
        printf("CML_FastInv47 :Test case 1: input for max error = %g \n", f_inputmaxerr);
        printf("CML_FastInv47 :Test case 1: output for max error = %f \n\n\n", f_outputmaxerr);

#endif
        fclose(fp);

          /* **********************************************************************
           *                         Test case 2                                *
           ********************************************************************** */
        current_p_CsvDataOut = NULL;
        fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_FastInv47_2, "w+");

#ifdef LINKED_LIST_PARSER
        for ( angle_x = -0.00000001; angle_x >= -100000000; angle_x *= 1.01)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_FastInv47(angle_x);
            
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
        dataIndex = 0;
        f_divout = 0;
        f_reldiverr;
        f_maxerr = 0;
        f_inputmaxerr = 0;
        f_outputmaxerr = 0;
        for ( angle_x = -0.00000001; angle_x >= -100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

            p_CsvDataOut.value[dataIndex] = CML_FastInv47(angle_x);			
            f_divout = 1/angle_x;
            f_reldiverr = 100 * (f_divout - p_CsvDataOut.value[dataIndex])/f_divout;
            f_reldiverr = f_reldiverr < 0.0F ? -f_reldiverr : f_reldiverr;	
            if (f_reldiverr > f_maxerr ) 
            {
                f_maxerr = f_reldiverr;
                f_inputmaxerr = angle_x;
                f_outputmaxerr = p_CsvDataOut.value[dataIndex];
            }
            dataIndex++;
        }

        p_CsvDataOut.dataBufferSize = dataIndex;

        /* parse CSV values for expected results */
        //i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
        i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
        printf("CML_FastInv47 :Test case 2: maximum error = %g \n", f_maxerr);
        printf("CML_FastInv47 :Test case 2: input for max error = %g \n", f_inputmaxerr);
        printf("CML_FastInv47 :Test case 2: output for max error = %f \n\n\n", f_outputmaxerr);

#endif
        fclose(fp);
        /* Checks on global data */
        check_global_data();			
            
        }
    }	
}

void TEST_CLASS_CML_MISC::test_CML_FastInv23(int doIt)
{	
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_FastInv23_1   "test_001_CML_FastInv23_out_target.csv"
        #define TEST_CML_VECTOR_CSVOUT_CML_FastInv23_2   "test_002_CML_FastInv23_out_target.csv"	
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_FastInv23_1   "test_001_CML_FastInv23_out_msvc.csv"
        #define TEST_CML_VECTOR_CSVOUT_CML_FastInv23_2   "test_002_CML_FastInv23_out_msvc.csv"	
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_FastInv23_1, "w+");	

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

            *(temp_p_CsvDataOut->value) = CML_FastInv23(angle_x);
            
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
        float32 f_divout = 0;
        float32 f_reldiverr;
        float32 f_maxerr = 0;
        float32 f_inputmaxerr = 0;
        float32 f_outputmaxerr = 0;
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

            p_CsvDataOut.value[dataIndex] = CML_FastInv23(angle_x);				
            f_divout = 1/angle_x;
            f_reldiverr = 100 * (f_divout - p_CsvDataOut.value[dataIndex])/f_divout;
            f_reldiverr = f_reldiverr < 0.0F ? -f_reldiverr : f_reldiverr;	
            if (f_reldiverr > f_maxerr ) 
            {
                f_maxerr = f_reldiverr;
                f_inputmaxerr = angle_x;
                f_outputmaxerr = p_CsvDataOut.value[dataIndex];
            }
            dataIndex++;
        }

        p_CsvDataOut.dataBufferSize = dataIndex;

        /* parse CSV values for expected results */
        //i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
        i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
        printf("CML_FastInv23 : Test case 1: maximum error = %f \n", f_maxerr);
        printf("CML_FastInv23 : Test case 1: input for max error = %g \n", f_inputmaxerr);
        printf("CML_FastInv23 : Test case 1: output for max error = %f \n\n\n", f_outputmaxerr);

#endif
        fclose(fp);

          /* **********************************************************************
           *                         Test case 2                                *
           ********************************************************************** */
        current_p_CsvDataOut = NULL;
        fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_FastInv23_2, "w+");			

#ifdef LINKED_LIST_PARSER
        for ( angle_x = -0.00000001; angle_x >= -100000000; angle_x *= 1.01)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_FastInv23(angle_x);
            
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
        dataIndex = 0;
        f_divout = 0;
        f_reldiverr;
        f_maxerr = 0;
        f_inputmaxerr = 0;
        f_outputmaxerr = 0;
        for ( angle_x = -0.00000001; angle_x >= -100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

            p_CsvDataOut.value[dataIndex] = CML_FastInv23(angle_x);				
            f_divout = 1/angle_x;
            f_reldiverr = 100 * (f_divout - p_CsvDataOut.value[dataIndex])/f_divout;
            f_reldiverr = f_reldiverr < 0.0F ? -f_reldiverr : f_reldiverr;	
            if (f_reldiverr > f_maxerr ) 
            {
                f_maxerr = f_reldiverr;
                f_inputmaxerr = angle_x;
                f_outputmaxerr = p_CsvDataOut.value[dataIndex];
            }
            dataIndex++;
        }

        p_CsvDataOut.dataBufferSize = dataIndex;

        /* parse CSV values for expected results */
        //i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
        i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
        printf("CML_FastInv23 : Test case 2:  maximum error = %f \n", f_maxerr);
        printf("CML_FastInv23 : Test case 2: input for max error = %g \n", f_inputmaxerr);
        printf("CML_FastInv23 : Test case 2: output for max error = %f \n\n\n", f_outputmaxerr);

#endif
        fclose(fp);

        /* Checks on global data */
        check_global_data();			
            
        }
    }	
}

void TEST_CLASS_CML_MISC::test_CML_FastestInv(int doIt)
{	
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_FastestInv_1   "test_001_CML_FastestInv_out_target.csv"	
        #define TEST_CML_VECTOR_CSVOUT_CML_FastestInv_2   "test_002_CML_FastestInv_out_target.csv"	
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_FastestInv_1   "test_001_CML_FastestInv_out_msvc.csv"
        #define TEST_CML_VECTOR_CSVOUT_CML_FastestInv_2   "test_002_CML_FastestInv_out_msvc.csv"	
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_FastestInv_1, "w+");	

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

            *(temp_p_CsvDataOut->value) = CML_FastestInv(angle_x);
            
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
        float32 f_divout = 0;
        float32 f_reldiverr;
        float32 f_maxerr = 0;
        float32 f_inputmaxerr = 0;
        float32 f_outputmaxerr = 0;
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

            p_CsvDataOut.value[dataIndex] = CML_FastestInv(angle_x);
            f_divout = 1/angle_x;
            f_reldiverr = 100 * (f_divout - p_CsvDataOut.value[dataIndex])/f_divout;
            f_reldiverr = f_reldiverr < 0.0F ? -f_reldiverr : f_reldiverr;	
            if (f_reldiverr > f_maxerr ) 
            {
                f_maxerr = f_reldiverr;
                f_inputmaxerr = angle_x;
                f_outputmaxerr = p_CsvDataOut.value[dataIndex];
            }
            dataIndex++;
        }

        p_CsvDataOut.dataBufferSize = dataIndex;

        /* parse CSV values for expected results */
        //i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
        i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
        printf("CML_FastestInv : Test case 1: maximum error = %f \n", f_maxerr);
        printf("CML_FastestInv : Test case 1: input for max error = %g \n", f_inputmaxerr);
        printf("CML_FastestInv : Test case 1: output for max error = %f \n\n\n", f_outputmaxerr);
#endif
        fclose(fp);

        /* **********************************************************************
         *                         Test case 2                                *
         ********************************************************************** */
        current_p_CsvDataOut = NULL;
        fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_FastestInv_2, "w+");	

#ifdef LINKED_LIST_PARSER
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_FastestInv(angle_x);
            
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
        dataIndex = 0;
        f_divout = 0;
        f_reldiverr;
        f_maxerr = 0;
        f_inputmaxerr = 0;
        f_outputmaxerr = 0;
        for ( angle_x = -0.00000001; angle_x >= -100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

            //angle_x = 625.0;
            p_CsvDataOut.value[dataIndex] = CML_FastestInv(angle_x);
            f_divout = 1/angle_x;
            f_reldiverr = 100 * (f_divout - p_CsvDataOut.value[dataIndex])/f_divout;
            f_reldiverr = f_reldiverr < 0.0F ? -f_reldiverr : f_reldiverr;	
            if (f_reldiverr > f_maxerr ) 
            {
                f_maxerr = f_reldiverr;
                f_inputmaxerr = angle_x;
                f_outputmaxerr = p_CsvDataOut.value[dataIndex];
            }
            dataIndex++;
        }

        p_CsvDataOut.dataBufferSize = dataIndex;

        /* parse CSV values for expected results */
        //i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
        i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
        printf("CML_FastestInv : Test case 2: maximum error = %f \n", f_maxerr);
        printf("CML_FastestInv : Test case 2: input for max error = %g \n", f_inputmaxerr);
        printf("CML_FastestInv : Test case 2: output for max error = %f \n\n\n", f_outputmaxerr);

#endif
        fclose(fp);
        /* Checks on global data */
        check_global_data();			
            
        }
    }	
}


void TEST_CLASS_CML_MISC::test_CML_Sqrt14(int doIt)
{	
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_Sqrt14_1   "test_001_CML_Sqrt14_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_Sqrt14_1   "test_001_CML_Sqrt14_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_Sqrt14_1, "w+");	

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

            *(temp_p_CsvDataOut->value) = CML_Sqrt14(angle_x);
            
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
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

            p_CsvDataOut.value[dataIndex] = CML_Sqrt14(angle_x);			

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


void TEST_CLASS_CML_MISC::test_CML_Sqrt27(int doIt)
{	
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_Sqrt27_1   "test_001_CML_Sqrt27_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_Sqrt27_1   "test_001_CML_Sqrt27_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_Sqrt27_1, "w+");	

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

            *(temp_p_CsvDataOut->value) = CML_Sqrt27(angle_x);
            
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
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

            p_CsvDataOut.value[dataIndex] = CML_Sqrt27(angle_x);			

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

void TEST_CLASS_CML_MISC::test_CML_Sqrt53(int doIt)
{	
    if (doIt) 
    {
        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_Sqrt53_1   "test_001_CML_Sqrt53_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_Sqrt53_1   "test_001_CML_Sqrt53_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_Sqrt53_1, "w+");	

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

            *(temp_p_CsvDataOut->value) = CML_Sqrt53(angle_x);
            
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
        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

            //angle_x = 2.0;
            p_CsvDataOut.value[dataIndex] = CML_Sqrt53(angle_x);			

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


void TEST_CLASS_CML_MISC::test_CML_Sqrt69(int doIt)
{	
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_Sqrt67_1   "test_001_CML_Sqrt67_out_target.csv"	
        #define TEST_CML_VECTOR_CSVOUT_CML_Sqrt67_2   "test_002_CML_Sqrt67_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_Sqrt67_1   "test_001_CML_Sqrt67_out_msvc.csv"	
        #define TEST_CML_VECTOR_CSVOUT_CML_Sqrt67_2   "test_002_CML_Sqrt67_out_msvc.csv"	
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_Sqrt67_1, "w+");	

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

            *(temp_p_CsvDataOut->value) = CML_Sqrt67(angle_x);
            
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
        #ifdef ENABLE_PROFILER
        std::cout << "CML_Sqrt67 Test case 1 \n";		
        fprintf(fpTest, "CML_Sqrt67 Test case 1 \n");
        #endif /* #ifdef ENABLE_PROFILER */

        for ( angle_x = 0.00000001; angle_x <= 100000000; angle_x *= 1.01F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);	

            double ref_fout = sqrt((double)angle_x);
#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
            float32 test_out = CML_f_sqrt67(angle_x);
#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */	
            p_CsvDataOut.value[dataIndex] = test_out;

            double abs_err = abs(ref_fout - (double)test_out);			
            rel_err = abs(abs_err/ref_fout);
            if (rel_err >= max_err)
            {
                max_err = rel_err;
                input_err = angle_x;
            }

#ifdef ENABLE_PROFILER
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
        
        /* **********************************************************************
           *                         Test case 2                                *
           ********************************************************************** */
        csv_data_float_t *current_p_CsvDataOut = NULL;
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_Sqrt67_2, "w+");	

         dataIndex = 0;
         rel_err = 0;
         max_err = 0;
         input_err = 0;
        #ifdef ENABLE_PROFILER
        std::cout << "CML_Sqrt67 Test case 2 \n";		
        fprintf(fpTest, "CML_Sqrt67 Test case 2 \n");
        #endif /* #ifdef ENABLE_PROFILER */

        for ( angle_x = 0.0; angle_x <= 3.0e10F; angle_x += 1000000.F)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);		

            double  ref_fout = sqrt((double)angle_x);
#ifdef ENABLE_PROFILER
        start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
            float32 test_out = CML_f_sqrt67(angle_x);
#ifdef ENABLE_PROFILER
        stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */	
            p_CsvDataOut.value[dataIndex] = test_out;

            double abs_err = abs(ref_fout - (double)test_out);			
            rel_err = abs(abs_err/ref_fout);
            if (rel_err >= max_err)
            {
                max_err = rel_err;
                input_err = angle_x;
            }

#ifdef ENABLE_PROFILER
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

        fclose(fp);

        /* Checks on global data */
        check_global_data();			
        

        }
    }	
}

void TEST_CLASS_CML_MISC::test_CML_f_Sign(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_f_Sign_1   "test_001_CML_f_Sign_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_f_Sign_1   "test_001_CML_f_Sign_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_f_Sign_1, "w+");	

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
        for ( angle_x = -0.00000001; angle_x <= 100000000; angle_x *= 10)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_f_Sign(angle_x);
            
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
        for ( angle_x = -100000; angle_x <= 100000; angle_x += 1000)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

            p_CsvDataOut.value[dataIndex] = CML_f_Sign(angle_x);			

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

void TEST_CLASS_CML_MISC::test_CML_f_Mod(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_f_Mod_1   "test_001_CML_f_Mod_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_f_Mod_1   "test_001_CML_f_Mod_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_f_Mod_1, "w+");	

        /* input CSV data, linked list node*/
        /* CSV parser return value for result values file */
        sint32 i_CsvRetOut = -1;
        /* CSV parser return value for input values file */
        sint32 i_CsvRetIn = -1;
        float32 f_value,f_modulo, sine_result, Expected_sine_result;

        {
            /* Set global data */
        initialise_global_data();
        /* Set expected values for global data checks */
        initialise_expected_global_data();

        /* **********************************************************************
           *                         Test case 1                                *
           ********************************************************************** */
                
#ifdef LINKED_LIST_PARSER
        for ( f_value = 0.001; f_value <= 10000000; f_value *= 2)
        for ( f_modulo = 0.0000001; f_modulo <= 10000000; f_modulo *= 5)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_f_Mod(f_value,f_modulo);
            
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
        float32 rel_err =0;
        float32 max_err = 0, max_err_modulo, max_err_val;
        float32 input_err = 0, ref_fout = 0;

        for ( f_value = 0.001; f_value <= 10000000; f_value *= 2)
        for ( f_modulo = 0.0000001; f_modulo <= 10000000; f_modulo *= 5)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);	

            float32 ref_fout = f_value - f_modulo * floor(f_value/f_modulo);

            float32 test_out = CML_f_Mod(f_value,f_modulo);

            float32 abs_err = abs(ref_fout - test_out);
            rel_err = abs(abs_err/ref_fout);
            if (rel_err >= max_err)
            {
                max_err = rel_err;
                max_err_modulo = f_modulo;
                max_err_val = f_value;

            }
            p_CsvDataOut.value[dataIndex] = test_out;
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

void TEST_CLASS_CML_MISC::test_CML_f_Rem(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_f_Rem_1   "test_001_CML_f_Rem_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_f_Rem_1   "test_001_CML_f_Rem_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_f_Rem_1, "w+");	

        /* input CSV data, linked list node*/
        /* CSV parser return value for result values file */
        sint32 i_CsvRetOut = -1;
        /* CSV parser return value for input values file */
        sint32 i_CsvRetIn = -1;
        float32 f_dividend,f_divisor, sine_result, Expected_sine_result;

        {
            /* Set global data */
        initialise_global_data();
        /* Set expected values for global data checks */
        initialise_expected_global_data();

        /* **********************************************************************
           *                         Test case 1                                *
           ********************************************************************** */
                
#ifdef LINKED_LIST_PARSER
        for ( f_dividend = 0.001; f_dividend <= 10000000; f_dividend *= 2)
        for ( f_divisor = 0.0000001; f_divisor <= 10000000; f_divisor *= 5)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_f_Rem(f_dividend,f_divisor);
            
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
        float32 rel_err =0;
        float32 max_err = 0;
        float32 input_err_divid = 0, input_err_divis = 0;
        for ( f_dividend = 0.001; f_dividend <= 10000000; f_dividend *= 2)
        for ( f_divisor = 0.0000001; f_divisor <= 10000000; f_divisor *= 5)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);	
            float32 ref_fout =  f_dividend - f_divisor * floor(f_dividend/f_divisor);

            float32 test_out = CML_f_Rem(f_dividend,f_divisor);		
            p_CsvDataOut.value[dataIndex] = test_out;
            float32 abs_err = abs(ref_fout - test_out);
            rel_err = abs(abs_err/ref_fout);
            if (rel_err >= max_err)
            {
                max_err = rel_err;
                input_err_divid = f_dividend;
                input_err_divis = f_divisor;
            }
            p_CsvDataOut.value[dataIndex] = test_out;
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



void TEST_CLASS_CML_MISC::test_CML_f_ModReciprocal(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_f_ModReciprocal_1   "test_001_CML_f_ModReciprocal_out_target.csv"		
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_f_ModReciprocal_1   "test_001_CML_f_ModReciprocal_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_f_ModReciprocal_1, "w+");	

        /* input CSV data, linked list node*/
        /* CSV parser return value for result values file */
        sint32 i_CsvRetOut = -1;
        /* CSV parser return value for input values file */
        sint32 i_CsvRetIn = -1;
        float32 f_dividend,f_divisor, f_reciprocal, sine_result, Expected_sine_result;

        {
            /* Set global data */
        initialise_global_data();
        /* Set expected values for global data checks */

        initialise_expected_global_data();

        /* **********************************************************************
           *                         Test case 1                                *
           ********************************************************************** */
                
#ifdef LINKED_LIST_PARSER
        for ( f_dividend = 0.001; f_dividend <= 10000000; f_dividend *= 2)
        for ( f_divisor = C_QUARTERPI; f_divisor <= 32; f_divisor *= 2)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);
            
            f_reciprocal = 1/f_divisor;
            *(temp_p_CsvDataOut->value) = CML_f_ModReciprocal(f_dividend, f_reciprocal ,f_divisor );			
            
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
        float32 rel_err =0;
        float32 max_err = 0;
        float32 input_err_divid = 0, input_err_divis = 0;
        for ( f_dividend = 0.001; f_dividend <= 10000000; f_dividend *= 2)
        for ( f_divisor = C_QUARTERPI; f_divisor <= 32; f_divisor *= 2)
        {	

            f_reciprocal = 1/f_divisor;
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			
            
            float32 ref_fout = f_dividend - f_divisor * floor(f_dividend/f_divisor);
            float32 test_out = CML_f_ModReciprocal(f_dividend, f_reciprocal, f_divisor);
            p_CsvDataOut.value[dataIndex] = test_out;

            float32 abs_err = abs(ref_fout - test_out);
            rel_err = abs(abs_err/ref_fout);
            if (rel_err >= max_err)
            {
                max_err = rel_err;
                input_err_divid = f_dividend;
                input_err_divis = f_divisor;
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

void TEST_CLASS_CML_MISC::test_CML_s_CountNrOfBitsSet(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_s_CountNrOfBitsSet_TestCase_1  "test_001_CML_s_CountNrOfBitsSet_out_target.csv"	
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_s_CountNrOfBitsSet_TestCase_1  "test_001_CML_s_CountNrOfBitsSet_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_s_CountNrOfBitsSet_TestCase_1, "w+");	

        /* input CSV data, linked list node*/
        /* CSV parser return value for result values file */
        sint32 i_CsvRetOut = -1;
        /* CSV parser return value for input values file */
        sint32 i_CsvRetIn = -1;
        float32 sine_result, Expected_sine_result;
        uint32  input_uint_value = 0;
        sint32  input_sint_value = 0;

        {
            /* Set global data */
        initialise_global_data();
        /* Set expected values for global data checks */
        initialise_expected_global_data();

        /* **********************************************************************
           *                         Test case 1                                *
           ********************************************************************** */
                
#ifdef LINKED_LIST_PARSER
        for ( input_sint_value = 0x80000000; input_sint_value != 0xffffffff; input_sint_value >>= 1)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_s_CountNrOfBitsSet(input_sint_value);
            
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

        for ( input_uint_value = 0; input_uint_value < 4294967296/2; input_uint_value += 16777216)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_s_CountNrOfBitsSet(input_uint_value);
            
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
        for ( input_sint_value = 0x80000000; input_sint_value != 0xffffffff; input_sint_value >>= 1)
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);	
            p_CsvDataOut.value[dataIndex] = CML_s_CountNrOfBitsSet(input_sint_value);		

            dataIndex++;
        }

        for ( input_uint_value = 0; input_uint_value < 4294967296/2; input_uint_value += 16777216)			
        {			
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

            p_CsvDataOut.value[dataIndex] = CML_s_CountNrOfBitsSet(input_uint_value);		

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


void TEST_CLASS_CML_MISC::test_CML_s_GetLutIndex(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_s_GetLutIndex_TestCase_1  "test_001_CML_s_GetLutIndex_out_target.csv"	
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_s_GetLutIndex_TestCase_1  "test_001_CML_s_GetLutIndex_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_s_GetLutIndex_TestCase_1, "w+");	

        /* input CSV data, linked list node*/
        /* CSV parser return value for result values file */
        sint32 i_CsvRetOut = -1;
        /* CSV parser return value for input values file */
        sint32 i_CsvRetIn = -1;
        float32 f_InputValue, f_LutMinInputValue, f_LutRes, s_LutMinInd, s_LutMaxInd, sine_result, Expected_sine_result;
        
        {
            /* Set global data */
        initialise_global_data();
        /* Set expected values for global data checks */
        initialise_expected_global_data();

        /* **********************************************************************
           *                         Test case 1                                *
           ********************************************************************** */
                
#ifdef LINKED_LIST_PARSER	
        for(f_InputValue = 1; f_InputValue <=1000; f_InputValue+=100)
        for(f_LutRes = 1; f_LutRes <= 10; f_LutRes+=5)
        for(f_LutMinInputValue = 100; f_LutMinInputValue <= 1000; f_LutMinInputValue+=100)
        for(s_LutMinInd = 100; s_LutMinInd <= 10000; s_LutMinInd+=1000)
        for(s_LutMaxInd = 10000; s_LutMaxInd <= 20000; s_LutMaxInd+=1000)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_s_GetLutIndex(f_InputValue, f_LutMinInputValue, f_LutRes, s_LutMinInd, s_LutMaxInd);
            
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
        for(f_InputValue = 1; f_InputValue <=1000; f_InputValue+=100)
        for(f_LutRes = 1; f_LutRes <= 10; f_LutRes+=5)
        for(f_LutMinInputValue = 100; f_LutMinInputValue <= 1000; f_LutMinInputValue+=100)
        for(s_LutMinInd = 100; s_LutMinInd <= 10000; s_LutMinInd+=1000)
        for(s_LutMaxInd = 10000; s_LutMaxInd <= 20000; s_LutMaxInd+=1000)
        {
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

            p_CsvDataOut.value[dataIndex] = CML_s_GetLutIndex(f_InputValue, f_LutMinInputValue, f_LutRes, s_LutMinInd, s_LutMaxInd);

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

void TEST_CLASS_CML_MISC::test_CML_s_GetLutIndexBackwards(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_s_GetLutIndexBackwards_TestCase_1  "test_001_CML_s_GetLutIndexBackwards_out_target.csv"	
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_s_GetLutIndexBackwards_TestCase_1  "test_001_CML_s_GetLutIndexBackwards_out_msvc.csv"		
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
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_s_GetLutIndexBackwards_TestCase_1, "w+");	

        /* input CSV data, linked list node*/
        /* CSV parser return value for result values file */
        sint32 i_CsvRetOut = -1;
        /* CSV parser return value for input values file */
        sint32 i_CsvRetIn = -1;
        float32 f_InputValue, s_LutMinInd, s_LutMaxInd, sine_result, Expected_sine_result;
        
        {
            /* Set global data */
        initialise_global_data();
        /* Set expected values for global data checks */
        initialise_expected_global_data();

        /* **********************************************************************
           *                         Test case 1                                *
           ********************************************************************** */
                
#ifdef LINKED_LIST_PARSER
        for(f_InputValue = 1; f_InputValue <=1000; f_InputValue+=100)
        for(s_LutMinInd = 100; s_LutMinInd <= 10000; s_LutMinInd+=1000)
        for(s_LutMaxInd = 10000; s_LutMaxInd <= 20000; s_LutMaxInd+=1000)
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_s_GetLutIndexBackwards(f_InputValue, a_LUT, s_LutMinInd, s_LutMaxInd);
            
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
        for(int i = 10000; i <=11000; i++)
            data_log_buffer[i] = i-10000;

        for(f_InputValue = 1; f_InputValue <=1000; f_InputValue+=100)
        for(s_LutMinInd = 100; s_LutMinInd <= 10000; s_LutMinInd+=1000)
        for(s_LutMaxInd = 10000; s_LutMaxInd <= 20000; s_LutMaxInd+=1000)
        {
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

            p_CsvDataOut.value[dataIndex] = CML_s_GetLutIndexBackwards(f_InputValue, &data_log_buffer[10000], s_LutMinInd, s_LutMaxInd);

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


void TEST_CLASS_CML_MISC::test_CML_b_IsPointInsidePolygon(int doIt)
{
    if (doIt) 
    {

        /* Test case data declarations */
#ifdef TARGET_PLATFORM
        #define TEST_CML_VECTOR_CSVOUT_CML_b_IsPointInsidePolygon_TestCase_1  "test_001_CML_b_IsPointInsidePolygon_out_target.csv"	
#else
        #define TEST_CML_VECTOR_CSVOUT_CML_b_IsPointInsidePolygon_TestCase_1  "test_001_CML_b_IsPointInsidePolygon_out_msvc.csv"		
#endif

        float *p_Xarray, *p_Yarray, u_size, f_Xpoint, f_Ypoint;

        float32 f_power;
        float32 expected_returnValue;
        float32 returnValue;
        /* result CSV data, linked list node*/
#ifdef LINKED_LIST_PARSER
        csv_data_float_t *p_CsvDataOut = NULL;
#else
        csv_data_float_t p_CsvDataOut;
#endif

        int i;
        
        csv_data_float_t *current_p_CsvDataOut = NULL;
        FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_b_IsPointInsidePolygon_TestCase_1, "w+");	

        /* input CSV data, linked list node*/
        /* CSV parser return value for result values file */
        sint32 i_CsvRetOut = -1;
        /* CSV parser return value for input values file */
        sint32 i_CsvRetIn = -1;
        float32 f_InputValue, s_LutMinInd, s_LutMaxInd, sine_result, Expected_sine_result;

        CML_t_TrajRefPoint CML_t_TrajRefPoint_buffer;
        
        {
            /* Set global data */
        initialise_global_data();
        /* Set expected values for global data checks */
        initialise_expected_global_data();

        /* **********************************************************************
           *                         Test case 1                                *
           ********************************************************************** */
                
#ifdef LINKED_LIST_PARSER
        for(f_Xpos	= 1e-6;		 f_Xpos		<= 1e6; f_Xpos    *= 200.3333)		
        for(f_C0	= -300.0001; f_C0		<= 300; f_C0      += 200.1234)
        for(f_C1	= -400.1234; f_C1		<= 180; f_C1      += 99.1234 )
        for(f_Angle	= 1.001;     f_Angle	<= 180; f_Angle   *= 2.1234 )
        {
            csv_data_float_t *temp_p_CsvDataOut = NULL;
            temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
            temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
            temp_p_CsvDataOut->len = sizeof(float32);

            *(temp_p_CsvDataOut->value) = CML_b_IsPointInsidePolygon(a_Xarray, a_Yarray, u_size, f_Xpoint, f_Ypoint);
            
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

        p_Xarray = &data_log_buffer[10000];
        p_Yarray = &data_log_buffer[10100];

        p_Xarray[0] = 120.2345;
        p_Xarray[1] = 200.45;
        p_Xarray[2] = 160.11;
        p_Xarray[3] = 43.567;

        p_Yarray[0] = 345.456;
        p_Yarray[1] = 234.123;
        p_Yarray[2] = 180.234;
        p_Yarray[3] = 23.678;

        u_size = 4;
        
        for(f_Xpoint = 0.002234; f_Xpoint <= 200; f_Xpoint+=15.3)		
        for(f_Ypoint = 1.234578; f_Ypoint <= 500; f_Ypoint+=27.5)		
        {
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

            p_CsvDataOut.value[dataIndex] = CML_b_IsPointInsidePolygon(p_Xarray, p_Yarray, u_size, f_Xpoint, f_Ypoint);
            
            dataIndex++;
        }

        p_Xarray[0] = -13.67;
        p_Xarray[1] = -170.45;
        p_Xarray[2] = -1600.11;
        p_Xarray[3] = -700.567;
        p_Xarray[4] = 1.2345;
        p_Xarray[5] = 200.45;
        p_Xarray[6] = 7160.11;
        p_Xarray[7] = 443.567;

        p_Yarray[0] = 1700.456;
        p_Yarray[1] = 1254.123;
        p_Yarray[2] = -18.234;
        p_Yarray[3] = -73.678;
        p_Yarray[4] = -2034.456;
        p_Yarray[5] = -1678.123;
        p_Yarray[6] = 4.234;
        p_Yarray[7] = 243.678;

        u_size = 8;
        
        for(f_Xpoint = -5180.57645; f_Xpoint <= 10000; f_Xpoint+=200)		
        for(f_Ypoint = -6070.557;  f_Ypoint  <= 5000;  f_Ypoint+=200)		
        {
            p_CsvDataOut.value = data_log_buffer;
            p_CsvDataOut.len = sizeof(float32);			

            p_CsvDataOut.value[dataIndex] = CML_b_IsPointInsidePolygon(p_Xarray, p_Yarray, u_size, f_Xpoint, f_Ypoint);
            
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
