/*****************************************************************************/
/*                            Cantata Test Script                            */
/*****************************************************************************/
/*
*    Filename: test_cml_stl_array.cpp
*    Author: uidn9012
*    Generated on: 12-Feb-2016 16:26:09
*    Generated from: cml_stl_array.cpp
*/
/*****************************************************************************/
/* Environment Definition                                                    */
/*****************************************************************************/


#define TEST_SCRIPT_GENERATOR 2
typedef unsigned long long uint64;
/* Include files from software under test */
#include <stdio.h>
#include <iostream>
#include"cml_ext.h"
#include "glob_type.h"
#include "cml_stl_type_traits.h"
#include "cml_stl_matrix.h"
#include "cml_stl_array.h"
#include "cml_stl_array2d.h"

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

/* Global Functions */
/* None */

/* Global data */

#define ArrayData                                     \
{    1,   2,   3,   4,   5,   6,   7,   8,   9,  10};    \

#define ArrayData_Zero                                     \
{    0,   0,   0,   0,   0,   0,   0,   0,   0,  0};  \

static char TEST_acData123[]     = ArrayData;
static int TEST_aiData123[] = ArrayData;
static float TEST_afData123[] = ArrayData;
static const char TEST_acData123_const[]    = ArrayData;
static const int TEST_aiData123_const[] = ArrayData;
static const float TEST_afData123_const[] = ArrayData;
static char TEST_acData_Zero[]     = ArrayData_Zero;
static int TEST_aiData_Zero[]     = ArrayData_Zero;
static float TEST_afData_Zero[]     = ArrayData_Zero;

template< typename >
bool check__boCompare( float fIst, float fSoll )
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
bool check__boCompare( char cIst, char cSoll )
{
	return cIst == cSoll;
}

template< typename T >
bool check__boCompare( T Ist, T Soll )
{
	return Ist == Soll;
}

template < typename T, sint32 COLS, bool EXT_MEM >
bool check__vArrayCompare(cml::CArrayStorage<T ,COLS, EXT_MEM> &oArray,cml::CArrayStorage<T ,COLS, EXT_MEM> &bArray)
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
bool check__vArrayCompare(cml::CArrayStorage<T ,COLS, EXT_MEM> &oArray,cml::CArrayStorage<const T ,COLS, EXT_MEM> &bArray)
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
void check__PrintValue(float Value, FILE *fpTest)
{
	fprintf(fpTest, "%f\t\t", Value);
}

void check__PrintValue(int Value, FILE *fpTest)
{
	fprintf(fpTest, "%i\t\t", Value);
}

void check__PrintValue(short Value, FILE *fpTest)
{
	fprintf(fpTest, "%i\t\t", Value);
}

void check__PrintValue(char Value, FILE *fpTest)
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
void check__vArrayPrint_to_File( cml::CArrayStorage<T ,COLS, EXT_MEM> &oArray, FILE *fpTest)
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
void check__vArrayPrint_to_console( cml::CArrayStorage<T ,COLS, EXT_MEM> &oArray)
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

template < typename T, sint32 COLS, bool EXT_MEM >
void check__vArrayPrint_to_File(const cml::CArrayStorage<T ,COLS, EXT_MEM> &oArray, FILE *fpTest)
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
void check__vArrayPrint_to_console(const cml::CArrayStorage<T ,COLS, EXT_MEM> &oArray)
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

template < typename T, sint32 COLS, bool EXT_MEM >
void check__vArrayPrint( cml::CArrayStorage<T ,COLS, EXT_MEM> &oArray, FILE *fpTest)
{    
	int  iIndex= 0;
	for( int row=0; row<oArray.size(); row++ )
	{
			check__PrintValue(oArray[iIndex], fpTest);
			iIndex++;
		//fprintf(fpTest, "\n");
	} 

	fprintf(fpTest, "\n\n");
}

template < typename T, sint32 COLS, bool EXT_MEM >
void check__vArrayPrint(const cml::CArrayStorage<T ,COLS, EXT_MEM> &oArray, FILE *fpTest)
{    
	int  iIndex= 0;
	for( int row=0; row<oArray.size(); row++ )
	{
			check__PrintValue(oArray[iIndex], fpTest);
			iIndex++;
		//fprintf(fpTest, "\n");
	} 

	fprintf(fpTest, "\n\n");
}

/* Expected variables for global data */
uint16 check_u16AssertCount;
uint16 check_u16ExpectedAssertCount;
bool   check_boThrowException;

/* This function initialises global data to default values. This function       */
/* is called by every test case so must not contain test case specific settings */
static void initialise_global_data()
{
}

/* This function copies the global data settings into expected variables for */
/* use in check_global_data(). It is called by every test case so must not   */
/* contain test case specific settings.                                      */
static void initialise_expected_global_data(){

	/* No global data */
}

/* This function checks global data against the expected values. */
static void check_global_data()
{
	std::cout << "\nStatus ---> PASS\n\n"; 
	fprintf(fpTest, "\nStatus ---> PASS\n\n");
}
/*****************************************************************************/
/* Test class declaration                                                    */
/*****************************************************************************/
class TEST_CLASS_ARRAY
{
public:
	void run_tests_array();
	void test_cml_CArrayStorage_false_constructor( int doIt );
	void test_cml_CArrayStorage_false_constructor_aData(int doIt);
	void test_cml_CArrayStorage_false_constructor_CArrayStorage_1(int doIt);
	void test_cml_CArrayStorage_false_constructor_CArrayStorage_2(int doIt);
	void test_cml_CArrayStorage_false_constructor_CArrayStorage_3(int doIt);
	void test_cml_CArrayStorage_false_operator_at_1(int doIt);
	void test_cml_CArrayStorage_false_operator_at_2(int doIt);
	void test_cml_CArrayStorage_false_size(int doIt);
	void test_cml_CArrayStorage_false_max_size(int doIt);
	void test_cml_CArrayStorage_true_constructor(int doIt);
	void test_cml_CArrayStorage_true_constructor_pData(int doIt);
	void test_cml_CArrayStorage_true_constructor_aData(int doIt);
	void test_cml_CArrayStorage_true_constructor_CArrayStorage_1(int doIt);
	void test_cml_CArrayStorage_true_operator_assign_1(int doIt);
	void test_cml_CArrayStorage_true_operator_assign_2(int doIt);
	void test_cml_CArrayStorage_true_operator_assign_3(int doIt);
	void test_cml_CArrayStorage_true_operator_assign_4(int doIt);
	void test_cml_CArrayStorage_true_attach(int doIt);
	void test_cml_CArrayStorage_true_size(int doIt);
	void test_cml_CArrayStorage_true_max_size(int doIt);
	void test_cml_CArrayStorage_const_true_constructor(int doIt);
	void test_cml_CArrayStorage_const_true_attach(int doIt);
	void test_cml_CArrayStorage_const_true_constructor_pData( int doIt );
	void test_cml_CArrayStorage_const_true_constructor_aData_1( int doIt );
	void test_cml_CArrayStorage_const_true_constructor_aData_2( int doIt );
	void test_cml_CArrayStorage_const_true_constructor_CArrayStorage_1( int doIt );
	void test_cml_CArrayStorage_const_true_constructor_CArrayStorage_2( int doIt );
	void test_cml_CArrayStorage_const_true_operator_at( int doIt );
	void test_cml_CArrayStorage_const_true_size( int doIt );
	void test_cml_CArrayStorage_const_true_max_size( int doIt );


	void test_cml_CArray_false_constructor(int doIt);
	void test_cml_CArray_false_constructor_pData(int doIt);
	void test_cml_CArray_false_constructor_pcData(int doIt);
	void test_cml_CArray_false_constructor_aData( int doIt );
	void test_cml_CArray_false_constructor_acData( int doIt );
	void test_cml_CArray_false_constructor_CArray( int doIt );
	void test_cml_CArray_false_constructor_CArrayStorage_1( int doIt );
	void test_cml_CArray_false_constructor_CArrayStorage_2( int doIt );
	void test_cml_CArray_false_operator_assign_1( int doIt );
	void test_cml_CArray_false_operator_assign_2( int doIt );
	void test_cml_CArray_false_operator_assign_3( int doIt );
	void test_cml_CArray_false_at_1( int doIt );
	void test_cml_CArray_false_at_2( int doIt );
	void test_cml_CArray_false_front_1( int doIt );
	void test_cml_CArray_false_front_2( int doIt );
	void test_cml_CArray_false_back_1( int doIt );
	void test_cml_CArray_false_back_2( int doIt );
	void test_cml_CArray_false_fill( int doIt );
	void test_cml_CArray_false_begin_1( int doIt );
	void test_cml_CArray_false_begin_2( int doIt );
	void test_cml_CArray_false_begin_3( int doIt );
	void test_cml_CArray_false_end_1( int doIt );
	void test_cml_CArray_false_end_2( int doIt );
	void test_cml_CArray_false_end_3( int doIt );
};

/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_stl_array(void)
{
	TEST_CLASS_ARRAY test_object;

	std::cout << "******** Start Testing: Array Library functions ********\n\n";
	fprintf(fpTest, "******** Start Testing: Array Library functions ********\n\n");

	test_object.run_tests_array();

	std::cout << "End of Testing: Array Library functions\n\n";
	fprintf(fpTest, "End of Testing: Array Library functions\n\n");

	return ;
}

/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/

void TEST_CLASS_ARRAY::run_tests_array()
{
	//test_cml_CArrayStorage_false_constructor(1);
	//test_cml_CArrayStorage_false_constructor_aData(1);
	//test_cml_CArrayStorage_false_constructor_CArrayStorage_1(1);
	//test_cml_CArrayStorage_false_constructor_CArrayStorage_2(1);
	//test_cml_CArrayStorage_false_constructor_CArrayStorage_3(1);
	test_cml_CArrayStorage_false_operator_at_1(1);
	test_cml_CArrayStorage_false_operator_at_2(1);
	test_cml_CArrayStorage_false_size(1);
	test_cml_CArrayStorage_false_max_size(1);

	//test_cml_CArrayStorage_true_constructor(1);
	//test_cml_CArrayStorage_true_constructor_pData(1);
	//test_cml_CArrayStorage_true_constructor_aData(1);
	//test_cml_CArrayStorage_true_constructor_CArrayStorage_1(1);
	test_cml_CArrayStorage_true_operator_assign_1(1);
	test_cml_CArrayStorage_true_operator_assign_2(1);
	test_cml_CArrayStorage_true_operator_assign_3(1);
	test_cml_CArrayStorage_true_operator_assign_4(1);
	test_cml_CArrayStorage_true_attach(1);
	//test_cml_CArrayStorage_true_size(1);
	//test_cml_CArrayStorage_true_max_size(1);

	//test_cml_CArrayStorage_const_true_constructor(1);
	test_cml_CArrayStorage_const_true_attach(1);
	//test_cml_CArrayStorage_const_true_constructor_pData(1);
	//test_cml_CArrayStorage_const_true_constructor_aData_1(1);
	//test_cml_CArrayStorage_const_true_constructor_aData_2(1);
	//test_cml_CArrayStorage_const_true_constructor_CArrayStorage_1(1);
	//test_cml_CArrayStorage_const_true_constructor_CArrayStorage_2(1);
	//test_cml_CArrayStorage_const_true_operator_at(1);
	//test_cml_CArrayStorage_const_true_size(1);
	//test_cml_CArrayStorage_const_true_max_size(1);

	//test_cml_CArray_false_constructor(1);
	//test_cml_CArray_false_constructor_pData(1);
	//test_cml_CArray_false_constructor_pcData(1);
	//test_cml_CArray_false_constructor_aData(1);
	//test_cml_CArray_false_constructor_acData(1);
	//test_cml_CArray_false_constructor_CArray(1);
	//test_cml_CArray_false_constructor_CArrayStorage_1(1);
	//test_cml_CArray_false_constructor_CArrayStorage_2(1);
	test_cml_CArray_false_operator_assign_1(1);
	test_cml_CArray_false_operator_assign_2(1);
	test_cml_CArray_false_operator_assign_3(1);
	test_cml_CArray_false_at_1(1);
	test_cml_CArray_false_at_2(1);
	test_cml_CArray_false_front_1(1);
	test_cml_CArray_false_front_2(1);
	test_cml_CArray_false_back_1(1);
	test_cml_CArray_false_back_2(1);
	test_cml_CArray_false_fill(1);
	test_cml_CArray_false_begin_1(1);
	test_cml_CArray_false_begin_2(1);
	test_cml_CArray_false_begin_3(1);
	test_cml_CArray_false_end_1(1);
	test_cml_CArray_false_end_2(1);
	test_cml_CArray_false_end_3(1);


}
/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/

