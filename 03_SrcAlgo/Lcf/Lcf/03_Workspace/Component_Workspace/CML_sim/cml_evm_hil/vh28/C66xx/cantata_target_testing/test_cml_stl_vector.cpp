/*****************************************************************************/
/*                            Cantata Test Script                            */
/*****************************************************************************/
/*
*    Filename: test_cml_stl_vector.cpp
*    Author: uidr1064
*    Generated on: 03-Feb-2016 10:24:29
*    Generated from: cml_stl_vector.cpp
*/
/*****************************************************************************/
/* Environment Definition                                                    */
/*****************************************************************************/

#define TEST_SCRIPT_GENERATOR 2

/* Include files from software under test */
#include <stdio.h>
#include <iostream>
#include "cml_ext.h"
#include "glob_type.h"
#include "cml_stl_type_traits.h"
#include "cml_stl_point.h"
#include "cml_stl_matrix.h"
#include "cml_stl_array.h"
#include "cml_stl_array2d.h"
#include "cml_stl_vector.h"

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

	/* No global data */
	std::cout << "\nStatus ---> PASS\n\n"; 
	fprintf(fpTest, "\nStatus ---> PASS\n\n");
}

/*****************************************************************************/
/* Test class declaration                                                    */
/*****************************************************************************/
class TEST_CLASS_VECTOR
{
public:
	void run_tests_vector();
	void test_cml_CVector_false_constructor(int);
	void test_cml_CVector_false_constructor_aData(int);
	void test_cml_CVector_false_constructor_acData(int);
	void test_cml_CVector_false_constructor_aData_size(int);
	void test_cml_CVector_false_constructor_acData_size(int);
	void test_cml_CVector_false_constructor_CVector(int);
	void test_cml_CVector_false_constructor_CArrayStorage(int);

	void test_cml_CVector_false_operator_assign_1(int);
	void test_cml_CVector_false_operator_assign_2(int);
	void test_cml_CVector_false_operator_assign_3(int);
	void test_cml_CVector_false_clear(int);
	void test_cml_CVector_false_empty(int);
	void test_cml_CVector_false_full(int);
	void test_cml_CVector_false_back_1(int);
	void test_cml_CVector_false_back_2(int);
	void test_cml_CVector_false_resize(int);
	void test_cml_CVector_false_resize_uninitialized(int);
	void test_cml_CVector_false_assign(int);
	void test_cml_CVector_false_push_back_1(int);
	void test_cml_CVector_false_push_back_2(int);
	void test_cml_CVector_false_pop_back_1(int);
	void test_cml_CVector_false_pop_back_2(int);
	void test_cml_CVector_false_insert(int);
	void test_cml_CVector_false_erase(int);
	void test_cml_CVector_false_insert_templatetype(int);
};

/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_stl_vector(void)
{
	TEST_CLASS_VECTOR test_object;

	std::cout << "******** Start Testing: Vector Library functions ********\n\n";
	fprintf(fpTest, "******** Start Testing: Vector Library functions ********\n\n");

	test_object.run_tests_vector();

	std::cout << "End of Testing: Vector Library functions\n\n";
	fprintf(fpTest, "End of Testing: Vector Library functions\n\n");

	return;
}

/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS_VECTOR::run_tests_vector()
{

	//test_cml_CVector_false_constructor(1);
	//test_cml_CVector_false_constructor_aData(1);
	//test_cml_CVector_false_constructor_acData(1);
	//test_cml_CVector_false_constructor_aData_size(1);
	//test_cml_CVector_false_constructor_acData_size(1);
	//test_cml_CVector_false_constructor_CVector(1);
	//test_cml_CVector_false_constructor_CArrayStorage(1);

	test_cml_CVector_false_operator_assign_1(1);
	test_cml_CVector_false_operator_assign_2(1);
	//test_cml_CVector_false_operator_assign_3(1);
	test_cml_CVector_false_clear(1);
	//test_cml_CVector_false_empty(1);
	//test_cml_CVector_false_full(1);
	test_cml_CVector_false_back_1(1);
	test_cml_CVector_false_back_2(1);
	//test_cml_CVector_false_resize(1);
	//test_cml_CVector_false_resize_uninitialized(1);
	test_cml_CVector_false_assign(1);
	test_cml_CVector_false_push_back_1(1);
	//test_cml_CVector_false_push_back_2(1);
	test_cml_CVector_false_pop_back_1(1);
	//test_cml_CVector_false_pop_back_2(1);
	test_cml_CVector_false_insert(1);
	test_cml_CVector_false_erase(1);
	/*test_cml_CVector_false_insert_templatetype(1);*/

}

