/*****************************************************************************/
/*                            Cantata Test Script                            */
/*****************************************************************************/
/*
*    Filename: test_cml_stl_algorithm.cpp
*    Author: uidr5285
*    Generated on: 12-Feb-2016 15:43:28
*    Generated from: cml_stl_algorithm.cpp
*/
/*****************************************************************************/
/* Environment Definition                                                    */
/*****************************************************************************/

#define TEST_SCRIPT_GENERATOR 2

typedef unsigned int long long uint64;

/* Include files from software under test */
#include <stdio.h>
#include <iostream>
#include <functional>
#include "cml_ext.h"
#include "glob_type.h"
#include "cml_stl_type_traits.h"
#include "cml_stl_point.h"
#include "cml_stl_matrix.h"
#include "cml_stl_array.h"
#include "cml_stl_array2d.h"
#include "cml_stl_vector.h"
#include "cml_stl_algorithm.h"
#include "cml_stl_list.h"

#ifdef ENABLE_PROFILER
#include <time.h>

#ifdef PROFILE_C6x_DSP
extern clock_t get_clock();
#else
extern unsigned int get_clock();
#endif /* #ifdef PROFILE_C6x_DSP */

extern int start_clock;
extern int stop_clock;
extern int overhead;
extern int total_cycles;
#endif /* ENABLE_PROFILER */

/* Test Log file */
extern FILE *fpTest;

/* The default value used for test script variables and stub returns*/
#define LOWER(x) (x - (0.01*x))
#define UPPER(x) (x + (0.01*x))

/* Global Functions */
/* None */

/* Global data */
#define UNSORTED 525, -632, 642, -652, -665, 675, -685, 695, 708, -717, 				\
	727, -737, -750, 760, -770, -783, 792, -450, -463, 472, 				\
	-482, 492, 505, -515, -162, 172, 185, -195, 205, -214, 				\
	-228, 237, -247, -260, 270, -280, 290, 303, -312, 322, 				\
	-332, -345, 355, -365, 374, 1028, -1037, 1047, -1057, -1070, 			\
	1080, -534, -548, 557, -567, 577, 590, -600, 610, 623, 				\
	-1090, 1099, 1112, -1122, -887, 897, 910, -920, 930, 943, 				\
	-952, 962, -972, -985, 995, -1005, 1015, 874, -887, 897, 				\
	910, -920, 930, 943, -952, 962, -972, -985, 995, -1005, 				\
	-868, 388, -397, 407, -417, -430, 440, 1015, -1207, 1217

#define ASCENDING -1207, -1122, -1090, -1070, -1057, -1037, -1005, -1005, -985, -985, 	\
	-972, -972, -952, -952, -920, -920, -887, -887, -868, -783, 			\
	-770, -750, -737, -717, -685, -665, -652, -632, -600, -567, 			\
	-548, -534, -515, -482, -463, -450, -430, -417, -397, -365, 			\
	-345, -332, -312, -280, -260, -247, -228, -214, -195, -162, 			\
	172, 185, 205, 237, 270, 290, 303, 322, 355, 374, 					\
	388, 407, 440, 472, 492, 505, 525, 557, 577, 590, 					\
	610, 623, 642, 675, 695, 708, 727, 760, 792, 874, 					\
	897, 897, 910, 910, 930, 930, 943, 943, 962, 962, 					\
	995, 995, 1015, 1015, 1028, 1047, 1080, 1099, 1112, 1217

#define DESCENDING 1217, 1112, 1099, 1080, 1047, 1028, 1015, 1015, 995, 995, 			\
	962, 962, 943, 943, 930, 930, 910, 910, 897, 897, 					\
	874, 792, 760, 727, 708, 695, 675, 642, 623, 610, 					\
	590, 577, 557, 525, 505, 492, 472, 440, 407, 388, 					\
	374, 355, 322, 303, 290, 270, 237, 205, 185, 172, 					\
	-162, -195, -214, -228, -247, -260, -280, -312, -332, -345, 			\
	-365, -397, -417, -430, -450, -463, -482, -515, -534, -548, 			\
	-567, -600, -632, -652, -665, -685, -717, -737, -750, -770, 			\
	-783, -868, -887, -887, -920, -920, -952, -952, -972, -972, 			\
	-985, -985, -1005, -1005, -1037, -1057, -1070, -1090, -1122, -1207

template< typename >
static bool check__boCompare( float fIst, float fSoll )
{
	float fTolerance = 0.001;

	if( fSoll != 0. )
	{
		fTolerance *= fSoll > 0. ? 1 : -1;
		fTolerance *= fSoll;
	}

	float fMin = fSoll - fTolerance;
	float fMax = fSoll + fTolerance;

	bool boRetVal = true;
	if( fIst > fMax )
	{
		//zu groﬂ    
		boRetVal = false;
	}
	if( fIst < fMin )
	{
		//zu klein    
		boRetVal = false;
	}


	return boRetVal;
}

template< typename >
static bool check__boCompare( char cIst, char cSoll )
{
	return cIst == cSoll;
}

template< typename T >
static bool check__boCompare( T Ist, T Soll )
{
	return Ist == Soll;
}

template < typename T, sint32 COLS, bool EXT_MEM >
static bool check__vArrayCompare(cml::CArrayStorage<T ,COLS, EXT_MEM > &oArray,cml::CArrayStorage<T ,COLS, EXT_MEM > &bArray)
{    
	int  iIndex= 0;
	bool flag = 1;
	for( int row=0; row<oArray.size(); row++ )
	{
			if(flag == 0)
				return flag;
			flag = check__boCompare(oArray[iIndex], bArray[iIndex]);
			iIndex++;
		//fprintf(fpTest, "\n");
	} 
	return flag;
}

template < typename T, sint32 COLS, bool EXT_MEM >
static bool check__vArrayCompare(cml::CArrayStorage<T ,COLS, EXT_MEM> &oArray,cml::CArrayStorage<const T ,COLS, EXT_MEM> &bArray)
{    
	int  iIndex= 0;
	bool flag = 1;
	for( int row=0; row<oArray.size(); row++ )
	{
			if(flag == 0)
				return flag;
			flag = check__boCompare(oArray[iIndex], bArray[iIndex]);
			iIndex++;
		//fprintf(fpTest, "\n");
	} 
	return flag;
}

/* This function prints the data contained in the CArray object. */
static void check__PrintValue(float Value, FILE *fpTest)
{
	fprintf(fpTest, "%f\t\t", Value);
}

static void check__PrintValue(int Value, FILE *fpTest)
{
	fprintf(fpTest, "%i\t\t", Value);
}

static void check__PrintValue(short Value, FILE *fpTest)
{
	fprintf(fpTest, "%i\t\t", Value);
}

static void check__PrintValue(char Value, FILE *fpTest)
{
	fprintf(fpTest, "%i\t\t", Value);
}

/* This function prints the data contained in the CArray object to a file. */
static void check__PrintValue_to_File(float Value, FILE *fpTest)
{
	fprintf(fpTest, "%f\t\t", Value);
}

static void check__PrintValue_to_File(int Value, FILE *fpTest)
{
	fprintf(fpTest, "%i\t\t", Value);
}

static void check__PrintValue_to_File(short Value, FILE *fpTest)
{
	fprintf(fpTest, "%i\t\t", Value);
}

static void check__PrintValue_to_File(char Value, FILE *fpTest)
{
	fprintf(fpTest, "%i\t\t", Value);
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

template < typename T, sint32 COLS, bool EXT_MEM >
static void check__vArrayPrint_to_File( cml::CArrayStorage<T ,COLS, EXT_MEM> &oArray, FILE *fpTest)
{    
	int  iIndex= 0;
	for( int row=0; row<oArray.size(); row++ )
	{
			check__PrintValue_to_File(oArray[iIndex], fpTest);
			iIndex++;
		//fprintf(fpTest, "\n");
	} 

	fprintf(fpTest, "\n\n");
}

template < typename T, sint32 COLS, bool EXT_MEM >
static void check__vArrayPrint_to_console( cml::CArrayStorage<T ,COLS, EXT_MEM> &oArray)
{    
	int  iIndex= 0;
	for( int row=0; row<oArray.size(); row++ )
	{
			check__PrintValue_to_console(oArray[iIndex]);
			iIndex++;
		//fprintf(fpTest, "\n");
	} 


	fprintf(fpTest, "\n\n");
}




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
	std::cout << "\nStatus ---> PASS\n\n"; 
	fprintf(fpTest, "\nStatus ---> PASS\n\n");
}

/*****************************************************************************/
/* Test class declaration                                                    */
/*****************************************************************************/
class TEST_CLASS_ALGORITHM
{
public:
	void run_tests_algorithm();
	void test_cml_algorithm_nth_element(int doIt);
	void test_cml_algorithm_median(int doIt);
	void test_cml_algorithm_sort(int doIt);
	void test_cml_algorithm_sort_TiOpt_01(int doIt);
	void test_cml_algorithm_sort_TiOpt_02(int doIt);
	void test_cml_algorithm_find(int doIt);
	void test_cml_algorithm_lower_bound(int doIt);
	void test_cml_algorithm_SPow_pow(int doIt);
	void test_cml_algorithm_pow(int doIt);
	void test_cml_algorithm_clamp(int doIt);
	void test_cml_algorithm_max(int doIt);
	void test_cml_algorithm_min(int doIt);
	void test_cml_algorithm_sgn(int doIt);
	void test_cml_algorithm__sort_TiOpt_iteration_01(int doIt);
	void test_cml_algorithm__sort_TiOpt_iteration_02(int doIt);
};

/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_stl_algorithm(void)
{
	TEST_CLASS_ALGORITHM test_object;

	std::cout << "******** Start Testing: Algorithm Library functions ********\n\n";
	fprintf(fpTest, "******** Start Testing: Algorithm Library functions ********\n\n");

	test_object.run_tests_algorithm();

	std::cout << "End of Testing: Algorithm Library functions\n\n";
	fprintf(fpTest, "End of Testing: Algorithm Library functions\n\n");

	return;
}


/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS_ALGORITHM::run_tests_algorithm()
{
	test_cml_algorithm_nth_element(1);
	test_cml_algorithm_median(1);
	test_cml_algorithm_sort(1);
	test_cml_algorithm_sort_TiOpt_01(1);
	test_cml_algorithm_sort_TiOpt_02(1);
	test_cml_algorithm_find(1);
	test_cml_algorithm_lower_bound(1);
	test_cml_algorithm_SPow_pow(1);
	test_cml_algorithm_pow(1);
	test_cml_algorithm_clamp(1);
	test_cml_algorithm_max(1);
	test_cml_algorithm_min(1);
	test_cml_algorithm_sgn(1);
	test_cml_algorithm__sort_TiOpt_iteration_01(1);
	test_cml_algorithm__sort_TiOpt_iteration_02(1);
}

