/*****************************************************************************/
/*                            Cantata Test Script                            */
/*****************************************************************************/
/*
*    Filename: test_cml_stl_list.cpp
*    Author: uidr1064
*    Generated on: 16-Feb-2016 10:47:30
*    Generated from: cml_stl_list.cpp
*/
/*****************************************************************************/
/* Environment Definition                                                    */
/*****************************************************************************/
#define NDEBUG

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

void test_cml_stl_list(void);


struct TEST_tstTestStuct
{
    float32 fData;
};

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

/* pragma qas cantata testscript start */

/* Global Functions */
/* None */

/* Global data */

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
	std::cout << "\nStatus ---> PASS\n\n"; 
	fprintf(fpTest, "\nStatus ---> PASS\n\n");
}

/*****************************************************************************/
/* Test class declaration                                                    */
/*****************************************************************************/
class TEST_CLASS_LIST
{
public:
	void run_tests_list();

	void test_cml_CList_constructor(int);
	void test_cml_CList_clear(int);
	void test_cml_CList_size(int);
	void test_cml_CList_empty(int);
	void test_cml_CList_full(int);
	void test_cml_CList_front_1(int);
	void test_cml_CList_front_2(int);
	void test_cml_CList_back_1(int);
	void test_cml_CList_back_2(int);
	void test_cml_CList_push_front_1(int);
	void test_cml_CList_push_front_2(int);
	void test_cml_CList_push_back_1(int);
	void test_cml_CList_push_back_2(int);
	void test_cml_CList_pop_front(int);
	void test_cml_CList_pop_back(int);
	void test_cml_CList_insert_1(int);
	void test_cml_CList_insert_2(int);
	void test_cml_CList_erase_1(int);
	void test_cml_CList_erase_2(int);
	void test_cml_CList_begin(int);
	void test_cml_CList_end(int);
	void test_cml_CBidirectionalIt_constructor(int);
	void test_cml_CBidirectionalIt_constructor_CBidirectionalIt(int);
	void test_cml_CBidirectionalIt_constructor_CBaseIt(int);
	void test_cml_CBidirectionalIt_operator_indirection(int);
	void test_cml_CBidirectionalIt_operator_arrow(int);
	void test_cml_CBidirectionalIt_operator_plusplus_1(int);
	void test_cml_CBidirectionalIt_operator_plusplus_2(int);
	void test_cml_CBidirectionalIt_operator_minusminus_1(int);
	void test_cml_CBidirectionalIt_operator_minusminus_2(int);
	void test_cml_CBidirectionalIt_operator_equalequal(int);
	void test_cml_CBidirectionalIt_operator_notequal(int);
};


/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_stl_list(void)
{
	TEST_CLASS_LIST test_object;

	std::cout << "******** Start Testing: List Library functions ********\n\n";
	fprintf(fpTest, "******** Start Testing: List Library functions ********\n\n");

	test_object.run_tests_list();

	std::cout << "End of Testing: List Library functions\n\n";
	fprintf(fpTest, "End of Testing: List Library functions\n\n");

	return;
}
/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS_LIST::run_tests_list()
{
	//test_cml_CList_constructor(1);
	test_cml_CList_clear(1);
	//test_cml_CList_size(1);
	test_cml_CList_empty(1);
	test_cml_CList_full(1);
	test_cml_CList_front_1(1);
	test_cml_CList_front_2(1);
	test_cml_CList_back_1(1);
	test_cml_CList_back_2(1);
	test_cml_CList_push_front_1(1);
	//test_cml_CList_push_front_2(1);
	test_cml_CList_push_back_1(1);
	//test_cml_CList_push_back_2(1);
	test_cml_CList_pop_front(1);
	test_cml_CList_pop_back(1);
	test_cml_CList_insert_1(1);
	//test_cml_CList_insert_2(1);
	test_cml_CList_erase_1(1);
	//test_cml_CList_erase_2(1);
	test_cml_CList_begin(1);
	test_cml_CList_end(1);
	/*test_cml_CBidirectionalIt_constructor(1);
	test_cml_CBidirectionalIt_constructor_CBidirectionalIt(1);
	test_cml_CBidirectionalIt_constructor_CBaseIt(1);*/
	test_cml_CBidirectionalIt_operator_indirection(1);
	test_cml_CBidirectionalIt_operator_arrow(1);
	test_cml_CBidirectionalIt_operator_plusplus_1(1);
	test_cml_CBidirectionalIt_operator_plusplus_2(1);
	test_cml_CBidirectionalIt_operator_minusminus_1(1);
	test_cml_CBidirectionalIt_operator_minusminus_2(1);
	test_cml_CBidirectionalIt_operator_equalequal(1);
	test_cml_CBidirectionalIt_operator_notequal(1);
}

/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/

#if 0
void TEST_CLASS_LIST::test_cml_CList_constructor(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CList<float32, 10>_constructor",
			"Description: \
			- cml_stl_list.h : CList::CList() \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CList object is generated with the right size and data "
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CList<float32 ,10> TestList;
		cml::CList<sint32 ,10> TestList1;

		/* Test case checks */
		CHECK_U_INT( TestList1.size(), 0 );

		CHECK_NAMED( "Empty", TestList1.empty(), true );

		CHECK_NAMED( "not Full", TestList1.full(), false );

		CHECK_NAMED( "begin() == end()", TestList1.begin() == TestList1.end(), true );

		CHECK_U_INT( TestList.size(), 0 );

		CHECK_NAMED( "Empty", TestList.empty(), true );

		CHECK_NAMED( "not Full", TestList.full(), false );

		CHECK_NAMED( "begin() == end()", TestList.begin() == TestList.end(), true );


		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_002_cml_CList<sint32, 10>_constructor",
			"Description: \
			- cml_stl_list.h : CList::CList() \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CList object is generated with the right size and data "
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CList<sint32 ,10> TestList;
		cml::CList<sint32 ,10> TestList1;

		/* Test case checks */
		CHECK_U_INT( TestList1.size(), 0 );

		CHECK_NAMED( "Empty", TestList1.empty(), true );

		CHECK_NAMED( "not Full", TestList1.full(), false );

		CHECK_NAMED( "begin() == end()", TestList1.begin() == TestList1.end(), true );

		CHECK_U_INT( TestList.size(), 0 );

		CHECK_NAMED( "Empty", TestList.empty(), true );

		CHECK_NAMED( "not Full", TestList.full(), false );

		CHECK_NAMED( "begin() == end()", TestList.begin() == TestList.end(), true );


		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_003_cml_CList<char, 10>_constructor",
			"Description: \
			- cml_stl_list.h : CList::CList() \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CList object is generated with the right size and data "
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CList<char ,10> TestList;
		cml::CList<char ,10> TestList1;

		/* Test case checks */
		CHECK_U_INT( TestList1.size(), 0 );

		CHECK_NAMED( "Empty", TestList1.empty(), true );

		CHECK_NAMED( "not Full", TestList1.full(), false );

		CHECK_NAMED( "begin() == end()", TestList1.begin() == TestList1.end(), true );

		CHECK_U_INT( TestList.size(), 0 );

		CHECK_NAMED( "Empty", TestList.empty(), true );

		CHECK_NAMED( "not Full", TestList.full(), false );

		CHECK_NAMED( "begin() == end()", TestList.begin() == TestList.end(), true );


		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}
#endif

void  TEST_CLASS_LIST::test_cml_CList_clear(int doIt)
{
	std::cout << "START ---> test_cml_CList_clear\n\n";		
	fprintf(fpTest, "START ---> test_cml_CList_clear\n\n");

	fprintf(fpTest, "Function Name ---> CList::clear() \n\n");
	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CList_clear_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_clear_001\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		int size,expected_size;
		cml::CList<float32 ,5> TestList;

		TestList.push_back( 0 );
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		
		size = TestList.size();
		expected_size = 0;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_size);
		check__PrintValue_to_File( expected_size, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.clear();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		size = TestList.size();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(size,expected_size);

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
		std::cout << "Test Case ---> test_cml_CList_clear_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_clear_002\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		int size,expected_size;
		cml::CList<sint32 ,5> TestList;

		TestList.push_back( 0 );
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		
		size = TestList.size();
		expected_size = 0;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_size);
		check__PrintValue_to_File( expected_size, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.clear();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		size = TestList.size();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(size,expected_size);

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
		std::cout << "Test Case ---> test_cml_CList_clear_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_clear_003\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		int size,expected_size;
		cml::CList<char ,5> TestList;

		TestList.push_back( 0 );
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		
		size = TestList.size();
		expected_size = 0;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_size);
		check__PrintValue_to_File( expected_size, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.clear();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		size = TestList.size();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(size,expected_size);

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
		std::cout << "Test Case ---> test_cml_CList_clear_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_clear_004\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		int size,expected_size;
		cml::CList<short ,5> TestList;

		TestList.push_back( 0 );
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		
		size = TestList.size();
		expected_size = 0;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_size);
		check__PrintValue_to_File( expected_size, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.clear();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		size = TestList.size();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(size,expected_size);

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
	std::cout << "END ---> test_cml_CList_clear\n\n";
	fprintf(fpTest, "END ---> test_cml_CList_clear\n\n");
}