/******************************************************

Tests for CArrayStorage
EXT_MEM = fales

*******************************************************/
#if 0
void TEST_CLASS_ARRAY::test_cml_CArrayStorage_false_constructor( int doIt )
{
	if (doIt) 
	{
		START_TEST("Test_cml_CArrayStorage<float, 10, false>_constructor_001",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage() \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CArrayStorage object is generated with the right size. Data can be written");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<float ,10, false> TestArray;

		/* Test case checks */
		CHECK(TestArray.size(),10);
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("Test_cml_CArrayStorage<sint32, 10, false>_constructor_002",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage() \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CArrayStorage object is generated with the right size. Data can be written");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<sint32 ,10, false> TestArray;

		/* Test case checks */
		CHECK(TestArray.size(),10);
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("Test_cml_CArrayStorage<short, 10, false>_constructor_003",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage() \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CArrayStorage object is generated with the right size. Data can be written");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<short ,10, false> TestArray;

		/* Test case checks */
		CHECK(TestArray.size(),10);
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
		
		START_TEST("Test_cml_CArrayStorage<char, 10, false>_constructor_004",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage() \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CArrayStorage object is generated with the right size. Data can be written");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<char ,10, false> TestArray;

		/* Test case checks */
		CHECK(TestArray.size(),10);
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_ARRAY::test_cml_CArrayStorage_false_constructor_aData( int doIt )
{
	if (doIt) 
	{
		START_TEST("Test_cml_CArrayStorage<char, 10, false>_constructor( data[] )_001",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( data[] ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CArrayStorage object is generated with the right size. Data can be written");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<char ,10, false> TestArray( TEST_acData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, TEST_acData123, sizeof(TestArray));
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("Test_cml_CArrayStorage<char, 10, false>_constructor( data[] )_002",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( data[] ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CArrayStorage object is generated with the right size. Data can be written");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<int ,10, false> TestArray( TEST_aiData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, TEST_aiData123, sizeof(TestArray));
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("Test_cml_CArrayStorage<char, 10, false>_constructor( data[] )_003",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( data[] ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CArrayStorage object is generated with the right size. Data can be written");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<float ,10, false> TestArray( TEST_afData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, TEST_afData123, sizeof(TestArray));
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_ARRAY::test_cml_CArrayStorage_false_constructor_CArrayStorage_1( int doIt )
{
	if (doIt) 
	{
		START_TEST("Test_cml_CArrayStorage<char, 10, false>_constructor( CArrayStorage )_001",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( CArrayStorage ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CArrayStorage object is generated with the right size. Data can be written");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<char ,10, false> TestArray2( TEST_acData123 );
		cml::CArrayStorage<char ,10, false> TestArray( TestArray2 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray2, sizeof(TestArray));
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("Test_cml_CArrayStorage<char, 10, false>_constructor( CArrayStorage )_002",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( CArrayStorage ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CArrayStorage object is generated with the right size. Data can be written");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<int ,10, false> TestArray2( TEST_aiData123 );
		cml::CArrayStorage<int ,10, false> TestArray( TestArray2 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray2, sizeof(TestArray));
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("Test_cml_CArrayStorage<char, 10, false>_constructor( CArrayStorage )_003",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( CArrayStorage ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CArrayStorage object is generated with the right size. Data can be written");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<float ,10, false> TestArray2( TEST_afData123 );
		cml::CArrayStorage<float ,10, false> TestArray( TestArray2 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray2, sizeof(TestArray));
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_ARRAY::test_cml_CArrayStorage_false_constructor_CArrayStorage_2( int doIt )
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArrayStorage<char, 10, false>_constructor( CArrayStorage< true > )_001",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( CArrayStorage< true > ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CArrayStorage object is generated with the right size. Data can be written");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<char ,10, false> TestArray2( TEST_acData123 );
		cml::CArrayStorage<char ,10, false> TestArray( TestArray2 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray2, sizeof(TestArray));
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<char, 10, false>_constructor( CArrayStorage< true > )_002",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( CArrayStorage< true > ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CArrayStorage object is generated with the right size. Data can be written");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<int ,10, false> TestArray2( TEST_aiData123 );
		cml::CArrayStorage<int ,10, false> TestArray( TestArray2 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray2, sizeof(TestArray));
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<char, 10, false>_constructor( CArrayStorage< true > )_003",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( CArrayStorage< true > ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CArrayStorage object is generated with the right size. Data can be written");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<float ,10, false> TestArray2( TEST_afData123 );
		cml::CArrayStorage<float ,10, false> TestArray( TestArray2 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray2, sizeof(TestArray));
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}


void TEST_CLASS_ARRAY::test_cml_CArrayStorage_false_constructor_CArrayStorage_3( int doIt )
{
	if (doIt) 
	{
		START_TEST("Test_cml_CArrayStorage<char, 100, false>_constructor( CArrayStorage< const > )_001",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( CArrayStorage< const > ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CArrayStorage object is generated with the right size. Data can be written");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<char ,10, false> TestArray2( TEST_acData123 );
		cml::CArrayStorage<char ,10, false> TestArray( TestArray2 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray2, sizeof(TestArray));
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("Test_cml_CArrayStorage<char, 100, false>_constructor( CArrayStorage< const > )_002",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( CArrayStorage< const > ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CArrayStorage object is generated with the right size. Data can be written");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<int ,10, false> TestArray2( TEST_aiData123 );
		cml::CArrayStorage<int ,10, false> TestArray( TestArray2 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray2, sizeof(TestArray));
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("Test_cml_CArrayStorage<char, 100, false>_constructor( CArrayStorage< const > )_003",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( CArrayStorage< const > ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CArrayStorage object is generated with the right size. Data can be written");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<float ,10, false> TestArray2( TEST_afData123 );
		cml::CArrayStorage<float ,10, false> TestArray( TestArray2 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray2, sizeof(TestArray));
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}
#endif

void TEST_CLASS_ARRAY::test_cml_CArrayStorage_false_operator_at_1( int doIt )
{
	std::cout << "START ---> test_cml_CArrayStorage_false_operator_at_1\n\n";		
	fprintf(fpTest, "START ---> test_cml_CArrayStorage_false_operator_at_1\n\n");

	fprintf(fpTest, "Function Name ---> operator[] \n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_cml_CArrayStorage_false_operator_at_1_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_false_operator_at_1_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		char i8Value;
		char expected_i8Value = (char)1;
		cml::CArrayStorage<char ,10, false> TestArray( TEST_acData123 );
				
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
				
		/* Call SUT */
		i8Value = TestArray[0];

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\nActual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
		std::cout << "Test Case ---> test_cml_CArrayStorage_false_operator_at_1_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_false_operator_at_1_002\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		int i8Value;
		int expected_i8Value = 1;
		cml::CArrayStorage<int ,10, false> TestArray( TEST_aiData123 );
		
		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		i8Value = TestArray[0];

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\nActual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_false_operator_at_1_002\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArrayStorage_false_operator_at_1_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_false_operator_at_1_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		float i8Value;
		float expected_i8Value = 1;
		cml::CArrayStorage<float ,10, false> TestArray( TEST_afData123 );

		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		i8Value = TestArray[0];

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\nActual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);
		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_false_operator_at_1_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArrayStorage_false_operator_at_1\n\n";
	fprintf(fpTest, "END ---> test_cml_CArrayStorage_false_operator_at_1\n\n");
}

void TEST_CLASS_ARRAY::test_cml_CArrayStorage_false_operator_at_2( int doIt )
{
	std::cout << "START ---> test_cml_CArrayStorage_false_operator_at_2\n\n";		
	fprintf(fpTest, "START ---> test_cml_CArrayStorage_false_operator_at_2\n\n");

	fprintf(fpTest, "Function Name ---> operator[]const \n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_cml_CArrayStorage_false_operator_at_2_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_false_operator_at_2_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
		/* Test case data declarations */
		char i8Value;
		char expected_i8Value = (char)1;
		const cml::CArrayStorage<char ,10, false> TestArray( TEST_acData123 );
				
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
				
		/* Call SUT */
		i8Value = TestArray[0];

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\nActual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
		std::cout << "Test Case ---> test_cml_CArrayStorage_false_operator_at_2_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_false_operator_at_2_002\n\n");
				
		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
		/* Test case data declarations */
		int i8Value;
		int expected_i8Value = 1;
		const cml::CArrayStorage<int ,10, false> TestArray( TEST_aiData123 );
		
		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
				
		/* Call SUT */
		i8Value = TestArray[0];

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\nActual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
		std::cout << "Test Case ---> test_cml_CArrayStorage_false_operator_at_2_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_false_operator_at_2_003\n\n");
				
		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
		/* Test case data declarations */
		float i8Value;
		float expected_i8Value = 1;
		const cml::CArrayStorage<float ,10, false> TestArray( TEST_afData123 );

		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
				
		/* Call SUT */
		i8Value = TestArray[0];

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\nActual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);
		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
	std::cout << "END ---> test_cml_CArrayStorage_false_operator_at_2\n\n";
	fprintf(fpTest, "END ---> test_cml_CArrayStorage_false_operator_at_2\n\n");
}

void TEST_CLASS_ARRAY::test_cml_CArrayStorage_false_size( int doIt )
{
		std::cout << "START ---> test_cml_CArrayStorage_false_size\n\n";		
		fprintf(fpTest, "START ---> test_cml_CArrayStorage_false_size\n\n");

		fprintf(fpTest, "Function Name ---> size() \n\n");

		if (doIt) {

		{
		std::cout << "Test Case --->test_cml_CArrayStorage_false_size_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_false_size_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
			
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<char ,10, false> TestArray( TEST_acData123 );
		sint32 size, expected_size = 10;
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_size);
		check__PrintValue_to_File(expected_size, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		size = TestArray.size();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console(size);
		check__PrintValue_to_File(size, fpTest);
		fprintf(fpTest, "\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( size,expected_size);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_false_size001\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArrayStorage_false_size_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_false_size_002\n\n");


		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
			
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<int ,10, false> TestArray( TEST_aiData123 );
		sint32 size, expected_size = 10;
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_size);
		check__PrintValue_to_File(expected_size, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		size = TestArray.size();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console(size);
		check__PrintValue_to_File(size, fpTest);
		fprintf(fpTest, "\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( size,expected_size);
		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		
		std::cout << "END ---> test_cml_CArrayStorage_false_size_002\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArrayStorage_false_size_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_false_size_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
			
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<float ,10, false> TestArray( TEST_afData123 );
		sint32 size, expected_size = 10;
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float,10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_size);
		check__PrintValue_to_File(expected_size, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		size = TestArray.size();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console(size);
		check__PrintValue_to_File(size, fpTest);
		fprintf(fpTest, "\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( size,expected_size);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "END ---> test_cml_CArrayStorage_false_size_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArrayStorage_false_size\n\n";
	fprintf(fpTest, "END ---> test_cml_CArrayStorage_false_size\n\n");
}

void TEST_CLASS_ARRAY::test_cml_CArrayStorage_false_max_size( int doIt )
{
	std::cout << "START ---> test_cml_CArrayStorage_false_max_size\n\n";		
	fprintf(fpTest, "START ---> test_cml_CArrayStorage_false_max_size\n\n");

	fprintf(fpTest, "Function Name ---> max_size() \n\n");

	if (doIt) {

		{
		std::cout << "Test Case --->test_cml_CArrayStorage_false_max_size_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_false_max_size_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
			
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<char ,10, false> TestArray( TEST_acData123 );
		sint32 size, expected_size = 10;
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_size);
		check__PrintValue_to_File(expected_size, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		size = TestArray.max_size();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console(size);
		check__PrintValue_to_File(size, fpTest);
		fprintf(fpTest, "\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;


		/* Checks on global data */			
		returnValue = check__boCompare( size,expected_size);
		
		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_false_max_size001\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArrayStorage_false_max_size_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_false_max_size_002\n\n");


		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
			
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<int ,10, false> TestArray( TEST_aiData123 );
		sint32 size, expected_size = 10;
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_size);
		check__PrintValue_to_File(expected_size, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		size = TestArray.max_size();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console(size);
		check__PrintValue_to_File(size, fpTest);
		fprintf(fpTest, "\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( size,expected_size);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		
		std::cout << "END ---> test_cml_CArrayStorage_false_max_size_002\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArrayStorage_false_max_size_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_false_max_size_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
			
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<float ,10, false> TestArray( TEST_afData123 );
		sint32 size, expected_size = 10;
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float,10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_size);
		check__PrintValue_to_File(expected_size, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		size = TestArray.max_size();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console(size);
		check__PrintValue_to_File(size, fpTest);
		fprintf(fpTest, "\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( size,expected_size);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "END ---> test_cml_CArrayStorage_false_max_size_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArrayStorage_false_max_size\n\n";
	fprintf(fpTest, "END ---> test_cml_CArrayStorage_false_max_size\n\n");
}

#if 0
void TEST_CLASS_ARRAY::test_cml_CArrayStorage_false_max_size( int doIt )
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArrayStorage<char, 10, false>_max_size()_001",
			"Description: \
			- cml_stl_array.h : CArrayStorage::max_size() \
			- Testing: interface \
			- Overview: verify that the size() function works properly \
			- Entry conditions: - \
			- Expected results: The right size is given back.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("{_wassert#replace}");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArrayStorage<char ,10, false> TestArray( TEST_acData123 );

		/* Call SUT */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<char, 10, false>_max_size()_002",
			"Description: \
			- cml_stl_array.h : CArrayStorage::max_size() \
			- Testing: interface \
			- Overview: verify that the size() function works properly \
			- Entry conditions: - \
			- Expected results: The right size is given back.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("{_wassert#replace}");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArrayStorage<int ,10, false> TestArray( TEST_aiData123 );

		/* Call SUT */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<char, 10, false>_max_size()_003",
			"Description: \
			- cml_stl_array.h : CArrayStorage::max_size() \
			- Testing: interface \
			- Overview: verify that the size() function works properly \
			- Entry conditions: - \
			- Expected results: The right size is given back.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("{_wassert#replace}");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArrayStorage<float ,10, false> TestArray( TEST_afData123 );

		/* Call SUT */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_ARRAY::test_cml_CArrayStorage_true_constructor( int doIt )
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArrayStorage<char, 10, true>_constructor_001",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage() \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can not be written, because of there is no storage. ");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<char ,10, true> TestArray;
		cml::CArrayStorage<char ,10, true> TestArray1 = TestArray;

		/* Test case checks */
		CHECK(TestArray.size(), 10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray1, sizeof(TEST_acData123));

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<char, 10, true>_constructor_002",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage() \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can not be written, because of there is no storage. ");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<int ,10, true> TestArray;

		/* Test case checks */

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<char, 10, true>_constructor_003",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage() \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can not be written, because of there is no storage. ");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<float ,10, true> TestArray;

		/* Test case checks */

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_ARRAY::test_cml_CArrayStorage_true_constructor_pData( int doIt )
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArrayStorage<char, 10, true>_constructor( pData )_001",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( pData ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be written \
			- org. data changed ");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		/* Call SUT */
		cml::CArrayStorage<char ,10, true> TestArray(TEST_acData123);

		/* Test case checks */
		CHECK(TestArray.size(),10);
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<char, 10, true>_constructor( pData )_002",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( pData ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be written \
			- org. data changed ");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		/* Call SUT */
		cml::CArrayStorage<int ,10, true> TestArray(TEST_aiData123);

		/* Test case checks */
		CHECK(TestArray.size(),10);
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<char, 10, true>_constructor( pData )_003",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( pData ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be written \
			- org. data changed ");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		/* Call SUT */
		cml::CArrayStorage<float ,10, true> TestArray(TEST_afData123);

		/* Test case checks */
		CHECK(TestArray.size(),10);
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_ARRAY::test_cml_CArrayStorage_true_constructor_aData( int doIt )
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArrayStorage<char, 10, true>_constructor( data[])_001",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( data[] ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be written \
			- org. data changed ");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<char ,10, true> TestArray( TEST_acData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<char, 10, true>_constructor( data[])_002",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( data[] ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be written \
			- org. data changed ");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<int ,10, true> TestArray(TEST_aiData123);

		/* Test case checks */
		CHECK(TestArray.size(),10);
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<char, 10, true>_constructor( data[])_003",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( data[] ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be written \
			- org. data changed ");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<float ,10, true> TestArray( TEST_afData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_ARRAY::test_cml_CArrayStorage_true_constructor_CArrayStorage_1( int doIt )
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArrayStorage<char, 10, true>_constructor( CArrayStorage )_001",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( CArrayStorage ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be written \
			- org. CArrayStorage is changed.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<char ,10, true> TestArray( TEST_acData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<char, 10, true>_constructor( CArrayStorage )_002",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( CArrayStorage ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be written \
			- org. CArrayStorage is changed.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<int ,10, true> TestArray( TEST_aiData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<char, 10, true>_constructor( CArrayStorage )_003",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( CArrayStorage ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be written \
			- org. CArrayStorage is changed.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<float ,10, true> TestArray( TEST_afData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}
#endif
void TEST_CLASS_ARRAY::test_cml_CArrayStorage_true_operator_assign_1( int doIt )
{
		std::cout << "START ---> test_cml_CArrayStorage_true_operator_assign_1\n\n";		
		fprintf(fpTest, "START ---> test_cml_CArrayStorage_true_operator_assign_1\n\n");

		fprintf(fpTest, "Function Name ---> operator=(data[])  \n\n");

	if (doIt) {

		{
		std::cout << "Test Case --->test_cml_CArrayStorage_true_operator_assign_1_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_true_operator_assign_1_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArrayStorage<char ,10, true> TestArray(TEST_acData_Zero);
		cml::CArrayStorage<char ,10, true> expected_TestArray(TEST_acData123);
		cml::CArrayStorage<char ,10, true> TestArray1(TEST_acData123);
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, true >( TestArray);
		check__vArrayPrint_to_File< char, 10, true >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console< char, 10, true >( expected_TestArray);
		check__vArrayPrint_to_File< char, 10, true >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		TestArray = TestArray1;

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< char, 10, true >( TestArray);
		check__vArrayPrint_to_File< char, 10, true >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,TestArray1);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_true_operator_assign_1_001\n\n";
		}

		{
		std::cout << "Test Case --->test_cml_CArrayStorage_true_operator_assign_1_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_true_operator_assign_1_002\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArrayStorage<int ,10, true> TestArray(TEST_aiData_Zero);
		cml::CArrayStorage<int ,10, true> expected_TestArray(TEST_aiData123);
		cml::CArrayStorage<int ,10, true> TestArray1(TEST_aiData123);
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, true >( TestArray);
		check__vArrayPrint_to_File< int, 10, true >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console< int, 10, true >( expected_TestArray);
		check__vArrayPrint_to_File< int, 10, true >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		TestArray = TestArray1;

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< int, 10, true >( TestArray);
		check__vArrayPrint_to_File< int, 10, true >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,TestArray1);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_true_operator_assign_1_002\n\n";
		}
		
		{
		std::cout << "Test Case --->test_cml_CArrayStorage_true_operator_assign_1_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_true_operator_assign_1_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArrayStorage<float ,10, true> TestArray(TEST_afData_Zero);
		cml::CArrayStorage<float ,10, true> expected_TestArray(TEST_afData123);
		cml::CArrayStorage<float ,10, true> TestArray1(TEST_afData123);
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, true >( TestArray);
		check__vArrayPrint_to_File< float, 10, true >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console< float, 10, true >( expected_TestArray);
		check__vArrayPrint_to_File< float, 10, true >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		TestArray = TestArray1;

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< float, 10, true >( TestArray);
		check__vArrayPrint_to_File< float, 10, true >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,TestArray1);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_true_operator_assign_1_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArrayStorage_true_operator_assign_1\n\n";
	fprintf(fpTest, "END ---> test_cml_CArrayStorage_true_operator_assign_1\n\n");
}

void TEST_CLASS_ARRAY::test_cml_CArrayStorage_true_operator_assign_2( int doIt )
{
		std::cout << "START ---> test_cml_CArrayStorage_true_operator_assign_2\n\n";		
		fprintf(fpTest, "START ---> test_cml_CArrayStorage_true_operator_assign_2\n\n");

		fprintf(fpTest, "Function Name ---> operator=(data[])  \n\n");

	if (doIt) {

		{
		std::cout << "Test Case --->test_cml_CArrayStorage_true_operator_assign_2_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_true_operator_assign_2_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArrayStorage<char ,10, true> TestArray(TEST_acData_Zero);
		cml::CArrayStorage<const char ,10, true> expected_TestArray(TEST_acData123_const);
		cml::CArrayStorage<const char ,10, true> TestArray1(TEST_acData123_const);
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, true >( TestArray);
		check__vArrayPrint_to_File< char, 10, true >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console<const char, 10, true >( expected_TestArray);
		check__vArrayPrint_to_File<const char, 10, true >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		TestArray = TestArray1;

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< char, 10, true >( TestArray);
		check__vArrayPrint_to_File< char, 10, true >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,TestArray1);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_true_operator_assign_2_001\n\n";
		}

		{
		std::cout << "Test Case --->test_cml_CArrayStorage_true_operator_assign_2_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_true_operator_assign_2_002\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArrayStorage<int ,10, true> TestArray(TEST_aiData_Zero);
		cml::CArrayStorage<const int ,10, true> expected_TestArray(TEST_aiData123_const);
		cml::CArrayStorage<const int ,10, true> TestArray1(TEST_aiData123_const);
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, true >( TestArray);
		check__vArrayPrint_to_File< int, 10, true >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console<const int, 10, true >( expected_TestArray);
		check__vArrayPrint_to_File<const int, 10, true >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		TestArray = TestArray1;

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< int, 10, true >( TestArray);
		check__vArrayPrint_to_File< int, 10, true >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,TestArray1);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_true_operator_assign_2_002\n\n";
		}
		
		{
		std::cout << "Test Case --->test_cml_CArrayStorage_true_operator_assign_2_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_true_operator_assign_2_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArrayStorage<float ,10, true> TestArray(TEST_afData_Zero);
		cml::CArrayStorage<const float ,10, true> expected_TestArray(TEST_afData123_const);
		cml::CArrayStorage<const float ,10, true> TestArray1(TEST_afData123_const);
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, true >( TestArray);
		check__vArrayPrint_to_File< float, 10, true >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console<const float, 10, true >( expected_TestArray);
		check__vArrayPrint_to_File<const float, 10, true >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		TestArray = TestArray1;

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< float, 10, true >( TestArray);
		check__vArrayPrint_to_File< float, 10, true >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,TestArray1);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_true_operator_assign_2_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArrayStorage_true_operator_assign_2\n\n";
	fprintf(fpTest, "END ---> test_cml_CArrayStorage_true_operator_assign_2\n\n");
}

void TEST_CLASS_ARRAY::test_cml_CArrayStorage_true_operator_assign_3( int doIt )
{
	std::cout << "START ---> test_cml_CArrayStorage_true_operator_assign_3\n\n";		
	fprintf(fpTest, "START ---> test_cml_CArrayStorage_true_operator_assign_3\n\n");

	fprintf(fpTest, "Function Name ---> operator[](const size_type position) \n\n");

	if (doIt) {
	
		{
		std::cout << "Test Case ---> test_cml_CArrayStorage_true_operator_assign_3_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_true_operator_assign_3_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		char i8Value;
		char expected_i8Value = (char)1;
		cml::CArrayStorage<char ,10, true> TestArray( TEST_acData123 );
				
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, true >( TestArray);
		check__vArrayPrint_to_File< char, 10, true >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
				
		/* Call SUT */
		i8Value = TestArray[0];

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_true_operator_assign_3_001\n\n";
		}
	
		{
		std::cout << "Test Case ---> test_cml_CArrayStorage_true_operator_assign_3_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_true_operator_assign_3_002\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		int i8Value;
		int expected_i8Value = 1;
		cml::CArrayStorage<int ,10, true> TestArray( TEST_aiData123 );
		
		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, true >( TestArray);
		check__vArrayPrint_to_File< int, 10, true >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		i8Value = TestArray[0];

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_true_operator_assign_3_002\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArrayStorage_true_operator_assign_3_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_true_operator_assign_3_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		float i8Value;
		float expected_i8Value = 1;
		cml::CArrayStorage<float ,10, true> TestArray( TEST_afData123 );

		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, true >( TestArray);
		check__vArrayPrint_to_File< float, 10, true >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		i8Value = TestArray[0];

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);
		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_true_operator_assign_3_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArrayStorage_true_operator_assign_3\n\n";
	fprintf(fpTest, "END ---> test_cml_CArrayStorage_true_operator_assign_3\n\n");
}

void TEST_CLASS_ARRAY::test_cml_CArrayStorage_true_operator_assign_4( int doIt )
{
	std::cout << "START ---> test_cml_CArrayStorage_true_operator_assign_4\n\n";		
	fprintf(fpTest, "START ---> test_cml_CArrayStorage_true_operator_assign_4\n\n");

	fprintf(fpTest, "Function Name ---> operator[]()const \n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_cml_CArrayStorage_true_operator_assign_4_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_true_operator_assign_4_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
		/* Test case data declarations */
		char i8Value;
		char expected_i8Value = (char)1;
		const cml::CArrayStorage<char ,10, true> TestArray( TEST_acData123 );
				
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, true >( TestArray);
		check__vArrayPrint_to_File< char, 10, true >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
				
		/* Call SUT */
		i8Value = TestArray[0];

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_true_operator_assign_4_001\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArrayStorage_true_operator_assign_4_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_true_operator_assign_4_002\n\n");
				
		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
		/* Test case data declarations */
		int i8Value;
		int expected_i8Value = 1;
		const cml::CArrayStorage<int ,10, true> TestArray( TEST_aiData123 );
		
		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, true >( TestArray);
		check__vArrayPrint_to_File< int, 10, true >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
				
		/* Call SUT */
		i8Value = TestArray[0];

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_true_operator_assign_4_002\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArrayStorage_true_operator_assign_4_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_true_operator_assign_4_003\n\n");
				
		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
		/* Test case data declarations */
		float i8Value;
		float expected_i8Value = 1;
		const cml::CArrayStorage<float ,10, true> TestArray( TEST_afData123 );

		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, true >( TestArray);
		check__vArrayPrint_to_File< float, 10, true >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
				
		/* Call SUT */
		i8Value = TestArray[0];

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);
		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_true_operator_assign_4_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArrayStorage_true_operator_assign_4\n\n";
	fprintf(fpTest, "END ---> test_cml_CArrayStorage_true_operator_assign_4\n\n");
}

void TEST_CLASS_ARRAY::test_cml_CArrayStorage_true_attach( int doIt )
{
		std::cout << "START ---> test_cml_CArrayStorage_true_attach\n\n";		
		fprintf(fpTest, "START ---> test_cml_CArrayStorage_true_attach\n\n");

		fprintf(fpTest, "Function Name ---> attach()  \n\n");

	if (doIt) {

		{
		std::cout << "Test Case --->test_cml_CArrayStorage_true_attach_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_true_attach_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArrayStorage<char ,10, true> TestArray;//(TEST_acData_Zero);
		cml::CArrayStorage<char ,10, true> expected_TestArray(TEST_acData123);
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		//check__vArrayPrint_to_console< char, 10, true >( TestArray);
		//check__vArrayPrint_to_File< char, 10, true >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console< char, 10, true >( expected_TestArray);
		check__vArrayPrint_to_File< char, 10, true >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestArray.attach( TEST_acData123, 10 );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< char, 10, true >( TestArray);
		check__vArrayPrint_to_File< char, 10, true >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,expected_TestArray);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_true_attach_001\n\n";
		}

		{
		std::cout << "Test Case --->test_cml_CArrayStorage_true_attach_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_true_attach_002\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArrayStorage<int ,10, true> TestArray;//(TEST_aiData_Zero);
		cml::CArrayStorage<int ,10, true> expected_TestArray(TEST_aiData123);
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		//check__vArrayPrint_to_console< int, 10, true >( TestArray);
		//check__vArrayPrint_to_File< int, 10, true >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console< int, 10, true >( expected_TestArray);
		check__vArrayPrint_to_File< int, 10, true >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestArray.attach( TEST_aiData123, 10 );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< int, 10, true >( TestArray);
		check__vArrayPrint_to_File< int, 10, true >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,expected_TestArray);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_true_attach_002\n\n";
		}

		{
		std::cout << "Test Case --->test_cml_CArrayStorage_true_attach_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_true_attach_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArrayStorage<float ,10, true> TestArray;//(TEST_afData_Zero);
		cml::CArrayStorage<float ,10, true> expected_TestArray(TEST_afData123);
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		//check__vArrayPrint_to_console< float, 10, true >( TestArray);
		//check__vArrayPrint_to_File< float, 10, true >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console< float, 10, true >( expected_TestArray);
		check__vArrayPrint_to_File< float, 10, true >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestArray.attach( TEST_afData123, 10 );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< float, 10, true >( TestArray);
		check__vArrayPrint_to_File< float, 10, true >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,expected_TestArray);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_true_attach_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArrayStorage_true_attach\n\n";
	fprintf(fpTest, "END ---> test_cml_CArrayStorage_true_attach\n\n");
}

#if 0
void TEST_CLASS_ARRAY::test_cml_CArrayStorage_true_size( int doIt )
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArrayStorage<char, 10, true>_size()_001",
			"Description: \
			- cml_stl_array.h : CArrayStorage::size() \
			- Testing: interface \
			- Overview: verify that the size() function works properly \
			- Entry conditions: - \
			- Expected results: The right size is given back.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("{_wassert#replace}");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArrayStorage<char ,10, true> TestArray(TEST_acData123);

		/* Call SUT */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<char, 10, true>_size()_002",
			"Description: \
			- cml_stl_array.h : CArrayStorage::size() \
			- Testing: interface \
			- Overview: verify that the size() function works properly \
			- Entry conditions: - \
			- Expected results: The right size is given back.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("{_wassert#replace}");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArrayStorage<int ,10, true> TestArray(TEST_aiData123);

		/* Call SUT */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<char, 10, true>_size()_003",
			"Description: \
			- cml_stl_array.h : CArrayStorage::size() \
			- Testing: interface \
			- Overview: verify that the size() function works properly \
			- Entry conditions: - \
			- Expected results: The right size is given back.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("{_wassert#replace}");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArrayStorage<float ,10, true> TestArray(TEST_afData123);

		/* Call SUT */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_ARRAY::test_cml_CArrayStorage_true_max_size( int doIt )
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArrayStorage<char, 10, true>_max_size()_001",
			"Description: \
			- cml_stl_array.h : CArrayStorage::max_size() \
			- Testing: interface \
			- Overview: verify that the size() function works properly \
			- Entry conditions: - \
			- Expected results: The right size is given back.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("{_wassert#replace}");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArrayStorage<char ,10, true> TestArray(TEST_acData123);

		/* Call SUT */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<char, 10, true>_max_size()_002",
			"Description: \
			- cml_stl_array.h : CArrayStorage::max_size() \
			- Testing: interface \
			- Overview: verify that the size() function works properly \
			- Entry conditions: - \
			- Expected results: The right size is given back.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("{_wassert#replace}");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArrayStorage<int ,10, true> TestArray(TEST_aiData123);

		/* Call SUT */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<char, 10, true>_max_size()_003",
			"Description: \
			- cml_stl_array.h : CArrayStorage::max_size() \
			- Testing: interface \
			- Overview: verify that the size() function works properly \
			- Entry conditions: - \
			- Expected results: The right size is given back.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("{_wassert#replace}");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArrayStorage<float ,10, true> TestArray(TEST_afData123);

		/* Call SUT */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}


void TEST_CLASS_ARRAY::test_cml_CArrayStorage_const_true_constructor( int doIt )
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_constructor_001",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage() \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be read \
			- Data can not be read or written.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION

			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<const char ,10, true> TestArray;

		/* Test case checks */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_constructor_002",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage() \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be read \
			- Data can not be read or written.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<const int ,10, true> TestArray;

		/* Test case checks */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_constructor_003",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage() \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be read \
			- Data can not be read or written.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<const float ,10, true> TestArray;

		/* Test case checks */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}
#endif

void TEST_CLASS_ARRAY::test_cml_CArrayStorage_const_true_attach( int doIt )
{
		std::cout << "START ---> test_cml_CArrayStorage_const_true_attach\n\n";		
		fprintf(fpTest, "START ---> test_cml_CArrayStorage_const_true_attach\n\n");

		fprintf(fpTest, "Function Name ---> attach(const)  \n\n");

	if (doIt) {

		{
		std::cout << "Test Case --->test_cml_CArrayStorage_const_true_attach_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_const_true_attach_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArrayStorage<char ,10, true> TestArray;//(TEST_acData_Zero);
		cml::CArrayStorage<const char ,10, true> expected_TestArray(TEST_acData123_const);
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		//check__vArrayPrint_to_console< char, 10, true >( TestArray);
		//check__vArrayPrint_to_File< char, 10, true >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console<const char, 10, true >( expected_TestArray);
		check__vArrayPrint_to_File<const char, 10, true >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestArray.attach( TEST_acData123, 10 );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< char, 10, true >( TestArray);
		check__vArrayPrint_to_File< char, 10, true >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,expected_TestArray);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_const_true_attach_001\n\n";
		}

		{
		std::cout << "Test Case --->test_cml_CArrayStorage_const_true_attach_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_const_true_attach_002\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArrayStorage<int ,10, true> TestArray;//(TEST_aiData_Zero);
		cml::CArrayStorage<const int ,10, true> expected_TestArray(TEST_aiData123_const);
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		//check__vArrayPrint_to_console< int, 10, true >( TestArray);
		//check__vArrayPrint_to_File< int, 10, true >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console<const int, 10, true >( expected_TestArray);
		check__vArrayPrint_to_File<const int, 10, true >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestArray.attach( TEST_aiData123, 10 );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< int, 10, true >( TestArray);
		check__vArrayPrint_to_File< int, 10, true >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,expected_TestArray);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_const_true_attach_002\n\n";
		}

		{
		std::cout << "Test Case --->test_cml_CArrayStorage_const_true_attach_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_const_true_attach_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArrayStorage<float ,10, true> TestArray;//(TEST_afData_Zero);
		cml::CArrayStorage<const float ,10, true> expected_TestArray(TEST_afData123_const);
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		//check__vArrayPrint_to_console< float, 10, true >( TestArray);
		//check__vArrayPrint_to_File< float, 10, true >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console<const float, 10, true >( expected_TestArray);
		check__vArrayPrint_to_File<const float, 10, true >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestArray.attach( TEST_afData123, 10 );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< float, 10, true >( TestArray);
		check__vArrayPrint_to_File< float, 10, true >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,expected_TestArray);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_const_true_attach_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArrayStorage_const_true_attach\n\n";
	fprintf(fpTest, "END ---> test_cml_CArrayStorage_const_true_attach\n\n");
}

#if 0
void TEST_CLASS_ARRAY::test_cml_CArrayStorage_const_true_constructor_pData( int doIt )
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArrayStorage<const char, 100, true>_constructor( pData )_001",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( pData ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be read. \
			- Data can not be written, because of const.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<const char ,10, true> TestArray;
		cml::CArrayStorage<const char ,10, true> TestArray1 = TestArray;

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray1, sizeof(TestArray));

		/*Writing into TestArray not possible, because for const*/
		//check_vFillCArrayStorage( TestArray, TEST_acData9 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_constructor( pData )_002",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( pData ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be read. \
			- Data can not be written, because of const.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<const int ,10, true> TestArray;
		cml::CArrayStorage<const int ,10, true> TestArray1 = TestArray;
		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray1, sizeof(TestArray));

		/*Writing into TestArray not possible, because for const*/
		//check_vFillCArrayStorage( TestArray, TEST_acData9 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_constructor( pData )_003",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( pData ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be read. \
			- Data can not be written, because of const.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<const float ,10, true> TestArray;
		cml::CArrayStorage<const float ,10, true> TestArray1 = TestArray1;
		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray1, sizeof(TestArray));

		/*Writing into TestArray not possible, because for const*/
		//check_vFillCArrayStorage( TestArray, TEST_acData9 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_ARRAY::test_cml_CArrayStorage_const_true_constructor_aData_1( int doIt )
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_constructor( data[] )_001",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( data[] ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be read." );

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<const char ,10, true> TestArray;
		cml::CArrayStorage<const char ,10, true> TestArray1 = TestArray1;

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray1, sizeof(TestArray));

		/*Writing into TestArray not possible, because for const*/
		//check_vFillCArrayStorage( TestArray, TEST_acData9 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_constructor( data[] )_002",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( data[] ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be read." );

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<const int ,10, true> TestArray;
		cml::CArrayStorage<const int ,10, true> TestArray1 = TestArray;

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray1, sizeof(TestArray));

		/*Writing into TestArray not possible, because for const*/
		//check_vFillCArrayStorage( TestArray, TEST_acData9 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_constructor( data[] )_003",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( data[] ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be read." );

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<const float ,10, true> TestArray;
		cml::CArrayStorage<const float ,10, true> TestArray1 = TestArray1;

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray1, sizeof(TestArray));

		/*Writing into TestArray not possible, because for const*/
		//check_vFillCArrayStorage( TestArray, TEST_acData9 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_ARRAY::test_cml_CArrayStorage_const_true_constructor_aData_2( int doIt )
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_constructor( const data[] )_001",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( const data[] ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be read.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<const char ,10, true> TestArray;
		cml::CArrayStorage<const char ,10, true> TestArray1 = TestArray1;
		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray1, sizeof(TestArray));

		/*Writing into TestArray not possible, because for const*/
		//check_vFillCArrayStorage( TestArray, TEST_acData9 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_constructor( const data[] )_002",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( const data[] ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be read.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<const int ,10, true> TestArray;
		cml::CArrayStorage<const int ,10, true> TestArray1 = TestArray;
		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray1, sizeof(TestArray));

		/*Writing into TestArray not possible, because for const*/
		//check_vFillCArrayStorage( TestArray, TEST_acData9 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_constructor( const data[] )_003",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( const data[] ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be read.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<const float ,10, true> TestArray;
		cml::CArrayStorage<const float ,10, true> TestArray1 = TestArray1;
		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray1, sizeof(TestArray));

		/*Writing into TestArray not possible, because for const*/
		//check_vFillCArrayStorage( TestArray, TEST_acData9 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}


void TEST_CLASS_ARRAY::test_cml_CArrayStorage_const_true_constructor_CArrayStorage_1( int doIt )
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_constructor( CArrayStorage )_001",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( CArrayStorage ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. ");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		char acData[100];

		/* Call SUT */
		const cml::CArrayStorage<const char ,10, true> TestArray2( acData );
		cml::CArrayStorage<const char ,10, true> TestArray( TestArray2 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray2, sizeof(TestArray));

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_constructor( CArrayStorage )_002",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( CArrayStorage ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. ");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		int acData[100];

		/* Call SUT */
		const cml::CArrayStorage<const int ,10, true> TestArray2( acData );
		cml::CArrayStorage<const int ,10, true> TestArray( TestArray2 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray2, sizeof(TestArray));

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_constructor( CArrayStorage )_003",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( CArrayStorage ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. ");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		float acData[100];

		/* Call SUT */
		const cml::CArrayStorage<const float ,10, true> TestArray2( acData );
		cml::CArrayStorage<const float ,10, true> TestArray( TestArray2 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray2, sizeof(TestArray));

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}


void TEST_CLASS_ARRAY::test_cml_CArrayStorage_const_true_constructor_CArrayStorage_2( int doIt )
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_constructor( CArrayStorage< true > )_001",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( CArrayStorage< false > ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be written \
			- org. CArrayStorage is changed.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<      char ,10, true> TestArray2( TEST_acData123 );
		cml::CArrayStorage<const char ,10, true> TestArray( TestArray2 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray2, sizeof(TestArray));

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_constructor( CArrayStorage< true > )_002",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( CArrayStorage< false > ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be written \
			- org. CArrayStorage is changed.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<      int ,10, true> TestArray2( TEST_aiData123 );
		cml::CArrayStorage<const int ,10, true> TestArray( TestArray2 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray2, sizeof(TestArray));

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_constructor( CArrayStorage< true > )_003",
			"Description: \
			- cml_stl_array.h : CArrayStorage::CArrayStorage( CArrayStorage< false > ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: - a CArrayStorage object is generated with the right size. \
			- Data can be written \
			- org. CArrayStorage is changed.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArrayStorage<      float ,10, true> TestArray2( TEST_afData123 );
		cml::CArrayStorage<const float ,10, true> TestArray( TestArray2 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, &TestArray2, sizeof(TestArray));

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}
#endif

#if 0
void TEST_CLASS_ARRAY::test_cml_CArrayStorage_const_true_operator_at( int doIt )
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_operator[]_001",
			"Description: \
			- cml_stl_array.h : CArrayStorage::operator[] ) \
			- Testing: interface, boundary_condition \
			- Overview: verify that the operator[] works properly \
			- Entry conditions: - \
			- Expected results: The right data is given back. \
			Access to positions outside of the array area are detected ");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("{_wassert#replace}");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		char i8Value;
		cml::CArrayStorage<const char ,10, true> TestArray(TEST_acData123);

		/* Call SUT */
		i8Value = TestArray[0];
		/* Test case checks */
		CHECK( i8Value, 1 );

		/* Test case checks */

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_operator[]_002",
			"Description: \
			- cml_stl_array.h : CArrayStorage::operator[] ) \
			- Testing: interface, boundary_condition \
			- Overview: verify that the operator[] works properly \
			- Entry conditions: - \
			- Expected results: The right data is given back. \
			Access to positions outside of the array area are detected ");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("{_wassert#replace}");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		int i8Value;
		cml::CArrayStorage<const int ,10, true> TestArray(TEST_aiData123);

		/* Call SUT */
		i8Value = TestArray[0];
		/* Test case checks */
		CHECK( i8Value, 1 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_operator[]_003",
			"Description: \
			- cml_stl_array.h : CArrayStorage::operator[] ) \
			- Testing: interface, boundary_condition \
			- Overview: verify that the operator[] works properly \
			- Entry conditions: - \
			- Expected results: The right data is given back. \
			Access to positions outside of the array area are detected ");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("{_wassert#replace}");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		float i8Value;
		cml::CArrayStorage<const float ,10, true> TestArray(TEST_afData123);

		/* Call SUT */
		i8Value = TestArray[0];
		/* Test case checks */
		CHECK( i8Value, 1 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}
#endif
#if 0
void TEST_CLASS_ARRAY::test_cml_CArrayStorage_const_true_size( int doIt )
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_size()_001",
			"Description: \
			- cml_stl_array.h : CArrayStorage::size() \
			- Testing: interface \
			- Overview: verify that the size() function works properly \
			- Entry conditions: - \
			- Expected results: The right size is given back.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("{_wassert#replace}");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<char ,10, false> TestArray(TEST_acData123);


		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, TEST_acData123, sizeof(TestArray));

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_size()_002",
			"Description: \
			- cml_stl_array.h : CArrayStorage::size() \
			- Testing: interface \
			- Overview: verify that the size() function works properly \
			- Entry conditions: - \
			- Expected results: The right size is given back.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("{_wassert#replace}");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<int ,10, false> TestArray(TEST_aiData123);


		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, TEST_aiData123, sizeof(TestArray));

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_size()_003",
			"Description: \
			- cml_stl_array.h : CArrayStorage::size() \
			- Testing: interface \
			- Overview: verify that the size() function works properly \
			- Entry conditions: - \
			- Expected results: The right size is given back.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("{_wassert#replace}");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<float ,10, false> TestArray(TEST_afData123);

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, TEST_afData123, sizeof(TestArray));

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_ARRAY::test_cml_CArrayStorage_const_true_max_size( int doIt )
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_max_size()_001",
			"Description: \
			- cml_stl_array.h : CArrayStorage::max_size() \
			- Testing: interface \
			- Overview: verify that the size() function works properly \
			- Entry conditions: - \
			- Expected results: The right size is given back.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("{_wassert#replace}");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<char ,10, false> TestArray(TEST_acData123);

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, TEST_acData123, sizeof(TestArray));

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_max_size()_002",
			"Description: \
			- cml_stl_array.h : CArrayStorage::max_size() \
			- Testing: interface \
			- Overview: verify that the size() function works properly \
			- Entry conditions: - \
			- Expected results: The right size is given back.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("{_wassert#replace}");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<int ,10, false> TestArray(TEST_aiData123);

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, TEST_aiData123, sizeof(TestArray));

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArrayStorage<const char, 10, true>_max_size()_003",
			"Description: \
			- cml_stl_array.h : CArrayStorage::max_size() \
			- Testing: interface \
			- Overview: verify that the size() function works properly \
			- Entry conditions: - \
			- Expected results: The right size is given back.");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("{_wassert#replace}");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<float ,10, false> TestArray(TEST_afData123);

		/* Test case checks */
		CHECK(TestArray.size(),10);
		CHECK_MEMORY("copy constructor", &TestArray, TEST_afData123, sizeof(TestArray));

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

// last class


void TEST_CLASS_ARRAY::test_cml_CArray_false_constructor(int doIt)
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArray<char, 10, false>_constructor_001",
			"Description: \
			- cml_stl_array.h : CArray::CArray() \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<char ,10, false> TestArray;

		/* Test case checks */
		CHECK(TestArray.size(),10);
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArray<char, 10, false>_constructor_002",
			"Description: \
			- cml_stl_array.h : CArray::CArray() \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<short ,10, false> TestArray;

		/* Test case checks */
		CHECK(TestArray.size(),10);
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArray<char, 10, false>_constructor_003",
			"Description: \
			- cml_stl_array.h : CArray::CArray() \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<int ,10, false> TestArray;

		/* Test case checks */
		CHECK(TestArray.size(),10);
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArray<char, 10, false>_constructor_004",
			"Description: \
			- cml_stl_array.h : CArray::CArray() \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<float ,10, false> TestArray;

		/* Test case checks */
		CHECK(TestArray.size(),10);
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}


void TEST_CLASS_ARRAY::test_cml_CArray_false_constructor_pData(int doIt)
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArray<char, 10, false>_constructor( *data, size )_001",
			"Description:\
			- cml_stl_array.h : CArray::CArray(  *data, size ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a new buffer for data is provided  \
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<char ,10, false> TestArray;

		/* Test case checks */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArray<char, 10, false>_constructor( *data, size )_002",
			"Description:\
			- cml_stl_array.h : CArray::CArray(  *data, size ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a new buffer for data is provided  \
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<int ,10, false> TestArray;

		/* Test case checks */
		CHECK(TestArray.size(),10);
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArray<char, 10, false>_constructor( *data, size )_003",
			"Description:\
			- cml_stl_array.h : CArray::CArray(  *data, size ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a new buffer for data is provided  \
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<float ,10, false> TestArray;

		/* Test case checks */
		CHECK(TestArray.size(),10);
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}


void TEST_CLASS_ARRAY::test_cml_CArray_false_constructor_pcData(int doIt)
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArray<char, 100, false>_constructor( *const data, size )_001",
			"Description: \
			- cml_stl_array.h : CArray::CArray(  * const data, size ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a new buffer for data is provided  \
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<char ,10, false> TestArray;

		/* Test case checks */
		CHECK(TestArray.size(),10);
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArray<char, 10, false>_constructor( *const data, size )_002",
			"Description: \
			- cml_stl_array.h : CArray::CArray(  * const data, size ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a new buffer for data is provided  \
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<int ,10, false> TestArray;

		/* Test case checks */
		CHECK(TestArray.size(),10);
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArray<char, 10, false>_constructor( *const data, size )_003",
			"Description: \
			- cml_stl_array.h : CArray::CArray(  * const data, size ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a new buffer for data is provided  \
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<float ,10, false> TestArray;

		/* Test case checks */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}


void TEST_CLASS_ARRAY::test_cml_CArray_false_constructor_aData(int doIt)
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArray<char, 10, false>_constructor( data[])_001",
			"Description: \
			- cml_stl_array.h : CArray::CArray( data[] ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a new buffer for data is provided  \
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<char ,10, false> TestArray( TEST_acData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArray<char, 10, false>_constructor( data[])_002",
			"Description: \
			- cml_stl_array.h : CArray::CArray( data[] ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a new buffer for data is provided  \
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<int ,10, false> TestArray( TEST_aiData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArray<char, 10, false>_constructor( data[])_003",
			"Description: \
			- cml_stl_array.h : CArray::CArray( data[] ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a new buffer for data is provided  \
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<float ,10, false> TestArray( TEST_afData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_ARRAY::test_cml_CArray_false_constructor_acData(int doIt)
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArray<char, 10, false>_constructor( const data[] )_001",
			"Description: \
			- cml_stl_array.h : CArray::CArray() \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a new buffer for data is provided  \
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data" );

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<char ,10, false> TestArray( TEST_acData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArray<char, 10, false>_constructor( const data[] )_002",
			"Description: \
			- cml_stl_array.h : CArray::CArray() \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a new buffer for data is provided  \
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data" );

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<int ,10, false> TestArray( TEST_aiData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArray<char, 10, false>_constructor( const data[] )_003",
			"Description: \
			- cml_stl_array.h : CArray::CArray() \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a new buffer for data is provided  \
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data" );

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<float ,10, false> TestArray( TEST_afData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);
		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}


void TEST_CLASS_ARRAY::test_cml_CArray_false_constructor_CArray(int doIt)
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArray<char, 10, false>_constructor( CArray )_001",
			"Description: \
			- cml_stl_array.h : CArray::CArray( CArray ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a new buffer for data is provided\
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<char ,10, false> TestArray( TEST_acData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArray<char, 10, false>_constructor( CArray )_002",
			"Description: \
			- cml_stl_array.h : CArray::CArray( CArray ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a new buffer for data is provided\
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<int ,10, false> TestArray( TEST_aiData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArray<char, 10, false>_constructor( CArray )_003",
			"Description: \
			- cml_stl_array.h : CArray::CArray( CArray ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a new buffer for data is provided\
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<float ,10, false> TestArray( TEST_afData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_ARRAY::test_cml_CArray_false_constructor_CArrayStorage_1(int doIt)
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArray<char, 10, false>_constructor( CArrayStorage )_001",
			"Description: \
			- cml_stl_array.h : CArray::CArray( CArrayStorage ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a new buffer for data is provided\
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<char ,10, false> TestArray( TEST_acData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArray<char, 10, false>_constructor( CArrayStorage )_002",
			"Description: \
			- cml_stl_array.h : CArray::CArray( CArrayStorage ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a new buffer for data is provided\
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<int ,10, false> TestArray( TEST_aiData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArray<char, 10, false>_constructor( CArrayStorage )_003",
			"Description: \
			- cml_stl_array.h : CArray::CArray( CArrayStorage ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a new buffer for data is provided\
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<float ,10, false> TestArray( TEST_afData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}


void TEST_CLASS_ARRAY::test_cml_CArray_false_constructor_CArrayStorage_2(int doIt)
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArray<char, 10, false>_constructor( const CArrayStorage )_001",
			"Description: \
			- cml_stl_array.h : CArray::CArray( const CArrayStorage ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a new buffer for data is provided\
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<char ,10, false> TestArray( TEST_acData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArray<char, 10, false>_constructor( const CArrayStorage )_002",
			"Description: \
			- cml_stl_array.h : CArray::CArray( const CArrayStorage ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a new buffer for data is provided\
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<int ,10, false> TestArray( TEST_aiData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArray<char, 10, false>_constructor( const CArrayStorage )_003",
			"Description: \
			- cml_stl_array.h : CArray::CArray( const CArrayStorage ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a new buffer for data is provided\
			- Entry conditions: - \
			- Expected results: a CArray object is generated with the right size and data");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CArray<float ,10, false> TestArray( TEST_afData123 );

		/* Test case checks */
		CHECK(TestArray.size(),10);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}
#endif
void TEST_CLASS_ARRAY::test_cml_CArray_false_fill(int doIt)
{
		std::cout << "START ---> test_cml_CArray_false_fill\n\n";		
		fprintf(fpTest, "START ---> test_cml_CArray_false_fill\n\n");

		fprintf(fpTest, "Function Name ---> fill()  \n\n");

	if (doIt) {

		{
		std::cout << "Test Case --->test_cml_CArray_false_fill_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_fill_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
	
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		char acTest[10] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
		cml::CArray<char, 10, false> TestArray(  TEST_acData_Zero );
		cml::CArray<char, 10, false> expected_TestArray(  acTest );
		
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console< char, 10, false >( expected_TestArray);
		check__vArrayPrint_to_File< char, 10, false >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestArray.fill( 9 );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,expected_TestArray);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_fill_001\n\n";
		}

		
		{
		std::cout << "Test Case --->test_cml_CArray_false_fill_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_fill_002\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
	
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		int acTest[10] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
		cml::CArray<int, 10, false> TestArray(  TEST_aiData_Zero );
		cml::CArray<int, 10, false> expected_TestArray(  acTest );
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console< int, 10, false >( expected_TestArray);
		check__vArrayPrint_to_File< int, 10, false >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestArray.fill( 9 );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,expected_TestArray);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_fill_002\n\n";
		}
		
		{
		std::cout << "Test Case --->test_cml_CArray_false_fill_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_fill_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
	
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		float acTest[10] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
		cml::CArray<float, 10, false> TestArray(  TEST_afData_Zero );
		cml::CArray<float, 10, false> expected_TestArray(  acTest );
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console< float, 10, false >( expected_TestArray);
		check__vArrayPrint_to_File< float, 10, false >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestArray.fill( 9 );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,expected_TestArray);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_fill_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArray_false_fill\n\n";
	fprintf(fpTest, "END ---> test_cml_CArray_false_fill\n\n");
}

void TEST_CLASS_ARRAY::test_cml_CArray_false_operator_assign_1(int doIt)
{
		std::cout << "START ---> test_cml_CArray_false_operator_assign_1\n\n";		
		fprintf(fpTest, "START ---> test_cml_CArray_false_operator_assign_1\n\n");

		fprintf(fpTest, "Function Name ---> operator=(CArray)  \n\n");

	if (doIt) {

		{
		std::cout << "Test Case --->test_cml_CArray_false_operator_assign_1_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_operator_assign_1_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
	
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArray<char, 10, false> TestArray(  TEST_acData_Zero );
		cml::CArray<char, 10, false> TestArray2( TEST_acData123 );
		cml::CArray<char, 10, false> expected_TestArray(  TEST_acData123 );
		
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console< char, 10, false >( expected_TestArray);
		check__vArrayPrint_to_File< char, 10, false >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestArray = TestArray2;

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,expected_TestArray);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_operator_assign_1_001\n\n";
		}

		
		{
		std::cout << "Test Case --->test_cml_CArray_false_operator_assign_1_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_operator_assign_1_002\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
	
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArray<int, 10, false> TestArray2( TEST_aiData123 );
		cml::CArray<int, 10, false> expected_TestArray(  TEST_aiData123 );
		cml::CArray<int, 10, false> TestArray(  TEST_aiData_Zero );
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console< int, 10, false >( expected_TestArray);
		check__vArrayPrint_to_File< int, 10, false >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestArray = TestArray2;

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,expected_TestArray);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_operator_assign_1_002\n\n";
		}
		
		{
		std::cout << "Test Case --->test_cml_CArray_false_operator_assign_1_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_operator_assign_1_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
	
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArray<float, 10, false> TestArray2( TEST_afData123 );
		cml::CArray<float, 10, false> expected_TestArray(  TEST_afData123 );
		cml::CArray<float, 10, false> TestArray(  TEST_afData_Zero );
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console< float, 10, false >( expected_TestArray);
		check__vArrayPrint_to_File< float, 10, false >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestArray = TestArray2;

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,expected_TestArray);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_operator_assign_1_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArray_false_operator_assign_1\n\n";
	fprintf(fpTest, "END ---> test_cml_CArray_false_operator_assign_1\n\n");
}

void TEST_CLASS_ARRAY::test_cml_CArray_false_operator_assign_2(int doIt)
{
		std::cout << "START ---> test_cml_CArray_false_operator_assign_2\n\n";		
		fprintf(fpTest, "START ---> test_cml_CArray_false_operator_assign_2\n\n");

		fprintf(fpTest, "Function Name ---> operator=(CArray<const_type>)  \n\n");

	if (doIt) {

		{
		std::cout << "Test Case --->test_cml_CArray_false_operator_assign_2_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_operator_assign_2_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
	
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArray<char, 10, false> TestArray(  TEST_acData_Zero );
		cml::CArray< char, 10, false> TestArray2( TEST_acData123_const );
		cml::CArray< char, 10, false> expected_TestArray(  TEST_acData123_const );
		
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console< char, 10, false >( expected_TestArray);
		check__vArrayPrint_to_File< char, 10, false >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestArray = TestArray2;

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,expected_TestArray);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_operator_assign_2_001\n\n";
		}

		
		{
		std::cout << "Test Case --->test_cml_CArray_false_operator_assign_2_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_operator_assign_2_002\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
	
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArray< int, 10, false> TestArray2( TEST_aiData123_const );
		cml::CArray< int, 10, false> expected_TestArray(  TEST_aiData123_const );
		cml::CArray< int, 10, false> TestArray(  TEST_aiData_Zero );
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console< int, 10, false >( expected_TestArray);
		check__vArrayPrint_to_File< int, 10, false >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestArray = TestArray2;

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,expected_TestArray);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n2\n\n";
		}
		
		{
		std::cout << "Test Case --->test_cml_CArray_false_operator_assign_2_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_operator_assign_2_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
	
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArray< float, 10, false> TestArray2( TEST_afData123_const );
		cml::CArray< float, 10, false> expected_TestArray(  TEST_afData123_const );
		cml::CArray<float, 10, false> TestArray(  TEST_afData_Zero );
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console< float, 10, false >( expected_TestArray);
		check__vArrayPrint_to_File< float, 10, false >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestArray = TestArray2;

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,expected_TestArray);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArray_false_operator_assign_2\n\n";
	fprintf(fpTest, "END ---> test_cml_CArray_false_operator_assign_2\n\n");
}

void TEST_CLASS_ARRAY::test_cml_CArray_false_operator_assign_3(int doIt)
{
		std::cout << "START ---> test_cml_CArray_false_operator_assign_1\n\n";		
		fprintf(fpTest, "START ---> test_cml_CArray_false_operator_assign_1\n\n");

		fprintf(fpTest, "Function Name ---> operator=(CArray<type>)  \n\n");

	if (doIt) {

		{
		std::cout << "Test Case --->test_cml_CArray_false_operator_assign_3_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_operator_assign_3_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
	
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArray<char, 10, false> TestArray(  TEST_acData_Zero );
		cml::CArray<char, 10, false> TestArray2( TEST_acData123 );
		cml::CArray<char, 10, false> expected_TestArray(  TEST_acData123 );
		
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console< char, 10, false >( expected_TestArray);
		check__vArrayPrint_to_File< char, 10, false >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestArray = TestArray2;

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,expected_TestArray);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_operator_assign_3_001\n\n";
		}

		
		{
		std::cout << "Test Case --->test_cml_CArray_false_operator_assign_3_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_operator_assign_3_002\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
	
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArray<int, 10, false> TestArray2( TEST_aiData123 );
		cml::CArray<int, 10, false> expected_TestArray(  TEST_aiData123 );
		cml::CArray<int, 10, false> TestArray(  TEST_aiData_Zero );
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console< int, 10, false >( expected_TestArray);
		check__vArrayPrint_to_File< int, 10, false >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestArray = TestArray2;

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,expected_TestArray);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_operator_assign_3_002\n\n";
		}
		
		{
		std::cout << "Test Case --->test_cml_CArray_false_operator_assign_3_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_operator_assign_3_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
	
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CArray<float, 10, false> TestArray2( TEST_afData123 );
		cml::CArray<float, 10, false> expected_TestArray(  TEST_afData123 );
		cml::CArray<float, 10, false> TestArray(  TEST_afData_Zero );
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result ---> \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console< float, 10, false >( expected_TestArray);
		check__vArrayPrint_to_File< float, 10, false >( expected_TestArray, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestArray = TestArray2;

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestArray,expected_TestArray);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_operator_assign_3_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArray_false_operator_assign_3\n\n";
	fprintf(fpTest, "END ---> test_cml_CArray_false_operator_assign_3\n\n");
}

void TEST_CLASS_ARRAY::test_cml_CArray_false_at_1(int doIt)
{

	std::cout << "START ---> test_cml_CArray_false_at_1\n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray_false_at_1\n\n");

	fprintf(fpTest, "Function Name ---> at=()\n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_cml_CArrayStorage_false_operator_at_1_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_false_operator_at_1_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		char i8Value;
		char expected_i8Value = (char)1;
		cml::CArray<char ,10, false> TestArray( TEST_acData123 );
				
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
				
		/* Call SUT */
		i8Value = TestArray.at(0);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_false_operator_at_1_001\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArrayStorage_false_operator_at_1_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_false_operator_at_1_002\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		int i8Value;
		int expected_i8Value = 1;
		cml::CArray<int ,10, false> TestArray( TEST_aiData123 );
		
		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		i8Value = TestArray.at(0);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_false_operator_at_1_002\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArrayStorage_false_operator_at_1_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArrayStorage_false_operator_at_1_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		float i8Value;
		float expected_i8Value = 1;
		cml::CArray<float ,10, false> TestArray( TEST_afData123 );

		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		i8Value = TestArray.at(0);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);
		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArrayStorage_false_operator_at_1_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArrayStorage_false_operator_at_1\n\n";
	fprintf(fpTest, "END ---> test_cml_CArrayStorage_false_operator_at_1\n\n");
}

void TEST_CLASS_ARRAY::test_cml_CArray_false_at_2(int doIt)
{
	std::cout << "START ---> test_cml_CArray_false_at_2\n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray_false_at_2\n\n");

	fprintf(fpTest, "Function Name ---> at=()const \n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_cml_CArray_false_at_2_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_at_2_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		char i8Value;
		char expected_i8Value = (char)1;
		const cml::CArray<char ,10, false> TestArray( TEST_acData123 );
				
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
				
		/* Call SUT */
		i8Value = TestArray.at(0);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_at_2_001\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArray_false_at_2_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_at_2_002\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		int i8Value;
		int expected_i8Value = 1;
		const cml::CArray<int ,10, false> TestArray( TEST_aiData123 );
		
		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		i8Value = TestArray.at(0);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_at_2_002\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArray_false_at_2_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_at_2_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		float i8Value;
		float expected_i8Value = 1;
		const cml::CArray<float ,10, false> TestArray( TEST_afData123 );

		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		i8Value = TestArray.at(0);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);
		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_at_2_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArray_false_at_2\n\n";
	fprintf(fpTest, "END ---> test_cml_CArray_false_at_2\n\n");
}

void TEST_CLASS_ARRAY::test_cml_CArray_false_front_1(int doIt)
{
	std::cout << "START ---> test_cml_CArray_false_front_1\n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray_false_front_1\n\n");

	fprintf(fpTest, "Function Name ---> front=() \n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_cml_CArray_false_front_1_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_front_1_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		char i8Value;
		char expected_i8Value = (char)1;
		cml::CArray<char ,10, false> TestArray( TEST_acData123 );
				
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
				
		/* Call SUT */
		i8Value = TestArray.front();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_front_1_001\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArray_false_front_1_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_front_1_002\n\n");
		
		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		int i8Value;
		int expected_i8Value = 1;
		cml::CArray<int ,10, false> TestArray( TEST_aiData123 );
		
		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		i8Value = TestArray.front();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_front_1_002\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArray_false_front_1_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_front_1_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
		
		/* Test case data declarations */
		float i8Value;
		float expected_i8Value = 1;
		cml::CArray<float ,10, false> TestArray( TEST_afData123 );

		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		i8Value = TestArray.front();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);
		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_front_1_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArray_false_front_1\n\n";
	fprintf(fpTest, "END ---> test_cml_CArray_false_front_1\n\n");
}

