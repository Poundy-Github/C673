/*! \file **********************************************************************

COMPANY:                   Continental India

CPU:                       CPU-Independent

COMPONENT:                 CML (Common Math Library)

MODULNAME:                 test_cml_stl_vector.cpp

DESCRIPTION:               Test script for Vector Computations Library

AUTHOR:                    Balachandra Naik

CREATION DATE:             20.01.2016

VERSION:                   $Revision: 1.1 $

**************************************************************************** */

/* Include files from software under test */
#include <stdio.h>
#include <iostream>
#include "cml_ext.h"
#include "cml_stl_vector.h"

using namespace cml;

/* This function checks the data contained by a CArray object. */   
template < typename T, sint32 SIZE, boolean_t EXT_MEM >
bool checkCVectorContent( const cml::CVector< T, SIZE, EXT_MEM > &oVector, void *pBuffer)
{
    bool biRetVal = true;
    
    for( int iIndex=0; iIndex < oVector.size(); ++iIndex )
    {
        const T &u8Ist  = (const T &)( oVector[ iIndex ] );
        const T &u8Soll = *( (T *)pBuffer + iIndex );
        u8Ist != u8Soll ? biRetVal &= false : 0 ;
    }
    return biRetVal;
} 

/* Global test data declarartions */
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

#define ArrayData9                                           \
  /*      1    2    3    4    5    6    7    8    9   10  */ \
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
  

float32 floattestArrayData123[]  = { ArrayData123 };
float32 floattestArrayData9[]    = { ArrayData9 };

sint32 inttestArrayData123[]     = { ArrayData123 };
sint32 inttestArrayData9[]       = { ArrayData9 };

sint16 shorttestArrayData123[]   = { ArrayData123 };
sint16 shorttestArrayData9[]     = { ArrayData9 };

sint8 chartestArrayData123[]     = { ArrayData123 };
sint8 chartestArrayData9[]       = { ArrayData9 };


/* Test Log file */
extern FILE *fpTest;

/* Function declaration */
void test_cml_stl_vector(void);



/* This function initialises global data to default values. This function       */
/* is called by every test case so must not contain test case specific settings */
static void initialise_global_data()
{
	//std::cout << "Initialize global data if required\n";    
}

/* This function copies the global data settings into expected variables for */
/* use in check_global_data(). It is called by every test case so must not   */
/* contain test case specific settings.                                      */
static void initialise_expected_global_data()
{
	//std::cout << "Initialize expected global data if required\n";    
}

/* This function checks global data against the expected values. */
static void check_global_data()
{
	std::cout << "Test case: PASS\n\n"; 
	fprintf(fpTest, "Test case: PASS\n");
}
/*****************************************************************************/
/* Test class declaration                                                    */
/*****************************************************************************/
class TEST_CLASS
{
public:
	void run_tests_vector();

	void test_CML_CVector_Constructor(int);
	void test_assignment_operator_vector_copy(int);
	void test_resize(int);
	void test_assign(int);
	void test_push_back(int);
	void test_pop_back(int);
	void test_insert(int);
	void test_insert_multiple_elements(int);
	void test_erase(int);
	
	
};

/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_stl_vector(void)
{
	TEST_CLASS test_object;
		
	std::cout << "******** Start Testing: Vector Library functions ********\n\n";
	fprintf(fpTest, "******** Start Testing: Vector Library functions ********\n\n");

	test_object.run_tests_vector();

	std::cout << "End of Testing: Vector Library functions\n\n";
	fprintf(fpTest, "End of Testing: Vector Library functions\n\n");

}

/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests_vector() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS::run_tests_vector()
{
	test_CML_CVector_Constructor(1);
	test_assignment_operator_vector_copy(1);
	test_resize(1);
	test_assign(1);
	test_push_back(1);
	test_pop_back(1);
	test_insert(1);
	test_insert_multiple_elements(1);
	test_erase(1);
}

/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/

void TEST_CLASS::test_CML_CVector_Constructor(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_CML_CVector_Constructor\n";
		fprintf(fpTest, "START ---> test_CML_CVector_Constructor\n");

		/* Test case data declarations */
		cml::CVector<float32 ,100, false> *TestVector;

		cml::CVector<float32 ,100, true> TestVector2(floattestArrayData123);

		int size = 0;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* Call Function Under Test */
		TestVector = new cml::CVector<float32, 100, false>();

		size = TestVector2.size();

		size = TestVector2.max_size();

		TestVector2.clear();

		/* Checks on global data */
		check_global_data();

		std::cout << "END ---> test_CML_CVector_Constructor\n\n";
		fprintf(fpTest, "END ---> test_CML_CVector_Constructor\n\n");
	}
}

