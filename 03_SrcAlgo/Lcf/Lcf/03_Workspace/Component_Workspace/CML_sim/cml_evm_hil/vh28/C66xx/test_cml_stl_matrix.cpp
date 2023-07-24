/*! \file **********************************************************************

COMPANY:                   Continental India

CPU:                       CPU-Independent

COMPONENT:                 CML (Common Math Library)

MODULNAME:                 test_cml_stl_matrix.cpp

DESCRIPTION:               Test script for Matrix Computations Library

AUTHOR:                    Balachandra Naik

CREATION DATE:             18.12.2015

VERSION:                   $Revision: 1.1 $

**************************************************************************** */

/* Include files from software under test */
#include <stdio.h>
#include <iostream>
#include "cml_ext.h"
#include "cml_stl_matrix.h"
#include "cml_mtrx.c"
#include "cml_misc.c"
#include "cml_trigo.c"
#include "cml_mat.c"

/* Global test data declarartions */
//float32 A_glob[65536];

//float32 B_glob[65536];

/* Test Log file */
extern FILE *fpTest;

/* Function declaration */
void test_cml_stl_matrix(void);



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

/* This function prints the data contained in the CMatrix object. */
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


template < typename T, sint32 ROWS, sint32 COLS, bool EXT_MEM >
void check__vMatrixPrint( cml::CMatrix< T, ROWS, COLS, EXT_MEM > &oMatrix, FILE *fpTest)
{    
    int  iIndex= 0;
    for( int row=0; row<oMatrix.rows(); row++ )
    {
        for( int col=0; col<oMatrix.cols(); col++ )
        {            
			check__PrintValue(oMatrix[iIndex], fpTest);
            iIndex++;
        }

		fprintf(fpTest, "\n");
    } 

	fprintf(fpTest, "\n\n");
}

void check_float_ArrayPrint(int rows, int cols, const float32 *Array, FILE *fpTest)
{
    int  iIndex= 0;
    for( int row=0; row<rows; row++ )
    {
        for( int col=0; col<cols; col++ )
        {            
			check__PrintValue(Array[iIndex], fpTest);
            iIndex++;
        }

		fprintf(fpTest, "\n");
    } 

	fprintf(fpTest, "\n\n");
}

void check_int_ArrayPrint(int rows, int cols, const sint32 *Array, FILE *fpTest)
{
    int  iIndex= 0;
    for( int row=0; row<rows; row++ )
    {
        for( int col=0; col<cols; col++ )
        {            
			check__PrintValue(Array[iIndex], fpTest);
            iIndex++;
        }

		fprintf(fpTest, "\n");
    } 

	fprintf(fpTest, "\n\n");
}

void check_short_ArrayPrint(int rows, int cols, const sint16 *Array, FILE *fpTest)
{
    int  iIndex= 0;
    for( int row=0; row<rows; row++ )
    {
        for( int col=0; col<cols; col++ )
        {            
			check__PrintValue(Array[iIndex], fpTest);
            iIndex++;
        }

		fprintf(fpTest, "\n");
    } 

	fprintf(fpTest, "\n\n");
}

void check_char_ArrayPrint(int rows, int cols, const sint8 *Array, FILE *fpTest)
{
    int  iIndex= 0;
    for( int row=0; row<rows; row++ )
    {
        for( int col=0; col<cols; col++ )
        {            
			check__PrintValue(Array[iIndex], fpTest);
            iIndex++;
        }

		fprintf(fpTest, "\n");
    } 

	fprintf(fpTest, "\n\n");
}


/* This function checks global data against the expected values. */
static void check_global_data()
{
	std::cout << "Status --->  PASS\n\n"; 
	fprintf(fpTest, "Status --->  PASS\n");
}
/*****************************************************************************/
/* Test class declaration                                                    */
/*****************************************************************************/
class TEST_CLASS
{
public:
	void run_tests_matrix();
	void test_assignment_operator_matrix_copy(int);
	void test_add_operator_matrix_addition(int);
	void test_add_operator_matrix_addition_return_matrix(int);
	void test_subtract_operator_matrix_subtraction(int);
	void test_subtract_operator_matrix_subtraction_return_matrix(int);
	void test_negate_operator_matrix_negate_return_matrix(int);
	void test_multiply_operator_matrix_multiplication(int);
	void test_multiply_operator_matrix_multiplication_return_matrix(int);
	void test_multiply_operator_matrix_multiplication_by_scalar(int);
	void test_devide_operator_matrix_division_by_scalar(int);
	void test_addition_operator_matrix_addition_by_scalar(int);
	void test_subtraction_operator_matrix_subtraction_by_scalar(int);
	void test_multiply_operator_matrix_multiplication_by_scalar_internal_memory(int);
	void test_devide_operator_matrix_division_by_scalar_internal_memory(int);
	void test_addition_operator_matrix_addition_by_scalar_internal_memory(int);
	void test_subtraction_operator_matrix_subtraction_by_scalar_internal_memory(int);
	void test_setIdentity(int);
	void test_transpose(int);
	void test_mulSym(int);
	void test_mulTrnsp(int);
	void test_trnspMul(int);
	void test_invert(int);
	void test_getCholesky(int);
	void test_getLowTriaInverse(int);
	void test_getLowTriaSqr(int);
	void test_getUppTriaSqr(int);
	/*void test_CML_f_AbsGen(int);
	void test_CML_f_MinGen(int);
	void test_CML_f_MaxGen(int);
	void test_CML_f_Round2FloatGen(int);
	void test_CML_s_Round2IntGen(int);
	void test_CML_u_Round2UintGen(int);
	void test_CML_f_Floor2FloatGen(int);
	void test_CML_f_Ceil2FloatGen(int);
	void test_CML_f_MultAddGen(int);
	void test_CML_a_InitMatrixHeader(int);*/
	void test_CML_CMatrix_Constructor(int);
#ifndef NDEBUG
	void test_getAlmostEqualRelativeAndAbs(int);
#endif
	
};

/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_stl_matrix(void)
{
	TEST_CLASS test_object;
		
	std::cout << "******** Start Testing: Matrix Library functions ********\n\n";
	fprintf(fpTest, "******** Start Testing: Matrix Library functions ********\n\n");

	test_object.run_tests_matrix();

	std::cout << "End of Testing: Matrix Library functions\n\n";
	fprintf(fpTest, "End of Testing: Matrix Library functions\n\n");

}

/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests_matrix() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS::run_tests_matrix()
{
	//test_CML_CMatrix_Constructor(1);
	test_assignment_operator_matrix_copy(1);
	test_add_operator_matrix_addition(1);
	test_add_operator_matrix_addition_return_matrix(1);
	test_subtract_operator_matrix_subtraction(1);
	test_subtract_operator_matrix_subtraction_return_matrix(1);
	test_negate_operator_matrix_negate_return_matrix(1);
	test_multiply_operator_matrix_multiplication(1);
	test_multiply_operator_matrix_multiplication_return_matrix(1);
	test_multiply_operator_matrix_multiplication_by_scalar(1);
	test_devide_operator_matrix_division_by_scalar(1);
	test_addition_operator_matrix_addition_by_scalar(1);
	test_subtraction_operator_matrix_subtraction_by_scalar(1);
	test_multiply_operator_matrix_multiplication_by_scalar_internal_memory(1);
	test_devide_operator_matrix_division_by_scalar_internal_memory(1);
	test_addition_operator_matrix_addition_by_scalar_internal_memory(1);
	test_subtraction_operator_matrix_subtraction_by_scalar_internal_memory(1);
	test_setIdentity(1);
	test_transpose(1);
	test_mulSym(1);
	test_mulTrnsp(1);
	test_trnspMul(1);
	test_invert(1);
	test_getCholesky(1);
	test_getLowTriaInverse(1);
	test_getLowTriaSqr(1);
	test_getUppTriaSqr(1);	

#ifndef NDEBUG
	//test_getAlmostEqualRelativeAndAbs(1);
#endif	

}

/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/

void TEST_CLASS::test_CML_CMatrix_Constructor(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_CML_CMatrix_Constructor\n";		

		/* Test case data declarations */
		cml::CMatrix<int, 3, 3, false> *testObj;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* Call Function Under Test */
		testObj = new cml::CMatrix<int, 3, 3, false>();
		
		std::cout << "END ---> test_CML_CMatrix_Constructor\n\n";		
	}
}


//template< typename TYPE2, boolean_t EXT_MEM2 >
//CMatrix& operator=(const CMatrix<TYPE2, ROWS, COLS, EXT_MEM2>& rhs)
void TEST_CLASS::test_assignment_operator_matrix_copy(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_assignment_operator_matrix_copy\n\n";		
		fprintf(fpTest, "START ---> test_assignment_operator_matrix_copy\n\n");

		fprintf(fpTest, "Function Name ---> operator= \n\n");
				
		/* Copy float Matrix :  4X4 Matrix */
		fprintf(fpTest, "Test Case ---> Copy Matrix of type float --> A = B\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		{
			/* Test case input data declarations */
			const float32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			const float32 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			cml::CMatrix<float32, 4, 4, false> testMatrix(A);
				
			cml::boolean_t returnValue;
						
			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_float_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, B, fpTest);	

			fprintf(fpTest, "B = \n");
			check_float_ArrayPrint(4, 4, B, fpTest);	

			std::cout << "START ---> test_assignment_operator_matrix_copy\n\n";
		    
			std::cout << "test_assignment_operator_matrix_copy -> Copy float Matrix :  4X4 Matrix\n";			

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix = B; /* Overloaded Assignment operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A = \n");
			check__vMatrixPrint<float32, 4, 4, false>(testMatrix, fpTest);	

			fprintf(fpTest, "B = \n");
			check_float_ArrayPrint(4, 4, B, fpTest);	

#ifndef NDEBUG
			/* Checks on global data */			
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(B);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}
		
		/* Copy int Matrix :  4X4 Matrix */
		fprintf(fpTest, "Test Case ---> Copy Matrix of type int --> A = B\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		{
			/* Test case input data declarations */
			sint32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint32 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			cml::CMatrix<sint32, 4, 4, true> testMatrix(A);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_int_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, B, fpTest);	

			fprintf(fpTest, "B = \n");
			check_int_ArrayPrint(4, 4, B, fpTest);	

			std::cout << "test_assignment_operator_matrix_copy -> Copy int Matrix :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix = B; /* Overloaded Assignment operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(testMatrix, fpTest);	

			fprintf(fpTest, "B = \n");
			check_int_ArrayPrint(4, 4, B, fpTest);						

#ifndef NDEBUG
			/* Checks on global data */			
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(B);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		/* Copy short Matrix :  4X4 Matrix */
		fprintf(fpTest, "Test Case ---> Copy Matrix of type short --> A = B\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		{
			/* Test case input data declarations */
			sint16 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint16 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			cml::CMatrix<sint16, 4, 4, true> testMatrix(A);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_short_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, B, fpTest);	

			fprintf(fpTest, "B = \n");
			check_short_ArrayPrint(4, 4, B, fpTest);	

			std::cout << "test_assignment_operator_matrix_copy -> Copy short Matrix :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix = B; /* Overloaded Assignment operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(testMatrix, fpTest);	

			fprintf(fpTest, "B = \n");
			check_short_ArrayPrint(4, 4, B, fpTest);

#ifndef NDEBUG
			/* Checks on global data */			
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(B);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";  
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		/* Copy char Matrix :  4X4 Matrix */
		fprintf(fpTest, "Test Case ---> Copy Matrix of type char --> A = B\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		{
			/* Test case input data declarations */
			sint8 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint8 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			cml::CMatrix<sint8, 4, 4, true> testMatrix(A);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_char_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, B, fpTest);	

			fprintf(fpTest, "B = \n");
			check_char_ArrayPrint(4, 4, B, fpTest);

			std::cout << "test_assignment_operator_matrix_copy -> Copy char Matrix :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix = B; /* Overloaded Assignment operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(testMatrix, fpTest);	

			fprintf(fpTest, "B = \n");
			check_char_ArrayPrint(4, 4, B, fpTest);

#ifndef NDEBUG
			/* Checks on global data */			
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(B);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		std::cout << "END ---> test_assignment_operator_matrix_copy\n\n";
		fprintf(fpTest, "END ---> test_assignment_operator_matrix_copy\n\n");
	}
}