void TEST_CLASS_ARRAY::test_cml_CArray_false_front_2(int doIt)
{
	std::cout << "START ---> test_cml_CArray_false_front_2\n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray_false_front_2\n\n");

	fprintf(fpTest, "Function Name ---> front=()const \n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_cml_CArray_false_front_2_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_front_2_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		char i8Value;
		char expected_i8Value = (char)1;
		const cml::CArray<char ,10, false> TestArray( TEST_acData123 );
				
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
				
		/* Call SUT */
		i8Value = TestArray.front();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_front_2_001\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArray_false_front_2_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_front_2_002\n\n");
		
		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		int i8Value;
		int expected_i8Value = 1;
		const cml::CArray<int ,10, false> TestArray( TEST_aiData123 );
		
		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		i8Value = TestArray.front();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_front_2_002\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArray_false_front_2_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_front_2_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
		
		/* Test case data declarations */
		float i8Value;
		float expected_i8Value = 1;
		const cml::CArray<float ,10, false> TestArray( TEST_afData123 );

		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		i8Value = TestArray.front();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);
		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_front_2_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArray_false_front_2\n\n";
	fprintf(fpTest, "END ---> test_cml_CArray_false_front_2\n\n");
}

void TEST_CLASS_ARRAY::test_cml_CArray_false_back_1(int doIt)
{
	std::cout << "START ---> test_cml_CArray_false_back_1\n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray_false_back_1\n\n");

	fprintf(fpTest, "Function Name ---> back() \n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_cml_CArray_false_back_1_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_back_1_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		char i8Value;
		char expected_i8Value = (char)10;
		cml::CArray<char ,10, false> TestArray( TEST_acData123 );
				
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
				
		/* Call SUT */
		i8Value = TestArray.back();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_back_1_001\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArray_false_back_1_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_back_1_002\n\n");
		
		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		int i8Value;
		int expected_i8Value = 10;
		cml::CArray<int ,10, false> TestArray( TEST_aiData123 );
		
		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		i8Value = TestArray.back();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_back_1_002\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArray_false_back_1_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_back_1_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
		
		/* Test case data declarations */
		float i8Value;
		float expected_i8Value = 10;
		cml::CArray<float ,10, false> TestArray( TEST_afData123 );

		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		i8Value = TestArray.back();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);
		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_back_1_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArray_false_back_1\n\n";
	fprintf(fpTest, "END ---> test_cml_CArray_false_back_1\n\n");
}

