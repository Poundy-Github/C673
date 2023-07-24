/*****************************************************************************/
/*                            Cantata Test Script                            */
/*****************************************************************************/
/*
 *    Filename: test_cml_stl_array2d.cpp
 *    Author: uidr5285
 *    Generated on: 11-Feb-2016 11:53:47
 *    Generated from: cml_stl_array2d.cpp
 */
/*****************************************************************************/
/* Environment Definition                                                    */
/*****************************************************************************/

#define TEST_SCRIPT_GENERATOR 2

/* Include files from software under test */
//#define uint64 unsigned int long long
//#include "cml_stl_array2d.h"

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
extern void test_Dummy(void);

/* None */

/* Global data */
#define ArrayData0                                           \
{ /*      1    2    3    4    5    6    7    8    9   10  */ \
  /* 1*/  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    \
  /* 2*/  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    \
  /* 3*/  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    \
  /* 4*/  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    \
  /* 5*/  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    \
  /* 6*/  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    \
  /* 7*/  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    \
  /* 8*/  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    \
  /* 9*/  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    \
  /*10*/  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    \
  /*11*/  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    \
  /*12*/  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    \
};                                                           \

char const TEST_racData0[] = ArrayData0;
char       TEST_acData0[]  = ArrayData0;


#define ArrayData9                                           \
{ /*      1    2    3    4    5    6    7    8    9   10  */ \
  /* 1*/  9,   9,   9,   9,   9,   9,   9,   9,   9,   9,    \
  /* 2*/  9,   9,   9,   9,   9,   9,   9,   9,   9,   9,    \
  /* 3*/  9,   9,   9,   9,   9,   9,   9,   9,   9,   9,    \
  /* 4*/  9,   9,   9,   9,   9,   9,   9,   9,   9,   9,    \
  /* 5*/  9,   9,   9,   9,   9,   9,   9,   9,   9,   9,    \
  /* 6*/  9,   9,   9,   9,   9,   9,   9,   9,   9,   9,    \
  /* 7*/  9,   9,   9,   9,   9,   9,   9,   9,   9,   9,    \
  /* 8*/  9,   9,   9,   9,   9,   9,   9,   9,   9,   9,    \
  /* 9*/  9,   9,   9,   9,   9,   9,   9,   9,   9,   9,    \
  /*10*/  9,   9,   9,   9,   9,   9,   9,   9,   9,   9,    \
  /*11*/  9,   9,   9,   9,   9,   9,   9,   9,   9,   9,    \
  /*12*/  9,   9,   9,   9,   9,   9,   9,   9,   9,   9,    \
};                                                           \

      char TEST_acData9[]  = ArrayData9;
const char TEST_racData9[] = ArrayData9;

#define ArrayData123                                          \
  /*       1    2    3    4    5    6    7    8    9   10  */ \
  /* 1*/   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,    \
  /* 2*/  11,  12,  13,  14,  15,  16,  17,  18,  19,  20,    \
  /* 3*/  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,    \
  /* 4*/  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,    \
  /* 5*/  41,  42,  43,  44,  45,  46,  47,  48,  49,  50,    \
  /* 6*/  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,    \
  /* 7*/  61,  62,  63,  64,  65,  66,  67,  68,  69,  70,    \
  /* 8*/  71,  72,  73,  74,  75,  76,  77,  78,  79,  80,    \
  /* 9*/  81,  82,  83,  84,  85,  86,  87,  88,  89,  90,    \
  /*10*/  91,  92,  93,  94,  95,  96,  97,  98,  99, 100,    \
  /*11*/ 101, 102, 103, 104, 105, 106, 107, 108, 109, 110,    \
  /*12*/ 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,    \

static char TEST_acData123[]     = { ArrayData123 };
static const char TEST_racData123[]    = { ArrayData123 };
static const char TEST_racData123org[] = { ArrayData123 };

static char TEST_acData123_3[]   = { ArrayData123 ArrayData123 ArrayData123 };

static int TEST_intData123[] = { ArrayData123 };

static short TEST_shortData123[] = { ArrayData123 };

static float TEST_floatData123[] = { ArrayData123 };


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
static void check__vArrayPrint_to_File( const cml::CArrayStorage<T ,COLS, EXT_MEM> &oArray, FILE *fpTest)
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

template < typename T, sint32 COLS, bool EXT_MEM >
static void check__vArrayPrint_to_console( const cml::CArrayStorage<T ,COLS, EXT_MEM> &oArray)
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

class CTestType3
{
public:
	char cData1;
	char cData2;
	char cData3;

	CTestType3(){ cData1 = cData2 = cData3 = -3; }
	CTestType3( char data1, char data2, char data3 )
	{ cData1 = data1; cData2 = data2; cData3 = data3; }

private:
/*
	CTestType3( const CTestType3& rhs );
	CTestType3& operator=( const CTestType3& rhs);
*/
};

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
class TEST_CLASS_ARRAY2D
{
public:
    void run_tests_array2d();

    void test_cml_CArray2D_false_constructor(int doIt);
    void test_cml_CArray2D_copy_constructor_01(int doIt);
    void test_cml_CArray2D_copy_constructor_02(int doIt);
    void test_cml_CArray2D_copy_constructor_03(int doIt);
    void test_cml_CArray2D_copy_constructor_04(int doIt);
    void test_cml_CArray2D_copy_constructor_05(int doIt);
    void test_cml_CArray2D_copy_constructor_06(int doIt);
    void test_cml_CArray2D_rows(int doIt);
    void test_cml_CArray2D_cols(int doIt);
    void test_cml_CArray2D_overload_assignment_operator_01(int doIt);
    void test_cml_CArray2D_overload_function_call_operator_01(int doIt);
    void test_cml_CArray2D_overload_function_call_operator_02(int doIt);
    void test_cml_CArray2D_at_01(int doIt);
    void test_cml_CArray2D_at_02(int doIt);
    void test_cml_CArray2D_rowBegin_01(int doIt);
    void test_cml_CArray2D_rowBegin_02(int doIt);
    void test_cml_CArray2D_cRowBegin(int doIt);
    void test_cml_CArray2D_rowEnd_01(int doIt);
    void test_cml_CArray2D_rowEnd_02(int doIt);
    void test_cml_CArray2D_cRowEnd(int doIt);
    void test_cml_CArray2D_colBegin_01(int doIt);
    void test_cml_CArray2D_colBegin_02(int doIt);
    void test_cml_CArray2D_cColBegin(int doIt);
    void test_cml_CArray2D_colEnd_01(int doIt);
    void test_cml_CArray2D_colEnd_02(int doIt);
    void test_cml_CArray2D_cColEnd(int doIt);
};

/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_stl_array2d(void)
{
	TEST_CLASS_ARRAY2D test_object;

	std::cout << "******** Start Testing: Array2d Library functions ********\n\n";
	fprintf(fpTest, "******** Start Testing: Array2d Library functions ********\n\n");

	test_object.run_tests_array2d();

	std::cout << "End of Testing: Array2d Library functions\n\n";
	fprintf(fpTest, "End of Testing: Array2d Library functions\n\n");

	return;
}

/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS_ARRAY2D::run_tests_array2d()
{
	/*test_cml_CArray2D_false_constructor(1);
	test_cml_CArray2D_copy_constructor_01(1);
	test_cml_CArray2D_copy_constructor_02(1);
	test_cml_CArray2D_copy_constructor_03(1);
	test_cml_CArray2D_copy_constructor_04(1);
	test_cml_CArray2D_copy_constructor_05(1);
	test_cml_CArray2D_copy_constructor_06(1);*/
	test_cml_CArray2D_rows(1);
	test_cml_CArray2D_cols(1);
	test_cml_CArray2D_overload_assignment_operator_01(1);
	test_cml_CArray2D_overload_function_call_operator_01(1);
	test_cml_CArray2D_overload_function_call_operator_02(1);
	test_cml_CArray2D_at_01(1);
	test_cml_CArray2D_at_02(1);
	test_cml_CArray2D_rowBegin_01(1);
	test_cml_CArray2D_rowBegin_02(1);
	test_cml_CArray2D_cRowBegin(1);
	test_cml_CArray2D_rowEnd_01(1);
	test_cml_CArray2D_rowEnd_02(1);
	test_cml_CArray2D_cRowEnd(1);
	test_cml_CArray2D_colBegin_01(1);
	test_cml_CArray2D_colBegin_02(1);
	test_cml_CArray2D_cColBegin(1);
	test_cml_CArray2D_colEnd_01(1);
	test_cml_CArray2D_colEnd_02(1);
	test_cml_CArray2D_cColEnd(1);
}