//template< typename TYPE2, boolean_t EXT_MEM2 >
//CMatrix& operator+=(const CMatrix<TYPE2, ROWS, COLS, EXT_MEM2>& rhs)
void TEST_CLASS::test_add_operator_matrix_addition(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_add_operator_matrix_addition\n\n";
		fprintf(fpTest, "START ---> test_add_operator_matrix_addition\n\n");

		fprintf(fpTest, "Function Name ---> operator+= \n\n");
				
		/* Add float Matrices :  4X4 Matrix */
		fprintf(fpTest, "Test Case ---> Add Matrices of type float --> A += B, assign to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
				
		{
			/* Test case input data declarations */
			float32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			float32 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			float32 result[16] = {
				2,		2,		3,		4,
				5,		12,		7,		8,
				9,		10,		22,		12,
				13,		14,		15,		32
			};

			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_float_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A+B = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);				

			std::cout << "test_add_operator_matrix_addition -> Add float Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 += testMatrix2; /* Overloaded Addition Assignment operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A+B = \n");
			check__vMatrixPrint<float32, 4, 4, true>(testMatrix1, fpTest);	
						
#ifndef NDEBUG
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}
		
		/* Add int Matrices :  4X4 Matrix */
		fprintf(fpTest, "Test Case ---> Add Matrices of type int --> A += B, assign to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		{
			/* Test case input data declarations */
			sint32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint32 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			sint32 result[16] = {
				2,		2,		3,		4,
				5,		12,		7,		8,
				9,		10,		22,		12,
				13,		14,		15,		32
			};

			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_int_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A+B = \n");
			check_int_ArrayPrint(4, 4, result, fpTest);		

			std::cout << "test_add_operator_matrix_addition -> Add int Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 += testMatrix2; /* Overloaded Addition Assignment operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A+B = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(testMatrix1, fpTest);	

#ifndef NDEBUG
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		/* Add short Matrices :  4X4 Matrix */
		fprintf(fpTest, "Test Case ---> Add Matrices of type short --> A += B, assign to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		{
			/* Test case input data declarations */
			sint16 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint16 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			sint16 result[16] = {
				2,		2,		3,		4,
				5,		12,		7,		8,
				9,		10,		22,		12,
				13,		14,		15,		32
			};

			typedef cml::CMatrix <sint16, 4, 4, true> self;

			cml::CMatrix<sint16, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_short_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A+B = \n");
			check_short_ArrayPrint(4, 4, result, fpTest);	

			std::cout << "test_add_operator_matrix_addition -> Add short Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 += testMatrix2; /* Overloaded Addition Assignment operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A+B = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(testMatrix1, fpTest);	

#ifndef NDEBUG
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		/* Add char Matrices :  4X4 Matrix */
		fprintf(fpTest, "Test Case ---> Add Matrices of type char --> A += B, assign to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
		{
			/* Test case input data declarations */
			sint8 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint8 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			sint8 result[16] = {
				2,		2,		3,		4,
				5,		12,		7,		8,
				9,		10,		22,		12,
				13,		14,		15,		32
			};

			typedef cml::CMatrix <sint8, 4, 4, true> self;

			cml::CMatrix<sint8, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_char_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A+B = \n");
			check_char_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_add_operator_matrix_addition -> Add char Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 += testMatrix2; /* Overloaded Addition Assignment operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A+B = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";   
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		std::cout << "END ---> test_add_operator_matrix_addition\n\n";
		fprintf(fpTest, "END ---> test_add_operator_matrix_addition\n\n");
	}
}

//template< typename TYPE2, boolean_t EXT_MEM2 >
//CMatrix<type, ROWS, COLS, false> operator+(const CMatrix<TYPE2, ROWS, COLS, EXT_MEM2>& rhs) const
void TEST_CLASS::test_add_operator_matrix_addition_return_matrix(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_add_operator_matrix_addition_return_matrix\n\n";
		fprintf(fpTest, "START ---> test_add_operator_matrix_addition_return_matrix\n\n");
				
		fprintf(fpTest, "Function Name ---> operator+ \n\n");
				
		/* Add float Matrices :  4X4 Matrix */
		fprintf(fpTest, "Test Case ---> Add Matrices of type float --> A += B, without assigning to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		{
			/* Test case input data declarations */
			float32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			float32 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			float32 result[16] = {
				2,		2,		3,		4,
				5,		12,		7,		8,
				9,		10,		22,		12,
				13,		14,		15,		32
			};

			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			self return_matrix(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_float_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A+B = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_add_operator_matrix_addition_return_matrix -> Add float Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1 + testMatrix2; /* Overloaded Addition operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A+B = \n");
			check__vMatrixPrint<float32, 4, 4, true>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}
		
		/* Add int Matrices :  4X4 Matrix */
		fprintf(fpTest, "Test Case ---> Add Matrices of type int --> A += B, without assigning to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		{
			/* Test case input data declarations */
			sint32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint32 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			sint32 result[16] = {
				2,		2,		3,		4,
				5,		12,		7,		8,
				9,		10,		22,		12,
				13,		14,		15,		32
			};

			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			self return_matrix(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_int_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A+B = \n");
			check_int_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_add_operator_matrix_addition_return_matrix -> Add int Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1 + testMatrix2; /* Overloaded Addition operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A+B = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		/* Add short Matrices :  4X4 Matrix */
		fprintf(fpTest, "Test Case ---> Add Matrices of type short --> A += B, without assigning to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		{
			/* Test case input data declarations */
			sint16 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint16 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			sint16 result[16] = {
				2,		2,		3,		4,
				5,		12,		7,		8,
				9,		10,		22,		12,
				13,		14,		15,		32
			};

			typedef cml::CMatrix <sint16, 4, 4, true> self;

			cml::CMatrix<sint16, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			self return_matrix(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_short_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A+B = \n");
			check_short_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_add_operator_matrix_addition_return_matrix -> Add short Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1 + testMatrix2; /* Overloaded Addition operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A+B = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		/* Add int Matrices :  4X4 Matrix */
		fprintf(fpTest, "Test Case ---> Add Matrices of type char --> A += B, without assigning to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		{
			/* Test case input data declarations */
			sint8 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint8 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			sint8 result[16] = {
				2,		2,		3,		4,
				5,		12,		7,		8,
				9,		10,		22,		12,
				13,		14,		15,		32
			};

			typedef cml::CMatrix <sint8, 4, 4, true> self;

			cml::CMatrix<sint8, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			self return_matrix(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_char_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A+B = \n");
			check_char_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_add_operator_matrix_addition_return_matrix -> Add char Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1 + testMatrix2; /* Overloaded Addition operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A+B = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";  
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		std::cout << "END ---> test_add_operator_matrix_addition_return_matrix\n\n";
		fprintf(fpTest, "END ---> test_add_operator_matrix_addition_return_matrix\n\n");
	}
}

//template< typename TYPE2, boolean_t EXT_MEM2 >
//CMatrix& operator-=(const CMatrix<TYPE2, ROWS, COLS, EXT_MEM2>& rhs)
void TEST_CLASS::test_subtract_operator_matrix_subtraction(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_subtract_operator_matrix_subtraction\n\n";
		fprintf(fpTest, "START ---> test_subtract_operator_matrix_subtraction\n\n");

		fprintf(fpTest, "Function Name ---> operator-= \n\n");
				
		fprintf(fpTest, "Test Case ---> Subtract Matrices of type float --> A -= B, assign to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
				
		/* Subtract float Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			float32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			float32 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			float32 result[16] = {
				0,		2,		3,		4,
				5,		0,		7,		8,
				9,		10,		0,		12,
				13,		14,		15,		0
			};

			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_float_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A-B = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_subtract_operator_matrix_subtraction -> Subtract float Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 -= testMatrix2; /* Overloaded Subtraction Assignment operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A-B = \n");
			check__vMatrixPrint<float32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Subtract Matrices of type int --> A -= B, assign to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
		
		/* Subtract int Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint32 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			sint32 result[16] = {
				0,		2,		3,		4,
				5,		0,		7,		8,
				9,		10,		0,		12,
				13,		14,		15,		0
			};

			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_int_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A-B = \n");
			check_int_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_subtract_operator_matrix_subtraction -> Subtract int Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 -= testMatrix2; /* Overloaded Subtraction Assignment operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A-B = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Subtract Matrices of type short --> A -= B, assign to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Subtract short Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint16 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint16 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			sint16 result[16] = {
				0,		2,		3,		4,
				5,		0,		7,		8,
				9,		10,		0,		12,
				13,		14,		15,		0
			};

			typedef cml::CMatrix <sint16, 4, 4, true> self;

			cml::CMatrix<sint16, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_short_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A-B = \n");
			check_short_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_subtract_operator_matrix_subtraction -> Subtract short Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 -= testMatrix2; /* Overloaded Subtraction Assignment operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A-B = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Subtract Matrices of type char --> A -= B, assign to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Subtract char Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint8 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint8 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			sint8 result[16] = {
				0,		2,		3,		4,
				5,		0,		7,		8,
				9,		10,		0,		12,
				13,		14,		15,		0
			};

			typedef cml::CMatrix <sint8, 4, 4, true> self;

			cml::CMatrix<sint8, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_char_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A-B = \n");
			check_char_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_subtract_operator_matrix_subtraction -> Subtract char Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 -= testMatrix2; /* Overloaded Subtraction Assignment operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A-B = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		std::cout << "END ---> test_subtract_operator_matrix_subtraction\n\n";
		fprintf(fpTest, "END ---> test_subtract_operator_matrix_subtraction\n\n");
	}
}

//template< typename TYPE2, boolean_t EXT_MEM2 >
//CMatrix<type, ROWS, COLS, false> operator-(const CMatrix<TYPE2, ROWS, COLS, EXT_MEM2>& rhs) const
void TEST_CLASS::test_subtract_operator_matrix_subtraction_return_matrix(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_subtract_operator_matrix_subtraction_return_matrix\n\n";
		fprintf(fpTest, "START ---> test_subtract_operator_matrix_subtraction_return_matrix\n\n");

		fprintf(fpTest, "Function Name ---> operator-= \n\n");
				
		fprintf(fpTest, "Test Case ---> Subtract Matrices of type float --> A -= B, without assigning to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
				
		/* Subtract float Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			float32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			float32 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			float32 result[16] = {
				0,		2,		3,		4,
				5,		0,		7,		8,
				9,		10,		0,		12,
				13,		14,		15,		0
			};

			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			self return_matrix(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_float_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A-B = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_subtract_operator_matrix_subtraction_return_matrix -> Subtract float Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1 - testMatrix2 ; /* Overloaded Subtraction operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A-B = \n");
			check__vMatrixPrint<float32, 4, 4, true>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Subtract Matrices of type int --> A -= B, without assigning to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
		
		/* Subtract int Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint32 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			sint32 result[16] = {
				0,		2,		3,		4,
				5,		0,		7,		8,
				9,		10,		0,		12,
				13,		14,		15,		0
			};

			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			self return_matrix(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_int_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A-B = \n");
			check_int_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_subtract_operator_matrix_subtraction_return_matrix -> Subtract int Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1 - testMatrix2 ; /* Overloaded Subtraction operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A-B = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Subtract Matrices of type short --> A -= B, without assigning to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Subtract short Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint16 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint16 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			sint16 result[16] = {
				0,		2,		3,		4,
				5,		0,		7,		8,
				9,		10,		0,		12,
				13,		14,		15,		0
			};

			typedef cml::CMatrix <sint16, 4, 4, true> self;

			cml::CMatrix<sint16, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			self return_matrix(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_short_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A-B = \n");
			check_short_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_subtract_operator_matrix_subtraction_return_matrix -> Subtract short Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1 - testMatrix2 ; /* Overloaded Subtraction operator */		

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A-B = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Subtract Matrices of type char --> A -= B, without assigning to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Subtract char Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint8 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint8 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			sint8 result[16] = {
				0,		2,		3,		4,
				5,		0,		7,		8,
				9,		10,		0,		12,
				13,		14,		15,		0
			};

			typedef cml::CMatrix <sint8, 4, 4, true> self;

			cml::CMatrix<sint8, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			self return_matrix(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_char_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A-B = \n");
			check_char_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_subtract_operator_matrix_subtraction_return_matrix -> Subtract char Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1 - testMatrix2 ; /* Overloaded Subtraction operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A-B = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		std::cout << "END ---> test_subtract_operator_matrix_subtraction_return_matrix\n\n";
		fprintf(fpTest, "END ---> test_subtract_operator_matrix_subtraction_return_matrix\n\n");
	}
}

//template< boolean_t EXT_MEM2 >
//CMatrix<type, ROWS, COLS,false> operator-() const
void TEST_CLASS::test_negate_operator_matrix_negate_return_matrix(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_negate_operator_matrix_negate_return_matrix\n\n";
		fprintf(fpTest, "START ---> test_negate_operator_matrix_negate_return_matrix\n\n");

		fprintf(fpTest, "Function Name ---> operator- (Negation) \n\n");
				
		fprintf(fpTest, "Test Case ---> Negate Matrix of type float --> result = -A\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Operator not found by the Compiler */

		std::cout << "COMPILER ERROR ---> Operator not found by the Compiler \n\n";
						
		/* Negate float Matrix :  4X4 Matrix */
		{
			/* Test case input data declarations */
			float32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			float32 result[16] = {
				-1,		-2,		-3,		-4,
				-5,		-6,		-7,		-8,
				-9,		-10,	-11,	-12,
				-13,	-14,	-15,	-16
			};

			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);
						
			self return_matrix(A);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	
				
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A-B = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_negate_operator_matrix_negate_return_matrix -> Negate float Matrix :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = -(testMatrix1); /* Overloaded Negation operator */		

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "-A = \n");
			check__vMatrixPrint<float32, 4, 4, true>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> COMPILER ERROR - Operator not found by the Compiler\n\n");
		}

		fprintf(fpTest, "Test Case ---> Negate Matrix of type int --> result = -A\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
		
		/* Negate int Matrix :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint32 result[16] = {
				-1,		-2,		-3,		-4,
				-5,		-6,		-7,		-8,
				-9,		-10,	-11,	-12,
				-13,	-14,	-15,	-16
			};

			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self return_matrix(A);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	
				
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A-B = \n");
			check_int_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_negate_operator_matrix_negate_return_matrix -> Negate float Matrix :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = - testMatrix1; /* Overloaded Negation operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "-A = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> COMPILER ERROR - Operator not found by the Compiler\n\n");
		}

		fprintf(fpTest, "Test Case ---> Negate Matrix of type short --> result = -A\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Negate short Matrix :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint16 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};
				
			sint16 result[16] = {
				-1,		-2,		-3,		-4,
				-5,		-6,		-7,		-8,
				-9,		-10,	-11,	-12,
				-13,	-14,	-15,	-16
			};

			typedef cml::CMatrix <sint16, 4, 4, true> self;

			cml::CMatrix<sint16, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self return_matrix(A);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, A, fpTest);	
				
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A-B = \n");
			check_short_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_negate_operator_matrix_negate_return_matrix -> Negate float Matrix :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = - testMatrix1; /* Overloaded Negation operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "-A = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> COMPILER ERROR - Operator not found by the Compiler\n\n");
		}

		fprintf(fpTest, "Test Case ---> Negate Matrix of type char --> result = -A\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Negate char Matrix :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint8 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint8 result[16] = {
				-1,		-2,		-3,		-4,
				-5,		-6,		-7,		-8,
				-9,		-10,	-11,	-12,
				-13,	-14,	-15,	-16
			};

			typedef cml::CMatrix <sint8, 4, 4, true> self;

			cml::CMatrix<sint8, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self return_matrix(A);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, A, fpTest);	
				
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A-B = \n");
			check_char_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_negate_operator_matrix_negate_return_matrix -> Negate float Matrix :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = - testMatrix1; /* Overloaded Negation operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "-A = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> COMPILER ERROR - Operator not found by the Compiler\n\n");
		}

		std::cout << "END ---> test_negate_operator_matrix_negate_return_matrix\n\n";
		fprintf(fpTest, "END ---> test_negate_operator_matrix_negate_return_matrix\n\n");
	}
}

//template< typename TYPE2, boolean_t EXT_MEM2 >
//CMatrix& operator*= ( const CMatrix<TYPE2, COLS, COLS, EXT_MEM2>& rhs )
void TEST_CLASS::test_multiply_operator_matrix_multiplication(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_multiply_operator_matrix_multiplication\n\n";
		fprintf(fpTest, "START ---> test_multiply_operator_matrix_multiplication\n\n");

		fprintf(fpTest, "Function Name ---> operator*= \n\n");
				
		fprintf(fpTest, "Test Case ---> Multiply Matrices of type float --> A = A * B, assign to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
				
		/* Multiply float Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			float32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			float32 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			float32 result[16] = {
				1,     12,     33,     64,
				5,     36,     77,    128,
				9,     60,    121,    192,
				13,    84,    165,    256
			};

			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_float_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*B = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_multiply_operator_matrix_multiplication -> Multiply float Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 *= testMatrix2; /* Overloaded Multiplication Assignment operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*B = \n");
			check__vMatrixPrint<float32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiply Matrices of type int --> A = A * B, assign to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
		
		/* Multiply int Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint32 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			sint32 result[16] = {
				1,     12,     33,     64,
				5,     36,     77,    128,
				9,     60,    121,    192,
				13,    84,    165,    256
			};

			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_int_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*B = \n");
			check_int_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_multiply_operator_matrix_multiplication -> Multiply int Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 *= testMatrix2; /* Overloaded Multiplication Assignment operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*B = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiply Matrices of type short --> A = A * B, assign to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Multiply short Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint16 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint16 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			sint16 result[16] = {
				1,     12,     33,     64,
				5,     36,     77,    128,
				9,     60,    121,    192,
				13,    84,    165,    256
			};

			typedef cml::CMatrix <sint16, 4, 4, true> self;

			cml::CMatrix<sint16, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_short_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*B = \n");
			check_short_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_multiply_operator_matrix_multiplication -> Multiply short Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 *= testMatrix2; /* Overloaded Multiplication Assignment operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*B = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiply Matrices of type char --> A = A * B, assign to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Multiply char Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint8 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint8 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			sint8 result[16] = {
				1,     12,     33,     64,
				5,     36,     77,    128,
				9,     60,    121,    192,
				13,    84,    165,    256
			};

			typedef cml::CMatrix <sint8, 4, 4, true> self;

			cml::CMatrix<sint8, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_char_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*B = \n");
			check_char_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_multiply_operator_matrix_multiplication -> Multiply char Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 *= testMatrix2; /* Overloaded Multiplication Assignment operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*B = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";   
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiply Matrices of type char --> A = A * B, assign to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X5, 5X5\n\n");

		/* Multiply float Matrices :  4X5, 5X5 Matrix */
		{
			/* Test case input data declarations */
			sint8 A[20] = {
				1,		2,		3,		4,		10,
				5,		6,		7,		8,		10,
				9,		10,		11,		12,		10,
				13,		14,		15,		16,		10
			};

			sint8 B[25] = {
				1,		0,		0,		0,		0,
				0,		6,		0,		0,		0,
				0,		0,		11,		0,		0,
				0,		0,		0,		16,		0,
				0,		0,		0,		0,		10
			};

			sint8 result[20] = {
				1,      12,    33,    64,   100,
				5,      36,    77,   128,   100,
				9,      60,   121,   192,   100,
				13,     84,   165,   256,   100
			};

			typedef cml::CMatrix <sint8, 4, 5, true> self4x5;

			typedef cml::CMatrix <sint8, 5, 5, true> self5x5;

			cml::CMatrix<sint8, 4, 5, true> testMatrix1(A);

			self4x5 result_matrix(result);

			self5x5 testMatrix2(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 5, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_char_ArrayPrint(5, 5, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*B = \n");
			check_char_ArrayPrint(4, 5, result, fpTest);

			std::cout << "test_multiply_operator_matrix_multiplication -> Multiply float Matrices :  4X5, 5X5 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 *= testMatrix2; /* Overloaded Multiplication Assignment operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*B = \n");
			check__vMatrixPrint<sint8, 4, 5, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";   
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		std::cout << "END ---> test_multiply_operator_matrix_multiplication\n\n";
		fprintf(fpTest, "END ---> test_multiply_operator_matrix_multiplication\n\n");
	}
}

//template< typename TYPE2, sint32 COLS2, boolean_t EXT_MEM2>
//CMatrix<type, ROWS, COLS2, false> operator* ( const CMatrix<TYPE2, COLS, COLS2, EXT_MEM2>& rhs ) const
void TEST_CLASS::test_multiply_operator_matrix_multiplication_return_matrix(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_multiply_operator_matrix_multiplication_return_matrix\n\n";
		fprintf(fpTest, "START ---> test_multiply_operator_matrix_multiplication_return_matrix\n\n");

		fprintf(fpTest, "Function Name ---> operator* \n\n");
				
		fprintf(fpTest, "Test Case ---> Multiply Matrices of type float --> result = A * B, without assigning to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
				
		/* Multiply float Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			float32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			float32 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			float32 result[16] = {
				1,     12,     33,     64,
				5,     36,     77,    128,
				9,     60,    121,    192,
				13,    84,    165,    256
			};

			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			self return_matrix(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_float_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*B = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_multiply_operator_matrix_multiplication_return_matrix -> Multiply float Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1 * testMatrix2; /* Overloaded Multiplication operator */			

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*B = \n");
			check__vMatrixPrint<float32, 4, 4, true>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiply Matrices of type int --> result = A * B, without assigning to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
		
		/* Multiply int Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint32 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			sint32 result[16] = {
				1,     12,     33,     64,
				5,     36,     77,    128,
				9,     60,    121,    192,
				13,    84,    165,    256
			};

			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			self return_matrix(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_int_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*B = \n");
			check_int_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_multiply_operator_matrix_multiplication_return_matrix -> Multiply int Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1 * testMatrix2; /* Overloaded Multiplication operator */		

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*B = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiply Matrices of type short --> result = A * B, without assigning to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Multiply short Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint16 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint16 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			sint16 result[16] = {
				1,     12,     33,     64,
				5,     36,     77,    128,
				9,     60,    121,    192,
				13,    84,    165,    256
			};

			typedef cml::CMatrix <sint16, 4, 4, true> self;

			cml::CMatrix<sint16, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			self return_matrix(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_short_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*B = \n");
			check_short_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_multiply_operator_matrix_multiplication_return_matrix -> Multiply short Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1 * testMatrix2; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*B = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiply Matrices of type char --> result = A * B, without assigning to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Multiply char Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint8 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint8 B[16] = {
				1,		0,		0,		0,
				0,		6,		0,		0,
				0,		0,		11,		0,
				0,		0,		0,		16
			};

			sint8 result[16] = {
				1,     12,     33,     64,
				5,     36,     77,    128,
				9,     60,    121,    192,
				13,    84,    165,    256
			};

			typedef cml::CMatrix <sint8, 4, 4, true> self;

			cml::CMatrix<sint8, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			self return_matrix(B);
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_char_ArrayPrint(4, 4, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*B = \n");
			check_char_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_multiply_operator_matrix_multiplication_return_matrix -> Multiply char Matrices :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1 * testMatrix2; /* Overloaded Multiplication operator */		

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*B = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";  
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiply Matrices of type char --> result = A * B, without assigning to this\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Multiply float Matrices :  4X5, 5X6 Matrix */
		{
			/* Test case input data declarations */
			float32 A[20] = {
				1,		2,		3,		4,		5,
				6,		7,		8,		9,		10,
				11,		12,		13,		14,		15,
				16,		17,		18,		19,		20
			};

			float32 B[30] = {
				100,	101,	102,	103,	104,	105,
				106,	107,	108,	109,	110,	111,
				112,	113,	114,	115,	116,	117,
				118,	119,	120,	121,	122,	123,
				124,	125,	126,	127,	128,	129
			};

			float32 result[24] = {
				1740,        1755,        1770,        1785,        1800,        1815,
				4540,        4580,        4620,        4660,        4700,        4740,
				7340,        7405,        7470,        7535,        7600,        7665,
				10140,       10230,       10320,       10410,       10500,       10590
			};

			typedef cml::CMatrix <float32, 4, 6, true> self4x6;

			typedef cml::CMatrix <float32, 5, 6, true> self5x6;

			cml::CMatrix<float32, 4, 5, true> testMatrix1(A);
			cml::CMatrix<float32, 4, 6, true> testMatrix1_Debug(result);

			self4x6 result_matrix(result);

			self5x6 testMatrix2(B);

			cml::CMatrix <float32, 4, 6, false> return_matrix;
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 5, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_float_ArrayPrint(5, 6, B, fpTest);	

			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*B = \n");
			check_float_ArrayPrint(4, 6, result, fpTest);

			std::cout << "test_multiply_operator_matrix_multiplication -> Multiply float Matrices :  4X5, 5X5 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1 * testMatrix2; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*B = \n");
			check__vMatrixPrint<float32, 4, 6, false>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1_Debug = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1_Debug.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";   
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		std::cout << "END ---> test_multiply_operator_matrix_multiplication_return_matrix\n\n";
		fprintf(fpTest, "END ---> test_multiply_operator_matrix_multiplication_return_matrix\n\n");
	}
}

//self& operator*= (const_reference rhs)
void TEST_CLASS::test_multiply_operator_matrix_multiplication_by_scalar(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_multiply_operator_matrix_multiplication_by_scalar\n\n";
		fprintf(fpTest, "START ---> test_multiply_operator_matrix_multiplication_by_scalar\n\n");

		fprintf(fpTest, "Function Name ---> operator*=(Multiply by Scalar) \n\n");
				
		fprintf(fpTest, "Test Case ---> Multiply all elements of the float matrix by a scalar --> A *= Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
				
		/* Multiply float Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			float32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			float32 result[16] = {
				100,         200,         300,         400,
				500,         600,         700,         800,
				900,        1000,        1100,        1200,
				1300,       1400,        1500,        1600
			};
			
			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const float32 scale_value = 100.0;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "scale_value*A = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_multiply_operator_matrix_multiplication_by_scalar -> Multiply float Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 *= scale_value; /* Overloaded Multiplication operator */		

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "scale_value*A = \n");
			check__vMatrixPrint<float32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiply all elements of the int matrix by a scalar --> A *= Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Multiply int Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint32 result[16] = {
				100,         200,         300,         400,
				500,         600,         700,         800,
				900,        1000,        1100,        1200,
				1300,       1400,        1500,        1600
			};
			
			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint32 scale_value = 100;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "scale_value*A = \n");
			check_int_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_multiply_operator_matrix_multiplication_by_scalar -> Multiply int Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 *= scale_value; /* Overloaded Multiplication operator */		

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "scale_value*A = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiply all elements of the short matrix by a scalar --> A *= Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Multiply short Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint16 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint16 result[16] = {
				100,         200,         300,         400,
				500,         600,         700,         800,
				900,        1000,        1100,        1200,
				1300,       1400,        1500,        1600
			};
			
			typedef cml::CMatrix <sint16, 4, 4, true> self;

			cml::CMatrix<sint16, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint16 scale_value = 100;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "scale_value*A = \n");
			check_short_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_multiply_operator_matrix_multiplication_by_scalar -> Multiply short Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 *= scale_value; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "scale_value*A = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiply all elements of the char matrix by a scalar --> A *= Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Multiply char Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint8 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint8 result[16] = {				
				 5,    10,    15,    20,
				25,    30,    35,    40,
				45,    50,    55,    60,
				65,    70,    75,    80
			};
			
			typedef cml::CMatrix <sint8, 4, 4, true> self;

			cml::CMatrix<sint8, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint8 scale_value = 5;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "scale_value*A = \n");
			check_char_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_multiply_operator_matrix_multiplication_by_scalar -> Multiply char Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 *= scale_value; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "scale_value*A = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		std::cout << "END ---> test_multiply_operator_matrix_multiplication_by_scalar\n\n";
		fprintf(fpTest, "END ---> test_multiply_operator_matrix_multiplication_by_scalar\n\n");
	}
}

//self& operator/= (const_reference rhs)
void TEST_CLASS::test_devide_operator_matrix_division_by_scalar(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_devide_operator_matrix_division_by_scalar\n\n";
		fprintf(fpTest, "START ---> test_devide_operator_matrix_division_by_scalar\n\n");

		fprintf(fpTest, "Function Name ---> operator/=(Devide by Scalar) \n\n");
				
		fprintf(fpTest, "Test Case ---> Devide all elements of the float matrix by a scalar --> A /= Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
				
		/* Devide float Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			float32 A[16] = {
				100,         200,         300,         400,
				500,         600,         700,         800,
				900,        1000,        1100,        1200,
				1300,       1400,        1500,        1600				
			};

			float32 result[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};
			
			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const float32 down_scale_value = 100.0;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "down_scale_value = %f\n", down_scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A/down_scale_value = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_devide_operator_matrix_division_by_scalar -> Devide float Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 /= down_scale_value; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A/down_scale_value = \n");
			check__vMatrixPrint<float32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Devide all elements of the int matrix by a scalar --> A /= Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Devide int Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint32 A[16] = {
				100,         200,         300,         400,
				500,         600,         700,         800,
				900,        1000,        1100,        1200,
				1300,       1400,        1500,        1600				
			};

			sint32 result[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};
			
			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint32 down_scale_value = 100;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "down_scale_value = %f\n", down_scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A/down_scale_value = \n");
			check_int_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_devide_operator_matrix_division_by_scalar -> Devide int Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 /= down_scale_value; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A/down_scale_value = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Devide all elements of the short matrix by a scalar --> A /= Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Devide short Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint16 A[16] = {
				100,         200,         300,         400,
				500,         600,         700,         800,
				900,        1000,        1100,        1200,
				1300,       1400,        1500,        1600				
			};

			sint16 result[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};
			
			typedef cml::CMatrix <sint16, 4, 4, true> self;

			cml::CMatrix<sint16, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint16 down_scale_value = 100;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "down_scale_value = %f\n", down_scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A/down_scale_value = \n");
			check_short_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_devide_operator_matrix_division_by_scalar -> Devide short Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 /= down_scale_value; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A/down_scale_value = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Devide all elements of the char matrix by a scalar --> A /= Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Devide char Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint8 A[16] = {
				5,    10,    15,    20,
				25,    30,    35,    40,
				45,    50,    55,    60,
				65,    70,    75,    80				
			};

			sint8 result[16] = {				
				 1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};
			
			typedef cml::CMatrix <sint8, 4, 4, true> self;

			cml::CMatrix<sint8, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint8 down_scale_value = 5;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "down_scale_value = %f\n", down_scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A/down_scale_value = \n");
			check_char_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_devide_operator_matrix_division_by_scalar -> Devide char Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 /= down_scale_value; /* Overloaded Multiplication operator */		

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A/down_scale_value = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		std::cout << "END ---> test_devide_operator_matrix_division_by_scalar\n\n";
		fprintf(fpTest, "END ---> test_devide_operator_matrix_division_by_scalar\n\n");
	}
}

//self& operator+= (const_reference rhs)
void TEST_CLASS::test_addition_operator_matrix_addition_by_scalar(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_addition_operator_matrix_addition_by_scalar\n\n";
		fprintf(fpTest, "START ---> test_addition_operator_matrix_addition_by_scalar\n\n");

		fprintf(fpTest, "Function Name ---> operator+=(Addition by Scalar) \n\n");
				
		fprintf(fpTest, "Test Case ---> Add all elements of the float matrix by a scalar --> A += Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
				
		/* Add float Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			float32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			float32 result[16] = {
				101,   102,   103,   104,
				105,   106,   107,   108,
				109,   110,   111,   112,
				113,   114,   115,   116
			};
			
			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const float32 scale_value = 100.0;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A+scale_value = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_addition_operator_matrix_addition_by_scalar -> Add float Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 += scale_value; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A/down_scale_value = \n");
			check__vMatrixPrint<float32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Add all elements of the int matrix by a scalar --> A += Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Add int Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint32 result[16] = {
				101,   102,   103,   104,
				105,   106,   107,   108,
				109,   110,   111,   112,
				113,   114,   115,   116
			};
			
			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint32 scale_value = 100;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A+scale_value = \n");
			check_int_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_addition_operator_matrix_addition_by_scalar -> Add int Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 += scale_value; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A/down_scale_value = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Add all elements of the short matrix by a scalar --> A += Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Add short Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint16 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint16 result[16] = {
				101,   102,   103,   104,
				105,   106,   107,   108,
				109,   110,   111,   112,
				113,   114,   115,   116
			};
			
			typedef cml::CMatrix <sint16, 4, 4, true> self;

			cml::CMatrix<sint16, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint16 scale_value = 100;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A+scale_value = \n");
			check_short_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_addition_operator_matrix_addition_by_scalar -> Add short Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 += scale_value; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A/down_scale_value = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Add all elements of the char matrix by a scalar --> A += Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Add char Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint8 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint8 result[16] = {				
				101,   102,   103,   104,
				105,   106,   107,   108,
				109,   110,   111,   112,
				113,   114,   115,   116
			};
			
			typedef cml::CMatrix <sint8, 4, 4, true> self;

			cml::CMatrix<sint8, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint8 scale_value = 100;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A+scale_value = \n");
			check_char_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_addition_operator_matrix_addition_by_scalar -> Add char Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 += scale_value; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A/down_scale_value = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		std::cout << "END ---> test_addition_operator_matrix_addition_by_scalar\n\n";
		fprintf(fpTest, "END ---> test_addition_operator_matrix_addition_by_scalar\n\n");
	}
}

//self& operator-= (const_reference rhs)
void TEST_CLASS::test_subtraction_operator_matrix_subtraction_by_scalar(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_subtraction_operator_matrix_subtraction_by_scalar\n\n";
		fprintf(fpTest, "START ---> test_subtraction_operator_matrix_subtraction_by_scalar\n\n");

		fprintf(fpTest, "Function Name ---> operator-=(Subtraction by Scalar) \n\n");
				
		fprintf(fpTest, "Test Case ---> Subtract all elements of the float matrix by a scalar --> A -= Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
				
		/* Subtract float Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			float32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			float32 result[16] = {
				0,     1,     2,     3,
				4,     5,     6,     7,
				8,     9,     10,    11,
				12,    13,    14,    15
			};
			
			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const float32 scale_value = 1.0;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A-scale_value = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_subtraction_operator_matrix_subtraction_by_scalar -> Subtract float Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 -= scale_value; /* Overloaded Multiplication operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A-scale_value = \n");
			check__vMatrixPrint<float32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Subtract all elements of the int matrix by a scalar --> A -= Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Subtract int Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint32 result[16] = {
				0,     1,     2,     3,
				4,     5,     6,     7,
				8,     9,     10,    11,
				12,    13,    14,    15
			};
			
			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint32 scale_value = 1;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A-scale_value = \n");
			check_int_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_subtraction_operator_matrix_subtraction_by_scalar -> Subtract int Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 -= scale_value; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A-scale_value = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Subtract all elements of the short matrix by a scalar --> A -= Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Subtract short Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint16 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint16 result[16] = {
				0,     1,     2,     3,
				4,     5,     6,     7,
				8,     9,     10,    11,
				12,    13,    14,    15
			};
			
			typedef cml::CMatrix <sint16, 4, 4, true> self;

			cml::CMatrix<sint16, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint16 scale_value = 1;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A-scale_value = \n");
			check_short_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_subtraction_operator_matrix_subtraction_by_scalar -> Subtract short Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 -= scale_value; /* Overloaded Multiplication operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A-scale_value = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Subtract all elements of the char matrix by a scalar --> A -= Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Subtract char Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint8 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint8 result[16] = {				
				0,     1,     2,     3,
				4,     5,     6,     7,
				8,     9,     10,    11,
				12,    13,    14,    15
			};
			
			typedef cml::CMatrix <sint8, 4, 4, true> self;

			cml::CMatrix<sint8, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint8 scale_value = 1;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A-scale_value = \n");
			check_char_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_subtraction_operator_matrix_subtraction_by_scalar -> Subtract char Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 -= scale_value; /* Overloaded Multiplication operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A-scale_value = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		std::cout << "END ---> test_subtraction_operator_matrix_subtraction_by_scalar\n\n";
		fprintf(fpTest, "END ---> test_subtraction_operator_matrix_subtraction_by_scalar\n\n");
	}
}

//self_internal operator* (const_reference rhs) const
void TEST_CLASS::test_multiply_operator_matrix_multiplication_by_scalar_internal_memory(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_multiply_operator_matrix_multiplication_by_scalar_internal_memory\n\n";
		fprintf(fpTest, "START ---> test_multiply_operator_matrix_multiplication_by_scalar_internal_memory\n\n");

		fprintf(fpTest, "Function Name ---> operator*(Multiply by Scalar with result in internal memory) \n\n");
				
		fprintf(fpTest, "Test Case ---> Multiply all elements of the float matrix by a scalar --> result = A * Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
				
		/* Multiply float Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			float32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			float32 result[16] = {
				100,         200,         300,         400,
				500,         600,         700,         800,
				900,        1000,        1100,        1200,
				1300,       1400,        1500,        1600
			};
			
			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const float32 scale_value = 100.0;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*scale_value = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_multiply_operator_matrix_multiplication_by_scalar_internal_memory -> Multiply float Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 = testMatrix1 * scale_value; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*scale_value = \n");
			check__vMatrixPrint<float32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiply all elements of the int matrix by a scalar --> result = A * Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Multiply int Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint32 result[16] = {
				100,         200,         300,         400,
				500,         600,         700,         800,
				900,        1000,        1100,        1200,
				1300,       1400,        1500,        1600
			};
			
			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint32 scale_value = 100;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*scale_value = \n");
			check_int_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_multiply_operator_matrix_multiplication_by_scalar_internal_memory -> Multiply int Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 *= scale_value; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*scale_value = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiply all elements of the short matrix by a scalar --> result = A * Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Multiply short Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint16 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint16 result[16] = {
				100,         200,         300,         400,
				500,         600,         700,         800,
				900,        1000,        1100,        1200,
				1300,       1400,        1500,        1600
			};
			
			typedef cml::CMatrix <sint16, 4, 4, true> self;

			cml::CMatrix<sint16, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint16 scale_value = 100;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*scale_value = \n");
			check_short_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_multiply_operator_matrix_multiplication_by_scalar_internal_memory -> Multiply short Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 = testMatrix1 * scale_value; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*scale_value = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiply all elements of the char matrix by a scalar --> result = A * Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Multiply char Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint8 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint8 result[16] = {				
				 5,    10,    15,    20,
				25,    30,    35,    40,
				45,    50,    55,    60,
				65,    70,    75,    80
			};
			
			typedef cml::CMatrix <sint8, 4, 4, true> self;

			cml::CMatrix<sint8, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint8 scale_value = 5;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*scale_value = \n");
			check_char_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_multiply_operator_matrix_multiplication_by_scalar_internal_memory -> Multiply char Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 = testMatrix1 * scale_value; /* Overloaded Multiplication operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*scale_value = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		std::cout << "END ---> test_multiply_operator_matrix_multiplication_by_scalar_internal_memory\n\n";
		fprintf(fpTest, "END ---> test_multiply_operator_matrix_multiplication_by_scalar_internal_memory\n\n");
	}
}

//self_internal operator/ (const_reference rhs) const
void TEST_CLASS::test_devide_operator_matrix_division_by_scalar_internal_memory(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_devide_operator_matrix_division_by_scalar_internal_memory\n\n";
		fprintf(fpTest, "START ---> test_devide_operator_matrix_division_by_scalar_internal_memory\n\n");

		fprintf(fpTest, "Function Name ---> operator/(Devide by Scalar with result in internal memory) \n\n");
				
		fprintf(fpTest, "Test Case ---> Devide all elements of the float matrix by a scalar -->  result = A / Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
				
		/* Devide float Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			float32 A[16] = {
				100,         200,         300,         400,
				500,         600,         700,         800,
				900,        1000,        1100,        1200,
				1300,       1400,        1500,        1600				
			};

			float32 result[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};
			
			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const float32 down_scale_value = 100.0;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "down_scale_value = %f\n", down_scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A/down_scale_value = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_devide_operator_matrix_division_by_scalar_internal_memory -> Devide float Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			testMatrix1 = testMatrix1 / down_scale_value; /* Overloaded Multiplication operator */		

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A/down_scale_value = \n");
			check__vMatrixPrint<float32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Devide all elements of the int matrix by a scalar -->  result = A / Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Devide int Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint32 A[16] = {
				100,         200,         300,         400,
				500,         600,         700,         800,
				900,        1000,        1100,        1200,
				1300,       1400,        1500,        1600				
			};

			sint32 result[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};
			
			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint32 down_scale_value = 100;

			cml::boolean_t returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "down_scale_value = %f\n", down_scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A/down_scale_value = \n");
			check_int_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_devide_operator_matrix_division_by_scalar_internal_memory -> Devide int Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			testMatrix1 = testMatrix1 / down_scale_value; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A/down_scale_value = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Devide all elements of the short matrix by a scalar -->  result = A / Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Devide short Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint16 A[16] = {
				100,         200,         300,         400,
				500,         600,         700,         800,
				900,        1000,        1100,        1200,
				1300,       1400,        1500,        1600				
			};

			sint16 result[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};
			
			typedef cml::CMatrix <sint16, 4, 4, true> self;

			cml::CMatrix<sint16, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint16 down_scale_value = 100;

			cml::boolean_t returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "down_scale_value = %f\n", down_scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A/down_scale_value = \n");
			check_short_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_devide_operator_matrix_division_by_scalar_internal_memory -> Devide short Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			testMatrix1 = testMatrix1 / down_scale_value; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A/down_scale_value = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Devide all elements of the char matrix by a scalar -->  result = A / Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Devide char Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint8 A[16] = {
				5,    10,    15,    20,
				25,    30,    35,    40,
				45,    50,    55,    60,
				65,    70,    75,    80				
			};

			sint8 result[16] = {				
				 1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};
			
			typedef cml::CMatrix <sint8, 4, 4, true> self;

			cml::CMatrix<sint8, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint8 down_scale_value = 5;

			cml::boolean_t returnValue; 

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "down_scale_value = %f\n", down_scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A/down_scale_value = \n");
			check_char_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_devide_operator_matrix_division_by_scalar_internal_memory -> Devide char Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			testMatrix1 = testMatrix1 / down_scale_value; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A/down_scale_value = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		std::cout << "END ---> test_devide_operator_matrix_division_by_scalar_internal_memory\n\n";
		fprintf(fpTest, "END ---> test_devide_operator_matrix_division_by_scalar_internal_memory\n\n");
	}
}

//self_internal operator+ (const_reference rhs) const
void TEST_CLASS::test_addition_operator_matrix_addition_by_scalar_internal_memory(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_addition_operator_matrix_addition_by_scalar_internal_memory\n\n";
		fprintf(fpTest, "START ---> test_addition_operator_matrix_addition_by_scalar_internal_memory\n\n");

		fprintf(fpTest, "Function Name ---> operator+(Addition by Scalar with result in internal memory) \n\n");
				
		fprintf(fpTest, "Test Case ---> Add all elements of the float matrix by a scalar -->  result = A + Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
				
		/* Add float Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			float32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			float32 result[16] = {
				101,   102,   103,   104,
				105,   106,   107,   108,
				109,   110,   111,   112,
				113,   114,   115,   116
			};
			
			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const float32 scale_value = 100.0;

			cml::boolean_t returnValue; 

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A+scale_value = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_addition_operator_matrix_addition_by_scalar_internal_memory -> Add float Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			testMatrix1 = testMatrix1 + scale_value; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A+scale_value = \n");
			check__vMatrixPrint<float32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Add all elements of the int matrix by a scalar -->  result = A + Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Add int Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint32 result[16] = {
				101,   102,   103,   104,
				105,   106,   107,   108,
				109,   110,   111,   112,
				113,   114,   115,   116
			};
			
			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint32 scale_value = 100;

			cml::boolean_t returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A+scale_value = \n");
			check_int_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_addition_operator_matrix_addition_by_scalar_internal_memory -> Add int Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();				

			/* Call Function Under Test */			
			testMatrix1 = testMatrix1 + scale_value; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A+scale_value = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Add all elements of the short matrix by a scalar -->  result = A + Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Add short Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint16 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint16 result[16] = {
				101,   102,   103,   104,
				105,   106,   107,   108,
				109,   110,   111,   112,
				113,   114,   115,   116
			};
			
			typedef cml::CMatrix <sint16, 4, 4, true> self;

			cml::CMatrix<sint16, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint16 scale_value = 100;

			cml::boolean_t returnValue; 

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A+scale_value = \n");
			check_short_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_addition_operator_matrix_addition_by_scalar_internal_memory -> Add short Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			testMatrix1 = testMatrix1 + scale_value; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A+scale_value = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Add all elements of the char matrix by a scalar -->  result = A + Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Add char Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint8 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint8 result[16] = {				
				101,   102,   103,   104,
				105,   106,   107,   108,
				109,   110,   111,   112,
				113,   114,   115,   116
			};
			
			typedef cml::CMatrix <sint8, 4, 4, true> self;

			cml::CMatrix<sint8, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint8 scale_value = 100;

			cml::boolean_t returnValue; 

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A+scale_value = \n");
			check_char_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_addition_operator_matrix_addition_by_scalar_internal_memory -> Add char Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			testMatrix1 = testMatrix1 + scale_value; /* Overloaded Multiplication operator */		

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A+scale_value = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		std::cout << "END ---> test_addition_operator_matrix_addition_by_scalar_internal_memory\n\n";
		fprintf(fpTest, "END ---> test_addition_operator_matrix_addition_by_scalar_internal_memory\n\n");
	}
}

//self_internal operator- (const_reference rhs) const
void TEST_CLASS::test_subtraction_operator_matrix_subtraction_by_scalar_internal_memory(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_subtraction_operator_matrix_subtraction_by_scalar_internal_memory\n\n";
		fprintf(fpTest, "START ---> test_subtraction_operator_matrix_subtraction_by_scalar_internal_memory\n\n");

		fprintf(fpTest, "Function Name ---> operator-(Subtraction by Scalar with result in internal memory) \n\n");
				
		fprintf(fpTest, "Test Case ---> Subtract all elements of the float matrix by a scalar --> result = A - Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
				
		/* Subtract float Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			float32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			float32 result[16] = {
				0,     1,     2,     3,
				4,     5,     6,     7,
				8,     9,     10,    11,
				12,    13,    14,    15
			};
			
			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const float32 scale_value = 1.0;

			cml::boolean_t returnValue; 

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A-scale_value = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_subtraction_operator_matrix_subtraction_by_scalar_internal_memory -> Subtract float Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			testMatrix1 = testMatrix1 - scale_value; /* Overloaded Multiplication operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A-scale_value = \n");
			check__vMatrixPrint<float32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Subtract all elements of the int matrix by a scalar --> result = A - Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Subtract int Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint32 result[16] = {
				0,     1,     2,     3,
				4,     5,     6,     7,
				8,     9,     10,    11,
				12,    13,    14,    15
			};
			
			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint32 scale_value = 1;

			cml::boolean_t returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A-scale_value = \n");
			check_int_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_subtraction_operator_matrix_subtraction_by_scalar_internal_memory -> Subtract int Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			testMatrix1 = testMatrix1 - scale_value; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A-scale_value = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Subtract all elements of the short matrix by a scalar --> result = A - Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Subtract short Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint16 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint16 result[16] = {
				0,     1,     2,     3,
				4,     5,     6,     7,
				8,     9,     10,    11,
				12,    13,    14,    15
			};
			
			typedef cml::CMatrix <sint16, 4, 4, true> self;

			cml::CMatrix<sint16, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint16 scale_value = 1;

			cml::boolean_t returnValue; 

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A-scale_value = \n");
			check_short_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_subtraction_operator_matrix_subtraction_by_scalar_internal_memory -> Subtract short Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			testMatrix1 = testMatrix1 - scale_value; /* Overloaded Multiplication operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A-scale_value = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Subtract all elements of the char matrix by a scalar --> result = A - Scalefactor\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Subtract char Matrix by scalar :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint8 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint8 result[16] = {				
				0,     1,     2,     3,
				4,     5,     6,     7,
				8,     9,     10,    11,
				12,    13,    14,    15
			};
			
			typedef cml::CMatrix <sint8, 4, 4, true> self;

			cml::CMatrix<sint8, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint8 scale_value = 1;

			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "scale_value = %f\n", scale_value);
			
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A-scale_value = \n");
			check_char_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_subtraction_operator_matrix_subtraction_by_scalar_internal_memory -> Subtract char Matrix by scalar :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			testMatrix1 = testMatrix1 - scale_value; /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A-scale_value = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		std::cout << "END ---> test_subtraction_operator_matrix_subtraction_by_scalar_internal_memory\n\n";
		fprintf(fpTest, "END ---> test_subtraction_operator_matrix_subtraction_by_scalar_internal_memory\n\n");
	}
}

//void setIdentity()
void TEST_CLASS::test_setIdentity(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_setIdentity\n\n";
		fprintf(fpTest, "START ---> test_setIdentity\n\n");

		std::cout << "Compiler error! Since fill() is passed with float value and setting idenitity values by float\n";
		
		/* Remarks */
		fprintf(fpTest, "Remarks ---> Compiler error! Since fill() is passed with float value and setting idenitity values by float\n\n");

#if 0
				
		/* Float Matrix :  4X4 Matrix */
		{
			/* Test case input data declarations */
			float32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			float32 result[16] = {
				1,     0,     0,     0,
				0,     1,     0,     0,
				0,     0,     1,     0,
				0,     0,     0,     1
			};
			
			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const float32 scale_value = 1.0;

			cml::boolean_t returnValue; 	

			std::cout << "test_setIdentity -> Float Matrix :  4X4 Matrix\n";
			fprintf(fpTest, "test_setIdentity -> Float Matrix :  4X4 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			

			/* Call Function Under Test */			
			testMatrix1.setIdentity();	 

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}
		}

		/* int Matrix :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint32 result[16] = {
				1,     0,     0,     0,
				0,     1,     0,     0,
				0,     0,     1,     0,
				0,     0,     0,     1
			};
			
			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint32 scale_value = 1;

			cml::boolean_t returnValue; 	

			std::cout << "test_setIdentity -> int Matrix :  4X4 Matrix\n";
			fprintf(fpTest, "test_setIdentity -> int Matrix :  4X4 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			

			/* Call Function Under Test */			
			testMatrix1.setIdentity();	 		 

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}
		}

		/* short Matrix :  4X4 Matrix :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint16 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint16 result[16] = {
				1,     0,     0,     0,
				0,     1,     0,     0,
				0,     0,     1,     0,
				0,     0,     0,     1
			};
			
			typedef cml::CMatrix <sint16, 4, 4, true> self;

			cml::CMatrix<sint16, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint16 scale_value = 1;

			cml::boolean_t returnValue; 	

			std::cout << "test_setIdentity -> short Matrix :  4X4 Matrix\n";
			fprintf(fpTest, "test_setIdentity -> short Matrix :  4X4 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			

			/* Call Function Under Test */			
			testMatrix1.setIdentity();	 		 

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}
		}

		/* char Matrix :  4X4 Matrix :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint8 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint8 result[16] = {				
				1,     0,     0,     0,
				0,     1,     0,     0,
				0,     0,     1,     0,
				0,     0,     0,     1
			};
			
			typedef cml::CMatrix <sint8, 4, 4, true> self;

			cml::CMatrix<sint8, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			const sint8 scale_value = 1;

			cml::boolean_t returnValue; 	

			std::cout << "test_setIdentity -> char Matrix :  4X4 Matrix\n";
			fprintf(fpTest, "test_setIdentity -> char Matrix :  4X4 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			

			/* Call Function Under Test */			
			testMatrix1.setIdentity();	 		 

#ifndef NDEBUG			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}
		}
#endif

		std::cout << "END ---> test_setIdentity\n\n";
		fprintf(fpTest, "END ---> test_setIdentity\n\n");
	}
}

//CMatrix<type, COLS, ROWS, false> transpose() const
void TEST_CLASS::test_transpose(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_transpose\n\n";
		fprintf(fpTest, "START ---> test_transpose\n\n");

		fprintf(fpTest, "Function Name ---> transpose \n\n");
				
		fprintf(fpTest, "Test Case ---> Transpose of a Matrix of type float --> result = Transpose(A)\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
								
		/* Float Matrix :  4X4 Matrix */
		{
			/* Test case input data declarations */
			float32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			float32 result[16] = {
				1,     5,     9,     13,
				2,     6,     10,    14,
				3,     7,     11,    15,
				4,     8,     12,    16
			};
			
			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			cml::CMatrix<float32, 4, 4, false> return_matrix;

			cml::boolean_t returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	
						
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "Transpose(A) = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_transpose -> Float Matrix :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			return_matrix = testMatrix1.transpose();

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "Transpose(A) = \n");
			check__vMatrixPrint<float32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			

			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Transpose of a Matrix of type int --> result = Transpose(A)\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* int Matrix :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint32 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint32 result[16] = {
				1,     5,     9,     13,
				2,     6,     10,    14,
				3,     7,     11,    15,
				4,     8,     12,    16
			};
			
			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);
			
			cml::CMatrix<sint32, 4, 4, false> return_matrix; return_matrix;
			
			cml::boolean_t returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	
						
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "Transpose(A) = \n");
			check_int_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_transpose -> int Matrix :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			return_matrix = testMatrix1.transpose();	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "Transpose(A) = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			

			testMatrix1 = return_matrix;
		
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Transpose of a Matrix of type short --> result = Transpose(A)\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* short Matrix :  4X4 Matrix :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint16 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint16 result[16] = {
				1,     5,     9,     13,
				2,     6,     10,    14,
				3,     7,     11,    15,
				4,     8,     12,    16
			};
			
			typedef cml::CMatrix <sint16, 4, 4, true> self;

			cml::CMatrix<sint16, 4, 4, true> testMatrix1(A);

			self result_matrix(result);
			
			cml::CMatrix<sint16, 4, 4, false> return_matrix; return_matrix;
			
			cml::boolean_t returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, A, fpTest);	
						
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "Transpose(A) = \n");
			check_short_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_transpose -> short Matrix :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			return_matrix = testMatrix1.transpose();

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "Transpose(A) = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			

			testMatrix1 = return_matrix;
		
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Transpose of a Matrix of type char --> result = Transpose(A)\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* char Matrix :  4X4 Matrix :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint8 A[16] = {
				1,		2,		3,		4,
				5,		6,		7,		8,
				9,		10,		11,		12,
				13,		14,		15,		16
			};

			sint8 result[16] = {				
				1,     5,     9,     13,
				2,     6,     10,    14,
				3,     7,     11,    15,
				4,     8,     12,    16
			};
			
			typedef cml::CMatrix <sint8, 4, 4, true> self;

			cml::CMatrix<sint8, 4, 4, true> testMatrix1(A);

			self result_matrix(result);
			
			cml::CMatrix<sint8, 4, 4, false> return_matrix; return_matrix;
			
			cml::boolean_t returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, A, fpTest);	
						
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "Transpose(A) = \n");
			check_char_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_transpose -> char Matrix :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			return_matrix = testMatrix1.transpose();	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "Transpose(A) = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG			

			testMatrix1 = return_matrix;
			
			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		std::cout << "END ---> test_transpose\n\n";
		fprintf(fpTest, "END ---> test_transpose\n\n");
	}
}