void TEST_CLASS_ARRAY::test_cml_CArray_false_back_2(int doIt)
{
	std::cout << "START ---> test_cml_CArray_false_back_2\n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray_false_back_2\n\n");

	fprintf(fpTest, "Function Name ---> back()const \n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_cml_CArray_false_back_2_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_back_2_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		char i8Value;
		char expected_i8Value = (char)10;
		const cml::CArray<char ,10, false> TestArray( TEST_acData123 );
				
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
				
		/* Call SUT */
		i8Value = TestArray.back();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_back_2_001\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArray_false_back_2_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_back_2_002\n\n");
		
		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		int i8Value;
		int expected_i8Value = 10;
		const cml::CArray<int ,10, false> TestArray( TEST_aiData123 );
		
		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		i8Value = TestArray.back();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_back_2_002\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArray_false_back_2_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_back_2_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
		
		/* Test case data declarations */
		float i8Value;
		float expected_i8Value = 10;
		const cml::CArray<float ,10, false> TestArray( TEST_afData123 );

		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		i8Value = TestArray.back();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);
		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_back_2_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArray_false_back_2\n\n";
	fprintf(fpTest, "END ---> test_cml_CArray_false_back_2\n\n");
}

#if 0
void TEST_CLASS_ARRAY::test_cml_CArray_false_fill(int doIt)
{
	if (doIt) 
	{
		START_TEST("verify_cml_CArray<char, 10, false>_fill()_001",
			"Description: \
			- cml_stl_array.h : CArray::back() \
			- Testing: interface, boundary_condition \
			- Overview: verify that the method fill() works properly \
			1) The whole array will be filled with \'9\' \
			- Entry conditions: - \
			- Expected results: 1) The whole array has to be filled with \'9\' ");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		char acTest[10] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
		cml::CArray<char ,10, false> TestArray;

		/* Call SUT */
		TestArray.fill( 9 );
		/* Test case checks */
		CHECK_MEMORY("Fills", &TestArray, acTest, sizeof(acTest));

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArray<char, 10, false>_fill()_002",
			"Description: \
			- cml_stl_array.h : CArray::back() \
			- Testing: interface, boundary_condition \
			- Overview: verify that the method fill() works properly \
			1) The whole array will be filled with \'9\' \
			- Entry conditions: - \
			- Expected results: 1) The whole array has to be filled with \'9\' ");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		int acTest[10] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
		cml::CArray<int ,10, false> TestArray;

		/* Call SUT */
		TestArray.fill( 9 );
		/* Test case checks */
		CHECK_MEMORY("Fills", &TestArray, acTest, sizeof(acTest));

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("verify_cml_CArray<char, 10, false>_fill()_003",
			"Description: \
			- cml_stl_array.h : CArray::back() \
			- Testing: interface, boundary_condition \
			- Overview: verify that the method fill() works properly \
			1) The whole array will be filled with \'9\' \
			- Entry conditions: - \
			- Expected results: 1) The whole array has to be filled with \'9\' ");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		float acTest[10] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
		cml::CArray<float ,10, false> TestArray;

		/* Call SUT */
		TestArray.fill( 9 );
		/* Test case checks */
		CHECK_MEMORY("Fills", &TestArray, acTest, sizeof(acTest));

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}
#endif
void TEST_CLASS_ARRAY::test_cml_CArray_false_begin_1(int doIt)
{
	std::cout << "START ---> test_cml_CArray_false_begin_1\n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray_false_begin_1\n\n");

	fprintf(fpTest, "Function Name ---> begin() n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_cml_CArray_false_begin_1_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_begin_1_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		char i8Value;
		char expected_i8Value = (char)1;
		cml::CArray<char ,10, false> TestArray( TEST_acData123 );
				
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
				
		/* Call SUT */
		cml::CArray<char ,10, false>::it itr = TestArray.begin();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


		i8Value = *itr;

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_begin_1_001\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArray_false_begin_1_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_begin_1_002\n\n");
		
		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		int i8Value;
		int expected_i8Value = 1;
		cml::CArray<int ,10, false> TestArray( TEST_aiData123 );
		
		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::CArray<int ,10, false>::it itr = TestArray.begin();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


		i8Value = *itr;

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_begin_1_002\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArray_false_begin_1_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_begin_1_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
		
		/* Test case data declarations */
		float i8Value;
		float expected_i8Value = 1;
		cml::CArray<float ,10, false> TestArray( TEST_afData123 );

		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		cml::CArray<float ,10, false>::it itr = TestArray.begin();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		i8Value = *itr;

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);
		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_begin_1_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArray_false_begin_1\n\n";
	fprintf(fpTest, "END ---> test_cml_CArray_false_begin_1\n\n");
}

