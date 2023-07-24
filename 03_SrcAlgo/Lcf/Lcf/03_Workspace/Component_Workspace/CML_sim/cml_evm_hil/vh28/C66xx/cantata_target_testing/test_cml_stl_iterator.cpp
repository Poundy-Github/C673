/*****************************************************************************/
/*                            Cantata Test Script                            */
/*****************************************************************************/
/*
 *    Filename: test_cml_stl_iterator.cpp
 *    Author: uidr5285
 *    Generated on: 18-Feb-2016 10:01:19
 *    Generated from: cml_stl_iterator.cpp
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
#include <string>

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
#include "cml_stl_iterator.h"

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

//template< typename T >
static void check__PrintValue_to_File(char Value, FILE *fpTest)
{
	/*if(typeid(Value) == typeid(float))
		fprintf(fpTest, "%f\t\t", Value);
	else*/
		fprintf(fpTest, "%i\t\t", Value);
}

static void check__PrintValue_to_File(float Value, FILE *fpTest)
{
	fprintf(fpTest, "%f\t\t", Value);
}

static void check__PrintValue_to_File(short Value, FILE *fpTest)
{
	fprintf(fpTest, "%i\t\t", Value);
}

static void check__PrintValue_to_File(int Value, FILE *fpTest)
{
	fprintf(fpTest, "%i\t\t", Value);
}

static void check__PrintValue_to_File(char *Value, FILE *fpTest)
{
	fprintf(fpTest, "%i\t\t", Value);
}

static void check__PrintValue_to_File(sint32 *Value, FILE *fpTest)
{
	fprintf(fpTest, "%i\t\t", Value);
}

static void check__PrintValue_to_File(short *Value, FILE *fpTest)
{
	fprintf(fpTest, "%i\t\t", Value);
}

static void check__PrintValue_to_File(float *Value, FILE *fpTest)
{
	fprintf(fpTest, "%i\t\t", Value);
}

template< typename T >
static void check__PrintValue_to_console(T Value)
{	
	std::cout << Value<<"\t\t"; 
}

template < typename T, sint32 COLS, bool EXT_MEM >
static void check__vArraySegmentPrint_to_File( cml::CArrayStorage<T ,COLS, EXT_MEM> &oArray, FILE *fpTest, uint32 start, uint32 stop )
{    
	int  iIndex = start;
	for( int row = start; row < stop; row++ )
	{
			check__PrintValue_to_File(oArray[iIndex], fpTest);
			iIndex++;
		//fprintf(fpTest, "\n");
	} 

	fprintf(fpTest, "\n\n");
}

template < typename T, sint32 COLS, bool EXT_MEM >
static void check__vArrayPrintSegment_to_console( cml::CArrayStorage<T ,COLS, EXT_MEM> &oArray, uint32 start, uint32 stop)
{    
	int  iIndex = start;
	for( int row = start; row < stop; row++ )
	{
			check__PrintValue_to_console(oArray[iIndex]);
			iIndex++;
		//fprintf(fpTest, "\n");
	} 


	fprintf(fpTest, "\n\n");
}



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

	std::cout << "\nStatus ---> PASS\n\n"; 
	fprintf(fpTest, "\nStatus ---> PASS\n\n");
    /* No global data */
}

/*****************************************************************************/
/* Test class declaration                                                    */
/*****************************************************************************/
class TEST_CLASS_ITERATOR
{
public:
    void run_tests_iterator();
    void test_cml_stl_CBaseIt_empty_constructor(int doIt);
    void test_cml_stl_CBaseIt_initialization_constructor(int doIt);
    void test_cml_stl_CBaseIt_Copy_constructor(int doIt);
    void test_cml_stl_CBaseIt_overload_deference_operator(int doIt);
    void test_cml_stl_CBaseIt_overload_Indirection_operator(int doIt);
    void test_cml_stl_CBaseIt_overload_Equal_Comparison_operator(int doIt);
    void test_cml_stl_CBaseIt_overload_Unequal_Comparison_operator(int doIt);
    void test_cml_stl_CBaseIt_overload_Greater_or_Equal_operator(int doIt);
    void test_cml_stl_CBaseIt_overload_Lesser_or_Equal_operator(int doIt);
    void test_cml_stl_CBaseIt_overload_Less_than_operator(int doIt);
    void test_cml_stl_CBaseIt_overload_Greater_than_operator(int doIt);
    void test_cml_stl_CBaseIt_memory_distance(int doIt);

    void test_cml_stl_CLinMemIt_empty_constructor(int doIt);
    void test_cml_stl_CLinMemIt_initialization_constructor_01(int doIt);
    void test_cml_stl_CLinMemIt_initialization_constructor_02(int doIt);
    void test_cml_stl_CLinMemIt_Copy_constructor_01(int doIt);
    void test_cml_stl_CLinMemIt_Copy_constructor_02(int doIt);
    void test_cml_stl_CLinMemIt_Operator_Subscript(int doIt);
    void test_cml_stl_CLinMemIt_Operator_Post_Increment(int doIt);
    void test_cml_stl_CLinMemIt_Operator_Pre_Increment(int doIt);
    void test_cml_stl_CLinMemIt_Operator_Post_Decrement(int doIt);
    void test_cml_stl_CLinMemIt_Operator_Pre_Decrement(int doIt);
    void test_cml_stl_CLinMemIt_Operator_Addition_Assignment(int doIt);
    void test_cml_stl_CLinMemIt_Operator_Subtraction_Assignment(int doIt);
    void test_cml_stl_CLinMemIt_Operator_Addition(int doIt);
    void test_cml_stl_CLinMemIt_Operator_Subtraction(int doIt);
    void test_cml_stl_CLinMemIt_Operator_Subtraction_01(int doIt);
};

/*****************************************************************************/
/* Coverage Analysis                                                         */
/*****************************************************************************/
/* Coverage Rule Set: DO-178B/ED-12B Level B Coverage */


/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_stl_iterator()
{
    TEST_CLASS_ITERATOR test_object;

	std::cout << "******** Start Testing: Iterator Library functions ********\n\n";
	fprintf(fpTest, "******** Start Testing: Iterator Library functions ********\n\n");

	test_object.run_tests_iterator();

	std::cout << "End of Testing: Iterator Library functions\n\n";
	fprintf(fpTest, "End of Testing: Iterator Library functions\n\n");
    return;
}

/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS_ITERATOR::run_tests_iterator()
{
	
	test_cml_stl_CBaseIt_overload_deference_operator(1);
	test_cml_stl_CBaseIt_overload_Indirection_operator(1);
	test_cml_stl_CBaseIt_overload_Equal_Comparison_operator(1);
	test_cml_stl_CBaseIt_overload_Unequal_Comparison_operator(1);
	test_cml_stl_CBaseIt_overload_Greater_or_Equal_operator(1);
	test_cml_stl_CBaseIt_overload_Lesser_or_Equal_operator(1);
	test_cml_stl_CBaseIt_overload_Less_than_operator(1);
	test_cml_stl_CBaseIt_overload_Greater_than_operator(1);
	test_cml_stl_CBaseIt_memory_distance(1);


	test_cml_stl_CLinMemIt_Operator_Subscript(1);
	test_cml_stl_CLinMemIt_Operator_Pre_Increment(1);
	test_cml_stl_CLinMemIt_Operator_Post_Increment(1);
	test_cml_stl_CLinMemIt_Operator_Post_Decrement(1);
	test_cml_stl_CLinMemIt_Operator_Pre_Decrement(1);
	test_cml_stl_CLinMemIt_Operator_Addition_Assignment(1);
	test_cml_stl_CLinMemIt_Operator_Subtraction_Assignment(1);
	test_cml_stl_CLinMemIt_Operator_Addition(1);
	test_cml_stl_CLinMemIt_Operator_Subtraction(1);
	test_cml_stl_CLinMemIt_Operator_Subtraction_01(1);
}

/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/