//template<typename TYPE2, sint32 COLS2, boolean_t EXT_MEM2>
//CMatrix<type, ROWS, COLS2, false> mulSym ( const CMatrix<TYPE2, COLS, COLS2, EXT_MEM2>& rhs ) const
void TEST_CLASS::test_mulSym(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_mulSym\n\n";
		fprintf(fpTest, "START ---> test_mulSym\n\n");

		fprintf(fpTest, "Function Name ---> mulSym \n\n");
				
		fprintf(fpTest, "Test Case ---> Multiplication of two matrices type float if the result is known to be a symmetric   --> result  = A * B\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
				
		/* Multiply float Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			float32 A[16] = {
				1,		1,		1,		1,
				2,		2,		2,		2,
				3,		3,		3,		3,
				4,		4,		4,		4
			};

			float32 B[16] = {				
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
			};

			float32 result[16] = {
				4,      8,    12,    16,
				8,     16,    24,    32,
				12,    24,    36,    48,
				16,    32,    48,    64
			};

			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			cml::CMatrix<float32, 4, 4, false> return_matrix; return_matrix;
				
			cml::boolean_t returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_float_ArrayPrint(4, 4, B, fpTest);	
						
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*B = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_mulSym -> Multiply float Matrices with symmetric result:  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			return_matrix = testMatrix1.mulSym(testMatrix2); 	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*B = \n");
			check__vMatrixPrint<float32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiplication of two matrices type int if the result is known to be a symmetric   --> result  = A * B\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
		
		/* Multiply int Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint32 A[16] = {
				1,		1,		1,		1,
				2,		2,		2,		2,
				3,		3,		3,		3,
				4,		4,		4,		4
			};

			sint32 B[16] = {				
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
			};

			sint32 result[16] = {
				4,      8,    12,    16,
				8,     16,    24,    32,
				12,    24,    36,    48,
				16,    32,    48,    64
			};

			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			cml::CMatrix<sint32, 4, 4, false> return_matrix;
				
			cml::boolean_t returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_int_ArrayPrint(4, 4, B, fpTest);	
						
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*B = \n");
			check_int_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_mulSym -> Multiply int Matrices with symmetric result :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			return_matrix = testMatrix1.mulSym(testMatrix2);  /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*B = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiplication of two matrices type short if the result is known to be a symmetric   --> result  = A * B\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Multiply short Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint16 A[16] = {
				1,		1,		1,		1,
				2,		2,		2,		2,
				3,		3,		3,		3,
				4,		4,		4,		4
			};

			sint16 B[16] = {				
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
			};

			sint16 result[16] = {
				4,      8,    12,    16,
				8,     16,    24,    32,
				12,    24,    36,    48,
				16,    32,    48,    64
			};

			typedef cml::CMatrix <sint16, 4, 4, true> self;

			cml::CMatrix<sint16, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			cml::CMatrix<sint16, 4, 4, false> return_matrix;;
				
			cml::boolean_t returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_short_ArrayPrint(4, 4, B, fpTest);	
						
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*B = \n");
			check_short_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_mulSym -> Multiply short Matrices with symmetric result :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			return_matrix = testMatrix1.mulSym(testMatrix2); /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*B = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiplication of two matrices type char if the result is known to be a symmetric   --> result  = A * B\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Multiply char Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint8 A[16] = {
				1,		1,		1,		1,
				2,		2,		2,		2,
				3,		3,		3,		3,
				4,		4,		4,		4
			};

			sint8 B[16] = {				
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
			};

			sint8 result[16] = {
				4,      8,    12,    16,
				8,     16,    24,    32,
				12,    24,    36,    48,
				16,    32,    48,    64
			};

			typedef cml::CMatrix <sint8, 4, 4, true> self;

			cml::CMatrix<sint8, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			cml::CMatrix<sint8, 4, 4, false> return_matrix; 
				
			cml::boolean_t returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_char_ArrayPrint(4, 4, B, fpTest);	
						
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*B = \n");
			check_char_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_mulSym -> Multiply char Matrices with symmetric result :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			return_matrix = testMatrix1.mulSym(testMatrix2); /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*B = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";  
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}		

		std::cout << "END ---> test_mulSym\n\n";
		fprintf(fpTest, "END ---> test_mulSym\n\n");
	}
}

void TEST_CLASS::test_mulTrnsp(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_mulTrnsp\n\n";
		fprintf(fpTest, "START ---> test_mulTrnsp\n\n");

		fprintf(fpTest, "Function Name ---> mulTrnsp \n\n");
				
		fprintf(fpTest, "Test Case ---> Multiplication of two matrices type float with B transpose   --> result  = A * B'\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
				
		/* Multiply float Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			float32 A[16] = {
				1,		1,		1,		1,
				2,		2,		2,		2,
				3,		3,		3,		3,
				4,		4,		4,		4
			};

			float32 B[16] = {				
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
			};

			float32 result[16] = {
			    10,    10,    10,    10,
				20,    20,    20,    20,
				30,    30,    30,    30,
				40,    40,    40,    40
			};

			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			cml::CMatrix<float32, 4, 4, false> return_matrix;
				
			cml::boolean_t returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_float_ArrayPrint(4, 4, B, fpTest);	
						
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*B' = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_mulTrnsp -> Multiply float Matrices with B Transpose:  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			return_matrix = testMatrix1.mulTrnsp(testMatrix2); 

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*B' = \n");
			check__vMatrixPrint<float32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiplication of two matrices type int with B transpose   --> result  = A * B'\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
		
		/* Multiply int Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint32 A[16] = {
				1,		1,		1,		1,
				2,		2,		2,		2,
				3,		3,		3,		3,
				4,		4,		4,		4
			};

			sint32 B[16] = {				
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
			};

			sint32 result[16] = {
				10,    10,    10,    10,
				20,    20,    20,    20,
				30,    30,    30,    30,
				40,    40,    40,    40
			};

			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			cml::CMatrix<sint32, 4, 4, false> return_matrix;
				
			cml::boolean_t returnValue; 

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_int_ArrayPrint(4, 4, B, fpTest);	
						
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*B' = \n");
			check_int_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_mulTrnsp -> Multiply int Matrices with B Transpose :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			return_matrix = testMatrix1.mulTrnsp(testMatrix2);  /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*B' = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiplication of two matrices type short with B transpose   --> result  = A * B'\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Multiply short Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint16 A[16] = {
				1,		1,		1,		1,
				2,		2,		2,		2,
				3,		3,		3,		3,
				4,		4,		4,		4
			};

			sint16 B[16] = {				
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
			};

			sint16 result[16] = {
				10,    10,    10,    10,
				20,    20,    20,    20,
				30,    30,    30,    30,
				40,    40,    40,    40
			};

			typedef cml::CMatrix <sint16, 4, 4, true> self;

			cml::CMatrix<sint16, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			cml::CMatrix<sint16, 4, 4, false> return_matrix;
				
			cml::boolean_t returnValue; 

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_short_ArrayPrint(4, 4, B, fpTest);	
						
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*B' = \n");
			check_short_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_mulTrnsp -> Multiply short Matrices with B Transpose :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			return_matrix = testMatrix1.mulTrnsp(testMatrix2); /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*B' = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiplication of two matrices type char with B transpose   --> result  = A * B'\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Multiply char Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint8 A[16] = {
				1,		1,		1,		1,
				2,		2,		2,		2,
				3,		3,		3,		3,
				4,		4,		4,		4
			};

			sint8 B[16] = {				
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
			};

			sint8 result[16] = {
				10,    10,    10,    10,
				20,    20,    20,    20,
				30,    30,    30,    30,
				40,    40,    40,    40
			};

			typedef cml::CMatrix <sint8, 4, 4, true> self;

			cml::CMatrix<sint8, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			cml::CMatrix<sint8, 4, 4, false> return_matrix;
				
			cml::boolean_t returnValue; 

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_char_ArrayPrint(4, 4, B, fpTest);	
						
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A*B' = \n");
			check_char_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_mulTrnsp -> Multiply char Matrices with B Transpose :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			return_matrix = testMatrix1.mulTrnsp(testMatrix2); /* Overloaded Multiplication operator */			

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A*B' = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";  
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}		

		std::cout << "END ---> test_mulTrnsp\n\n";
		fprintf(fpTest, "END ---> test_mulTrnsp\n\n");
	}
}