#if 0
void  TEST_CLASS_LIST::test_cml_CList_size(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CList<float32, 10>_size()",
			"Description: \
			- cml_stl_list.h : CList::size() \
			- Testing: interface \
			- Overview: verify that size works properly \
			- Entry conditions: - \
			- Expected results: the right size is returned"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<float32 ,10> TestList;

		/* Call SUT */
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 0 );

		TestList.push_back( 0 );

		/* Call SUT */
		/* Test case checks */
		CHECK_U_INT(  TestList.size(), 1 );

		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
		TestList.push_back( 6 );
		TestList.push_back( 7 );
		TestList.push_back( 8 );
		TestList.push_back( 9 );

		/* Call SUT */
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 10 );

		TestList.pop_back();

		/* Call SUT */
		/* Test case checks */
		CHECK_U_INT( TestList.size(),  9 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_002_cml_CList<sint32, 10>_size()",
			"Description: \
			- cml_stl_list.h : CList::size() \
			- Testing: interface \
			- Overview: verify that size works properly \
			- Entry conditions: - \
			- Expected results: the right size is returned"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<sint32 ,10> TestList;

		/* Call SUT */
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 0 );

		TestList.push_back( 0 );

		/* Call SUT */
		/* Test case checks */
		CHECK_U_INT(  TestList.size(), 1 );

		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
		TestList.push_back( 6 );
		TestList.push_back( 7 );
		TestList.push_back( 8 );
		TestList.push_back( 9 );

		/* Call SUT */
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 10 );

		TestList.pop_back();

		/* Call SUT */
		/* Test case checks */
		CHECK_U_INT( TestList.size(),  9 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_003_cml_CList<char, 10>_size()",
			"Description: \
			- cml_stl_list.h : CList::size() \
			- Testing: interface \
			- Overview: verify that size works properly \
			- Entry conditions: - \
			- Expected results: the right size is returned"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<char ,10> TestList;

		/* Call SUT */
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 0 );

		TestList.push_back( 0 );

		/* Call SUT */
		/* Test case checks */
		CHECK_U_INT(  TestList.size(), 1 );

		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
		TestList.push_back( 6 );
		TestList.push_back( 7 );
		TestList.push_back( 8 );
		TestList.push_back( 9 );

		/* Call SUT */
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 10 );

		TestList.pop_back();

		/* Call SUT */
		/* Test case checks */
		CHECK_U_INT( TestList.size(),  9 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}
#endif

void  TEST_CLASS_LIST::test_cml_CList_empty(int doIt)
{
	std::cout << "START ---> test_cml_CList_empty\n\n";		
	fprintf(fpTest, "START ---> test_cml_CList_empty\n\n");

	fprintf(fpTest, "Function Name ---> CList::empty() \n\n");
	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CList_empty_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_empty_001\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::boolean_t size,expected_size;
		cml::CList<float32 ,10> TestList;

		size = TestList.empty();
		expected_size = false;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_size);
		check__PrintValue_to_File( expected_size, fpTest);
		fprintf(fpTest, "\n\n");

		TestList.push_back( 0 );

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		size = TestList.empty();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(size,expected_size);

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
		std::cout << "Test Case ---> test_cml_CList_empty_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_empty_002\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::boolean_t size,expected_size;
		cml::CList<sint32 ,10> TestList;

		size = TestList.empty();
		expected_size = false;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_size);
		check__PrintValue_to_File( expected_size, fpTest);
		fprintf(fpTest, "\n\n");

		TestList.push_back( 0 );

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		size = TestList.empty();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(size,expected_size);

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
		std::cout << "Test Case ---> test_cml_CList_empty_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_empty_003\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::boolean_t size,expected_size;
		cml::CList<char ,10> TestList;

		size = TestList.empty();
		expected_size = false;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_size);
		check__PrintValue_to_File( expected_size, fpTest);
		fprintf(fpTest, "\n\n");

		TestList.push_back( 0 );

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		size = TestList.empty();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(size,expected_size);

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
	std::cout << "END ---> test_cml_CList_empty\n\n";
	fprintf(fpTest, "END ---> test_cml_CList_empty\n\n");
}

void  TEST_CLASS_LIST::test_cml_CList_full(int doIt)
{
	std::cout << "START ---> test_cml_CList_full\n\n";		
	fprintf(fpTest, "START ---> test_cml_CList_full\n\n");

	fprintf(fpTest, "Function Name ---> CList::full() \n\n");
	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CList_full_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_full_001\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::boolean_t size,expected_size;
		cml::CList<float32 ,10> TestList;

		size = TestList.full();
		expected_size = true;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_size);
		check__PrintValue_to_File( expected_size, fpTest);
		fprintf(fpTest, "\n\n");

		TestList.push_back( 0 );
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
		TestList.push_back( 6 );
		TestList.push_back( 7 );
		TestList.push_back( 8 );
		TestList.push_back( 9 );

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		size = TestList.full();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(size,expected_size);

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
		std::cout << "Test Case ---> test_cml_CList_full_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_full_002\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::boolean_t size,expected_size;
		cml::CList<sint32 ,10> TestList;

		size = TestList.full();
		expected_size = true;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_size);
		check__PrintValue_to_File( expected_size, fpTest);
		fprintf(fpTest, "\n\n");

		TestList.push_back( 0 );
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
		TestList.push_back( 6 );
		TestList.push_back( 7 );
		TestList.push_back( 8 );
		TestList.push_back( 9 );

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		size = TestList.full();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(size,expected_size);

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
		std::cout << "Test Case ---> test_cml_CList_full_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_full_003\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::boolean_t size,expected_size;
		cml::CList<char ,10> TestList;

		size = TestList.full();
		expected_size = true;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_size);
		check__PrintValue_to_File( expected_size, fpTest);
		fprintf(fpTest, "\n\n");

		TestList.push_back( 0 );
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
		TestList.push_back( 6 );
		TestList.push_back( 7 );
		TestList.push_back( 8 );
		TestList.push_back( 9 );

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		size = TestList.full();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(size,expected_size);

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
	std::cout << "END ---> test_cml_CList_full\n\n";
	fprintf(fpTest, "END ---> test_cml_CList_full\n\n");
}

void  TEST_CLASS_LIST::test_cml_CList_front_1(int doIt)
{
	std::cout << "START ---> test_cml_CList_front_1\n\n";		
	fprintf(fpTest, "START ---> test_cml_CList_front_1\n\n");

	fprintf(fpTest, "Function Name ---> CList::front() \n\n");
	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CList_front_1_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_front_1_001\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		float32 val,expected_val;
		cml::CList<float32 ,10> TestList;
		val = 0;
		TestList.push_back( 1 );
		
		expected_val = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = TestList.front();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_front_1_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_front_1_002\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		sint32 val,expected_val;
		cml::CList<sint32 ,10> TestList;
		val = 0;
		TestList.push_back( 1 );
		
		expected_val = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = TestList.front();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_front_1_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_front_1_003\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		char val,expected_val;
		cml::CList<char ,10> TestList;
		val = 0;
		TestList.push_back( 1 );
		
		expected_val = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = TestList.front();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_front_1_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_front_1_004\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		short val,expected_val;
		cml::CList<short ,10> TestList;
		val = 0;
		TestList.push_back( 1 );
		
		expected_val = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = TestList.front();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
	std::cout << "END ---> test_cml_CList_front_1\n\n";
	fprintf(fpTest, "END ---> test_cml_CList_front_1\n\n");
}

void  TEST_CLASS_LIST::test_cml_CList_front_2(int doIt)
{
	std::cout << "START ---> test_cml_CList_front_2\n\n";		
	fprintf(fpTest, "START ---> test_cml_CList_front_2\n\n");

	fprintf(fpTest, "Function Name ---> CList::front()const \n\n");
	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CList_front_2_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_front_2_001\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<float32 ,10> TestList_dummy;
		TestList_dummy.push_back( 1 );
		float32 val,expected_val;
		const cml::CList<float32 ,10> TestList(TestList_dummy);
		val = 0;		
		
		expected_val = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = TestList.front();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_front_2_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_front_2_002\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		sint32 val,expected_val;
		cml::CList<sint32 ,10> TestList_dummy;
		TestList_dummy.push_back( 1 );
		const cml::CList<sint32 ,10> TestList(TestList_dummy);
		val = 0;

		expected_val = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = TestList.front();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_front_2_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_front_2_003\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		char val,expected_val;
		cml::CList<char ,10> TestList_dummy;
		TestList_dummy.push_back( 1 );
		const cml::CList<char ,10> TestList(TestList_dummy);
		val = 0;
				
		expected_val = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = TestList.front();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_front_2_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_front_2_004\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<short ,10> TestList_dummy;
		TestList_dummy.push_back( 1 );
		short val,expected_val;
		const cml::CList<short ,10> TestList(TestList_dummy);
		val = 0;

		expected_val = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = TestList.front();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
	std::cout << "END ---> test_cml_CList_front_2\n\n";
	fprintf(fpTest, "END ---> test_cml_CList_front_2\n\n");
}

void  TEST_CLASS_LIST::test_cml_CList_back_1(int doIt)
{
	std::cout << "START ---> test_cml_CList_back_1\n\n";		
	fprintf(fpTest, "START ---> test_cml_CList_back_1\n\n");

	fprintf(fpTest, "Function Name ---> CList::back() \n\n");
	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CList_back_1_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_back_1_001\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		float32 val,expected_val;
		cml::CList<float32 ,10> TestList;
		val = 0;
		TestList.push_back( 1 );
		
		expected_val = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = TestList.back();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_back_1_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_back_1_002\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		sint32 val,expected_val;
		cml::CList<sint32 ,10> TestList;
		val = 0;
		TestList.push_back( 1 );
		
		expected_val = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = TestList.back();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_back_1_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_back_1_003\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		char val,expected_val;
		cml::CList<char ,10> TestList;
		val = 0;
		TestList.push_back( 1 );
		
		expected_val = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = TestList.back();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_back_1_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_back_1_004\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		short val,expected_val;
		cml::CList<short ,10> TestList;
		val = 0;
		TestList.push_back( 1 );
		
		expected_val = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = TestList.back();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
	std::cout << "END ---> test_cml_CList_back_1\n\n";
	fprintf(fpTest, "END ---> test_cml_CList_back_1\n\n");
}