void TEST_CLASS_ARRAY::test_cml_CArray_false_begin_2(int doIt)
{
	std::cout << "START ---> test_cml_CArray_false_begin_2\n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray_false_begin_2\n\n");

	fprintf(fpTest, "Function Name ---> begin()const \n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_cml_CArray_false_begin_2_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_begin_2_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		char i8Value;
		char expected_i8Value = (char)1;
		const cml::CArray<char ,10, false> TestArray( TEST_acData123 );
				
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
				
		/* Call SUT */
		cml::CArray<char ,10, false>::cIt itr = TestArray.begin();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


		i8Value = *itr;

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_begin_2_001\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArray_false_begin_2_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_begin_2_002\n\n");
		
		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		int i8Value;
		int expected_i8Value = 1;
		const cml::CArray<int ,10, false> TestArray( TEST_aiData123 );
		
		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::CArray<int ,10, false>::cIt itr = TestArray.begin();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		i8Value = *itr;

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_begin_2_002\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArray_false_begin_2_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_begin_2_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
		
		/* Test case data declarations */
		float i8Value;
		float expected_i8Value = 1;
		const cml::CArray<float ,10, false> TestArray( TEST_afData123 );

		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		cml::CArray<float ,10, false>::cIt itr = TestArray.begin();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		i8Value = *itr;

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);
		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_begin_2_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArray_false_begin_2\n\n";
	fprintf(fpTest, "END ---> test_cml_CArray_false_begin_2\n\n");
}