void TEST_CLASS::test_trnspMul(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_trnspMul\n\n";
		fprintf(fpTest, "START ---> test_trnspMul\n\n");

		fprintf(fpTest, "Function Name ---> trnspMul \n\n");
				
		fprintf(fpTest, "Test Case ---> Multiplication of two matrices type float with A transpose   --> result  = A' * B\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
				
		/* Multiply float Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			float32 A[16] = {
				1,		1,		1,		1,
				2,		2,		2,		2,
				3,		3,		3,		3,
				4,		4,		4,		4
			};

			float32 B[16] = {				
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
			};

			float32 result[16] = {
			    10,    20,    30,    40,
				10,    20,    30,    40,
				10,    20,    30,    40,
				10,    20,    30,    40
			};

			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			cml::CMatrix<float32, 4, 4, false> return_matrix;
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_float_ArrayPrint(4, 4, B, fpTest);	
						
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A'*B = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_trnspMul -> Multiply float Matrices with A Transpose:  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1.trnspMul(testMatrix2); 	 

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A'*B = \n");
			check__vMatrixPrint<float32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiplication of two matrices type int with A transpose   --> result  = A' * B\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
		
		/* Multiply int Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint32 A[16] = {
				1,		1,		1,		1,
				2,		2,		2,		2,
				3,		3,		3,		3,
				4,		4,		4,		4
			};

			sint32 B[16] = {				
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
			};

			sint32 result[16] = {
				10,    20,    30,    40,
				10,    20,    30,    40,
				10,    20,    30,    40,
				10,    20,    30,    40
			};

			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			cml::CMatrix<sint32, 4, 4, false> return_matrix;
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_int_ArrayPrint(4, 4, B, fpTest);	
						
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A'*B = \n");
			check_int_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_trnspMul -> Multiply int Matrices with A Transpose :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1.trnspMul(testMatrix2);  /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A'*B = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiplication of two matrices type short with A transpose   --> result  = A' * B\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Multiply short Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint16 A[16] = {
				1,		1,		1,		1,
				2,		2,		2,		2,
				3,		3,		3,		3,
				4,		4,		4,		4
			};

			sint16 B[16] = {				
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
			};

			sint16 result[16] = {
				10,    20,    30,    40,
				10,    20,    30,    40,
				10,    20,    30,    40,
				10,    20,    30,    40
			};

			typedef cml::CMatrix <sint16, 4, 4, true> self;

			cml::CMatrix<sint16, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			cml::CMatrix<sint16, 4, 4, false> return_matrix;
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_short_ArrayPrint(4, 4, B, fpTest);	
						
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A'*B = \n");
			check_short_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_trnspMul -> Multiply short Matrices with A Transpose :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1.trnspMul(testMatrix2); /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A'*B = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Multiplication of two matrices type char with A transpose   --> result  = A' * B\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Multiply char Matrices :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint8 A[16] = {
				1,		1,		1,		1,
				2,		2,		2,		2,
				3,		3,		3,		3,
				4,		4,		4,		4
			};

			sint8 B[16] = {				
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
				1,		2,		3,		4,
			};

			sint8 result[16] = {
				10,    20,    30,    40,
				10,    20,    30,    40,
				10,    20,    30,    40,
				10,    20,    30,    40
			};

			typedef cml::CMatrix <sint8, 4, 4, true> self;

			cml::CMatrix<sint8, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			self testMatrix2(B);

			cml::CMatrix<sint8, 4, 4, false> return_matrix;
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, A, fpTest);	

			fprintf(fpTest, "B = \n");
			check_char_ArrayPrint(4, 4, B, fpTest);	
						
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "A'*B = \n");
			check_char_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_trnspMul -> Multiply char Matrices with A Transpose :  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1.trnspMul(testMatrix2); /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "A'*B = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(testMatrix1, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";  
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}		

		std::cout << "END ---> test_trnspMul\n\n";
		fprintf(fpTest, "END ---> test_trnspMul\n\n");
	}
}

void TEST_CLASS::test_invert(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_invert\n\n";
		fprintf(fpTest, "START ---> test_invert\n\n");

		fprintf(fpTest, "Function Name ---> invert \n\n");
				
		fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Invert float Matrix :  4X4 Matrix */
		{
			/* Test case input data declarations */
			float32 A[16] = {
				1, 0, 1, 1,
				2, 0, 1, 0,
				2, 1, 1, 0,
				0, 0, 1, 3 
			};			

			float32 result[16] = {
			    -3,     2,     0,     1,
				 0,    -1,     1,     0,
				 6,    -3,     0,    -2,
				-2,     1,     0,     1
			};

			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			cml::CMatrix<float32, 4, 4, false> return_matrix;
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "inv(A) = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_invert -> Invert float matrix:  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1.invert(); 	 

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "inv(A) = \n");
			check__vMatrixPrint<float32, 4, 4, false>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type int --> result  = inv(A)\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Invert int Matrix :  4X4 Matrix */
		{
			/* Test case input data declarations */
			sint32 A[16] = {
				1, 0, 1, 1,
				2, 0, 1, 0,
				2, 1, 1, 0,
				0, 0, 1, 3 
			};			

			sint32 result[16] = {
			    -3,     2,     0,     1,
				 0,    -1,     1,     0,
				 6,    -3,     0,    -2,
				-2,     1,     0,     1
			};

			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			cml::CMatrix<sint32, 4, 4, false> return_matrix;
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "inv(A) = \n");
			check_int_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_invert -> Invert int matrix:  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1.invert(); 	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "inv(A) = \n");
			check__vMatrixPrint<sint32, 4, 4, false>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> Inverse of non-float matrix may give wrong result due to fractional division\n\n");
		}

		fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 3X3\n\n");
				
		/* Invert float Matrix :  3X3 Matrix */
		{
			/* Test case input data declarations */
			float32 A[9] = {
				3.f,   2.f,   6.f,
                1.f,   1.f,   3.f,
               -3.f,  -2.f,  -5.f
			};			

			float32 result[9] = {
			    1.0000,   -2.0000,   -0.0000,
			   -4.0000,    3.0000,   -3.0000,
                1.0000,         0,    1.0000
			};

			typedef cml::CMatrix <float32, 3, 3, true> self;

			cml::CMatrix<float32, 3, 3, true> testMatrix1(A);

			self result_matrix(result);

			cml::CMatrix<float32, 3, 3, false> return_matrix;
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(3, 3, A, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "inv(A) = \n");
			check_float_ArrayPrint(3, 3, result, fpTest);

			std::cout << "test_invert -> Invert float matrix:  3X3 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1.invert(); 	 

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "inv(A) = \n");
			check__vMatrixPrint<float32, 3, 3, false>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type float(Hilbert_3-Matrix) --> result  = inv(A)\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 3X3\n\n");
		
		/* Invert Hilbert_3-Matrix :  3X3 Matrix */
		{
			/* Test case input data declarations */
			float32 A[9] = {
				1.f,    1.f/2,   1.f/3,
                1.f/2,  1.f/3,   1.f/4,
                1.f/3,  1.f/4,   1.f/5
			};

			float32 result[9] = {
				8.9999877600215f,   -35.9999359201113f,    29.9999400001038f,
			  -35.9999359201113f,   191.9996678405774f,  -179.9996904005383f,
			   29.9999400001038f,  -179.9996904005383f,   179.9997120005019f
			};

			typedef cml::CMatrix <float32, 3, 3, true> self;

			cml::CMatrix<float32, 3, 3, true> testMatrix1(A);

			self result_matrix(result);

			cml::CMatrix<float32, 3, 3, false> return_matrix;
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(3, 3, A, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "inv(A) = \n");
			check_float_ArrayPrint(3, 3, result, fpTest);

			std::cout << "test_invert -> Invert Hilbert_3-Matrix :  3X3 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1.invert();  /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "inv(A) = \n");
			check__vMatrixPrint<float32, 3, 3, false>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> Precision differences\n\n");
		}

		fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type float(Hilbert_5-Matrix) --> result  = inv(A)\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 5X5\n\n");

		/* Invert Hilbert_5-Matrix :  5X5 Matrix */
		{
			/* Test case input data declarations */
			float32 A[25] = {
				1.,    1./2,  1./3,  1./4,  1./5,
                1./2,  1./3,  1./4,  1./5,  1./6,  
                1./3,  1./4,  1./5,  1./6,  1./7,  
                1./4,  1./5,  1./6,  1./7,  1./8,  
                1./5,  1./6,  1./7,  1./8,  1./9  
			};			

			float32 result[25] = {
				25,     -300,    1050,   -1400,    630,
                -300,   4800,  -18900,   26880, -12600,
                1050, -18900,   79380, -117600,  56700,
               -1400,  26880, -117600,  179200, -88200,
                630,  -12600,   56700,  -88200,  44100
			};

			typedef cml::CMatrix <float32, 5, 5, true> self;

			cml::CMatrix<float32, 5, 5, true> testMatrix1(A);

			self result_matrix(result);

			cml::CMatrix<float32, 5, 5, false> return_matrix;
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(5, 5, A, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "inv(A) = \n");
			check_float_ArrayPrint(5, 5, result, fpTest);

			std::cout << "test_invert -> Invert Hilbert_5-Matrix :  5X5 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1.invert(); /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "inv(A) = \n");
			check__vMatrixPrint<float32, 5, 5, false>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> Precision differences\n\n");
		}

		fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type int --> result  = inv(A)\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 3X3\n\n");

		/* Invert int Matrix :  3X3 Matrix  */
		{
			/* Test case input data declarations */
			sint32 A[9] = {
				3,   2,   6,
                1,   1,   3,
               -3,  -2,  -5
			};

			sint32 result[9] = {
			    1,   -2,   -0,
			   -4,    3,   -3,
                1,    0,    1
			};
						
			typedef cml::CMatrix <sint32, 3, 3, true> self;

			cml::CMatrix<sint32, 3, 3, true> testMatrix1(A);

			self result_matrix(result);

			cml::CMatrix<sint32, 3, 3, false> return_matrix;
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(3, 3, A, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "inv(A) = \n");
			check_int_ArrayPrint(3, 3, result, fpTest);

			std::cout << "test_invert -> Invert int matrix :  3X3 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1.invert(); /* Overloaded Multiplication operator */		

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "inv(A) = \n");
			check__vMatrixPrint<sint32, 3, 3, false>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";  
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> Inverse of non-float matrix may give wrong result due to fractional division\n\n");
		}	

		fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type short --> result  = inv(A)\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 3X3\n\n");

		/* Invert short Matrix :  3X3 Matrix  */
		{
			/* Test case input data declarations */
			sint16 A[9] = {
				3,   2,   6,
                1,   1,   3,
               -3,  -2,  -5
			};

			sint16 result[9] = {
			    1,   -2,   -0,
			   -4,    3,   -3,
                1,    0,    1
			};
						
			typedef cml::CMatrix <sint16, 3, 3, true> self;

			cml::CMatrix<sint16, 3, 3, true> testMatrix1(A);

			self result_matrix(result);

			cml::CMatrix<sint16, 3, 3, false> return_matrix;
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(3, 3, A, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "inv(A) = \n");
			check_short_ArrayPrint(3, 3, result, fpTest);

			std::cout << "test_invert -> Invert short matrix :  3X3 Matrix\n";
			fprintf(fpTest, "test_invert -> Invert short matrix :  3X3 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1.invert(); /* Overloaded Multiplication operator */	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "inv(A) = \n");
			check__vMatrixPrint<sint16, 3, 3, false>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";  
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> Inverse of non-float matrix may give wrong result due to fractional division\n\n");
		}

		fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type char --> result  = inv(A)\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 3X3\n\n");

		/* Invert char Matrix :  3X3 Matrix  */
		{
			/* Test case input data declarations */
			sint8 A[9] = {
				3,   2,   6,
                1,   1,   3,
               -3,  -2,  -5
			};

			sint8 result[9] = {
			    1,   -2,   -0,
			   -4,    3,   -3,
                1,    0,    1
			};
						
			typedef cml::CMatrix <sint8, 3, 3, true> self;

			cml::CMatrix<sint8, 3, 3, true> testMatrix1(A);

			self result_matrix(result);

			cml::CMatrix<sint8, 3, 3, false> return_matrix;
				
			cml::boolean_t returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(3, 3, A, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "inv(A) = \n");
			check_char_ArrayPrint(3, 3, result, fpTest);
			
			std::cout << "test_invert -> Invert char matrix :  3X3 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();
			
			/* Call Function Under Test */			
			returnValue = testMatrix1.invert(return_matrix); /* Overloaded Multiplication operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "inv(A) = \n");
			check__vMatrixPrint<sint8, 3, 3, false>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";  
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> Inverse of non-float matrix may give wrong result due to fractional division\n\n");
		}

		fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 2X2\n\n");
		
		/* Invert float Matrix :  2X2 Matrix  */
		{
			/* Test case input data declarations */
			float32 A[4] = {
				1,	0,
				1,	1
			};

			float32 result[4] = {
			    1,	0,
				-1,	1
			};
						
			typedef cml::CMatrix <float32, 2, 2, true> self;

			cml::CMatrix<float32, 2, 2, true> testMatrix1(A);

			self result_matrix(result);

			cml::CMatrix<float32, 2, 2, false> return_matrix;
				
			cml::boolean_t returnValue; 

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(2, 2, A, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "inv(A) = \n");
			check_float_ArrayPrint(2, 2, result, fpTest);

			std::cout << "test_invert -> Invert char matrix :  2X2 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();
			
			/* Call Function Under Test */			
			returnValue = testMatrix1.invert(return_matrix); /* Overloaded Multiplication operator */		

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "inv(A) = \n");
			check__vMatrixPrint<float32, 2, 2, false>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";  
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 1X1\n\n");

		/* Invert float Matrix :  1X1 Matrix  */
		{
			/* Test case input data declarations */
			float32 A[1] = {
				2
			};

			float32 result[1] = {
			    0.5
			};
						
			typedef cml::CMatrix <float32, 1, 1, true> self;

			cml::CMatrix<float32, 1, 1, true> testMatrix1(A);

			self result_matrix(result);

			cml::CMatrix<float32, 1, 1, false> return_matrix;
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(1, 1, A, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "inv(A) = \n");
			check_float_ArrayPrint(1, 1, result, fpTest);

			std::cout << "test_invert -> Invert char matrix :  1X1 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			returnValue = testMatrix1.invert(return_matrix); /* Overloaded Multiplication operator */

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "inv(A) = \n");
			check__vMatrixPrint<float32, 1, 1, false>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";  
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		std::cout << "END ---> test_invert\n\n";
		fprintf(fpTest, "END ---> test_invert\n\n");
	}
}