void  TEST_CLASS_LIST::test_cml_CList_back_2(int doIt)
{
	std::cout << "START ---> test_cml_CList_back_2\n\n";		
	fprintf(fpTest, "START ---> test_cml_CList_back_2\n\n");

	fprintf(fpTest, "Function Name ---> CList::back()const \n\n");
	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CList_back_2_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_back_2_001\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<float32 ,10> TestList_dummy;
		TestList_dummy.push_back( 1 );
		float32 val,expected_val;
		const cml::CList<float32 ,10> TestList(TestList_dummy);
		val = 0;		
		
		expected_val = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = TestList.back();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_back_2_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_back_2_002\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		sint32 val,expected_val;
		cml::CList<sint32 ,10> TestList_dummy;
		TestList_dummy.push_back( 1 );
		const cml::CList<sint32 ,10> TestList(TestList_dummy);
		val = 0;

		expected_val = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = TestList.back();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_back_2_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_back_2_003\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		char val,expected_val;
		cml::CList<char ,10> TestList_dummy;
		TestList_dummy.push_back( 1 );
		const cml::CList<char ,10> TestList(TestList_dummy);
		val = 0;
				
		expected_val = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = TestList.back();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_back_2_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_back_2_004\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<short ,10> TestList_dummy;
		TestList_dummy.push_back( 1 );
		short val,expected_val;
		const cml::CList<short ,10> TestList(TestList_dummy);
		//TestList.push_back(1);
		val = 0;

		expected_val = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = TestList.back();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
	std::cout << "END ---> test_cml_CList_back_2\n\n";
	fprintf(fpTest, "END ---> test_cml_CList_back_2\n\n");
}