/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/
#if 0
/***** Testing Dummy Constructor *****/
void TEST_CLASS_ARRAY2D::test_cml_CArray2D_false_constructor(int doIt){
if (doIt) {
	/************************* Test Case 001 *************************/
    START_TEST("test_cml_CArray2D_constructor_001",
				"Description: \
				- cml_stl_array2d.h : CArray2D::CArray2D() \
				- Testing: interface \
				- Overview: Verify that the constructor works properly and a buffer for data is provided \
				- Data type for template: char\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

        	/* Test case data declarations */

            /* Set global data */
            initialise_global_data();

            /* Set expected values for global data checks */

            /* Call SUT */
            cml::CArray2D<char ,12, 10, false> *testObj = new cml::CArray2D<char ,12, 10, false>();

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj->size()), sint32(120) );

            testObj->fill( 0 );
            for(cml::CArray2D<char ,12, 10, false>::const_iterator it = testObj->begin(); it != testObj->end(); it++)
            {
            	CHECK_NAMED("cml::CArray2D<char ,12, 10, false> (Test Fill with 0)", char(*it), char(0));
            }

            testObj->fill( 9 );
            for(cml::CArray2D<char ,12, 10, false>::const_iterator it = testObj->begin(); it != testObj->end(); it++)
            {
            	CHECK_NAMED("cml::CArray2D<char ,12, 10, false> (Test Fill with 9)", char(*it), char(9));
            }

            /* Checks on global data */
            check_global_data();

            delete testObj;

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();

    /************************* Test Case 002 *************************/
    START_TEST("test_cml_CArray2D_constructor_002",
				"Description: \
				- cml_stl_array2d.h : CArray2D::CArray2D() \
				- Testing: interface \
				- Overview: Verify that the constructor works properly and a buffer for data is provided \
				- Data type for template: short\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<short ,12, 10, false> *testObj = new cml::CArray2D<short ,12, 10, false>();

			/* Test case checks */
			CHECK_NAMED( "Size", sint32(testObj->size()), sint32(120) );

			testObj->fill( 0 );
			for(cml::CArray2D<short ,12, 10, false>::const_iterator it = testObj->begin(); it != testObj->end(); it++)
			{
				CHECK_NAMED("cml::CArray2D<short ,12, 10, false> (Test Fill with 0)", short(*it), short(0));
			}

			testObj->fill( 9 );
			for(cml::CArray2D<short ,12, 10, false>::const_iterator it = testObj->begin(); it != testObj->end(); it++)
			{
				CHECK_NAMED("cml::CArray2D<short ,12, 10, false> (Test Fill with 9)", short(*it), short(9));
			}

			/* Checks on global data */
			check_global_data();

			delete testObj;

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();

    /************************* Test Case 003 *************************/
    START_TEST("test_cml_CArray2D_constructor_003",
				"Description: \
				- cml_stl_array2d.h : CArray2D::CArray2D() \
				- Testing: interface \
				- Overview: Verify that the constructor works properly and a buffer for data is provided \
				- Data type for template: int\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
            cml::CArray2D<int ,12, 10, false> *testObj = new cml::CArray2D<int ,12, 10, false>();

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj->size()), sint32(120) );

            testObj->fill( 0 );
            for(cml::CArray2D<int ,12, 10, false>::const_iterator it = testObj->begin(); it != testObj->end(); it++)
            {
            	CHECK_NAMED("cml::CArray2D<int ,12, 10, false> (Test Fill with 0)", int(*it), int(0));
            }

            testObj->fill( 9 );
            for(cml::CArray2D<int ,12, 10, false>::const_iterator it = testObj->begin(); it != testObj->end(); it++)
            {
            	CHECK_NAMED("cml::CArray2D<int ,12, 10, false> (Test Fill with 9)", int(*it), int(9));
            }

            /* Checks on global data */
            check_global_data();

            delete testObj;

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();

    /************************* Test Case 004 *************************/
    START_TEST("test_cml_CArray2D_constructor_004",
				"Description: \
				- cml_stl_array2d.h : CArray2D::CArray2D() \
				- Testing: interface \
				- Overview: Verify that the constructor works properly and a buffer for data is provided \
				- Data type for template: float\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
            cml::CArray2D<float ,12, 10, false> *testObj = new cml::CArray2D<float ,12, 10, false>();

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj->size()), sint32(120) );

            testObj->fill( 0.0f );
            for(cml::CArray2D<float ,12, 10, false>::const_iterator it = testObj->begin(); it != testObj->end(); it++)
            {
            	CHECK_DOUBLE(*it, 0.0f);
            }

            testObj->fill( 9.0f );
            for(cml::CArray2D<float ,12, 10, false>::const_iterator it = testObj->begin(); it != testObj->end(); it++)
            {
            	CHECK_DOUBLE(*it, 9.0f);
            }

            /* Checks on global data */
            check_global_data();

            delete testObj;

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();
}}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_copy_constructor_01(int doIt){
if (doIt) {
	/************************* Test Case 001 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_01_001",
				"Description: \
				- cml_stl_array2d.h : CArray2D(type (&data)[SIZE2]) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with pointer to array of possibly different size than this.\
				            Copies external data to the internal data storage. \
				- Data type for template: char\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	char DummyArray1[120] = {ArrayData123};

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<char ,12, 10, false> testObj(DummyArray1);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            for(int i = 0; i < testObj.size(); i++)
            {
            	CHECK_S_CHAR(testObj[i],DummyArray1[i]);
            }

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();

	/************************* Test Case 002 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_01_002",
				"Description: \
				- cml_stl_array2d.h : CArray2D(type (&data)[SIZE2]) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with pointer to array of possibly different size than this.\
				            Copies external data to the internal data storage. \
				- Data type for template: short\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	short DummyArray1[120] = {ArrayData123};

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<short ,12, 10, false> testObj(DummyArray1);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            for(int i = 0; i < testObj.size(); i++)
            {
            	CHECK_S_INT(testObj[i],DummyArray1[i]);
            }

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();

	/************************* Test Case 003 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_01_003",
				"Description: \
				- cml_stl_array2d.h : CArray2D(type (&data)[SIZE2]) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with pointer to array of possibly different size than this.\
				            Copies external data to the internal data storage. \
				- Data type for template: int\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	int DummyArray1[120] = {ArrayData123};

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<int ,12, 10, false> testObj(DummyArray1);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            for(int i = 0; i < testObj.size(); i++)
            {
            	CHECK_S_INT(testObj[i],DummyArray1[i]);
            }

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();

	/************************* Test Case 004 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_01_004",
				"Description: \
				- cml_stl_array2d.h : CArray2D(type (&data)[SIZE2]) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with pointer to array of possibly different size than this.\
				            Copies external data to the internal data storage. \
				- Data type for template: float\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	float DummyArray1[120] = {ArrayData123};

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<float ,12, 10, false> testObj(DummyArray1);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            for(int i = 0; i < testObj.size(); i++)
            {
            	CHECK_DOUBLE(testObj[i],DummyArray1[i]);
            }

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();
}}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_copy_constructor_02(int doIt){
if (doIt) {
	/************************* Test Case 001 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_02_001",
				"Description: \
				- cml_stl_array2d.h : CArray2D(const_type (&data)[SIZE2]) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with constant reference to array of possibly different size than this.\
				            Copies external data to the internal data storage. \
				- Data type for template: char\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	const char DummyArray1[120] = {ArrayData123};

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<char ,12, 10, false> testObj(DummyArray1);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            for(int i = 0; i < testObj.size(); i++)
            {
            	CHECK_S_CHAR(testObj[i],DummyArray1[i]);
            }

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();

	/************************* Test Case 002 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_02_002",
				"Description: \
				- cml_stl_array2d.h : CArray2D(type (&data)[SIZE2]) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with constant reference to array of possibly different size than this.\
				            Copies external data to the internal data storage. \
				- Data type for template: short\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	const short DummyArray1[120] = {ArrayData123};

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<short ,12, 10, false> testObj(DummyArray1);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            for(int i = 0; i < testObj.size(); i++)
            {
            	CHECK_S_INT(testObj[i],DummyArray1[i]);
            }

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();

	/************************* Test Case 003 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_02_003",
				"Description: \
				- cml_stl_array2d.h : CArray2D(type (&data)[SIZE2]) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with constant reference to array of possibly different size than this.\
				            Copies external data to the internal data storage. \
				- Data type for template: int\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	const int DummyArray1[120] = {ArrayData123};

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<int ,12, 10, false> testObj(DummyArray1);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            for(int i = 0; i < testObj.size(); i++)
            {
            	CHECK_S_INT(testObj[i],DummyArray1[i]);
            }

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();

	/************************* Test Case 004 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_02_004",
				"Description: \
				- cml_stl_array2d.h : CArray2D(type (&data)[SIZE2]) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with constant reference to array of possibly different size than this.\
				            Copies external data to the internal data storage. \
				- Data type for template: float\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	const float DummyArray1[120] = {ArrayData123};

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<float ,12, 10, false> testObj(DummyArray1);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            for(int i = 0; i < testObj.size(); i++)
            {
            	CHECK_DOUBLE(testObj[i],DummyArray1[i]);
            }

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();
}}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_copy_constructor_03(int doIt){
if (doIt) {
	/************************* Test Case 001 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_03_001",
				"Description: \
				- cml_stl_array2d.h : CArray2D( CArrayStorage<      type, SIZE2, EXT_MEM2>& rhs ) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with a constant CArrayStorage object of data\
				            and possibly different size and EXT_MEM setting. \
				- Data type for template: char\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	char DummyArray1[120] = {ArrayData123};
        	cml::CArrayStorage<char, 120, false> dummyObj(DummyArray1);

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<char ,12, 10, false> testObj(dummyObj);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            CHECK_MEMORY("Copy Constructor", &testObj, &dummyObj, sizeof(dummyObj));

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();

	/************************* Test Case 002 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_03_002",
				"Description: \
				- cml_stl_array2d.h : CArray2D(CArrayStorage<      type, SIZE2, EXT_MEM2>& rhs ) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with a constant CArrayStorage object of data\
				            and possibly different size and EXT_MEM setting. \
				- Data type for template: short\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	short DummyArray1[120] = {ArrayData123};
        	cml::CArrayStorage<short, 120, false> dummyObj(DummyArray1);

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<short ,12, 10, false> testObj(dummyObj);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            CHECK_MEMORY("Copy Constructor", &testObj, &dummyObj, sizeof(dummyObj));

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();

	/************************* Test Case 003 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_03_003",
				"Description: \
				- cml_stl_array2d.h : CArray2D(CArrayStorage<      type, SIZE2, EXT_MEM2>& rhs ) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with a constant CArrayStorage object of data\
				            and possibly different size and EXT_MEM setting. \
				- Data type for template: int \
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	int DummyArray1[120] = {ArrayData123};
        	cml::CArrayStorage<int, 120, false> dummyObj(DummyArray1);

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<int ,12, 10, false> testObj(dummyObj);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            CHECK_MEMORY("Copy Constructor", &testObj, &dummyObj, sizeof(dummyObj));

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();

	/************************* Test Case 004 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_03_004",
				"Description: \
				- cml_stl_array2d.h : CArray2D(CArrayStorage<      type, SIZE2, EXT_MEM2>& rhs ) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with a constant CArrayStorage object of data\
				            and possibly different size and EXT_MEM setting. \
				- Data type for template: float \
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	float DummyArray1[120] = {ArrayData123};
        	cml::CArrayStorage<float, 120, false> dummyObj(DummyArray1);

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<float ,12, 10, false> testObj(dummyObj);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            CHECK_MEMORY("Copy Constructor", &testObj, &dummyObj, sizeof(dummyObj));

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();
}}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_copy_constructor_04(int doIt){
if (doIt) {
	/************************* Test Case 001 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_04_001",
				"Description: \
				- cml_stl_array2d.h : CArray2D(CArrayStorage<const_type, SIZE2, EXT_MEM2>& rhs ) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with a constant CArrayStorage object of constant data\
				            and possibly different size and EXT_MEM setting. \
				- Data type for template: char\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	char dummyCharData[120] = {ArrayData123};
        	cml::CArrayStorage<const char, 120, true> dummyObj(dummyCharData);

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<char ,12, 10, false> testObj(dummyObj);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            for(int i = 0; i < 120; i++)
            {
            	CHECK_S_CHAR(testObj[i], dummyObj[i]);
            }

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();

	/************************* Test Case 002 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_04_002",
				"Description: \
				- cml_stl_array2d.h : CArray2D(CArrayStorage<const_type, SIZE2, EXT_MEM2>& rhs ) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with a constant CArrayStorage object of constant data\
				            and possibly different size and EXT_MEM setting. \
				- Data type for template: short\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	short dummyCharData[120] = {ArrayData123};
        	cml::CArrayStorage<const short, 120, true> dummyObj(dummyCharData);

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<short ,12, 10, false> testObj(dummyObj);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            for(int i = 0; i < 120; i++)
            {
            	CHECK_S_INT(testObj[i], dummyObj[i]);
            }

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();

	/************************* Test Case 003 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_04_003",
				"Description: \
				- cml_stl_array2d.h : CArray2D(CArrayStorage<const_type, SIZE2, EXT_MEM2>& rhs ) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with a constant CArrayStorage object of constant data\
				            and possibly different size and EXT_MEM setting. \
				- Data type for template: int\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	int dummyCharData[120] = {ArrayData123};
        	cml::CArrayStorage<const int, 120, true> dummyObj(dummyCharData);

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<int ,12, 10, false> testObj(dummyObj);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            for(int i = 0; i < 120; i++)
            {
            	CHECK_S_INT(testObj[i], dummyObj[i]);
            }

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();

	/************************* Test Case 004 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_04_004",
				"Description: \
				- cml_stl_array2d.h : CArray2D(CArrayStorage<const_type, SIZE2, EXT_MEM2>& rhs ) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with a constant CArrayStorage object of constant data\
				            and possibly different size and EXT_MEM setting. \
				- Data type for template: float\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	float dummyCharData[120] = {ArrayData123};
        	cml::CArrayStorage<const float, 120, true> dummyObj(dummyCharData);

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<float ,12, 10, false> testObj(dummyObj);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            for(int i = 0; i < 120; i++)
            {
            	CHECK_DOUBLE(testObj[i], dummyObj[i]);
            }

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();
}}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_copy_constructor_05(int doIt){
if (doIt) {
	/************************* Test Case 001 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_05_001",
				"Description: \
				- cml_stl_array2d.h : CArray2D(const CArrayStorage<      type, SIZE2, EXT_MEM2>& rhs ) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with a constant CArrayStorage object of data\
				            and possibly different size and EXT_MEM setting. \
				- Data type for template: char\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	char DummyArray1[120] = {ArrayData123};
        	const cml::CArrayStorage<char, 120, false> dummyObj(DummyArray1);

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<char ,12, 10, false> testObj(dummyObj);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            CHECK_MEMORY("Copy Constructor", &testObj, &dummyObj, sizeof(dummyObj));

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();

	/************************* Test Case 002 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_05_002",
				"Description: \
				- cml_stl_array2d.h : CArray2D(const CArrayStorage<      type, SIZE2, EXT_MEM2>& rhs ) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with a constant CArrayStorage object of data\
				            and possibly different size and EXT_MEM setting. \
				- Data type for template: short\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	short DummyArray1[120] = {ArrayData123};
        	const cml::CArrayStorage<short, 120, false> dummyObj(DummyArray1);

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<short ,12, 10, false> testObj(dummyObj);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            CHECK_MEMORY("Copy Constructor", &testObj, &dummyObj, sizeof(dummyObj));

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();

	/************************* Test Case 003 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_05_003",
				"Description: \
				- cml_stl_array2d.h : CArray2D(const CArrayStorage<      type, SIZE2, EXT_MEM2>& rhs ) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with a constant CArrayStorage object of data\
				            and possibly different size and EXT_MEM setting. \
				- Data type for template: int\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	int DummyArray1[120] = {ArrayData123};
        	const cml::CArrayStorage<int, 120, false> dummyObj(DummyArray1);

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<int ,12, 10, false> testObj(dummyObj);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            CHECK_MEMORY("Copy Constructor", &testObj, &dummyObj, sizeof(dummyObj));

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();

	/************************* Test Case 004 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_05_004",
				"Description: \
				- cml_stl_array2d.h : CArray2D(const CArrayStorage<      type, SIZE2, EXT_MEM2>& rhs ) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with a constant CArrayStorage object of data\
				            and possibly different size and EXT_MEM setting. \
				- Data type for template: float\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	float DummyArray1[120] = {ArrayData123};
        	const cml::CArrayStorage<float, 120, false> dummyObj(DummyArray1);

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<float ,12, 10, false> testObj(dummyObj);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            CHECK_MEMORY("Copy Constructor", &testObj, &dummyObj, sizeof(dummyObj));

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();
}}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_copy_constructor_06(int doIt){
if (doIt) {
	/************************* Test Case 001 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_06_001",
				"Description: \
				- cml_stl_array2d.h : CArray2D( const CArrayStorage<const_type, SIZE2, EXT_MEM2>& rhs ) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with a constant CArrayStorage object of constant data\
				            and possibly different size and EXT_MEM setting. \
				- Data type for template: char\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	char dummyCharData[120] = {ArrayData123};
        	const cml::CArrayStorage<const char, 120, true> dummyObj(dummyCharData);

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<char ,12, 10, false> testObj(dummyObj);

			/* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            for(int i = 0; i < 120; i++)
            {
            	CHECK_S_CHAR(testObj[i], dummyObj[i]);
            }

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();

	/************************* Test Case 002 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_06_002",
				"Description: \
				- cml_stl_array2d.h : CArray2D( const CArrayStorage<const_type, SIZE2, EXT_MEM2>& rhs ) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with a constant CArrayStorage object of constant data\
				            and possibly different size and EXT_MEM setting. \
				- Data type for template: short\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	short dummyCharData[120] = {ArrayData123};
        	const cml::CArrayStorage<const short, 120, true> dummyObj(dummyCharData);

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<short ,12, 10, false> testObj(dummyObj);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            for(int i = 0; i < 120; i++)
            {
            	CHECK_S_INT(testObj[i], dummyObj[i]);
            }

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();

	/************************* Test Case 003 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_06_003",
				"Description: \
				- cml_stl_array2d.h : CArray2D( const CArrayStorage<const_type, SIZE2, EXT_MEM2>& rhs ) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with a constant CArrayStorage object of constant data\
				            and possibly different size and EXT_MEM setting. \
				- Data type for template: int\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	int dummyCharData[120] = {ArrayData123};
        	const cml::CArrayStorage<const int, 120, true> dummyObj(dummyCharData);

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<int ,12, 10, false> testObj(dummyObj);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            for(int i = 0; i < 120; i++)
            {
            	CHECK_S_INT(testObj[i], dummyObj[i]);
            }

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();

	/************************* Test Case 004 *************************/
    START_TEST("test_cml_CArray2D_copy_constructor_06_004",
				"Description: \
				- cml_stl_array2d.h : CArray2D( const CArrayStorage<const_type, SIZE2, EXT_MEM2>& rhs ) : super(data) \
				- Testing: interface \
				- Overview: Copy constructor with a constant CArrayStorage object of constant data\
				            and possibly different size and EXT_MEM setting. \
				- Data type for template: float\
				- Entry conditions: - \
				- Expected results: A CArray2D object is generated with the right size and data "
              );

        /* Expected Call Sequence  */
        EXPECTED_CALLS("");
        START_EXCEPTION

			/* Test case data declarations */
        	float dummyCharData[120] = {ArrayData123};
        	const cml::CArrayStorage<const float, 120, true> dummyObj(dummyCharData);

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */

			/* Call SUT */
			cml::CArray2D<float ,12, 10, false> testObj(dummyObj);

            /* Test case checks */
            CHECK_NAMED( "Size", sint32(testObj.size()), sint32(120) );
            for(int i = 0; i < 120; i++)
            {
            	CHECK_DOUBLE(testObj[i], dummyObj[i]);
            }

            /* Checks on global data */
            check_global_data();

        NO_EXCEPTIONS
        END_EXCEPTION
        END_CALLS();
    END_TEST();
}}
#endif

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_rows(int doIt)
{
	std::cout << "START ---> test_cml_CArray2D_rows \n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray2D_rows \n\n");

	fprintf(fpTest, "Function Name ---> rows() \n\n");
	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CArray2D_rows_001 \n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray2D_rows_001 \n\n");

		std::cout << "Data Dimension ---> 12*10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 12*10 \n\n");
		
		/* Test case data declarations */
		cml::CArray2D<float32 ,12, 10, false> testObj;
        sint32 result;
        sint32 expected_returnValue;
	
		result = 0;
		expected_returnValue = 12;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		result = testObj.rows();

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
	std::cout << "END ---> test_cml_CArray2D_rows \n\n";
	fprintf(fpTest, "END ---> test_cml_CArray2D_rows \n\n");
}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_cols(int doIt)
{
	std::cout << "START ---> test_cml_CArray2D_cols \n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray2D_cols \n\n");

	fprintf(fpTest, "Function Name ---> cols() \n\n");
	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CArray2D_cols_001 \n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray2D_cols_001 \n\n");

		std::cout << "Data Dimension ---> 12*10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 12*10 \n\n");
		
		/* Test case data declarations */
		cml::CArray2D<float32 ,12, 10, false> testObj;
        sint32 result;
        sint32 expected_returnValue;
	
		result = 0;
		expected_returnValue = 10;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__PrintValue_to_console( result);
		check__PrintValue_to_File( result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		result = testObj.cols();

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
	std::cout << "END ---> test_cml_CArray2D_cols \n\n";
	fprintf(fpTest, "END ---> test_cml_CArray2D_cols \n\n");
}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_overload_assignment_operator_01(int doIt)
{
	std::cout << "START ---> test_cml_CArray2D_overload_assignment_operator_01 \n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray2D_overload_assignment_operator_01 \n\n");

	fprintf(fpTest, "Function Name ---> operator=(const) \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CArray2D_overload_assignment_operator_01_001 \n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray2D_overload_assignment_operator_01_001 \n\n");

		std::cout << "Data Dimension ---> 12*10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 12*10 \n\n");
		
		/* Test case data declarations */
        char tempCh_Array[120] = {ArrayData123};
		cml::CArray2D<char ,12, 10, false> tempObj(tempCh_Array);
		cml::CArray2D<char ,12, 10, false> testObj(TEST_racData0);
	
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( testObj);
		check__vArrayPrint_to_File( testObj, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__vArrayPrint_to_console( tempObj);
		check__vArrayPrint_to_File( tempObj, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		testObj = tempObj;

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__vArrayPrint_to_console( testObj);
		check__vArrayPrint_to_File( testObj, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__vArrayCompare(testObj,tempObj);

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
	std::cout << "END ---> test_cml_CArray2D_overload_assignment_operator_01 \n\n";
	fprintf(fpTest, "END ---> test_cml_CArray2D_overload_assignment_operator_01 \n\n");
}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_overload_function_call_operator_01(int doIt)
{
	std::cout << "START ---> test_cml_CArray2D_overload_function_call_operator_01 \n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray2D_overload_function_call_operator_01 \n\n");

	fprintf(fpTest, "Function Name ---> operator()() \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CArray2D_overload_assignment_operator_01_001 \n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray2D_overload_assignment_operator_01_001 \n\n");

		std::cout << "Data Dimension ---> 12*10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 12*10 \n\n");
		
		/* Test case data declarations */
        char tempCh_Array[120] = {ArrayData123};
		cml::CArray2D<char ,12, 10, false> testObj(tempCh_Array);
		char result;
		char expected_returnValue;	
		
		expected_returnValue = 6;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( testObj);
		check__vArrayPrint_to_File( testObj, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		result = testObj(0, 5);

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
	std::cout << "END ---> test_cml_CArray2D_overload_function_call_operator_01 \n\n";
	fprintf(fpTest, "END ---> test_cml_CArray2D_overload_function_call_operator_01 \n\n");

}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_overload_function_call_operator_02(int doIt)
{
	std::cout << "START ---> test_cml_CArray2D_overload_function_call_operator_02 \n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray2D_overload_function_call_operator_02 \n\n");

	fprintf(fpTest, "Function Name ---> operator()()const \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CArray2D_overload_assignment_operator_02_001 \n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray2D_overload_assignment_operator_02_001 \n\n");

		std::cout << "Data Dimension ---> 12*10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 12*10 \n\n");
		
		/* Test case data declarations */
        char tempCh_Array[120] = {ArrayData123};
		const cml::CArray2D<char ,12, 10, false> testObj(tempCh_Array);
		char result;
		char expected_returnValue;	
		
		expected_returnValue = 6;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( testObj);
		check__vArrayPrint_to_File( testObj, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		result = testObj(0, 5);

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
	std::cout << "END ---> test_cml_CArray2D_overload_function_call_operator_02 \n\n";
	fprintf(fpTest, "END ---> test_cml_CArray2D_overload_function_call_operator_02 \n\n");
}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_at_01(int doIt)
{
	std::cout << "START ---> test_cml_CArray2D_at_01 \n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray2D_at_01 \n\n");

	fprintf(fpTest, "Function Name ---> at() \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CArray2D_at_01 \n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray2D_at_01 \n\n");

		std::cout << "Data Dimension ---> 12*10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 12*10 \n\n");
		
		/* Test case data declarations */
        char tempCh_Array[120] = {ArrayData123};
		cml::CArray2D<char ,12, 10, false> testObj(tempCh_Array);
		char result;
		char expected_returnValue;	
		
		expected_returnValue = 6;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( testObj);
		check__vArrayPrint_to_File( testObj, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		result = testObj.at(0, 5);

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
	std::cout << "END ---> test_cml_CArray2D_at_01 \n\n";
	fprintf(fpTest, "END ---> test_cml_CArray2D_at_01 \n\n");
}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_at_02(int doIt)
{
	std::cout << "START ---> test_cml_CArray2D_at_02 \n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray2D_at_02 \n\n");

	fprintf(fpTest, "Function Name ---> at()const \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CArray2D_at_02 \n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray2D_at_02 \n\n");

		std::cout << "Data Dimension ---> 12*10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 12*10 \n\n");
		
		/* Test case data declarations */
        char tempCh_Array[120] = {ArrayData123};
		const cml::CArray2D<char ,12, 10, false> testObj(tempCh_Array);
		char result;
		char expected_returnValue;	
		
		expected_returnValue = 6;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( testObj);
		check__vArrayPrint_to_File( testObj, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( expected_returnValue);
		check__PrintValue_to_File( expected_returnValue, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		result = testObj.at(0, 5);

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
	std::cout << "END ---> test_cml_CArray2D_at_02 \n\n";
	fprintf(fpTest, "END ---> test_cml_CArray2D_at_02 \n\n");
}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_rowBegin_01(int doIt)
{
	std::cout << "START ---> test_cml_CArray2D_rowBegin_01 \n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray2D_rowBegin_01 \n\n");

	fprintf(fpTest, "Function Name ---> rowBegin() \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CArray2D_rowBegin_01_001 \n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray2D_rowBegin_01_001 \n\n");

		std::cout << "Data Dimension ---> 12*10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 12*10 \n\n");
		
		/* Test case data declarations */
        char tempCh_Array[120] = {ArrayData123};
		cml::CArray2D<char ,12, 10, false> testObj(tempCh_Array);
		cml::CArray2D<char ,12, 10, false>::rowIt it;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( testObj);
		check__vArrayPrint_to_File( testObj, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( tempCh_Array[0]);
		check__PrintValue_to_File( tempCh_Array[0], fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		it = testObj.rowBegin(0);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console(*it);
		check__PrintValue_to_File( *it, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*it,tempCh_Array[0]);

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
	std::cout << "END ---> test_cml_CArray2D_rowBegin_01 \n\n";
	fprintf(fpTest, "END ---> test_cml_CArray2D_rowBegin_01 \n\n");
}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_rowBegin_02(int doIt)
{
	std::cout << "START ---> test_cml_CArray2D_rowBegin_02 \n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray2D_rowBegin_02 \n\n");

	fprintf(fpTest, "Function Name ---> rowBegin()const \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CArray2D_rowBegin_02_001 \n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray2D_rowBegin_02_001 \n\n");

		std::cout << "Data Dimension ---> 12*10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 12*10 \n\n");
		
		/* Test case data declarations */
        char tempCh_Array[120] = {ArrayData123};
		const cml::CArray2D<char ,12, 10, false> testObj(tempCh_Array);
		cml::CArray2D<char ,12, 10, false>::cRowIt it;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( testObj);
		check__vArrayPrint_to_File( testObj, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( tempCh_Array[0]);
		check__PrintValue_to_File( tempCh_Array[0], fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		it = testObj.rowBegin(0);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console(*it);
		check__PrintValue_to_File( *it, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*it,tempCh_Array[0]);

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
	std::cout << "END ---> test_cml_CArray2D_rowBegin_02 \n\n";
	fprintf(fpTest, "END ---> test_cml_CArray2D_rowBegin_02 \n\n");
}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_cRowBegin(int doIt)
{
	std::cout << "START ---> test_cml_CArray2D_cRowBegin \n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray2D_cRowBegin \n\n");

	fprintf(fpTest, "Function Name ---> cRowBegin()const \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CArray2D_rowBegin_02_001 \n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray2D_rowBegin_02_001 \n\n");

		std::cout << "Data Dimension ---> 12*10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 12*10 \n\n");
		
		/* Test case data declarations */
        char tempCh_Array[120] = {ArrayData123};
		const cml::CArray2D<char ,12, 10, false> testObj(tempCh_Array);
		cml::CArray2D<char ,12, 10, false>::cRowIt it;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( testObj);
		check__vArrayPrint_to_File( testObj, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( tempCh_Array[0]);
		check__PrintValue_to_File( tempCh_Array[0], fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		it = testObj.cRowBegin(0);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console(*it);
		check__PrintValue_to_File( *it, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*it,tempCh_Array[0]);

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
	std::cout << "END ---> test_cml_CArray2D_cRowBegin \n\n";
	fprintf(fpTest, "END ---> test_cml_CArray2D_cRowBegin \n\n");
}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_rowEnd_01(int doIt)
{
	std::cout << "START ---> test_cml_CArray2D_rowEnd_01 \n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray2D_rowEnd_01 \n\n");

	fprintf(fpTest, "Function Name ---> rowEnd() \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CArray2D_rowEnd_01_001 \n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray2D_rowEnd_01_001 \n\n");

		std::cout << "Data Dimension ---> 12*10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 12*10 \n\n");
		
		/* Test case data declarations */
        char tempCh_Array[120] = {ArrayData123};
		cml::CArray2D<char ,12, 10, false> testObj(tempCh_Array);
		cml::CArray2D<char ,12, 10, false>::rowIt it;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( testObj);
		check__vArrayPrint_to_File( testObj, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( tempCh_Array[10]);
		check__PrintValue_to_File( tempCh_Array[10], fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		it = testObj.rowEnd(0);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console(*it);
		check__PrintValue_to_File( *it, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*it,tempCh_Array[10]);

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
	std::cout << "END ---> test_cml_CArray2D_rowEnd_01 \n\n";
	fprintf(fpTest, "END ---> test_cml_CArray2D_rowEnd_01 \n\n");
}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_rowEnd_02(int doIt)
{
	std::cout << "START ---> test_cml_CArray2D_rowEnd_02 \n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray2D_rowEnd_02 \n\n");

	fprintf(fpTest, "Function Name ---> rowEnd()const \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CArray2D_rowEnd_02_001 \n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray2D_rowEnd_02_001 \n\n");

		std::cout << "Data Dimension ---> 12*10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 12*10 \n\n");
		
		/* Test case data declarations */
        char tempCh_Array[120] = {ArrayData123};
		const cml::CArray2D<char ,12, 10, false> testObj(tempCh_Array);
		cml::CArray2D<char ,12, 10, false>::cRowIt it;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( testObj);
		check__vArrayPrint_to_File( testObj, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( tempCh_Array[10]);
		check__PrintValue_to_File( tempCh_Array[10], fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		it = testObj.rowEnd(0);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console(*it);
		check__PrintValue_to_File( *it, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*it,tempCh_Array[10]);

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
	std::cout << "END ---> test_cml_CArray2D_rowEnd_02 \n\n";
	fprintf(fpTest, "END ---> test_cml_CArray2D_rowEnd_02 \n\n");
}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_cRowEnd(int doIt)
{
	std::cout << "START ---> test_cml_CArray2D_cRowEnd \n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray2D_cRowEnd \n\n");

	fprintf(fpTest, "Function Name ---> cRowEnd()const \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CArray2D_cRowEnd_001 \n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray2D_cRowEnd_001 \n\n");

		std::cout << "Data Dimension ---> 12*10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 12*10 \n\n");
		
		/* Test case data declarations */
        char tempCh_Array[120] = {ArrayData123};
		const cml::CArray2D<char ,12, 10, false> testObj(tempCh_Array);
		cml::CArray2D<char ,12, 10, false>::cRowIt it;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( testObj);
		check__vArrayPrint_to_File( testObj, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( tempCh_Array[10]);
		check__PrintValue_to_File( tempCh_Array[10], fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		it = testObj.cRowEnd(0);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console(*it);
		check__PrintValue_to_File( *it, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*it,tempCh_Array[10]);

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
	std::cout << "END ---> test_cml_CArray2D_cRowEnd \n\n";
	fprintf(fpTest, "END ---> test_cml_CArray2D_cRowEnd \n\n");
}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_colBegin_01(int doIt)
{
	std::cout << "START ---> test_cml_CArray2D_colBegin_01 \n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray2D_colBegin_01 \n\n");

	fprintf(fpTest, "Function Name ---> colBegin() \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CArray2D_colBegin_01_001 \n\n";		
		fprintf(fpTest, "Test Case ---> ttest_cml_CArray2D_colBegin_01_001 \n\n");

		std::cout << "Data Dimension ---> 12*10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 12*10 \n\n");
		
		/* Test case data declarations */
        char tempCh_Array[120] = {ArrayData123};
		cml::CArray2D<char ,12, 10, false> testObj(tempCh_Array);
		cml::CArray2D<char ,12, 10, false>::colIt it;
		sint32 col = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( testObj);
		check__vArrayPrint_to_File( testObj, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( tempCh_Array[col + (0 * testObj.cols())]);
		check__PrintValue_to_File( tempCh_Array[col + (0 * testObj.cols())], fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		it = testObj.colBegin(col);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console(*it);
		check__PrintValue_to_File( *it, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*it,tempCh_Array[col + (0 * testObj.cols())]);

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
	std::cout << "END ---> test_cml_CArray2D_colBegin_01 \n\n";
	fprintf(fpTest, "END ---> test_cml_CArray2D_colBegin_01 \n\n");
}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_colBegin_02(int doIt)
{
	std::cout << "START ---> test_cml_CArray2D_colBegin_02 \n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray2D_colBegin_02 \n\n");

	fprintf(fpTest, "Function Name ---> colBegin()const \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CArray2D_colBegin_02_001 \n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray2D_colBegin_02_001 \n\n");

		std::cout << "Data Dimension ---> 12*10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 12*10 \n\n");
		
		/* Test case data declarations */
        char tempCh_Array[120] = {ArrayData123};
		const cml::CArray2D<char ,12, 10, false> testObj(tempCh_Array);
		cml::CArray2D<char ,12, 10, false>::cColIt it;
		sint32 col = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( testObj);
		check__vArrayPrint_to_File( testObj, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( tempCh_Array[col + (0 * testObj.cols())]);
		check__PrintValue_to_File( tempCh_Array[col + (0 * testObj.cols())], fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		it = testObj.colBegin(col);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console(*it);
		check__PrintValue_to_File( *it, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*it,tempCh_Array[col + (0 * testObj.cols())]);

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
	std::cout << "END ---> test_cml_CArray2D_colBegin_02 \n\n";
	fprintf(fpTest, "END ---> test_cml_CArray2D_colBegin_02 \n\n");
}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_cColBegin(int doIt)
{
	std::cout << "START ---> test_cml_CArray2D_cColBegin \n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray2D_cColBegin \n\n");

	fprintf(fpTest, "Function Name ---> colBegin()const \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CArray2D_cColBegin_001 \n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray2D_cColBegin_001 \n\n");

		std::cout << "Data Dimension ---> 12*10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 12*10 \n\n");
		
		/* Test case data declarations */
        char tempCh_Array[120] = {ArrayData123};
		const cml::CArray2D<char ,12, 10, false> testObj(tempCh_Array);
		cml::CArray2D<char ,12, 10, false>::cColIt it;
		sint32 col = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( testObj);
		check__vArrayPrint_to_File( testObj, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( tempCh_Array[col + (0 * testObj.cols())]);
		check__PrintValue_to_File( tempCh_Array[col + (0 * testObj.cols())], fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		it = testObj.cColBegin(col);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");

		check__PrintValue_to_console(*it);
		check__PrintValue_to_File( *it, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*it,tempCh_Array[col + (0 * testObj.cols())]);

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
	std::cout << "END ---> test_cml_CArray2D_cColBegin \n\n";
	fprintf(fpTest, "END ---> test_cml_CArray2D_cColBegin \n\n");
}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_colEnd_01(int doIt)
{
	std::cout << "START ---> test_cml_CArray2D_colEnd_01 \n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray2D_colEnd_01 \n\n");

	fprintf(fpTest, "Function Name ---> colEnd() \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CArray2D_colEnd_01_001 \n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray2D_colEnd_01_001 \n\n");

		std::cout << "Data Dimension ---> 12*10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 12*10 \n\n");
		
		/* Test case data declarations */
        float32 tempCh_Array[120] = {ArrayData123};
		cml::CArray2D<float32 ,12, 10, false> testObj(tempCh_Array);
		cml::CArray2D<float32 ,12, 10, false>::colIt it;
		sint32 col = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( testObj);
		check__vArrayPrint_to_File( testObj, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( tempCh_Array[col + ((11 * testObj.cols()))]);
		check__PrintValue_to_File( tempCh_Array[col + (11 * testObj.cols())], fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		it = testObj.colEnd(col);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		--it;
		check__PrintValue_to_console(*it);
		check__PrintValue_to_File( *it, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*(it),tempCh_Array[col + (11 * testObj.cols())]);

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
	std::cout << "END ---> test_cml_CArray2D_colEnd_01 \n\n";
	fprintf(fpTest, "END ---> test_cml_CArray2D_colEnd_01 \n\n");
}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_colEnd_02(int doIt)
{
	std::cout << "START ---> test_cml_CArray2D_colEnd_02 \n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray2D_colEnd_02 \n\n");

	fprintf(fpTest, "Function Name ---> colEnd()const \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CArray2D_colEnd_02_001 \n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray2D_colEnd_02_001 \n\n");

		std::cout << "Data Dimension ---> 12*10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 12*10 \n\n");
		
		/* Test case data declarations */
        float32 tempCh_Array[120] = {ArrayData123};
		const cml::CArray2D<float32 ,12, 10, false> testObj(tempCh_Array);
		cml::CArray2D<float32 ,12, 10, false>::cColIt it;
		sint32 col = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( testObj);
		check__vArrayPrint_to_File( testObj, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( tempCh_Array[col + ((11 * testObj.cols()))]);
		check__PrintValue_to_File( tempCh_Array[col + (11 * testObj.cols())], fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		it = testObj.colEnd(col);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		--it;
		check__PrintValue_to_console(*it);
		check__PrintValue_to_File( *it, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*(it),tempCh_Array[col + (11 * testObj.cols())]);

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
	std::cout << "END ---> test_cml_CArray2D_colEnd_02 \n\n";
	fprintf(fpTest, "END ---> test_cml_CArray2D_colEnd_02 \n\n");
}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_cColEnd(int doIt)
{
	std::cout << "START ---> test_cml_CArray2D_cColEnd \n\n";		
	fprintf(fpTest, "START ---> test_cml_CArray2D_cColEnd \n\n");

	fprintf(fpTest, "Function Name ---> cColEnd()const \n\n");

	if (doIt) 
	{
		{
		std::cout << "Test Case ---> test_cml_CArray2D_cColEnd_001 \n\n";		
		fprintf(fpTest, "Test Case ---> test_cml_CArray2D_cColEnd_001 \n\n");

		std::cout << "Data Dimension ---> 12*10 \n\n";		
		fprintf(fpTest, "Data Dimension ---> 12*10 \n\n");
		
		/* Test case data declarations */
        float32 tempCh_Array[120] = {ArrayData123};
		const cml::CArray2D<float32 ,12, 10, false> testObj(tempCh_Array);
		cml::CArray2D<float32 ,12, 10, false>::cColIt it;
		sint32 col = 1;
		
		/* Input*/
		std::cout << "Input ---> \n";	
		fprintf(fpTest, "Input ---> \n");
		
		std::cout << "input1 = \n";	
		fprintf(fpTest, "input1 = \n");

		check__vArrayPrint_to_console( testObj);
		check__vArrayPrint_to_File( testObj, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Expected Result*/
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");

		check__PrintValue_to_console( tempCh_Array[col + ((11 * testObj.cols()))]);
		check__PrintValue_to_File( tempCh_Array[col + (11 * testObj.cols())], fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		it = testObj.cColEnd(col);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Actual Result */
		std::cout << "Actual Result ---> \n";
		fprintf(fpTest, "Actual Result ---> \n");

		std::cout << "result1 ---> \n";
		fprintf(fpTest, "result1 = \n");
		--it;
		check__PrintValue_to_console(*it);
		check__PrintValue_to_File( *it, fpTest);	
		fprintf(fpTest, "\n\n");

		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare(*(it),tempCh_Array[col + (11 * testObj.cols())]);

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
	std::cout << "END ---> test_cml_CArray2D_cColEnd \n\n";
	fprintf(fpTest, "END ---> test_cml_CArray2D_cColEnd \n\n");
}

#if 0
void TEST_CLASS_ARRAY2D::test_cml_CArray2D_colEnd_01(int doIt){
	if (doIt) {
		/************************* Test Case 001 *************************/
	    START_TEST("test_cml_CArray2D_colEnd_01_001",
					"Description: \
					- cml_stl_array2d.h : colIt  colEnd(sint32 col) \
					- Testing: interface \
					- Overview: Returns an iterator to the last column of this array. \
					- Data type for template: char\
					- Entry conditions: - \
					- Expected results: An iterator to the last column of this array "
	              );

	        /* Expected Call Sequence  */
	        EXPECTED_CALLS("");
	        START_EXCEPTION

				/* Test case data declarations */
	        	char tempCh_Array[120] = {ArrayData123};
				cml::CArray2D<char ,12, 10, false> testObj(tempCh_Array);
				cml::CArray2D<char ,12, 10, false>::colIt it;
				sint32 col;

				/* Set global data */
				initialise_global_data();
				col = 1;

				/* Set expected values for global data checks */

				/* Call SUT */
				it = testObj.colEnd(col);

	            /* Test case checks */
				for(int i = 11; i >= 0; i--)
				{
					--it;
					CHECK_S_CHAR(*it, tempCh_Array[col + ((i * testObj.cols()))]);
				}

	            /* Checks on global data */
	            check_global_data();

	        NO_EXCEPTIONS
	        END_EXCEPTION
	        END_CALLS();
	    END_TEST();

		/************************* Test Case 002 *************************/
	    START_TEST("test_cml_CArray2D_colEnd_01_002",
					"Description: \
					- cml_stl_array2d.h : colIt  colEnd(sint32 col) \
					- Testing: interface \
					- Overview: Returns an iterator to the last column of this array. \
					- Data type for template: short\
					- Entry conditions: - \
					- Expected results: An iterator to the last column of this array "
	              );

	        /* Expected Call Sequence  */
	        EXPECTED_CALLS("");
	        START_EXCEPTION

				/* Test case data declarations */
	        	short tempCh_Array[120] = {ArrayData123};
				cml::CArray2D<short ,12, 10, false> testObj(tempCh_Array);
				cml::CArray2D<short ,12, 10, false>::colIt it;
				sint32 col;

				/* Set global data */
				initialise_global_data();
				col = 1;

				/* Set expected values for global data checks */

				/* Call SUT */
				it = testObj.colEnd(col);

	            /* Test case checks */
				for(int i = 11; i >= 0; i--)
				{
					--it;
					CHECK_S_INT(*it, tempCh_Array[col + ((i * testObj.cols()))]);
				}

	            /* Checks on global data */
	            check_global_data();

	        NO_EXCEPTIONS
	        END_EXCEPTION
	        END_CALLS();
	    END_TEST();

		/************************* Test Case 003 *************************/
	    START_TEST("test_cml_CArray2D_colEnd_01_003",
					"Description: \
					- cml_stl_array2d.h : colIt  colEnd(sint32 col) \
					- Testing: interface \
					- Overview: Returns an iterator to the last column of this array. \
					- Data type for template: int\
					- Entry conditions: - \
					- Expected results: An iterator to the last column of this array "
	              );

	        /* Expected Call Sequence  */
	        EXPECTED_CALLS("");
	        START_EXCEPTION

				/* Test case data declarations */
	        	int tempCh_Array[120] = {ArrayData123};
				cml::CArray2D<int ,12, 10, false> testObj(tempCh_Array);
				cml::CArray2D<int ,12, 10, false>::colIt it;
				sint32 col;

				/* Set global data */
				initialise_global_data();
				col = 1;

				/* Set expected values for global data checks */

				/* Call SUT */
				it = testObj.colEnd(col);

	            /* Test case checks */
				for(int i = 11; i >= 0; i--)
				{
					--it;
					CHECK_S_INT(*it, tempCh_Array[col + ((i * testObj.cols()))]);
				}

	            /* Checks on global data */
	            check_global_data();

	        NO_EXCEPTIONS
	        END_EXCEPTION
	        END_CALLS();
	    END_TEST();

		/************************* Test Case 004 *************************/
	    START_TEST("test_cml_CArray2D_colEnd_01_004",
					"Description: \
					- cml_stl_array2d.h : colIt  colEnd(sint32 col) \
					- Testing: interface \
					- Overview: Returns an iterator to the last column of this array. \
					- Data type for template: float\
					- Entry conditions: - \
					- Expected results: An iterator to the last column of this array "
	              );

	        /* Expected Call Sequence  */
	        EXPECTED_CALLS("");
	        START_EXCEPTION

				/* Test case data declarations */
	        	float tempCh_Array[120] = {ArrayData123};
				cml::CArray2D<float ,12, 10, false> testObj(tempCh_Array);
				cml::CArray2D<float ,12, 10, false>::colIt it;
				sint32 col;

				/* Set global data */
				initialise_global_data();
				col = 1;

				/* Set expected values for global data checks */

				/* Call SUT */
				it = testObj.colEnd(col);

	            /* Test case checks */
				for(int i = 11; i >= 0; i--)
				{
					--it;
					CHECK_DOUBLE(*it, tempCh_Array[col + ((i * testObj.cols()))]);
				}

	            /* Checks on global data */
	            check_global_data();

	        NO_EXCEPTIONS
	        END_EXCEPTION
	        END_CALLS();
	    END_TEST();
}}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_colEnd_02(int doIt){
	if (doIt) {
		/************************* Test Case 001 *************************/
	    START_TEST("test_cml_CArray2D_colEnd_02_001",
					"Description: \
					- cml_stl_array2d.h : cColIt  colEnd(sint32 col)  const \
					- Testing: interface \
					- Overview: Returns an constant iterator to the last column of this array. \
					- Data type for template: char\
					- Entry conditions: - \
					- Expected results: An constant iterator to the last column of this array "
	              );

	        /* Expected Call Sequence  */
	        EXPECTED_CALLS("");
	        START_EXCEPTION

				/* Test case data declarations */
	        	char tempCh_Array[120] = {ArrayData123};
	        	const cml::CArray2D<char ,12, 10, false> testObj(tempCh_Array);
				cml::CArray2D<char ,12, 10, false>::cColIt it;
				sint32 col;

				/* Set global data */
				initialise_global_data();
				col = 1;

				/* Set expected values for global data checks */

				/* Call SUT */
				it = testObj.colEnd(col);

	            /* Test case checks */
				for(int i = 11; i >= 0; i--)
				{
					--it;
					CHECK_S_CHAR(*it, tempCh_Array[col + ((i * testObj.cols()))]);
				}

	            /* Checks on global data */
	            check_global_data();

	        NO_EXCEPTIONS
	        END_EXCEPTION
	        END_CALLS();
	    END_TEST();

		/************************* Test Case 002 *************************/
	    START_TEST("test_cml_CArray2D_colEnd_02_002",
					"Description: \
					- cml_stl_array2d.h : cColIt  colEnd(sint32 col)  const \
					- Testing: interface \
					- Overview: Returns an constant iterator to the last column of this array. \
					- Data type for template: short\
					- Entry conditions: - \
					- Expected results: An constant iterator to the last column of this array "
	              );

	        /* Expected Call Sequence  */
	        EXPECTED_CALLS("");
	        START_EXCEPTION

				/* Test case data declarations */
	        	short tempCh_Array[120] = {ArrayData123};
				const cml::CArray2D<short ,12, 10, false> testObj(tempCh_Array);
				cml::CArray2D<short ,12, 10, false>::cColIt it;
				sint32 col;

				/* Set global data */
				initialise_global_data();
				col = 1;

				/* Set expected values for global data checks */

				/* Call SUT */
				it = testObj.colEnd(col);

	            /* Test case checks */
				for(int i = 11; i >= 0; i--)
				{
					--it;
					CHECK_S_INT(*it, tempCh_Array[col + ((i * testObj.cols()))]);
				}

	            /* Checks on global data */
	            check_global_data();

	        NO_EXCEPTIONS
	        END_EXCEPTION
	        END_CALLS();
	    END_TEST();

		/************************* Test Case 003 *************************/
	    START_TEST("test_cml_CArray2D_colEnd_02_003",
					"Description: \
					- cml_stl_array2d.h : cColIt  colEnd(sint32 col)  const \
					- Testing: interface \
					- Overview: Returns an constant iterator to the last column of this array. \
					- Data type for template: int\
					- Entry conditions: - \
					- Expected results: An constant iterator to the last column of this array "
	              );

	        /* Expected Call Sequence  */
	        EXPECTED_CALLS("");
	        START_EXCEPTION

				/* Test case data declarations */
	        	int tempCh_Array[120] = {ArrayData123};
	        	const cml::CArray2D<int ,12, 10, false> testObj(tempCh_Array);
				cml::CArray2D<int ,12, 10, false>::cColIt it;
				sint32 col;

				/* Set global data */
				initialise_global_data();
				col = 4;

				/* Set expected values for global data checks */

				/* Call SUT */
				it = testObj.colEnd(col);

	            /* Test case checks */
				for(int i = 11; i >= 0; i--)
				{
					--it;
					CHECK_S_INT(*it, tempCh_Array[col + ((i * testObj.cols()))]);
				}

	            /* Checks on global data */
	            check_global_data();

	        NO_EXCEPTIONS
	        END_EXCEPTION
	        END_CALLS();
	    END_TEST();

		/************************* Test Case 004 *************************/
	    START_TEST("test_cml_CArray2D_colEnd_02_004",
					"Description: \
					- cml_stl_array2d.h : cColIt  colEnd(sint32 col)  const \
					- Testing: interface \
					- Overview: Returns an constant iterator to the last column of this array. \
					- Data type for template: float\
					- Entry conditions: - \
					- Expected results: An constant iterator to the last column of this array "
	              );

	        /* Expected Call Sequence  */
	        EXPECTED_CALLS("");
	        START_EXCEPTION

				/* Test case data declarations */
	        	float tempCh_Array[120] = {ArrayData123};
	        	const cml::CArray2D<float ,12, 10, false> testObj(tempCh_Array);
				cml::CArray2D<float ,12, 10, false>::cColIt it;
				sint32 col;

				/* Set global data */
				initialise_global_data();
				col = 6;

				/* Set expected values for global data checks */

				/* Call SUT */
				it = testObj.colEnd(col);

	            /* Test case checks */
				for(int i = 11; i >= 0; i--)
				{
					--it;
					CHECK_DOUBLE(*it, tempCh_Array[col + ((i * testObj.cols()))]);
				}

	            /* Checks on global data */
	            check_global_data();

	        NO_EXCEPTIONS
	        END_EXCEPTION
	        END_CALLS();
	    END_TEST();
}}

void TEST_CLASS_ARRAY2D::test_cml_CArray2D_cColEnd(int doIt){
	if (doIt) {
		/************************* Test Case 001 *************************/
	    START_TEST("test_cml_CArray2D_cColEnd_001",
					"Description: \
					- cml_stl_array2d.h : cColIt  cColEnd(sint32 col)  const \
					- Testing: interface \
					- Overview: Returns an constant iterator to the last column of this array. \
					- Data type for template: char\
					- Entry conditions: - \
					- Expected results: An constant iterator to the last column of this array "
	              );

	        /* Expected Call Sequence  */
	        EXPECTED_CALLS("");
	        START_EXCEPTION

				/* Test case data declarations */
	        	char tempCh_Array[120] = {ArrayData123};
	        	const cml::CArray2D<char ,12, 10, false> testObj(tempCh_Array);
				cml::CArray2D<char ,12, 10, false>::cColIt it;
				sint32 col;

				/* Set global data */
				initialise_global_data();
				col = 1;

				/* Set expected values for global data checks */

				/* Call SUT */
				it = testObj.cColEnd(col);

	            /* Test case checks */
				for(int i = 11; i >= 0; i--)
				{
					--it;
					CHECK_S_CHAR(*it, tempCh_Array[col + ((i * testObj.cols()))]);
				}

	            /* Checks on global data */
	            check_global_data();

	        NO_EXCEPTIONS
	        END_EXCEPTION
	        END_CALLS();
	    END_TEST();

		/************************* Test Case 002 *************************/
	    START_TEST("test_cml_CArray2D_cColEnd_002",
					"Description: \
					- cml_stl_array2d.h : cColIt  cColEnd(sint32 col)  const \
					- Testing: interface \
					- Overview: Returns an constant iterator to the last column of this array. \
					- Data type for template: short\
					- Entry conditions: - \
					- Expected results: An constant iterator to the last column of this array "
	              );

	        /* Expected Call Sequence  */
	        EXPECTED_CALLS("");
	        START_EXCEPTION

				/* Test case data declarations */
	        	short tempCh_Array[120] = {ArrayData123};
				const cml::CArray2D<short ,12, 10, false> testObj(tempCh_Array);
				cml::CArray2D<short ,12, 10, false>::cColIt it;
				sint32 col;

				/* Set global data */
				initialise_global_data();
				col = 1;

				/* Set expected values for global data checks */

				/* Call SUT */
				it = testObj.cColEnd(col);

	            /* Test case checks */
				for(int i = 11; i >= 0; i--)
				{
					--it;
					CHECK_S_INT(*it, tempCh_Array[col + ((i * testObj.cols()))]);
				}

	            /* Checks on global data */
	            check_global_data();

	        NO_EXCEPTIONS
	        END_EXCEPTION
	        END_CALLS();
	    END_TEST();

		/************************* Test Case 003 *************************/
	    START_TEST("test_cml_CArray2D_cColEnd_003",
					"Description: \
					- cml_stl_array2d.h : cColIt  cColEnd(sint32 col)  const \
					- Testing: interface \
					- Overview: Returns an constant iterator to the last column of this array. \
					- Data type for template: int\
					- Entry conditions: - \
					- Expected results: An constant iterator to the last column of this array "
	              );

	        /* Expected Call Sequence  */
	        EXPECTED_CALLS("");
	        START_EXCEPTION

				/* Test case data declarations */
	        	int tempCh_Array[120] = {ArrayData123};
	        	const cml::CArray2D<int ,12, 10, false> testObj(tempCh_Array);
				cml::CArray2D<int ,12, 10, false>::cColIt it;
				sint32 col;

				/* Set global data */
				initialise_global_data();
				col = 4;

				/* Set expected values for global data checks */

				/* Call SUT */
				it = testObj.cColEnd(col);

	            /* Test case checks */
				for(int i = 11; i >= 0; i--)
				{
					--it;
					CHECK_S_INT(*it, tempCh_Array[col + ((i * testObj.cols()))]);
				}

	            /* Checks on global data */
	            check_global_data();

	        NO_EXCEPTIONS
	        END_EXCEPTION
	        END_CALLS();
	    END_TEST();

		/************************* Test Case 004 *************************/
	    START_TEST("test_cml_CArray2D_cColEnd_004",
					"Description: \
					- cml_stl_array2d.h : cColIt  cColEnd(sint32 col)  const \
					- Testing: interface \
					- Overview: Returns an constant iterator to the last column of this array. \
					- Data type for template: float\
					- Entry conditions: - \
					- Expected results: An constant iterator to the last column of this array "
	              );

	        /* Expected Call Sequence  */
	        EXPECTED_CALLS("");
	        START_EXCEPTION

				/* Test case data declarations */
	        	float tempCh_Array[120] = {ArrayData123};
	        	const cml::CArray2D<float ,12, 10, false> testObj(tempCh_Array);
				cml::CArray2D<float ,12, 10, false>::cColIt it;
				sint32 col;

				/* Set global data */
				initialise_global_data();
				col = 6;

				/* Set expected values for global data checks */

				/* Call SUT */
				it = testObj.cColEnd(col);

	            /* Test case checks */
				for(int i = 11; i >= 0; i--)
				{
					--it;
					CHECK_DOUBLE(*it, tempCh_Array[col + ((i * testObj.cols()))]);
				}

	            /* Checks on global data */
	            check_global_data();

	        NO_EXCEPTIONS
	        END_EXCEPTION
	        END_CALLS();
	    END_TEST();
}}
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