//CMatrix<type, COLS, ROWS, false> getCholesky() const
void TEST_CLASS::test_getCholesky(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_getCholesky\n\n";
		fprintf(fpTest, "START ---> test_getCholesky\n\n");

		fprintf(fpTest, "Function Name ---> getCholesky \n\n");
				
		fprintf(fpTest, "Test Case ---> Cholesky factor of float Matrix --> result = cholesky(A)\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
				
		/* Cholesky factor of float Matrix :  4X4 Matrix */
		{
			/* Test case input data declarations */
			float32 A[16] = {
				1.f,   4.f,   5.f,   6.f, 
                4.f,  32.f,  40.f,  48.f,
                5.f,  40.f,  75.f,  90.f,
                6.f,  48.f,  90.f, 144.f
			};			

			float32 result[16] = {
			    1.f,  0.f,  0.f,  0.f,
                4.f,  4.f,  0.f,  0.f,
                5.f,  5.f,  5.f,  0.f,
                6.f,  6.f,  6.f,  6.f
			};

			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			cml::CMatrix<float32, 4, 4, false> return_matrix;
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "cholesky(A) = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_getCholesky -> Cholesky factor of float Matrix:  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1.getCholesky(); 	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "cholesky(A) = \n");
			check__vMatrixPrint<float32, 4, 4, false>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Cholesky factor of float Matrix --> result = cholesky(A)\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
		
		/* Cholesky factor of float Matrix :  4X4 Matrix */
		{
			/* Test case input data declarations */
			float32 A[16] = {
				1.f,   2.f,   3.f,   4.f, 
                2.f,  29.f,  36.f,  43.f,
                3.f,  36.f, 109.f, 126.f,
                4.f,  43.f, 126.f, 246.f
			};			

			float32 result[16] = {
			    1.f,  0.f,  0.f,  0.f,
                2.f,  5.f,  0.f,  0.f,
                3.f,  6.f,  8.f,  0.f,
                4.f,  7.f,  9.f, 10.f
			};

			typedef cml::CMatrix <float32, 4, 4, true> self;

			cml::CMatrix<float32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			cml::CMatrix<float32, 4, 4, false> return_matrix;
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, A, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "cholesky(A) = \n");
			check_float_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_getCholesky -> Cholesky factor of float Matrix:  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1.getCholesky(); 	 

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "cholesky(A) = \n");
			check__vMatrixPrint<float32, 4, 4, false>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}	

		fprintf(fpTest, "Test Case ---> Cholesky factor of int Matrix --> result = cholesky(A)\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Cholesky factor of int Matrix :  3X3 Matrix */
		{
			/* Test case input data declarations */
			sint32 A[16] = {
				1,   2,   3,   4, 
                2,  29,  36,  43,
                3,  36, 109, 126,
                4,  43, 126, 246
			};			

			sint32 result[16] = {
			    1,  0,  0,  0,
                2,  5,  0,  0,
                3,  6,  8,  0,
                4,  7,  9, 10
			};

			typedef cml::CMatrix <sint32, 4, 4, true> self;

			cml::CMatrix<sint32, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			cml::CMatrix<sint32, 4, 4, false> return_matrix;
				
			cml::boolean_t returnValue; 

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, A, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "cholesky(A) = \n");
			check_int_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_getCholesky -> Cholesky factor of int Matrix:  4X4 Matrix\n";
		
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();			

			/* Call Function Under Test */			
			return_matrix = testMatrix1.getCholesky(); 	

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "cholesky(A) = \n");
			check__vMatrixPrint<sint32, 4, 4, false>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Cholesky factor of short Matrix --> result = cholesky(A)\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Cholesky factor of short Matrix :  3X3 Matrix */
		{
			/* Test case input data declarations */
			sint16 A[16] = {
				1,   2,   3,   4, 
                2,  29,  36,  43,
                3,  36, 109, 126,
                4,  43, 126, 246
			};			

			sint16 result[16] = {
			    1,  0,  0,  0,
                2,  5,  0,  0,
                3,  6,  8,  0,
                4,  7,  9, 10
			};

			typedef cml::CMatrix <sint16, 4, 4, true> self;

			cml::CMatrix<sint16, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			cml::CMatrix<sint16, 4, 4, false> return_matrix;
				
			cml::boolean_t returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, A, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "cholesky(A) = \n");
			check_short_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_getCholesky -> Cholesky factor of short Matrix:  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();
						
			/* Call Function Under Test */			
			return_matrix = testMatrix1.getCholesky(); 	 

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "cholesky(A) = \n");
			check__vMatrixPrint<sint16, 4, 4, false>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Cholesky factor of char Matrix --> result = cholesky(A)\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* Cholesky factor of char Matrix :  3X3 Matrix */
		{
			/* Test case input data declarations */
			sint8 A[16] = {
				1,   2,   3,   4, 
                2,  29,  36,  43,
                3,  36, 109, 126,
                4,  43, 126, 246
			};			

			sint8 result[16] = {
			    1,  0,  0,  0,
                2,  5,  0,  0,
                3,  6,  8,  0,
                4,  7,  9, 10
			};

			typedef cml::CMatrix <sint8, 4, 4, true> self;

			cml::CMatrix<sint8, 4, 4, true> testMatrix1(A);

			self result_matrix(result);

			cml::CMatrix<sint8, 4, 4, false> return_matrix;
				
			cml::boolean_t returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, A, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "cholesky(A) = \n");
			check_char_ArrayPrint(4, 4, result, fpTest);

			std::cout << "test_getCholesky -> Cholesky factor of char Matrix:  4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */			
			return_matrix = testMatrix1.getCholesky(); 	 

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "cholesky(A) = \n");
			check__vMatrixPrint<sint8, 4, 4, false>(return_matrix, fpTest);