void TEST_CLASS_ARRAY::test_cml_CArray_false_begin_3(int doIt)
{
	std::cout << "START ---> test_cml_CArray_false_begin_3\n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray_false_begin_3\n\n");

	fprintf(fpTest, "Function Name ---> cbegin() n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_cml_CArray_false_begin_3_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_begin_3_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		char i8Value;
		char expected_i8Value = (char)1;
		cml::CArray<char ,10, false> TestArray( TEST_acData123 );
				
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
				
		/* Call SUT */
		cml::CArray<char ,10, false>::cIt itr = TestArray.cbegin();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		i8Value = *itr;

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_begin_3_001\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArray_false_begin_3_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_begin_3_002\n\n");
		
		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		int i8Value;
		int expected_i8Value = 1;
		cml::CArray<int ,10, false> TestArray( TEST_aiData123 );
		
		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::CArray<int ,10, false>::cIt itr = TestArray.cbegin();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		i8Value = *itr;

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_begin_3_002\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArray_false_begin_3_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_begin_3_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
		
		/* Test case data declarations */
		float i8Value;
		float expected_i8Value = 1;
		cml::CArray<float ,10, false> TestArray( TEST_afData123 );

		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		cml::CArray<float ,10, false>::cIt itr = TestArray.cbegin();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		i8Value = *itr;

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);
		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_begin_3_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArray_false_begin_3\n\n";
	fprintf(fpTest, "END ---> test_cml_CArray_false_begin_3\n\n");
}

