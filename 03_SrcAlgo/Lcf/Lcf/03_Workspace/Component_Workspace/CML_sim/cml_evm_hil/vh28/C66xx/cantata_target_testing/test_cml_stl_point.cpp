/*****************************************************************************/
/*                            Cantata Test Script                            */
/*****************************************************************************/
/*
*    Filename: test_cml_stl_point.cpp
*    Author: uidr1064
*    Generated on: 05-Jan-2016 16:53:36
*    Generated from: cml_stl_point.cpp
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

/* Global data */
/* None */

/* Expected variables for global data */
/* None */

/* This function prints the data contained in the CPoint object to a file. */
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

/* This function prints the data contained in the CPoint object to console. */
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

template < typename T, sint32 ROWS, sint32 COLS, bool EXT_MEM >
void check__vMatrixPrint_to_File( cml::CMatrix< T, ROWS, COLS, EXT_MEM > &oMatrix, FILE *fpTest)
{    
	int  iIndex= 0;
	for( int row=0; row<oMatrix.rows(); row++ )
	{
		for( int col=0; col<oMatrix.cols(); col++ )
		{            
			check__PrintValue_to_File(oMatrix[iIndex], fpTest);
			iIndex++;
		}

		fprintf(fpTest, "\n");
	} 

	fprintf(fpTest, "\n\n");
}