void TEST_CLASS_ITERATOR::test_cml_stl_CBaseIt_overload_deference_operator(int doIt)
{
	std::cout << "START ---> test_cml_stl_CBaseIt_overload_deference_operator\n\n";		
	fprintf(fpTest, "START ---> test_cml_stl_CBaseIt_overload_deference_operator\n\n");

	fprintf(fpTest, "Function Name ---> operator->()const \n\n");

	if (doIt) 
	{
		{

		std::cout << "Test Case ---> dereference char data of 2D_Array\n\n";		
		fprintf(fpTest, "Test Case ---> dereference char data of 2D_Array\n\n");

		std::cout << "Data Dimension ---> 10X10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10X10 \n\n");

        	/* Test case data declarations */
#ifndef NDEBUG
        	cml::CBaseIt<char, false,cml::CArray<char, 10> > returnValue;
#else
			cml::CBaseIt<char, false > returnValue;
#endif

            /* Set global data */
            initialise_global_data();
			boolean bool_val;
        	typedef cml::CArray<char, 10> Array;
			//typedef cml::CBaseIt<char, false,cml::CArray<char, 10> > Array2D;
        	cml::CArray<char, 10>  tempArray;
        	cml::CArray<Array, 10> _2DArray;
			char val, expected_val;
        	val = 0;
			expected_val = 1;

#ifndef NDEBUG
        	cml::CBaseIt<Array, false,cml::CArray<Array, 10> > it;
#else
			cml::CBaseIt<Array, false > it;
#endif
			
        	for(int i = 0; i < 10; i++)
        	{
        		tempArray[i] = i+1;
        	}
        	_2DArray.fill(tempArray);

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__PrintValue_to_console<char>(tempArray[0]);
			//check__PrintValue_to_File(tempArray[0],fpTest);
			for(int i =0;i<10;i++)
			check__vArraySegmentPrint_to_File<char,10,false>(tempArray, fpTest, 0, 10);
			//check__vArraySegmentPrint_to_File<Array,10,false>(_2DArray, fpTest, 0, 9);
			
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<char>(expected_val);
			check__PrintValue_to_File(expected_val,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
        	it = _2DArray.begin();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


        	returnValue = (it->begin());

			val = *returnValue;

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<char>(val);
			check__PrintValue_to_File(val,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool_val = check__boCompare(val, expected_val);
			
			if(bool_val)
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

		std::cout << "Test Case ---> dereference sint32 data of 2D_Array\n\n";		
		fprintf(fpTest, "Test Case ---> dereference sint32 data of 2D_Array\n\n");

		std::cout << "Data Dimension ---> 10X10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10X10 \n\n");

        	/* Test case data declarations */
#ifndef NDEBUG
        	cml::CBaseIt<sint32, false,cml::CArray<sint32, 10> > returnValue;
#else
			cml::CBaseIt<sint32, false> returnValue;
#endif        	

            /* Set global data */
            initialise_global_data();
			boolean bool_val;
        	typedef cml::CArray<sint32, 10> Array;
			//typedef cml::CBaseIt<char, false,cml::CArray<char, 10> > Array2D;
        	cml::CArray<sint32, 10>  tempArray;
        	cml::CArray<Array, 10> _2DArray;
			sint32 val, expected_val;
        	val = 0;
			expected_val = 1;

#ifndef NDEBUG
        	cml::CBaseIt<Array, false,cml::CArray<Array, 10> > it;
#else
			cml::CBaseIt<Array, false > it;
#endif     
			
        	for(int i = 0; i < 10; i++)
        	{
        		tempArray[i] = i+1;
        	}
        	_2DArray.fill(tempArray);

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__PrintValue_to_console<sint32>(tempArray[0]);
			//check__PrintValue_to_File(tempArray[0],fpTest);
			for(int i =0;i<10;i++)
			check__vArraySegmentPrint_to_File<sint32,10,false>(tempArray, fpTest, 0, 10);
			//check__vArraySegmentPrint_to_File<Array,10,false>(_2DArray, fpTest, 0, 9);

			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<sint32>(expected_val);
			check__PrintValue_to_File(expected_val,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
        	it = _2DArray.begin();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


        	returnValue = (it->begin());

			val = *returnValue;

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<sint32>(val);
			check__PrintValue_to_File(val,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool_val = check__boCompare(val, expected_val);
			
			if(bool_val)
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

		std::cout << "Test Case ---> dereference short data of 2D_Array\n\n";		
		fprintf(fpTest, "Test Case ---> dereference short data of 2D_Array\n\n");

		std::cout << "Data Dimension ---> 10X10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10X10 \n\n");

        	/* Test case data declarations */
#ifndef NDEBUG
        	cml::CBaseIt<short, false,cml::CArray<short, 10> > returnValue;
#else
			cml::CBaseIt<short, false > returnValue;
#endif          	

            /* Set global data */
            initialise_global_data();
			boolean bool_val;
        	typedef cml::CArray<short, 10> Array;
			//typedef cml::CBaseIt<char, false,cml::CArray<char, 10> > Array2D;
        	cml::CArray<short, 10>  tempArray;
        	cml::CArray<Array, 10> _2DArray;
			short val, expected_val;
        	val = 0;
			expected_val = 1;

#ifndef NDEBUG
        	cml::CBaseIt<Array, false,cml::CArray<Array, 10> > it;
#else
			cml::CBaseIt<Array, false > it;
#endif 
			
        	for(int i = 0; i < 10; i++)
        	{
        		tempArray[i] = i+1;
        	}
        	_2DArray.fill(tempArray);

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__PrintValue_to_console<short>(tempArray[0]);
			//check__PrintValue_to_File(tempArray[0],fpTest);
			for(int i =0;i<10;i++)
			check__vArraySegmentPrint_to_File<short,10,false>(tempArray, fpTest, 0, 10);
			//check__vArraySegmentPrint_to_File<Array,10,false>(_2DArray, fpTest, 0, 9);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<short>(expected_val);
			check__PrintValue_to_File(expected_val,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
        	it = _2DArray.begin();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


        	returnValue = (it->begin());

			val = *returnValue;

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<short>(val);
			check__PrintValue_to_File(val,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool_val = check__boCompare(val, expected_val);
			
			if(bool_val)
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

			std::cout << "Test Case ---> dereference float32 data of 2D_Array\n\n";		
			fprintf(fpTest, "Test Case ---> dereference float32 data of 2D_Array\n\n");

			std::cout << "Data Dimension ---> 10X10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10X10 \n\n");

        	/* Test case data declarations */
#ifndef NDEBUG
        	cml::CBaseIt<float32, false,cml::CArray<float32, 10> > returnValue;
#else
			cml::CBaseIt<float32, false> returnValue;
#endif        	

            /* Set global data */
            initialise_global_data();
			boolean bool_val;
        	typedef cml::CArray<float32, 10> Array;
			//typedef cml::CBaseIt<char, false,cml::CArray<char, 10> > Array2D;
        	cml::CArray<float32, 10>  tempArray;
        	cml::CArray<Array, 10> _2DArray;
			float32 val, expected_val;
        	val = 0;
			expected_val = 1;

#ifndef NDEBUG
        	cml::CBaseIt<Array, false,cml::CArray<Array, 10> > it;
#else
			cml::CBaseIt<Array, false > it;
#endif
			
        	for(int i = 0; i < 10; i++)
        	{
        		tempArray[i] = i+1.0F;
        	}
        	_2DArray.fill(tempArray);

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__PrintValue_to_console<float32>(tempArray[0]);
			//check__PrintValue_to_File(tempArray[0],fpTest);
			for(int i =0;i<10;i++)
			check__vArraySegmentPrint_to_File<float32,10,false>(tempArray, fpTest, 0, 10);
			//check__vArraySegmentPrint_to_File<Array,10,false>(_2DArray, fpTest, 0, 9);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<float32>(expected_val);
			check__PrintValue_to_File(expected_val,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
        	it = _2DArray.begin();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


        	returnValue = (it->begin());

			val = *returnValue;

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<float32>(val);
			check__PrintValue_to_File(val,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool_val = check__boCompare(val, expected_val);
			
			if(bool_val)
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

	std::cout << "END ---> test_cml_stl_CBaseIt_overload_deference_operator\n\n";
	fprintf(fpTest, "END ---> test_cml_stl_CBaseIt_overload_deference_operator\n\n");
}


void TEST_CLASS_ITERATOR::test_cml_stl_CBaseIt_overload_Indirection_operator(int doIt)
{
	std::cout << "START ---> test_cml_stl_CBaseIt_overload_Indirection_operator\n\n";		
	fprintf(fpTest, "START ---> test_cml_stl_CBaseIt_overload_Indirection_operator\n\n");

	fprintf(fpTest, "Function Name ---> operator*()const \n\n");

	if (doIt) 
	{
		{

			std::cout << "Test Case ---> Indirection char data of Array\n\n";		
			fprintf(fpTest, "Test Case ---> Indirection char data of Array\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
        	cml::CArray<char, 5, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<char, false, cml::CArray<char, 5> > it;
#else
			cml::CBaseIt<char, false > it;
#endif
        	
        	char returnValue;
        	char expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

			it = Array.begin();

			/* Set expected values for global data checks */
			expected_returnValue = 1;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			//check__PrintValue_to_console<char>(Array[0]);
			//check__PrintValue_to_File(Array[0],fpTest);
			check__vArrayPrintSegment_to_console<char,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<char,5,false>(Array, fpTest, 0, 5);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<char>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = *it;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<char>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> Indirection sint32 data of Array\n\n";		
			fprintf(fpTest, "Test Case ---> Indirection sint32 data of Array\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
        	cml::CArray<sint32, 5, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 5> > it;
#else
			cml::CBaseIt<sint32, false > it;
#endif
        	
        	sint32 returnValue;
        	sint32 expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

			it = Array.begin();

			/* Set expected values for global data checks */
			expected_returnValue = 1;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			//check__PrintValue_to_console<sint32>(Array[0]);
			//check__PrintValue_to_File(Array[0],fpTest);
			check__vArrayPrintSegment_to_console<sint32,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<sint32,5,false>(Array, fpTest, 0, 5);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<sint32>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = *it;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<sint32>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> Indirection short data of Array\n\n";		
			fprintf(fpTest, "Test Case ---> Indirection short data of Array\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
        	cml::CArray<short, 5, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<short, false, cml::CArray<short, 5> > it;
#else
			cml::CBaseIt<short, false > it;
#endif
        	
        	short returnValue;
        	short expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

			it = Array.begin();

			/* Set expected values for global data checks */
			expected_returnValue = 1;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			//check__PrintValue_to_console<short>(Array[0]);
			//check__PrintValue_to_File(Array[0],fpTest);
			check__vArrayPrintSegment_to_console<short,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<short,5,false>(Array, fpTest, 0, 5);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<short>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = *it;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<short>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> Indirection float32 data of Array\n\n";		
			fprintf(fpTest, "Test Case ---> Indirection float32 data of Array\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
        	cml::CArray<float32, 5, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<float32, false, cml::CArray<float32, 5> > it;
#else
			cml::CBaseIt<float32, false > it;
#endif
        	
        	float32 returnValue;
        	float32 expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

			it = Array.begin();

			/* Set expected values for global data checks */
			expected_returnValue = 1;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			//check__PrintValue_to_console<float32>(Array[0]);
			//check__PrintValue_to_File(Array[0],fpTest);
			check__vArrayPrintSegment_to_console<float32,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<float32,5,false>(Array, fpTest, 0, 5);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<float32>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = *it;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<float32>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

	std::cout << "END ---> test_cml_stl_CBaseIt_overload_Indirection_operator\n\n";
	fprintf(fpTest, "END ---> test_cml_stl_CBaseIt_overload_Indirection_operator\n\n");
}

void TEST_CLASS_ITERATOR::test_cml_stl_CBaseIt_overload_Equal_Comparison_operator(int doIt)
{
	std::cout << "START ---> test_cml_stl_CBaseIt_overload_Equal_Comparison_operator\n\n";		
	fprintf(fpTest, "START ---> test_cml_stl_CBaseIt_overload_Equal_Comparison_operator\n\n");

	fprintf(fpTest, "Function Name ---> operator==() const \n\n");

	if (doIt) 
	{
		{

			std::cout << "Test Case ---> Equal_Comparison_operator on char Array(true check)\n\n";		
			fprintf(fpTest, "Test Case ---> Equal_Comparison_operator on char Array(true check)\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5\n\n");

        	/* Test case data declarations */
        	cml::CArray<char, 5, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<char, false, cml::CArray<char, 5> > it1;
        	cml::CBaseIt<char, false, cml::CArray<char, 5> > it2;
#else
			cml::CBaseIt<char, false > it1;
        	cml::CBaseIt<char, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

			it1 = Array.begin();
			it2 = Array.begin();

			 /* Set expected values for global data checks */
			expected_returnValue = true;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<char,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<char,5,false>(Array, fpTest, 0, 5);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 == it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> Equal_Comparison_operator on char Array(false check)\n\n";		
			fprintf(fpTest, "Test Case ---> Equal_Comparison_operator on char Array(false check)\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
        	cml::CArray<char, 5, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<char, false, cml::CArray<char, 5> > it1;
        	cml::CBaseIt<char, false, cml::CArray<char, 5> > it2;
#else
			cml::CBaseIt<char, false > it1;
        	cml::CBaseIt<char, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

			it1 = Array.begin();
			it2 = Array.begin()+1;

			 /* Set expected values for global data checks */
			expected_returnValue = false;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<char,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<char,5,false>(Array, fpTest, 0, 5);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 == it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> Equal_Comparison_operator on sint32 Array(true check)\n\n";		
			fprintf(fpTest, "Test Case ---> Equal_Comparison_operator on sint32 Array(true check)\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
        	cml::CArray<sint32, 5, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 5> > it1;
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 5> > it2;
#else
			cml::CBaseIt<sint32, false > it1;
        	cml::CBaseIt<sint32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

			it1 = Array.begin();
			it2 = Array.begin();

			 /* Set expected values for global data checks */
			expected_returnValue = true;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<sint32,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<sint32,5,false>(Array, fpTest, 0, 5);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 == it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> Equal_Comparison_operator on sint32 Array(false check)\n\n";		
			fprintf(fpTest, "Test Case ---> Equal_Comparison_operator on sint32 Array(false check)\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
        	cml::CArray<sint32, 5, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 5> > it1;
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 5> > it2;
#else
			cml::CBaseIt<sint32, false > it1;
        	cml::CBaseIt<sint32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

			it1 = Array.begin();
			it2 = Array.begin()+1;

			 /* Set expected values for global data checks */
			expected_returnValue = false;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<sint32,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<sint32,5,false>(Array, fpTest, 0, 5);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 == it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> Equal_Comparison_operator on short Array(true check) \n\n";		
			fprintf(fpTest, "Test Case ---> Equal_Comparison_operator on short Array(true check)\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
        	cml::CArray<short, 5, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<short, false, cml::CArray<short, 5> > it1;
        	cml::CBaseIt<short, false, cml::CArray<short, 5> > it2;
#else
			cml::CBaseIt<short, false > it1;
        	cml::CBaseIt<short, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

			it1 = Array.begin();
			it2 = Array.begin();

			 /* Set expected values for global data checks */
			expected_returnValue = true;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<short,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<short,5,false>(Array, fpTest, 0, 5);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 == it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> Equal_Comparison_operator on short Array(false check) \n\n";		
			fprintf(fpTest, "Test Case ---> Equal_Comparison_operator on short Array(false check) \n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
        	cml::CArray<short, 5, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<short, false, cml::CArray<short, 5> > it1;
        	cml::CBaseIt<short, false, cml::CArray<short, 5> > it2;
#else
			cml::CBaseIt<short, false > it1;
        	cml::CBaseIt<short, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

			it1 = Array.begin();
			it2 = Array.begin()+1;

			 /* Set expected values for global data checks */
			expected_returnValue = false;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<short,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<short,5,false>(Array, fpTest, 0, 5);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 == it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> Equal_Comparison_operator on float32 Array(true check)\n\n";		
			fprintf(fpTest, "Test Case ---> Equal_Comparison_operator on float32 Array(true check)\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
        	cml::CArray<float32, 5, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<float32, false, cml::CArray<float32, 5> > it1;
        	cml::CBaseIt<float32, false, cml::CArray<float32, 5> > it2;
#else
			cml::CBaseIt<float32, false > it1;
        	cml::CBaseIt<float32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

			it1 = Array.begin();
			it2 = Array.begin();

			 /* Set expected values for global data checks */
			expected_returnValue = true;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<float32,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<float32,5,false>(Array, fpTest, 0, 5);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 == it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> Equal_Comparison_operator on float32 Array(false check) \n\n";		
			fprintf(fpTest, "Test Case ---> Equal_Comparison_operator on float32 Array(false check)\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
        	cml::CArray<float32, 5, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<float32, false, cml::CArray<float32, 5> > it1;
        	cml::CBaseIt<float32, false, cml::CArray<float32, 5> > it2;
#else
			cml::CBaseIt<float32, false > it1;
        	cml::CBaseIt<float32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

			it1 = Array.begin();
			it2 = Array.begin()+1;

			 /* Set expected values for global data checks */
			expected_returnValue = false;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<float32,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<float32,5,false>(Array, fpTest, 0, 5);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 == it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

	std::cout << "END ---> test_cml_stl_CBaseIt_overload_Equal_Comparison_operator\n\n";
	fprintf(fpTest, "END ---> test_cml_stl_CBaseIt_overload_Equal_Comparison_operator\n\n");
}
	
void TEST_CLASS_ITERATOR::test_cml_stl_CBaseIt_overload_Unequal_Comparison_operator(int doIt)
{
	std::cout << "START ---> test_cml_stl_CBaseIt_overload_Unequal_Comparison_operator\n\n";		
	fprintf(fpTest, "START ---> test_cml_stl_CBaseIt_overload_Unequal_Comparison_operator\n\n");

	fprintf(fpTest, "Function Name ---> operator!=()const \n\n");

	if (doIt)
	{
		{

			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Unequal_Comparison_operator_001\n\n";		
			fprintf(fpTest, "Test Case ---> Un_Equal_Comparison_operator on char Array(true check)\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
        	cml::CArray<char, 5, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<char, false, cml::CArray<char, 5> > it1;
        	cml::CBaseIt<char, false, cml::CArray<char, 5> > it2;
#else
			cml::CBaseIt<char, false > it1;
        	cml::CBaseIt<char, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = true;
						
			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<char,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<char,5,false>(Array, fpTest, 0,5);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 != it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Unequal_Comparison_operator_002\n\n";		
			fprintf(fpTest, "Test Case ---> Un_Equal_Comparison_operator on char Array(false check)\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
        	cml::CArray<char, 5, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<char, false, cml::CArray<char, 5> > it1;
        	cml::CBaseIt<char, false, cml::CArray<char, 5> > it2;
#else
			cml::CBaseIt<char, false > it1;
        	cml::CBaseIt<char, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

			it1 = Array.begin();
			it2 = Array.begin();

            /* Set expected values for global data checks */
			expected_returnValue = false;
						
			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<char,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<char,5,false>(Array, fpTest, 0, 5);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 != it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Unequal_Comparison_operator_003\n\n";		
			fprintf(fpTest, "Test Case ---> Un_Equal_Comparison_operator on sint32 Array(true check)\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
        	cml::CArray<sint32, 5, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 5> > it1;
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 5> > it2;
#else
			cml::CBaseIt<sint32, false > it1;
        	cml::CBaseIt<sint32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = true;
						
			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<sint32,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<sint32,5,false>(Array, fpTest, 0, 5);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 != it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Unequal_Comparison_operator_004\n\n";		
			fprintf(fpTest, "Test Case ---> Un_Equal_Comparison_operator on sint Array(false check)\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
        	cml::CArray<sint32, 5, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 5> > it1;
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 5> > it2;
#else
			cml::CBaseIt<sint32, false > it1;
        	cml::CBaseIt<sint32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

			it1 = Array.begin();
			it2 = Array.begin();

            /* Set expected values for global data checks */
			expected_returnValue = false;
						
			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<sint32,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<sint32,5,false>(Array, fpTest, 0, 5);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 != it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Unequal_Comparison_operator_005\n\n";		
			fprintf(fpTest, "Test Case ---> Un_Equal_Comparison_operator on short Array(true check)\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
        	cml::CArray<short, 5, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<short, false, cml::CArray<short, 5> > it1;
        	cml::CBaseIt<short, false, cml::CArray<short, 5> > it2;
#else
			cml::CBaseIt<short, false > it1;
        	cml::CBaseIt<short, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = true;
						
			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<short,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<short,5,false>(Array, fpTest, 0, 5);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 != it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Unequal_Comparison_operator_006\n\n";		
			fprintf(fpTest, "Test Case ---> Un_Equal_Comparison_operator on short Array(false check) \n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
        	cml::CArray<short, 5, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<short, false, cml::CArray<short, 5> > it1;
        	cml::CBaseIt<short, false, cml::CArray<short, 5> > it2;
#else
			cml::CBaseIt<short, false > it1;
        	cml::CBaseIt<short, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

			it1 = Array.begin();
			it2 = Array.begin();

            /* Set expected values for global data checks */
			expected_returnValue = false;
						
			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<short,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<short,5,false>(Array, fpTest, 0, 5);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 != it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

	std::cout << "END ---> test_cml_stl_CBaseIt_overload_Unequal_Comparison_operator\n\n";
	fprintf(fpTest, "END ---> test_cml_stl_CBaseIt_overload_Unequal_Comparison_operator\n\n");
}


	
void TEST_CLASS_ITERATOR::test_cml_stl_CBaseIt_overload_Greater_or_Equal_operator(int doIt)
{
	std::cout << "START ---> test_cml_stl_CBaseIt_overload_Greater_or_Equal_operator\n\n";		
	fprintf(fpTest, "START ---> test_cml_stl_CBaseIt_overload_Greater_or_Equal_operator\n\n");

	fprintf(fpTest, "Function Name ---> operator>=()const \n\n");

	if (doIt)
	{
		{

			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Greater_or_Equal_operator_001\n\n";		
			fprintf(fpTest, "Test Case ---> Greater_or_Equal_operator of char array(false check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<char, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<char, false, cml::CArray<char, 2> > it1;
        	cml::CBaseIt<char, false, cml::CArray<char, 2> > it2;
#else
			cml::CBaseIt<char, false > it1;
        	cml::CBaseIt<char, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = false;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<char,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<char,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 >= it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Greater_or_Equal_operator_002\n\n";		
			fprintf(fpTest, "Test Case ---> Greater_or_Equal_operator of char array(true check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<char, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<char, false, cml::CArray<char, 2> > it1;
        	cml::CBaseIt<char, false, cml::CArray<char, 2> > it2;
#else
			cml::CBaseIt<char, false > it1;
        	cml::CBaseIt<char, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 2;
			Array[1] = 1;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = false;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<char,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<char,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 >= it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Greater_or_Equal_operator_003\n\n";		
			fprintf(fpTest, "Test Case ---> Greater_or_Equal_operator of sint32 array(false check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<sint32, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 2> > it1;
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 2> > it2;
#else
			cml::CBaseIt<sint32, false > it1;
        	cml::CBaseIt<sint32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = false;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<sint32,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<sint32,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 >= it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Greater_or_Equal_operator_004\n\n";		
			fprintf(fpTest, "Test Case ---> Greater_or_Equal_operator of sint32 array(true check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<sint32, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 2> > it1;
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 2> > it2;
#else
			cml::CBaseIt<sint32, false > it1;
        	cml::CBaseIt<sint32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 2;
			Array[1] = 1;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = false;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<sint32,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<sint32,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 >= it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Greater_or_Equal_operator_005\n\n";		
			fprintf(fpTest, "Test Case ---> Greater_or_Equal_operator of short array(false check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<short, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<short, false, cml::CArray<short, 2> > it1;
        	cml::CBaseIt<short, false, cml::CArray<short, 2> > it2;
#else
			cml::CBaseIt<short, false > it1;
        	cml::CBaseIt<short, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = false;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<short,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<short,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 >= it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Greater_or_Equal_operator_006\n\n";		
			fprintf(fpTest, "Test Case ---> Greater_or_Equal_operator of short array(true check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<short, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<short, false, cml::CArray<short, 2> > it1;
        	cml::CBaseIt<short, false, cml::CArray<short, 2> > it2;
#else
			cml::CBaseIt<short, false > it1;
        	cml::CBaseIt<short, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 2;
			Array[1] = 1;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = false;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<short,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<short,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 >= it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Greater_or_Equal_operator_007\n\n";		
			fprintf(fpTest, "Test Case ---> Greater_or_Equal_operator of float32 array(false check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<float32, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<float32, false, cml::CArray<float32, 2> > it1;
        	cml::CBaseIt<float32, false, cml::CArray<float32, 2> > it2;
#else
			cml::CBaseIt<float32, false > it1;
        	cml::CBaseIt<float32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = false;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<float32,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<float32,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 >= it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Greater_or_Equal_operator_008\n\n";		
			fprintf(fpTest, "Test Case ---> Greater_or_Equal_operator of float32 array(true check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<float32, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<float32, false, cml::CArray<float32, 2> > it1;
        	cml::CBaseIt<float32, false, cml::CArray<float32, 2> > it2;
#else
			cml::CBaseIt<float32, false > it1;
        	cml::CBaseIt<float32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 2;
			Array[1] = 1;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = false;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<float32,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<float32,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 >= it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

	std::cout << "END ---> test_cml_stl_CBaseIt_overload_Greater_or_Equal_operator\n\n";
	fprintf(fpTest, "END ---> test_cml_stl_CBaseIt_overload_Greater_or_Equal_operator\n\n");
}

void TEST_CLASS_ITERATOR::test_cml_stl_CBaseIt_overload_Lesser_or_Equal_operator(int doIt)
{
	std::cout << "START ---> test_cml_stl_CBaseIt_overload_Lesser_or_Equal_operator\n\n";		
	fprintf(fpTest, "START ---> test_cml_stl_CBaseIt_overload_Lesser_or_Equal_operator\n\n");

	fprintf(fpTest, "Function Name ---> operator<=()const \n\n");

	if (doIt)
	{
		{
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Lesser_or_Equal_operator_001\n\n";		
			fprintf(fpTest, "Test Case ---> Lesser_or_Equal_operator of char array(true check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<char, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<char, false, cml::CArray<char, 2> > it1;
        	cml::CBaseIt<char, false, cml::CArray<char, 2> > it2;
#else
			cml::CBaseIt<char, false > it1;
        	cml::CBaseIt<char, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = true;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<char,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<char,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 <= it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Lesser_or_Equal_operator_002\n\n";		
			fprintf(fpTest, "Test Case ---> Lesser_or_Equal_operator of char array(false check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<char, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<char, false, cml::CArray<char, 2> > it1;
        	cml::CBaseIt<char, false, cml::CArray<char, 2> > it2;
#else
			cml::CBaseIt<char, false > it1;
        	cml::CBaseIt<char, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = false;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<char,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<char,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it2 <= it1);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Lesser_or_Equal_operator_003\n\n";		
			fprintf(fpTest, "Test Case ---> Lesser_or_Equal_operator of sint32 array(true check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<sint32, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 2> > it1;
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 2> > it2;
#else
			cml::CBaseIt<sint32, false > it1;
        	cml::CBaseIt<sint32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = true;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<sint32,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<sint32,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 <= it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Lesser_or_Equal_operator_004\n\n";		
			fprintf(fpTest, "Test Case ---> Lesser_or_Equal_operator of sint32 array(false check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<sint32, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 2> > it1;
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 2> > it2;
#else
			cml::CBaseIt<sint32, false > it1;
        	cml::CBaseIt<sint32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = false;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<sint32,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<sint32,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it2 <= it1);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Lesser_or_Equal_operator_005\n\n";		
			fprintf(fpTest, "Test Case ---> Lesser_or_Equal_operator of short array(true check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<short, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<short, false, cml::CArray<short, 2> > it1;
        	cml::CBaseIt<short, false, cml::CArray<short, 2> > it2;
#else
			cml::CBaseIt<short, false > it1;
        	cml::CBaseIt<short, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = true;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<short,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<short,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 <= it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Lesser_or_Equal_operator_006\n\n";		
			fprintf(fpTest, "Test Case ---> Lesser_or_Equal_operator of short array(false check) \n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<short, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<short, false, cml::CArray<short, 2> > it1;
        	cml::CBaseIt<short, false, cml::CArray<short, 2> > it2;
#else
			cml::CBaseIt<short, false > it1;
        	cml::CBaseIt<short, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = false;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<short,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<short,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it2 <= it1);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Lesser_or_Equal_operator_007\n\n";		
			fprintf(fpTest, "Test Case ---> Lesser_or_Equal_operator of float32 array(true check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<float32, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<float32, false, cml::CArray<float32, 2> > it1;
        	cml::CBaseIt<float32, false, cml::CArray<float32, 2> > it2;
#else
			cml::CBaseIt<float32, false > it1;
        	cml::CBaseIt<float32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = true;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<float32,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<float32,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 <= it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Lesser_or_Equal_operator_008\n\n";		
			fprintf(fpTest, "Test Case ---> Lesser_or_Equal_operator of float32 array(false check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<float32, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<float32, false, cml::CArray<float32, 2> > it1;
        	cml::CBaseIt<float32, false, cml::CArray<float32, 2> > it2;
#else
			cml::CBaseIt<float32, false > it1;
        	cml::CBaseIt<float32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = false;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<float32,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<float32,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it2 <= it1);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

	std::cout << "END ---> test_cml_stl_CBaseIt_overload_Lesser_or_Equal_operator\n\n";
	fprintf(fpTest, "END ---> test_cml_stl_CBaseIt_overload_Lesser_or_Equal_operator\n\n");
}

void TEST_CLASS_ITERATOR::test_cml_stl_CBaseIt_overload_Less_than_operator(int doIt)
{
	std::cout << "START ---> test_cml_stl_CBaseIt_overload_Less_than_operator\n\n";		
	fprintf(fpTest, "START ---> test_cml_stl_CBaseIt_overload_Less_than_operator\n\n");

	fprintf(fpTest, "Function Name ---> operator<()const \n\n");

	if (doIt)
	{
		{
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Less_than_operator_001\n\n";		
			fprintf(fpTest, "Test Case ---> Less_than_operator of char array(true check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<char, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<char, false, cml::CArray<char, 2> > it1;
        	cml::CBaseIt<char, false, cml::CArray<char, 2> > it2;
#else
			cml::CBaseIt<char, false > it1;
        	cml::CBaseIt<char, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = true;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<char,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<char,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 < it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Less_than_operator_002\n\n";		
			fprintf(fpTest, "Test Case ---> Less_than_operator of char array(false check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<char, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<char, false, cml::CArray<char, 2> > it1;
        	cml::CBaseIt<char, false, cml::CArray<char, 2> > it2;
#else
			cml::CBaseIt<char, false > it1;
        	cml::CBaseIt<char, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 2;
			Array[1] = 1;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = false;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<char,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<char,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it2 < it1);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Less_than_operator_003\n\n";		
			fprintf(fpTest, "Test Case ---> Less_than_operator of sint32 array(true check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<sint32, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 2> > it1;
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 2> > it2;
#else
			cml::CBaseIt<sint32, false > it1;
        	cml::CBaseIt<sint32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = true;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<sint32,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<sint32,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 < it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Less_than_operator_004\n\n";		
			fprintf(fpTest, "Test Case ---> Less_than_operator of sint32 array(false check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<sint32, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 2> > it1;
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 2> > it2;
#else
			cml::CBaseIt<sint32, false > it1;
        	cml::CBaseIt<sint32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 2;
			Array[1] = 1;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = false;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<sint32,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<sint32,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it2 < it1);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Less_than_operator_005\n\n";		
			fprintf(fpTest, "Test Case ---> Less_than_operator of short array(true check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<short, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<short, false, cml::CArray<short, 2> > it1;
        	cml::CBaseIt<short, false, cml::CArray<short, 2> > it2;
#else
			cml::CBaseIt<short, false > it1;
        	cml::CBaseIt<short, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = true;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<short,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<short,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 < it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Less_than_operator_006\n\n";		
			fprintf(fpTest, "Test Case ---> Less_than_operator of short array(false check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<short, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<short, false, cml::CArray<short, 2> > it1;
        	cml::CBaseIt<short, false, cml::CArray<short, 2> > it2;
#else
			cml::CBaseIt<short, false > it1;
        	cml::CBaseIt<short, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 2;
			Array[1] = 1;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = false;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<short,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<short,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it2 < it1);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Less_than_operator_007\n\n";		
			fprintf(fpTest, "Test Case ---> Less_than_operator of float32 array(true check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<float32, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<float32, false, cml::CArray<float32, 2> > it1;
        	cml::CBaseIt<float32, false, cml::CArray<float32, 2> > it2;
#else
			cml::CBaseIt<float32, false > it1;
        	cml::CBaseIt<float32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = true;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<float32,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<float32,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 < it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Less_than_operator_008\n\n";		
			fprintf(fpTest, "Test Case ---> Less_than_operator of float32 array(false check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<float32, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<float32, false, cml::CArray<float32, 2> > it1;
        	cml::CBaseIt<float32, false, cml::CArray<float32, 2> > it2;
#else
			cml::CBaseIt<float32, false > it1;
        	cml::CBaseIt<float32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 2;
			Array[1] = 1;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = false;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<float32,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<float32,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it2 < it1);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
	std::cout << "END ---> test_cml_stl_CBaseIt_overload_Less_than_operator\n\n";
	fprintf(fpTest, "END ---> test_cml_stl_CBaseIt_overload_Less_than_operator\n\n");
}

void TEST_CLASS_ITERATOR::test_cml_stl_CBaseIt_overload_Greater_than_operator(int doIt)
{
	std::cout << "START ---> test_cml_stl_CBaseIt_overload_Greater_than_operator\n\n";		
	fprintf(fpTest, "START ---> test_cml_stl_CBaseIt_overload_Greater_than_operator\n\n");

	fprintf(fpTest, "Function Name ---> operator>()const \n\n");

	if (doIt) 
	{
		{
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Greater_than_operator_001\n\n";		
			fprintf(fpTest, "Test Case ---> Greater_than_operator of char array(false check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<char, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<char, false, cml::CArray<char, 2> > it1;
        	cml::CBaseIt<char, false, cml::CArray<char, 2> > it2;
#else
			cml::CBaseIt<char, false > it1;
        	cml::CBaseIt<char, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = false;
			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<char,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<char,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 > it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Greater_than_operator_002\n\n";		
			fprintf(fpTest, "Test Case ---> Greater_than_operator of char array(true check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<char, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<char, false, cml::CArray<char, 2> > it1;
        	cml::CBaseIt<char, false, cml::CArray<char, 2> > it2;
#else
			cml::CBaseIt<char, false > it1;
        	cml::CBaseIt<char, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 2;
			Array[1] = 1;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = true;
			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<char,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<char,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it2 > it1);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Greater_than_operator_003\n\n";		
			fprintf(fpTest, "Test Case ---> Greater_than_operator of sint32 array(false check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<sint32, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 2> > it1;
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 2> > it2;
#else
			cml::CBaseIt<sint32, false > it1;
        	cml::CBaseIt<sint32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = false;
			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<sint32,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<sint32,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 > it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Greater_than_operator_004\n\n";		
			fprintf(fpTest, "Test Case ---> Greater_than_operator of sint32 array(true check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<sint32, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 2> > it1;
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 2> > it2;
#else
			cml::CBaseIt<sint32, false > it1;
        	cml::CBaseIt<sint32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 2;
			Array[1] = 1;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = true;
			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<sint32,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<sint32,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it2 > it1);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Greater_than_operator_005\n\n";		
			fprintf(fpTest, "Test Case ---> Greater_than_operator of short array(false check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<short, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<short, false, cml::CArray<short, 2> > it1;
        	cml::CBaseIt<short, false, cml::CArray<short, 2> > it2;
#else
			cml::CBaseIt<short, false > it1;
        	cml::CBaseIt<short, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = false;
			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<short,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<short,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 > it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Greater_than_operator_006\n\n";		
			fprintf(fpTest, "Test Case ---> Greater_than_operator of short array(true check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<short, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<short, false, cml::CArray<short, 2> > it1;
        	cml::CBaseIt<short, false, cml::CArray<short, 2> > it2;
#else
			cml::CBaseIt<short, false > it1;
        	cml::CBaseIt<short, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 2;
			Array[1] = 1;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = true;
			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<short,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<short,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it2 > it1);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Greater_than_operator_007\n\n";		
			fprintf(fpTest, "Test Case ---> Greater_than_operator of float32 array(false check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<float32, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<float32, false, cml::CArray<float32, 2> > it1;
        	cml::CBaseIt<float32, false, cml::CArray<float32, 2> > it2;
#else
			cml::CBaseIt<float32, false > it1;
        	cml::CBaseIt<float32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = false;
			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<float32,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<float32,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it1 > it2);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_Greater_than_operator_008\n\n";		
			fprintf(fpTest, "Test Case ---> Greater_than_operator of float32 array(true check)\n\n");

			std::cout << "Data Dimension ---> 2 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<float32, 2, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<float32, false, cml::CArray<float32, 2> > it1;
        	cml::CBaseIt<float32, false, cml::CArray<float32, 2> > it2;
#else
			cml::CBaseIt<float32, false > it1;
        	cml::CBaseIt<float32, false > it2;
#endif
        	
        	bool returnValue;
        	bool expected_returnValue;

            /* Set global data */
            initialise_global_data();
			Array[0] = 2;
			Array[1] = 1;

			it1 = Array.begin();
			it2 = Array.begin() + 1;

            /* Set expected values for global data checks */
			expected_returnValue = true;
			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vArrayPrintSegment_to_console<float32,2,false>(Array,0,2);
			check__vArraySegmentPrint_to_File<float32,2,false>(Array, fpTest, 0, 2);
			
			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<bool>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = (it2 > it1);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<bool>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

	std::cout << "END ---> test_cml_stl_CBaseIt_overload_Greater_than_operator\n\n";
	fprintf(fpTest, "END ---> test_cml_stl_CBaseIt_overload_Greater_than_operator\n\n");
}

void TEST_CLASS_ITERATOR::test_cml_stl_CBaseIt_memory_distance(int doIt)
{
	std::cout << "START ---> test_cml_stl_CBaseIt_memory_distance\n\n";		
	fprintf(fpTest, "START ---> test_cml_stl_CBaseIt_memory_distance\n\n");

	fprintf(fpTest, "Function Name ---> memory_distance()const \n\n");

	if (doIt)
	{
		{
		std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_deference_operator_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_stl_CBaseIt_overload_deference_operator_001\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<char, 10, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<char, false, cml::CArray<char, 10> > it1;
        	cml::CBaseIt<char, false, cml::CArray<char, 10> > it2;
#else
			cml::CBaseIt<char, false > it1;
        	cml::CBaseIt<char, false > it2;
#endif
        	
        	int returnValue;
        	int expected_returnValue;

            /* Set global data */
            initialise_global_data();

			it1 = Array.begin();
			it2 = Array.begin() + 5;

            /* Set expected values for global data checks */
			expected_returnValue = 5;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__PrintValue_to_console<char *>(&Array[0]);
			check__PrintValue_to_File(&Array[0],fpTest);

			std::cout << "\ninput2 = \n";	
			fprintf(fpTest, "\ninput2 = \n");

			check__PrintValue_to_console<char *>(&Array[4]);
			check__PrintValue_to_File(&Array[4],fpTest);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<char>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = it2.memory_distance(it1);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<char>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			fprintf(fpTest, "Remarks ---> Address value differs on different platforms\n\n");
			std::cout << "Remarks ---> Address value differs on different platforms\n\n";
						  
		}

		{
		std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_deference_operator_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_stl_CBaseIt_overload_deference_operator_002\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<sint32, 10, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 10> > it1;
        	cml::CBaseIt<sint32, false, cml::CArray<sint32, 10> > it2;
#else
			cml::CBaseIt<sint32, false > it1;
        	cml::CBaseIt<sint32, false > it2;
#endif
        	
        	int returnValue;
        	int expected_returnValue;

            /* Set global data */
            initialise_global_data();

			it1 = Array.begin();
			it2 = Array.begin() + 5;

            /* Set expected values for global data checks */
			expected_returnValue = 5;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__PrintValue_to_console<sint32 *>(&Array[0]);
			check__PrintValue_to_File(&Array[0],fpTest);

			std::cout << "\ninput2 = \n";	
			fprintf(fpTest, "\ninput2 = \n");

			check__PrintValue_to_console<sint32 *>(&Array[4]);
			check__PrintValue_to_File(&Array[4],fpTest);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<char>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = it2.memory_distance(it1);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<char>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			fprintf(fpTest, "Remarks ---> Address value differs on different platforms\n\n");
			std::cout << "Remarks ---> Address value differs on different platforms\n\n";
						  
		}

		{
		std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_deference_operator_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_stl_CBaseIt_overload_deference_operator_003\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<short, 10, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<short, false, cml::CArray<short, 10> > it1;
        	cml::CBaseIt<short, false, cml::CArray<short, 10> > it2;
#else
			cml::CBaseIt<short, false > it1;
        	cml::CBaseIt<short, false > it2;
#endif
        	
        	int returnValue;
        	int expected_returnValue;

            /* Set global data */
            initialise_global_data();

			it1 = Array.begin();
			it2 = Array.begin() + 5;

            /* Set expected values for global data checks */
			expected_returnValue = 5;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__PrintValue_to_console<short *>(&Array[0]);
			check__PrintValue_to_File(&Array[0],fpTest);

			std::cout << "\ninput2 = \n";	
			fprintf(fpTest, "\ninput2 = \n");

			check__PrintValue_to_console<short *>(&Array[4]);
			check__PrintValue_to_File(&Array[4],fpTest);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<char>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = it2.memory_distance(it1);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<char>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			fprintf(fpTest, "Remarks ---> Address value differs on different platforms\n\n");
			std::cout << "Remarks ---> Address value differs on different platforms\n\n";
						  
		}

		{
		std::cout << "Test Case ---> test_cml_stl_CBaseIt_overload_deference_operator_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_stl_CBaseIt_overload_deference_operator_004\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");

        	/* Test case data declarations */
        	cml::CArray<float32, 10, false> Array;

#ifndef NDEBUG
        	cml::CBaseIt<float32, false, cml::CArray<float32, 10> > it1;
        	cml::CBaseIt<float32, false, cml::CArray<float32, 10> > it2;
#else
			cml::CBaseIt<float32, false > it1;
        	cml::CBaseIt<float32, false > it2;
#endif
        	
        	int returnValue;
        	int expected_returnValue;

            /* Set global data */
            initialise_global_data();

			it1 = Array.begin();
			it2 = Array.begin() + 5;

            /* Set expected values for global data checks */
			expected_returnValue = 5;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__PrintValue_to_console<float32 *>(&Array[0]);
			check__PrintValue_to_File(&Array[0],fpTest);

			std::cout << "\ninput2 = \n";	
			fprintf(fpTest, "\ninput2 = \n");

			check__PrintValue_to_console<float32 *>(&Array[4]);
			check__PrintValue_to_File(&Array[4],fpTest);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<char>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = it2.memory_distance(it1);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<char>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			fprintf(fpTest, "Remarks ---> Address value differs on different platforms\n\n");
			std::cout << "Remarks ---> Address value differs on different platforms\n\n";
						  
		}
	}

	std::cout << "END ---> test_cml_stl_CBaseIt_memory_distance\n\n";
	fprintf(fpTest, "END ---> test_cml_stl_CBaseIt_memory_distance\n\n");
}

void TEST_CLASS_ITERATOR::test_cml_stl_CLinMemIt_Operator_Subscript(int doIt)
{
	std::cout << "START ---> test_cml_stl_CLinMemIt_Operator_Subscript\n\n";		
	fprintf(fpTest, "START ---> test_cml_stl_CLinMemIt_Operator_Subscript\n\n");

	fprintf(fpTest, "Function Name ---> operator[](const)const \n\n");

	if (doIt) 
	{

		{
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subscript_001\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subscript_001\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
			cml::CArray<char, 5> Array;
			char returnValue;
			char expected_returnValue;


			/* Set global data */
			initialise_global_data();

			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

#ifndef NDEBUG
        	cml::CLinMemIt<char, false, cml::CArray<char, 5> > it(&Array[0], &Array);
#else
			cml::CLinMemIt<char, false > it(&Array[0]);
#endif					

			/* Set expected values for global data checks */
			expected_returnValue = 2;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<char,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<char,5,false>(Array, fpTest, 0, 5);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<char>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = it[1];

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<char>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subscript_002\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subscript_002\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
			cml::CArray<sint32, 5> Array;
			sint32 returnValue;
			sint32 expected_returnValue;


			/* Set global data */
			initialise_global_data();

			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

#ifndef NDEBUG
        	cml::CLinMemIt<sint32, false, cml::CArray<sint32, 5> > it(&Array[0], &Array);
#else
			cml::CLinMemIt<sint32, false > it(&Array[0]);
#endif			

			/* Set expected values for global data checks */
			expected_returnValue = 2;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<sint32,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<sint32,5,false>(Array, fpTest, 0, 5);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<sint32>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = it[1];

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<char>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subscript_003\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subscript_003\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
			cml::CArray<short, 5> Array;
			short returnValue;
			short expected_returnValue;


			/* Set global data */
			initialise_global_data();

			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

#ifndef NDEBUG
        	cml::CLinMemIt<short, false, cml::CArray<short, 5> > it(&Array[0], &Array);
#else
			cml::CLinMemIt<short, false > it(&Array[0]);
#endif			

			/* Set expected values for global data checks */
			expected_returnValue = 2;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<short,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<short,5,false>(Array, fpTest, 0, 5);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<short>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = it[1];

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<short>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subscript_004\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subscript_004\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
			cml::CArray<float32, 5> Array;
			float32 returnValue;
			float32 expected_returnValue;


			/* Set global data */
			initialise_global_data();

			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;


#ifndef NDEBUG
        	cml::CLinMemIt<float32, false, cml::CArray<float32, 5> > it(&Array[0], &Array);
#else
			cml::CLinMemIt<float32, false > it(&Array[0]);
#endif
			

			/* Set expected values for global data checks */
			expected_returnValue = 2;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<float32,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<float32,5,false>(Array, fpTest, 0, 5);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__PrintValue_to_console<float32>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = it[1];

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<float32>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			if(bool_val)
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

	std::cout << "END ---> test_cml_stl_CLinMemIt_Operator_Subscript\n\n";
	fprintf(fpTest, "END ---> test_cml_stl_CLinMemIt_Operator_Subscript\n\n");
}

void TEST_CLASS_ITERATOR::test_cml_stl_CLinMemIt_Operator_Post_Increment(int doIt)
{
	std::cout << "START ---> test_cml_stl_CLinMemIt_Operator_Post_Increment\n\n";		
	fprintf(fpTest, "START ---> test_cml_stl_CLinMemIt_Operator_Post_Increment\n\n");

	fprintf(fpTest, "Function Name ---> operator++() \n\n");

if (doIt) 
	{
		{
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Post_Increment_001\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Post_Increment_001\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
			cml::CArray<char, 5> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<char, false, cml::CArray<char, 5> > it;
			cml::CLinMemIt<char, false, cml::CArray<char, 5> > it_dummy;
#else
			cml::CLinMemIt<char, false > it;
			cml::CLinMemIt<char, false > it_dummy;
#endif
			
			char returnValue1;
			char returnValue2;
			char expected_returnValue1;
			char expected_returnValue2;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			it = Array.begin();

			/* Set expected values for global data checks */
			expected_returnValue1 = 1;
			expected_returnValue2 = 2;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<char,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<char,5,false>(Array, fpTest, 0, 5);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<char>(expected_returnValue1);
			check__PrintValue_to_File(expected_returnValue1,fpTest);

			std::cout << "expected_result2 = \n";	
			fprintf(fpTest, "expected_result2 = \n");

			check__PrintValue_to_console<char>(expected_returnValue2);
			check__PrintValue_to_File(expected_returnValue2,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it_dummy = it++;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


			returnValue1 = *it_dummy;
			returnValue2 = *it;

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<char>(returnValue1);
			check__PrintValue_to_File(returnValue1,fpTest);

			std::cout << "result2 ---> \n";
			fprintf(fpTest, "result2 = \n");

			check__PrintValue_to_console<char>(returnValue2);
			check__PrintValue_to_File(returnValue2,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue1, expected_returnValue1);
			bool_val &= check__boCompare(returnValue2, expected_returnValue2);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Post_Increment_002\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Post_Increment_002\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
			cml::CArray<sint32, 5> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<sint32, false, cml::CArray<sint32, 5> > it;
			cml::CLinMemIt<sint32, false, cml::CArray<sint32, 5> > it_dummy;
#else
			cml::CLinMemIt<sint32, false > it;
			cml::CLinMemIt<sint32, false > it_dummy;
#endif
			
			sint32 returnValue1;
			sint32 returnValue2;
			sint32 expected_returnValue1;
			sint32 expected_returnValue2;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			it = Array.begin();

			/* Set expected values for global data checks */
			expected_returnValue1 = 1;
			expected_returnValue2 = 2;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<sint32,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<sint32,5,false>(Array, fpTest, 0, 5);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<sint32>(expected_returnValue1);
			check__PrintValue_to_File(expected_returnValue1,fpTest);

			std::cout << "expected_result2 = \n";	
			fprintf(fpTest, "expected_result2 = \n");

			check__PrintValue_to_console<sint32>(expected_returnValue2);
			check__PrintValue_to_File(expected_returnValue2,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it_dummy = it++;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


			returnValue1 = *it_dummy;
			returnValue2 = *it;

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<sint32>(returnValue1);
			check__PrintValue_to_File(returnValue1,fpTest);

			std::cout << "result2 ---> \n";
			fprintf(fpTest, "result2 = \n");

			check__PrintValue_to_console<sint32>(returnValue2);
			check__PrintValue_to_File(returnValue2,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue1, expected_returnValue1);
			bool_val &= check__boCompare(returnValue2, expected_returnValue2);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Post_Increment_003\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Post_Increment_003\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
			cml::CArray<float32, 5> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<float32, false, cml::CArray<float32, 5> > it;
			cml::CLinMemIt<float32, false, cml::CArray<float32, 5> > it_dummy;
#else
			cml::CLinMemIt<float32, false > it;
			cml::CLinMemIt<float32, false > it_dummy;
#endif
			
			float32 returnValue1;
			float32 returnValue2;
			float32 expected_returnValue1;
			float32 expected_returnValue2;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			it = Array.begin();

			/* Set expected values for global data checks */
			expected_returnValue1 = 1;
			expected_returnValue2 = 2;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<float32,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<float32,5,false>(Array, fpTest, 0, 5);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<float32>(expected_returnValue1);
			check__PrintValue_to_File(expected_returnValue1,fpTest);

			std::cout << "expected_result2 = \n";	
			fprintf(fpTest, "expected_result2 = \n");

			check__PrintValue_to_console<float32>(expected_returnValue2);
			check__PrintValue_to_File(expected_returnValue2,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it_dummy = it++;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


			returnValue1 = *it_dummy;
			returnValue2 = *it;

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<float32>(returnValue1);
			check__PrintValue_to_File(returnValue1,fpTest);

			std::cout << "result2 ---> \n";
			fprintf(fpTest, "result2 = \n");

			check__PrintValue_to_console<float32>(returnValue2);
			check__PrintValue_to_File(returnValue2,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue1, expected_returnValue1);
			bool_val &= check__boCompare(returnValue2, expected_returnValue2);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Post_Increment_004\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Post_Increment_004\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
			cml::CArray<short, 5> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<short, false, cml::CArray<short, 5> > it;
			cml::CLinMemIt<short, false, cml::CArray<short, 5> > it_dummy;
#else
			cml::CLinMemIt<short, false > it;
			cml::CLinMemIt<short, false > it_dummy;
#endif
			
			short returnValue1;
			short returnValue2;
			short expected_returnValue1;
			short expected_returnValue2;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			it = Array.begin();

			/* Set expected values for global data checks */
			expected_returnValue1 = 1;
			expected_returnValue2 = 2;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<short,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<short,5,false>(Array, fpTest, 0, 5);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<short>(expected_returnValue1);
			check__PrintValue_to_File(expected_returnValue1,fpTest);

			std::cout << "expected_result2 = \n";	
			fprintf(fpTest, "expected_result2 = \n");

			check__PrintValue_to_console<short>(expected_returnValue2);
			check__PrintValue_to_File(expected_returnValue2,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it_dummy = it++;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


			returnValue1 = *it_dummy;
			returnValue2 = *it;

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<short>(returnValue1);
			check__PrintValue_to_File(returnValue1,fpTest);

			std::cout << "result2 ---> \n";
			fprintf(fpTest, "result2 = \n");

			check__PrintValue_to_console<short>(returnValue2);
			check__PrintValue_to_File(returnValue2,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue1, expected_returnValue1);
			bool_val &= check__boCompare(returnValue2, expected_returnValue2);
			
			if(bool_val)
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

	std::cout << "END ---> test_cml_stl_CLinMemIt_Operator_Post_Increment\n\n";
	fprintf(fpTest, "END ---> test_cml_stl_CLinMemIt_Operator_Post_Increment\n\n");
}

void TEST_CLASS_ITERATOR::test_cml_stl_CLinMemIt_Operator_Pre_Increment(int doIt)
{
	std::cout << "START ---> test_cml_stl_CLinMemIt_Operator_Pre_Increment\n\n";		
	fprintf(fpTest, "START ---> test_cml_stl_CLinMemIt_Operator_Pre_Increment\n\n");

	fprintf(fpTest, "Function Name ---> operator++(difference_type) \n\n");

	if (doIt) 
	{
		{
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Pre_Increment_001\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Pre_Increment_001\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
			cml::CArray<char, 5> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<char, false, cml::CArray<char, 5> > it;
#else
			cml::CLinMemIt<char, false > it;
#endif
			
			char returnValue;
			char expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			it = Array.begin();

			/* Set expected values for global data checks */
			expected_returnValue = 2;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<char,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<char,5,false>(Array, fpTest, 0, 5);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<char>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = *++it;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<char>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Pre_Increment_002\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Pre_Increment_002\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
			cml::CArray<sint32, 5> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<sint32, false, cml::CArray<sint32, 5> > it;
#else
			cml::CLinMemIt<sint32, false > it;
#endif
			
			sint32 returnValue;
			sint32 expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			it = Array.begin();

			/* Set expected values for global data checks */
			expected_returnValue = 2;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<sint32,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<sint32,5,false>(Array, fpTest, 0, 5);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<sint32>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = *++it;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<sint32>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Pre_Increment_003\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Pre_Increment_003\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
			cml::CArray<short, 5> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<short, false, cml::CArray<short, 5> > it;
#else
			cml::CLinMemIt<short, false > it;
#endif
			
			short returnValue;
			short expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			it = Array.begin();

			/* Set expected values for global data checks */
			expected_returnValue = 2;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<short,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<short,5,false>(Array, fpTest, 0, 5);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<short>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = *++it;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<short>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Pre_Increment_004\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Pre_Increment_004\n\n");

			std::cout << "Data Dimension ---> 5 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 5 \n\n");

        	/* Test case data declarations */
			cml::CArray<float32, 5> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<float32, false, cml::CArray<float32, 5> > it;
#else
			cml::CLinMemIt<float32, false > it;
#endif
			
			float32 returnValue;
			float32 expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			it = Array.begin();

			/* Set expected values for global data checks */
			expected_returnValue = 2;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<float32,5,false>(Array,0,5);
			check__vArraySegmentPrint_to_File<float32,5,false>(Array, fpTest, 0, 5);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<float32>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = *++it;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<float32>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			
			if(bool_val)
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

	std::cout << "END ---> test_cml_stl_CLinMemIt_Operator_Pre_Increment\n\n";
	fprintf(fpTest, "END ---> test_cml_stl_CLinMemIt_Operator_Pre_Increment\n\n");
}

void TEST_CLASS_ITERATOR::test_cml_stl_CLinMemIt_Operator_Post_Decrement(int doIt)
{
	std::cout << "START ---> test_cml_stl_CLinMemIt_Operator_Post_Decrement\n\n";		
	fprintf(fpTest, "START ---> test_cml_stl_CLinMemIt_Operator_Post_Decrement\n\n");

	fprintf(fpTest, "Function Name ---> operator--() \n\n");

if (doIt) 
	{
		{
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Post_Decrement_001\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Post_Decrement_001\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<char, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<char, false, cml::CArray<char, 10> > it;
			cml::CLinMemIt<char, false, cml::CArray<char, 10> > it_dummy;
#else
			cml::CLinMemIt<char, false > it;
			cml::CLinMemIt<char, false > it_dummy;
#endif
			
			char returnValue1;
			char returnValue2;
			char expected_returnValue1;
			char expected_returnValue2;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.end();
			it--;

			/* Set expected values for global data checks */
			expected_returnValue1 = 10;
			expected_returnValue2 = 9;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<char,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<char,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<char>(expected_returnValue1);
			check__PrintValue_to_File(expected_returnValue1,fpTest);

			std::cout << "expected_result2 = \n";	
			fprintf(fpTest, "expected_result2 = \n");

			check__PrintValue_to_console<char>(expected_returnValue2);
			check__PrintValue_to_File(expected_returnValue2,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it_dummy = it--;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


			returnValue1 = *it_dummy;
			returnValue2 = *it;

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<char>(returnValue1);
			check__PrintValue_to_File(returnValue1,fpTest);

			std::cout << "result2 ---> \n";
			fprintf(fpTest, "result2 = \n");

			check__PrintValue_to_console<char>(returnValue2);
			check__PrintValue_to_File(returnValue2,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue1, expected_returnValue1);
			bool_val &= check__boCompare(returnValue2, expected_returnValue2);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Post_Decrement_002\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Post_Decrement_002\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<sint32, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<sint32, false, cml::CArray<sint32, 10> > it;
			cml::CLinMemIt<sint32, false, cml::CArray<sint32, 10> > it_dummy;
#else
			cml::CLinMemIt<sint32, false > it;
			cml::CLinMemIt<sint32, false > it_dummy;
#endif
			
			sint32 returnValue1;
			sint32 returnValue2;
			sint32 expected_returnValue1;
			sint32 expected_returnValue2;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.end();
			it--;

			/* Set expected values for global data checks */
			expected_returnValue1 = 10;
			expected_returnValue2 = 9;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<sint32,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<sint32,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<sint32>(expected_returnValue1);
			check__PrintValue_to_File(expected_returnValue1,fpTest);

			std::cout << "expected_result2 = \n";	
			fprintf(fpTest, "expected_result2 = \n");

			check__PrintValue_to_console<sint32>(expected_returnValue2);
			check__PrintValue_to_File(expected_returnValue2,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it_dummy = it--;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


			returnValue1 = *it_dummy;
			returnValue2 = *it;

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<sint32>(returnValue1);
			check__PrintValue_to_File(returnValue1,fpTest);

			std::cout << "result2 ---> \n";
			fprintf(fpTest, "result2 = \n");

			check__PrintValue_to_console<sint32>(returnValue2);
			check__PrintValue_to_File(returnValue2,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue1, expected_returnValue1);
			bool_val &= check__boCompare(returnValue2, expected_returnValue2);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Post_Decrement_003\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Post_Decrement_003\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<short, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<short, false, cml::CArray<short, 10> > it;
			cml::CLinMemIt<short, false, cml::CArray<short, 10> > it_dummy;
#else
			cml::CLinMemIt<short, false > it;
			cml::CLinMemIt<short, false > it_dummy;
#endif
			
			short returnValue1;
			short returnValue2;
			short expected_returnValue1;
			short expected_returnValue2;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.end();
			it--;

			/* Set expected values for global data checks */
			expected_returnValue1 = 10;
			expected_returnValue2 = 9;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<short,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<short,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<short>(expected_returnValue1);
			check__PrintValue_to_File(expected_returnValue1,fpTest);

			std::cout << "expected_result2 = \n";	
			fprintf(fpTest, "expected_result2 = \n");

			check__PrintValue_to_console<short>(expected_returnValue2);
			check__PrintValue_to_File(expected_returnValue2,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it_dummy = it--;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


			returnValue1 = *it_dummy;
			returnValue2 = *it;

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<short>(returnValue1);
			check__PrintValue_to_File(returnValue1,fpTest);

			std::cout << "result2 ---> \n";
			fprintf(fpTest, "result2 = \n");

			check__PrintValue_to_console<short>(returnValue2);
			check__PrintValue_to_File(returnValue2,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue1, expected_returnValue1);
			bool_val &= check__boCompare(returnValue2, expected_returnValue2);
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Post_Decrement_004\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Post_Decrement_004\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<float32, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<float32, false, cml::CArray<float32, 10> > it;
			cml::CLinMemIt<float32, false, cml::CArray<float32, 10> > it_dummy;
#else
			cml::CLinMemIt<float32, false > it;
			cml::CLinMemIt<float32, false > it_dummy;
#endif
			
			float32 returnValue1;
			float32 returnValue2;
			float32 expected_returnValue1;
			float32 expected_returnValue2;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.end();
			it--;

			/* Set expected values for global data checks */
			expected_returnValue1 = 10;
			expected_returnValue2 = 9;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<float32,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<float32,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<float32>(expected_returnValue1);
			check__PrintValue_to_File(expected_returnValue1,fpTest);

			std::cout << "expected_result2 = \n";	
			fprintf(fpTest, "expected_result2 = \n");

			check__PrintValue_to_console<float32>(expected_returnValue2);
			check__PrintValue_to_File(expected_returnValue2,fpTest);
			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it_dummy = it--;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


			returnValue1 = *it_dummy;
			returnValue2 = *it;

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<float32>(returnValue1);
			check__PrintValue_to_File(returnValue1,fpTest);

			std::cout << "result2 ---> \n";
			fprintf(fpTest, "result2 = \n");

			check__PrintValue_to_console<float32>(returnValue2);
			check__PrintValue_to_File(returnValue2,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue1, expected_returnValue1);
			bool_val &= check__boCompare(returnValue2, expected_returnValue2);
			
			if(bool_val)
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

	std::cout << "END ---> test_cml_stl_CLinMemIt_Operator_Post_Decrement\n\n";
	fprintf(fpTest, "END ---> test_cml_stl_CLinMemIt_Operator_Post_Decrement\n\n");
}


void TEST_CLASS_ITERATOR::test_cml_stl_CLinMemIt_Operator_Pre_Decrement(int doIt)
{
	std::cout << "START ---> test_cml_stl_CLinMemIt_Operator_Pre_Decrement\n\n";		
	fprintf(fpTest, "START ---> test_cml_stl_CLinMemIt_Operator_Pre_Decrement\n\n");

	fprintf(fpTest, "Function Name ---> operator--(difference_type) \n\n");

	if (doIt) 
	{
		{
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Pre_Decrement_001\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Pre_Decrement_001\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<char, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<char, false, cml::CArray<char, 10> > it;
#else
			cml::CLinMemIt<char, false > it;
#endif
			
			char returnValue;
			char expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.end();

			/* Set expected values for global data checks */
			expected_returnValue = 10;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<char,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<char,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<char>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = *--it;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<char>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Pre_Decrement_002\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Pre_Decrement_002\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<sint32, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<sint32, false, cml::CArray<sint32, 10> > it;
#else
			cml::CLinMemIt<sint32, false > it;
#endif
			
			sint32 returnValue;
			sint32 expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.end();

			/* Set expected values for global data checks */
			expected_returnValue = 10;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<sint32,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<sint32,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<sint32>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = *--it;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<sint32>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Pre_Decrement_003\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Pre_Decrement_003\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<short, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<short, false, cml::CArray<short, 10> > it;
#else
			cml::CLinMemIt<short, false > it;
#endif
			
			short returnValue;
			short expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.end();

			/* Set expected values for global data checks */
			expected_returnValue = 10;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<short,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<short,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<short>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = *--it;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<short>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Pre_Decrement_004\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Pre_Decrement_004\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<float32, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<float32, false, cml::CArray<float32, 10> > it;
#else
			cml::CLinMemIt<float32, false > it;
#endif
			
			float32 returnValue;
			float32 expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.end();

			/* Set expected values for global data checks */
			expected_returnValue = 10;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<float32,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<float32,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<float32>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = *--it;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<float32>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			
			if(bool_val)
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

	std::cout << "END ---> test_cml_stl_CLinMemIt_Operator_Pre_Decrement\n\n";
	fprintf(fpTest, "END ---> test_cml_stl_CLinMemIt_Operator_Pre_Decrement\n\n");
}


void TEST_CLASS_ITERATOR::test_cml_stl_CLinMemIt_Operator_Addition_Assignment(int doIt)
{
	std::cout << "START ---> test_cml_stl_CLinMemIt_Operator_Addition_Assignment\n\n";		
	fprintf(fpTest, "START ---> test_cml_stl_CLinMemIt_Operator_Addition_Assignment\n\n");

	fprintf(fpTest, "Function Name ---> operator+=(const) \n\n");

	if (doIt) 
	{
		{
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Addition_Assignment_001\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Addition_Assignment_001\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<char, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<char, false, cml::CArray<char, 10> > it;
#else
			cml::CLinMemIt<char, false > it;
#endif
			
			char returnValue;
			char expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.begin();

			/* Set expected values for global data checks */
			expected_returnValue = 3;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<char,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<char,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<char>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it += 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			returnValue = *it;

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<char>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Addition_Assignment_002\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Addition_Assignment_002\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<sint32, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<sint32, false, cml::CArray<sint32, 10> > it;
#else
			cml::CLinMemIt<sint32, false > it;
#endif
			
			sint32 returnValue;
			sint32 expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.begin();

			/* Set expected values for global data checks */
			expected_returnValue = 3;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<sint32,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<sint32,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<sint32>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it += 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			returnValue = *it;
			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<sint32>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Addition_Assignment_003\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Addition_Assignment_003\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<short, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<short, false, cml::CArray<short, 10> > it;
#else
			cml::CLinMemIt<short, false > it;
#endif
			
			short returnValue;
			short expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.begin();

			/* Set expected values for global data checks */
			expected_returnValue = 3;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<short,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<short,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<short>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it += 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


			returnValue = *it;
			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<short>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Addition_Assignment_004\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Addition_Assignment_004\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<float32, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<float32, false, cml::CArray<float32, 10> > it;
#else
			cml::CLinMemIt<float32, false > it;
#endif
			
			float32 returnValue;
			float32 expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.begin();

			/* Set expected values for global data checks */
			expected_returnValue = 3;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<float32,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<float32,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<float32>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it += 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


			returnValue = *it;
			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<float32>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			
			if(bool_val)
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

	std::cout << "END ---> test_cml_stl_CLinMemIt_Operator_Addition_Assignment\n\n";
	fprintf(fpTest, "END ---> test_cml_stl_CLinMemIt_Operator_Addition_Assignment\n\n");
}

void TEST_CLASS_ITERATOR::test_cml_stl_CLinMemIt_Operator_Subtraction_Assignment(int doIt)
{
	std::cout << "START ---> test_cml_stl_CLinMemIt_Operator_Subtraction_Assignment\n\n";		
	fprintf(fpTest, "START ---> test_cml_stl_CLinMemIt_Operator_Subtraction_Assignment\n\n");

	fprintf(fpTest, "Function Name ---> operator-=(const) \n\n");

	if (doIt) 
	{
		{
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_Assignment_001\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_Assignment_001\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<char, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<char, false, cml::CArray<char, 10> > it;
#else
			cml::CLinMemIt<char, false > it;
#endif
			
			char returnValue;
			char expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.end();

			/* Set expected values for global data checks */
			expected_returnValue = 9;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<char,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<char,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<char>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it -= 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<char>(*it);
			check__PrintValue_to_File(*it,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(*it, expected_returnValue);
			
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_Assignment_002\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_Assignment_002\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<sint32, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<sint32, false, cml::CArray<sint32, 10> > it;
#else
			cml::CLinMemIt<sint32, false > it;
#endif
			
			sint32 returnValue;
			sint32 expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.end();

			/* Set expected values for global data checks */
			expected_returnValue = 9;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<sint32,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<sint32,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<sint32>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it -= 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<sint32>(*it);
			check__PrintValue_to_File(*it,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(*it, expected_returnValue);
			
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_Assignment_003\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_Assignment_003\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<short, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<short, false, cml::CArray<short, 10> > it;
#else
			cml::CLinMemIt<short, false > it;
#endif
			
			short returnValue;
			short expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.end();

			/* Set expected values for global data checks */
			expected_returnValue = 9;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<short,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<short,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<short>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it -= 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<short>(*it);
			check__PrintValue_to_File(*it,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(*it, expected_returnValue);
			
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_Assignment_004\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_Assignment_004\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<float32, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<float32, false, cml::CArray<float32, 10> > it;
#else
			cml::CLinMemIt<float32, false > it;
#endif
			
			float32 returnValue;
			float32 expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.end();

			/* Set expected values for global data checks */
			expected_returnValue = 9;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<float32,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<float32,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<float32>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it -= 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<float32>(*it);
			check__PrintValue_to_File(*it,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(*it, expected_returnValue);
			
			
			if(bool_val)
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

	std::cout << "END ---> test_cml_stl_CLinMemIt_Operator_Subtraction_Assignment\n\n";
	fprintf(fpTest, "END ---> test_cml_stl_CLinMemIt_Operator_Subtraction_Assignment\n\n");
}

void TEST_CLASS_ITERATOR::test_cml_stl_CLinMemIt_Operator_Addition(int doIt)
{
	std::cout << "START ---> test_cml_stl_CLinMemIt_Operator_Addition\n\n";		
	fprintf(fpTest, "START ---> test_cml_stl_CLinMemIt_Operator_Addition\n\n");

	fprintf(fpTest, "Function Name ---> operator+(const)const \n\n");

	if (doIt) 
	{
		{
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Addition_001\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Addition_001\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<char, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<char, false, cml::CArray<char, 10> > it;
#else
			cml::CLinMemIt<char, false > it;
#endif
			
			char returnValue;
			char expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.begin();

			/* Set expected values for global data checks */
			expected_returnValue = 3;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<char,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<char,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<char>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it = it + 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			returnValue = *it;

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<char>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Addition_002\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Addition_002\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<sint32, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<sint32, false, cml::CArray<sint32, 10> > it;
#else
			cml::CLinMemIt<sint32, false > it;
#endif
			
			sint32 returnValue;
			sint32 expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.begin();

			/* Set expected values for global data checks */
			expected_returnValue = 3;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<sint32,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<sint32,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<sint32>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it = it + 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


			returnValue = *it;
			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<sint32>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Addition_003\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Addition_003\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<short, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<short, false, cml::CArray<short, 10> > it;
#else
			cml::CLinMemIt<short, false > it;
#endif
			
			short returnValue;
			short expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.begin();

			/* Set expected values for global data checks */
			expected_returnValue = 3;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<short,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<short,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<short>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it = it + 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


			returnValue = *it;
			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<short>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Addition_004\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Addition_004\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<float32, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<float32, false, cml::CArray<float32, 10> > it;
#else
			cml::CLinMemIt<float32, false > it;
#endif
			
			float32 returnValue;
			float32 expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.begin();

			/* Set expected values for global data checks */
			expected_returnValue = 3;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<float32,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<float32,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<float32>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it = it + 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


			returnValue = *it;
			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<float32>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			
			if(bool_val)
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

	std::cout << "END ---> test_cml_stl_CLinMemIt_Operator_Addition\n\n";
	fprintf(fpTest, "END ---> test_cml_stl_CLinMemIt_Operator_Addition\n\n");
}

void TEST_CLASS_ITERATOR::test_cml_stl_CLinMemIt_Operator_Subtraction(int doIt)
{
	std::cout << "START ---> test_cml_stl_CLinMemIt_Operator_Subtraction\n\n";		
	fprintf(fpTest, "START ---> test_cml_stl_CLinMemIt_Operator_Subtraction\n\n");

	fprintf(fpTest, "Function Name ---> operator-(const) \n\n");

	if (doIt) 
	{
		{
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_001\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_001\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<char, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<char, false, cml::CArray<char, 10> > it;
#else
			cml::CLinMemIt<char, false > it;
#endif
			
			char returnValue;
			char expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.end();

			/* Set expected values for global data checks */
			expected_returnValue = 9;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<char,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<char,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<char>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it = it - 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<char>(*it);
			check__PrintValue_to_File(*it,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(*it, expected_returnValue);
			
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_002\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_002\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<sint32, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<sint32, false, cml::CArray<sint32, 10> > it;
#else
			cml::CLinMemIt<sint32, false > it;
#endif
			
			sint32 returnValue;
			sint32 expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.end();

			/* Set expected values for global data checks */
			expected_returnValue = 9;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<sint32,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<sint32,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<sint32>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it = it - 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<sint32>(*it);
			check__PrintValue_to_File(*it,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(*it, expected_returnValue);
			
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_003\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_003\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<short, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<short, false, cml::CArray<short, 10> > it;
#else
			cml::CLinMemIt<short, false > it;
#endif
			
			short returnValue;
			short expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.end();

			/* Set expected values for global data checks */
			expected_returnValue = 9;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<short,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<short,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<short>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it = it - 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<short>(*it);
			check__PrintValue_to_File(*it,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(*it, expected_returnValue);
			
			
			if(bool_val)
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
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_004\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_004\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<float32, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<float32, false, cml::CArray<float32, 10> > it;
#else
			cml::CLinMemIt<float32, false > it;
#endif
			
			float32 returnValue;
			float32 expected_returnValue;

			/* Set global data */
			initialise_global_data();
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 10;
			it = Array.end();

			/* Set expected values for global data checks */
			expected_returnValue = 9;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__vArrayPrintSegment_to_console<float32,10,false>(Array,0,10);
			check__vArraySegmentPrint_to_File<float32,10,false>(Array, fpTest, 0, 10);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<float32>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			it = it - 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<float32>(*it);
			check__PrintValue_to_File(*it,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(*it, expected_returnValue);
			
			
			if(bool_val)
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

	std::cout << "END ---> test_cml_stl_CLinMemIt_Operator_Subtraction\n\n";
	fprintf(fpTest, "END ---> test_cml_stl_CLinMemIt_Operator_Subtraction\n\n");
}

void TEST_CLASS_ITERATOR::test_cml_stl_CLinMemIt_Operator_Subtraction_01(int doIt)
{
	std::cout << "START ---> test_cml_stl_CLinMemIt_Operator_Subtraction_01\n\n";		
	fprintf(fpTest, "START ---> test_cml_stl_CLinMemIt_Operator_Subtraction_01\n\n");

	fprintf(fpTest, "Function Name ---> operator-(const)const \n\n");

	if (doIt) 
	{
		{
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_01_001\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_01_001\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<char, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<char, false, cml::CArray<char, 10> > it1;
			cml::CLinMemIt<char, false, cml::CArray<char, 10> > it2;
#else
			cml::CLinMemIt<char, false > it1;
			cml::CLinMemIt<char, false > it2;
#endif
			
			int returnValue;
			int expected_returnValue;

			/* Set global data */
			initialise_global_data();
			it1 = Array.begin();
			it2 = Array.begin() + 5;

			/* Set expected values for global data checks */
			expected_returnValue = 5;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__PrintValue_to_console<char *>(&Array[0]);
			check__PrintValue_to_File(&Array[0],fpTest);

			std::cout << "\ninput2 = \n";	
			fprintf(fpTest, "\ninput2 = \n");

			check__PrintValue_to_console<char *>(&Array[4]);
			check__PrintValue_to_File(&Array[4],fpTest);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<int>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = it2 - it1;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<int>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			
			if(bool_val)
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
			fprintf(fpTest, "Remarks ---> Address value differs on different platforms\n\n");
			std::cout << "Remarks ---> Address value differs on different platforms\n\n";
						  
		}

		{
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_01_002\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_01_002\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<sint32, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<sint32, false, cml::CArray<sint32, 10> > it1;
			cml::CLinMemIt<sint32, false, cml::CArray<sint32, 10> > it2;
#else
			cml::CLinMemIt<sint32, false > it1;
			cml::CLinMemIt<sint32, false > it2;
#endif
			
			int returnValue;
			int expected_returnValue;

			/* Set global data */
			initialise_global_data();
			it1 = Array.begin();
			it2 = Array.begin() + 5;

			/* Set expected values for global data checks */
			expected_returnValue = 5;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__PrintValue_to_console<sint32 *>(&Array[0]);
			check__PrintValue_to_File(&Array[0],fpTest);

			std::cout << "\ninput2 = \n";	
			fprintf(fpTest, "\ninput2 = \n");

			check__PrintValue_to_console<sint32 *>(&Array[4]);
			check__PrintValue_to_File(&Array[4],fpTest);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<int>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = it2 - it1;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<int>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			
			if(bool_val)
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
			fprintf(fpTest, "Remarks ---> Address value differs on different platforms\n\n");
			std::cout << "Remarks ---> Address value differs on different platforms\n\n";
						  
		}

		{
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_01_003\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_01_003\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<short, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<short, false, cml::CArray<short, 10> > it1;
			cml::CLinMemIt<short, false, cml::CArray<short, 10> > it2;
#else
			cml::CLinMemIt<short, false > it1;
			cml::CLinMemIt<short, false > it2;
#endif
			
			int returnValue;
			int expected_returnValue;

			/* Set global data */
			initialise_global_data();
			it1 = Array.begin();
			it2 = Array.begin() + 5;

			/* Set expected values for global data checks */
			expected_returnValue = 5;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__PrintValue_to_console<short *>(&Array[0]);
			check__PrintValue_to_File(&Array[0],fpTest);

			std::cout << "\ninput2 = \n";	
			fprintf(fpTest, "\ninput2 = \n");

			check__PrintValue_to_console<short *>(&Array[4]);
			check__PrintValue_to_File(&Array[4],fpTest);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<int>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = it2 - it1;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<int>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			
			if(bool_val)
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
			fprintf(fpTest, "Remarks ---> Address value differs on different platforms\n\n");
			std::cout << "Remarks ---> Address value differs on different platforms\n\n";
						  
		}

		{
			std::cout << "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_01_001\n\n";		
			fprintf(fpTest, "Test Case ---> test_cml_stl_CLinMemIt_Operator_Subtraction_01_001\n\n");

			std::cout << "Data Dimension ---> 10 \n\n";		
			fprintf(fpTest, "Data Dimension ---> 10 \n\n");

        	/* Test case data declarations */
			cml::CArray<float32, 10> Array;

#ifndef NDEBUG
        	cml::CLinMemIt<float32, false, cml::CArray<float32, 10> > it1;
			cml::CLinMemIt<float32, false, cml::CArray<float32, 10> > it2;
#else
			cml::CLinMemIt<float32, false > it1;
			cml::CLinMemIt<float32, false > it2;
#endif
			
			int returnValue;
			int expected_returnValue;

			/* Set global data */
			initialise_global_data();
			it1 = Array.begin();
			it2 = Array.begin() + 5;

			/* Set expected values for global data checks */
			expected_returnValue = 5;

			/* Input*/
			std::cout << "Input ---> \n";	
			fprintf(fpTest, "Input ---> \n");
		
			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");
			
			check__PrintValue_to_console<float32 *>(&Array[0]);
			check__PrintValue_to_File(&Array[0],fpTest);

			std::cout << "\ninput2 = \n";	
			fprintf(fpTest, "\ninput2 = \n");

			check__PrintValue_to_console<float32 *>(&Array[4]);
			check__PrintValue_to_File(&Array[4],fpTest);
			fprintf(fpTest, "\n\n");

			/* Expected Result*/
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
		
			std::cout << "expected_result1 = \n";	
			fprintf(fpTest, "expected_result1 = \n");

			check__PrintValue_to_console<int>(expected_returnValue);
			check__PrintValue_to_File(expected_returnValue,fpTest);

			fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			returnValue = it2 - it1;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "result1 ---> \n";
			fprintf(fpTest, "result1 = \n");

			check__PrintValue_to_console<int>(returnValue);
			check__PrintValue_to_File(returnValue,fpTest);
			fprintf(fpTest, "\n\n");
		
			/* Test checks */

			bool bool_val = check__boCompare(returnValue, expected_returnValue);
			
			
			if(bool_val)
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
			fprintf(fpTest, "Remarks ---> Address value differs on different platforms\n\n");
			std::cout << "Remarks ---> Address value differs on different platforms\n\n";
						  
		}
	}

	std::cout << "END ---> test_cml_stl_CLinMemIt_Operator_Subtraction_01\n\n";
	fprintf(fpTest, "END ---> test_cml_stl_CLinMemIt_Operator_Subtraction_01\n\n");
}

/*****************************************************************************/
/* Call Interface Control                                                    */
/*****************************************************************************/
#pragma qas cantata ignore on

#pragma qas cantata ignore off
/* pragma qas cantata testscript end */
/*****************************************************************************/
/* End of test script                                                        */
/*****************************************************************************/