void TEST_CLASS_ARRAY::test_cml_CArray_false_end_1(int doIt)
{
	std::cout << "START ---> test_cml_CArray_false_end_1\n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray_false_end_1\n\n");

	fprintf(fpTest, "Function Name ---> end() n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_cml_CArray_false_end_1_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_end_1_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		char i8Value;
		char expected_i8Value = (char)10;
		cml::CArray<char ,10, false> TestArray( TEST_acData123 );
				
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
				
		/* Call SUT */
		//TestArray.end();
		cml::CArray<char ,10, false>::it itr = TestArray.end();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		itr--;
		i8Value = *itr;

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_end_1\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArray_false_end_1_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_end_1_002\n\n");
		
		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		int i8Value;
		int expected_i8Value = 10;
		cml::CArray<int ,10, false> TestArray( TEST_aiData123 );
		
		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::CArray<int ,10, false>::it itr = TestArray.end();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


		itr--;
		i8Value = *itr;
		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_end_1_002\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArray_false_end_1_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_end_1_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
		
		/* Test case data declarations */
		float i8Value;
		float expected_i8Value = 10;
		cml::CArray<float ,10, false> TestArray( TEST_afData123 );

		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		cml::CArray<float ,10, false>::it itr = TestArray.end();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


		itr--;
		i8Value = *itr;
		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);
		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_end_1_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArray_false_end_1\n\n";
	fprintf(fpTest, "END ---> test_cml_CArray_false_end_1\n\n");
}