template < typename T, sint32 ROWS, sint32 COLS, bool EXT_MEM >
void check__vMatrixPrint_to_console( cml::CMatrix< T, ROWS, COLS, EXT_MEM > &oMatrix)
{    
	int  iIndex= 0;
	for( int row=0; row<oMatrix.rows(); row++ )
	{
		for( int col=0; col<oMatrix.cols(); col++ )
		{            
			check__PrintValue_to_console(oMatrix[iIndex]);
			iIndex++;
		}

		fprintf(fpTest, "\n");
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

	/* No global data */
	std::cout << "\nStatus ---> PASS\n\n"; 
	fprintf(fpTest, "\nStatus ---> PASS\n\n");
}

/*****************************************************************************/
/* Test class declaration                                                    */
/*****************************************************************************/
class TEST_CLASS_POINT
{
public:
	void run_tests_point();
	void test_norm(int);
	void test_normsq(int);
	void test_scalarproduct2D(int);
	void test_crossproduct2D(int);
	void test_norm3D(int);
	void test_normsq3D(int);
	void test_scalarproduct3D(int);
	void test_crossproduct3D(int);
};

/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_stl_point(void)
{
	TEST_CLASS_POINT test_object;

	std::cout << "******** Start Testing: Point Library functions ********\n\n";
	fprintf(fpTest, "******** Start Testing: Point Library functions ********\n\n");

	test_object.run_tests_point();

	std::cout << "End of Testing: Point Library functions\n\n";
	fprintf(fpTest, "End of Testing: Point Library functions\n\n");

	return ;
}

/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS_POINT::run_tests_point()
{
	test_norm(1);
	test_normsq(1);
	test_scalarproduct2D(1);
	test_crossproduct2D(1);
	test_norm3D(1);
	test_normsq3D(1);
	test_scalarproduct3D(1);
	test_crossproduct3D(1);
}

/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/

void TEST_CLASS_POINT::test_norm(int doIt)
{
	std::cout << "START ---> test_norm\n\n";		
	fprintf(fpTest, "START ---> test_norm\n\n");

	fprintf(fpTest, "Function Name ---> norm() \n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_norm_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_norm_001\n\n");

		std::cout << "Data Dimension ---> 2*1\n\n";		
		fprintf(fpTest, "Data Dimension ---> 2*1\n\n");
		
		/* Test case data declarations */
		cml::CartesianPoint2D<sint32> input(1,-1);
		float32 result, expected_result;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_result = cml::sqrt(2);
		
		/* Input */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vMatrixPrint_to_console< sint32, 2,1, false >( input);
		check__vMatrixPrint_to_File< sint32, 2,1, false >( input, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_result);
		check__PrintValue_to_File(expected_result, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = input.norm();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(result);
		check__PrintValue_to_File(result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( result,expected_result);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status---> FAIL\n\n";    
			fprintf(fpTest, "Status---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
		std::cout << "Test Case ---> test_norm_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_norm_002\n\n");

		std::cout << "Data Dimension ---> 2*1\n\n";		
		fprintf(fpTest, "Data Dimension ---> 2*1\n\n");
		
		/* Test case data declarations */
		cml::CMatrix<float32, 2, 1, false> vector;
		vector(0,0) = 2.5;
		vector(1,0) = 1.5;
		cml::CartesianPoint2D<float32> input(vector);
		float32 result, expected_result;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_result = 2.9154756f;
		
		/* Input */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vMatrixPrint_to_console< float32, 2,1, false >( input);
		check__vMatrixPrint_to_File< float32, 2,1, false >( input, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_result);
		check__PrintValue_to_File(expected_result, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = input.norm();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(result);
		check__PrintValue_to_File(result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( result,expected_result);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status---> FAIL\n\n";    
			fprintf(fpTest, "Status---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
		std::cout << "Test Case ---> test_norm_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_norm_003\n\n");

		std::cout << "Data Dimension ---> 2*1\n\n";		
		fprintf(fpTest, "Data Dimension ---> 2*1\n\n");
		
		/* Test case data declarations */
		cml::CMatrix<char, 2, 1, false> vector;
		vector(0,0) = 1.5;
		vector(1,0) = 1.5;
		cml::CartesianPoint2D<char> input(vector);
		float32 result, expected_result;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_result = 1.4142132f;
		
		/* Input */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vMatrixPrint_to_console< char, 2,1, false >( vector);
		check__vMatrixPrint_to_File< char, 2,1, false >( vector, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_result);
		check__PrintValue_to_File(expected_result, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = input.norm();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(result);
		check__PrintValue_to_File(result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( result,expected_result);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status---> FAIL\n\n";    
			fprintf(fpTest, "Status---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> Precision difference expected on target platforms\n\n");
		std::cout << "Remarks ---> Precision difference expected on target platforms\n\n";
	}

	}
	std::cout << "END ---> test_norm\n\n";
	fprintf(fpTest, "END ---> test_norm\n\n");
}

void TEST_CLASS_POINT::test_normsq(int doIt)
{
	std::cout << "START ---> test_normsq\n\n";		
	fprintf(fpTest, "START ---> test_normsq\n\n");

	fprintf(fpTest, "Function Name ---> normsq() \n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_normsq_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_normsq_001\n\n");

		std::cout << "Data Dimension ---> 2*1\n\n";		
		fprintf(fpTest, "Data Dimension ---> 2*1\n\n");


		/* Test case data declarations */
		cml::CartesianPoint2D<sint32> input(1,-1);
		float32 result, expected_result;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_result = 2;
		
		/* Input */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vMatrixPrint_to_console< sint32, 2,1, false >( input);
		check__vMatrixPrint_to_File< sint32, 2,1, false >( input, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_result);
		check__PrintValue_to_File(expected_result, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = input.normSq();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(result);
		check__PrintValue_to_File(result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( result,expected_result);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status---> FAIL\n\n";    
			fprintf(fpTest, "Status---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
		std::cout << "Test Case ---> test_normsq_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_normsq_002\n\n");

		std::cout << "Data Dimension ---> 2*1\n\n";		
		fprintf(fpTest, "Data Dimension ---> 2*1\n\n");
		
		/* Test case data declarations */
		cml::CMatrix<float32, 2, 1, false> vector;
		vector(0,0) = 2.5;
		vector(1,0) = 1.5;
		cml::CartesianPoint2D<float32> input(vector);
		float32 result, expected_result;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_result = 8.5000000f;
		
		/* Input */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vMatrixPrint_to_console< float32, 2,1, false >( input);
		check__vMatrixPrint_to_File< float32, 2,1, false >( input, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_result);
		check__PrintValue_to_File(expected_result, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = input.normSq();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(result);
		check__PrintValue_to_File(result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( result,expected_result);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status---> FAIL\n\n";    
			fprintf(fpTest, "Status---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
		std::cout << "Test Case ---> test_normsq_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_normsq_003\n\n");

		std::cout << "Data Dimension ---> 2*1\n\n";		
		fprintf(fpTest, "Data Dimension ---> 2*1\n\n");
		
		/* Test case data declarations */
		cml::CMatrix<char, 2, 1, false> vector;
		vector(0,0) = 1.5;
		vector(1,0) = 1.5;
		cml::CartesianPoint2D<char> input(vector);
		float32 result, expected_result;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_result = 2.f;
		
		/* Input */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vMatrixPrint_to_console< char, 2,1, false >( vector);
		check__vMatrixPrint_to_File< char, 2,1, false >( vector, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_result);
		check__PrintValue_to_File(expected_result, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = input.normSq();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(result);
		check__PrintValue_to_File(result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( result,expected_result);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status---> FAIL\n\n";    
			fprintf(fpTest, "Status---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
	std::cout << "END ---> test_normsq\n\n";
	fprintf(fpTest, "END ---> test_normsq\n\n");
}

void TEST_CLASS_POINT::test_scalarproduct2D(int doIt)
{
	std::cout << "START ---> test_scalarproduct2D\n\n";		
	fprintf(fpTest, "START ---> test_scalarproduct2D\n\n");

	fprintf(fpTest, "Function Name ---> scalarproduct() \n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_scalarproduct2D_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_scalarproduct2D_001\n\n");

		std::cout << "Data Dimension ---> 2*1\n\n";		
		fprintf(fpTest, "Data Dimension ---> 2*1\n\n");

		/* Test case data declarations */
		sint32 input2[] = {1,2};
		cml::CMatrix<sint32, 2, 1, false> vector;
		cml::CartesianPoint2D<sint32> input(1,-1);
		cml::CartesianPoint2D<sint32> rhs(input2);

		float32 result, expected_result;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_result = -1;
		
		/* Input */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vMatrixPrint_to_console< sint32, 2,1, false >( input);
		check__vMatrixPrint_to_File< sint32, 2,1, false >( input, fpTest);
		
		std::cout << "input2 = \n";		
		fprintf(fpTest, "input2 = \n");
		
		check__vMatrixPrint_to_console< sint32, 2,1, false >( rhs);
		check__vMatrixPrint_to_File< sint32, 2,1, false >( rhs, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_result);
		check__PrintValue_to_File(expected_result, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = input.scalarProduct(rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(result);
		check__PrintValue_to_File(result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( result,expected_result);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status---> FAIL\n\n";    
			fprintf(fpTest, "Status---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
		std::cout << "Test Case ---> test_scalarproduct2D_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_scalarproduct2D_002\n\n");

		std::cout << "Data Dimension ---> 2*1\n\n";		
		fprintf(fpTest, "Data Dimension ---> 2*1\n\n");
		
		/* Test case data declarations */
		float32 input2[] = {1.5,
			-2.5};
		cml::CMatrix<float32, 2, 1, false> vector;
		cml::CartesianPoint2D<float32> input(2.5,-3.5);
		cml::CartesianPoint2D<float32> rhs(input2);

		float32 result, expected_result;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_result = 12.500000;
		
		/* Input */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vMatrixPrint_to_console< float32, 2,1, false >( input);
		check__vMatrixPrint_to_File< float32, 2,1, false >( input, fpTest);
		
		std::cout << "input2 = \n";		
		fprintf(fpTest, "input2 = \n");
		
		check__vMatrixPrint_to_console< float32, 2,1, false >( rhs);
		check__vMatrixPrint_to_File< float32, 2,1, false >( rhs, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_result);
		check__PrintValue_to_File(expected_result, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = input.scalarProduct(rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(result);
		check__PrintValue_to_File(result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( result,expected_result);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status---> FAIL\n\n";    
			fprintf(fpTest, "Status---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
	std::cout << "END ---> test_scalarproduct2D\n\n";
	fprintf(fpTest, "END ---> test_scalarproduct2D\n\n");
}

void TEST_CLASS_POINT::test_crossproduct2D(int doIt)
{
	std::cout << "START ---> test_crossproduct2D\n\n";		
	fprintf(fpTest, "START ---> test_crossproduct2D\n\n");

	fprintf(fpTest, "Function Name ---> crossproduct() \n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_crossproduct2D_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_crossproduct2D_001\n\n");

		std::cout << "Data Dimension ---> 2*1\n\n";		
		fprintf(fpTest, "Data Dimension ---> 2*1\n\n");


		/* Test case data declarations */
		sint32 input2[] = {1,
			2};
		cml::CMatrix<sint32, 2, 1, false> vector;
		cml::CartesianPoint2D<sint32> input(1,-1);
		cml::CartesianPoint2D<sint32> rhs(input2);

		float32 result, expected_result;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_result = 3;
		
		/* Input */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vMatrixPrint_to_console< sint32, 2,1, false >( input);
		check__vMatrixPrint_to_File< sint32, 2,1, false >( input, fpTest);
		
		std::cout << "input2 = \n";		
		fprintf(fpTest, "input2 = \n");
		
		check__vMatrixPrint_to_console< sint32, 2,1, false >( rhs);
		check__vMatrixPrint_to_File< sint32, 2,1, false >( rhs, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_result);
		check__PrintValue_to_File(expected_result, fpTest);
		fprintf(fpTest, "\n\n");
		
#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		result = input.crossProduct(rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(result);
		check__PrintValue_to_File(result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( result,expected_result);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status---> FAIL\n\n";    
			fprintf(fpTest, "Status---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
		std::cout << "Test Case ---> test_crossproduct2D_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_crossproduct2D_002\n\n");

		std::cout << "Data Dimension ---> 2*1\n\n";		
		fprintf(fpTest, "Data Dimension ---> 2*1\n\n");
		
		/* Test case data declarations */
		float32 input2[] = {1.5,
			-2.5};
		cml::CMatrix<float32, 2, 1, false> vector;
		cml::CartesianPoint2D<float32> input(2.5,-3.5);
		cml::CartesianPoint2D<float32> rhs(input2);

		float32 result, expected_result;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_result = -1.0;
		
		/* Input */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vMatrixPrint_to_console< float32, 2,1, false >( input);
		check__vMatrixPrint_to_File< float32, 2,1, false >( input, fpTest);
		
		std::cout << "input2 = \n";		
		fprintf(fpTest, "input2 = \n");
		
		check__vMatrixPrint_to_console< float32, 2,1, false >( rhs);
		check__vMatrixPrint_to_File< float32, 2,1, false >( rhs, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_result);
		check__PrintValue_to_File(expected_result, fpTest);
		fprintf(fpTest, "\n\n");
		
#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		result = input.crossProduct(rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(result);
		check__PrintValue_to_File(result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( result,expected_result);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status---> FAIL\n\n";    
			fprintf(fpTest, "Status---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
	std::cout << "END ---> test_crossproduct2D_002\n\n";
	fprintf(fpTest, "END ---> test_crossproduct2D_002\n\n");
}

void TEST_CLASS_POINT::test_norm3D(int doIt)
{
	std::cout << "START ---> test_norm3D\n\n";		
	fprintf(fpTest, "START ---> test_norm3D\n\n");

	fprintf(fpTest, "Function Name ---> norm()  \n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_norm3D_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_norm3D_001\n\n");

		std::cout << "Data Dimension ---> 3*1\n\n";		
		fprintf(fpTest, "Data Dimension ---> 3*1\n\n");

		/* Test case data declarations */
		cml::CMatrix<sint32, 3, 1, false> vector;
		cml::CartesianPoint3D<sint32> input(1,-1,1);
		float32 result, expected_result;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_result = 1.7320508f;
		
		/* Input */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vMatrixPrint_to_console< sint32, 3,1, false >( input);
		check__vMatrixPrint_to_File< sint32, 3,1, false >( input, fpTest);
		
		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_result);
		check__PrintValue_to_File(expected_result, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = input.norm();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(result);
		check__PrintValue_to_File(result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( result,expected_result);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status---> FAIL\n\n";    
			fprintf(fpTest, "Status---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> Precision difference expected on target platform\n\n");
		std::cout << "Remarks ---> Precision difference expected on target platform\n\n";
		}
		
		{
		std::cout << "Test Case ---> test_norm3D_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_norm3D_002\n\n");

		std::cout << "Data Dimension ---> 3*1\n\n";		
		fprintf(fpTest, "Data Dimension ---> 3*1\n\n");
		
		/* Test case data declarations */
		cml::CMatrix<float32, 3, 1, false> vector;
		vector(0,0) = 2.5;
		vector(1,0) = 1.5;
		vector(2,0) = 1.5;
		cml::CartesianPoint3D<float32> input(vector);
		float32 result, expected_result;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_result = 3.2787192f;
		
		/* Input */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vMatrixPrint_to_console< float32, 3,1, false >( input);
		check__vMatrixPrint_to_File< float32, 3,1, false >( input, fpTest);
		
		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_result);
		check__PrintValue_to_File(expected_result, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = input.norm();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(result);
		check__PrintValue_to_File(result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( result,expected_result);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status---> FAIL\n\n";    
			fprintf(fpTest, "Status---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
		std::cout << "Test Case ---> test_norm3D_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_norm3D_003\n\n");

		std::cout << "Data Dimension ---> 3*1\n\n";		
		fprintf(fpTest, "Data Dimension ---> 3*1\n\n");
		
		/* Test case data declarations */
		cml::CMatrix<char, 3, 1, false> vector;
		vector(0,0) = 1.5;
		vector(1,0) = 1.5;
		vector(2,0) = 1.5;
		cml::CartesianPoint3D<char> input(vector);
		float32 result, expected_result;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_result = 1.7320508f;
		
		/* Input */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vMatrixPrint_to_console< char, 3,1, false >( input);
		check__vMatrixPrint_to_File< char, 3,1, false >( input, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_result);
		check__PrintValue_to_File(expected_result, fpTest);
		fprintf(fpTest, "\n\n");
		
#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = input.norm();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(result);
		check__PrintValue_to_File(result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( result,expected_result);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status---> FAIL\n\n";    
			fprintf(fpTest, "Status---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

		total_cycles = stop_clock - start_clock - overhead;

		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);	
		fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

		/* Remarks */
		fprintf(fpTest, "Remarks ---> Precision difference expected on target platform\n\n");
		std::cout << "Remarks ---> Precision difference expected on target platform\n\n";
		}
	}
	std::cout << "END ---> test_norm3D\n\n";
	fprintf(fpTest, "END ---> test_norm3D\n\n");
}

void TEST_CLASS_POINT::test_normsq3D(int doIt)
{
	std::cout << "START ---> test_normsq3D\n\n";		
	fprintf(fpTest, "START ---> test_normsq3D\n\n");

	fprintf(fpTest, "Function Name ---> normsq()  \n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_normsq3D_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_normsq3D_001\n\n");

		std::cout << "Data Dimension ---> 3*1\n\n";		
		fprintf(fpTest, "Data Dimension ---> 3*1\n\n");


		/* Test case data declarations */
		cml::CMatrix<sint32, 3, 1, false> vector;
		cml::CartesianPoint3D<sint32> input(1,-1, 1);
		float32 result, expected_result;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();
		expected_result = 3;

		/* Input */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vMatrixPrint_to_console< sint32, 3,1, false >( input);
		check__vMatrixPrint_to_File< sint32, 3,1, false >( input, fpTest);
		
		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_result);
		check__PrintValue_to_File(expected_result, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
			
		/* Call SUT */
		result = input.normSq();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(result);
		check__PrintValue_to_File(result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( result,expected_result);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status---> FAIL\n\n";    
			fprintf(fpTest, "Status---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
		std::cout << "Test Case ---> test_normsq3D_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_normsq3D_002\n\n");

		std::cout << "Data Dimension ---> 3*1\n\n";		
		fprintf(fpTest, "Data Dimension ---> 3*1\n\n");
		
		/* Test case data declarations */
		cml::CMatrix<float32, 3, 1, false> vector;
		vector(0,0) = 2.5;
		vector(1,0) = 1.5;
		vector(2,0) = 1.5;
		cml::CartesianPoint3D<float32> input(vector);
		float32 result, expected_result;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_result = 10.750000f;
		
		/* Input */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vMatrixPrint_to_console< float32, 3,1, false >( input);
		check__vMatrixPrint_to_File< float32, 3,1, false >( input, fpTest);
		
		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_result);
		check__PrintValue_to_File(expected_result, fpTest);
		fprintf(fpTest, "\n\n");
	
#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = input.normSq();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(result);
		check__PrintValue_to_File(result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( result,expected_result);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status---> FAIL\n\n";    
			fprintf(fpTest, "Status---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
		std::cout << "Test Case ---> test_normsq3D_003\n\n";		
		fprintf(fpTest, "Test Case ---> test_normsq3D_003\n\n");

		std::cout << "Data Dimension ---> 3*1\n\n";		
		fprintf(fpTest, "Data Dimension ---> 3*1\n\n");
		
		/* Test case data declarations */
		cml::CMatrix<char, 3, 1, false> vector;
		vector(0,0) = 1.5;
		vector(1,0) = 1.5;
		vector(2,0) = 1.5;
		cml::CartesianPoint3D<char> input(vector);
		float32 result, expected_result;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_result = 3.f;
				
		/* Input */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vMatrixPrint_to_console< char, 3,1, false >( input);
		check__vMatrixPrint_to_File< char, 3,1, false >( input, fpTest);

		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_result);
		check__PrintValue_to_File(expected_result, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = input.normSq();

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(result);
		check__PrintValue_to_File(result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( result,expected_result);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status---> FAIL\n\n";    
			fprintf(fpTest, "Status---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
	std::cout << "END ---> test_normsq3D\n\n";
	fprintf(fpTest, "END ---> test_normsq3D\n\n");
}

void TEST_CLASS_POINT::test_scalarproduct3D(int doIt)
{
	std::cout << "START ---> test_scalarproduct3D\n\n";		
	fprintf(fpTest, "START ---> test_scalarproduct3D\n\n");

	fprintf(fpTest, "Function Name ---> scalarproduct()  \n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_scalarproduct3D_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_scalarproduct3D_001\n\n");

		std::cout << "Data Dimension ---> 3*1\n\n";		
		fprintf(fpTest, "Data Dimension ---> 3*1\n\n");

		/* Test case data declarations */
		sint32 input2[] = {1,
			2,
			3};
		cml::CMatrix<sint32, 3, 1, false> vector;
		cml::CartesianPoint3D<sint32> input(1,-1, 1);
		cml::CartesianPoint3D<sint32> rhs(input2);

		float32 result, expected_result;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_result = 2;
		
		/* Input */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vMatrixPrint_to_console< sint32, 3,1, false >( input);
		check__vMatrixPrint_to_File< sint32, 3,1, false >( input, fpTest);
		
		std::cout << "input2 = \n";		
		fprintf(fpTest, "input2 = \n");
		
		check__vMatrixPrint_to_console< sint32, 3,1, false >( rhs);
		check__vMatrixPrint_to_File< sint32, 3,1, false >( rhs, fpTest);
		
		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_result);
		check__PrintValue_to_File(expected_result, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = input.scalarProduct(rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(result);
		check__PrintValue_to_File(result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( result,expected_result);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status---> FAIL\n\n";    
			fprintf(fpTest, "Status---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
		std::cout << "Test Case ---> test_scalarproduct3D_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_scalarproduct3D_002\n\n");

		std::cout << "Data Dimension ---> 3*1\n\n";		
		fprintf(fpTest, "Data Dimension ---> 3*1\n\n");
		
		/* Test case data declarations */
		float32 input2[] = {1.5,
			-2.5,
			1.5};
		cml::CMatrix<float32, 3, 1, false> vector;
		cml::CartesianPoint3D<float32> input(2.5,-3.5, 1.5);
		cml::CartesianPoint3D<float32> rhs(input2);

		float32 result, expected_result;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_result = 14.750000f;
		
		/* Input */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vMatrixPrint_to_console< float32, 3,1, false >( input);
		check__vMatrixPrint_to_File< float32, 3,1, false >( input, fpTest);
		
		std::cout << "input2 = \n";		
		fprintf(fpTest, "input2 = \n");
		
		check__vMatrixPrint_to_console< float32, 3,1, false >( rhs);
		check__vMatrixPrint_to_File< float32, 3,1, false >( rhs, fpTest);
		
		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__PrintValue_to_console(expected_result);
		check__PrintValue_to_File(expected_result, fpTest);
		fprintf(fpTest, "\n\n");
		
#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		/* Call SUT */
		result = input.scalarProduct(rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__PrintValue_to_console(result);
		check__PrintValue_to_File(result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = check__boCompare( result,expected_result);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status---> FAIL\n\n";    
			fprintf(fpTest, "Status---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
	std::cout << "END ---> test_scalarproduct3D\n\n";
	fprintf(fpTest, "END ---> test_scalarproduct3D\n\n");
}

void TEST_CLASS_POINT::test_crossproduct3D(int doIt)
{
	std::cout << "START ---> test_crossproduct3D\n\n";		
	fprintf(fpTest, "START ---> test_crossproduct3D\n\n");

	fprintf(fpTest, "Function Name ---> crossproduct()  \n\n");

	if (doIt) {

		{
		std::cout << "Test Case ---> test_crossproduct3D_001\n\n";		
		fprintf(fpTest, "Test Case ---> test_crossproduct3D_001\n\n");

		std::cout << "Data Dimension ---> 3*1\n\n";		
		fprintf(fpTest, "Data Dimension ---> 3*1\n\n");

		/* Test case data declarations */
		sint32 input2[] = {1,
			2,
			1};
		cml::CMatrix<sint32, 3, 1, false> vector;
		cml::CartesianPoint3D<sint32> input(1,-1, 1);
		cml::CartesianPoint3D<sint32> rhs(input2);
		cml::CartesianPoint3D<sint32> result, expected_result;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_result(0,0) = -3;
		expected_result(1,0) = 0;
		expected_result(2,0) = 3;

		/* Input */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vMatrixPrint_to_console< sint32, 3,1, false >( input);
		check__vMatrixPrint_to_File< sint32, 3,1, false >( input, fpTest);
		
		std::cout << "input2 = \n";		
		fprintf(fpTest, "input2 = \n");
		
		check__vMatrixPrint_to_console< sint32, 3,1, false >( rhs);
		check__vMatrixPrint_to_File< sint32, 3,1, false >( rhs, fpTest);
		
		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__vMatrixPrint_to_console< sint32, 3,1, false >(expected_result);
		check__vMatrixPrint_to_File< sint32, 3,1, false >(expected_result, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = input.crossProduct(rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__vMatrixPrint_to_console< sint32, 3,1, false >(result);
		check__vMatrixPrint_to_File< sint32, 3,1, false >(result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = result.getAlmostEqualRelativeAndAbs(expected_result);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status---> FAIL\n\n";    
			fprintf(fpTest, "Status---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
		std::cout << "Test Case ---> test_crossproduct3D_002\n\n";		
		fprintf(fpTest, "Test Case ---> test_crossproduct3D_002\n\n");

		std::cout << "Data Dimension ---> 3*1\n\n";		
		fprintf(fpTest, "Data Dimension ---> 3*1\n\n");
		

		/* Test case data declarations */
		typedef cml::CartesianPoint3D<float32> self ;
		self input, rhs,result,expected_result;
		
		input(0,0) = 2.5;
		input(1,0) = -3.5;
		input(2,0) = 1.5;

		rhs(0,0) = 1.5;
		rhs(1,0) = -2.5;
		rhs(2,0) = 1.5;
		
		expected_result(0,0) = -1.5;
		expected_result(1,0) = -1.5;
		expected_result(2,0) = -1.0;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();


		/* Input */
		std::cout << "\nInput ---> \n";	
		fprintf(fpTest, "\nInput ---> \n");
		
		std::cout << "input1 = \n";		
		fprintf(fpTest, "input1 = \n");
		
		check__vMatrixPrint_to_console< float32, 3,1, false >( input);
		check__vMatrixPrint_to_File< float32, 3,1, false >( input, fpTest);
		
		std::cout << "input2 = \n";		
		fprintf(fpTest, "input2 = \n");
		
		check__vMatrixPrint_to_console< float32, 3,1, false >( rhs);
		check__vMatrixPrint_to_File< float32, 3,1, false >( rhs, fpTest);
		
		/* Expected Result */
		std::cout << "Expected Result ---> \n";	
		fprintf(fpTest, "Expected Result ---> \n");	
		
		std::cout << "expected_result = \n";	
		fprintf(fpTest, "expected_result = \n");
		
		check__vMatrixPrint_to_console< float32, 3,1, false >(expected_result);
		check__vMatrixPrint_to_File< float32, 3,1, false >(expected_result, fpTest);
		fprintf(fpTest, "\n\n");

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
		
		/* Call SUT */
		result = input.crossProduct(rhs);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

		/* Actual Result*/
		std::cout << "Actual Result ---> \n";	
		fprintf(fpTest, "Actual Result ---> \n");
		
		std::cout << "result1 = \n";	
		fprintf(fpTest, "result1 = \n");
		
		check__vMatrixPrint_to_console< float32, 3,1, false >(result);
		check__vMatrixPrint_to_File< float32, 3,1, false >(result, fpTest);
		fprintf(fpTest, "\n\n");
		
		/* Test case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = result.getAlmostEqualRelativeAndAbs(expected_result);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status---> FAIL\n\n";    
			fprintf(fpTest, "Status---> FAIL\n\n");
		}

#ifdef ENABLE_PROFILER
		std::cout << "Clock Cycles ---> \n";		
		fprintf(fpTest, "Clock Cycles ---> \n");

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
	std::cout << "END ---> test_crossproduct3D\n\n";
	fprintf(fpTest, "END ---> test_crossproduct3D\n\n");
}

#if 0
void TEST_CLASS_POINT::test_crossproduct3D(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_crossproduct3D_001",
			"Description:\
			- cml_stl_point.h : cml::CartesianPoint3D<T> crossproduct() \
			- Testing: interface \
			- Overview: verify that the crossproduct() works properly and cover all possible paths of implementation \
			- Entry conditions: 3D input vectors with signed integer values\
			- Expected results: cross product");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Test case data declarations */
			sint32 input2[] = {1,
			2,
			1};
		cml::CMatrix<sint32, 3, 1, false> vector;
		cml::CartesianPoint3D<sint32> input(1,-1, 1);
		cml::CartesianPoint3D<sint32> rhs(input2);
		cml::CartesianPoint3D<sint32> result, expected_result;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_result(0,0) = -3;
		expected_result(1,0) = 0;
		expected_result(2,0) = 3;

		/* Call SUT */
		result = input.crossProduct(rhs);

		/* Test case checks */
		CHECK_DOUBLE(result(0,0), expected_result(0,0));
		CHECK_DOUBLE(result(1,0), expected_result(1,0));
		CHECK_DOUBLE(result(2,0), expected_result(2,0));

		/* Checks on global data */
		check_global_data();
		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_crossproduct3D_002",
			"Description:\
			- cml_stl_point.h : cml::CartesianPoint3D<T> crossproduct() \
			- Testing: interface \
			- Overview: verify that the crossproduct() works properly and cover all possible paths of implementation \
			- Entry conditions: 3D input vectors with signed float values\
			- Expected results: cross productt");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Test case data declarations */
			float32 input2[] = {1.5,
			-2.5,
			1.5};
		cml::CMatrix<float32, 3, 1, false> vector;
		cml::CartesianPoint3D<float32> input(2.5,-3.5, 1.5);
		cml::CartesianPoint3D<float32> rhs(input2);
		cml::CartesianPoint3D<float32> result, expected_result;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_result(0,0) = -1.5f;
		expected_result(1,0) = -1.5f;
		expected_result(2,0) = -1.0f;

		/* Call SUT */
		result = input.crossProduct(rhs);

		/* Test case checks */

		CHECK_DOUBLE(result(0,0), expected_result(0,0));
		CHECK_DOUBLE(result(1,0), expected_result(1,0));
		CHECK_DOUBLE(result(2,0), expected_result(2,0));

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
/* pragma qas cantata testscript end */
/*****************************************************************************/
/* End of test script                                                        */
/*****************************************************************************/