/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/
#if 0
void TEST_CLASS_VECTOR::test_cml_CVector_false_constructor(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CVector<sint32, 5, false>_constructor",
			"Description: \
			- cml_stl_vector.h : CVector::CVector() \
			- Testing: interface, boundary_condition \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CVector object is generated with the right size and data be writen and read"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CVector<sint32 ,5, false> TestVector;

		/* Test case checks */

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_VECTOR::test_cml_CVector_false_constructor_aData(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CVector<sint32, 5, false>_constructor( data[] )",
			"Description: \
			- cml_stl_vector.h : CVector::CVector( data[] ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CVector object is generated with the right size and data be writen and read"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();
		sint32 vector[5] = { 1, 2, 3, 4, 5 };
		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CVector<sint32 ,5, false> TestVector( vector );

		/* Test case checks */

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_VECTOR::test_cml_CVector_false_constructor_acData(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CVector<sint32, 5, false>_constructor( const data[] )",
			"Description: \
			- cml_stl_vector.h : CVector::CVector( const data[] ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CVector object is generated with the right size and data be writen and read"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();
		const sint32 vector[5] = { 1, 2, 3, 4, 5 };
		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CVector<sint32 ,5, false> TestVector( vector );

		/* Test case checks */

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_VECTOR::test_cml_CVector_false_constructor_aData_size(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CVector<sint32, 5, false>_constructor( data[], size)",
			"Description: \
			- cml_stl_vector.h : CVector::CVector( data[], size ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CVector object is generated with the right size and data be writen and read"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();
		sint32 vector[5] = { 1, 2, 3, 4, 5 };
		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CVector<sint32 ,5, false> TestVector( vector,5 );

		/* Test case checks */

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_VECTOR::test_cml_CVector_false_constructor_acData_size(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CVector<sint32, 5, false>_constructor( const data[], size )",
			"Description: \
			- cml_stl_vector.h : CVector::CVector( const data[], size ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CVector object is generated with the right size and data be writen and read"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();
		const sint32 vector[5] = { 1, 2, 3, 4, 5 };
		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CVector<sint32 ,5, false> TestVector( vector, 5 );

		/* Test case checks */

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_VECTOR::test_cml_CVector_false_constructor_CVector(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CVector<sint32, 5, false>_constructor( CVector )",
			"Description: \
			- cml_stl_vector.h : CVector::CVector( CVector ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CVector object is generated with the right size and data be writen and read"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();
		sint32 vector[5] = { 1, 2, 3, 4, 5 };
		cml::CVector<sint32 ,5, false> TestVector( vector, 5 );
		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CVector<sint32 ,5, false> TestVector1( TestVector );

		/* Test case checks */

		CHECK_U_INT(TestVector[0], TestVector[0]);
		CHECK_U_INT(TestVector[1], TestVector[1]);
		CHECK_U_INT(TestVector[2], TestVector[2]);
		CHECK_U_INT(TestVector[3], TestVector[3]);
		CHECK_U_INT(TestVector[4], TestVector[4]);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_VECTOR::test_cml_CVector_false_constructor_CArrayStorage(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CVector<sint32, 5, false>_constructor( CVector )",
			"Description: \
			- cml_stl_vector.h : CVector::CVector( CVector ) \
			- Testing: interface \
			- Overview: verify that the constructor works properly and a buffer for data is provided \
			- Entry conditions: - \
			- Expected results: a CVector object is generated with the right size and data be writen and read"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();
		sint32 vector[5] = { 1, 2, 3, 4, 5 };
		cml::CArrayStorage<sint32 ,5, false> TestVector( vector );
		/* Set expected values for global data checks */

		/* Test case data declarations */

		/* Call SUT */
		cml::CVector<sint32 ,5, false> TestVector1( TestVector );

		/* Test case checks */

		CHECK_U_INT(TestVector[0], TestVector[0]);
		CHECK_U_INT(TestVector[1], TestVector[1]);
		CHECK_U_INT(TestVector[2], TestVector[2]);
		CHECK_U_INT(TestVector[3], TestVector[3]);
		CHECK_U_INT(TestVector[4], TestVector[4]);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}
#endif 
void TEST_CLASS_VECTOR::test_cml_CVector_false_operator_assign_1(int doIt)
{
	std::cout << "START ---> test_cml_CVector_false_operator_assign_1\n\n";		
	fprintf(fpTest, "START ---> test_cml_CVector_false_operator_assign_1\n\n");

	fprintf(fpTest, "Function Name ---> operator=(CVector)  \n\n");

	if (doIt) {

		std::cout << "Test Case ---> test_cml_CVector_false_operator_assign_1_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CVector_false_operator_assign_1_001\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Set global data */
		initialise_global_data();
		float32 vector1[5] = { 1.f, 2.f, 3.f, 4.f, 5.f };
		float32 vector2[5] = { 0.f, 0.f, 0.f, 0.f, 0.f };
		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CVector<float32, 5, false> TestVector2(vector1,5);
		cml::CVector<float32, 5, false> TestVector(vector2,5);
		uint8 TestVector_size, TestVector2_size;

		/* Input Vector */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float32, 5, false >( TestVector);
		check__vArrayPrint_to_File< float32, 5, false >( TestVector, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__vArrayPrint_to_console< float32, 5, false >( TestVector2);
		check__vArrayPrint_to_File< float32, 5, false >( TestVector2, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestVector = TestVector2;

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		TestVector_size = TestVector.size();
		TestVector2_size = TestVector2.size();

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console< float32, 5, false >( TestVector);
		check__vArrayPrint_to_File< float32, 5, false >( TestVector, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestVector,TestVector2);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n";    
			fprintf(fpTest, "Status ---> FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
	}
	std::cout << "END ---> test_cml_CVector_false_operator_assign_1\n\n";
	fprintf(fpTest, "END ---> test_cml_CVector_false_operator_assign_1\n\n");
}

void TEST_CLASS_VECTOR::test_cml_CVector_false_operator_assign_2(int doIt)
{
	std::cout << "START ---> test_cml_CVector_false_operator_assign_2\n\n";		
	fprintf(fpTest, "START ---> test_cml_CVector_false_operator_assign_2\n\n");

	fprintf(fpTest, "Function Name ---> operator=(CVector<SIZE>)  \n\n");

	if (doIt) {

		std::cout << "Test Case ---> test_cml_CVector_false_operator_assign_2_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CVector_false_operator_assign_2_001\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Set global data */
		initialise_global_data();
		float32 vector1[5] = { 1.f, 2.f, 3.f, 4.f, 5.f };
		float32 vector2[5] = { 0.f, 0.f, 0.f, 0.f, 0.f };
		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CVector<float32, 5, true> TestVector2(vector1,5);
		cml::CVector<float32, 5, true> TestVector(vector2,5);
		uint8 TestVector_size, TestVector2_size;
		
		/* Input Vector */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float32, 5, true >( TestVector);
		check__vArrayPrint_to_File< float32, 5, true >( TestVector, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__vArrayPrint_to_console< float32, 5, true >( TestVector2);
		check__vArrayPrint_to_File< float32, 5, true >( TestVector2, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestVector = TestVector2;

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		TestVector_size = TestVector.size();
		TestVector2_size = TestVector2.size();

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console< float32, 5, true >( TestVector);
		check__vArrayPrint_to_File< float32, 5, true >( TestVector, fpTest);	
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestVector,TestVector2);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n";    
			fprintf(fpTest, "Status ---> FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
	}
	std::cout << "END ---> test_cml_CVector_false_operator_assign_2\n\n";
	fprintf(fpTest, "END ---> test_cml_CVector_false_operator_assign_2\n\n");
}

#if 0

void TEST_CLASS_VECTOR::test_cml_CVector_false_operator_assign_3(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CVector<const float32, 5, false>_operator=( CVector )",
			"Description: \
			- cml_stl_vector.h : CVector::operator=( CVector ) \
			- Testing: interface \
			- Overview: verify that the operator= works properly and copies the data\
			- Entry conditions: - \
			- Expected results: the data of the object and the operand are the same"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();
		//            const float32  vector1[5] = { 1.f, 2.f, 3.f, 4.f, 5.f };
		//        	float32 vector2[5] = { 0.f, 0.f, 0.f, 0.f, 0.f };
		//            /* Set expected values for global data checks */
		//
		//            /* Test case data declarations */
		//            cml::CVector<const float32, 5, false> TestVector2(vector1,5);
		//            cml::CVector<float32, 5, false> TestVector(vector2,5);
		//            uint8 TestVector_size, TestVector2_size;
		//
		//            /* Call SUT */
		//
		//            TestVector = TestVector2;
		//            TestVector_size = TestVector.size();
		//            TestVector2_size = TestVector2.size();
		//
		//            /* Test case checks */
		//
		//            CHECK_DOUBLE(TestVector[0], TestVector2[0]);
		//            CHECK_DOUBLE(TestVector[1], TestVector2[1]);
		//            CHECK_DOUBLE(TestVector[2], TestVector2[2]);
		//            CHECK_DOUBLE(TestVector[3], TestVector2[3]);
		//            CHECK_DOUBLE(TestVector[4], TestVector2[4]);
		//            CHECK_U_INT(TestVector_size, TestVector2_size);

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}
#endif

void TEST_CLASS_VECTOR::test_cml_CVector_false_clear(int doIt)
{
	std::cout << "START ---> test_cml_CVector_false_clear\n\n";		
	fprintf(fpTest, "START ---> test_cml_CVector_false_clear\n\n");

	fprintf(fpTest, "Function Name ---> operator=(CVector)  \n\n");

	if (doIt) {

		std::cout << "Test Case ---> test_cml_CVector_false_clear_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CVector_false_clear_001\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Set global data */
		initialise_global_data();

		float32 vector1[5] = { 1.f, 2.f, 3.f, 4.f, 5.f };
		
		sint32 size,expected_size;
		expected_size = 0;
				
		/* Test case data declarations */
		cml::CVector<float32, 5, false> TestVector( vector1, 5 );

		/* Input Vector */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float32, 5, false >( TestVector);
		check__vArrayPrint_to_File< float32, 5, false >( TestVector, fpTest);
		
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
		TestVector.clear();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		size = TestVector.size();

		/* Actual Result Array */
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
		returnValue = check__boCompare(size,expected_size);;

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n";    
			fprintf(fpTest, "Status ---> FAIL\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
	}
	std::cout << "END ---> test_cml_CVector_false_clear\n\n";
	fprintf(fpTest, "END ---> test_cml_CVector_false_clear\n\n");
}

#if 0
void TEST_CLASS_VECTOR::test_cml_CVector_false_empty(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CVector<float32, 5, false>_empty()",
			"Description: \
			- cml_stl_vector.h : CVector::empty() \
			- Testing: interface \
			- Overview: verify that empty() works properly \
			- Entry conditions: - \
			- Expected results: the right information is returned"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		float32 vector1[5] = { 1.f, 2.f, 3.f, 4.f, 5.f };
		cml::CVector<float32, 5, false> TestVector( vector1, 5 );

		/* Call SUT */
		/* Test case checks */
		CHECK( TestVector.empty(), false );

		TestVector.clear();

		/* Call SUT */
		/* Test case checks */
		CHECK( TestVector.empty(), true );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_VECTOR::test_cml_CVector_false_full(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CVector<float32, 5, false>_full()",
			"Description: \
			- cml_stl_vector.h : CVector::full() \
			- Testing: interface \
			- Overview: verify that full() works properly \
			- Entry conditions: - \
			- Expected results: the right information is returned"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		float32 vector1[5] = { 1.f, 2.f, 3.f, 4.f, 5.f };
		cml::CVector<float32, 5, false> TestVector( vector1, 5 );

		/* Call SUT */
		/* Test case checks */

		CHECK( TestVector.full(), true );

		TestVector.clear();

		/* Call SUT */
		/* Test case checks */
		CHECK(  TestVector.full(), false );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}
#endif
void TEST_CLASS_VECTOR::test_cml_CVector_false_back_1(int doIt)
{
	std::cout << "START ---> test_cml_CVector_false_back_1\n\n";		
	fprintf(fpTest, "START ---> test_cml_CVector_false_back_1\n\n");

	fprintf(fpTest, "Function Name ---> back()  \n\n");

	if (doIt) {

		std::cout << "Test Case ---> test_cml_CVector_false_back_1_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CVector_false_back_1_001\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		float32 vector1[5] = { 1.f, 2.f, 3.f, 4.f, 5.f };
		float32 result,expected_result;
		
		expected_result = 3;

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CVector<float32, 5, false> TestVector( vector1, 3 );

		/* Input Vector */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float32, 5, false >( TestVector);
		check__vArrayPrint_to_File< float32, 5, false >( TestVector, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_result);
		check__PrintValue_to_File( expected_result, fpTest);	
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		result = TestVector.back();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);	
		fprintf(fpTest, "\n\n");
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_result);;

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
	std::cout << "END ---> test_cml_CVector_false_back_1\n\n";
	fprintf(fpTest, "END ---> test_cml_CVector_false_back_1\n\n");
}
void TEST_CLASS_VECTOR::test_cml_CVector_false_back_2(int doIt)
{
	std::cout << "START ---> test_cml_CVector_false_back_2\n\n";		
	fprintf(fpTest, "START ---> test_cml_CVector_false_back_2\n\n");

	fprintf(fpTest, "Function Name ---> back()true  \n\n");

	if (doIt) {

		std::cout << "Test Case ---> test_cml_CVector_false_back_2_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CVector_false_back_2_001\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		float32 vector1[5] = { 1.f, 2.f, 3.f, 4.f, 5.f };
		float32 result,expected_result;
		
		expected_result = 3;

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CVector<float32, 5, true> TestVector( vector1, 3 );

		/* Input Vector */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float32, 5, true >( TestVector);
		check__vArrayPrint_to_File< float32, 5, true >( TestVector, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_result);
		check__PrintValue_to_File( expected_result, fpTest);	
		fprintf(fpTest, "\n\n");	

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		result = TestVector.back();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);	
		fprintf(fpTest, "\n\n");
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_result);;

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
	std::cout << "END ---> test_cml_CVector_false_back_2\n\n";
	fprintf(fpTest, "END ---> test_cml_CVector_false_back_2\n\n");
}

#if 0 
void TEST_CLASS_VECTOR::test_cml_CVector_false_resize(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CVector<float32, 5, false>_resize()",
			"Description: \
			- cml_stl_vector.h : CVector::resize() \
			- Testing: interface, boundary_condition \
			- Overview: verify that resize() works properly \
			- Entry conditions: - \
			- Expected results: the size of the CVector object is changed, new elements are initialized"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		float32 vector1[5] = { 1.f, 2.f, 3.f, 4.f, 5.f };

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CVector<float32, 5, false> TestVector( vector1, 3 );

		/* Call SUT */
		/* Test case checks */
		CHECK( TestVector.back(), 3 );

		TestVector.resize( 4, 4 );


		/* Call SUT */
		/* Test case checks */
		CHECK( TestVector.back(), 4 );

		TestVector.resize( 2 );

		/* Call SUT */
		/* Test case checks */
		CHECK( TestVector.back(), 2 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_VECTOR::test_cml_CVector_false_resize_uninitialized(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CVector<float32, 5, false>_resize()",
			"Description: \
			- cml_stl_vector.h : CVector::resize() \
			- Testing: interface, boundary_condition \
			- Overview: verify that resize() works properly \
			- Entry conditions: - \
			- Expected results: the size of the CVector object is changed, new elements are initialized"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		float32 vector1[5] = { 1.f, 2.f, 3.f, 4.f, 5.f };

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CVector<float32, 5, false> TestVector( vector1, 3 );

		/* Call SUT */
		/* Test case checks */
		CHECK( TestVector.back(), 3 );

		TestVector.resize_uninitialized( 4 );


		/* Call SUT */
		/* Test case checks */
		//CHECK( TestVector.back(), 4 );

		TestVector.resize_uninitialized( 2 );

		/* Call SUT */
		/* Test case checks */
		//CHECK( TestVector.back(), 2 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}
#endif
void TEST_CLASS_VECTOR::test_cml_CVector_false_assign(int doIt)
{
	std::cout << "START ---> test_cml_CVector_false_assign\n\n";		
	fprintf(fpTest, "START ---> test_cml_CVector_false_assign\n\n");

	fprintf(fpTest, "Function Name ---> assign()  \n\n");

	if (doIt) {

		std::cout << "Test Case ---> test_cml_CVector_false_assign_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CVector_false_assign_001\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		/* Set global data */
		initialise_global_data();
		float32 vector1[5] = { 1.f, 2.f, 3.f, 4.f, 5.f };
		float32 vector2[5] = { 0.f, 0.f, 0.f, 0.f, 0.f };
		cml::CVector<float32, 5, false>::size_type n = 4;
		cml::CVector<float32, 5, false>::const_reference u = 0;
		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CVector<float32, 5, false> TestVector2(vector2,5);
		cml::CVector<float32, 5, false> TestVector(vector1,5);

		/* Input Vector */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vArrayPrint_to_console< float32, 5, false >( TestVector);
		check__vArrayPrint_to_File< float32, 5, false >( TestVector, fpTest);
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__vArrayPrint_to_console< float32, 5, false >( TestVector2);
		check__vArrayPrint_to_File< float32, 5, false >( TestVector2, fpTest);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		TestVector.assign(n,u);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console< float32, 5, false >( TestVector);
		check__vArrayPrint_to_File< float32, 5, false >( TestVector, fpTest);	
				
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(TestVector,TestVector2);
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
		fprintf(fpTest, "Remarks ---> Difference in implementation of std::fill and assign function(issue in accessing last element of array by index operator)\n\n");
		std::cout << "Remarks ---> Difference in implementation of std::fill and assign function(issue in accessing last element of array by index operator)\n\n";
	}
	std::cout << "END ---> test_cml_CVector_false_assign\n\n";
	fprintf(fpTest, "END ---> test_cml_CVector_false_assign\n\n");
}

void TEST_CLASS_VECTOR::test_cml_CVector_false_push_back_1(int doIt)
{
	std::cout << "START ---> test_cml_CVector_false_push_back_1\n\n";		
	fprintf(fpTest, "START ---> test_cml_CVector_false_push_back_1\n\n");

	fprintf(fpTest, "Function Name ---> push_back(data)  \n\n");

	if (doIt) {

		std::cout << "Test Case ---> test_cml_CVector_false_push_back_1_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CVector_false_push_back_1_001\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		float32 result,expected_result,size;
		
		/* Set global data */
		initialise_global_data();
		expected_result = 1;
		
		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CVector<float32, 5, false> TestVector;
		size = TestVector.size();

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

		check__PrintValue_to_console( expected_result);
		check__PrintValue_to_File( expected_result, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestVector.push_back( 9 );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		result = TestVector.size();

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);	
		fprintf(fpTest, "\n\n");
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_result);;

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
	std::cout << "END ---> test_cml_CVector_false_push_back_1\n\n";
	fprintf(fpTest, "END ---> test_cml_CVector_false_push_back_1\n\n");
}

#if 0
void TEST_CLASS_VECTOR::test_cml_CVector_false_push_back_2(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CVector<float32, 5, false>_push_back()",
			"Description: \
			- cml_stl_vector.h : CVector::push_back() \
			- Testing: interface, boundary_condition \
			- Overview: verify that push_back() works properly \
			- Entry conditions: - \
			- Expected results: the right elements are written with the given value"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();

		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CVector<float32, 5, false> TestVector;

		/* Call SUT */
		TestVector.push_back() = 9;

		CHECK_U_INT( TestVector.size(), 1 );

		for( int i=0; i<4; i++ )
		{
			TestVector.push_back() = 5;
		}

		CHECK_U_INT( TestVector.size(), 5 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}
#endif

void TEST_CLASS_VECTOR::test_cml_CVector_false_pop_back_1(int doIt)
{
	std::cout << "START ---> test_cml_CVector_false_pop_back_1\n\n";		
	fprintf(fpTest, "START ---> test_cml_CVector_false_pop_back_1\n\n");

	fprintf(fpTest, "Function Name ---> pop_back()  \n\n");

	if (doIt) {

		std::cout << "Test Case ---> test_cml_CVector_false_pop_back_1_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CVector_false_pop_back_1_001\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");

		float32 result,expected_result,size;

		/* Set global data */
		initialise_global_data();
		float32 vector[5] = { 1.f, 2.f, 3.f, 4.f, 5.f };
		expected_result = 4;
		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CVector<float32, 5, false> TestVector(vector,5);

		size = TestVector.size();

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

		check__PrintValue_to_console( expected_result);
		check__PrintValue_to_File( expected_result, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		TestVector.pop_back();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		result = TestVector.size();

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);	
		fprintf(fpTest, "\n\n");
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_result);;

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
	std::cout << "END ---> test_cml_CVector_false_pop_back_1\n\n";
	fprintf(fpTest, "END ---> test_cml_CVector_false_pop_back_1\n\n");
}

#if 0 
void TEST_CLASS_VECTOR::test_cml_CVector_false_pop_back_2(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CVector<float32, 5, false>_push_back()",
			"Description: \
			- cml_stl_vector.h : CVector::push_back() \
			- Testing: interface, boundary_condition \
			- Overview: verify that push_back() works properly \
			- Entry conditions: - \
			- Expected results: the right elements are written with the given value"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();
		float32 vector[5] = { 1.f, 2.f, 3.f, 4.f, 5.f };
		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CVector<float32, 5, false> TestVector(vector,5);

		/* Call SUT */
		TestVector.pop_back(1);

		CHECK_U_INT( TestVector.size(), 4 );

		for( int i=1; i<3; i++ )
		{
			TestVector.pop_back(i);
		}

		CHECK_U_INT( TestVector.size(), 1 );

		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}
#endif 

void TEST_CLASS_VECTOR::test_cml_CVector_false_insert(int doIt)
{
	std::cout << "START ---> test_cml_CVector_false_insert\n\n";		
	fprintf(fpTest, "START ---> test_cml_CVector_false_insert\n\n");

	fprintf(fpTest, "Function Name ---> insert()  \n\n");

	if (doIt) {

		std::cout << "Test Case ---> test_cml_CVector_false_insert\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CVector_false_insert\n\n");

		std::cout << "Data Dimension ---> 2 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 2 \n\n");

		float32 result,expected_result,size;

		/* Set global data */
		initialise_global_data();
		
		/* Set expected values for global data checks */

		/* Test case data declarations */

		cml::CVector<float32, 2, false> TestVector;
		expected_result = 2;
		size = TestVector.size();

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

		check__PrintValue_to_console( expected_result);
		check__PrintValue_to_File( expected_result, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestVector.insert(TestVector.begin(), 2.f);
		TestVector.insert(TestVector.begin(), 1.f);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		result = TestVector.size();

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_result);;

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
	std::cout << "END ---> test_cml_CVector_false_insert \n\n";
	fprintf(fpTest, "END ---> test_cml_CVector_false_insert \n\n");
}

void TEST_CLASS_VECTOR::test_cml_CVector_false_erase(int doIt)
{
	std::cout << "START ---> test_cml_CVector_false_erase\n\n";		
	fprintf(fpTest, "START ---> test_cml_CVector_false_erase\n\n");

	fprintf(fpTest, "Function Name ---> erase()  \n\n");

	if (doIt) {

		std::cout << "Test Case ---> test_cml_CVector_false_erase\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CVector_false_erase\n\n");

		std::cout << "Data Dimension ---> 10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 10 \n\n");

		float32 result,expected_result,size;

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CVector<float32, 10, false> TestVector;

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		TestVector.insert(TestVector.begin(), 2.f);
		TestVector.insert(TestVector.begin(), 1.f);
		TestVector.insert(TestVector.end(), 4.f );
		TestVector.insert(TestVector.end(), 5.f );
		TestVector.insert(TestVector.begin()+2, 3.f);
		TestVector.insert(TestVector.end(), 6.f );
		TestVector.insert(TestVector.end(), 7.f );
		TestVector.insert(TestVector.end(), 8.f );
		TestVector.insert(TestVector.end(), 9.f );
		TestVector.insert(TestVector.end(), 10.f );

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		expected_result = 9;

		size = TestVector.size();
		
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

		check__PrintValue_to_console( expected_result);
		check__PrintValue_to_File( expected_result, fpTest);
		fprintf(fpTest, "\n\n");

		TestVector.erase( TestVector.begin() );
		
		result = TestVector.size();

		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(result,expected_result);;

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
	std::cout << "END ---> test_cml_CVector_false_erase\n\n";
	fprintf(fpTest, "END ---> test_cml_CVector_false_erase\n\n");
}

#if 0
void TEST_CLASS_VECTOR::test_cml_CVector_false_insert_templatetype(int doIt)
{
	std::cout << "START ---> test_cml_CVector_false_insert_templatetype\n\n";		
	fprintf(fpTest, "START ---> test_cml_CVector_false_insert_templatetype\n\n");

	fprintf(fpTest, "Function Name ---> CVector::insert<cml::CVector<float32, 5, false>::const_reference>()  \n\n");

	if (doIt) {

		std::cout << "Test Case ---> test_cml_CVector_false_insert_templatetype_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CVector_false_insert_templatetype_001\n\n");

		std::cout << "Data Dimension ---> 5 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 5 \n\n");


		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */

		/* Test case data declarations */
		int size,expected_result,result;
		float32 vector[5] = { 1.f, 2.f, 3.f, 4.f, 5.f };
		float32 vector1[5] = { 0.f, 0.f, 0.f, 0.f, 0.f };
		//float32 result[8] ={1.f, 2.f, 3.f,0.f, 0.f, 0.f, 0.f, 0.f };
		cml::CVector<float32, 10, false> TestVector(vector1, 5);
		cml::CVector<float32, 5, false> TestVector1(vector, 5);
		//cml::CVector<float32, 8, false> expected_result(result, 8);

		cml::CVector<float32, 5, false>::it iterator1 = TestVector1.begin();
		cml::CVector<float32, 5, false>::it iterator2 = TestVector1.begin()+3;
		
		/* Input Vector */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");

		size = TestVector.size();

		check__PrintValue_to_console( size);
		check__PrintValue_to_File( size, fpTest);

		/*check__vArrayPrint_to_console< float32, 5, false >( TestVector);
		check__vArrayPrint_to_File< float32, 5, false >( TestVector, fpTest);
		
		std::cout << "input2 = \n";		
		fprintf(fpTest, "input2 = \n");
		
		check__vArrayPrint_to_console< float32, 5, false >( TestVector1);
		check__vArrayPrint_to_File< float32, 5, false >( TestVector1, fpTest);*/
		expected_result = 8;
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console( expected_result);
		check__PrintValue_to_File( expected_result, fpTest);
	
		//check__vArrayPrint_to_console< float32, 8, false >( expected_result);
		//check__vArrayPrint_to_File< float32, 8, false >( expected_result, fpTest);
		

		/* Call SUT */
		TestVector.insert<cml::CVector<float32, 5, false>::it>(TestVector.begin(), iterator1, iterator2 );

		/*CHECK_U_INT( TestVector.size(), 8 );
		CHECK_DOUBLE( TestVector[0], 1.f);
		CHECK_DOUBLE( TestVector[1], 2.f);
		CHECK_DOUBLE( TestVector[2], 3.f);*/
		result = TestVector.size();
		/* Actual Result Array */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		//check__vArrayPrint_to_console< float32, 8, false >( TestVector);
		//check__vArrayPrint_to_File< float32, 8, false >( TestVector, fpTest);	
		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
				
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		//returnValue = check__vArrayCompare(TestVector,TestVector2);
		returnValue = check__boCompare(result,expected_result);
		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

		/* Checks on global data */
		check_global_data();

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> \n\n");
		std::cout << "Remarks ---> \n\n";
	}
	std::cout << "END ---> test_cml_CVector_false_insert_templatetype\n\n";
	fprintf(fpTest, "END ---> test_cml_CVector_false_insert_templatetype\n\n");
}

#endif

#if 0
void TEST_CLASS_VECTOR::test_cml_CVector_false_insert_templatetype(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CVector<float32, 5, false>_insert<cml::CVector<float32, 5, false>::const_reference>()",
			"Description: \
			- cml_stl_vector.h : CVector::insert<cml::CVector<float32, 5, false>::const_reference>() \
			- Testing: interface, boundary_condition \
			- Overview: verify that insert<cml::CVector<float32, 5, false>::const_reference>() works properly \
			- Entry conditions: - \
			- Expected results: the size of the CVector is increased, the new data is stored"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();
		/* Set expected values for global data checks */

		/* Test case data declarations */
		float32 vector[5] = { 1.f, 2.f, 3.f, 4.f, 5.f };
		float32 vector1[5] = { 0.f, 0.f, 0.f, 0.f, 0.f };
		cml::CVector<float32, 10, false> TestVector(vector1, 5);
		cml::CVector<float32, 5, false> TestVector1(vector, 5);

		cml::CVector<float32, 5, false>::it iterator1 = TestVector1.begin();
		cml::CVector<float32, 5, false>::it iterator2 = TestVector1.begin()+3;

		/* Call SUT */
		TestVector.insert<cml::CVector<float32, 5, false>::it>(TestVector.begin(), iterator1, iterator2 );

		CHECK_U_INT( TestVector.size(), 8 );
		CHECK_DOUBLE( TestVector[0], 1.f);
		CHECK_DOUBLE( TestVector[1], 2.f);
		CHECK_DOUBLE( TestVector[2], 3.f);


		/* Checks on global data */
		check_global_data();

		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_VECTOR::test_cml_CVector_false_erase(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_001_cml_CVector<float32, 5, false>_erase()",
			"Description: \
			- cml_stl_vector.h : CVector::erase() \
			- Testing: interface, boundary_condition \
			- Overview: verify that erase() works properly \
			- Entry conditions: - \
			- Expected results: the size of the CVector is decreased, the data is deleted"
			);

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Set global data */
			initialise_global_data();
		/* Set expected values for global data checks */

		/* Test case data declarations */
		cml::CVector<float32, 10, false> TestVector;

		/* Call SUT */
		TestVector.insert(TestVector.begin(), 2.f);
		TestVector.insert(TestVector.begin(), 1.f);
		TestVector.insert(TestVector.end(), 4.f );
		TestVector.insert(TestVector.end(), 5.f );
		TestVector.insert(TestVector.begin()+2, 3.f);
		TestVector.insert(TestVector.end(), 6.f );
		TestVector.insert(TestVector.end(), 7.f );
		TestVector.insert(TestVector.end(), 8.f );
		TestVector.insert(TestVector.end(), 9.f );
		TestVector.insert(TestVector.end(), 10.f );



		CHECK_U_INT( TestVector.size(), 10 );
		TestVector.erase( TestVector.begin() );
		CHECK_U_INT( TestVector.size(), 9 );

		TestVector.erase(TestVector.begin()+3 );
		CHECK_U_INT( TestVector.size(), 8 );

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