void  TEST_CLASS_LIST::test_cml_CList_push_front_1(int doIt)
{
	std::cout << "START ---> test_cml_CList_push_front_1\n\n";		
	fprintf(fpTest, "START ---> test_cml_CList_push_front_1\n\n");

	fprintf(fpTest, "Function Name ---> CList::push_front() \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CList_push_front_1_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_push_front_1_001\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<float32 ,10> TestList;
		float32 val,expected_val;
		
		val = 0;
		expected_val = 10;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.push_front( 10 );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		val = TestList.front();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_push_front_1_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_push_front_1_002\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<sint32 ,10> TestList;
		sint32 val,expected_val;
		
		val = 0;
		expected_val = 10;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.push_front( 10 );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		val = TestList.front();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_push_front_1_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_push_front_1_003\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<char ,10> TestList;
		char val,expected_val;
		
		val = 0;
		expected_val = 10;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.push_front( 10 );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		val = TestList.front();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
	std::cout << "END ---> test_cml_CList_push_front_1\n\n";
	fprintf(fpTest, "END ---> test_cml_CList_push_front_1\n\n");
}

#if 0
void  TEST_CLASS_LIST::test_cml_CList_push_front_2(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CList<float32, 10>_push_front()",
			"Description: \
			- cml_stl_list.h : CList::push_front() \
			- Testing: interface \
			- Overview: verify that push_front works properly \
			- Entry conditions: - \
			- Expected results: push_front adds new data at the begin of the list."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<float32 ,10> TestList;

		TestList.push_front() = 10;

		CHECK( TestList.front(), 10 );
		CHECK( TestList.back(), 10 );

		TestList.push_front() = 9;

		CHECK( TestList.front(), 9 );
		CHECK( TestList.back(), 10 );

		TestList.push_front() = 8;
		TestList.push_front() = 7;
		TestList.push_front() = 6;
		TestList.push_front() = 5;
		TestList.push_front() = 4;
		TestList.push_front() = 3;
		TestList.push_front() = 2;
		TestList.push_front() = 1;

		CHECK( TestList.front(), 1 );
		CHECK( TestList.back(), 10 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_002_cml_CList<sint32, 10>_push_front()",
			"Description: \
			- cml_stl_list.h : CList::push_front() \
			- Testing: interface \
			- Overview: verify that push_front works properly \
			- Entry conditions: - \
			- Expected results: push_front adds new data at the begin of the list."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<sint32 ,10> TestList;

		TestList.push_front() = 10;

		CHECK_U_INT( TestList.front(), 10 );
		CHECK_U_INT( TestList.back(), 10 );

		TestList.push_front() = 9;

		CHECK_U_INT( TestList.front(), 9 );
		CHECK_U_INT( TestList.back(), 10 );

		TestList.push_front() = 8;
		TestList.push_front() = 7;
		TestList.push_front() = 6;
		TestList.push_front() = 5;
		TestList.push_front() = 4;
		TestList.push_front() = 3;
		TestList.push_front() = 2;
		TestList.push_front() = 1;

		CHECK_U_INT( TestList.front(), 1 );
		CHECK_U_INT( TestList.back(), 10 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_003_cml_CList<char, 10>_push_front()",
			"Description: \
			- cml_stl_list.h : CList::push_front() \
			- Testing: interface \
			- Overview: verify that push_front works properly \
			- Entry conditions: - \
			- Expected results: push_front adds new data at the begin of the list."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<char ,10> TestList;

		TestList.push_front() = 10;

		CHECK_U_INT( TestList.front(), 10 );
		CHECK_U_INT( TestList.back(), 10 );

		TestList.push_front() = 9;

		CHECK_U_INT( TestList.front(), 9 );
		CHECK_U_INT( TestList.back(), 10 );

		TestList.push_front() = 8;
		TestList.push_front() = 7;
		TestList.push_front() = 6;
		TestList.push_front() = 5;
		TestList.push_front() = 4;
		TestList.push_front() = 3;
		TestList.push_front() = 2;
		TestList.push_front() = 1;

		CHECK_U_INT( TestList.front(), 1 );
		CHECK_U_INT( TestList.back(), 10 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_004_cml_CList<short, 10>_push_front()",
					"Description: \
					- cml_stl_list.h : CList::push_front() \
					- Testing: interface \
					- Overview: verify that push_front works properly \
					- Entry conditions: - \
					- Expected results: push_front adds new data at the begin of the list."
					);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<short ,10> TestList;

		TestList.push_front() = 10;

		CHECK_U_INT( TestList.front(), 10 );
		CHECK_U_INT( TestList.back(), 10 );

		TestList.push_front() = 9;

		CHECK_U_INT( TestList.front(), 9 );
		CHECK_U_INT( TestList.back(), 10 );

		TestList.push_front() = 8;
		TestList.push_front() = 7;
		TestList.push_front() = 6;
		TestList.push_front() = 5;
		TestList.push_front() = 4;
		TestList.push_front() = 3;
		TestList.push_front() = 2;
		TestList.push_front() = 1;

		CHECK_U_INT( TestList.front(), 1 );
		CHECK_U_INT( TestList.back(), 10 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}
#endif

void  TEST_CLASS_LIST::test_cml_CList_push_back_1(int doIt)
{
	std::cout << "START ---> test_cml_CList_push_back_1\n\n";		
	fprintf(fpTest, "START ---> test_cml_CList_push_back_1\n\n");

	fprintf(fpTest, "Function Name ---> CList::push_back() \n\n");
	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CList_push_back_1_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_push_back_1_001\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<float32 ,10> TestList;
		float32 val,expected_val;
		
		val = 0;
		expected_val = 10;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.push_back( 10 );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		val = TestList.back();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_push_back_1_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_push_back_1_002\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<sint32 ,10> TestList;
		sint32 val,expected_val;
		
		val = 0;
		expected_val = 10;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.push_back( 10 );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		val = TestList.back();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_push_back_1_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_push_back_1_003\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<char ,10> TestList;
		char val,expected_val;
		
		val = 0;
		expected_val = 10;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.push_back( 10 );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		val = TestList.back();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
	std::cout << "END ---> test_cml_CList_push_back_1\n\n";
	fprintf(fpTest, "END ---> test_cml_CList_push_back_1\n\n");
}

#if 0
void  TEST_CLASS_LIST::test_cml_CList_push_back_1(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CList<float32, 10>_push_back(const_reference x)",
			"Description: \
			- cml_stl_list.h : CList::push_back(const_reference x) \
			- Testing: interface \
			- Overview: verify that push_back works properly \
			- Entry conditions: - \
			- Expected results: push_back adds new data at the begin of the list."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<float32 ,10> TestList;

		TestList.push_back( 1 );

		CHECK( TestList.front(), 1 );
		CHECK( TestList.back(), 1 );

		TestList.push_back( 2 );

		CHECK( TestList.front(), 1 );
		CHECK( TestList.back(), 2 );

		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
		TestList.push_back( 6 );
		TestList.push_back( 7 );
		TestList.push_back( 8 );
		TestList.push_back( 9 );
		TestList.push_back( 10 );

		CHECK( TestList.front(), 1 );
		CHECK( TestList.back(), 10 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_002_cml_CList<sint32, 10>_push_back(const_reference x)",
			"Description: \
			- cml_stl_list.h : CList::push_back(const_reference x) \
			- Testing: interface \
			- Overview: verify that push_back works properly \
			- Entry conditions: - \
			- Expected results: push_back adds new data at the begin of the list."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<sint32 ,10> TestList;

		TestList.push_back( 1 );

		CHECK_U_INT( TestList.front(), 1 );
		CHECK_U_INT( TestList.back(), 1 );

		TestList.push_back( 2 );

		CHECK_U_INT( TestList.front(), 1 );
		CHECK_U_INT( TestList.back(), 2 );

		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
		TestList.push_back( 6 );
		TestList.push_back( 7 );
		TestList.push_back( 8 );
		TestList.push_back( 9 );
		TestList.push_back( 10 );

		CHECK_U_INT( TestList.front(), 1 );
		CHECK_U_INT( TestList.back(), 10 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_002_cml_CList<sint32, 10>_push_back(const_reference x)",
			"Description: \
			- cml_stl_list.h : CList::push_back(const_reference x) \
			- Testing: interface \
			- Overview: verify that push_back works properly \
			- Entry conditions: - \
			- Expected results: push_back adds new data at the begin of the list."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<sint32 ,10> TestList;

		TestList.push_back( 1 );

		CHECK_U_INT( TestList.front(), 1 );
		CHECK_U_INT( TestList.back(), 1 );

		TestList.push_back( 2 );

		CHECK_U_INT( TestList.front(), 1 );
		CHECK_U_INT( TestList.back(), 2 );

		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
		TestList.push_back( 6 );
		TestList.push_back( 7 );
		TestList.push_back( 8 );
		TestList.push_back( 9 );
		TestList.push_back( 10 );

		CHECK_U_INT( TestList.front(), 1 );
		CHECK_U_INT( TestList.back(), 10 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void  TEST_CLASS_LIST::test_cml_CList_push_back_2(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CList<float32, 10>_push_back()",
			"Description: \
			- cml_stl_list.h : CList::push_back() \
			- Testing: interface \
			- Overview: verify that push_back works properly \
			- Entry conditions: - \
			- Expected results: push_back adds new data at the begin of the list."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<float32 ,10> TestList;

		TestList.push_back() = 1;

		CHECK( TestList.front(), 1 );
		CHECK( TestList.back(), 1 );

		TestList.push_back() = 2;

		CHECK( TestList.front(), 1 );
		CHECK( TestList.back(), 2 );

		TestList.push_back() = 3;
		TestList.push_back() = 4;
		TestList.push_back() = 5;
		TestList.push_back() = 6;
		TestList.push_back() = 7;
		TestList.push_back() = 8;
		TestList.push_back() = 9;
		TestList.push_back() = 10;

		CHECK( TestList.front(), 1 );
		CHECK( TestList.back(), 10 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_002_cml_CList<sint32, 10>_push_back()",
			"Description: \
			- cml_stl_list.h : CList::push_back() \
			- Testing: interface \
			- Overview: verify that push_back works properly \
			- Entry conditions: - \
			- Expected results: push_back adds new data at the begin of the list."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<sint32 ,10> TestList;

		TestList.push_back() = 1;

		CHECK_U_INT( TestList.front(), 1 );
		CHECK_U_INT( TestList.back(), 1 );

		TestList.push_back() = 2;

		CHECK_U_INT( TestList.front(), 1 );
		CHECK_U_INT( TestList.back(), 2 );

		TestList.push_back() = 3;
		TestList.push_back() = 4;
		TestList.push_back() = 5;
		TestList.push_back() = 6;
		TestList.push_back() = 7;
		TestList.push_back() = 8;
		TestList.push_back() = 9;
		TestList.push_back() = 10;

		CHECK_U_INT( TestList.front(), 1 );
		CHECK_U_INT( TestList.back(), 10 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_003_cml_CList<char, 10>_push_back()",
			"Description: \
			- cml_stl_list.h : CList::push_back() \
			- Testing: interface \
			- Overview: verify that push_back works properly \
			- Entry conditions: - \
			- Expected results: push_back adds new data at the begin of the list."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<char ,10> TestList;

		TestList.push_back() = 1;

		CHECK_U_INT( TestList.front(), 1 );
		CHECK_U_INT( TestList.back(), 1 );

		TestList.push_back() = 2;

		CHECK_U_INT( TestList.front(), 1 );
		CHECK_U_INT( TestList.back(), 2 );

		TestList.push_back() = 3;
		TestList.push_back() = 4;
		TestList.push_back() = 5;
		TestList.push_back() = 6;
		TestList.push_back() = 7;
		TestList.push_back() = 8;
		TestList.push_back() = 9;
		TestList.push_back() = 10;

		CHECK_U_INT( TestList.front(), 1 );
		CHECK_U_INT( TestList.back(), 10 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_004_cml_CList<short, 10>_push_back()",
					"Description: \
					- cml_stl_list.h : CList::push_back() \
					- Testing: interface \
					- Overview: verify that push_back works properly \
					- Entry conditions: - \
					- Expected results: push_back adds new data at the begin of the list."
					);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<short ,10> TestList;

		TestList.push_back() = 1;

		CHECK_U_INT( TestList.front(), 1 );
		CHECK_U_INT( TestList.back(), 1 );

		TestList.push_back() = 2;

		CHECK_U_INT( TestList.front(), 1 );
		CHECK_U_INT( TestList.back(), 2 );

		TestList.push_back() = 3;
		TestList.push_back() = 4;
		TestList.push_back() = 5;
		TestList.push_back() = 6;
		TestList.push_back() = 7;
		TestList.push_back() = 8;
		TestList.push_back() = 9;
		TestList.push_back() = 10;

		CHECK_U_INT( TestList.front(), 1 );
		CHECK_U_INT( TestList.back(), 10 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}
#endif

void  TEST_CLASS_LIST::test_cml_CList_pop_front(int doIt)
{
	std::cout << "START ---> test_cml_CList_pop_front\n\n";		
	fprintf(fpTest, "START ---> test_cml_CList_pop_front\n\n");

	fprintf(fpTest, "Function Name ---> CList::pop_front() \n\n");

	if (doIt)
	{
		{
		std::cout << "Test Case ---> test_cml_CList_pop_front_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_pop_front_001\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");
		
		/* Test case data declarations */
		cml::CList<float32 ,2> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		float32 val,expected_val;
		
		val = 0;
		expected_val = 20;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.pop_front();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		val = TestList.front();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_pop_front_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_pop_front_002\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");
		
		/* Test case data declarations */
		cml::CList<sint32 ,2> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		sint32 val,expected_val;
		
		val = 0;
		expected_val = 20;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.pop_front();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		val = TestList.front();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_pop_front_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_pop_front_003\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");
		
		/* Test case data declarations */
		cml::CList<char ,2> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		char val,expected_val;
		
		val = 0;
		expected_val = 20;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.pop_front();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		val = TestList.front();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_pop_front_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_pop_front_004\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");
		
		/* Test case data declarations */
		cml::CList<short ,2> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		short val,expected_val;
		
		val = 0;
		expected_val = 20;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.pop_front();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		val = TestList.front();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
	std::cout << "END ---> test_cml_CList_pop_front\n\n";
	fprintf(fpTest, "END ---> test_cml_CList_pop_front\n\n");
}

void  TEST_CLASS_LIST::test_cml_CList_pop_back(int doIt)
{
	std::cout << "START ---> test_cml_CList_pop_back\n\n";		
	fprintf(fpTest, "START ---> test_cml_CList_pop_back\n\n");

	fprintf(fpTest, "Function Name ---> CList::pop_back() \n\n");
	if (doIt)
	{
		{
		std::cout << "Test Case ---> test_cml_CList_pop_back_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_pop_back_001\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");
		
		/* Test case data declarations */
		cml::CList<float32 ,2> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		float32 val,expected_val;
		
		val = 0;
		expected_val = 10;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.pop_back();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		val = TestList.back();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_pop_back_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_pop_back_002\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");
		
		/* Test case data declarations */
		cml::CList<sint32 ,2> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		sint32 val,expected_val;
		
		val = 0;
		expected_val = 10;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.pop_back();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		val = TestList.back();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_pop_back_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_pop_back_003\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");
		
		/* Test case data declarations */
		cml::CList<char ,2> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		char val,expected_val;
		
		val = 0;
		expected_val = 10;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.pop_back();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		val = TestList.back();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_pop_back_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_pop_back_004\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");
		
		/* Test case data declarations */
		cml::CList<short ,2> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		short val,expected_val;
		
		val = 0;
		expected_val = 10;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.pop_back();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		val = TestList.back();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
	std::cout << "END ---> test_cml_CList_pop_back\n\n";
	fprintf(fpTest, "END ---> test_cml_CList_pop_back\n\n");
}

void  TEST_CLASS_LIST::test_cml_CList_insert_1(int doIt)
{
	std::cout << "START ---> test_cml_CList_insert_1\n\n";		
	fprintf(fpTest, "START ---> test_cml_CList_insert_1\n\n");

	fprintf(fpTest, "Function Name ---> CList::insert() \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CList_insert_1_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_insert_1_001\n\n");

		std::cout << "Data Dimension ---> 3 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 3 \n\n");
		
		/* Test case data declarations */
		cml::CList<float32 ,3> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		int size,expected_size;
		
		size = TestList.size();
		expected_size = 3;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_size);
		check__PrintValue_to_File( expected_size, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.insert( TestList.begin(), 30 );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		size = TestList.size();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(size,expected_size);

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
		std::cout << "Test Case ---> test_cml_CList_insert_1_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_insert_1_002\n\n");

		std::cout << "Data Dimension ---> 3 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 3 \n\n");
		
		/* Test case data declarations */
		cml::CList<sint32 ,3> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		int size,expected_size;
		
		size = TestList.size();
		expected_size = 3;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_size);
		check__PrintValue_to_File( expected_size, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.insert( TestList.begin(), 30 );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		size = TestList.size();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(size,expected_size);

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
		std::cout << "Test Case ---> test_cml_CList_insert_1_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_insert_1_003\n\n");

		std::cout << "Data Dimension ---> 3 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 3 \n\n");
		
		/* Test case data declarations */
		cml::CList<char ,3> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		int size,expected_size;
		
		size = TestList.size();
		expected_size = 3;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_size);
		check__PrintValue_to_File( expected_size, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.insert( TestList.begin(), 30 );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		size = TestList.size();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(size,expected_size);

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
		std::cout << "Test Case ---> test_cml_CList_insert_1_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_insert_1_004\n\n");

		std::cout << "Data Dimension ---> 3 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 3 \n\n");
		
		/* Test case data declarations */
		cml::CList<short ,3> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		int size,expected_size;
		
		size = TestList.size();
		expected_size = 3;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_size);
		check__PrintValue_to_File( expected_size, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.insert( TestList.begin(), 30 );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		size = TestList.size();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(size,expected_size);

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
	std::cout << "END ---> test_cml_CList_insert_1\n\n";
	fprintf(fpTest, "END ---> test_cml_CList_insert_1\n\n");
}

#if 0

void  TEST_CLASS_LIST::test_cml_CList_insert_2(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CList<float32, 10>_insert()",
			"Description: \
			- cml_stl_list.h : CList::insert() \
			- Testing: interface \
			- Overview: verify that insert works properly \
			- Entry conditions: - \
			- Expected results: new data is inserted at the right position."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<float32 ,10> TestList;

		TestList.push_front( 4 );
		TestList.push_front( 2 );

		CHECK_U_INT( TestList.size(), 2 );

		/* Call SUT */
		*TestList.insert( TestList.begin() ) = 1;
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 3 );

		/* Call SUT */
		*TestList.insert( TestList.end() ) = 5;
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 4 );

		/* Call SUT */
		*TestList.insert( ++ ++TestList.begin() ) = 3;
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 5 );

		*TestList.insert( ++ ++TestList.begin() ) =  6;
		*TestList.insert( ++ ++TestList.begin() ) =  7;
		*TestList.insert( ++ ++TestList.begin() ) =  8;
		*TestList.insert( ++ ++TestList.begin() ) =  9;
		*TestList.insert( ++ ++TestList.begin() ) = 10;

		CHECK_U_INT( TestList.size(), 10 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_002_cml_CList<sint32, 10>_insert()",
			"Description: \
			- cml_stl_list.h : CList::insert() \
			- Testing: interface \
			- Overview: verify that insert works properly \
			- Entry conditions: - \
			- Expected results: new data is inserted at the right position."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<sint32 ,10> TestList;

		TestList.push_front( 4 );
		TestList.push_front( 2 );

		CHECK_U_INT( TestList.size(), 2 );

		/* Call SUT */
		*TestList.insert( TestList.begin() ) = 1;
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 3 );

		/* Call SUT */
		*TestList.insert( TestList.end() ) = 5;
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 4 );

		/* Call SUT */
		*TestList.insert( ++ ++TestList.begin() ) = 3;
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 5 );

		*TestList.insert( ++ ++TestList.begin() ) =  6;
		*TestList.insert( ++ ++TestList.begin() ) =  7;
		*TestList.insert( ++ ++TestList.begin() ) =  8;
		*TestList.insert( ++ ++TestList.begin() ) =  9;
		*TestList.insert( ++ ++TestList.begin() ) = 10;

		CHECK_U_INT( TestList.size(), 10 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_003_cml_CList<char, 10>_insert()",
			"Description: \
			- cml_stl_list.h : CList::insert() \
			- Testing: interface \
			- Overview: verify that insert works properly \
			- Entry conditions: - \
			- Expected results: new data is inserted at the right position."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<char ,10> TestList;

		TestList.push_front( 4 );
		TestList.push_front( 2 );

		CHECK_U_INT( TestList.size(), 2 );

		/* Call SUT */
		*TestList.insert( TestList.begin() ) = 1;
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 3 );

		/* Call SUT */
		*TestList.insert( TestList.end() ) = 5;
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 4 );

		/* Call SUT */
		*TestList.insert( ++ ++TestList.begin() ) = 3;
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 5 );

		*TestList.insert( ++ ++TestList.begin() ) =  6;
		*TestList.insert( ++ ++TestList.begin() ) =  7;
		*TestList.insert( ++ ++TestList.begin() ) =  8;
		*TestList.insert( ++ ++TestList.begin() ) =  9;
		*TestList.insert( ++ ++TestList.begin() ) = 10;

		CHECK_U_INT( TestList.size(), 10 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_004_cml_CList<short, 10>_insert()",
					"Description: \
					- cml_stl_list.h : CList::insert() \
					- Testing: interface \
					- Overview: verify that insert works properly \
					- Entry conditions: - \
					- Expected results: new data is inserted at the right position."
					);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<short ,10> TestList;

		TestList.push_front( 4 );
		TestList.push_front( 2 );

		CHECK_U_INT( TestList.size(), 2 );

		/* Call SUT */
		*TestList.insert( TestList.begin() ) = 1;
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 3 );

		/* Call SUT */
		*TestList.insert( TestList.end() ) = 5;
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 4 );

		/* Call SUT */
		*TestList.insert( ++ ++TestList.begin() ) = 3;
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 5 );

		*TestList.insert( ++ ++TestList.begin() ) =  6;
		*TestList.insert( ++ ++TestList.begin() ) =  7;
		*TestList.insert( ++ ++TestList.begin() ) =  8;
		*TestList.insert( ++ ++TestList.begin() ) =  9;
		*TestList.insert( ++ ++TestList.begin() ) = 10;

		CHECK_U_INT( TestList.size(), 10 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}