/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/
void TEST_CLASS_ALGORITHM::test_cml_algorithm_nth_element(int doIt)
{
	std::cout << "START ---> test_cml_algorithm_nth_element\n\n";		
	fprintf(fpTest, "START ---> test_cml_algorithm_nth_element\n\n");

	fprintf(fpTest, "Function Name ---> nth_element() \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_001\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");
		
		/* Test case data declarations */
		cml::CArray<int, 1, false> Array;
		cml::CArray<int, 1, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		Array[0] = 1;
		expected_Array[0] = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_002\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");
		
		/* Test case data declarations */
		cml::CArray<int, 2, false> Array;
		cml::CArray<int, 2, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		Array[0] = 1;
		Array[1] = 2;
		expected_Array[0] = 1;
		expected_Array[1] = 2;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_003\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");
		
		/* Test case data declarations */
		cml::CArray<int, 2, false> Array;
		cml::CArray<int, 2, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		Array[0] = 2;
		Array[1] = 1;
		expected_Array[0] = 1;
		expected_Array[1] = 2;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_004\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CArray<int, 5, false> Array;
		cml::CArray<int, 5, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		
		int j = 1;
		
		for(cml::CArray<int, 5, false>::it i = Array.begin(); i != Array.end(); i++)
		{
			*i = j;
			j++;
		}
		j = 1;
		for(cml::CArray<int, 5, false>::it i = expected_Array.begin(); i != expected_Array.end(); i++)
		{
			*i = j;
			j++;
		}
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{		
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_005\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_005\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CArray<int, 5, false> Array;
		cml::CArray<int, 5, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		
		int j = 5;
		
		for(cml::CArray<int, 5, false>::it i = Array.begin(); i != Array.end(); i++)
		{
			*i = j;
			j--;
		}
		j = 1;
		for(cml::CArray<int, 5, false>::it i = expected_Array.begin(); i != expected_Array.end(); i++)
		{
			*i = j;
			j++;
		}
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_006\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_006\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CArray<int, 5, false> Array;
		cml::CArray<int, 5, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		
		int j = 0;
		
		Array[0] = 3;
		Array[1] = 1;
		Array[2] = 4;
		Array[3] = 2;
		Array[4] = 0;

		for(cml::CArray<int, 5, false>::it i = expected_Array.begin(); i != expected_Array.end(); i++)
		{
			*i = j;
			j++;
		}
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_007\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_007\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");
		
		/* Test case data declarations */
		cml::CArray<char, 1, false> Array;
		cml::CArray<char, 1, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		Array[0] = 1;
		expected_Array[0] = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_008\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_008\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");
		
		/* Test case data declarations */
		cml::CArray<char, 2, false> Array;
		cml::CArray<char, 2, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		Array[0] = 1;
		Array[1] = 2;
		expected_Array[0] = 1;
		expected_Array[1] = 2;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_009\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_009\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");
		
		/* Test case data declarations */
		cml::CArray<char, 2, false> Array;
		cml::CArray<char, 2, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		Array[0] = 2;
		Array[1] = 1;
		expected_Array[0] = 1;
		expected_Array[1] = 2;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_010\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_010\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CArray<char, 5, false> Array;
		cml::CArray<char, 5, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		
		int j = 1;
		
		for(cml::CArray<char, 5, false>::it i = Array.begin(); i != Array.end(); i++)
		{
			*i = j;
			j++;
		}
		j = 1;
		for(cml::CArray<char, 5, false>::it i = expected_Array.begin(); i != expected_Array.end(); i++)
		{
			*i = j;
			j++;
		}
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{		
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_011\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_011\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CArray<char, 5, false> Array;
		cml::CArray<char, 5, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		
		int j = 5;
		
		for(cml::CArray<char, 5, false>::it i = Array.begin(); i != Array.end(); i++)
		{
			*i = j;
			j--;
		}
		j = 1;
		for(cml::CArray<char, 5, false>::it i = expected_Array.begin(); i != expected_Array.end(); i++)
		{
			*i = j;
			j++;
		}
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_012\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_012\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CArray<char, 5, false> Array;
		cml::CArray<char, 5, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		
		int j = 0;
		
		Array[0] = 3;
		Array[1] = 1;
		Array[2] = 4;
		Array[3] = 2;
		Array[4] = 0;

		for(cml::CArray<char, 5, false>::it i = expected_Array.begin(); i != expected_Array.end(); i++)
		{
			*i = j;
			j++;
		}
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_013\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_013\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");
		
		/* Test case data declarations */
		cml::CArray<short, 1, false> Array;
		cml::CArray<short, 1, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		Array[0] = 1;
		expected_Array[0] = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_014\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_014\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");
		
		/* Test case data declarations */
		cml::CArray<short, 2, false> Array;
		cml::CArray<short, 2, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		Array[0] = 1;
		Array[1] = 2;
		expected_Array[0] = 1;
		expected_Array[1] = 2;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_015\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_015\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");
		
		/* Test case data declarations */
		cml::CArray<short, 2, false> Array;
		cml::CArray<short, 2, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		Array[0] = 2;
		Array[1] = 1;
		expected_Array[0] = 1;
		expected_Array[1] = 2;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_016\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_016\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CArray<short, 5, false> Array;
		cml::CArray<short, 5, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		
		int j = 1;
		
		for(cml::CArray<short, 5, false>::it i = Array.begin(); i != Array.end(); i++)
		{
			*i = j;
			j++;
		}
		j = 1;
		for(cml::CArray<short, 5, false>::it i = expected_Array.begin(); i != expected_Array.end(); i++)
		{
			*i = j;
			j++;
		}
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{		
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_017\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_017\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CArray<short, 5, false> Array;
		cml::CArray<short, 5, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		
		int j = 5;
		
		for(cml::CArray<short, 5, false>::it i = Array.begin(); i != Array.end(); i++)
		{
			*i = j;
			j--;
		}
		j = 1;
		for(cml::CArray<short, 5, false>::it i = expected_Array.begin(); i != expected_Array.end(); i++)
		{
			*i = j;
			j++;
		}
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_018\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_018\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CArray<short, 5, false> Array;
		cml::CArray<short, 5, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		
		int j = 0;
		
		Array[0] = 3;
		Array[1] = 1;
		Array[2] = 4;
		Array[3] = 2;
		Array[4] = 0;

		for(cml::CArray<short, 5, false>::it i = expected_Array.begin(); i != expected_Array.end(); i++)
		{
			*i = j;
			j++;
		}
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_019\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_019\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");
		
		/* Test case data declarations */
		cml::CArray<float, 1, false> Array;
		cml::CArray<float, 1, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		Array[0] = 1;
		expected_Array[0] = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_020\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_020\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");
		
		/* Test case data declarations */
		cml::CArray<float, 2, false> Array;
		cml::CArray<float, 2, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		Array[0] = 1;
		Array[1] = 2;
		expected_Array[0] = 1;
		expected_Array[1] = 2;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_021\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_021\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");
		
		/* Test case data declarations */
		cml::CArray<float, 2, false> Array;
		cml::CArray<float, 2, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		Array[0] = 2;
		Array[1] = 1;
		expected_Array[0] = 1;
		expected_Array[1] = 2;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_022\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_022\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CArray<float, 5, false> Array;
		cml::CArray<float, 5, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		
		int j = 1;
		
		for(cml::CArray<float, 5, false>::it i = Array.begin(); i != Array.end(); i++)
		{
			*i = j;
			j++;
		}
		j = 1;
		for(cml::CArray<float, 5, false>::it i = expected_Array.begin(); i != expected_Array.end(); i++)
		{
			*i = j;
			j++;
		}
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{		
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_023\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_023\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CArray<float, 5, false> Array;
		cml::CArray<float, 5, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		
		int j = 5;
		
		for(cml::CArray<float, 5, false>::it i = Array.begin(); i != Array.end(); i++)
		{
			*i = j;
			j--;
		}
		j = 1;
		for(cml::CArray<float, 5, false>::it i = expected_Array.begin(); i != expected_Array.end(); i++)
		{
			*i = j;
			j++;
		}
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_nth_element_024\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_nth_element_024\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CArray<float, 5, false> Array;
		cml::CArray<float, 5, false> expected_Array;

		/* Set global data */
		initialise_global_data();
		
		int j = 0;
		
		Array[0] = 3;
		Array[1] = 1;
		Array[2] = 4;
		Array[3] = 2;
		Array[4] = 0;

		for(cml::CArray<float, 5, false>::it i = expected_Array.begin(); i != expected_Array.end(); i++)
		{
			*i = j;
			j++;
		}
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);
		
		/* Set expected values for global data checks */

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		//test_nth_element_TC001(Array);
		cml::nth_element(Array.begin(), Array.begin()+0, Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}
	}
	std::cout << "END ---> test_cml_algorithm_nth_element\n\n";
	fprintf(fpTest, "END ---> test_cml_algorithm_nth_element\n\n");
}

void TEST_CLASS_ALGORITHM::test_cml_algorithm_median(int doIt)
{
	std::cout << "START ---> test_cml_algorithm_median\n\n";		
	fprintf(fpTest, "START ---> test_cml_algorithm_median\n\n");

	fprintf(fpTest, "Function Name ---> median() \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_algorithm_median_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_median_001\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");


		/* Test case data declarations */
		cml::CArray<int, 5, false> Array;

		int return_value;
		int expected_return_value;

		/* Set global data */
		initialise_global_data();
		Array[0] = 5;
		Array[1] = 4;
		Array[2] = 3;
		Array[3] = 2;
		Array[4] = 1;

		/* Set expected values for global data checks */
		expected_return_value = 3;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_return_value);
		check__PrintValue_to_File( expected_return_value, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		return_value = cml::median(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( return_value);
		check__PrintValue_to_File( return_value, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(return_value,expected_return_value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_median_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_median_003\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");


		/* Test case data declarations */
		cml::CArray<char, 5, false> Array;

		char return_value;
		char expected_return_value;

		/* Set global data */
		initialise_global_data();
		Array[0] = 5;
		Array[1] = 4;
		Array[2] = 3;
		Array[3] = 2;
		Array[4] = 1;

		/* Set expected values for global data checks */
		expected_return_value = 3;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_return_value);
		check__PrintValue_to_File( expected_return_value, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		return_value = cml::median(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( return_value);
		check__PrintValue_to_File( return_value, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(return_value,expected_return_value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_median_005\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_median_005\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");


		/* Test case data declarations */
		cml::CArray<short, 5, false> Array;

		short return_value;
		short expected_return_value;

		/* Set global data */
		initialise_global_data();
		Array[0] = 5;
		Array[1] = 4;
		Array[2] = 3;
		Array[3] = 2;
		Array[4] = 1;

		/* Set expected values for global data checks */
		expected_return_value = 3;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_return_value);
		check__PrintValue_to_File( expected_return_value, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		return_value = cml::median(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( return_value);
		check__PrintValue_to_File( return_value, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(return_value,expected_return_value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_median_007\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_median_007\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");


		/* Test case data declarations */
		cml::CArray<float, 5, false> Array;

		float return_value;
		float expected_return_value;

		/* Set global data */
		initialise_global_data();
		Array[0] = 5;
		Array[1] = 4;
		Array[2] = 3;
		Array[3] = 2;
		Array[4] = 1;

		/* Set expected values for global data checks */
		expected_return_value = 3;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_return_value);
		check__PrintValue_to_File( expected_return_value, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		return_value = cml::median(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( return_value);
		check__PrintValue_to_File( return_value, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(return_value,expected_return_value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

	}
	std::cout << "END ---> test_cml_algorithm_median\n\n";
	fprintf(fpTest, "END ---> test_cml_algorithm_median\n\n");
}

void TEST_CLASS_ALGORITHM::test_cml_algorithm_sort(int doIt)
{
	std::cout << "START ---> test_cml_algorithm_sort\n\n";		
	fprintf(fpTest, "START ---> test_cml_algorithm_sort\n\n");

	fprintf(fpTest, "Function Name ---> sort() \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_001\n\n");

		std::cout << "Data Dimension ---> 8 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 8 \n\n");
		
		/* Test case data declarations */
		cml::CArray<int, 8, false> Array;
		cml::CArray<int, 8, false> expected_Array;

		/* Set global data */
		Array[0] = 10;
		Array[1] = 9;
		Array[2] = 8;
		Array[3] = 7;
		Array[4] = 6;
		Array[5] = 8;
		Array[6] = 9;
		Array[7] = 10;

		/* Set expected values for global data checks */
		expected_Array[0] = 6;
		expected_Array[1] = 7;
		expected_Array[2] = 8;
		expected_Array[3] = 8;
		expected_Array[4] = 9;
		expected_Array[5] = 9;
		expected_Array[6] = 10;
		expected_Array[7] = 10;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::sort(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_002\n\n");

		std::cout << "Data Dimension ---> 8 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 8 \n\n");
		
		/* Test case data declarations */
		cml::CArray<int, 8, false> Array;
		cml::CArray<int, 8, false> expected_Array;

		/* Set global data */
		for(int i = 0, j = 1; i < 8; i++, j++)
		{
			Array[i] = j;
		}

		/* Set expected values for global data checks */
		for(int i = 0, j = 1; i < 8; i++, j++)
		{
			expected_Array[i] = j;
		}


		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::sort(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_003\n\n");

		std::cout << "Data Dimension ---> 8 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 8 \n\n");
		
		/* Test case data declarations */
		cml::CArray<int, 8, false> Array;
		cml::CArray<int, 8, false> expected_Array;

		/* Set global data */
		for(int i = 0, j = 8; i < 8; i++, j--)
		{
			Array[i] = j;
		}

		/* Set expected values for global data checks */
		for(int i = 0, j = 1; i < 8; i++, j++)
		{
			expected_Array[i] = j;
		}

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::sort(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_004\n\n");

		std::cout << "Data Dimension ---> 8 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 8 \n\n");
		
		/* Test case data declarations */
		cml::CArray<int, 8, false> Array;
		cml::CArray<int, 8, false> expected_Array;

		/* Set global data */
		Array[0] = 9;
		Array[1] = 2;
		Array[2] = 1;
		Array[3] = 11;
		Array[4] = 3;
		Array[5] = 4;
		Array[6] = 5;
		Array[7] = 10;

		/* Set expected values for global data checks */
		expected_Array[0] = 1;
		expected_Array[1] = 2;
		expected_Array[2] = 3;
		expected_Array[3] = 4;
		expected_Array[4] = 5;
		expected_Array[5] = 9;
		expected_Array[6] = 10;
		expected_Array[7] = 11;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::sort(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_005\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_005\n\n");

		std::cout << "Data Dimension ---> 8 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 8 \n\n");
		
		/* Test case data declarations */
		cml::CArray<char, 8, false> Array;
		cml::CArray<char, 8, false> expected_Array;

		/* Set global data */
		Array[0] = 10;
		Array[1] = 9;
		Array[2] = 8;
		Array[3] = 7;
		Array[4] = 6;
		Array[5] = 8;
		Array[6] = 9;
		Array[7] = 10;

		/* Set expected values for global data checks */
		expected_Array[0] = 6;
		expected_Array[1] = 7;
		expected_Array[2] = 8;
		expected_Array[3] = 8;
		expected_Array[4] = 9;
		expected_Array[5] = 9;
		expected_Array[6] = 10;
		expected_Array[7] = 10;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::sort(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_006\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_006\n\n");

		std::cout << "Data Dimension ---> 8 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 8 \n\n");
		
		/* Test case data declarations */
		cml::CArray<char, 8, false> Array;
		cml::CArray<char, 8, false> expected_Array;

		/* Set global data */
		for(int i = 0, j = 1; i < 8; i++, j++)
		{
			Array[i] = j;
		}

		/* Set expected values for global data checks */
		for(int i = 0, j = 1; i < 8; i++, j++)
		{
			expected_Array[i] = j;
		}

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::sort(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_007\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_007\n\n");

		std::cout << "Data Dimension ---> 8 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 8 \n\n");
		
		/* Test case data declarations */
		cml::CArray<char, 8, false> Array;
		cml::CArray<char, 8, false> expected_Array;

		/* Set global data */
		for(int i = 0, j = 8; i < 8; i++, j--)
		{
			Array[i] = j;
		}

		/* Set expected values for global data checks */
		for(int i = 0, j = 1; i < 8; i++, j++)
		{
			expected_Array[i] = j;
		}

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::sort(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_008\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_008\n\n");

		std::cout << "Data Dimension ---> 8 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 8 \n\n");
		
		/* Test case data declarations */
		cml::CArray<char, 8, false> Array;
		cml::CArray<char, 8, false> expected_Array;

		/* Set global data */
		Array[0] = 9;
		Array[1] = 2;
		Array[2] = 1;
		Array[3] = 11;
		Array[4] = 3;
		Array[5] = 4;
		Array[6] = 5;
		Array[7] = 10;

		/* Set expected values for global data checks */
		expected_Array[0] = 1;
		expected_Array[1] = 2;
		expected_Array[2] = 3;
		expected_Array[3] = 4;
		expected_Array[4] = 5;
		expected_Array[5] = 9;
		expected_Array[6] = 10;
		expected_Array[7] = 11;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::sort(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_009\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_009\n\n");

		std::cout << "Data Dimension ---> 8 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 8 \n\n");
		
		/* Test case data declarations */
		cml::CArray<short, 8, false> Array;
		cml::CArray<short, 8, false> expected_Array;

		/* Set global data */
		Array[0] = 10;
		Array[1] = 9;
		Array[2] = 8;
		Array[3] = 7;
		Array[4] = 6;
		Array[5] = 8;
		Array[6] = 9;
		Array[7] = 10;

		/* Set expected values for global data checks */
		expected_Array[0] = 6;
		expected_Array[1] = 7;
		expected_Array[2] = 8;
		expected_Array[3] = 8;
		expected_Array[4] = 9;
		expected_Array[5] = 9;
		expected_Array[6] = 10;
		expected_Array[7] = 10;


		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::sort(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_010\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_010\n\n");

		std::cout << "Data Dimension ---> 8 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 8 \n\n");
		
		/* Test case data declarations */
		cml::CArray<short, 8, false> Array;
		cml::CArray<short, 8, false> expected_Array;

		/* Set global data */
		for(int i = 0, j = 1; i < 8; i++, j++)
		{
			Array[i] = j;
		}

		/* Set expected values for global data checks */
		for(int i = 0, j = 1; i < 8; i++, j++)
		{
			expected_Array[i] = j;
		}

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::sort(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_011\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_011\n\n");

		std::cout << "Data Dimension ---> 8 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 8 \n\n");
		
		/* Test case data declarations */
		cml::CArray<short, 8, false> Array;
		cml::CArray<short, 8, false> expected_Array;

		/* Set global data */
		for(int i = 0, j = 8; i < 8; i++, j--)
		{
			Array[i] = j;
		}

		/* Set expected values for global data checks */
		for(int i = 0, j = 1; i < 8; i++, j++)
		{
			expected_Array[i] = j;
		}

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::sort(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_012\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_012\n\n");

		std::cout << "Data Dimension ---> 8 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 8 \n\n");
		
		/* Test case data declarations */
		cml::CArray<short, 8, false> Array;
		cml::CArray<short, 8, false> expected_Array;

		/* Set global data */
		Array[0] = 9;
		Array[1] = 2;
		Array[2] = 1;
		Array[3] = 11;
		Array[4] = 3;
		Array[5] = 4;
		Array[6] = 5;
		Array[7] = 10;

		/* Set expected values for global data checks */
		expected_Array[0] = 1;
		expected_Array[1] = 2;
		expected_Array[2] = 3;
		expected_Array[3] = 4;
		expected_Array[4] = 5;
		expected_Array[5] = 9;
		expected_Array[6] = 10;
		expected_Array[7] = 11;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::sort(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}
				
		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_013\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_013\n\n");

		std::cout << "Data Dimension ---> 8 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 8 \n\n");
		
		/* Test case data declarations */
		cml::CArray<short, 8, false> Array;
		cml::CArray<short, 8, false> expected_Array;

		/* Set global data */
		Array[0] = 10;
		Array[1] = 9;
		Array[2] = 8;
		Array[3] = 7;
		Array[4] = 6;
		Array[5] = 8;
		Array[6] = 9;
		Array[7] = 10;

		/* Set expected values for global data checks */
		expected_Array[0] = 6;
		expected_Array[1] = 7;
		expected_Array[2] = 8;
		expected_Array[3] = 8;
		expected_Array[4] = 9;
		expected_Array[5] = 9;
		expected_Array[6] = 10;
		expected_Array[7] = 10;


		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::sort(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_014\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_014\n\n");

		std::cout << "Data Dimension ---> 8 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 8 \n\n");
		
		/* Test case data declarations */
		cml::CArray<float, 8, false> Array;
		cml::CArray<float, 8, false> expected_Array;

		/* Set global data */
		for(int i = 0, j = 1; i < 8; i++, j++)
		{
			Array[i] = j;
		}

		/* Set expected values for global data checks */
		for(int i = 0, j = 1; i < 8; i++, j++)
		{
			expected_Array[i] = j;
		}


		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::sort(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_015\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_015\n\n");

		std::cout << "Data Dimension ---> 8 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 8 \n\n");
		
		/* Test case data declarations */
		cml::CArray<float, 8, false> Array;
		cml::CArray<float, 8, false> expected_Array;

		/* Set global data */
		for(int i = 0, j = 8; i < 8; i++, j--)
		{
			Array[i] = j;
		}

		/* Set expected values for global data checks */
		for(int i = 0, j = 1; i < 8; i++, j++)
		{
			expected_Array[i] = j;
		}


		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::sort(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_016\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_016\n\n");

		std::cout << "Data Dimension ---> 8 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 8 \n\n");
		
		/* Test case data declarations */
		cml::CArray<float, 8, false> Array;
		cml::CArray<float, 8, false> expected_Array;

		/* Set global data */
		Array[0] = 9;
		Array[1] = 2;
		Array[2] = 1;
		Array[3] = 11;
		Array[4] = 3;
		Array[5] = 4;
		Array[6] = 5;
		Array[7] = 10;

		/* Set expected values for global data checks */
		expected_Array[0] = 1;
		expected_Array[1] = 2;
		expected_Array[2] = 3;
		expected_Array[3] = 4;
		expected_Array[4] = 5;
		expected_Array[5] = 9;
		expected_Array[6] = 10;
		expected_Array[7] = 11;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::sort(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_017\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_017\n\n");

		std::cout << "Data Dimension ---> 100 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 100 \n\n");
		
		/* Test case data declarations */
		int unsortedArray[100] = {UNSORTED};
		int sortedArray[100] = {ASCENDING};
		cml::CArray<int, 100, false> Array(unsortedArray);
		cml::CArray<int, 100, false> expected_Array(sortedArray);

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::sort(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_018\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_018\n\n");

		std::cout << "Data Dimension ---> 100 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 100 \n\n");
		
		/* Test case data declarations */
		float unsortedArray[100] = {UNSORTED};
		float sortedArray[100] = {ASCENDING};
		cml::CArray<float, 100, false> Array(unsortedArray);
		cml::CArray<float, 100, false> expected_Array(sortedArray);

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::sort(Array.begin(), Array.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

	}
	std::cout << "END ---> test_cml_algorithm_sort\n\n";
	fprintf(fpTest, "END ---> test_cml_algorithm_sort\n\n");
}

void TEST_CLASS_ALGORITHM::test_cml_algorithm_sort_TiOpt_01(int doIt)
{
	std::cout << "START ---> test_cml_algorithm_sort_TiOpt_01\n\n";		
	fprintf(fpTest, "START ---> test_cml_algorithm_sort_TiOpt_01\n\n");

	fprintf(fpTest, "Function Name ---> sort_TiOpt() \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_TiOpt_01_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_TiOpt_01_001\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");


		/* Test case data declarations */
		cml::CArray<int, 5> Array;
		cml::CArray<int, 5> expected_Array;
		cml::CArray<int, 5> scratchMem;

		/* Set global data */
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 1;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_Array[0] = 1;
		expected_Array[1] = 2;
		expected_Array[2] = 3;
		expected_Array[3] = 5;
		expected_Array[4] = 7;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		cml::sort_TiOpt(Array.begin(), Array.end(), scratchMem.begin());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_TiOpt_01_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_TiOpt_01_002\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");


		/* Test case data declarations */
		cml::CArray<char, 5> Array;
		cml::CArray<char, 5> expected_Array;
		cml::CArray<char, 5> scratchMem;

		/* Set global data */
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 1;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_Array[0] = 1;
		expected_Array[1] = 2;
		expected_Array[2] = 3;
		expected_Array[3] = 5;
		expected_Array[4] = 7;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		cml::sort_TiOpt(Array.begin(), Array.end(), scratchMem.begin());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_TiOpt_01_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_TiOpt_01_003\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");


		/* Test case data declarations */
		cml::CArray<short, 5> Array;
		cml::CArray<short, 5> expected_Array;
		cml::CArray<short, 5> scratchMem;

		/* Set global data */
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 1;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_Array[0] = 1;
		expected_Array[1] = 2;
		expected_Array[2] = 3;
		expected_Array[3] = 5;
		expected_Array[4] = 7;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		cml::sort_TiOpt(Array.begin(), Array.end(), scratchMem.begin());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_TiOpt_01_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_TiOpt_01_004\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");


		/* Test case data declarations */
		cml::CArray<float, 5> Array;
		cml::CArray<float, 5> expected_Array;
		cml::CArray<float, 5> scratchMem;

		/* Set global data */
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 1;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_Array[0] = 1;
		expected_Array[1] = 2;
		expected_Array[2] = 3;
		expected_Array[3] = 5;
		expected_Array[4] = 7;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		cml::sort_TiOpt(Array.begin(), Array.end(), scratchMem.begin());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

	}
	std::cout << "END ---> test_cml_algorithm_sort_TiOpt_01\n\n";
	fprintf(fpTest, "END ---> test_cml_algorithm_sort_TiOpt_01\n\n");
}

void TEST_CLASS_ALGORITHM::test_cml_algorithm_sort_TiOpt_02(int doIt)
{
	std::cout << "START ---> test_cml_algorithm_sort_TiOpt_02\n\n";		
	fprintf(fpTest, "START ---> test_cml_algorithm_sort_TiOpt_02\n\n");

	fprintf(fpTest, "Function Name ---> sort_TiOpt() \n\n");
	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_TiOpt_02_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_TiOpt_02_001\n\n");

		std::cout << "Data Dimension ---> 100 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 100 \n\n");


		/* Test case data declarations */
		int unsortedArray[100] = {UNSORTED};
		int sortedArray[100] = {ASCENDING};

		/* Set global data */
		cml::CArray<int, 100> Array(unsortedArray);
		cml::CArray<int, 100> scratchMem;

		/* Set expected values for global data checks */
		cml::CArray<int, 100> expected_Array(sortedArray);

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		cml::sort_TiOpt(Array.begin(), Array.end(), scratchMem.begin(), std::less<int>());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_TiOpt_02_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_TiOpt_02_002\n\n");

		std::cout << "Data Dimension ---> 100 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 100 \n\n");


		/* Test case data declarations */
		int unsortedArray[100] = {UNSORTED};
		int sortedArray[100] = {DESCENDING};

		/* Set global data */
		cml::CArray<int, 100> Array(unsortedArray);
		cml::CArray<int, 100> scratchMem;

		/* Set expected values for global data checks */
		cml::CArray<int, 100> expected_Array(sortedArray);

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		cml::sort_TiOpt(Array.begin(), Array.end(), scratchMem.begin(), std::greater<int>());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_TiOpt_02_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_TiOpt_02_003\n\n");

		std::cout << "Data Dimension ---> 100 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 100 \n\n");


		/* Test case data declarations */
		short unsortedArray[100] = {UNSORTED};
		short sortedArray[100] = {ASCENDING};

		/* Set global data */
		cml::CArray<short, 100> Array(unsortedArray);
		cml::CArray<short, 100> scratchMem;

		/* Set expected values for global data checks */
		cml::CArray<short, 100> expected_Array(sortedArray);

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		cml::sort_TiOpt(Array.begin(), Array.end(), scratchMem.begin(), std::less<short>());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_TiOpt_02_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_TiOpt_02_004\n\n");

		std::cout << "Data Dimension ---> 100 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 100 \n\n");


		/* Test case data declarations */
		short unsortedArray[100] = {UNSORTED};
		short sortedArray[100] = {DESCENDING};

		/* Set global data */
		cml::CArray<short, 100> Array(unsortedArray);
		cml::CArray<short, 100> scratchMem;

		/* Set expected values for global data checks */
		cml::CArray<short, 100> expected_Array(sortedArray);

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		cml::sort_TiOpt(Array.begin(), Array.end(), scratchMem.begin(), std::greater<short>());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_TiOpt_02_005\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_TiOpt_02_005\n\n");

		std::cout << "Data Dimension ---> 100 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 100 \n\n");


		/* Test case data declarations */
		float unsortedArray[100] = {UNSORTED};
		float sortedArray[100] = {ASCENDING};

		/* Set global data */
		cml::CArray<float, 100> Array(unsortedArray);
		cml::CArray<float, 100> scratchMem;

		/* Set expected values for global data checks */
		cml::CArray<float, 100> expected_Array(sortedArray);

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		cml::sort_TiOpt(Array.begin(), Array.end(), scratchMem.begin(), std::less<float>());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sort_TiOpt_02_006\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sort_TiOpt_02_006\n\n");

		std::cout << "Data Dimension ---> 100 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 100 \n\n");


		/* Test case data declarations */
		float unsortedArray[100] = {UNSORTED};
		float sortedArray[100] = {DESCENDING};

		/* Set global data */
		cml::CArray<float, 100> Array(unsortedArray);
		cml::CArray<float, 100> scratchMem;

		/* Set expected values for global data checks */
		cml::CArray<float, 100> expected_Array(sortedArray);

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		cml::sort_TiOpt(Array.begin(), Array.end(), scratchMem.begin(), std::greater<float>());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

	}
	std::cout << "END ---> test_cml_algorithm_sort_TiOpt_02\n\n";
	fprintf(fpTest, "END ---> test_cml_algorithm_sort_TiOpt_02\n\n");
}

void TEST_CLASS_ALGORITHM::test_cml_algorithm_find(int doIt)
{
	std::cout << "START ---> test_cml_algorithm_find\n\n";		
	fprintf(fpTest, "START ---> test_cml_algorithm_find\n\n");

	fprintf(fpTest, "Function Name ---> find() \n\n");
	if (doIt) 
	{
		{
		std::cout << "Test Case ---> happy \n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_find_001\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Test case data declarations */
		cml::CArray<int, 5> Array;
		int val;

		cml::CArray<int, 5>::it result;
		cml::CArray<int, 5>::it expected_returnValue;

		/* Set global data */
		val = 9;
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 1;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_returnValue = Array.end()-1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");


		check__PrintValue_to_console( *expected_returnValue);
		check__PrintValue_to_File( *expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::find(Array.begin(), Array.end(), val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( *(result-1));
		check__PrintValue_to_File( *(result-1), fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*(result-1),*expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_find_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_find_002\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Test case data declarations */
		cml::CArray<int, 5> Array;
		int val;

		cml::CArray<int, 5>::it result;
		cml::CArray<int, 5>::it expected_returnValue;

		/* Set global data */
		val = 2;
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 1;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_returnValue = Array.begin() + 2;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( *expected_returnValue);
		check__PrintValue_to_File( *expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::find(Array.begin(), Array.end(), val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( *result);
		check__PrintValue_to_File( *result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*result,*expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_find_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_find_003\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Test case data declarations */
		cml::CArray<char, 5> Array;
		char val;

		cml::CArray<char, 5>::it result;
		cml::CArray<char, 5>::it expected_returnValue;

		/* Set global data */
		val = 9;
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 1;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_returnValue = Array.end()-1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");


		check__PrintValue_to_console( *expected_returnValue);
		check__PrintValue_to_File( *expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::find(Array.begin(), Array.end(), val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( *(result-1));
		check__PrintValue_to_File( *(result-1), fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*(result-1),*expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_find_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_find_004\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Test case data declarations */
		cml::CArray<char, 5> Array;
		char val;

		cml::CArray<char, 5>::it result;
		cml::CArray<char, 5>::it expected_returnValue;

		/* Set global data */
		val = 2;
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 1;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_returnValue = Array.begin() + 2;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( *expected_returnValue);
		check__PrintValue_to_File( *expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::find(Array.begin(), Array.end(), val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( *result);
		check__PrintValue_to_File( *result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*result,*expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_find_005\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_find_005\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Test case data declarations */
		cml::CArray<short, 5> Array;
		short val;

		cml::CArray<short, 5>::it result;
		cml::CArray<short, 5>::it expected_returnValue;

		/* Set global data */
		val = 9;
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 1;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_returnValue = Array.end()-1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");


		check__PrintValue_to_console( *expected_returnValue);
		check__PrintValue_to_File( *expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::find(Array.begin(), Array.end(), val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( *(result-1));
		check__PrintValue_to_File( *(result-1), fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*(result-1),*expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_find_006\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_find_006\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Test case data declarations */
		cml::CArray<short, 5> Array;
		short val;

		cml::CArray<short, 5>::it result;
		cml::CArray<short, 5>::it expected_returnValue;

		/* Set global data */
		val = 2;
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 1;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_returnValue = Array.begin() + 2;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( *expected_returnValue);
		check__PrintValue_to_File( *expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::find(Array.begin(), Array.end(), val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( *result);
		check__PrintValue_to_File( *result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*result,*expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_find_007\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_find_007\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Test case data declarations */
		cml::CArray<float, 5> Array;
		float val;

		cml::CArray<float, 5>::it result;
		cml::CArray<float, 5>::it expected_returnValue;

		/* Set global data */
		val = 9;
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 1;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_returnValue = Array.end()-1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");


		check__PrintValue_to_console( *expected_returnValue);
		check__PrintValue_to_File( *expected_returnValue, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::find(Array.begin(), Array.end(), val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( *(result-1));
		check__PrintValue_to_File( *(result-1), fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*(result-1),*expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_find_008\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_find_008\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Test case data declarations */
		cml::CArray<float, 5> Array;
		float val;

		cml::CArray<float, 5>::it result;
		cml::CArray<float, 5>::it expected_returnValue;

		/* Set global data */
		val = 2;
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 1;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_returnValue = Array.begin() + 2;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( *expected_returnValue);
		check__PrintValue_to_File( *expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::find(Array.begin(), Array.end(), val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( *result);
		check__PrintValue_to_File( *result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*result,*expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}
	}
	std::cout << "END ---> test_cml_algorithm_find\n\n";
	fprintf(fpTest, "END ---> test_cml_algorithm_find\n\n");

}

void TEST_CLASS_ALGORITHM::test_cml_algorithm_lower_bound(int doIt)
{
	std::cout << "START ---> test_cml_algorithm_lower_bound\n\n";		
	fprintf(fpTest, "START ---> test_cml_algorithm_lower_bound\n\n");

	fprintf(fpTest, "Function Name ---> lower_bound() \n\n");
	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_algorithm_lower_bound_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_lower_bound_001\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Test case data declarations */
		cml::CArray<int, 5> Array;
		int val;

		cml::CArray<int, 5>::it result;
		cml::CArray<int, 5>::it expected_returnValue;

		/* Set global data */
		val = 0;
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 1;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_returnValue = Array.begin();
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( *expected_returnValue);
		check__PrintValue_to_File( *expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		//result = cml::find(Array.begin(), Array.end(), val);
		result = cml::lower_bound(Array.begin(), Array.end(), val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( *result);
		check__PrintValue_to_File( *result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*result,*expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_lower_bound_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_lower_bound_002\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Test case data declarations */
		cml::CArray<int, 5> Array;
		int val;

		cml::CArray<int, 5>::it result;
		cml::CArray<int, 5>::it expected_returnValue;

		/* Set global data */
		val = 6;
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 8;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_returnValue = Array.begin()+3;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( *expected_returnValue);
		check__PrintValue_to_File( *expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		//result = cml::find(Array.begin(), Array.end(), val);
		result = cml::lower_bound(Array.begin(), Array.end(), val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( *result);
		check__PrintValue_to_File( *result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*result,*expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_lower_bound_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_lower_bound_003\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Test case data declarations */
		cml::CArray<int, 5> Array;
		int val;

		cml::CArray<int, 5>::it result;
		cml::CArray<int, 5>::it expected_returnValue;

		/* Set global data */
		val = 9;
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 8;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_returnValue = Array.end()-1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( *expected_returnValue);
		check__PrintValue_to_File( *expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		//result = cml::find(Array.begin(), Array.end(), val);
		result = cml::lower_bound(Array.begin(), Array.end(), val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( *(result-1));
		check__PrintValue_to_File( *(result-1), fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*(result-1),*expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_lower_bound_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_lower_bound_004\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Test case data declarations */
		cml::CArray<char, 5> Array;
		char val;

		cml::CArray<char, 5>::it result;
		cml::CArray<char, 5>::it expected_returnValue;

		/* Set global data */
		val = 0;
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 1;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_returnValue = Array.begin();
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( *expected_returnValue);
		check__PrintValue_to_File( *expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		//result = cml::find(Array.begin(), Array.end(), val);
		result = cml::lower_bound(Array.begin(), Array.end(), val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( *result);
		check__PrintValue_to_File( *result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*result,*expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_lower_bound_005\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_lower_bound_005\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Test case data declarations */
		cml::CArray<char, 5> Array;
		char val;

		cml::CArray<char, 5>::it result;
		cml::CArray<char, 5>::it expected_returnValue;

		/* Set global data */
		val = 6;
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 8;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_returnValue = Array.begin()+3;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( *expected_returnValue);
		check__PrintValue_to_File( *expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		//result = cml::find(Array.begin(), Array.end(), val);
		result = cml::lower_bound(Array.begin(), Array.end(), val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( *result);
		check__PrintValue_to_File( *result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*result,*expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_lower_bound_006\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_lower_bound_006\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Test case data declarations */
		cml::CArray<char, 5> Array;
		char val;

		cml::CArray<char, 5>::it result;
		cml::CArray<char, 5>::it expected_returnValue;

		/* Set global data */
		val = 9;
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 8;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_returnValue = Array.end()-1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( *expected_returnValue);
		check__PrintValue_to_File( *expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		//result = cml::find(Array.begin(), Array.end(), val);
		result = cml::lower_bound(Array.begin(), Array.end(), val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( *(result-1));
		check__PrintValue_to_File( *(result-1), fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*(result-1),*expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_lower_bound_007\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_lower_bound_007\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Test case data declarations */
		cml::CArray<short, 5> Array;
		short val;

		cml::CArray<short, 5>::it result;
		cml::CArray<short, 5>::it expected_returnValue;

		/* Set global data */
		val = 0;
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 1;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_returnValue = Array.begin();
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( *expected_returnValue);
		check__PrintValue_to_File( *expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		//result = cml::find(Array.begin(), Array.end(), val);
		result = cml::lower_bound(Array.begin(), Array.end(), val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( *result);
		check__PrintValue_to_File( *result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*result,*expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

				{
		std::cout << "Test Case ---> test_cml_algorithm_lower_bound_008\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_lower_bound_008\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Test case data declarations */
		cml::CArray<short, 5> Array;
		short val;

		cml::CArray<short, 5>::it result;
		cml::CArray<short, 5>::it expected_returnValue;

		/* Set global data */
		val = 6;
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 8;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_returnValue = Array.begin() +3;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( *expected_returnValue);
		check__PrintValue_to_File( *expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		//result = cml::find(Array.begin(), Array.end(), val);
		result = cml::lower_bound(Array.begin(), Array.end(), val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( *result);
		check__PrintValue_to_File( *result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*result,*expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_lower_bound_009\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_lower_bound_009\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Test case data declarations */
		cml::CArray<short, 5> Array;
		short val;

		cml::CArray<short, 5>::it result;
		cml::CArray<short, 5>::it expected_returnValue;

		/* Set global data */
		val = 9;
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 8;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_returnValue = Array.end()-1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( *expected_returnValue);
		check__PrintValue_to_File( *expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		//result = cml::find(Array.begin(), Array.end(), val);
		result = cml::lower_bound(Array.begin(), Array.end(), val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( *(result-1));
		check__PrintValue_to_File( *(result-1), fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*(result-1),*expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_lower_bound_010\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_lower_bound_010\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Test case data declarations */
		cml::CArray<float, 5> Array;
		float val;

		cml::CArray<float, 5>::it result;
		cml::CArray<float, 5>::it expected_returnValue;

		/* Set global data */
		val = 0;
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 1;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_returnValue = Array.begin();
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( *expected_returnValue);
		check__PrintValue_to_File( *expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		//result = cml::find(Array.begin(), Array.end(), val);
		result = cml::lower_bound(Array.begin(), Array.end(), val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( *result);
		check__PrintValue_to_File( *result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*result,*expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_lower_bound_011\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_lower_bound_011\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Test case data declarations */
		cml::CArray<float, 5> Array;
		float val;

		cml::CArray<float, 5>::it result;
		cml::CArray<float, 5>::it expected_returnValue;

		/* Set global data */
		val = 6;
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 8;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_returnValue = Array.begin() + 3;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( *expected_returnValue);
		check__PrintValue_to_File( *expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		//result = cml::find(Array.begin(), Array.end(), val);
		result = cml::lower_bound(Array.begin(), Array.end(), val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( *result);
		check__PrintValue_to_File( *result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*result,*expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_lower_bound_012\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_lower_bound_012\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Test case data declarations */
		cml::CArray<float, 5> Array;
		float val;

		cml::CArray<float, 5>::it result;
		cml::CArray<float, 5>::it expected_returnValue;

		/* Set global data */
		val = 9;
		Array[0] = 5;
		Array[1] = 3;
		Array[2] = 2;
		Array[3] = 8;
		Array[4] = 7;

		/* Set expected values for global data checks */
		expected_returnValue = Array.end()-1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( *expected_returnValue);
		check__PrintValue_to_File( *expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		//result = cml::find(Array.begin(), Array.end(), val);
		result = cml::lower_bound(Array.begin(), Array.end(), val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( *(result-1));
		check__PrintValue_to_File( *(result-1), fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*(result-1),*expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}
	}
	std::cout << "END ---> test_cml_algorithm_lower_bound\n\n";
	fprintf(fpTest, "END ---> test_cml_algorithm_lower_bound\n\n");

}


void TEST_CLASS_ALGORITHM::test_cml_algorithm_SPow_pow(int doIt)
{
	std::cout << "START ---> test_cml_algorithm_SPow_pow\n\n";		
	fprintf(fpTest, "START ---> test_cml_algorithm_SPow_pow\n\n");

	fprintf(fpTest, "Function Name ---> pow() \n\n");
	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_algorithm_SPow_pow_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_SPow_pow_001\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		uint32 POWER;
		int val;

		int result;
		int expected_returnValue;

		/* Set global data */
		val = 2;
		POWER = 4;

		/* Set expected values for global data checks */
		expected_returnValue = 16;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");


		
		/* Call SUT */
		cml::SPow<4, int> Obj;

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		result = Obj.pow(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_SPow_pow_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_SPow_pow_002\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		uint32 POWER;
		float val;

		float result;
		float expected_returnValue;

		/* Set global data */
		val = 1.2;
		POWER = 4;

		/* Set expected values for global data checks */
		expected_returnValue = 2.0736f;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Call SUT */
		cml::SPow<4, float> Obj;

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		result = Obj.pow(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> Precision Difference \n\n");
		std::cout << "Remarks ---> Precision Difference \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_SPow_pow_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_SPow_pow_003\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		uint32 POWER;
		float val;

		float result;
		float expected_returnValue;

		/* Set global data */
		val = 1.2;
		POWER = 0;

		/* Set expected values for global data checks */
		expected_returnValue = 1.0f;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Call SUT */
		cml::SPow<0, float> Obj;

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		result = Obj.pow(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

	}
	std::cout << "END ---> test_cml_algorithm_SPow_pow\n\n";
	fprintf(fpTest, "END ---> test_cml_algorithm_SPow_pow\n\n");
}

#if 0
void TEST_CLASS_ALGORITHM::test_cml_algorithm_SPow_pow(int doIt)
{
	if (doIt) 
	{
		/************************* Test Case 001 *************************/
		START_TEST("test_cml_algorithm_SPow_pow_001",
			"Description: \
			- cml_stl_algorithm.h : static inline T pow(const T& val) \
			- Testing: interface, boundary_condition  \
			- Overview: Implements the power of input value using a recursive template. \
			- Entry conditions: Data Type is int \
			- Expected results: Power of the input value based on the template parameter POWER"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Test case data declarations */
			uint32 POWER;
		int val;

		int returnValue;
		int expected_returnValue;

		/* Set global data */
		val = 2;
		POWER = 4;

		/* Set expected values for global data checks */
		expected_returnValue = 16;

		/* Call SUT */
		returnValue = test_SPow_pow_TC01(val);

		/* Test Checks */
		CHECK_U_INT(returnValue, expected_returnValue);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		/************************* Test Case 002 *************************/
		START_TEST("test_cml_algorithm_SPow_pow_002",
			"Description: \
			- cml_stl_algorithm.h : static inline T pow(const T& val) \
			- Testing: interface, boundary_condition  \
			- Overview: Implements the power of input value using a recursive template. \
			- Entry conditions: Data Type is float \
			- Expected results: Power of the input value based on the template parameter POWER"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Test case data declarations */
			uint32 POWER;
		float val;

		float returnValue;
		float expected_returnValue;

		/* Set global data */
		val = 1.2;
		POWER = 4;

		/* Set expected values for global data checks */
		expected_returnValue = 2.0736f;

		/* Call SUT */
		returnValue = test_SPow_pow_TC02(val);

		/* Test Checks */
		CHECK_DOUBLE_RANGE(returnValue, LOWER(expected_returnValue), UPPER(expected_returnValue));

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		/************************* Test Case 003 *************************/
		START_TEST("test_cml_algorithm_SPow_pow_003",
			"Description: \
			- cml_stl_algorithm.h : static inline T pow(const T& val) \
			- Testing: interface, boundary_condition  \
			- Overview: Implements the power of input value using a recursive template. \
			- Entry conditions: Data Type is float \
			Power = 0\
			- Expected results: return 1"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Test case data declarations */
			uint32 POWER;
		float val;

		float returnValue;
		float expected_returnValue;

		/* Set global data */
		val = 1.2;
		POWER = 0;

		/* Set expected values for global data checks */
		expected_returnValue = 1.0f;

		/* Call SUT */
		returnValue = test_SPow_pow_TC03(val);

		/* Test Checks */
		CHECK_DOUBLE_RANGE(returnValue, LOWER(expected_returnValue), UPPER(expected_returnValue));

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}
#endif

void TEST_CLASS_ALGORITHM::test_cml_algorithm_pow(int doIt)
{
	std::cout << "START ---> test_cml_algorithm_pow\n\n";		
	fprintf(fpTest, "START ---> test_cml_algorithm_pow\n\n");

	fprintf(fpTest, "Function Name ---> pow() \n\n");
	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_algorithm_pow_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_pow_001\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		uint32 POWER;
		int val;

		int result;
		int expected_returnValue;

		/* Set global data */
		val = 2;
		POWER = 4;

		/* Set expected values for global data checks */
		expected_returnValue = 16;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		
		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::pow<4, int>(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_pow_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_pow_002\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		uint32 POWER;
		char val;

		char result;
		char expected_returnValue;

		/* Set global data */
		val = 2;
		POWER = 4;

		/* Set expected values for global data checks */
		expected_returnValue = 16;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::pow<4, char>(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_pow_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_pow_003\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		uint32 POWER;
		short val;

		short result;
		short expected_returnValue;

		/* Set global data */
		val = 2;
		POWER = 4;

		/* Set expected values for global data checks */
		expected_returnValue = 16;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::pow<4, short>(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_pow_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_pow_004\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		uint32 POWER;
		float val;

		float result;
		float expected_returnValue;

		/* Set global data */
		val = 2;
		POWER = 4;

		/* Set expected values for global data checks */
		expected_returnValue = 16;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::pow<4, float>(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

	}
	std::cout << "END ---> test_cml_algorithm_pow\n\n";
	fprintf(fpTest, "END ---> test_cml_algorithm_pow\n\n");
}

void TEST_CLASS_ALGORITHM::test_cml_algorithm_clamp(int doIt)
{
	std::cout << "START ---> test_cml_algorithm_clamp\n\n";		
	fprintf(fpTest, "START ---> test_cml_algorithm_clamp\n\n");

	fprintf(fpTest, "Function Name ---> clamp() \n\n");
	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_algorithm_clamp_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_clamp_001\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		int min;
		int max;
		int val;
		int result;
		int expected_returnValue;

		/* Set global data */
		min = 1;
		max = 4;
		val = 2;

		/* Set expected values for global data checks */
		expected_returnValue = 2;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::clamp(min, max, val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_clamp_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_clamp_002\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		int min;
		int max;
		int val;
		int result;
		int expected_returnValue;

		/* Set global data */
		min = 1;
		max = 4;
		val = 0;

		/* Set expected values for global data checks */
		expected_returnValue = 1;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::clamp(min, max, val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_clamp_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_clamp_003\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		int min;
		int max;
		int val;
		int result;
		int expected_returnValue;

		/* Set global data */
		min = 1;
		max = 4;
		val = 5;

		/* Set expected values for global data checks */
		expected_returnValue = 4;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::clamp(min, max, val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_clamp_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_clamp_004\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		char min;
		char max;
		char val;
		char result;
		char expected_returnValue;

		/* Set global data */
		min = 1;
		max = 4;
		val = 2;

		/* Set expected values for global data checks */
		expected_returnValue = 2;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::clamp(min, max, val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

				{
		std::cout << "Test Case ---> test_cml_algorithm_clamp_005\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_clamp_005\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		char min;
		char max;
		char val;
		char result;
		char expected_returnValue;

		/* Set global data */
		min = 1;
		max = 4;
		val = 0;

		/* Set expected values for global data checks */
		expected_returnValue = 1;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::clamp(min, max, val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_clamp_006\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_clamp_006\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		char min;
		char max;
		char val;
		char result;
		char expected_returnValue;

		/* Set global data */
		min = 1;
		max = 4;
		val = 5;

		/* Set expected values for global data checks */
		expected_returnValue = 4;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::clamp(min, max, val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_clamp_007\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_clamp_007\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		short min;
		short max;
		short val;
		short result;
		short expected_returnValue;

		/* Set global data */
		min = 1;
		max = 4;
		val = 2;

		/* Set expected values for global data checks */
		expected_returnValue = 2;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::clamp(min, max, val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_clamp_008\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_clamp_008\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		short min;
		short max;
		short val;
		short result;
		short expected_returnValue;

		/* Set global data */
		min = 1;
		max = 4;
		val = 0;

		/* Set expected values for global data checks */
		expected_returnValue = 1;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::clamp(min, max, val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_clamp_009\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_clamp_009\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		short min;
		short max;
		short val;
		short result;
		short expected_returnValue;

		/* Set global data */
		min = 1;
		max = 4;
		val = 5;

		/* Set expected values for global data checks */
		expected_returnValue = 4;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::clamp(min, max, val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_clamp_010\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_clamp_010\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		float min;
		float max;
		float val;
		float result;
		float expected_returnValue;

		/* Set global data */
		min = 1;
		max = 4;
		val = 2;

		/* Set expected values for global data checks */
		expected_returnValue = 2;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::clamp(min, max, val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_clamp_011\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_clamp_011\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		float min;
		float max;
		float val;
		float result;
		float expected_returnValue;

		/* Set global data */
		min = 1;
		max = 4;
		val = 0;

		/* Set expected values for global data checks */
		expected_returnValue = 1;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::clamp(min, max, val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_clamp_012\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_clamp_012\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		float min;
		float max;
		float val;
		float result;
		float expected_returnValue;

		/* Set global data */
		min = 1;
		max = 4;
		val = 5;

		/* Set expected values for global data checks */
		expected_returnValue = 4;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::clamp(min, max, val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}
	}
	std::cout << "END ---> test_cml_algorithm_clamp\n\n";
	fprintf(fpTest, "END ---> test_cml_algorithm_clamp\n\n");
}

void TEST_CLASS_ALGORITHM::test_cml_algorithm_max(int doIt)
{
	std::cout << "START ---> test_cml_algorithm_max\n\n";		
	fprintf(fpTest, "START ---> test_cml_algorithm_max\n\n");

	fprintf(fpTest, "Function Name ---> max() \n\n");
	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_algorithm_max_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_max_001\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		int lhs;
		int rhs;
		int result;
		int expected_returnValue;

		/* Set global data */
		lhs = 1;
		rhs = 4;

		/* Set expected values for global data checks */
		expected_returnValue = 4;


		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( lhs);
		check__PrintValue_to_File( lhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		std::cout << "input2 = \n";	
		fprintf(fpTest, "input2 = \n");

		check__PrintValue_to_console( rhs);
		check__PrintValue_to_File( rhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::max(lhs, rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_max_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_max_002\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		int lhs;
		int rhs;
		int result;
		int expected_returnValue;

		/* Set global data */
		lhs = 4;
		rhs = 1;

		/* Set expected values for global data checks */
		expected_returnValue = 4;


		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( lhs);
		check__PrintValue_to_File( lhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		std::cout << "input2 = \n";	
		fprintf(fpTest, "input2 = \n");

		check__PrintValue_to_console( rhs);
		check__PrintValue_to_File( rhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::max(lhs, rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_max_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_max_003\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		char lhs;
		char rhs;
		char result;
		char expected_returnValue;

		/* Set global data */
		lhs = 1;
		rhs = 4;

		/* Set expected values for global data checks */
		expected_returnValue = 4;


		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( lhs);
		check__PrintValue_to_File( lhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		std::cout << "input2 = \n";	
		fprintf(fpTest, "input2 = \n");

		check__PrintValue_to_console( rhs);
		check__PrintValue_to_File( rhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::max(lhs, rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_max_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_max_004\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		char lhs;
		char rhs;
		char result;
		char expected_returnValue;

		/* Set global data */
		lhs = 4;
		rhs = 1;

		/* Set expected values for global data checks */
		expected_returnValue = 4;


		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( lhs);
		check__PrintValue_to_File( lhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		std::cout << "input2 = \n";	
		fprintf(fpTest, "input2 = \n");

		check__PrintValue_to_console( rhs);
		check__PrintValue_to_File( rhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::max(lhs, rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_max_005\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_max_005\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		short lhs;
		short rhs;
		short result;
		short expected_returnValue;

		/* Set global data */
		lhs = 1;
		rhs = 4;

		/* Set expected values for global data checks */
		expected_returnValue = 4;


		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( lhs);
		check__PrintValue_to_File( lhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		std::cout << "input2 = \n";	
		fprintf(fpTest, "input2 = \n");

		check__PrintValue_to_console( rhs);
		check__PrintValue_to_File( rhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::max(lhs, rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_max_006\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_max_006\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		short lhs;
		short rhs;
		short result;
		short expected_returnValue;

		/* Set global data */
		lhs = 4;
		rhs = 1;

		/* Set expected values for global data checks */
		expected_returnValue = 4;


		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( lhs);
		check__PrintValue_to_File( lhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		std::cout << "input2 = \n";	
		fprintf(fpTest, "input2 = \n");

		check__PrintValue_to_console( rhs);
		check__PrintValue_to_File( rhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::max(lhs, rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_max_007\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_max_007\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		float lhs;
		float rhs;
		float result;
		float expected_returnValue;

		/* Set global data */
		lhs = 1;
		rhs = 4;

		/* Set expected values for global data checks */
		expected_returnValue = 4;


		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( lhs);
		check__PrintValue_to_File( lhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		std::cout << "input2 = \n";	
		fprintf(fpTest, "input2 = \n");

		check__PrintValue_to_console( rhs);
		check__PrintValue_to_File( rhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::max(lhs, rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_max_008\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_max_008\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		float lhs;
		float rhs;
		float result;
		float expected_returnValue;

		/* Set global data */
		lhs = 4;
		rhs = 1;

		/* Set expected values for global data checks */
		expected_returnValue = 4;


		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( lhs);
		check__PrintValue_to_File( lhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		std::cout << "input2 = \n";	
		fprintf(fpTest, "input2 = \n");

		check__PrintValue_to_console( rhs);
		check__PrintValue_to_File( rhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::max(lhs, rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

	}
	std::cout << "END ---> test_cml_algorithm_max\n\n";
	fprintf(fpTest, "END ---> test_cml_algorithm_max\n\n");
}

void TEST_CLASS_ALGORITHM::test_cml_algorithm_min(int doIt)
{
	std::cout << "START ---> test_cml_algorithm_min\n\n";		
	fprintf(fpTest, "START ---> test_cml_algorithm_min\n\n");

	fprintf(fpTest, "Function Name ---> min() \n\n");
	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_algorithm_min_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_min_001\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		int lhs;
		int rhs;
		int result;
		int expected_returnValue;

		/* Set global data */
		lhs = 1;
		rhs = 4;

		/* Set expected values for global data checks */
		expected_returnValue = 1;


		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( lhs);
		check__PrintValue_to_File( lhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		std::cout << "input2 = \n";	
		fprintf(fpTest, "input2 = \n");

		check__PrintValue_to_console( rhs);
		check__PrintValue_to_File( rhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::min(lhs, rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_min_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_min_002\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		int lhs;
		int rhs;
		int result;
		int expected_returnValue;

		/* Set global data */
		lhs = 4;
		rhs = 1;

		/* Set expected values for global data checks */
		expected_returnValue = 1;


		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( lhs);
		check__PrintValue_to_File( lhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		std::cout << "input2 = \n";	
		fprintf(fpTest, "input2 = \n");

		check__PrintValue_to_console( rhs);
		check__PrintValue_to_File( rhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::min(lhs, rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_min_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_min_003\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		char lhs;
		char rhs;
		char result;
		char expected_returnValue;

		/* Set global data */
		lhs = 1;
		rhs = 4;

		/* Set expected values for global data checks */
		expected_returnValue = 1;


		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( lhs);
		check__PrintValue_to_File( lhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		std::cout << "input2 = \n";	
		fprintf(fpTest, "input2 = \n");

		check__PrintValue_to_console( rhs);
		check__PrintValue_to_File( rhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::min(lhs, rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_min_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_min_004\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		char lhs;
		char rhs;
		char result;
		char expected_returnValue;

		/* Set global data */
		lhs = 4;
		rhs = 1;

		/* Set expected values for global data checks */
		expected_returnValue = 1;


		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( lhs);
		check__PrintValue_to_File( lhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		std::cout << "input2 = \n";	
		fprintf(fpTest, "input2 = \n");

		check__PrintValue_to_console( rhs);
		check__PrintValue_to_File( rhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::min(lhs, rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_min_005\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_min_005\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		short lhs;
		short rhs;
		short result;
		short expected_returnValue;

		/* Set global data */
		lhs = 1;
		rhs = 4;

		/* Set expected values for global data checks */
		expected_returnValue = 1;


		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( lhs);
		check__PrintValue_to_File( lhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		std::cout << "input2 = \n";	
		fprintf(fpTest, "input2 = \n");

		check__PrintValue_to_console( rhs);
		check__PrintValue_to_File( rhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::min(lhs, rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_min_006\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_min_006\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		short lhs;
		short rhs;
		short result;
		short expected_returnValue;

		/* Set global data */
		lhs = 4;
		rhs = 1;

		/* Set expected values for global data checks */
		expected_returnValue = 1;


		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( lhs);
		check__PrintValue_to_File( lhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		std::cout << "input2 = \n";	
		fprintf(fpTest, "input2 = \n");

		check__PrintValue_to_console( rhs);
		check__PrintValue_to_File( rhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::min(lhs, rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_min_007\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_min_007\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		float lhs;
		float rhs;
		float result;
		float expected_returnValue;

		/* Set global data */
		lhs = 1;
		rhs = 4;

		/* Set expected values for global data checks */
		expected_returnValue = 1;


		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( lhs);
		check__PrintValue_to_File( lhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		std::cout << "input2 = \n";	
		fprintf(fpTest, "input2 = \n");

		check__PrintValue_to_console( rhs);
		check__PrintValue_to_File( rhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::min(lhs, rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_min_008\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_min_008\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		float lhs;
		float rhs;
		float result;
		float expected_returnValue;

		/* Set global data */
		lhs = 4;
		rhs = 1;

		/* Set expected values for global data checks */
		expected_returnValue = 1;


		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( lhs);
		check__PrintValue_to_File( lhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		std::cout << "input2 = \n";	
		fprintf(fpTest, "input2 = \n");

		check__PrintValue_to_console( rhs);
		check__PrintValue_to_File( rhs, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::min(lhs, rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}
	}
	std::cout << "END ---> test_cml_algorithm_min\n\n";
	fprintf(fpTest, "END ---> test_cml_algorithm_min\n\n");
}

void TEST_CLASS_ALGORITHM::test_cml_algorithm_sgn(int doIt)
{
	std::cout << "START ---> test_cml_algorithm_sgn\n\n";		
	fprintf(fpTest, "START ---> test_cml_algorithm_sgn\n\n");

	fprintf(fpTest, "Function Name ---> sgn() \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_algorithm_sgn_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sgn_001\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		int val;

		int result;
		int expected_returnValue;

		/* Set global data */
		val = -5;

		/* Set expected values for global data checks */
		expected_returnValue = -1;
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::sgn(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sgn_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sgn_002\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		int val;

		int result;
		int expected_returnValue;

		/* Set global data */
		val = 5;

		/* Set expected values for global data checks */
		expected_returnValue = 1;
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::sgn(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sgn_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sgn_003\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		int val;

		int result;
		int expected_returnValue;

		/* Set global data */
		val = 0;

		/* Set expected values for global data checks */
		expected_returnValue = 0;
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::sgn(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sgn_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sgn_004\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		char val;

		char result;
		char expected_returnValue;

		/* Set global data */
		val = -5;

		/* Set expected values for global data checks */
		expected_returnValue = -1;
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::sgn(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sgn_005\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sgn_005\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		char val;

		char result;
		char expected_returnValue;

		/* Set global data */
		val = 5;

		/* Set expected values for global data checks */
		expected_returnValue = 1;
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::sgn(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sgn_006\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sgn_006\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		char val;

		char result;
		char expected_returnValue;

		/* Set global data */
		val = 0;

		/* Set expected values for global data checks */
		expected_returnValue = 0;
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::sgn(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sgn_007\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sgn_007\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		short val;

		short result;
		short expected_returnValue;

		/* Set global data */
		val = -5;

		/* Set expected values for global data checks */
		expected_returnValue = -1;
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::sgn(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sgn_008\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sgn_008\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		short val;

		short result;
		short expected_returnValue;

		/* Set global data */
		val = 5;

		/* Set expected values for global data checks */
		expected_returnValue = 1;
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::sgn(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}
		
		{
		std::cout << "Test Case ---> test_cml_algorithm_sgn_009\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sgn_009\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		short val;

		short result;
		short expected_returnValue;

		/* Set global data */
		val = 0;

		/* Set expected values for global data checks */
		expected_returnValue = 0;
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::sgn(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sgn_010\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sgn_010\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		float val;

		float result;
		float expected_returnValue;

		/* Set global data */
		val = -5;

		/* Set expected values for global data checks */
		expected_returnValue = -1;
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::sgn(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sgn_011\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sgn_011\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		float val;

		float result;
		float expected_returnValue;

		/* Set global data */
		val = 5;

		/* Set expected values for global data checks */
		expected_returnValue = 1;
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::sgn(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}
		
		{
		std::cout << "Test Case ---> test_cml_algorithm_sgn_012\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sgn_012\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		float val;

		float result;
		float expected_returnValue;

		/* Set global data */
		val = 0;

		/* Set expected values for global data checks */
		expected_returnValue = 0;
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::sgn(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}
		
		{
		std::cout << "Test Case ---> test_cml_algorithm_sgn_010\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sgn_010\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		float val;

		float result;
		float expected_returnValue;

		/* Set global data */
		val = -5;

		/* Set expected values for global data checks */
		expected_returnValue = -1;
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::sgn(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_algorithm_sgn_011\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sgn_011\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		float val;

		float result;
		float expected_returnValue;

		/* Set global data */
		val = 5;

		/* Set expected values for global data checks */
		expected_returnValue = 1;
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::sgn(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}
		
		{
		std::cout << "Test Case ---> test_cml_algorithm_sgn_012\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm_sgn_012\n\n");

		std::cout << "Data Dimension ---> 1 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 1 \n\n");

		/* Test case data declarations */
		float val;

		float result;
		float expected_returnValue;

		/* Set global data */
		val = 0;

		/* Set expected values for global data checks */
		expected_returnValue = 0;
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);

		std::cout << "\n\n"; 
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = cml::sgn(val);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_returnValue);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}

	}
	std::cout << "END ---> test_cml_algorithm_sgn\n\n";
	fprintf(fpTest, "END ---> test_cml_algorithm_sgn\n\n");

}

void TEST_CLASS_ALGORITHM::test_cml_algorithm__sort_TiOpt_iteration_01(int doIt)
{
	std::cout << "START ---> test_cml_algorithm__sort_TiOpt_iteration_01\n\n";		
	fprintf(fpTest, "START ---> test_cml_algorithm__sort_TiOpt_iteration_01\n\n");

	fprintf(fpTest, "Function Name ---> _sort_TiOpt_iteration() \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_algorithm__sort_TiOpt_iteration_01_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm__sort_TiOpt_iteration_01_001\n\n");

		std::cout << "Data Dimension ---> 8 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 8 \n\n");

		/* Test case data declarations */
		cml::CArray<int, 8, false> Array;
		cml::CArray<int, 8, false> expected_Array;
		cml::CArray<int, 8, false> scratchMem;

		sint32 left;
		sint32 right;
		sint32 depth;
		sint32 idx;


		/* Set global data */
		Array[0] = -5;
		Array[1] = 7;
		Array[2] = 25;
		Array[3] = -9;
		Array[4] = 0;
		Array[5] = 5;
		Array[6] = 11;
		Array[7] = 2;

		left = 2;
		right = 6;
		depth = 0;
		idx = 4;

		/* Set expected values for global data checks */
		expected_Array[0] = -5;
		expected_Array[1] = 7;
		expected_Array[2] = -9;
		expected_Array[3] = 0;
		expected_Array[4] = 5;
		expected_Array[5] = 11;
		expected_Array[6] = 25;
		expected_Array[7] = 2;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		_sort_TiOpt_iteration(Array.begin(), scratchMem.begin(), left, right, depth, idx);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}
	}
	std::cout << "END ---> test_cml_algorithm__sort_TiOpt_iteration_01\n\n";
	fprintf(fpTest, "END ---> test_cml_algorithm__sort_TiOpt_iteration_01\n\n");
}

void TEST_CLASS_ALGORITHM::test_cml_algorithm__sort_TiOpt_iteration_02(int doIt)
{
	std::cout << "START ---> test_cml_algorithm__sort_TiOpt_iteration_02\n\n";		
	fprintf(fpTest, "START ---> test_cml_algorithm__sort_TiOpt_iteration_02\n\n");

	fprintf(fpTest, "Function Name ---> _sort_TiOpt_iteration(RandomAccessIterator,RandomAccessIterator,sint32,sint32,sint32,sint32,Compare) \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_algorithm__sort_TiOpt_iteration_02_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_algorithm__sort_TiOpt_iteration_02_001\n\n");

		std::cout << "Data Dimension ---> 8 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 8 \n\n");

		/* Test case data declarations */
		cml::CArray<int, 8, false> Array;
		cml::CArray<int, 8, false> expected_Array;
		cml::CArray<int, 8, false> scratchMem;

		sint32 left;
		sint32 right;
		sint32 depth;
		sint32 idx;


		/* Set global data */
		Array[0] = -5;
		Array[1] = 7;
		Array[2] = 25;
		Array[3] = -9;
		Array[4] = 0;
		Array[5] = 5;
		Array[6] = 11;
		Array[7] = 2;

		left = 2;
		right = 6;
		depth = 0;
		idx = 4;

		/* Set expected values for global data checks */
		expected_Array[0] = -5;
		expected_Array[1] = 7;
		expected_Array[2] = -9;
		expected_Array[3] = 0;
		expected_Array[4] = 5;
		expected_Array[5] = 11;
		expected_Array[6] = 25;
		expected_Array[7] = 2;

		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( expected_Array);
		check__vArrayPrint_to_File( expected_Array, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		_sort_TiOpt_iteration(Array.begin(), scratchMem.begin(), left, right, depth, idx,  std::less<int>());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( Array);
		check__vArrayPrint_to_File( Array, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(Array,expected_Array);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
		}
	}
	std::cout << "END ---> test_cml_algorithm__sort_TiOpt_iteration_02\n\n";
	fprintf(fpTest, "END ---> test_cml_algorithm__sort_TiOpt_iteration_02\n\n");	
}

#if 0
void TEST_CLASS_ALGORITHM::test_cml_algorithm_sgn(int doIt)
{
	if (doIt) 
	{
		/************************* Test Case 001 *************************/
		START_TEST("test_cml_algorithm_sgn_001",
			"Description: \
			- cml_stl_algorithm.h : inline static sint32 sgn(const T& val) \
			- Testing: interface, boundary_condition  \
			- Overview: Returns the sign of the given value of any Type. \
			- Entry conditions: Data Type is int \
			val is negative \
			- Expected results: Returns -1 for negative, +1 for positive and 0 if value is zero."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Test case data declarations */
			int val;

		int returnValue;
		int expected_returnValue;

		/* Set global data */
		val = -5;

		/* Set expected values for global data checks */
		expected_returnValue = -1;

		/* Call SUT */
		returnValue = test_CML_sgn(val);

		/* Test Checks */
		CHECK_S_INT(returnValue, expected_returnValue);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		/************************* Test Case 002 *************************/
		START_TEST("test_cml_algorithm_sgn_002",
			"Description: \
			- cml_stl_algorithm.h : inline static sint32 sgn(const T& val) \
			- Testing: interface, boundary_condition  \
			- Overview: Returns the sign of the given value of any Type. \
			- Entry conditions: Data Type is int \
			val is positive \
			- Expected results: Returns -1 for negative, +1 for positive and 0 if value is zero."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Test case data declarations */
			int val;

		int returnValue;
		int expected_returnValue;

		/* Set global data */
		val = 5;

		/* Set expected values for global data checks */
		expected_returnValue = 1;

		/* Call SUT */
		returnValue = test_CML_sgn(val);

		/* Test Checks */
		CHECK_S_INT(returnValue, expected_returnValue);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		/************************* Test Case 003 *************************/
		START_TEST("test_cml_algorithm_sgn_003",
			"Description: \
			- cml_stl_algorithm.h : inline static sint32 sgn(const T& val) \
			- Testing: interface, boundary_condition  \
			- Overview: Returns the sign of the given value of any Type. \
			- Entry conditions: Data Type is int \
			val is Zero \
			- Expected results: Returns -1 for negative, +1 for positive and 0 if value is zero."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Test case data declarations */
			int val;

		int returnValue;
		int expected_returnValue;

		/* Set global data */
		val = 0;

		/* Set expected values for global data checks */
		expected_returnValue = 0;

		/* Call SUT */
		returnValue = test_CML_sgn(val);

		/* Test Checks */
		CHECK_S_INT(returnValue, expected_returnValue);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		/************************* Test Case 004 *************************/
		START_TEST("test_cml_algorithm_sgn_004",
			"Description: \
			- cml_stl_algorithm.h : inline static sint32 sgn(const T& val) \
			- Testing: interface, boundary_condition  \
			- Overview: Returns the sign of the given value of any Type. \
			- Entry conditions: Data Type is char \
			val is negative \
			- Expected results: Returns -1 for negative, +1 for positive and 0 if value is zero."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Test case data declarations */
			char val;

		char returnValue;
		char expected_returnValue;

		/* Set global data */
		val = -5;

		/* Set expected values for global data checks */
		expected_returnValue = -1;

		/* Call SUT */
		returnValue = test_CML_sgn_char(val);

		/* Test Checks */
		CHECK_S_CHAR(returnValue, expected_returnValue);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		/************************* Test Case 005 *************************/
		START_TEST("test_cml_algorithm_sgn_005",
			"Description: \
			- cml_stl_algorithm.h : inline static sint32 sgn(const T& val) \
			- Testing: interface, boundary_condition  \
			- Overview: Returns the sign of the given value of any Type. \
			- Entry conditions: Data Type is char \
			val is positive \
			- Expected results: Returns -1 for negative, +1 for positive and 0 if value is zero."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Test case data declarations */
			char val;

		char returnValue;
		char expected_returnValue;

		/* Set global data */
		val = 5;

		/* Set expected values for global data checks */
		expected_returnValue = 1;

		/* Call SUT */
		returnValue = test_CML_sgn_char(val);

		/* Test Checks */
		CHECK_S_CHAR(returnValue, expected_returnValue);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		/************************* Test Case 006 *************************/
		START_TEST("test_cml_algorithm_sgn_006",
			"Description: \
			- cml_stl_algorithm.h : inline static sint32 sgn(const T& val) \
			- Testing: interface, boundary_condition  \
			- Overview: Returns the sign of the given value of any Type. \
			- Entry conditions: Data Type is char \
			val is Zero \
			- Expected results: Returns -1 for negative, +1 for positive and 0 if value is zero."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Test case data declarations */
			char val;

		char returnValue;
		char expected_returnValue;

		/* Set global data */
		val = 0;

		/* Set expected values for global data checks */
		expected_returnValue = 0;

		/* Call SUT */
		returnValue = test_CML_sgn_char(val);

		/* Test Checks */
		CHECK_S_CHAR(returnValue, expected_returnValue);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		/************************* Test Case 007 *************************/
		START_TEST("test_cml_algorithm_sgn_007",
			"Description: \
			- cml_stl_algorithm.h : inline static sint32 sgn(const T& val) \
			- Testing: interface, boundary_condition  \
			- Overview: Returns the sign of the given value of any Type. \
			- Entry conditions: Data Type is short \
			val is negative \
			- Expected results: Returns -1 for negative, +1 for positive and 0 if value is zero."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Test case data declarations */
			short val;

		short returnValue;
		short expected_returnValue;

		/* Set global data */
		val = -5;

		/* Set expected values for global data checks */
		expected_returnValue = -1;

		/* Call SUT */
		returnValue = test_CML_sgn_short(val);

		/* Test Checks */
		CHECK_S_INT(returnValue, expected_returnValue);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		/************************* Test Case 008 *************************/
		START_TEST("test_cml_algorithm_sgn_008",
			"Description: \
			- cml_stl_algorithm.h : inline static sint32 sgn(const T& val) \
			- Testing: interface, boundary_condition  \
			- Overview: Returns the sign of the given value of any Type. \
			- Entry conditions: Data Type is short \
			val is positive \
			- Expected results: Returns -1 for negative, +1 for positive and 0 if value is zero."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Test case data declarations */
			short val;

		short returnValue;
		short expected_returnValue;

		/* Set global data */
		val = 5;

		/* Set expected values for global data checks */
		expected_returnValue = 1;

		/* Call SUT */
		returnValue = test_CML_sgn_short(val);

		/* Test Checks */
		CHECK_S_INT(returnValue, expected_returnValue);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		/************************* Test Case 009 *************************/
		START_TEST("test_cml_algorithm_sgn_009",
			"Description: \
			- cml_stl_algorithm.h : inline static sint32 sgn(const T& val) \
			- Testing: interface, boundary_condition  \
			- Overview: Returns the sign of the given value of any Type. \
			- Entry conditions: Data Type is short \
			val is Zero \
			- Expected results: Returns -1 for negative, +1 for positive and 0 if value is zero."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Test case data declarations */
			short val;

		short returnValue;
		short expected_returnValue;

		/* Set global data */
		val = 0;

		/* Set expected values for global data checks */
		expected_returnValue = 0;

		/* Call SUT */
		returnValue = test_CML_sgn_short(val);

		/* Test Checks */
		CHECK_S_INT(returnValue, expected_returnValue);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		/************************* Test Case 010 *************************/
		START_TEST("test_cml_algorithm_sgn_010",
			"Description: \
			- cml_stl_algorithm.h : inline static sint32 sgn(const T& val) \
			- Testing: interface, boundary_condition  \
			- Overview: Returns the sign of the given value of any Type. \
			- Entry conditions: Data Type is float \
			val is negative \
			- Expected results: Returns -1 for negative, +1 for positive and 0 if value is zero."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Test case data declarations */
			float val;

		float returnValue;
		float expected_returnValue;

		/* Set global data */
		val = -5;

		/* Set expected values for global data checks */
		expected_returnValue = -1;

		/* Call SUT */
		returnValue = test_CML_sgn_float(val);

		/* Test Checks */
		CHECK_DOUBLE(returnValue, expected_returnValue);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		/************************* Test Case 011 *************************/
		START_TEST("test_cml_algorithm_sgn_011",
			"Description: \
			- cml_stl_algorithm.h : inline static sint32 sgn(const T& val) \
			- Testing: interface, boundary_condition  \
			- Overview: Returns the sign of the given value of any Type. \
			- Entry conditions: Data Type is float \
			val is positive \
			- Expected results: Returns -1 for negative, +1 for positive and 0 if value is zero."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Test case data declarations */
			float val;

		float returnValue;
		float expected_returnValue;

		/* Set global data */
		val = 5;

		/* Set expected values for global data checks */
		expected_returnValue = 1;

		/* Call SUT */
		returnValue = test_CML_sgn_float(val);

		/* Test Checks */
		CHECK_DOUBLE(returnValue, expected_returnValue);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		/************************* Test Case 012 *************************/
		START_TEST("test_cml_algorithm_sgn_012",
			"Description: \
			- cml_stl_algorithm.h : inline static sint32 sgn(const T& val) \
			- Testing: interface, boundary_condition  \
			- Overview: Returns the sign of the given value of any Type. \
			- Entry conditions: Data Type is float \
			val is Zero \
			- Expected results: Returns -1 for negative, +1 for positive and 0 if value is zero."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Test case data declarations */
			float val;

		float returnValue;
		float expected_returnValue;

		/* Set global data */
		val = 0;

		/* Set expected values for global data checks */
		expected_returnValue = 0;

		/* Call SUT */
		returnValue = test_CML_sgn_float(val);

		/* Test Checks */
		CHECK_DOUBLE(returnValue, expected_returnValue);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

#if 1
void TEST_CLASS_ALGORITHM::test_cml_algorithm__sort_TiOpt_iteration_01(int doIt)
{
	if (doIt) 
	{
		/************************* Test Case 001 *************************/
		START_TEST("test_cml_algorithm__sort_TiOpt_iteration_01_001",
			"Description: \
			- cml_stl_algorithm.h : static void _sort_TiOpt_iteration (RandomAccessIterator ping, RandomAccessIterator pong, sint32 left, sint32 right, sint32 depth, sint32 idx, Compare comp) \
			- Testing: interface, boundary_condition  \
			- Overview:  Iteration sort the sub array elements in the range in \
			ascending order using recursive partition sort \
			- Entry conditions: Array size is 8 and is unsorted. \
			- Expected results: Array is sorted in ascending order within the range"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

	
		/* Test case data declarations */
			cml::CArray<int, 8, false> Array;
		cml::CArray<int, 8, false> expected_Array;
		cml::CArray<int, 8, false> scratchMem;

		sint32 left;
		sint32 right;
		sint32 depth;
		sint32 idx;


		/* Set global data */
		Array[0] = -5;
		Array[1] = 7;
		Array[2] = 25;
		Array[3] = -9;
		Array[4] = 0;
		Array[5] = 5;
		Array[6] = 11;
		Array[7] = 2;

		left = 2;
		right = 6;
		depth = 0;
		idx = 4;

		/* Set expected values for global data checks */
		expected_Array[0] = 6;
		expected_Array[1] = 7;
		expected_Array[2] = 8;
		expected_Array[3] = 8;
		expected_Array[4] = 9;
		expected_Array[5] = 9;
		expected_Array[6] = 10;
		expected_Array[7] = 10;

		/* Call SUT */
		_sort_TiOpt_iteration(Array, scratchMem, left, right, depth, idx);

		/* Test Checks */
		//CHECK_MEMORY("Array == expected_Array", &Array, &expected_Array, sizeof(expected_Array));

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_ALGORITHM::test_cml_algorithm__sort_TiOpt_iteration_02(int doIt)
{
	if (doIt) 
	{
		/************************* Test Case 001 *************************/
		START_TEST("test_cml_algorithm__sort_TiOpt_iteration_01_001",
			"Description: \
			- cml_stl_algorithm.h : static void _sort_TiOpt_iteration (RandomAccessIterator ping, RandomAccessIterator pong, sint32 left, sint32 right, sint32 depth, sint32 idx, Compare comp) \
			- Testing: interface, boundary_condition  \
			- Overview:  Iteration sort the sub array elements in the range in \
			ascending order using recursive partition sort \
			- Entry conditions: Array size is 8 and is unsorted. \
			- Expected results: Array is sorted in ascending order within the range"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Test case data declarations */
			cml::CArray<int, 8, false> Array;
		cml::CArray<int, 8, false> expected_Array;
		cml::CArray<int, 8, false> scratchMem;

		sint32 left;
		sint32 right;
		sint32 depth;
		sint32 idx;


		/* Set global data */
		Array[0] = -5;
		Array[1] = 7;
		Array[2] = 25;
		Array[3] = -9;
		Array[4] = 0;
		Array[5] = 5;
		Array[6] = 11;
		Array[7] = 2;

		left = 2;
		right = 6;
		depth = 0;
		idx = 4;

		/* Set expected values for global data checks */
		expected_Array[0] = 6;
		expected_Array[1] = 7;
		expected_Array[2] = 8;
		expected_Array[3] = 8;
		expected_Array[4] = 9;
		expected_Array[5] = 9;
		expected_Array[6] = 10;
		expected_Array[7] = 10;

		/* Call SUT */
		_sort_TiOpt_iteration(Array.begin(), scratchMem.begin(), left, right, depth, idx,  std::less<int>());

		/* Test Checks */
		//CHECK_MEMORY("Array == expected_Array", &Array, &expected_Array, sizeof(expected_Array));

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}
#endif
#endif
/*****************************************************************************/
/* Call Interface Control                                                    */
/*****************************************************************************/
#pragma qas cantata ignore on

#pragma qas cantata ignore off
/* pragma qas cantata testscript end */
/*****************************************************************************/
/* End of test script                                                        */
/*****************************************************************************/