#ifndef NDEBUG
			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);
#endif

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}
	}

	std::cout << "END ---> test_getCholesky\n\n";
	fprintf(fpTest, "END ---> test_getCholesky\n\n");
}

void TEST_CLASS::test_getLowTriaInverse(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_getLowTriaInverse\n\n";
		fprintf(fpTest, "START ---> test_getLowTriaInverse\n\n");

		fprintf(fpTest, "Function Name ---> getLowTriaInverse \n\n");
				
		fprintf(fpTest, "Test Case ---> Low triangular inverse of type float\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 2X2\n\n");

		/* 2X2 float Matrix */
		{			
			/* Test case input data declarations */
			float32 input_matrix[4] = 
			{
				1.0,  0.0, 
				1.0,  1.0
			};

			float32 expected_result_matrix[4] = 
			{
				1.0,  0.0, 
				-1.0,  1.0
			};

			typedef cml::CMatrix <float32, 2, 2, true> self;		

			self testMatrix(input_matrix);
			self expected_result(expected_result_matrix);

			cml::CMatrix <float32, 2, 2, false> result; 

			cml::boolean_t returnValue, expected_returnValue = TRUE;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(2, 2, input_matrix, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "expected_result = \n");
			check_float_ArrayPrint(2, 2, expected_result_matrix, fpTest);
			
			std::cout << "test_getLowTriaInverse of type float -> 2X2 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = testMatrix.getLowTriaInverse();

			/* Copy result to this MAtrix */
			testMatrix = result;

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "actual_result = \n");
			check__vMatrixPrint<float32, 2, 2, true>(testMatrix, fpTest);

#ifndef NDEBUG
			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif
			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n"; 
				fprintf(fpTest, "Status --->  FAIL\n");
			}	

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Low triangular inverse of type float\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 2X2\n\n");

		/* 2X2 float Matrix */
		{
			/* Test case input data declarations */
			float32 input_matrix[4] = 
			{
				1e-20F,  1e-20F, 
				1e-20F,  1e-20F
			};

			float32 expected_result_matrix[4] = 
			{
				1e+20F,  0.0, 
				-1e+20F,  1e+20F
			};

			typedef cml::CMatrix <float32, 2, 2, true> self;		

			self testMatrix(input_matrix);
			self expected_result(expected_result_matrix);
			cml::CMatrix <float32, 2, 2, false> result; 

			cml::boolean_t returnValue, expected_returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(2, 2, input_matrix, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "expected_result = \n");
			check_float_ArrayPrint(2, 2, expected_result_matrix, fpTest);
			
			std::cout << "test_getLowTriaInverse of type float -> 2X2 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = testMatrix.getLowTriaInverse();

			/* Copy result to this MAtrix */
			testMatrix = result;

			expected_returnValue = FALSE;

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "actual_result = \n");
			check__vMatrixPrint<float32, 2, 2, true>(testMatrix, fpTest);