#endif

void  TEST_CLASS_LIST::test_cml_CList_erase_1(int doIt)
{
	std::cout << "START ---> test_cml_CList_erase_1\n\n";		
	fprintf(fpTest, "START ---> test_cml_CList_erase_1\n\n");

	fprintf(fpTest, "Function Name ---> CList::erase() \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CList_erase_1_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_erase_1_001\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");
		
		/* Test case data declarations */
		cml::CList<float32 ,2> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		int size,expected_size;
		
		size = TestList.size();
		expected_size = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_size);
		check__PrintValue_to_File( expected_size, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.erase( TestList.begin() );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		size = TestList.size();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(size,expected_size);

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
		std::cout << "Test Case ---> test_cml_CList_erase_1_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_erase_1_002\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");
		
		/* Test case data declarations */
		cml::CList<sint32 ,2> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		int size,expected_size;
		
		size = TestList.size();
		expected_size = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_size);
		check__PrintValue_to_File( expected_size, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.erase( TestList.begin() );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		size = TestList.size();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(size,expected_size);

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
		std::cout << "Test Case ---> test_cml_CList_erase_1_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_erase_1_003\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");
		
		/* Test case data declarations */
		cml::CList<char ,2> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		int size,expected_size;
		
		size = TestList.size();
		expected_size = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_size);
		check__PrintValue_to_File( expected_size, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.erase( TestList.begin() );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		size = TestList.size();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(size,expected_size);

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
		std::cout << "Test Case ---> test_cml_CList_erase_1_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_erase_1_004\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");
		
		/* Test case data declarations */
		cml::CList<short ,2> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		int size,expected_size;
		
		size = TestList.size();
		expected_size = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_size);
		check__PrintValue_to_File( expected_size, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestList.erase( TestList.begin() );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		size = TestList.size();
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(size,expected_size);

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
	std::cout << "END ---> test_cml_CList_erase_1\n\n";
	fprintf(fpTest, "END ---> test_cml_CList_erase_1\n\n");
}

#if 0
void  TEST_CLASS_LIST::test_cml_CList_erase_2(int doIt)
{
	if (doIt)
	{
		START_TEST("test_001_cml_CList<float32, 10>_erase(iterator first, iterator last)",
			"Description: \
			- cml_stl_list.h : CList::erase() \
			- Testing: interface \
			- Overview: verify that erase works properly \
			- Entry conditions: - \
			- Expected results: the selected data is removed from the list."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<float32 ,20> TestList;
		TestList.push_front( 91 );
		TestList.push_front( 5 );
		TestList.push_front( 4 );
		TestList.push_front( 92 );
		TestList.push_front( 93 );
		TestList.push_front( 3 );
		TestList.push_front( 2 );
		TestList.push_front( 1 );
		TestList.push_front( 99 );
		TestList.push_front( 95 );
		TestList.push_front( 96 );
		TestList.push_front( 97 );

		CHECK_U_INT( TestList.size(), 12 );


		/* Call SUT */
		TestList.erase( -- TestList.end(), TestList.end() );
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 11 );


		/* Call SUT */
		TestList.erase( TestList.begin(), ++ ++ ++TestList.begin() );
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 8 );


		/* Call SUT */
		TestList.erase( TestList.begin(), ++TestList.begin() );
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 7 );


		/* Call SUT */
		TestList.erase( ++ ++ ++TestList.begin(), -- --TestList.end() );
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 5 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_002_cml_CList<sint32, 10>_erase(iterator first, iterator last)",
			"Description: \
			- cml_stl_list.h : CList::erase() \
			- Testing: interface \
			- Overview: verify that erase works properly \
			- Entry conditions: - \
			- Expected results: the selected data is removed from the list."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<sint32 ,20> TestList;
		TestList.push_front( 91 );
		TestList.push_front( 5 );
		TestList.push_front( 4 );
		TestList.push_front( 92 );
		TestList.push_front( 93 );
		TestList.push_front( 3 );
		TestList.push_front( 2 );
		TestList.push_front( 1 );
		TestList.push_front( 99 );
		TestList.push_front( 95 );
		TestList.push_front( 96 );
		TestList.push_front( 97 );

		CHECK_U_INT( TestList.size(), 12 );


		/* Call SUT */
		TestList.erase( -- TestList.end(), TestList.end() );
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 11 );


		/* Call SUT */
		TestList.erase( TestList.begin(), ++ ++ ++TestList.begin() );
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 8 );


		/* Call SUT */
		TestList.erase( TestList.begin(), ++TestList.begin() );
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 7 );


		/* Call SUT */
		TestList.erase( ++ ++ ++TestList.begin(), -- --TestList.end() );
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 5 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_003_cml_CList<char, 10>_erase(iterator first, iterator last)",
			"Description: \
			- cml_stl_list.h : CList::erase() \
			- Testing: interface \
			- Overview: verify that erase works properly \
			- Entry conditions: - \
			- Expected results: the selected data is removed from the list."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<char ,20> TestList;
		TestList.push_front( 91 );
		TestList.push_front( 5 );
		TestList.push_front( 4 );
		TestList.push_front( 92 );
		TestList.push_front( 93 );
		TestList.push_front( 3 );
		TestList.push_front( 2 );
		TestList.push_front( 1 );
		TestList.push_front( 99 );
		TestList.push_front( 95 );
		TestList.push_front( 96 );
		TestList.push_front( 97 );

		CHECK_U_INT( TestList.size(), 12 );


		/* Call SUT */
		TestList.erase( -- TestList.end(), TestList.end() );
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 11 );


		/* Call SUT */
		TestList.erase( TestList.begin(), ++ ++ ++TestList.begin() );
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 8 );


		/* Call SUT */
		TestList.erase( TestList.begin(), ++TestList.begin() );
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 7 );


		/* Call SUT */
		TestList.erase( ++ ++ ++TestList.begin(), -- --TestList.end() );
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 5 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_004_cml_CList<short, 10>_erase(iterator first, iterator last)",
					"Description: \
					- cml_stl_list.h : CList::erase() \
					- Testing: interface \
					- Overview: verify that erase works properly \
					- Entry conditions: - \
					- Expected results: the selected data is removed from the list."
					);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CList<short ,20> TestList;
		TestList.push_front( 91 );
		TestList.push_front( 5 );
		TestList.push_front( 4 );
		TestList.push_front( 92 );
		TestList.push_front( 93 );
		TestList.push_front( 3 );
		TestList.push_front( 2 );
		TestList.push_front( 1 );
		TestList.push_front( 99 );
		TestList.push_front( 95 );
		TestList.push_front( 96 );
		TestList.push_front( 97 );

		CHECK_U_INT( TestList.size(), 12 );


		/* Call SUT */
		TestList.erase( -- TestList.end(), TestList.end() );
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 11 );


		/* Call SUT */
		TestList.erase( TestList.begin(), ++ ++ ++TestList.begin() );
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 8 );


		/* Call SUT */
		TestList.erase( TestList.begin(), ++TestList.begin() );
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 7 );


		/* Call SUT */
		TestList.erase( ++ ++ ++TestList.begin(), -- --TestList.end() );
		/* Test case checks */
		CHECK_U_INT( TestList.size(), 5 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

	}
}
#endif