//self& operator=(const self& rhs)
void TEST_CLASS::test_assignment_operator_vector_copy(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_assignment_operator_vector_copy\n\n";
		fprintf(fpTest, "START ---> test_assignment_operator_vector_copy\n\n");
				
		/* Copy float Vector */
		{
			/* Test case data declarations */

			typedef cml::CVector <float32, 100, true> self;

            cml::CVector<float32, 100, true> TestVector2( floattestArrayData123, 100 );
            cml::CVector<float32, 100, true> TestVector(  floattestArrayData9,  80 );
							
			cml::boolean_t returnValue;

			std::cout << "test_assignment_operator_vector_copy -> Copy float Vector\n";
			fprintf(fpTest, "test_assignment_operator_vector_copy -> Copy float Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector = TestVector2; /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, floattestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Copy int Vector */
		{
			/* Test case data declarations */
            cml::CVector<sint32, 100, true> TestVector2( inttestArrayData123, 100 );
            cml::CVector<sint32, 100, true> TestVector(  inttestArrayData9,  80 );
							
			cml::boolean_t returnValue;

			std::cout << "test_assignment_operator_vector_copy -> Copy int Vector\n";
			fprintf(fpTest, "test_assignment_operator_vector_copy -> Copy int Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector = TestVector2; /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, inttestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Copy short Vector */
		{
			/* Test case data declarations */
            cml::CVector<sint16, 100, true> TestVector2( shorttestArrayData123, 100 );
            cml::CVector<sint16, 100, true> TestVector(  shorttestArrayData9,  80 );
							
			cml::boolean_t returnValue;

			std::cout << "test_assignment_operator_vector_copy -> Copy short Vector\n";
			fprintf(fpTest, "test_assignment_operator_vector_copy -> Copy short Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector = TestVector2; /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, shorttestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Copy char Vector */
		{
			/* Test case data declarations */
            cml::CVector<sint8, 100, true> TestVector2( chartestArrayData123, 100 );
            cml::CVector<sint8, 100, true> TestVector(  chartestArrayData9,  80 );
							
			cml::boolean_t returnValue;

			std::cout << "test_assignment_operator_vector_copy -> Copy char Vector\n";
			fprintf(fpTest, "test_assignment_operator_vector_copy -> Copy char Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector = TestVector2; /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, chartestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}
	
		std::cout << "END ---> test_assignment_operator_vector_copy\n\n";
		fprintf(fpTest, "END ---> test_assignment_operator_vector_copy\n\n");
	}
}

//void resize( const size_type& sz, const_reference c = type() )
void TEST_CLASS::test_resize(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_resize\n\n";
		fprintf(fpTest, "START ---> test_resize\n\n");
				
		/* Resize float Vector */
		{
			/* Test case data declarations */			

            cml::CVector<float32, 100, true> TestVector( floattestArrayData123, 50 );
            							
			cml::boolean_t returnValue;

			std::cout << "test_resize -> Resize float Vector\n";
			fprintf(fpTest, "test_resize -> Resize float Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.resize(80, 100); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, floattestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Resize int Vector */
		{
			/* Test case data declarations */			

            cml::CVector<sint32, 100, true> TestVector( inttestArrayData123, 50 );
            							
			cml::boolean_t returnValue;

			std::cout << "test_resize -> Resize int Vector\n";
			fprintf(fpTest, "test_resize -> Resize int Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.resize(80, 100); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, inttestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Resize short Vector */
		{
			/* Test case data declarations */			

            cml::CVector<sint16, 100, true> TestVector( shorttestArrayData123, 50 );
            							
			cml::boolean_t returnValue;

			std::cout << "test_resize -> Resize short Vector\n";
			fprintf(fpTest, "test_resize -> Resize short Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.resize(80, 100); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, shorttestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Resize char Vector */
		{
			/* Test case data declarations */			

            cml::CVector<sint8, 100, true> TestVector( chartestArrayData123, 50 );
            							
			cml::boolean_t returnValue;

			std::cout << "test_resize -> Resize char Vector\n";
			fprintf(fpTest, "test_resize -> Resize char Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.resize(80, 100); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, chartestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}
	
		std::cout << "END ---> test_resize\n\n";
		fprintf(fpTest, "END ---> test_resize\n\n");
	}
}

//void assign(const size_type n, const_reference u)
void TEST_CLASS::test_assign(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_assign\n\n";
		fprintf(fpTest, "START ---> test_assign\n\n");
				
		/* Assign float Vector */
		{
			/* Test case data declarations */			

            cml::CVector<float32, 100, true> TestVector( floattestArrayData123, 100 );
            							
			cml::boolean_t returnValue;

			std::cout << "test_assign -> Assign float Vector\n";
			fprintf(fpTest, "test_assign -> Assign float Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.assign(70, 25); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, floattestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Assign int Vector */
		{
			/* Test case data declarations */			

            cml::CVector<sint32, 100, true> TestVector( inttestArrayData123, 100 );
            							
			cml::boolean_t returnValue;

			std::cout << "test_assign -> Assign int Vector\n";
			fprintf(fpTest, "test_assign -> Assign int Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.assign(70, 25); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, inttestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Assign short Vector */
		{
			/* Test case data declarations */			

            cml::CVector<sint16, 100, true> TestVector( shorttestArrayData123, 100 );
            							
			cml::boolean_t returnValue;

			std::cout << "test_assign -> Assign short Vector\n";
			fprintf(fpTest, "test_assign -> Assign short Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.assign(70, 25); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, shorttestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Assign char Vector */
		{
			/* Test case data declarations */			

            cml::CVector<sint8, 100, true> TestVector( chartestArrayData123, 100 );
            							
			cml::boolean_t returnValue;

			std::cout << "test_assign -> Assign char Vector\n";
			fprintf(fpTest, "test_assign -> Assign char Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.assign(70, 25); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, chartestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}
	
		std::cout << "END ---> test_assign\n\n";
		fprintf(fpTest, "END ---> test_assign\n\n");
	}
}

//void push_back(const_reference x)
void TEST_CLASS::test_push_back(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_push_back\n\n";
		fprintf(fpTest, "START ---> test_push_back\n\n");
				
		/* Push back float Vector */
		{
			/* Test case data declarations */			

            cml::CVector<float32, 100, true> TestVector( floattestArrayData123, 80 );
            							
			cml::boolean_t returnValue;

			std::cout << "test_push_back -> Push back float Vector\n";
			fprintf(fpTest, "test_push_back -> Push back float Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.push_back(70); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, floattestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Push back int Vector */
		{
			/* Test case data declarations */			

            cml::CVector<sint32, 100, true> TestVector( inttestArrayData123, 80 );
            							
			cml::boolean_t returnValue;

			std::cout << "test_push_back -> Push back int Vector\n";
			fprintf(fpTest, "test_push_back -> Push back int Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.push_back(70); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, inttestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Push back short Vector */
		{
			/* Test case data declarations */			

            cml::CVector<sint16, 100, true> TestVector( shorttestArrayData123, 80 );
            							
			cml::boolean_t returnValue;

			std::cout << "test_push_back -> Push back short Vector\n";
			fprintf(fpTest, "test_push_back -> Push back short Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.push_back(70); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, shorttestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Push back char Vector */
		{
			/* Test case data declarations */			

            cml::CVector<sint8, 100, true> TestVector( chartestArrayData123, 80 );
            							
			cml::boolean_t returnValue;

			std::cout << "test_push_back -> Push back char Vector\n";
			fprintf(fpTest, "test_push_back -> Push back char Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.push_back(70); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, chartestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}
	
		std::cout << "END ---> test_push_back\n\n";
		fprintf(fpTest, "END ---> test_push_back\n\n");
	}
}

//void pop_back(size_type n)
void TEST_CLASS::test_pop_back(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_pop_back\n\n";
		fprintf(fpTest, "START ---> test_pop_back\n\n");
				
		/* Pop back float Vector */
		{
			/* Test case data declarations */			

            cml::CVector<float32, 100, true> TestVector( floattestArrayData123, 80 );
            							
			cml::boolean_t returnValue;

			std::cout << "test_pop_back -> Pop back float Vector\n";
			fprintf(fpTest, "test_pop_back -> Pop back float Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.pop_back(70); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, floattestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Pop back int Vector */
		{
			/* Test case data declarations */			

            cml::CVector<sint32, 100, true> TestVector( inttestArrayData123, 80 );
            							
			cml::boolean_t returnValue;

			std::cout << "test_pop_back -> Pop back int Vector\n";
			fprintf(fpTest, "test_pop_back -> Pop back int Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.pop_back(70); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, inttestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Pop back short Vector */
		{
			/* Test case data declarations */			

            cml::CVector<sint16, 100, true> TestVector( shorttestArrayData123, 80 );
            							
			cml::boolean_t returnValue;

			std::cout << "test_pop_back -> Pop back short Vector\n";
			fprintf(fpTest, "test_pop_back -> Pop back short Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.pop_back(70); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, shorttestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Pop back char Vector */
		{
			/* Test case data declarations */			

            cml::CVector<sint8, 100, true> TestVector( chartestArrayData123, 80 );
            							
			cml::boolean_t returnValue;

			std::cout << "test_pop_back -> Pop back char Vector\n";
			fprintf(fpTest, "test_pop_back -> Pop back char Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.pop_back(70); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, chartestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}
	
		std::cout << "END ---> test_pop_back\n\n";
		fprintf(fpTest, "END ---> test_pop_back\n\n");
	}
}

//it insert(const cIt& position, const_reference p)
void TEST_CLASS::test_insert(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_insert\n\n";
		fprintf(fpTest, "START ---> test_insert\n\n");
				
		/* Insert element in float Vector */
		{
			/* Test case data declarations */			

            cml::CVector<float32, 100, true> TestVector( floattestArrayData123, 80 );
            							
			cml::boolean_t returnValue;

			cml::CVector<float32, 100, true>::it Iterator = TestVector.begin() + 20;

			std::cout << "test_insert -> Insert element in float Vector\n";
			fprintf(fpTest, "test_insert -> Insert element in float Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.insert(Iterator, 99); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, floattestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Insert element in int Vector */
		{
			/* Test case data declarations */			

            cml::CVector<sint32, 100, true> TestVector( inttestArrayData123, 80 );
            							
			cml::boolean_t returnValue;

			cml::CVector<sint32, 100, true>::it Iterator = TestVector.begin() + 20;

			std::cout << "test_insert -> Insert element in int Vector\n";
			fprintf(fpTest, "test_insert -> Insert element in int Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.insert(Iterator, 99); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, inttestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Insert element in short Vector */
		{
			/* Test case data declarations */			

            cml::CVector<sint16, 100, true> TestVector( shorttestArrayData123, 80 );
            							
			cml::boolean_t returnValue;

			cml::CVector<sint16, 100, true>::it Iterator = TestVector.begin() + 20;

			std::cout << "test_insert -> Insert element in short Vector\n";
			fprintf(fpTest, "test_insert -> Insert element in short Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.insert(Iterator, 99); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, shorttestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Insert element in char Vector */
		{
			/* Test case data declarations */			

            cml::CVector<sint8, 100, true> TestVector( chartestArrayData123, 80 );
            							
			cml::boolean_t returnValue;

			cml::CVector<sint8, 100, true>::it Iterator = TestVector.begin() + 20;

			std::cout << "test_insert -> Insert element in char Vector\n";
			fprintf(fpTest, "test_insert -> Insert element in char Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.insert(Iterator, 99); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, chartestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}
	
		std::cout << "END ---> test_insert\n\n";
		fprintf(fpTest, "END ---> test_insert\n\n");
	}
}

// template <class InputIterator>
// void insert (it position, InputIterator first, InputIterator last)
void TEST_CLASS::test_insert_multiple_elements(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_insert_multiple_elements\n\n";
		fprintf(fpTest, "START ---> test_insert_multiple_elements\n\n");
				
		/* Insert multiple elements in float Vector */
		{
			/* Test case data declarations */			

            cml::CVector<float32, 100, true> TestVector( floattestArrayData123, 80 );
            							
			cml::boolean_t returnValue;

			cml::CVector<float32, 100, true>::it Iterator = TestVector.begin() + 20;
			
			std::cout << "test_insert_multiple_elements -> Insert multiple elements in float Vector\n";
			fprintf(fpTest, "test_insert_multiple_elements -> Insert multiple elements in float Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.insert(Iterator, TestVector.begin() + 50, TestVector.begin() + 60); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, floattestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Insert multiple elements in int Vector */
		{
			/* Test case data declarations */			

            cml::CVector<sint32, 100, true> TestVector( inttestArrayData123, 80 );
            							
			cml::boolean_t returnValue;

			cml::CVector<sint32, 100, true>::it Iterator = TestVector.begin() + 20;

			std::cout << "test_insert_multiple_elements -> Insert multiple elements in int Vector\n";
			fprintf(fpTest, "test_insert_multiple_elements -> Insert multiple elements in int Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.insert(Iterator, TestVector.begin() + 50, TestVector.begin() + 60); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, inttestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Insert multiple elements in short Vector */
		{
			/* Test case data declarations */			

            cml::CVector<sint16, 100, true> TestVector( shorttestArrayData123, 80 );
            							
			cml::boolean_t returnValue;

			cml::CVector<sint16, 100, true>::it Iterator = TestVector.begin() + 20;

			std::cout << "test_insert_multiple_elements -> Insert multiple elements in short Vector\n";
			fprintf(fpTest, "test_insert_multiple_elements -> Insert multiple elements in short Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.insert(Iterator, TestVector.begin() + 50, TestVector.begin() + 60); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, shorttestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Insert multiple elements in char Vector */
		{
			/* Test case data declarations */			

            cml::CVector<sint8, 100, true> TestVector( chartestArrayData123, 80 );
            							
			cml::boolean_t returnValue;

			cml::CVector<sint8, 100, true>::it Iterator = TestVector.begin() + 20;

			std::cout << "test_insert_multiple_elements -> Insert multiple elements in char Vector\n";
			fprintf(fpTest, "test_insert_multiple_elements -> Insert multiple elements in char Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.insert(Iterator, TestVector.begin() + 50, TestVector.begin() + 60); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, chartestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}
	
		std::cout << "END ---> test_insert_multiple_elements\n\n";
		fprintf(fpTest, "END ---> test_insert_multiple_elements\n\n");
	}
}

//it erase(const cIt& position)
void TEST_CLASS::test_erase(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_erase\n\n";
		fprintf(fpTest, "START ---> test_erase\n\n");
				
		/* Erase element in float Vector */
		{
			/* Test case data declarations */			

            cml::CVector<float32, 100, true> TestVector( floattestArrayData123, 80 );
            							
			cml::boolean_t returnValue;

			cml::CVector<float32, 100, true>::it Iterator = TestVector.begin() + 20;

			std::cout << "test_erase -> Erase element in float Vector\n";
			fprintf(fpTest, "test_erase -> Erase element in float Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.erase(Iterator); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, floattestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Erase element in int Vector */
		{
			/* Test case data declarations */			

            cml::CVector<sint32, 100, true> TestVector( inttestArrayData123, 80 );
            							
			cml::boolean_t returnValue;

			cml::CVector<sint32, 100, true>::it Iterator = TestVector.begin() + 20;

			std::cout << "test_erase -> Erase element in int Vector\n";
			fprintf(fpTest, "test_erase -> Erase element in int Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.erase(Iterator); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, inttestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Erase element in short Vector */
		{
			/* Test case data declarations */			

            cml::CVector<sint16, 100, true> TestVector( shorttestArrayData123, 80 );
            							
			cml::boolean_t returnValue;

			cml::CVector<sint16, 100, true>::it Iterator = TestVector.begin() + 20;

			std::cout << "test_erase -> Erase element in short Vector\n";
			fprintf(fpTest, "test_erase -> Erase element in short Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.erase(Iterator); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, shorttestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* Erase element in char Vector */
		{
			/* Test case data declarations */			

            cml::CVector<sint8, 100, true> TestVector( chartestArrayData123, 80 );
            							
			cml::boolean_t returnValue;

			cml::CVector<sint8, 100, true>::it Iterator = TestVector.begin() + 20;

			std::cout << "test_erase -> Erase element in char Vector\n";
			fprintf(fpTest, "test_erase -> Erase element in char Vector\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			TestVector.erase(Iterator); /* Overloaded Assignment operator */

			returnValue = checkCVectorContent(TestVector, chartestArrayData123);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}
	
		std::cout << "END ---> test_erase\n\n";
		fprintf(fpTest, "END ---> test_erase\n\n");
	}
}




// End of test cases      