#ifndef NDEBUG
			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif
			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n"; 
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Low triangular inverse of type float\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 3X3\n\n");

		/* 3X3 float Matrix */
		{
			/* Test case input data declarations */
			float32 input_matrix[9] = 
			{
				1.f,   0.f,   0.f,  
				1.f,   1.f,   0.f, 
				1.f,   1.f,   1.f
			};

			float32 expected_result_matrix[9] = 
			{
				1.f,   0.f,   0.f,
				-1.f,   1.f,   0.f,
				0.f,  -1.f,   1.f
			};


			typedef cml::CMatrix <float32, 3, 3, true> self;		

			self testMatrix(input_matrix);
			self expected_result(expected_result_matrix);
			cml::CMatrix <float32, 3, 3, false> result; 

			cml::boolean_t returnValue, expected_returnValue = TRUE;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(3, 3, input_matrix, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "expected_result = \n");
			check_float_ArrayPrint(3, 3, expected_result_matrix, fpTest);
			
			std::cout << "test_getLowTriaInverse of type float -> 3X3 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = testMatrix.getLowTriaInverse();

			/* Copy result to this MAtrix */
			testMatrix = result;

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "actual_result = \n");
			check__vMatrixPrint<float32, 3, 3, true>(testMatrix, fpTest);

#ifndef NDEBUG
			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif
			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n"; 
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Low triangular inverse of type float\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 3X3\n\n");

		/* 3X3 float Matrix */
		{
			/* Test case input data declarations */
			float32 input_matrix[9] = 
			{
				1.f,   0.f,   0.f,
				3.f,   0.5f,  0.f,
				1.f,   4.f,   0.5f
			};

			float32 expected_result_matrix[9] = 
			{
				1.f,    0.f,   0.f,
				-6.f,    2.f,   0.f,
				46.f,  -16.f,   2.f
			};


			typedef cml::CMatrix <float32, 3, 3, true> self;		

			self testMatrix(input_matrix);
			self expected_result(expected_result_matrix);
			cml::CMatrix <float32, 3, 3, false> result; 

			cml::boolean_t returnValue, expected_returnValue = TRUE;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(3, 3, input_matrix, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "expected_result = \n");
			check_float_ArrayPrint(3, 3, expected_result_matrix, fpTest);
			
			std::cout << "test_getLowTriaInverse of type float -> 3X3 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = testMatrix.getLowTriaInverse();

			/* Copy result to this MAtrix */
			testMatrix = result;

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "actual_result = \n");
			check__vMatrixPrint<float32, 3, 3, true>(testMatrix, fpTest);

#ifndef NDEBUG
			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif
			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n"; 
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Low triangular inverse of type float\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* 4X4 float Matrix */
		{
			/* Test case input data declarations */
			float32 input_matrix[16] = 
			{
				1.0f,  0.0f, 2.0f, 3.0f,
				1.0f,  1.0f, 4.0f, 5.0f,
				1.0f,  0.0f, 6.0f, 7.0f,
				1.0f,  1.0f, 8.0f, 9.0f
			};

			float32 expected_result_matrix[16] = 
			{
				1.000000000000000f,                 0.0f,                 0.0f,                 0.0f,
				-1.000000000000000f,   1.000000000000000f,                 0.0f,                 0.0f,
				-0.166666666666667f,                 0.0f,   0.166666666666667f,                 0.0f,
				0.148148148148148f,  -0.111111111111111f,  -0.148148148148148f,   0.111111111111111f
			};


			typedef cml::CMatrix <float32, 4, 4, true> self;		

			self testMatrix(input_matrix);
			self expected_result(expected_result_matrix);
			cml::CMatrix <float32, 4, 4, false> result; 

			cml::boolean_t returnValue, expected_returnValue = TRUE;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, input_matrix, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "expected_result = \n");
			check_float_ArrayPrint(4, 4, expected_result_matrix, fpTest);
			
			std::cout << "test_getLowTriaInverse of type float -> 4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = testMatrix.getLowTriaInverse();

			/* Copy result to this MAtrix */
			testMatrix = result;

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "actual_result = \n");
			check__vMatrixPrint<float32, 4, 4, true>(testMatrix, fpTest);

#ifndef NDEBUG
			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif
			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n"; 
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}	

		fprintf(fpTest, "Test Case ---> Low triangular inverse of type int\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 3X3\n\n");

		/* 3X3 int Matrix */
		{
			/* Test case input data declarations */
			sint32 input_matrix[9] = 
			{
				1,   0,   0,  
				1,   1,   0, 
				1,   1,   1
			};

			sint32 expected_result_matrix[9] = 
			{
				1,   0,   0,
			   -1,   1,   0,
				0,  -1,   1
			};


			typedef cml::CMatrix <sint32, 3, 3, true> self;		

			self testMatrix(input_matrix);
			self expected_result(expected_result_matrix);
			cml::CMatrix <sint32, 3, 3, false> result; 

			cml::boolean_t returnValue, expected_returnValue = TRUE;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(3, 3, input_matrix, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "expected_result = \n");
			check_int_ArrayPrint(3, 3, expected_result_matrix, fpTest);
			
			std::cout << "test_getLowTriaInverse of type int -> 3X3 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = testMatrix.getLowTriaInverse();

			/* Copy result to this MAtrix */
			testMatrix = result;

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "actual_result = \n");
			check__vMatrixPrint<sint32, 3, 3, true>(testMatrix, fpTest);

#ifndef NDEBUG
			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif
			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n"; 
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Low triangular inverse of type short\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 3X3\n\n");

		/* 3X3 short Matrix */
		{
			/* Test case input data declarations */
			sint16 input_matrix[9] = 
			{
				1,   0,   0,  
				1,   1,   0, 
				1,   1,   1
			};

			sint16 expected_result_matrix[9] = 
			{
				1,   0,   0,
			   -1,   1,   0,
				0,  -1,   1
			};


			typedef cml::CMatrix <sint16, 3, 3, true> self;		

			self testMatrix(input_matrix);
			self expected_result(expected_result_matrix);
			cml::CMatrix <sint16, 3, 3, false> result; 

			cml::boolean_t returnValue, expected_returnValue = TRUE;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(3, 3, input_matrix, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "expected_result = \n");
			check_short_ArrayPrint(3, 3, expected_result_matrix, fpTest);
			
			std::cout << "test_getLowTriaInverse of type short -> 3X3 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = testMatrix.getLowTriaInverse();

			/* Copy result to this MAtrix */
			testMatrix = result;

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "actual_result = \n");
			check__vMatrixPrint<sint16, 3, 3, true>(testMatrix, fpTest);
			
#ifndef NDEBUG
			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif
			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n"; 
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Low triangular inverse of type char\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 3X3\n\n");

		/* 3X3 char Matrix */
		{
			/* Test case input data declarations */
			sint8 input_matrix[9] = 
			{
				1,   0,   0,  
				1,   1,   0, 
				1,   1,   1
			};

			sint8 expected_result_matrix[9] = 
			{
				1,   0,   0,
			   -1,   1,   0,
				0,  -1,   1
			};


			typedef cml::CMatrix <sint8, 3, 3, true> self;		

			self testMatrix(input_matrix);
			self expected_result(expected_result_matrix);
			cml::CMatrix <sint8, 3, 3, false> result; 

			cml::boolean_t returnValue, expected_returnValue; 		

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(3, 3, input_matrix, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "expected_result = \n");
			check_char_ArrayPrint(3, 3, expected_result_matrix, fpTest);
			
			std::cout << "test_getLowTriaInverse of type char -> 3X3 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = testMatrix.getLowTriaInverse();

			/* Copy result to this MAtrix */
			testMatrix = result;

			expected_returnValue = TRUE;

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "actual_result = \n");
			check__vMatrixPrint<sint8, 3, 3, true>(testMatrix, fpTest);

#ifndef NDEBUG
			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif
			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n"; 
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}
	}

	std::cout << "END ---> test_getLowTriaInverse\n\n";
	fprintf(fpTest, "END ---> test_getLowTriaInverse\n\n");
}

void TEST_CLASS::test_getLowTriaSqr(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_getLowTriaSqr\n\n";
		fprintf(fpTest, "START ---> test_getLowTriaSqr\n\n");

		fprintf(fpTest, "Function Name ---> getLowTriaSqr \n\n");
				
		fprintf(fpTest, "Test Case ---> Low triangular square of type float\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
		
		/* 4X4 float Matrix */
		{
			/* Test case input data declarations */
			float32 input_matrix[16] = 
			{
				1.f,  0.f,  0.f,  0.f,
                4.f,  4.f,  0.f,  0.f,
                5.f,  5.f,  5.f,  0.f,
                6.f,  6.f,  6.f,  6.f
			};

			float32 expected_result_matrix[16] = 
			{
				1.f,   4.f,   5.f,   6.f, 
                4.f,  32.f,  40.f,  48.f,
                5.f,  40.f,  75.f,  90.f,
                6.f,  48.f,  90.f, 144.f
			};


			typedef cml::CMatrix <float32, 4, 4, true> self;		

			self testMatrix(input_matrix);
			self expected_result(expected_result_matrix);
			cml::CMatrix <float32, 4, 4, false> result;

			cml::boolean_t returnValue, expected_returnValue; 

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, input_matrix, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "expected_result = \n");
			check_float_ArrayPrint(4, 4, expected_result_matrix, fpTest);
			
			std::cout << "test_getLowTriaSqr of type float -> 4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = testMatrix.getLowTriaSqr();

			/* Copy result to this MAtrix */
			testMatrix = result;

			expected_returnValue = TRUE;

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "actual_result = \n");
			check__vMatrixPrint<float32, 4, 4, true>(testMatrix, fpTest);

#ifndef NDEBUG
			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif
			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n"; 
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}	

		fprintf(fpTest, "Test Case ---> Low triangular square of type float\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* 4X4 float Matrix */
		{
			/* Test case input data declarations */
			float32 input_matrix[16] = 
			{
				1.f,  0.f,  0.f,  0.f,
                2.f,  5.f,  0.f,  0.f,
                3.f,  6.f,  8.f,  0.f,
                4.f,  7.f,  9.f, 10.f
			};

			float32 expected_result_matrix[16] = 
			{
				1.f,   2.f,   3.f,   4.f, 
                2.f,  29.f,  36.f,  43.f,
                3.f,  36.f, 109.f, 126.f,
                4.f,  43.f, 126.f, 246.f
			};


			typedef cml::CMatrix <float32, 4, 4, true> self;		

			self testMatrix(input_matrix);
			self expected_result(expected_result_matrix);
			cml::CMatrix <float32, 4, 4, false> result;

			cml::boolean_t returnValue, expected_returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, input_matrix, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "expected_result = \n");
			check_float_ArrayPrint(4, 4, expected_result_matrix, fpTest);
			
			std::cout << "test_getLowTriaSqr of type float -> 4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = testMatrix.getLowTriaSqr();

			/* Copy result to this MAtrix */
			testMatrix = result;

			expected_returnValue = TRUE;

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "actual_result = \n");
			check__vMatrixPrint<float32, 4, 4, true>(testMatrix, fpTest);

#ifndef NDEBUG
			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif
			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n"; 
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Low triangular square of type int\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* 4X4 int Matrix */
		{
			/* Test case input data declarations */
			sint32 input_matrix[16] = 
			{
				1,  0,  0,  0,
                2,  5,  0,  0,
                3,  6,  8,  0,
                4,  7,  9, 10
			};

			sint32 expected_result_matrix[16] = 
			{
				1,   2,   3,   4, 
                2,  29,  36,  43,
                3,  36, 109, 126,
                4,  43, 126, 246
			};


			typedef cml::CMatrix <sint32, 4, 4, true> self;		

			self testMatrix(input_matrix);
			self expected_result(expected_result_matrix);
			cml::CMatrix <sint32, 4, 4, false> result;

			cml::boolean_t returnValue, expected_returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, input_matrix, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "expected_result = \n");
			check_int_ArrayPrint(4, 4, expected_result_matrix, fpTest);
			
			std::cout << "test_getLowTriaSqr of type int -> 4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = testMatrix.getLowTriaSqr();

			/* Copy result to this MAtrix */
			testMatrix = result;

			expected_returnValue = TRUE;

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "actual_result = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(testMatrix, fpTest);

#ifndef NDEBUG
			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif
			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n"; 
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Low triangular square of type short\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* 4X4 short Matrix */
		{
			/* Test case input data declarations */
			sint16 input_matrix[16] = 
			{
				1,  0,  0,  0,
                2,  5,  0,  0,
                3,  6,  8,  0,
                4,  7,  9, 10
			};

			sint16 expected_result_matrix[16] = 
			{
				1,   2,   3,   4, 
                2,  29,  36,  43,
                3,  36, 109, 126,
                4,  43, 126, 246
			};


			typedef cml::CMatrix <sint16, 4, 4, true> self;		

			self testMatrix(input_matrix);
			self expected_result(expected_result_matrix);
			cml::CMatrix <sint16, 4, 4, false> result;

			cml::boolean_t returnValue, expected_returnValue; 

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, input_matrix, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "expected_result = \n");
			check_short_ArrayPrint(4, 4, expected_result_matrix, fpTest);
			
			std::cout << "test_getLowTriaSqr of type short -> 4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = testMatrix.getLowTriaSqr();

			/* Copy result to this MAtrix */
			testMatrix = result;

			expected_returnValue = TRUE;

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "actual_result = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(testMatrix, fpTest);

#ifndef NDEBUG
			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif
			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n"; 
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Low triangular square of type char\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* 4X4 char Matrix */
		{
			/* Test case input data declarations */
			sint8 input_matrix[16] = 
			{
				1,  0,  0,  0,
                2,  5,  0,  0,
                3,  6,  8,  0,
                4,  7,  9, 10
			};

			sint8 expected_result_matrix[16] = 
			{
				1,   2,   3,   4, 
                2,  29,  36,  43,
                3,  36, 109, 126,
                4,  43, 126, 246
			};


			typedef cml::CMatrix <sint8, 4, 4, true> self;		

			self testMatrix(input_matrix);
			self expected_result(expected_result_matrix);
			cml::CMatrix <sint8, 4, 4, false> result;

			cml::boolean_t returnValue, expected_returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, input_matrix, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "expected_result = \n");
			check_char_ArrayPrint(4, 4, expected_result_matrix, fpTest);
			
			std::cout << "test_getLowTriaSqr of type char -> 4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = testMatrix.getLowTriaSqr();

			/* Copy result to this MAtrix */
			testMatrix = result;

			expected_returnValue = TRUE;

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "actual_result = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(testMatrix, fpTest);

#ifndef NDEBUG
			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif
			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n"; 
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}
	}

	std::cout << "END ---> test_getLowTriaSqr\n\n";
	fprintf(fpTest, "END ---> test_getLowTriaSqr\n\n");
}

void TEST_CLASS::test_getUppTriaSqr(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_getUppTriaSqr\n\n";
		fprintf(fpTest, "START ---> test_getUppTriaSqr\n\n");

		fprintf(fpTest, "Function Name ---> getUppTriaSqr \n\n");
				
		fprintf(fpTest, "Test Case ---> Upper triangular square of type float\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");
		
		/* 4X4 float Matrix */
		{
			/* Test case input data declarations */
			float32 input_matrix[16] = 
			{
				1.f,  1.f,  1.f,  1.f,
                0.f,  4.f,  4.f,  4.f,
                0.f,  0.f,  5.f,  5.f,
                0.f,  0.f,  0.f,  6.f
			};

			float32 expected_result_matrix[16] = 
			{
				4.f,    12.f,    10.f,     6.f,
               12.f,    48.f,    40.f,    24.f,
               10.f,    40.f,    50.f,    30.f,
                6.f,    24.f,    30.f,    36.f
			};


			typedef cml::CMatrix <float32, 4, 4, true> self;		

			self testMatrix(input_matrix);
			self expected_result(expected_result_matrix);
			cml::CMatrix <float32, 4, 4, false> result;

			cml::boolean_t returnValue, expected_returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, input_matrix, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "expected_result = \n");
			check_float_ArrayPrint(4, 4, expected_result_matrix, fpTest);
			
			std::cout << "test_getUppTriaSqr of type float -> 4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = testMatrix.getUppTriaSqr();

			/* Copy result to this MAtrix */
			testMatrix = result;

			expected_returnValue = TRUE;

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "actual_result = \n");
			check__vMatrixPrint<float32, 4, 4, true>(testMatrix, fpTest);