void  TEST_CLASS_LIST::test_cml_CList_begin(int doIt)
{
	std::cout << "START ---> test_cml_CList_begin\n\n";		
	fprintf(fpTest, "START ---> test_cml_CList_begin\n\n");

	fprintf(fpTest, "Function Name ---> CList::begin() \n\n");

	if (doIt)
	{
		{
		std::cout << "Test Case ---> test_cml_CList_begin_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_begin_001\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<float32 ,10> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		float32 val,expected_val;
		
		val = 0;
		expected_val = 10;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(TestList.begin());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_begin_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_begin_002\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<sint32 ,10> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		sint32 val,expected_val;
		
		val = 0;
		expected_val = 10;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(TestList.begin());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_begin_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_begin_003\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<char ,10> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		char val,expected_val;
		
		val = 0;
		expected_val = 10;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(TestList.begin());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_begin_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_begin_004\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<short ,10> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		short val,expected_val;
		
		val = 0;
		expected_val = 10;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(TestList.begin());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
	std::cout << "END ---> test_cml_CList_begin\n\n";
	fprintf(fpTest, "END ---> test_cml_CList_begin\n\n");

}

void  TEST_CLASS_LIST::test_cml_CList_end(int doIt)
{
	std::cout << "START ---> test_cml_CList_end\n\n";		
	fprintf(fpTest, "START ---> test_cml_CList_end\n\n");

	fprintf(fpTest, "Function Name ---> CList::end() \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CList_end_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_end_001\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<float32 ,10> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		float32 val,expected_val;
		
		val = 0;
		expected_val = 20;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(--TestList.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_end_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_end_002\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<sint32 ,10> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		sint32 val,expected_val;
		
		val = 0;
		expected_val = 20;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(--TestList.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_end_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_end_003\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<char ,10> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		char val,expected_val;
		
		val = 0;
		expected_val = 20;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(--TestList.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CList_end_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CList_end_004\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<short ,10> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		short val,expected_val;
		
		val = 0;
		expected_val = 20;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(--TestList.end());

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
	std::cout << "END ---> test_cml_CList_end\n\n";
	fprintf(fpTest, "END ---> test_cml_CList_end\n\n");
}

#if 0
void  TEST_CLASS_LIST::test_cml_CBidirectionalIt_constructor(int doIt)
{
	if (doIt)
	{
		START_TEST("test_001_cml_CConstBidirectionalIt<float32, 10>_constructor()",
			"Description: \
			- cml_stl_list.h : CBidirectionalIt::constructor() \
			- Testing: interface \
			- Overview: verify that constructor works properly \
			- Entry conditions: - \
			- Expected results: a empty iterator is build."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		char Value;

		/* Call SUT */

		cml::CBidirectionalIt<float32, 10 >  TestIterator;
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_002_cml_CConstBidirectionalIt<sint32, 10>_constructor()",
			"Description: \
			- cml_stl_list.h : CBidirectionalIt::constructor() \
			- Testing: interface \
			- Overview: verify that constructor works properly \
			- Entry conditions: - \
			- Expected results: a empty iterator is build."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		char Value;

		/* Call SUT */

		cml::CBidirectionalIt<sint32, 10>  TestIterator;
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_003_cml_CConstBidirectionalIt<char, 10>_constructor()",
			"Description: \
			- cml_stl_list.h : CBidirectionalIt::constructor() \
			- Testing: interface \
			- Overview: verify that constructor works properly \
			- Entry conditions: - \
			- Expected results: a empty iterator is build."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		char Value;

		/* Call SUT */

		cml::CBidirectionalIt<char, 10>  TestIterator;
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void  TEST_CLASS_LIST::test_cml_CBidirectionalIt_constructor_CBidirectionalIt(int doIt)
{
	if (doIt)
	{
		START_TEST("test_001_cml_CConstBidirectionalIt<float32, 10>_constructor()",
			"Description: \
			- cml_stl_list.h : CBidirectionalIt ( const self_non_const&     _rhs )  \
			- Testing: interface \
			- Overview: verify that constructor works properly \
			- Entry conditions: - \
			- Expected results: a empty iterator is build."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CBidirectionalIt<float32, 10 >  TestIterator;
		cml::CList<float32 ,10> TestList;

		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );

		cml::CBidirectionalIt<float32, 10 >  TestIterator1(TestIterator);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_002_cml_CConstBidirectionalIt<sint32, 10>_constructor()",
			"Description: \
			- cml_stl_list.h : CBidirectionalIt ( const self_non_const&     _rhs )  \
			- Testing: interface \
			- Overview: verify that constructor works properly \
			- Entry conditions: - \
			- Expected results: a empty iterator is build."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CBidirectionalIt<sint32, 10 >  TestIterator;
		cml::CList<sint32 ,10> TestList;

		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );

		cml::CBidirectionalIt<sint32, 10 >  TestIterator1(TestIterator);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_003_cml_CConstBidirectionalIt<char, 10>_constructor()",
			"Description: \
			- cml_stl_list.h : CBidirectionalIt ( const self_non_const&     _rhs )  \
			- Testing: interface \
			- Overview: verify that constructor works properly \
			- Entry conditions: - \
			- Expected results: a empty iterator is build."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CBidirectionalIt<char, 10 >  TestIterator;
		cml::CList<char ,10> TestList;

		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );

		cml::CBidirectionalIt<char, 10 >  TestIterator1(TestIterator);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void  TEST_CLASS_LIST::test_cml_CBidirectionalIt_constructor_CBaseIt(int doIt)
{
	if (doIt)
	{
		START_TEST("test_001_cml_CBidirectionalIt<float32, 10>_constructor()",
			"Description: \
			- cml_stl_list.h : CBidirectionalIt ( const CBaseIt< list_node_type, IS_CONST_ITERATOR_2 >& _itNode )  \
			- Testing: interface \
			- Overview: verify that constructor works properly \
			- Entry conditions: - \
			- Expected results: a empty iterator is build."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		cml::CList<float32 ,10> TestList;


		cml::CBidirectionalIt<float32,false> Testiterator(TestList.begin());


		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_002_cml_CBidirectionalIt<sint32, 10>_constructor()",
			"Description: \
			- cml_stl_list.h : CBidirectionalIt ( const CBaseIt< list_node_type, IS_CONST_ITERATOR_2 >& _itNode )  \
			- Testing: interface \
			- Overview: verify that constructor works properly \
			- Entry conditions: - \
			- Expected results: a empty iterator is build."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		cml::CList<sint32 ,10> TestList;


		cml::CBidirectionalIt<sint32,false> Testiterator(TestList.begin());


		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_003_cml_CBidirectionalIt<char, 10>_constructor()",
			"Description: \
			- cml_stl_list.h : CBidirectionalIt ( const CBaseIt< list_node_type, IS_CONST_ITERATOR_2 >& _itNode )  \
			- Testing: interface \
			- Overview: verify that constructor works properly \
			- Entry conditions: - \
			- Expected results: a empty iterator is build."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		cml::CList<char ,10> TestList;


		cml::CBidirectionalIt<char,false> Testiterator(TestList.begin());


		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}
#endif

void  TEST_CLASS_LIST::test_cml_CBidirectionalIt_operator_indirection(int doIt)
{
	std::cout << "START ---> test_cml_CBidirectionalIt_operator_indirection\n\n";		
	fprintf(fpTest, "START ---> test_cml_CBidirectionalIt_operator_indirection\n\n");

	fprintf(fpTest, "Function Name ---> CBidirectionalIt::operator*() \n\n");

	if (doIt)
	{
		{
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_indirection_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_indirection_001\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<float32 ,10> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		float32 val,expected_val;
		
		val = 0;
		expected_val = 10;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<float32,false> Testiterator(TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(Testiterator);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_indirection_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_indirection_002\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<sint32 ,10> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		sint32 val,expected_val;
		
		val = 0;
		expected_val = 10;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<sint32,false> Testiterator(TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(Testiterator);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_indirection_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_indirection_003\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<char ,10> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		char val,expected_val;
		
		val = 0;
		expected_val = 10;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<char,false> Testiterator(TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(Testiterator);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_indirection_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_indirection_004\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<short ,10> TestList;
		TestList.push_back( 10 );
		TestList.push_back( 20 );
		
		short val,expected_val;
		
		val = 0;
		expected_val = 10;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<short,false> Testiterator(TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(Testiterator);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
	std::cout << "END ---> test_cml_CBidirectionalIt_operator_indirection\n\n";
	fprintf(fpTest, "END ---> test_cml_CBidirectionalIt_operator_indirection\n\n");
}

void  TEST_CLASS_LIST::test_cml_CBidirectionalIt_operator_arrow(int doIt)
{
	std::cout << "START ---> test_cml_CBidirectionalIt_operator_arrow\n\n";		
	fprintf(fpTest, "START ---> test_cml_CBidirectionalIt_operator_arrow\n\n");

	fprintf(fpTest, "Function Name ---> CBidirectionalIt::operator->() \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_arrow_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_arrow_001\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");
		
		/* Test case data declarations */
		cml::CList<TEST_tstTestStuct ,10> TestList;
	
		float32 val,expected_val;
		
		for( int i = 0; i<5; i++ )
		{
			TEST_tstTestStuct TestStruct;
			TestStruct.fData = i+1;
			TestList.push_back( TestStruct );
		}
		
		val = 0;
		expected_val = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<TEST_tstTestStuct,false> Testiterator(TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = Testiterator->fData;

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
	std::cout << "END ---> test_cml_CBidirectionalIt_operator_arrow\n\n";
	fprintf(fpTest, "END ---> test_cml_CBidirectionalIt_operator_arrow\n\n");
}

void  TEST_CLASS_LIST::test_cml_CBidirectionalIt_operator_plusplus_1(int doIt)
{
	std::cout << "START ---> test_cml_CBidirectionalIt_operator_plusplus_1\n\n";		
	fprintf(fpTest, "START ---> test_cml_CBidirectionalIt_operator_plusplus_1\n\n");

	fprintf(fpTest, "Function Name ---> CBidirectionalIt::operator++() \n\n");

	if (doIt)
	{
		{
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_plusplus_1_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_plusplus_1_001\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CList<float32 ,5> TestList;
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
	
		float32 val,expected_val;
		
		val = 0;
		expected_val = 3;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<float32,false> Testiterator(++ ++TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(Testiterator);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_plusplus_1_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_plusplus_1_002\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CList<sint32 ,5> TestList;
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
	
		sint32 val,expected_val;
		
		val = 0;
		expected_val = 3;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<sint32,false> Testiterator(++ ++TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(Testiterator);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_plusplus_1_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_plusplus_1_003\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CList<char ,5> TestList;
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
	
		char val,expected_val;
		
		val = 0;
		expected_val = 3;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<char,false> Testiterator(++ ++TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(Testiterator);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_plusplus_1_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_plusplus_1_004\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CList<short ,5> TestList;
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
	
		short val,expected_val;
		
		val = 0;
		expected_val = 3;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<short,false> Testiterator(++ ++TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(Testiterator);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
	std::cout << "END ---> test_cml_CBidirectionalIt_operator_plusplus_1\n\n";
	fprintf(fpTest, "END ---> test_cml_CBidirectionalIt_operator_plusplus_1\n\n");
}

void  TEST_CLASS_LIST::test_cml_CBidirectionalIt_operator_plusplus_2(int doIt)
{
	std::cout << "START ---> test_cml_CBidirectionalIt_operator_plusplus_2\n\n";		
	fprintf(fpTest, "START ---> test_cml_CBidirectionalIt_operator_plusplus_2\n\n");

	fprintf(fpTest, "Function Name ---> CBidirectionalIt::operator++() \n\n");

	if (doIt)
	{
		{
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_plusplus_2_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_plusplus_2_001\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CList<float32 ,5> TestList;
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
	
		float32 val,expected_val;
		
		val = 0;
		expected_val = 3;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<float32,false> Testiterator(++ ++TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(Testiterator++);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_plusplus_2_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_plusplus_2_002\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CList<sint32 ,5> TestList;
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
	
		sint32 val,expected_val;
		
		val = 0;
		expected_val = 3;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<sint32,false> Testiterator(++ ++TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(Testiterator++);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_plusplus_2_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_plusplus_2_003\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CList<char ,5> TestList;
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
	
		char val,expected_val;
		
		val = 0;
		expected_val = 3;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<char,false> Testiterator(++ ++TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(Testiterator++);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_plusplus_2_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_plusplus_2_004\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CList<short ,5> TestList;
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
	
		short val,expected_val;
		
		val = 0;
		expected_val = 3;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<short,false> Testiterator(++ ++TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(Testiterator++);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
	std::cout << "END ---> test_cml_CBidirectionalIt_operator_plusplus_2\n\n";
	fprintf(fpTest, "END ---> test_cml_CBidirectionalIt_operator_plusplus_2\n\n");
}

void  TEST_CLASS_LIST::test_cml_CBidirectionalIt_operator_minusminus_1(int doIt)
{
	std::cout << "START ---> test_cml_CBidirectionalIt_operator_minusminus_1\n\n";		
	fprintf(fpTest, "START ---> test_cml_CBidirectionalIt_operator_minusminus_1\n\n");

	fprintf(fpTest, "Function Name ---> CBidirectionalIt::operator--() \n\n");

	if (doIt)
	{
		{
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_minusminus_1_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_minusminus_1_001\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CList<float32 ,5> TestList;
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
	
		float32 val,expected_val;
		
		val = 0;
		expected_val = 3;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<float32,false> Testiterator(++ ++TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(Testiterator--);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_minusminus_1_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_minusminus_1_002\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CList<sint32 ,5> TestList;
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
	
		sint32 val,expected_val;
		
		val = 0;
		expected_val = 3;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<sint32,false> Testiterator(++ ++TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(Testiterator--);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_minusminus_1_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_minusminus_1_003\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CList<char ,5> TestList;
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
	
		char val,expected_val;
		
		val = 0;
		expected_val = 3;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<char,false> Testiterator(++ ++TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(Testiterator--);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_minusminus_1_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_minusminus_1_004\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CList<short ,5> TestList;
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
	
		short val,expected_val;
		
		val = 0;
		expected_val = 3;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<short,false> Testiterator(++ ++TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(Testiterator--);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
	std::cout << "END ---> test_cml_CBidirectionalIt_operator_minusminus_1\n\n";
	fprintf(fpTest, "END ---> test_cml_CBidirectionalIt_operator_minusminus_1\n\n");
}

void  TEST_CLASS_LIST::test_cml_CBidirectionalIt_operator_minusminus_2(int doIt)
{
	std::cout << "START ---> test_cml_CBidirectionalIt_operator_minusminus_2\n\n";		
	fprintf(fpTest, "START ---> test_cml_CBidirectionalIt_operator_minusminus_2\n\n");

	fprintf(fpTest, "Function Name ---> CBidirectionalIt::operator--() \n\n");

	if (doIt)
	{
		{
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_minusminus_2_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_minusminus_2_001\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CList<float32 ,5> TestList;
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
	
		float32 val,expected_val;
		
		val = 0;
		expected_val = 2;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<float32,false> Testiterator(++ ++TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(--Testiterator);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_minusminus_2_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_minusminus_2_002\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CList<sint32 ,5> TestList;
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
	
		sint32 val,expected_val;
		
		val = 0;
		expected_val = 2;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<sint32,false> Testiterator(++ ++TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(--Testiterator);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_minusminus_2_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_minusminus_2_003\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CList<char ,5> TestList;
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
	
		char val,expected_val;
		
		val = 0;
		expected_val = 2;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<char,false> Testiterator(++ ++TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(--Testiterator);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_minusminus_2_004\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_minusminus_2_004\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CList<short ,5> TestList;
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
	
		short val,expected_val;
		
		val = 0;
		expected_val = 2;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<short,false> Testiterator(++ ++TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = *(--Testiterator);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
	std::cout << "END ---> test_cml_CBidirectionalIt_operator_minusminus_2\n\n";
	fprintf(fpTest, "END ---> test_cml_CBidirectionalIt_operator_minusminus_2\n\n");
}

void  TEST_CLASS_LIST::test_cml_CBidirectionalIt_operator_equalequal(int doIt)
{
	std::cout << "START ---> test_cml_CBidirectionalIt_operator_equalequal\n\n";		
	fprintf(fpTest, "START ---> test_cml_CBidirectionalIt_operator_equalequal\n\n");

	fprintf(fpTest, "Function Name ---> CBidirectionalIt::operator==() \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_equalequal_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_equalequal_001\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CList<float32 ,5> TestList;
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
	
		cml::boolean_t val,expected_val;
		
		val = false;
		expected_val = true;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<float32,false> Testiterator1(++ ++TestList.begin());
		cml::CBidirectionalIt<float32,false> Testiterator2(++ ++TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = (Testiterator1==Testiterator2);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
	std::cout << "END ---> test_cml_CBidirectionalIt_operator_equalequal\n\n";
	fprintf(fpTest, "END ---> test_cml_CBidirectionalIt_operator_equalequal\n\n");
}

void  TEST_CLASS_LIST::test_cml_CBidirectionalIt_operator_notequal(int doIt)
{
	std::cout << "START ---> test_cml_CBidirectionalIt_operator_notequal\n\n";		
	fprintf(fpTest, "START ---> test_cml_CBidirectionalIt_operator_notequal\n\n");

	fprintf(fpTest, "Function Name ---> CBidirectionalIt::operator!=() \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CBidirectionalIt_operator_notequal_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CBidirectionalIt_operator_notequal_001\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");
		
		/* Test case data declarations */
		cml::CList<float32 ,5> TestList;
		TestList.push_back( 1 );
		TestList.push_back( 2 );
		TestList.push_back( 3 );
		TestList.push_back( 4 );
		TestList.push_back( 5 );
	
		cml::boolean_t val,expected_val;
		
		val = true;
		expected_val = false;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_val);
		check__PrintValue_to_File( expected_val, fpTest);
		fprintf(fpTest, "\n\n");

		cml::CBidirectionalIt<float32,false> Testiterator1(++ ++TestList.begin());
		cml::CBidirectionalIt<float32,false> Testiterator2(++ ++TestList.begin());

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		val = (Testiterator1!=Testiterator2);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( val);
		check__PrintValue_to_File( val, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(val,expected_val);

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
	std::cout << "END ---> test_cml_CBidirectionalIt_operator_notequal\n\n";
	fprintf(fpTest, "END ---> test_cml_CBidirectionalIt_operator_notequal\n\n");
}

#if 0
void  TEST_CLASS_LIST::test_cml_CBidirectionalIt_operator_equalequal(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CBidirectionalIt<float32, 10>_operator==()",
			"Description: \
			- cml_stl_list.h : CBidirectionalIt::operator==() \
			- Testing: interface \
			- Overview: verify that operator==() works properly \
			- Entry conditions: - \
			- Expected results: returns true if the node values are equal."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		cml::CList<float32 ,10> TestList1;
		cml::CList<float32 ,10> TestList2;

		TestList1.push_back( 1 );
		TestList1.push_back( 2 );
		TestList1.push_back( 3 );
		TestList1.push_back( 4 );
		TestList1.push_back( 5 );

		cml::CBidirectionalIt<float32,false> TestIterator1(++ ++TestList1.begin());
		cml::CBidirectionalIt<float32,false> TestIterator2(++ ++TestList1.begin());

		/* Call SUT */

		CHECK_BOOLEAN( (TestIterator1==TestIterator2),1);

		/* Test case checks */


		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_002_cml_CBidirectionalIt<sint32, 10>_operator==()",
			"Description: \
			- cml_stl_list.h : CBidirectionalIt::operator==() \
			- Testing: interface \
			- Overview: verify that operator==() works properly \
			- Entry conditions: - \
			- Expected results: returns true if the node values are equal."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		cml::CList<sint32 ,10> TestList1;
		cml::CList<sint32 ,10> TestList2;

		TestList1.push_back( 1 );
		TestList1.push_back( 2 );
		TestList1.push_back( 3 );
		TestList1.push_back( 4 );
		TestList1.push_back( 5 );

		cml::CBidirectionalIt<sint32,false> TestIterator1(++ ++TestList1.begin());
		cml::CBidirectionalIt<sint32,false> TestIterator2(++ ++TestList1.begin());

		/* Call SUT */

		CHECK_BOOLEAN( (TestIterator1==TestIterator2),1);

		/* Test case checks */


		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_003_cml_CBidirectionalIt<char, 10>_operator==()",
			"Description: \
			- cml_stl_list.h : CBidirectionalIt::operator==() \
			- Testing: interface \
			- Overview: verify that operator==() works properly \
			- Entry conditions: - \
			- Expected results: returns true if the node values are equal."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		cml::CList<char ,10> TestList1;
		cml::CList<char ,10> TestList2;

		TestList1.push_back( 1 );
		TestList1.push_back( 2 );
		TestList1.push_back( 3 );
		TestList1.push_back( 4 );
		TestList1.push_back( 5 );

		cml::CBidirectionalIt<char,false> TestIterator1(++ ++TestList1.begin());
		cml::CBidirectionalIt<char,false> TestIterator2(++ ++TestList1.begin());

		/* Call SUT */

		CHECK_BOOLEAN( (TestIterator1==TestIterator2),1);

		/* Test case checks */


		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_004_cml_CBidirectionalIt<short, 10>_operator==()",
					"Description: \
					- cml_stl_list.h : CBidirectionalIt::operator==() \
					- Testing: interface \
					- Overview: verify that operator==() works properly \
					- Entry conditions: - \
					- Expected results: returns true if the node values are equal."
					);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		cml::CList<short ,10> TestList1;
		cml::CList<short ,10> TestList2;

		TestList1.push_back( 1 );
		TestList1.push_back( 2 );
		TestList1.push_back( 3 );
		TestList1.push_back( 4 );
		TestList1.push_back( 5 );

		cml::CBidirectionalIt<short,false> TestIterator1(++ ++TestList1.begin());
		cml::CBidirectionalIt<short,false> TestIterator2(++ ++TestList1.begin());

		/* Call SUT */

		CHECK_BOOLEAN( (TestIterator1==TestIterator2),1);

		/* Test case checks */


		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void  TEST_CLASS_LIST::test_cml_CBidirectionalIt_operator_notequal(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CBidirectionalIt<float32, 10>_operator!=()",
			"Description: \
			- cml_stl_list.h : CBidirectionalIt::operator!=() \
			- Testing: interface \
			- Overview: verify that operator!=() works properly \
			- Entry conditions: - \
			- Expected results: returns true if the node values are not equal."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		float32 Value;
		cml::CList<float32 ,10> TestList1;
		cml::CList<float32 ,10> TestList2;

		TestList1.push_back( 1 );
		TestList1.push_back( 2 );
		TestList1.push_back( 3 );
		TestList1.push_back( 4 );
		TestList1.push_back( 5 );

		TestList2.push_back( 3 );
		TestList2.push_back( 4 );
		TestList2.push_back( 5 );
		TestList2.push_back( 6 );
		TestList2.push_back( 7 );

		cml::CBidirectionalIt<float32,false> TestIterator1(++ ++TestList1.begin());
		cml::CBidirectionalIt<float32,false> TestIterator2(++ ++TestList2.begin());

		/* Call SUT */

		CHECK_BOOLEAN( (TestIterator1!=TestIterator2),1);

		/* Test case checks */


		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_002_cml_CBidirectionalIt<sint32, 10>_operator!=()",
			"Description: \
			- cml_stl_list.h : CBidirectionalIt::operator!=() \
			- Testing: interface \
			- Overview: verify that operator!=() works properly \
			- Entry conditions: - \
			- Expected results: returns true if the node values are not equal."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		float32 Value;
		cml::CList<sint32 ,10> TestList1;
		cml::CList<sint32 ,10> TestList2;

		TestList1.push_back( 1 );
		TestList1.push_back( 2 );
		TestList1.push_back( 3 );
		TestList1.push_back( 4 );
		TestList1.push_back( 5 );

		TestList2.push_back( 3 );
		TestList2.push_back( 4 );
		TestList2.push_back( 5 );
		TestList2.push_back( 6 );
		TestList2.push_back( 7 );

		cml::CBidirectionalIt<sint32,false> TestIterator1(++ ++TestList1.begin());
		cml::CBidirectionalIt<sint32,false> TestIterator2(++ ++TestList2.begin());

		/* Call SUT */

		CHECK_BOOLEAN( (TestIterator1!=TestIterator2),1);

		/* Test case checks */


		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_003_cml_CBidirectionalIt<char, 10>_operator!=()",
			"Description: \
			- cml_stl_list.h : CBidirectionalIt::operator!=() \
			- Testing: interface \
			- Overview: verify that operator!=() works properly \
			- Entry conditions: - \
			- Expected results: returns true if the node values are not equal."
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		float32 Value;
		cml::CList<char ,10> TestList1;
		cml::CList<char ,10> TestList2;

		TestList1.push_back( 1 );
		TestList1.push_back( 2 );
		TestList1.push_back( 3 );
		TestList1.push_back( 4 );
		TestList1.push_back( 5 );

		TestList2.push_back( 3 );
		TestList2.push_back( 4 );
		TestList2.push_back( 5 );
		TestList2.push_back( 6 );
		TestList2.push_back( 7 );

		cml::CBidirectionalIt<char,false> TestIterator1(++ ++TestList1.begin());
		cml::CBidirectionalIt<char,false> TestIterator2(++ ++TestList2.begin());

		/* Call SUT */

		CHECK_BOOLEAN( (TestIterator1!=TestIterator2),1);

		/* Test case checks */


		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_004_cml_CBidirectionalIt<short, 10>_operator!=()",
					"Description: \
					- cml_stl_list.h : CBidirectionalIt::operator!=() \
					- Testing: interface \
					- Overview: verify that operator!=() works properly \
					- Entry conditions: - \
					- Expected results: returns true if the node values are not equal."
					);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		float32 Value;
		cml::CList<short ,10> TestList1;
		cml::CList<short ,10> TestList2;

		TestList1.push_back( 1 );
		TestList1.push_back( 2 );
		TestList1.push_back( 3 );
		TestList1.push_back( 4 );
		TestList1.push_back( 5 );

		TestList2.push_back( 3 );
		TestList2.push_back( 4 );
		TestList2.push_back( 5 );
		TestList2.push_back( 6 );
		TestList2.push_back( 7 );

		cml::CBidirectionalIt<short,false> TestIterator1(++ ++TestList1.begin());
		cml::CBidirectionalIt<short,false> TestIterator2(++ ++TestList2.begin());

		/* Call SUT */

		CHECK_BOOLEAN( (TestIterator1!=TestIterator2),1);

		/* Test case checks */


		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

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