void TEST_CLASS_ARRAY::test_cml_CArray_false_end_2(int doIt)
{
	std::cout << "START ---> test_cml_CArray_false_end_2\n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray_false_end_2\n\n");

	fprintf(fpTest, "Function Name ---> end()const \n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_cml_CArray_false_end_2_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_end_2_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		char i8Value;
		char expected_i8Value = (char)10;
		const cml::CArray<char ,10, false> TestArray( TEST_acData123 );
				
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
				
		/* Call SUT */
		cml::CArray<char ,10, false>::cIt itr = TestArray.end();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


		itr--;
		i8Value = *itr;
		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_end_2_001\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArray_false_end_2_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_end_2_002\n\n");
		
		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		int i8Value;
		int expected_i8Value = 10;
		const cml::CArray<int ,10, false> TestArray( TEST_aiData123 );
		
		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::CArray<int ,10, false>::cIt itr = TestArray.end();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


		itr--;
		i8Value = *itr;
		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_end_2_002\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArray_false_end_2_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_end_2_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
		
		/* Test case data declarations */
		float i8Value;
		float expected_i8Value = 10;
		const cml::CArray<float ,10, false> TestArray( TEST_afData123 );

		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		cml::CArray<float ,10, false>::cIt itr = TestArray.end();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


		itr--;
		i8Value = *itr;
		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);
		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_end_2_003\n\n";
		}
	}
	std::cout << "END ---> test_cml_CArray_false_end_2\n\n";
	fprintf(fpTest, "END ---> test_cml_CArray_false_end_2\n\n");
}

void TEST_CLASS_ARRAY::test_cml_CArray_false_end_3(int doIt)
{
	std::cout << "START ---> test_cml_CArray_false_end_3\n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray_false_end_3\n\n");

	fprintf(fpTest, "Function Name ---> cend() \n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_cml_CArray_false_end_3_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_end_3_001\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		char i8Value;
		char expected_i8Value = (char)10;
		cml::CArray<char ,10, false> TestArray( TEST_acData123 );
				
		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		
		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< char, 10, false >( TestArray);
		check__vArrayPrint_to_File< char, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
				
		/* Call SUT */
		cml::CArray<char ,10, false>::cIt itr = TestArray.cend();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


		itr--;
		i8Value = *itr;
		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
		std::cout << "Test Case ---> test_cml_CArray_false_end_3_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_end_3_002\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");

		/* Test case data declarations */
		int i8Value;
		int expected_i8Value = 10;
		cml::CArray<int ,10, false> TestArray( TEST_aiData123 );
		
		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< int, 10, false >( TestArray);
		check__vArrayPrint_to_File< int, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		cml::CArray<int ,10, false>::cIt itr = TestArray.cend();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


		itr--;
		i8Value = *itr;
		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_end_3_002\n\n";
		}

		{
		std::cout << "Test Case ---> test_cml_CArray_false_end_3_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray_false_end_3_003\n\n");

		std::cout << "Data Dimension ---> 10\n\n";		
		fprintf(fpTest, "Data Dimension ---> 10\n\n");
		
		/* Test case data declarations */
		float i8Value;
		float expected_i8Value = 10;
		cml::CArray<float ,10, false> TestArray( TEST_afData123 );

		/* Set global data */
		initialise_global_data();

		/* Input Array */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float, 10, false >( TestArray);
		check__vArrayPrint_to_File< float, 10, false >( TestArray, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_i8Value);
		check__PrintValue_to_File(expected_i8Value, fpTest);
		fprintf(fpTest, "\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		cml::CArray<float ,10, false>::cIt itr = TestArray.cend();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


		itr--;
		i8Value = *itr;
		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "\n Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(i8Value);
		check__PrintValue_to_File(i8Value, fpTest);
		fprintf(fpTest, "\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( i8Value,expected_i8Value);
		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status: FAIL\n";    
			fprintf(fpTest, "Status: FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");

		std::cout << "END ---> test_cml_CArray_false_end_3_003\n\n";
		}
		
	}
	std::cout << "END ---> test_cml_CArray_false_end_3\n\n";
	fprintf(fpTest, "END ---> test_cml_CArray_false_end_3\n\n");
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