#ifndef NDEBUG
			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif
			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n"; 
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}	

		fprintf(fpTest, "Test Case ---> Upper triangular square of type float\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* 4X4 float Matrix */
		{
			/* Test case input data declarations */
			float32 input_matrix[16] = 
			{
				1.f,  2.f,  4.f,  7.f,
                0.f,  3.f,  5.f,  8.f,
                0.f,  0.f,  6.f,  9.f,
                0.f,  0.f,  0.f, 10.f
			};

			float32 expected_result_matrix[16] = 
			{
				70.f,    82.f,    87.f,    70.f,
				82.f,    98.f,   102.f,    80.f,
				87.f,   102.f,   117.f,    90.f,
				70.f,    80.f,    90.f,   100.f
			};


			typedef cml::CMatrix <float32, 4, 4, true> self;		

			self testMatrix(input_matrix);
			self expected_result(expected_result_matrix);
			cml::CMatrix <float32, 4, 4, false> result;

			cml::boolean_t returnValue, expected_returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_float_ArrayPrint(4, 4, input_matrix, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "expected_result = \n");
			check_float_ArrayPrint(4, 4, expected_result_matrix, fpTest);
			
			std::cout << "test_getUppTriaSqr of type float -> 4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = testMatrix.getUppTriaSqr();

			/* Copy result to this MAtrix */
			testMatrix = result;

			expected_returnValue = TRUE;

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "actual_result = \n");
			check__vMatrixPrint<float32, 4, 4, true>(testMatrix, fpTest);

#ifndef NDEBUG
			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif
			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n"; 
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Upper triangular square of type int\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* 4X4 int Matrix */
		{
			/* Test case input data declarations */
			sint32 input_matrix[16] = 
			{
				1,  2,  4,  7,
                0,  3,  5,  8,
                0,  0,  6,  9,
                0,  0,  0, 10
			};

			sint32 expected_result_matrix[16] = 
			{
				70,    82,    87,    70,
				82,    98,   102,    80,
				87,   102,   117,    90,
				70,    80,    90,   100
			};


			typedef cml::CMatrix <sint32, 4, 4, true> self;		

			self testMatrix(input_matrix);
			self expected_result(expected_result_matrix);
			cml::CMatrix <sint32, 4, 4, false> result;

			cml::boolean_t returnValue, expected_returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_int_ArrayPrint(4, 4, input_matrix, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "expected_result = \n");
			check_int_ArrayPrint(4, 4, expected_result_matrix, fpTest);
			
			std::cout << "test_getUppTriaSqr of type int -> 4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = testMatrix.getUppTriaSqr();

			/* Copy result to this MAtrix */
			testMatrix = result;

			expected_returnValue = TRUE;

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "actual_result = \n");
			check__vMatrixPrint<sint32, 4, 4, true>(testMatrix, fpTest);

#ifndef NDEBUG
			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif
			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n"; 
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Upper triangular square of type short\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* 4X4 short Matrix */
		{
			/* Test case input data declarations */
			sint16 input_matrix[16] = 
			{
				1,  2,  4,  7,
                0,  3,  5,  8,
                0,  0,  6,  9,
                0,  0,  0, 10
			};

			sint16 expected_result_matrix[16] = 
			{
				70,    82,    87,    70,
				82,    98,   102,    80,
				87,   102,   117,    90,
				70,    80,    90,   100
			};


			typedef cml::CMatrix <sint16, 4, 4, true> self;		

			self testMatrix(input_matrix);
			self expected_result(expected_result_matrix);
			cml::CMatrix <sint16, 4, 4, false> result;

			cml::boolean_t returnValue, expected_returnValue; 	

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_short_ArrayPrint(4, 4, input_matrix, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "expected_result = \n");
			check_short_ArrayPrint(4, 4, expected_result_matrix, fpTest);
			
			std::cout << "test_getUppTriaSqr of type short -> 4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = testMatrix.getUppTriaSqr();

			/* Copy result to this MAtrix */
			testMatrix = result;

			expected_returnValue = TRUE;

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "actual_result = \n");
			check__vMatrixPrint<sint16, 4, 4, true>(testMatrix, fpTest);

#ifndef NDEBUG
			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif
			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n"; 
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Upper triangular square of type char\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 4X4\n\n");

		/* 4X4 char Matrix */
		{
			/* Test case input data declarations */
			sint8 input_matrix[16] = 
			{
				1,  2,  4,  7,
                0,  3,  5,  8,
                0,  0,  6,  9,
                0,  0,  0, 10
			};

			sint8 expected_result_matrix[16] = 
			{
				70,    82,    87,    70,
				82,    98,   102,    80,
				87,   102,   117,    90,
				70,    80,    90,   100
			};


			typedef cml::CMatrix <sint8, 4, 4, true> self;		

			self testMatrix(input_matrix);
			self expected_result(expected_result_matrix);
			cml::CMatrix <sint8, 4, 4, false> result;

			cml::boolean_t returnValue, expected_returnValue;

			/* Input Matrix */
		    fprintf(fpTest, "Input ---> \n");

			fprintf(fpTest, "A = \n");
			check_char_ArrayPrint(4, 4, input_matrix, fpTest);	
					
			/* Expected Result Matrix */
		    fprintf(fpTest, "Expected Result ---> \n");

			fprintf(fpTest, "expected_result = \n");
			check_char_ArrayPrint(4, 4, expected_result_matrix, fpTest);
			
			std::cout << "test_getUppTriaSqr of type char -> 4X4 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = testMatrix.getUppTriaSqr();

			/* Copy result to this MAtrix */
			testMatrix = result;

			expected_returnValue = TRUE;

			/* Actual Result Matrix */
			fprintf(fpTest, "Actual Result ---> \n");
			fprintf(fpTest, "actual_result = \n");
			check__vMatrixPrint<sint8, 4, 4, true>(testMatrix, fpTest);

#ifndef NDEBUG
			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif
			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n"; 
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}
	}

	std::cout << "END ---> test_getUppTriaSqr\n\n";
	fprintf(fpTest, "END ---> test_getUppTriaSqr\n\n");
}

#ifndef NDEBUG
void TEST_CLASS::test_getAlmostEqualRelativeAndAbs(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_getAlmostEqualRelativeAndAbs\n\n";
		fprintf(fpTest, "START ---> test_getAlmostEqualRelativeAndAbs\n\n");

		fprintf(fpTest, "Function Name ---> getAlmostEqualRelativeAndAbs \n\n");
				
		fprintf(fpTest, "Test Case ---> Equality\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 1X1\n\n");

		/* Equal :  1X1 Matrix */
		{
			/* Test case data declarations */
			typedef cml::CMatrix <float32, 1, 1, true> self;

			cml::CMatrix<float32, 1, 1, true> *testMatrix = new cml::CMatrix<float32, 1, 1, true>;
			self a;

			cml::boolean_t returnValue, expected_returnValue; 			
			
			std::cout << "test_getAlmostEqualRelativeAndAbs -> Equal :  1X1 Matrix\n";
			
			/* Set global data */
			initialise_global_data();

			testMatrix->fill(1.175f);

			a.fill(1.175f);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_returnValue = TRUE;

			/* Call Function Under Test */
			returnValue = testMatrix->getAlmostEqualRelativeAndAbs(a);		

			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Un-Equality\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 1X1\n\n");

		/* Un-equal :  1X1 Matrix */
		{
			/* Test case data declarations */
			typedef cml::CMatrix <float32, 1, 1, true> self;

			cml::CMatrix<float32, 1, 1, true> *testMatrix = new cml::CMatrix<float32, 1, 1, true>;
			self a;

			cml::boolean_t returnValue, expected_returnValue; 			
			
			std::cout << "test_getAlmostEqualRelativeAndAbs -> Un-equal :  1X1 Matrix\n";
			fprintf(fpTest, "test_getAlmostEqualRelativeAndAbs -> Un-equal :  1X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			testMatrix->fill(1.5f);

			a.fill(2.0);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_returnValue = FALSE;

			/* Call Function Under Test */
			returnValue = testMatrix->getAlmostEqualRelativeAndAbs(a);

			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n"; 
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Equality\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 2X2\n\n");

		/* Equal :  2X2 Matrix */
		{
			/* Test case input data declarations */
			float32 A[4] = {
				1, 2, 
				3, 4
			};

			float32 B[4] = {
				1, 2, 
				3, 4
			};

			typedef cml::CMatrix <float32, 2, 2, true> self;

			cml::CMatrix<float32, 2, 2, true> testMatrix(A);

			self a(B);

			cml::boolean_t returnValue, expected_returnValue; 	
						
			std::cout << "test_getAlmostEqualRelativeAndAbs -> Equal :  2X2 Matrix\n";
			fprintf(fpTest, "test_getAlmostEqualRelativeAndAbs -> Equal :  2X2 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_returnValue = TRUE;

			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(a);	

			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n"; 
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Un-Equality\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 2X2\n\n");

		/* Un-equal :  2X2 Matrix */
		{
			/* Test case input data declarations */
			float32 A[4] = {
				1, 2, 
				3, 4
			};

			float32 B[4] = {
				4, 3, 
				2, 1
			};

			typedef cml::CMatrix <float32, 2, 2, true> self;

			cml::CMatrix<float32, 2, 2, true> testMatrix(A);
			self a(B);

			cml::boolean_t returnValue, expected_returnValue; 			
			
			std::cout << "test_getAlmostEqualRelativeAndAbs -> Un-equal :  2X2 Matrix\n";
			fprintf(fpTest, "test_getAlmostEqualRelativeAndAbs -> Un-equal :  2X2 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_returnValue = FALSE;

			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(a);

			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Equality\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 3X3\n\n");

		/* Equal :  3X3 Matrix */
		{
			/* Test case input data declarations */
			float32 A[9] = {
				1, 2, 3,
				4, 5, 6,
				7, 8, 9
			};

			float32 B[9] = {
				1, 2, 3,
				4, 5, 6,
				7, 8, 9
			};

			typedef cml::CMatrix <float32, 3, 3, true> self;

			cml::CMatrix<float32, 3, 3, true> testMatrix(A);

			self a(B);

			cml::boolean_t returnValue, expected_returnValue; 	

			std::cout << "test_getAlmostEqualRelativeAndAbs -> Equal :  3X3 Matrix\n";
			fprintf(fpTest, "test_getAlmostEqualRelativeAndAbs -> Equal :  3X3 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_returnValue = TRUE;

			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(a);	

			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Un-Equality\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 3X3\n\n");

		/* Un-equal :  3X3 Matrix */
		{
			/* Test case input data declarations */
			float32 A[9] = {
				1, 2, 3,
				4, 5, 6,
				7, 8, 9
			};

			float32 B[9] = {
				9, 8, 7,
				6, 5, 4,
				3, 2, 1
			};

			typedef cml::CMatrix <float32, 3, 3, true> self;

			cml::CMatrix<float32, 3, 3, true> testMatrix(A);
			self a(B);

			cml::boolean_t returnValue, expected_returnValue; 			
			
			std::cout << "test_getAlmostEqualRelativeAndAbs -> Un-equal :  3X3 Matrix\n";
			fprintf(fpTest, "test_getAlmostEqualRelativeAndAbs -> Un-equal :  3X3 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_returnValue = FALSE;

			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(a);

			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Equality\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 128X128\n\n");

		/* Equal Large Matrix :  128X128 Matrix */
		{
			cml::CMatrix<float32, 128, 128, true> *A = new cml::CMatrix<float32, 128, 128, true>;
			cml::CMatrix<float32, 128, 128, true> *B = new cml::CMatrix<float32, 128, 128, true>;

			/* Test case input data declarations */
			for (int i = 0; i<16384; i++)
			{
				A->operator[](i) = 1000;
			}

			for (int i = 0; i<16384; i++)
			{
				B->operator[](i) = 1000;
			}

			typedef cml::CMatrix <float32, 128, 128, true> self;

			cml::CMatrix<float32, 128, 128, true> testMatrix(*A);
			self a(*B);

			cml::boolean_t returnValue, expected_returnValue; 			
			
			std::cout << "test_getAlmostEqualRelativeAndAbs -> Un-equal :  128X128 Matrix\n";
			fprintf(fpTest, "test_getAlmostEqualRelativeAndAbs -> Un-equal :  128X128 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_returnValue = TRUE;

			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(a);

			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";  
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		fprintf(fpTest, "Test Case ---> Un-Equality\n\n");
		fprintf(fpTest, "Matrix Dimension ---> 128X128\n\n");

		/* Un-equal Large Matrix :  128X128 Matrix */
		{

			cml::CMatrix<float32, 128, 128, true> *A = new cml::CMatrix<float32, 128, 128, true>;
			cml::CMatrix<float32, 128, 128, true> *B = new cml::CMatrix<float32, 128, 128, true>;

			/* Test case input data declarations */
			for (int i = 0; i<16384; i++)
			{
				A->operator[](i) = 1000;
			}

			for (int i = 0; i<16384; i++)
			{
				B->operator[](i) = 512;
			}

			typedef cml::CMatrix <float32, 128, 128, true> self;

			cml::CMatrix<float32, 128, 128, true> testMatrix(*A);
			self a(*B);

			cml::boolean_t returnValue, expected_returnValue; 			
			
			std::cout << "test_getAlmostEqualRelativeAndAbs -> Un-equal :  128X128 Matrix\n";
			fprintf(fpTest, "test_getAlmostEqualRelativeAndAbs -> Un-equal :  128X128 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_returnValue = FALSE;

			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(a);

			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n\n";   
				fprintf(fpTest, "Status --->  FAIL\n");
			}

			/* Remarks */
			fprintf(fpTest, "Remarks ---> \n\n");
		}

#if 0

		/* Equal Large Matrix :  256X256 Matrix */
		{
			cml::CMatrix<float32, 256, 256, true> *A = new cml::CMatrix<float32, 256, 256, true>;
			cml::CMatrix<float32, 256, 256, true> *B = new cml::CMatrix<float32, 256, 256, true>;

			/* Test case input data declarations */
			for (int i = 0; i<65536; i++)
			{
				A->operator[](i) = 1000;
			}

			for (int i = 0; i<65536; i++)
			{
				B->operator[](i) = 1000;
			}

			typedef cml::CMatrix <float32, 256, 256, true> self;

			cml::CMatrix<float32, 256, 256, true> testMatrix(*A);
			self a(*B);

			cml::boolean_t returnValue, expected_returnValue; 			
			
			std::cout << "test_getAlmostEqualRelativeAndAbs -> Un-equal :  256X256 Matrix\n";
			fprintf(fpTest, "test_getAlmostEqualRelativeAndAbs -> Un-equal :  256X256 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_returnValue = TRUE;

			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(a);

			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";  
				fprintf(fpTest, "Status --->  FAIL\n");
			}
		}

		/* Un-equal Large Matrix :  256X256 Matrix */
		{

			cml::CMatrix<float32, 256, 256, true> *A = new cml::CMatrix<float32, 256, 256, true>;
			cml::CMatrix<float32, 256, 256, true> *B = new cml::CMatrix<float32, 256, 256, true>;

			/* Test case input data declarations */
			for (int i = 0; i<65536; i++)
			{
				A->operator[](i) = 1000;
			}

			for (int i = 0; i<65536; i++)
			{
				B->operator[](i) = 512;
			}

			typedef cml::CMatrix <float32, 256, 256, true> self;

			cml::CMatrix<float32, 256, 256, true> testMatrix(*A);
			self a(*B);

			cml::boolean_t returnValue, expected_returnValue; 			
			
			std::cout << "test_getAlmostEqualRelativeAndAbs -> Un-equal :  256X256 Matrix\n";
			fprintf(fpTest, "test_getAlmostEqualRelativeAndAbs -> Un-equal :  256X256 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_returnValue = FALSE;

			/* Call Function Under Test */
			returnValue = testMatrix.getAlmostEqualRelativeAndAbs(a);

			/* Checks on global data */
			if(returnValue == expected_returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n"; 
				fprintf(fpTest, "Status --->  FAIL\n");
			}
		}
#endif

		std::cout << "END ---> test_getAlmostEqualRelativeAndAbs\n\n";
		fprintf(fpTest, "END ---> test_getAlmostEqualRelativeAndAbs\n\n");
	}
}
#endif /* #ifndef NDEBUG */

// End of test cases      

