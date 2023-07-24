/*****************************************************************************/
/*                            Cantata Test Script                            */
/*****************************************************************************/
/*
*    Filename: test_cml_stl_matrix.cpp
*    Author: uidr1064
*    Generated on: 08-Dec-2015 16:36:04
*    Generated from: cml_stl_matrix.cpp
*/
/*****************************************************************************/
/* Environment Definition                                                    */
/*****************************************************************************/

#define TEST_SCRIPT_GENERATOR 2
typedef unsigned long long uint64;
/* Include files from software under test */
#include <stdio.h>
#include <iostream>
#include "cml_ext_cpp.h"
#if 0
extern "C"
{
#include "cml_ext.h"
}
#include "glob_type.h"
#include "cml_stl_type_traits.h"
#include "cml_stl_array.h"
#include "cml_stl_array2d.h"
#include "cml_stl_matrix.h"
#endif

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

#define EXT_MEM_TEST_FAIL 0  //Not working test cases will be moved under this switch
/* Test Log file */
extern FILE *fpTest;

//#if 0
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
		//zu groß    
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

template< typename T >
bool check__not_NULL( T &Ist)
{
	return (Ist!=NULL);
}

#if 0
#define check_boCArrayContent( CARRAY, BUFFER ) \
	check__boCArrayContent( CARRAY, (const void *)BUFFER, sizeof(BUFFER)/sizeof(BUFFER[0]), sizeof(BUFFER[0]) )

template< typename T, sint32 SIZE, bool EXT_MEM >
bool check__boCArrayContent( const cml::CArray< T, SIZE, EXT_MEM > &oArray, void const * const pBuffer)
{
	bool biRetVal = true;

	for( int iIndex=0; iIndex < oArray.size(); ++iIndex )
	{
		T Ist  =  oArray.at( iIndex );
		T Soll = *( (T *)pBuffer + iIndex );
		check__boCompare< T >( Ist, Soll ) ? (void)0 : biRetVal &= false; 
	}
	return biRetVal;
}

template < typename T, sint32 ROWS, sint32 COLS, bool EXT_MEM >
bool check__boCArrayContent( const cml::CMatrix< T, ROWS, COLS, EXT_MEM > &oMatrix, void const * const pBuffer, uint16 u16NoOfElements, uint8 u8ElementSize )
{
	return check__boCArrayContent( (cml::CArray< T, ROWS*COLS, EXT_MEM > &)oMatrix, pBuffer, u16NoOfElements, u8ElementSize );
}

#endif

template < typename T, sint32 ROWS, sint32 COLS, bool EXT_MEM >
bool check__boCMatrixContent( const cml::CMatrix< T,ROWS ,COLS , EXT_MEM > &RMatrix,  const cml::CMatrix< T, ROWS, COLS, EXT_MEM > &EMatrix)
{
	bool biRetVal = true;

	for( int iIndex=0; iIndex < RMatrix.size(); ++iIndex )
	{
		T Ist  =  RMatrix[ iIndex ];
		T Soll =  EMatrix[ iIndex ];;
		check__boCompare< T >( Ist, Soll ) ? 0 : biRetVal &= false; 
	}
	return biRetVal;
}

//template < typename T, sint32 ROWS, sint32 COLS, bool EXT_MEM >
//bool check__boCMatrixContent( const cml::CMatrix< T, ROWS, COLS, EXT_MEM > &oMatrix, void const * const pBuffer, uint16 u16NoOfElements, uint8 u8ElementSize )
//{
//	return check__boCMatrixContent( (cml::CArray< T, ROWS*COLS, EXT_MEM > &)oMatrix, pBuffer, u16NoOfElements, u8ElementSize );
//}


//#define check_vMatrixPrint( MATRIX )        \
//    check__vMatrixPrint_to_File( MATRIX, #MATRIX )

//template < typename T, sint32 ROWS, sint32 COLS, bool EXT_MEM >
//void check__vMatrixPrint_to_File(  cml::CMatrix< T, ROWS, COLS, EXT_MEM > &oMatrix, char *pName )
//{
//	printf( "\nCMatrix \'%s\' size=%i, rows=%i, cols=%i\n", pName, oMatrix.size(),oMatrix.rows(), oMatrix.cols() );
//
//	int  iIndex= 0;
//	for( int row=0; row<oMatrix.rows(); row++ )
//	{
//		for( int col=0; col<oMatrix.cols(); col++ )
//		{
//			//printf( "%i,", oMatrix( row, col ) );
//			check__PrintValue_to_File( oMatrix[iIndex] );
//			iIndex++;
//		} 
//		printf( "\n" );
//	} 
//}

/* This function prints the data contained in the CMatrix object to a file. */
void check__PrintValue_to_File(float Value, FILE *fpTest)
{
	fprintf(fpTest, "%f\t\t", Value);
}

void check__PrintValue_to_File(int Value, FILE *fpTest)
{
	fprintf(fpTest, "%i\t\t", Value);
}

void check__PrintValue_to_File(unsigned int Value, FILE *fpTest)
{
	fprintf(fpTest, "%i\t\t", Value);
}

void check__PrintValue_to_File(short Value, FILE *fpTest)
{
	fprintf(fpTest, "%i\t\t", Value);
}

void check__PrintValue_to_File(char Value, FILE *fpTest)
{
	fprintf(fpTest, "%i\t\t", Value);
}

/* This function prints the data contained in the CMatrix object to console. */
void check__PrintValue_to_console(float Value)
{	
	std::cout << Value << "\t\t"; 
}

void check__PrintValue_to_console(int Value)
{
	std::cout << Value << "\t\t"; 
}

void check__PrintValue_to_console(short Value)
{
	std::cout << Value << "\t\t"; 
}

void check__PrintValue_to_console(char Value)
{
	std::cout << Value << "\t\t"; 
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

		printf("\n");
	} 

	printf("\n\n");
}

void check_float_ArrayPrint_to_File(int rows, int cols, const float32 *Array, FILE *fpTest)
{
	int  iIndex= 0;
	for( int row=0; row<rows; row++ )
	{
		for( int col=0; col<cols; col++ )
		{            
			check__PrintValue_to_File(Array[iIndex], fpTest);
			iIndex++;
		}

		fprintf(fpTest, "\n");
	} 

	fprintf(fpTest, "\n");
}

void check_int_ArrayPrint_to_File(int rows, int cols, const sint32 *Array, FILE *fpTest)
{
	int  iIndex= 0;
	for( int row=0; row<rows; row++ )
	{
		for( int col=0; col<cols; col++ )
		{            
			check__PrintValue_to_File(Array[iIndex], fpTest);
			iIndex++;
		}

		fprintf(fpTest, "\n");
	} 

	fprintf(fpTest, "\n");
}

void check_short_ArrayPrint_to_File(int rows, int cols, const sint16 *Array, FILE *fpTest)
{
	int  iIndex= 0;
	for( int row=0; row<rows; row++ )
	{
		for( int col=0; col<cols; col++ )
		{            
			check__PrintValue_to_File(Array[iIndex], fpTest);
			iIndex++;
		}

		fprintf(fpTest, "\n");
	} 

	fprintf(fpTest, "\n");
}

void check_char_ArrayPrint_to_File(int rows, int cols, const sint8 *Array, FILE *fpTest)
{
	int  iIndex= 0;
	for( int row=0; row<rows; row++ )
	{
		for( int col=0; col<cols; col++ )
		{            
			check__PrintValue_to_File(Array[iIndex], fpTest);
			iIndex++;
		}

		fprintf(fpTest, "\n");
	} 

	fprintf(fpTest, "\n");
}

void check_float_ArrayPrint_to_console(int rows, int cols, const float32 *Array, FILE *fpTest)
{
	int  iIndex= 0;
	for( int row=0; row<rows; row++ )
	{
		for( int col=0; col<cols; col++ )
		{            
			check__PrintValue_to_File(Array[iIndex], fpTest);
			iIndex++;
		}

		fprintf(fpTest, "\n");
	} 

	fprintf(fpTest, "\n");
}

void check_int_ArrayPrint_to_console(int rows, int cols, const sint32 *Array, FILE *fpTest)
{
	int  iIndex= 0;
	for( int row=0; row<rows; row++ )
	{
		for( int col=0; col<cols; col++ )
		{            
			check__PrintValue_to_File(Array[iIndex], fpTest);
			iIndex++;
		}

		fprintf(fpTest, "\n");
	} 

	fprintf(fpTest, "\n");
}

void check_short_ArrayPrint_to_console(int rows, int cols, const sint16 *Array, FILE *fpTest)
{
	int  iIndex= 0;
	for( int row=0; row<rows; row++ )
	{
		for( int col=0; col<cols; col++ )
		{            
			check__PrintValue_to_File(Array[iIndex], fpTest);
			iIndex++;
		}

		fprintf(fpTest, "\n");
	} 

	fprintf(fpTest, "\n");
}

void check_char_ArrayPrint_to_console(int rows, int cols, const sint8 *Array, FILE *fpTest)
{
	int  iIndex= 0;
	for( int row=0; row<rows; row++ )
	{
		for( int col=0; col<cols; col++ )
		{            
			check__PrintValue_to_File(Array[iIndex], fpTest);
			iIndex++;
		}

		fprintf(fpTest, "\n");
	} 

	fprintf(fpTest, "\n");
}


/* Global data */
/* None */

/* Expected variables for global data */
/* None */

/* This function initialises global data to default values. This function       */
/* is called by every Test Case so must not contain Test Case specific settings */
static void initialise_global_data(){
	/* No global data */
}

/* This function copies the global data settings into expected variables for */
/* use in check_global_data(). It is called by every Test Case so must not   */
/* contain Test Case specific settings.                                      */
static void initialise_expected_global_data(){
	/* No global data */
}

/* This function checks global data against the expected values. */
static void check_global_data()
{
	std::cout << "Status ---> PASS\n\n"; 
	fprintf(fpTest, "Status ---> PASS\n\n");
}
/* global data declaration */
float32 array1[4] = { 1.f, 2.f, 3.f, 4.f};
float32 array2[4] = { 0.f, 0.f, 0.f, 0.f};
float32 f_racMatrix[64]  = {   1.f,  1.f,  1.f, 1.f,  1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,  2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,  3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f,  4.f,  4.f,  4.f, 4.f,
				5.f,  5.f,  5.f, 5.f,  5.f,  5.f,  5.f, 5.f,
				6.f,  6.f,  6.f, 6.f,  6.f,  6.f,  6.f, 6.f,
				7.f,  7.f,  7.f, 7.f,  7.f,  7.f,  7.f, 7.f,
                8.f,  8.f,  8.f, 8.f,  8.f,  8.f,  8.f, 8.f
			};

/*****************************************************************************/
/* Test class declaration                                                    */
/*****************************************************************************/
class TEST_CLASS_MATRIX
{
public:
	void run_tests_matrix();
	void test_CML_CMatrix_Constructor(int);	
	void test_operatormultiply(int);
	void test_operatorassignment(int);
	void test_operatoraddandassign(int);
	void test_operatoraddition(int);
	void test_operatorsubandassign(int);
	void test_operatorsubtraction(int);
	void test_operatornegate(int);
	void test_operatormultiplyassign(int);
	void test_operatormultiplyassign_with_constant(int);
	void test_operatordivideassign_with_constant(int);
	void test_operatorAddassign_with_constant(int);
	void test_operatorsubtractassign_with_constant(int);
	void test_operatormultiply_with_constant(int);
	void test_operatordivide_with_constant(int);
	void test_operatorAdd_with_constant(int);
	void test_operatorsubtract_with_constant(int);
	void test_getCholesky(int);
	void test_getLowTriaSqr(int);
	void test_getUppTriaSqr(int);
	void test_getAlmostEqualRelativeAndAbs(int);
	void test_getLowTriaInverse(int);
	void test_invert_NXN(int);
	void test_trnspMul(int);
	void test_mulTrnsp(int);
	void test_mulSym(int);
	void test_transpose(int);
	void test_setIdentity(int doIt);
	void test_CML_STL_add(int doIt);
	void test_CML_STL_sub(int doIt);
	void test_CML_STL_mul(int doIt);
};

/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_stl_matrix(void)
{
	TEST_CLASS_MATRIX test_object;

#ifdef ENABLE_PROFILER
	start_clock = get_clock();

	stop_clock = get_clock();

	overhead = stop_clock - start_clock;
#endif /* #ifdef ENABLE_PROFILER */

	std::cout << "******** Start Testing: Matrix Library functions ********\n\n";
	fprintf(fpTest, "******** Start Testing: Matrix Library functions ********\n\n");

	test_object.run_tests_matrix();

	std::cout << "End of Testing: Matrix Library functions\n\n";
	fprintf(fpTest, "End of Testing: Matrix Library functions\n\n");

	return ;
}

/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS_MATRIX::run_tests_matrix()
{
	test_CML_STL_sub(1);
	test_CML_STL_add(1);
	test_CML_STL_mul(1);
	test_operatorsubtraction(1);
	test_operatoraddition(1);
	test_CML_CMatrix_Constructor(1);
	test_operatorassignment(1);
	test_operatoraddandassign(1);
	test_operatorsubandassign(1);
	test_operatornegate(1);	
	test_operatormultiplyassign(1);
	test_operatormultiply(1);
	test_operatormultiplyassign_with_constant(1);
	test_operatordivideassign_with_constant(1);
	test_operatorAddassign_with_constant(1);
	test_operatorsubtractassign_with_constant(1);
	test_operatormultiply_with_constant(1);
	test_operatordivide_with_constant(1);
	test_operatorAdd_with_constant(1);
	test_operatorsubtract_with_constant(1);
	test_setIdentity(1);
	test_transpose(1);
	test_mulSym(1);
	test_mulTrnsp(1);
	test_trnspMul(1);
	test_invert_NXN(1);
	test_getCholesky(1);
	test_getLowTriaInverse(1);
	test_getLowTriaSqr(1);
	test_getUppTriaSqr(1);	
}

/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/


void TEST_CLASS_MATRIX::test_CML_CMatrix_Constructor(int doIt)
{

	std::cout << "START ---> test_CML_CMatrix_Constructor\n\n";		
	//fprintf(fpTest, "START ---> test_CML_CMatrix_Constructor\n\n");

	//fprintf(fpTest, "Function Name ---> CMatrix<int,3,3,false>() \n\n");

	if (doIt) 
	{
		{
		std::cout << "START ---> test_CML_CMatrix_Constructor_001\n\n";		
		fprintf(fpTest, "START ---> test_CML_CMatrix_Constructor_001\n\n");

		/* Test Case data declarations */
		cml::CMatrix<int,3,3,false> *testObj;

		/* Call SUT */
		testObj = new cml::CMatrix<int,3,3,false>();

		std::cout << "END ---> test_CML_CMatrix_Constructor_001\n\n";
		fprintf(fpTest, "END ---> test_CML_CMatrix_Constructor_001\n\n");
		}
		{
		std::cout << "START ---> test_CML_CMatrix_Constructor_002\n\n";		
		fprintf(fpTest, "START ---> test_CML_CMatrix_Constructor_002\n\n");

		/* Test case data declarations */
		const uint32 TEST_aiData123[] = {1,2,3,4};
		const cml::CArrayStorage<const uint32 ,4, true> TestArray( TEST_aiData123 );
		cml::CMatrix<const uint32,2,2,true> *testObj;

		/* Call SUT */
		testObj = new cml::CMatrix<const uint32,2,2,true>(TestArray);

		/* Test Case checks */
		cml::boolean_t returnValue;

		/* Checks on global data */			
		returnValue = (*testObj).getAlmostEqualRelativeAndAbs( (cml::CMatrix<const uint32,2,2,true>) TestArray);

		if(returnValue)
		{
			check_global_data();
		}
		else
		{
			std::cout << "Status ---> FAIL\n\n";    
			fprintf(fpTest, "Status ---> FAIL\n\n");
		}

		std::cout << "END ---> test_CML_CMatrix_Constructor_002\n\n";
		fprintf(fpTest, "END ---> test_CML_CMatrix_Constructor_002\n\n");
		}
	}
	std::cout << "END ---> test_CML_CMatrix_Constructor\n\n";
	fprintf(fpTest, "END ---> test_CML_CMatrix_Constructor\n\n");
}


void TEST_CLASS_MATRIX::test_operatorassignment(int doIt)
{

	std::cout << "START ---> test_operatorassignment\n\n";		
	fprintf(fpTest, "START ---> test_operatorassignment\n\n");

	std::cout << "Function Name ---> operator=() \n\n";
	fprintf(fpTest, "Function Name ---> operator=() \n\n");	

	if (doIt) 
	{
		/* Both inp_MT and rhs_MT matrices are with external memory with option EXT_MEM=true */
		{
			std::cout << "Test Case ---> Copy Matrix of type float --> A = B\n\n";		
			fprintf(fpTest, "Test Case ---> Copy Matrix of type float --> A = B\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> Temp_rhs_MT(array1,4);
			cml::CMatrix<float32, 2, 2, false> Temp_inp_MT(array2,4);
			cml::CMatrix<float32, 2, 2, true> rhs_MT(Temp_rhs_MT);
			cml::CMatrix<float32, 2, 2, true> inp_MT(Temp_inp_MT);
			cml::CMatrix<float32, 2, 2, true> expected_inp_MT(Temp_rhs_MT);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");				

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");			

			check__vMatrixPrint_to_console< float32, 2, 2, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( inp_MT, fpTest);			

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");			

/*			check__vMatrixPrint_to_console < float32, 2, 2, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( rhs_MT, fpTest);*/	

			check__vMatrixPrint_to_console( rhs_MT);
			check__vMatrixPrint_to_File( rhs_MT, fpTest);

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");			

			check__vMatrixPrint_to_console< float32, 2, 2, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( rhs_MT, fpTest);			

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");			

			check__vMatrixPrint_to_console< float32, 2, 2, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( rhs_MT, fpTest);		

			/* Set expected values for global data checks */
			initialise_expected_global_data();

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT = rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";		
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");			

			check__vMatrixPrint_to_console< float32, 2, 2, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( inp_MT, fpTest);			

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");			

			check__vMatrixPrint_to_console< float32, 2, 2, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( rhs_MT, fpTest);
			
			/* Test Case checks */

			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
			
		}
#if EXT_MEM_TEST_FAIL  
		/* This test case is giving compilation error.
		   'cml::CArrayStorage<T,SIZE,EXT_MEM>::operator =' : cannot convert parameter 1 from 'const cml::CArray<T,SIZE,EXT_MEM>' to 'const cml::CArrayStorage<T,SIZE,EXT_MEM> &'
		   From the file cml_stl_array.h at line 758
		*/
		/* inp_MT matrix is with internal memory with option EXT_MEM=false and rhs_MT matrix is with external memory with option EXT_MEM=true */
		{
			std::cout << "Test Case ---> Copy Matrix of type float --> A = B\n\n";		
			fprintf(fpTest, "Test Case ---> Copy Matrix of type float --> A = B\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> Temp_rhs_MT(array1,4);
			cml::CMatrix<float32, 2, 2, false> Temp_inp_MT(array2,4);
			cml::CMatrix<float32, 2, 2, true> rhs_MT(Temp_rhs_MT);
			cml::CMatrix<float32, 2, 2, false> inp_MT(Temp_inp_MT);
			cml::CMatrix<float32, 2, 2, false> expected_inp_MT(Temp_inp_MT);

		/*	expected_inp_MT(0,0) = 1.f;
			expected_inp_MT(0,1) = 2.f;
			expected_inp_MT(1,0) = 3.f;
			expected_inp_MT(1,1) = 4.f;*/


			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");				

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");			

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);			

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");			

/*			check__vMatrixPrint_to_console < float32, 2, 2, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( rhs_MT, fpTest);*/	

			check__vMatrixPrint_to_console( rhs_MT);
			check__vMatrixPrint_to_File( rhs_MT, fpTest);

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");			

			check__vMatrixPrint_to_console< float32, 2, 2, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( rhs_MT, fpTest);			

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");			

			check__vMatrixPrint_to_console< float32, 2, 2, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( rhs_MT, fpTest);		

			/* Set expected values for global data checks */
			initialise_expected_global_data();

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT = rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";		
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");			

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);			

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");			

			check__vMatrixPrint_to_console< float32, 2, 2, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( rhs_MT, fpTest);
			
			/* Test Case checks */

			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
			
		}
#endif // EXT_MEM_TEST_FAIL

		/* inp_MT matrix is with external memory with option EXT_MEM=true and rhs_MT matrix is with internal memory with option EXT_MEM=false */
		{
			std::cout << "Test Case ---> Copy Matrix of type float --> A = B\n\n";		
			fprintf(fpTest, "Test Case ---> Copy Matrix of type float --> A = B\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> Temp_rhs_MT(array1,4);
			cml::CMatrix<float32, 2, 2, false> Temp_inp_MT(array2,4);
			cml::CMatrix<float32, 2, 2, false> rhs_MT(Temp_rhs_MT);
			cml::CMatrix<float32, 2, 2, true> inp_MT(Temp_inp_MT);
			cml::CMatrix<float32, 2, 2, true> expected_inp_MT(Temp_rhs_MT);

/*          expected_inp_MT(0,0) = 1.f;
			expected_inp_MT(0,1) = 2.f;
			expected_inp_MT(1,0) = 3.f;
			expected_inp_MT(1,1) = 4.f;
*/

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");				

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");			

			check__vMatrixPrint_to_console< float32, 2, 2, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");			

/*			check__vMatrixPrint_to_console < float32, 2, 2, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( rhs_MT, fpTest);*/	

			check__vMatrixPrint_to_console( rhs_MT);
			check__vMatrixPrint_to_File( rhs_MT, fpTest);

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");			

			check__vMatrixPrint_to_console< float32, 2, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( rhs_MT, fpTest);			

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");			

			check__vMatrixPrint_to_console< float32, 2, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( rhs_MT, fpTest);		

			/* Set expected values for global data checks */
			initialise_expected_global_data();

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT = rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";		
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");			

			check__vMatrixPrint_to_console< float32, 2, 2, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");			

			check__vMatrixPrint_to_console< float32, 2, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( rhs_MT, fpTest);
			
			/* Test Case checks */

			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
			
		}

		{
			std::cout << "Test Case ---> Copy Matrix of type float --> A = B\n\n";
			fprintf(fpTest, "Test Case ---> Copy Matrix of type float --> A = B\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> rhs_MT;
			cml::CMatrix<float32, 2, 2, false> inp_MT;
			cml::CMatrix<float32, 2, 2, false> expected_inp_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 0;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 0;

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 0;
			rhs_MT(1,0) = 0;
			rhs_MT(1,1) = 1;

			expected_inp_MT(0,0) = 1;
			expected_inp_MT(0,1) = 0;
			expected_inp_MT(1,0) = 0;
			expected_inp_MT(1,1) = 1;


			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);			

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");			

			check__vMatrixPrint_to_console< float32, 2, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( rhs_MT, fpTest);			

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");			

			check__vMatrixPrint_to_console< float32, 2, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( rhs_MT, fpTest);			

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");			

			check__vMatrixPrint_to_console< float32, 2, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( rhs_MT, fpTest);		

			/* Set expected values for global data checks */
			initialise_expected_global_data();

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT = rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";		
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");			

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);			

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");			

			check__vMatrixPrint_to_console< float32, 2, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( rhs_MT, fpTest);	
			
			/* Test Case checks */

			cml::boolean_t returnValue;

			/* Checks on global data */
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
			
		}

		{
			std::cout << "Test Case ---> Copy Matrix of type float --> A = B \n\n";		
			fprintf(fpTest, "Test Case ---> Copy Matrix of type float --> A = B \n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			};   

			cml::CMatrix<float32, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, false> expected_inp_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, false> inp_MT;		

			/* Set global data */
			initialise_global_data();

			inp_MT.fill(0);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( rhs_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( rhs_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT =  rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( rhs_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		{
			std::cout << "Test Case ---> Copy Matrix of type int --> A = B \n\n";		
			fprintf(fpTest, "Test Case ---> Copy Matrix of type int --> A = B \n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const sint32 racMatrix[]  = {   1,  1,  1, 1,
				2,  2,  2, 2,
				3,  3,  3, 3,
				4,  4,  4, 4
			};   

			cml::CMatrix<sint32, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<sint32, 4, 4, false> expected_inp_MT(racMatrix);
			cml::CMatrix<sint32, 4, 4, false> inp_MT;		

			/* Set global data */
			initialise_global_data();

			inp_MT.fill(0);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( rhs_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( rhs_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT =  rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( rhs_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		{
			std::cout << "Test Case ---> Copy Matrix of type short --> A = B \n\n";		
			fprintf(fpTest, "Test Case ---> Copy Matrix of type short --> A = B \n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const sint16 racMatrix[]  = {   1,  1,  1, 1,
				2,  2,  2, 2,
				3,  3,  3, 3,
				4,  4,  4, 4
			};   

			cml::CMatrix<sint16, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<sint16, 4, 4, false> expected_inp_MT(racMatrix);
			cml::CMatrix<sint16, 4, 4, false> inp_MT;		

			/* Set global data */
			initialise_global_data();

			inp_MT.fill(0);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( rhs_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( rhs_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT =  rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( rhs_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		{
			std::cout << "Test Case ---> Copy Matrix of type char --> A = B \n\n";		
			fprintf(fpTest, "Test Case ---> Copy Matrix of type char --> A = B \n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const sint8 racMatrix[]  = {   1,  1,  1, 1,
				2,  2,  2, 2,
				3,  3,  3, 3,
				4,  4,  4, 4
			};   

			cml::CMatrix<sint8, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<sint8, 4, 4, false> expected_inp_MT(racMatrix);
			cml::CMatrix<sint8, 4, 4, false> inp_MT;		

			/* Set global data */
			initialise_global_data();

			inp_MT.fill(0);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( rhs_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( rhs_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT =  rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( rhs_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}
	}
	std::cout << "END ---> test_operatorassignment\n\n";
	fprintf(fpTest, "END ---> test_operatorassignment\n\n");
}


void TEST_CLASS_MATRIX::test_operatoraddandassign(int doIt)
{

	std::cout << "START ---> test_operatoraddandassign\n\n";		
	fprintf(fpTest, "START ---> test_operatoraddandassign\n\n");

	fprintf(fpTest, "Function Name ---> operator+=() \n\n");
	if (doIt) 
	{

	/* inp_MT matrix is with internal memory with option EXT_MEM=false and rhs_MT matrix is with external memory with option EXT_MEM=true */
		{

			std::cout << "Test Case ---> Add Matrices of type float --> A += B, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type float --> A += B, assign to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			 float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			};  

			 float expected_result[]  =    {   2.f,  2.f,  2.f, 2.f,
				4.f,  4.f,  4.f, 4.f,
				6.f,  6.f,  6.f, 6.f,
				8.f,  8.f,  8.f, 8.f
			};

			cml::CMatrix<float32, 4, 4, true> rhs_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, false> expected_inp_MT(expected_result);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";		
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";		
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( expected_inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( expected_inp_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT += rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);
		
			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

     /* inp_MT matrix is with external memory with option EXT_MEM=true and rhs_MT matrix is with internal memory with option EXT_MEM=false */
		{

			std::cout << "Test Case ---> Add Matrices of type float --> A += B, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type float --> A += B, assign to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			 float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			};  

			 float expected_result[]  =    {   2.f,  2.f,  2.f, 2.f,
				4.f,  4.f,  4.f, 4.f,
				6.f,  6.f,  6.f, 6.f,
				8.f,  8.f,  8.f, 8.f
			};

			cml::CMatrix<float32, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, true> inp_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, true> expected_inp_MT(expected_result,16);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( inp_MT, fpTest);

			std::cout << "input2 = \n";		
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";		
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( expected_inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( expected_inp_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT += rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( inp_MT, fpTest);
		
			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		/* inp_MT matrix is with external memory with option EXT_MEM=true and rhs_MT matrix is also external memory with option EXT_MEM=true */
		{

			std::cout << "Test Case ---> Add Matrices of type float --> A += B, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type float --> A += B, assign to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			 float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			};  

			 float expected_result[]  =    {   2.f,  2.f,  2.f, 2.f,
				4.f,  4.f,  4.f, 4.f,
				6.f,  6.f,  6.f, 6.f,
				8.f,  8.f,  8.f, 8.f
			};

			cml::CMatrix<float32, 4, 4, true> rhs_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, true> inp_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, true> expected_inp_MT(expected_result,16);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( inp_MT, fpTest);

			std::cout << "input2 = \n";		
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";		
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( expected_inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( expected_inp_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT += rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( inp_MT, fpTest);
		
			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}


		{

			std::cout << "Test Case ---> Add Matrices of type float --> A += B, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type float --> A += B, assign to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			};  

			const float expected_result[]  =    {   2.f,  2.f,  2.f, 2.f,
				4.f,  4.f,  4.f, 4.f,
				6.f,  6.f,  6.f, 6.f,
				8.f,  8.f,  8.f, 8.f
			};

			cml::CMatrix<float32, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, false> expected_inp_MT(expected_result);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";		
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";		
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( expected_inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( expected_inp_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT += rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);
		
			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{

			std::cout << "Test Case ---> Add Matrices of type int --> A += B, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type int --> A += B, assign to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const sint32 racMatrix[]  = {   1,  1,  1, 1,
				2,  2,  2, 2,
				3,  3,  3, 3,
				4,  4,  4, 4
			};  

			const sint32 expected_result[]  =    {   2,  2,  2, 2,
				4,  4,  4, 4,
				6,  6,  6, 6,
				8,  8,  8, 8
			};

			cml::CMatrix<sint32, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<sint32, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<sint32, 4, 4, false> expected_inp_MT(expected_result);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";		
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";		
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( expected_inp_MT);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( expected_inp_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT += rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( inp_MT, fpTest);
		
			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{

			std::cout << "Test Case ---> Add Matrices of type short --> A += B, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type short --> A += B, assign to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const sint16 racMatrix[]  = {   1,  1,  1, 1,
				2,  2,  2, 2,
				3,  3,  3, 3,
				4,  4,  4, 4
			};  

			const sint16 expected_result[]  =    {   2,  2,  2, 2,
				4,  4,  4, 4,
				6,  6,  6, 6,
				8,  8,  8, 8
			};

			cml::CMatrix<sint16, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<sint16, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<sint16, 4, 4, false> expected_inp_MT(expected_result);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";		
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";		
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( expected_inp_MT);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( expected_inp_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT += rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( inp_MT, fpTest);
		
			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{

			std::cout << "Test Case ---> Add Matrices of type short --> A += B, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type short --> A += B, assign to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const sint8 racMatrix[]  = {   1,  1,  1, 1,
				2,  2,  2, 2,
				3,  3,  3, 3,
				4,  4,  4, 4
			};  

			const sint8 expected_result[]  =    {   2,  2,  2, 2,
				4,  4,  4, 4,
				6,  6,  6, 6,
				8,  8,  8, 8
			};

			cml::CMatrix<sint8, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<sint8, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<sint8, 4, 4, false> expected_inp_MT(expected_result);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";		
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";		
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( expected_inp_MT);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( expected_inp_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT += rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( inp_MT, fpTest);
		
			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

	}

	std::cout << "END ---> test_operatoraddandassign\n\n";
	fprintf(fpTest, "END ---> test_operatoraddandassign\n\n");
}

void TEST_CLASS_MATRIX::test_operatoraddition(int doIt)
{
	std::cout << "START ---> test_operatoraddition\n\n";		
	fprintf(fpTest, "START ---> test_operatoraddition\n\n");

	std::cout << "Function Name ---> operator+() \n\n";
	fprintf(fpTest, "Function Name ---> operator+() \n\n");
	if (doIt) 
	{
		/* result = inp_MT +rhs_MT
		   result ---> internal memory with EXT_MEM=false
		   inp_MT ---> internal memory with EXT_MEM=false
		   rhs_MT ---> external memory with EXT_MEM=true
		*/
		
		{

			std::cout << "Test Case ---> Add Matrices of type float --> result = A + B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type float --> result = A + B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			};  

			const float expected_res[]  =    {   2.f,  2.f,  2.f, 2.f,
				4.f,  4.f,  4.f, 4.f,
				6.f,  6.f,  6.f, 6.f,
				8.f,  8.f,  8.f, 8.f
			};

			cml::CMatrix<const float32, 4, 4, true> rhs_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, false> result;
			cml::CMatrix<float32, 4, 4, false> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File<const float32, 4, 4, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( expected_result);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT + rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File< const float32, 4, 4, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		/* result = inp_MT +rhs_MT
		   result ---> internal memory with EXT_MEM=false
		   inp_MT ---> external memory with EXT_MEM=true
		   rhs_MT ---> external memory with EXT_MEM=true
		*/
		
		{

			std::cout << "Test Case ---> Add Matrices of type float --> result = A + B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type float --> result = A + B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			};  

			const float expected_res[]  =    {   2.f,  2.f,  2.f, 2.f,
				4.f,  4.f,  4.f, 4.f,
				6.f,  6.f,  6.f, 6.f,
				8.f,  8.f,  8.f, 8.f
			};

			cml::CMatrix<const float32, 4, 4, true> rhs_MT(racMatrix,16);
			cml::CMatrix<const float32, 4, 4, true> inp_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, false> result;
			cml::CMatrix<float32, 4, 4, false> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true>( inp_MT);
			check__vMatrixPrint_to_File<const float32, 4, 4, true>( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File<const float32, 4, 4, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( expected_result);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT + rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true>( inp_MT);
			check__vMatrixPrint_to_File<const float32, 4, 4, true>( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File< const float32, 4, 4, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		/* result = inp_MT +rhs_MT
		   result ---> external memory with EXT_MEM=true
		   inp_MT ---> internal memory with EXT_MEM=false
		   rhs_MT ---> external memory with EXT_MEM=true
		*/
		
		{

			std::cout << "Test Case ---> Add Matrices of type float --> result = A + B, without assigning to this\n\n";
			fprintf(fpTest, "Test Case ---> Add Matrices of type float --> result = A + B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			};  

		   float temp[]  = {   0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f
			};

			float expected_res[]  =    {   2.f,  2.f,  2.f, 2.f,
				4.f,  4.f,  4.f, 4.f,
				6.f,  6.f,  6.f, 6.f,
				8.f,  8.f,  8.f, 8.f
			};

			cml::CMatrix<const float32, 4, 4, true> rhs_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, true> result(temp,16);
			cml::CMatrix<float32, 4, 4, true> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			//result.fill(4.0);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1(inp_MT) = \n";
			fprintf(fpTest, "input1(inp_MT) = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 (rhs_MT) = \n";
			fprintf(fpTest, "input2(rhs_MT) = \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File<const float32, 4, 4, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( expected_result);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT + rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File< const float32, 4, 4, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		/* result = inp_MT +rhs_MT
		   result ---> external memory with EXT_MEM=true
		   inp_MT ---> external memory with EXT_MEM=true
		   rhs_MT ---> external memory with EXT_MEM=true
		*/
		
		{

			std::cout << "Test Case ---> Add Matrices of type float --> result = A + B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type float --> result = A + B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			}; 

	        float temp[]  = {   0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f
			};

			float expected_res[]  =    {   2.f,  2.f,  2.f, 2.f,
				4.f,  4.f,  4.f, 4.f,
				6.f,  6.f,  6.f, 6.f,
				8.f,  8.f,  8.f, 8.f
			};

			cml::CMatrix<const float32, 4, 4, true> rhs_MT(racMatrix,16);
			cml::CMatrix<const float32, 4, 4, true> inp_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, true> result(temp,16);
			cml::CMatrix<float32, 4, 4, true> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			//result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1(inp_MT) = \n";
			fprintf(fpTest, "input1(inp_MT) = \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true>( inp_MT);
			check__vMatrixPrint_to_File<const float32, 4, 4, true>( inp_MT, fpTest);

			std::cout << "input2(rhs_MT) = \n";
			fprintf(fpTest, "input2(rhs_MT) = \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File<const float32, 4, 4, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( expected_result);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT + rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1(inp_MT) = \n";
			fprintf(fpTest, "input1 (inp_MT)= \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true>( inp_MT);
			check__vMatrixPrint_to_File<const float32, 4, 4, true>( inp_MT, fpTest);

			std::cout << "input2 (rhs_MT) = \n";
			fprintf(fpTest, "input2 (rhs_MT)= \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File< const float32, 4, 4, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		/* result = inp_MT +rhs_MT
		   result ---> external memory with EXT_MEM=true
		   inp_MT ---> internal memory with EXT_MEM=false
		   rhs_MT ---> internal memory with EXT_MEM=false
		*/
		
		{

			std::cout << "Test Case ---> Add Matrices of type float --> result = A + B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type float --> result = A + B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			}; 

	        float temp[]  = {   0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f
			};

			float expected_res[]  =    {   2.f,  2.f,  2.f, 2.f,
				4.f,  4.f,  4.f, 4.f,
				6.f,  6.f,  6.f, 6.f,
				8.f,  8.f,  8.f, 8.f
			};

			cml::CMatrix< float32, 4, 4, false> rhs_MT(racMatrix,16);
			cml::CMatrix< float32, 4, 4, false> inp_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, true> result(temp,16);
			cml::CMatrix<float32, 4, 4, true> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			//result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1(inp_MT) = \n";
			fprintf(fpTest, "input1(inp_MT) = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false>( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false>( inp_MT, fpTest);

			std::cout << "input2(rhs_MT) = \n";
			fprintf(fpTest, "input2(rhs_MT) = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( expected_result);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT + rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1(inp_MT) = \n";
			fprintf(fpTest, "input1 (inp_MT)= \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false>( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false>( inp_MT, fpTest);

			std::cout << "input2 (rhs_MT) = \n";
			fprintf(fpTest, "input2 (rhs_MT)= \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File<  float32, 4, 4, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}


		{

			std::cout << "Test Case ---> Add Matrices of type float --> result = A + B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type float --> result = A + B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			};  

			const float expected_res[]  =    {   2.f,  2.f,  2.f, 2.f,
				4.f,  4.f,  4.f, 4.f,
				6.f,  6.f,  6.f, 6.f,
				8.f,  8.f,  8.f, 8.f
			};

			cml::CMatrix<float32, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, false> result;
			cml::CMatrix<float32, 4, 4, false> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( result, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( expected_result);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT + rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{

			std::cout << "Test Case ---> Add Matrices of type int --> result = A + B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type int --> result = A + B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const sint32 racMatrix[]  = {   1,  1,  1, 1,
				2,  2,  2, 2,
				3,  3,  3, 3,
				4,  4,  4, 4
			};  

			const sint32 expected_res[]  =    {   2,  2,  2, 2,
				4,  4,  4, 4,
				6,  6,  6, 6,
				8,  8,  8, 8
			};

			cml::CMatrix<sint32, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<sint32, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<sint32, 4, 4, false> result;
			cml::CMatrix<sint32, 4, 4, false> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( result);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( result, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( result);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( expected_result);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT + rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( result);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{

			std::cout << "Test Case ---> Add Matrices of type short --> result = A + B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type short --> result = A + B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const sint16 racMatrix[]  = {   1,  1,  1, 1,
				2,  2,  2, 2,
				3,  3,  3, 3,
				4,  4,  4, 4
			};  

			const sint16 expected_res[]  =    {   2,  2,  2, 2,
				4,  4,  4, 4,
				6,  6,  6, 6,
				8,  8,  8, 8
			};

			cml::CMatrix<sint16, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<sint16, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<sint16, 4, 4, false> result;
			cml::CMatrix<sint16, 4, 4, false> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( result);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( result, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( result);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( expected_result);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT + rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( result);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{

			std::cout << "Test Case ---> Add Matrices of type char --> result = A + B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type char --> result = A + B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const sint8 racMatrix[]  = {   1,  1,  1, 1,
				2,  2,  2, 2,
				3,  3,  3, 3,
				4,  4,  4, 4
			};  

			const sint8 expected_res[]  =    {   2,  2,  2, 2,
				4,  4,  4, 4,
				6,  6,  6, 6,
				8,  8,  8, 8
			};

			cml::CMatrix<sint8, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<sint8, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<sint8, 4, 4, false> result;
			cml::CMatrix<sint8, 4, 4, false> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( result);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( result, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( result);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( expected_result);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT + rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( result);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}
	}
	std::cout << "END ---> test_operatoraddition\n\n";
	fprintf(fpTest, "END ---> test_operatoraddition\n\n");
}


void TEST_CLASS_MATRIX::test_CML_STL_add(int doIt)
{
	std::cout << "START ---> test_CML_STL_add\n\n";
	fprintf(fpTest, "START ---> test_CML_STL_add\n\n");

	std::cout << "Function Name ---> CML_STL_add() \n\n";
	fprintf(fpTest, "Function Name ---> CML_STL_add() \n\n");
	if (doIt) 
	{
        /* result.CML_STL_add(inp_MT , rhs_MT) , result (EXT_MEM=false), inp_MT (EXT_MEM=false)  and rhs_MT (EXT_MEM=true) */
		{
			std::cout << "Test Case ---> Add Matrices of type float --> result.CML_STL_add(A,B), and updates to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Add Matrices of type float -->result.CML_STL_add(A,B), and updates to result (this)\n\n");

			std::cout << "Data Dimension ---> 8X8\n\n";
			fprintf(fpTest, "Data Dimension ---> 8X8\n\n");

			/* Test Case data declarations */
			float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,  1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,  2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,  3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f,  4.f,  4.f,  4.f, 4.f,
				5.f,  5.f,  5.f, 5.f,  5.f,  5.f,  5.f, 5.f,
				6.f,  6.f,  6.f, 6.f,  6.f,  6.f,  6.f, 6.f,
				7.f,  7.f,  7.f, 7.f,  7.f,  7.f,  7.f, 7.f,
                8.f,  8.f,  8.f, 8.f,  8.f,  8.f,  8.f, 8.f
			};  

			const float expected_res[]  =    {   2.f,  2.f,  2.f, 2.f, 2.f,  2.f,  2.f, 2.f,
				4.f,  4.f,  4.f, 4.f, 4.f,  4.f,  4.f, 4.f,
				6.f,  6.f,  6.f, 6.f, 6.f,  6.f,  6.f, 6.f,
				8.f,  8.f,  8.f, 8.f, 8.f,  8.f,  8.f, 8.f,
				10.f, 10.f, 10.f, 10.f,10.f,10.f,10.f,10.f,
				12.f, 12.f, 12.f, 12.f,12.f,12.f,12.f,12.f,
				14.f, 14.f, 14.f, 14.f,14.f,14.f,14.f,14.f,
				16.f, 16.f, 16.f, 16.f,16.f,16.f,16.f,16.f
			};

			cml::CMatrix<float32, 8, 8, true> rhs_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, false> inp_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, false> result;
			cml::CMatrix<float32, 8, 8, false> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( expected_result);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            /* Call SUT */
           result.CML_STL_add(inp_MT , rhs_MT);


#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		 /* result.CML_STL_add(inp_MT , rhs_MT) , result (EXT_MEM=false), inp_MT (EXT_MEM= true)  and rhs_MT (EXT_MEM=false) */
		{
			std::cout << "Test Case ---> Add Matrices of type float --> result.CML_STL_add(A,B), and updates to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Add Matrices of type float -->result.CML_STL_add(A,B), and updates to result (this)\n\n");

			std::cout << "Data Dimension ---> 8X8\n\n";
			fprintf(fpTest, "Data Dimension ---> 8X8\n\n");

			/* Test Case data declarations */
			float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,  1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,  2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,  3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f,  4.f,  4.f,  4.f, 4.f,
				5.f,  5.f,  5.f, 5.f,  5.f,  5.f,  5.f, 5.f,
				6.f,  6.f,  6.f, 6.f,  6.f,  6.f,  6.f, 6.f,
				7.f,  7.f,  7.f, 7.f,  7.f,  7.f,  7.f, 7.f,
                8.f,  8.f,  8.f, 8.f,  8.f,  8.f,  8.f, 8.f
			};  

			const float expected_res[]  =    {   2.f,  2.f,  2.f, 2.f, 2.f,  2.f,  2.f, 2.f,
				4.f,  4.f,  4.f, 4.f, 4.f,  4.f,  4.f, 4.f,
				6.f,  6.f,  6.f, 6.f, 6.f,  6.f,  6.f, 6.f,
				8.f,  8.f,  8.f, 8.f, 8.f,  8.f,  8.f, 8.f,
				10.f, 10.f, 10.f, 10.f,10.f,10.f,10.f,10.f,
				12.f, 12.f, 12.f, 12.f,12.f,12.f,12.f,12.f,
				14.f, 14.f, 14.f, 14.f,14.f,14.f,14.f,14.f,
				16.f, 16.f, 16.f, 16.f,16.f,16.f,16.f,16.f
			};

			cml::CMatrix<float32, 8, 8, true> inp_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, false> rhs_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, false> result;
			cml::CMatrix<float32, 8, 8, false> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

		    check__vMatrixPrint_to_console< float32, 8, 8, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( inp_MT, fpTest);


			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( expected_result);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            /* Call SUT */
           result.CML_STL_add(inp_MT , rhs_MT);


#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

		    check__vMatrixPrint_to_console< float32, 8, 8, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( inp_MT, fpTest);


			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

/* result.CML_STL_add(inp_MT , rhs_MT) , result (EXT_MEM=false), inp_MT (EXT_MEM=true)  and rhs_MT (EXT_MEM=true) */
		{
			std::cout << "Test Case ---> Add Matrices of type float --> result.CML_STL_add(A,B), and updates to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Add Matrices of type float -->result.CML_STL_add(A,B), and updates to result (this)\n\n");

			std::cout << "Data Dimension ---> 8X8\n\n";
			fprintf(fpTest, "Data Dimension ---> 8X8\n\n");

			/* Test Case data declarations */
			 float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,  1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,  2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,  3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f,  4.f,  4.f,  4.f, 4.f,
				5.f,  5.f,  5.f, 5.f,  5.f,  5.f,  5.f, 5.f,
				6.f,  6.f,  6.f, 6.f,  6.f,  6.f,  6.f, 6.f,
				7.f,  7.f,  7.f, 7.f,  7.f,  7.f,  7.f, 7.f,
                8.f,  8.f,  8.f, 8.f,  8.f,  8.f,  8.f, 8.f
			};  

			const float expected_res[]  =    {   2.f,  2.f,  2.f, 2.f, 2.f,  2.f,  2.f, 2.f,
				4.f,  4.f,  4.f, 4.f, 4.f,  4.f,  4.f, 4.f,
				6.f,  6.f,  6.f, 6.f, 6.f,  6.f,  6.f, 6.f,
				8.f,  8.f,  8.f, 8.f, 8.f,  8.f,  8.f, 8.f,
				10.f, 10.f, 10.f, 10.f,10.f,10.f,10.f,10.f,
				12.f, 12.f, 12.f, 12.f,12.f,12.f,12.f,12.f,
				14.f, 14.f, 14.f, 14.f,14.f,14.f,14.f,14.f,
				16.f, 16.f, 16.f, 16.f,16.f,16.f,16.f,16.f
			};

			cml::CMatrix<const float32, 8, 8, true> rhs_MT(racMatrix);
			cml::CMatrix<const float32, 8, 8, true> inp_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, false> result;
			cml::CMatrix<float32, 8, 8, false> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			/*check__vMatrixPrint_to_console<const float32, 8, 8, true >( inp_MT);
			check__vMatrixPrint_to_File<const float32, 8, 8, true >( inp_MT, fpTest);
*/
			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< const float32, 8, 8, true >( rhs_MT);
			check__vMatrixPrint_to_File< const float32, 8, 8, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( expected_result);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            /* Call SUT */
           result.CML_STL_add(inp_MT , rhs_MT);


#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

		/*	check__vMatrixPrint_to_console<const float32, 8, 8, true >( inp_MT);
			check__vMatrixPrint_to_File<const float32, 8, 8, true >( inp_MT, fpTest);*/

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< const float32, 8, 8, true >( rhs_MT);
			check__vMatrixPrint_to_File< const float32, 8, 8, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}


/* result.CML_STL_add(inp_MT , rhs_MT) , result (EXT_MEM=true), inp_MT (EXT_MEM=false)  and rhs_MT (EXT_MEM=false) */
		{

			std::cout << "Test Case ---> Add Matrices of type float --> result.CML_STL_add(A,B), and updates to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Add Matrices of type float -->result.CML_STL_add(A,B), and updates to result (this)\n\n");

			std::cout << "Data Dimension ---> 8X8\n\n";
			fprintf(fpTest, "Data Dimension ---> 8X8\n\n");

			/* Test Case data declarations */
			 float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,  1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,  2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,  3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f,  4.f,  4.f,  4.f, 4.f,
				5.f,  5.f,  5.f, 5.f,  5.f,  5.f,  5.f, 5.f,
				6.f,  6.f,  6.f, 6.f,  6.f,  6.f,  6.f, 6.f,
				7.f,  7.f,  7.f, 7.f,  7.f,  7.f,  7.f, 7.f,
                8.f,  8.f,  8.f, 8.f,  8.f,  8.f,  8.f, 8.f
			};  

			  float expected_res[]  =    {   2.f,  2.f,  2.f, 2.f, 2.f,  2.f,  2.f, 2.f,
				4.f,  4.f,  4.f, 4.f, 4.f,  4.f,  4.f, 4.f,
				6.f,  6.f,  6.f, 6.f, 6.f,  6.f,  6.f, 6.f,
				8.f,  8.f,  8.f, 8.f, 8.f,  8.f,  8.f, 8.f,
				10.f, 10.f, 10.f, 10.f,10.f,10.f,10.f,10.f,
				12.f, 12.f, 12.f, 12.f,12.f,12.f,12.f,12.f,
				14.f, 14.f, 14.f, 14.f,14.f,14.f,14.f,14.f,
				16.f, 16.f, 16.f, 16.f,16.f,16.f,16.f,16.f
			};

			float32 f_res_temp[64]  = {   0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
                0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f
			};

			cml::CMatrix<float32, 8, 8, false> rhs_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, false> inp_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, true> result(f_res_temp);
			cml::CMatrix<float32, 8, 8, true> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( expected_result);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            /* Call SUT */
            result.CML_STL_add(inp_MT , rhs_MT);


#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

/* result.CML_STL_add(inp_MT , rhs_MT) , result (EXT_MEM=true), inp_MT (EXT_MEM=false)  and rhs_MT (EXT_MEM=true) */
		{
			std::cout << "Test Case ---> Add Matrices of type float --> result.CML_STL_add(A,B), and updates to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Add Matrices of type float -->result.CML_STL_add(A,B), and updates to result (this)\n\n");

			std::cout << "Data Dimension ---> 8X8\n\n";
			fprintf(fpTest, "Data Dimension ---> 8X8\n\n");

			/* Test Case data declarations */
			float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,  1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,  2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,  3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f,  4.f,  4.f,  4.f, 4.f,
				5.f,  5.f,  5.f, 5.f,  5.f,  5.f,  5.f, 5.f,
				6.f,  6.f,  6.f, 6.f,  6.f,  6.f,  6.f, 6.f,
				7.f,  7.f,  7.f, 7.f,  7.f,  7.f,  7.f, 7.f,
                8.f,  8.f,  8.f, 8.f,  8.f,  8.f,  8.f, 8.f
			};  

			float expected_res[]  =    {   2.f,  2.f,  2.f, 2.f, 2.f,  2.f,  2.f, 2.f,
				4.f,  4.f,  4.f, 4.f, 4.f,  4.f,  4.f, 4.f,
				6.f,  6.f,  6.f, 6.f, 6.f,  6.f,  6.f, 6.f,
				8.f,  8.f,  8.f, 8.f, 8.f,  8.f,  8.f, 8.f,
				10.f, 10.f, 10.f, 10.f,10.f,10.f,10.f,10.f,
				12.f, 12.f, 12.f, 12.f,12.f,12.f,12.f,12.f,
				14.f, 14.f, 14.f, 14.f,14.f,14.f,14.f,14.f,
				16.f, 16.f, 16.f, 16.f,16.f,16.f,16.f,16.f
			};

			float32 f_res_temp[64]  = {   0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
                0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f
			};

			cml::CMatrix<float32, 8, 8, true> rhs_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, false> inp_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, true> result(f_res_temp);
			cml::CMatrix<float32, 8, 8, true> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( expected_result);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            /* Call SUT */
           result.CML_STL_add(inp_MT , rhs_MT);


#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		/* result.CML_STL_add(inp_MT , rhs_MT) , result (EXT_MEM=true), inp_MT (EXT_MEM= true)  and rhs_MT (EXT_MEM=false) */
		{
			std::cout << "Test Case ---> Add Matrices of type float --> result.CML_STL_add(A,B), and updates to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Add Matrices of type float -->result.CML_STL_add(A,B), and updates to result (this)\n\n");

			std::cout << "Data Dimension ---> 8X8\n\n";
			fprintf(fpTest, "Data Dimension ---> 8X8\n\n");

			/* Test Case data declarations */
			float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,  1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,  2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,  3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f,  4.f,  4.f,  4.f, 4.f,
				5.f,  5.f,  5.f, 5.f,  5.f,  5.f,  5.f, 5.f,
				6.f,  6.f,  6.f, 6.f,  6.f,  6.f,  6.f, 6.f,
				7.f,  7.f,  7.f, 7.f,  7.f,  7.f,  7.f, 7.f,
                8.f,  8.f,  8.f, 8.f,  8.f,  8.f,  8.f, 8.f
			};  

			float expected_res[]  =    {   2.f,  2.f,  2.f, 2.f, 2.f,  2.f,  2.f, 2.f,
				4.f,  4.f,  4.f, 4.f, 4.f,  4.f,  4.f, 4.f,
				6.f,  6.f,  6.f, 6.f, 6.f,  6.f,  6.f, 6.f,
				8.f,  8.f,  8.f, 8.f, 8.f,  8.f,  8.f, 8.f,
				10.f, 10.f, 10.f, 10.f,10.f,10.f,10.f,10.f,
				12.f, 12.f, 12.f, 12.f,12.f,12.f,12.f,12.f,
				14.f, 14.f, 14.f, 14.f,14.f,14.f,14.f,14.f,
				16.f, 16.f, 16.f, 16.f,16.f,16.f,16.f,16.f
			};

			float32 f_res_temp[64]  = {   0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
                0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f
			};

			cml::CMatrix<float32, 8, 8, true> inp_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, false> rhs_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, true> result(f_res_temp);
			cml::CMatrix<float32, 8, 8, true> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( rhs_MT, fpTest);
			

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( expected_result);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            /* Call SUT */
           result.CML_STL_add(inp_MT , rhs_MT);


#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}
		/* result.CML_STL_add(inp_MT , rhs_MT) , result (EXT_MEM=true), inp_MT (EXT_MEM=true)  and rhs_MT (EXT_MEM=true) */
		{
			std::cout << "Test Case ---> Add Matrices of type float --> result.CML_STL_add(A,B), and updates to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Add Matrices of type float -->result.CML_STL_add(A,B), and updates to result (this)\n\n");

			std::cout << "Data Dimension ---> 8X8\n\n";
			fprintf(fpTest, "Data Dimension ---> 8X8\n\n");

			/* Test Case data declarations */
			float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,  1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,  2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,  3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f,  4.f,  4.f,  4.f, 4.f,
				5.f,  5.f,  5.f, 5.f,  5.f,  5.f,  5.f, 5.f,
				6.f,  6.f,  6.f, 6.f,  6.f,  6.f,  6.f, 6.f,
				7.f,  7.f,  7.f, 7.f,  7.f,  7.f,  7.f, 7.f,
                8.f,  8.f,  8.f, 8.f,  8.f,  8.f,  8.f, 8.f
			};  

			 float expected_res[]  =    {   2.f,  2.f,  2.f, 2.f, 2.f,  2.f,  2.f, 2.f,
				4.f,  4.f,  4.f, 4.f, 4.f,  4.f,  4.f, 4.f,
				6.f,  6.f,  6.f, 6.f, 6.f,  6.f,  6.f, 6.f,
				8.f,  8.f,  8.f, 8.f, 8.f,  8.f,  8.f, 8.f,
				10.f, 10.f, 10.f, 10.f,10.f,10.f,10.f,10.f,
				12.f, 12.f, 12.f, 12.f,12.f,12.f,12.f,12.f,
				14.f, 14.f, 14.f, 14.f,14.f,14.f,14.f,14.f,
				16.f, 16.f, 16.f, 16.f,16.f,16.f,16.f,16.f
			};

			float32 f_res_temp[64]  = {   0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
                0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f
			};

			cml::CMatrix<float32, 8, 8, true> rhs_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, true> inp_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, true> result(f_res_temp);
			cml::CMatrix<float32, 8, 8, true> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( expected_result);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            /* Call SUT */
           result.CML_STL_add(inp_MT , rhs_MT);


#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{

			std::cout << "Test Case ---> Add Matrices of type float --> result.CML_STL_add(A,B), and updates to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Add Matrices of type float -->result.CML_STL_add(A,B), and updates to result (this)\n\n");

			std::cout << "Data Dimension ---> 8X8\n\n";
			fprintf(fpTest, "Data Dimension ---> 8X8\n\n");

			/* Test Case data declarations */
			const float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,  1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,  2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,  3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f,  4.f,  4.f,  4.f, 4.f,
				5.f,  5.f,  5.f, 5.f,  5.f,  5.f,  5.f, 5.f,
				6.f,  6.f,  6.f, 6.f,  6.f,  6.f,  6.f, 6.f,
				7.f,  7.f,  7.f, 7.f,  7.f,  7.f,  7.f, 7.f,
                8.f,  8.f,  8.f, 8.f,  8.f,  8.f,  8.f, 8.f
			};  

			const float expected_res[]  =    {   2.f,  2.f,  2.f, 2.f, 2.f,  2.f,  2.f, 2.f,
				4.f,  4.f,  4.f, 4.f, 4.f,  4.f,  4.f, 4.f,
				6.f,  6.f,  6.f, 6.f, 6.f,  6.f,  6.f, 6.f,
				8.f,  8.f,  8.f, 8.f, 8.f,  8.f,  8.f, 8.f,
				10.f, 10.f, 10.f, 10.f,10.f,10.f,10.f,10.f,
				12.f, 12.f, 12.f, 12.f,12.f,12.f,12.f,12.f,
				14.f, 14.f, 14.f, 14.f,14.f,14.f,14.f,14.f,
				16.f, 16.f, 16.f, 16.f,16.f,16.f,16.f,16.f
			};

			cml::CMatrix<float32, 8, 8, false> rhs_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, false> inp_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, false> result;
			cml::CMatrix<float32, 8, 8, false> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( expected_result);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            /* Call SUT */
            result.CML_STL_add(inp_MT , rhs_MT);


#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{

			std::cout << "Test Case ---> Add Matrices of type int --> result.CML_STL_add(A,B), and updates to result (this)\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type int --> result.CML_STL_add(A,B), and updates to result (this)\n\n");

			std::cout << "Data Dimension ---> 8X8\n\n";		
			fprintf(fpTest, "Data Dimension ---> 8X8\n\n");

			/* Test Case data declarations */
			const sint32 racMatrix[]  = {   1,  1,  1, 1, 1,  1,  1, 1,
				2,  2,  2, 2, 2,  2,  2, 2,
				3,  3,  3, 3, 3,  3,  3, 3,
				4,  4,  4, 4, 4,  4,  4, 4,
				5,  5,  5, 5, 5,  5,  5, 5,
				6,  6,  6, 6, 6,  6,  6, 6,
				7,  7,  7, 7, 7,  7,  7, 7,
				8,  8,  8, 8, 8,  8,  8, 8
			};  

			const sint32 expected_res[]  =    {   2,  2,  2, 2, 2,  2,  2, 2,
				4,  4,  4, 4, 4,  4,  4, 4,
				6,  6,  6, 6, 6,  6,  6, 6,
				8,  8,  8, 8, 8,  8,  8, 8,
				10, 10, 10, 10,10,10,10,10,
				12, 12, 12, 12,12,12,12,12,
				14, 14, 14, 14,14,14,14,14,
				16, 16, 16, 16,16,16,16,16
			};

			cml::CMatrix<sint32, 8, 8, false> rhs_MT(racMatrix);
			cml::CMatrix<sint32, 8, 8, false> inp_MT(racMatrix);
			cml::CMatrix<sint32, 8, 8, false> result;
			cml::CMatrix<sint32, 8, 8, false> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint32, 8, 8, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint32, 8, 8, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< sint32, 8, 8, false >( result);
			check__vMatrixPrint_to_File< sint32, 8, 8, false >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 8, 8, false >( expected_result);
			check__vMatrixPrint_to_File< sint32, 8, 8, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result.CML_STL_add(inp_MT , rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint32, 8, 8, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint32, 8, 8, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< sint32, 8, 8, false >( result);
			check__vMatrixPrint_to_File< sint32, 8, 8, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{

			std::cout << "Test Case ---> Add Matrices of type short --> result.CML_STL_add(A,B), and updates to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Add Matrices of type short --> result.CML_STL_add(A,B), and updates to result (this)\n\n");

			std::cout << "Data Dimension ---> 8X8\n\n";
			fprintf(fpTest, "Data Dimension ---> 8X8\n\n");

			/* Test Case data declarations */
			const sint16 racMatrix[]  = {   1,  1,  1, 1, 1,  1,  1, 1,
				2,  2,  2, 2, 2,  2,  2, 2,
				3,  3,  3, 3, 3,  3,  3, 3,
				4,  4,  4, 4, 4,  4,  4, 4,
				5,  5,  5, 5, 5,  5,  5, 5,
				6,  6,  6, 6, 6,  6,  6, 6,
				7,  7,  7, 7, 7,  7,  7, 7,
				8,  8,  8, 8, 8,  8,  8, 8
			};

			const sint16 expected_res[]  =    {   2,  2,  2, 2, 2,  2,  2, 2,
				4,  4,  4, 4, 4,  4,  4, 4,
				6,  6,  6, 6, 6,  6,  6, 6,
				8,  8,  8, 8, 8,  8,  8, 8,
				10, 10, 10, 10,10,10,10,10,
				12, 12, 12, 12,12,12,12,12,
				14, 14, 14, 14,14,14,14,14,
				16, 16, 16, 16,16,16,16,16
			};

			cml::CMatrix<sint16, 8, 8, false> rhs_MT(racMatrix);
			cml::CMatrix<sint16, 8, 8, false> inp_MT(racMatrix);
			cml::CMatrix<sint16, 8, 8, false> result;
			cml::CMatrix<sint16, 8, 8, false> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint16, 8, 8, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint16, 8, 8, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< sint16, 8, 8, false >( result);
			check__vMatrixPrint_to_File< sint16, 8, 8, false >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 8, 8, false >( expected_result);
			check__vMatrixPrint_to_File< sint16, 8, 8, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result.CML_STL_add(inp_MT , rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint16, 8, 8, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint16, 8, 8, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< sint16, 8, 8, false >( result);
			check__vMatrixPrint_to_File< sint16, 8, 8, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{

			std::cout << "Test Case ---> Add Matrices of type char --> result.CML_STL_add(A,B), and updates to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Add Matrices of type char --> result.CML_STL_add(A,B), and updates to result (this)\n\n");

			std::cout << "Data Dimension ---> 8X8\n\n";
			fprintf(fpTest, "Data Dimension ---> 8X8\n\n");

			/* Test Case data declarations */
			const sint8 racMatrix[]  = {   1,  1,  1, 1, 1,  1,  1, 1,
				2,  2,  2, 2, 2,  2,  2, 2,
				3,  3,  3, 3, 3,  3,  3, 3,
				4,  4,  4, 4, 4,  4,  4, 4,
				5,  5,  5, 5, 5,  5,  5, 5,
				6,  6,  6, 6, 6,  6,  6, 6,
				7,  7,  7, 7, 7,  7,  7, 7,
				8,  8,  8, 8, 8,  8,  8, 8
			};  

			const sint8 expected_res[]  =    {   2,  2,  2, 2, 2,  2,  2, 2,
				4,  4,  4, 4, 4,  4,  4, 4,
				6,  6,  6, 6, 6,  6,  6, 6,
				8,  8,  8, 8, 8,  8,  8, 8,
				10, 10, 10, 10,10,10,10,10,
				12, 12, 12, 12,12,12,12,12,
				14, 14, 14, 14,14,14,14,14,
				16, 16, 16, 16,16,16,16,16
			};

			cml::CMatrix<sint8, 8, 8, false> rhs_MT(racMatrix);
			cml::CMatrix<sint8, 8, 8, false> inp_MT(racMatrix);
			cml::CMatrix<sint8, 8, 8, false> result;
			cml::CMatrix<sint8, 8, 8, false> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint8, 8, 8, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint8, 8, 8, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< sint8, 8, 8, false >( result);
			check__vMatrixPrint_to_File< sint8, 8, 8, false >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 8, 8, false >( expected_result);
			check__vMatrixPrint_to_File< sint8, 8, 8, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

             /* Call SUT */
             result.CML_STL_add(inp_MT , rhs_MT);


#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint8, 8, 8, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint8, 8, 8, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< sint8, 8, 8, false >( result);
			check__vMatrixPrint_to_File< sint8, 8, 8, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

	}
	std::cout << "END ---> test_CML_STL_add\n\n";
	fprintf(fpTest, "END ---> test_CML_STL_add\n\n");
}

void TEST_CLASS_MATRIX::test_operatorsubandassign(int doIt)
{
	std::cout << "START ---> test_operatorsubandassign\n\n";		
	fprintf(fpTest, "START ---> test_operatorsubandassign\n\n");

	std::cout << "Function Name ---> operator-=() \n\n";		
	fprintf(fpTest, "Function Name ---> operator-=() \n\n");
	if (doIt) 
	{
		/* inp_MT matrix is with internal memory with option EXT_MEM=false and rhs_MT matrix is with external memory with option EXT_MEM=true */
		{

			std::cout << "Test Case ---> Add Matrices of type float --> A -= B, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type float --> A -= B, assign to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			 float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			};  

			 float expected_result[]  =    {   0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f
			};

			cml::CMatrix<float32, 4, 4, true> rhs_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, false> expected_inp_MT(expected_result);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";		
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";		
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( expected_inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( expected_inp_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT -= rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);
		
			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

     /* inp_MT matrix is with external memory with option EXT_MEM=true and rhs_MT matrix is with internal memory with option EXT_MEM=false */
		{

			std::cout << "Test Case ---> Add Matrices of type float --> A -= B, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type float --> A -= B, assign to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			 float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			};  

			 float expected_result[]  =    {   0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f
			};

			cml::CMatrix<float32, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, true> inp_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, true> expected_inp_MT(expected_result,16);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( inp_MT, fpTest);

			std::cout << "input2 = \n";		
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";		
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( expected_inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( expected_inp_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT -= rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( inp_MT, fpTest);
		
			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		/* inp_MT matrix is with external memory with option EXT_MEM=true and rhs_MT matrix is also external memory with option EXT_MEM=true */
		{

			std::cout << "Test Case ---> Add Matrices of type float --> A -= B, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type float --> A -= B, assign to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			 float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			};  

			 float expected_result[]  =    {   0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f
			};

			cml::CMatrix<float32, 4, 4, true> rhs_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, true> inp_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, true> expected_inp_MT(expected_result,16);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( inp_MT, fpTest);

			std::cout << "input2 = \n";		
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";		
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( expected_inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( expected_inp_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT -= rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( inp_MT, fpTest);
		
			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}


		{
			std::cout << "Test Case ---> Subtract Matrices of type float --> A -= B, with assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Subtract Matrices of type float --> A -= B, with assign to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			const float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			};  

			const float expected_result[]  =  {   0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f
			};

			cml::CMatrix<float32, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, false> expected_inp_MT(expected_result);

			/* Set global data */
			initialise_global_data();


			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";		
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();


			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( expected_inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( expected_inp_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT -= rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Subtract Matrices of type int --> A -= B, with assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Subtract Matrices of type int --> A -= B, with assign to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			const sint32 racMatrix[]  = {   1,  1,  1, 1,
				2,  2,  2, 2,
				3,  3,  3, 3,
				4,  4,  4, 4
			};  

			const sint32 expected_result[]  =  {   0,  0,  0, 0,
				0,  0,  0, 0,
				0,  0,  0, 0,
				0,  0,  0, 0
			};

			cml::CMatrix<sint32, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<sint32, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<sint32, 4, 4, false> expected_inp_MT(expected_result);

			/* Set global data */
			initialise_global_data();


			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";		
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();


			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( expected_inp_MT);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( expected_inp_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT -= rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Subtract Matrices of type short --> A -= B, with assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Subtract Matrices of type short --> A -= B, with assign to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			const sint16 racMatrix[]  = {   1,  1,  1, 1,
				2,  2,  2, 2,
				3,  3,  3, 3,
				4,  4,  4, 4
			};  

			const sint16 expected_result[]  =  {   0,  0,  0, 0,
				0,  0,  0, 0,
				0,  0,  0, 0,
				0,  0,  0, 0
			};

			cml::CMatrix<sint16, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<sint16, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<sint16, 4, 4, false> expected_inp_MT(expected_result);

			/* Set global data */
			initialise_global_data();


			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";		
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();


			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( expected_inp_MT);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( expected_inp_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT -= rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Subtract Matrices of type char --> A -= B, with assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Subtract Matrices of type char --> A -= B, with assign to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			const sint8 racMatrix[]  = {   1,  1,  1, 1,
				2,  2,  2, 2,
				3,  3,  3, 3,
				4,  4,  4, 4
			};  

			const sint8 expected_result[]  =  {   0,  0,  0, 0,
				0,  0,  0, 0,
				0,  0,  0, 0,
				0,  0,  0, 0
			};

			cml::CMatrix<sint8, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<sint8, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<sint8, 4, 4, false> expected_inp_MT(expected_result);

			/* Set global data */
			initialise_global_data();


			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";		
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";		
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();


			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( expected_inp_MT);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( expected_inp_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT -= rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

	}
	std::cout << "END ---> test_operatorsubandassign\n\n";
	fprintf(fpTest, "END ---> test_operatorsubandassign\n\n");
}

void TEST_CLASS_MATRIX::test_operatorsubtraction(int doIt)
{

	std::cout << "START ---> test_operatorsubtraction\n\n";		
	fprintf(fpTest, "START ---> test_operatorsubtraction\n\n");


	std::cout << "Function Name ---> operator-()  \n\n";		
	fprintf(fpTest, "Function Name ---> operator-()  \n\n");
	if (doIt) 
	{

		/* result = inp_MT - rhs_MT
		   result ---> internal memory with EXT_MEM=false
		   inp_MT ---> internal memory with EXT_MEM=false
		   rhs_MT ---> external memory with EXT_MEM=true
		*/
		
		{

			std::cout << "Test Case ---> Substract Matrices of type float --> result = A - B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Substract Matrices of type float --> result = A - B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			};  

			const float expected_res[]  =    {      0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f
			};

			cml::CMatrix<const float32, 4, 4, true> rhs_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, false> result;
			cml::CMatrix<float32, 4, 4, false> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File<const float32, 4, 4, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( expected_result);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT - rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File< const float32, 4, 4, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		/* result = inp_MT - rhs_MT
		   result ---> internal memory with EXT_MEM=false
		   inp_MT ---> external memory with EXT_MEM=true
		   rhs_MT ---> external memory with EXT_MEM=true
		*/
		
		{

			std::cout << "Test Case ---> Substract Matrices of type float --> result = A - B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Substract Matrices of type float --> result = A - B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			};  

			const float expected_res[]  =    {   0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f
			};

			cml::CMatrix<const float32, 4, 4, true> rhs_MT(racMatrix,16);
			cml::CMatrix<const float32, 4, 4, true> inp_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, false> result;
			cml::CMatrix<float32, 4, 4, false> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true>( inp_MT);
			check__vMatrixPrint_to_File<const float32, 4, 4, true>( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File<const float32, 4, 4, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( expected_result);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT - rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true>( inp_MT);
			check__vMatrixPrint_to_File<const float32, 4, 4, true>( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File< const float32, 4, 4, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		
}

		/* result = inp_MT - rhs_MT
		   result ---> external memory with EXT_MEM=true
		   inp_MT ---> internal memory with EXT_MEM=false
		   rhs_MT ---> external memory with EXT_MEM=true
		*/
		
		{

			std::cout << "Test Case ---> Substract Matrices of type float --> result = A - B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Substract Matrices of type float --> result = A - B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			};  

		   float temp[]  = {   4.f,  4.f,  4.f, 4.f,
				4.f,  4.f,  4.f, 4.f,
				4.f,  4.f,  4.f, 4.f,
				4.f,  4.f,  4.f, 4.f
			};

			float expected_res[]  =    {   0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f
			};

			cml::CMatrix<const float32, 4, 4, true> rhs_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, true> result(temp,16);
			cml::CMatrix<float32, 4, 4, true> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			//result.fill(4.0);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1(inp_MT) = \n";
			fprintf(fpTest, "input1(inp_MT) = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 (rhs_MT) = \n";
			fprintf(fpTest, "input2(rhs_MT) = \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File<const float32, 4, 4, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( expected_result);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT - rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File< const float32, 4, 4, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		/* result = inp_MT - rhs_MT
		   result ---> external memory with EXT_MEM=true
		   inp_MT ---> external memory with EXT_MEM=true
		   rhs_MT ---> external memory with EXT_MEM=true
		*/
		
		{

			std::cout << "Test Case ---> Substract Matrices of type float --> result = A - B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Substract Matrices of type float --> result = A - B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			}; 

	        float temp[]  = {   4.f,  4.f,  4.f, 4.f,
				4.f,  4.f,  4.f, 4.f,
				4.f,  4.f,  4.f, 4.f,
				4.f,  4.f,  4.f, 4.f
			};

			float expected_res[]  =    {   0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f
			};

			cml::CMatrix<const float32, 4, 4, true> rhs_MT(racMatrix,16);
			cml::CMatrix<const float32, 4, 4, true> inp_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, true> result(temp,16);
			cml::CMatrix<float32, 4, 4, true> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			//result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1(inp_MT) = \n";
			fprintf(fpTest, "input1(inp_MT) = \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true>( inp_MT);
			check__vMatrixPrint_to_File<const float32, 4, 4, true>( inp_MT, fpTest);

			std::cout << "input2(rhs_MT) = \n";
			fprintf(fpTest, "input2(rhs_MT) = \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File<const float32, 4, 4, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( expected_result);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT - rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1(inp_MT) = \n";
			fprintf(fpTest, "input1 (inp_MT)= \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true>( inp_MT);
			check__vMatrixPrint_to_File<const float32, 4, 4, true>( inp_MT, fpTest);

			std::cout << "input2 (rhs_MT) = \n";
			fprintf(fpTest, "input2 (rhs_MT)= \n");

			check__vMatrixPrint_to_console<const float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File< const float32, 4, 4, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		/* result = inp_MT - rhs_MT
		   result ---> external memory with EXT_MEM=true
		   inp_MT ---> internal memory with EXT_MEM=false
		   rhs_MT ---> internal memory with EXT_MEM=false
		*/
		
		{

			std::cout << "Test Case ---> Substract Matrices of type float --> result = A - B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Substract Matrices of type float --> result = A - B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			}; 

	        float temp[]  = {   4.f,  4.f,  4.f, 4.f,
				4.f,  4.f,  4.f, 4.f,
				4.f,  4.f,  4.f, 4.f,
				4.f,  4.f,  4.f, 4.f
			};

			float expected_res[]  =    {   0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f
			};

			cml::CMatrix< float32, 4, 4, false> rhs_MT(racMatrix,16);
			cml::CMatrix< float32, 4, 4, false> inp_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, true> result(temp,16);
			cml::CMatrix<float32, 4, 4, true> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			//result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1(inp_MT) = \n";
			fprintf(fpTest, "input1(inp_MT) = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false>( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false>( inp_MT, fpTest);

			std::cout << "input2(rhs_MT) = \n";
			fprintf(fpTest, "input2(rhs_MT) = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( expected_result);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT - rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1(inp_MT) = \n";
			fprintf(fpTest, "input1 (inp_MT)= \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false>( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false>( inp_MT, fpTest);

			std::cout << "input2 (rhs_MT) = \n";
			fprintf(fpTest, "input2 (rhs_MT)= \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File<  float32, 4, 4, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Subtract Matrices of type float --> result = A - B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Subtract Matrices of type float --> result = A - B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			};  

			const float expected_res[]  =    {   0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f
			};

			cml::CMatrix<float32, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, false> result;
			cml::CMatrix<float32, 4, 4, false> expected_result(expected_res);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( rhs_MT, fpTest);

			/* Set global data */
			initialise_global_data();

			result.fill(0);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( expected_result);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT - rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Subtract Matrices of type int --> result = A - B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Subtract Matrices of type int --> result = A - B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const sint32 racMatrix[]  = {   1,  1,  1, 1,
				2,  2,  2, 2,
				3,  3,  3, 3,
				4,  4,  4, 4
			};  

			const sint32 expected_res[]  =    {   0,  0,  0, 0,
				0,  0,  0, 0,
				0,  0,  0, 0,
				0,  0,  0, 0
			};

			cml::CMatrix<sint32, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<sint32, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<sint32, 4, 4, false> result;
			cml::CMatrix<sint32, 4, 4, false> expected_result(expected_res);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( rhs_MT, fpTest);

			/* Set global data */
			initialise_global_data();

			result.fill(0);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( expected_result);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT - rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( result);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Subtract Matrices of type short --> result = A - B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Subtract Matrices of type short --> result = A - B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const sint16 racMatrix[]  = {   1,  1,  1, 1,
				2,  2,  2, 2,
				3,  3,  3, 3,
				4,  4,  4, 4
			};  

			const sint16 expected_res[]  =    {   0,  0,  0, 0,
				0,  0,  0, 0,
				0,  0,  0, 0,
				0,  0,  0, 0
			};

			cml::CMatrix<sint16, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<sint16, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<sint16, 4, 4, false> result;
			cml::CMatrix<sint16, 4, 4, false> expected_result(expected_res);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( rhs_MT, fpTest);

			/* Set global data */
			initialise_global_data();

			result.fill(0);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( expected_result);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT - rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( result);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Subtract Matrices of type char --> result = A - B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Subtract Matrices of type char --> result = A - B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const sint8 racMatrix[]  = {   1,  1,  1, 1,
				2,  2,  2, 2,
				3,  3,  3, 3,
				4,  4,  4, 4
			};  

			const sint8 expected_res[]  =    {   0,  0,  0, 0,
				0,  0,  0, 0,
				0,  0,  0, 0,
				0,  0,  0, 0
			};

			cml::CMatrix<sint8, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<sint8, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<sint8, 4, 4, false> result;
			cml::CMatrix<sint8, 4, 4, false> expected_result(expected_res);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( rhs_MT, fpTest);

			/* Set global data */
			initialise_global_data();

			result.fill(0);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( expected_result);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT - rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( result);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

	}
	std::cout << "END ---> test_operatorsubtraction\n\n";
	fprintf(fpTest, "END ---> test_operatorsubtraction\n\n");

}

void TEST_CLASS_MATRIX::test_CML_STL_sub(int doIt)
{

	std::cout << "START ---> test_CML_STL_sub\n\n";
	fprintf(fpTest, "START ---> test_CML_STL_sub\n\n");


	std::cout << "Function Name ---> CML_STL_sub()  \n\n";
	fprintf(fpTest, "Function Name ---> CML_STL_sub()  \n\n");
	if (doIt) 
	{
		/* result.CML_STL_sub(inp_MT , rhs_MT) , result (EXT_MEM=false), inp_MT (EXT_MEM=false)  and rhs_MT (EXT_MEM=true) */
		{
			std::cout << "Test Case ---> Subtract Matrices of type float --> result.CML_STL_sub(A,B), and updates to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Subtract Matrices of type float -->result.CML_STL_sub(A,B), and updates to result (this)\n\n");

			std::cout << "Data Dimension ---> 8X8\n\n";
			fprintf(fpTest, "Data Dimension ---> 8X8\n\n");

			/* Test Case data declarations */
			float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,  1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,  2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,  3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f,  4.f,  4.f,  4.f, 4.f,
				5.f,  5.f,  5.f, 5.f,  5.f,  5.f,  5.f, 5.f,
				6.f,  6.f,  6.f, 6.f,  6.f,  6.f,  6.f, 6.f,
				7.f,  7.f,  7.f, 7.f,  7.f,  7.f,  7.f, 7.f,
                8.f,  8.f,  8.f, 8.f,  8.f,  8.f,  8.f, 8.f
			};  

			const float expected_res[]  =    {   0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
                0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f
			};

			cml::CMatrix<float32, 8, 8, true> rhs_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, false> inp_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, false> result;
			cml::CMatrix<float32, 8, 8, false> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1(inp_MT) = \n";
			fprintf(fpTest, "input1(inp_MT) = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2(rhs_MT) = \n";
			fprintf(fpTest, "input2(rhs_MT) = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( expected_result);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            /* Call SUT */
           result.CML_STL_sub(inp_MT , rhs_MT);


#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1(inp_MT) = \n";
			fprintf(fpTest, "input1(inp_MT) = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2(rhs_MT) = \n";
			fprintf(fpTest, "input2(rhs_MT) = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

/* result.CML_STL_sub(inp_MT , rhs_MT) , result (EXT_MEM=false), inp_MT (EXT_MEM=true)  and rhs_MT (EXT_MEM=true) */
		{
			std::cout << "Test Case ---> Subtract Matrices of type float --> result.CML_STL_sub(A,B), and updates to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Subtract Matrices of type float -->result.CML_STL_sub(A,B), and updates to result (this)\n\n");

			std::cout << "Data Dimension ---> 8X8\n\n";
			fprintf(fpTest, "Data Dimension ---> 8X8\n\n");

			/* Test Case data declarations */
			 float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,  1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,  2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,  3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f,  4.f,  4.f,  4.f, 4.f,
				5.f,  5.f,  5.f, 5.f,  5.f,  5.f,  5.f, 5.f,
				6.f,  6.f,  6.f, 6.f,  6.f,  6.f,  6.f, 6.f,
				7.f,  7.f,  7.f, 7.f,  7.f,  7.f,  7.f, 7.f,
                8.f,  8.f,  8.f, 8.f,  8.f,  8.f,  8.f, 8.f
			};  

			const float expected_res[]  =    {   0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
                0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f
			};

			cml::CMatrix<const float32, 8, 8, true> rhs_MT(racMatrix);
			cml::CMatrix<const float32, 8, 8, true> inp_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, false> result;
			cml::CMatrix<float32, 8, 8, false> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1(inp_MT) = \n";
			fprintf(fpTest, "input1(inp_MT) = \n");

			/*check__vMatrixPrint_to_console<const float32, 8, 8, true >( inp_MT);
			check__vMatrixPrint_to_File<const float32, 8, 8, true >( inp_MT, fpTest);
*/
			std::cout << "input2(rhs_MT) = \n";
			fprintf(fpTest, "input2(rhs_MT) = \n");

			check__vMatrixPrint_to_console< const float32, 8, 8, true >( rhs_MT);
			check__vMatrixPrint_to_File< const float32, 8, 8, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( expected_result);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            /* Call SUT */
           result.CML_STL_sub(inp_MT , rhs_MT);


#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1(inp_MT) = \n";
			fprintf(fpTest, "input1(inp_MT) = \n");

		/*	check__vMatrixPrint_to_console<const float32, 8, 8, true >( inp_MT);
			check__vMatrixPrint_to_File<const float32, 8, 8, true >( inp_MT, fpTest);*/

			std::cout << "input2(rhs_MT) = \n";
			fprintf(fpTest, "input2(rhs_MT) = \n");

			check__vMatrixPrint_to_console< const float32, 8, 8, true >( rhs_MT);
			check__vMatrixPrint_to_File< const float32, 8, 8, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

 /* result.CML_STL_sub(inp_MT , rhs_MT) , result (EXT_MEM=true), inp_MT (EXT_MEM=false)  and rhs_MT (EXT_MEM=false) */
		{

			std::cout << "Test Case ---> Subtract Matrices of type float --> result.CML_STL_sub(A,B), and updates to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Subtract Matrices of type float -->result.CML_STL_sub(A,B), and updates to result (this)\n\n");

			std::cout << "Data Dimension ---> 8X8\n\n";
			fprintf(fpTest, "Data Dimension ---> 8X8\n\n");

			/* Test Case data declarations */
			float32 racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,  1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,  2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,  3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f,  4.f,  4.f,  4.f, 4.f,
				5.f,  5.f,  5.f, 5.f,  5.f,  5.f,  5.f, 5.f,
				6.f,  6.f,  6.f, 6.f,  6.f,  6.f,  6.f, 6.f,
				7.f,  7.f,  7.f, 7.f,  7.f,  7.f,  7.f, 7.f,
                8.f,  8.f,  8.f, 8.f,  8.f,  8.f,  8.f, 8.f
			};  

			float32 expected_res[]  =    {   0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
                0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f
			};

			float32 f_res_temp[64]  = {   0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
                0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f
			};

			cml::CMatrix<float32, 8, 8, false> rhs_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, false> inp_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, true> result(f_res_temp);
			cml::CMatrix<float32, 8, 8, true> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1(inp_MT) = \n";
			fprintf(fpTest, "input1(inp_MT) = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2(rhs_MT) = \n";
			fprintf(fpTest, "input2(rhs_MT) = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( expected_result);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            /* Call SUT */
            result.CML_STL_sub(inp_MT , rhs_MT);


#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}
/* result.CML_STL_sub(inp_MT , rhs_MT) , result (EXT_MEM=true), inp_MT (EXT_MEM=false)  and rhs_MT (EXT_MEM=true) */
		{
			std::cout << "Test Case ---> Subtract Matrices of type float --> result.CML_STL_sub(A,B), and updates to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Subtract Matrices of type float -->result.CML_STL_sub(A,B), and updates to result (this)\n\n");

			std::cout << "Data Dimension ---> 8X8\n\n";
			fprintf(fpTest, "Data Dimension ---> 8X8\n\n");

			/* Test Case data declarations */
			float32 racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,  1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,  2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,  3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f,  4.f,  4.f,  4.f, 4.f,
				5.f,  5.f,  5.f, 5.f,  5.f,  5.f,  5.f, 5.f,
				6.f,  6.f,  6.f, 6.f,  6.f,  6.f,  6.f, 6.f,
				7.f,  7.f,  7.f, 7.f,  7.f,  7.f,  7.f, 7.f,
                8.f,  8.f,  8.f, 8.f,  8.f,  8.f,  8.f, 8.f
			};  

			float32 expected_res[]  =    {   0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
                0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f
			};

			float32 f_res_temp[64]  = {   0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
                0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f
			};

			cml::CMatrix<float32, 8, 8, true> rhs_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, false> inp_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, true> result(f_res_temp);
			cml::CMatrix<float32, 8, 8, true> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( expected_result);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            /* Call SUT */
           result.CML_STL_sub(inp_MT , rhs_MT);


#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}


		/* result.CML_STL_sub(inp_MT , rhs_MT) , result (EXT_MEM=true), inp_MT (EXT_MEM=true)  and rhs_MT (EXT_MEM=true) */
		{
			std::cout << "Test Case ---> Subtract Matrices of type float --> result.CML_STL_sub(A,B), and updates to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Subtract Matrices of type float -->result.CML_STL_sub(A,B), and updates to result (this)\n\n");

			std::cout << "Data Dimension ---> 8X8\n\n";
			fprintf(fpTest, "Data Dimension ---> 8X8\n\n");

			/* Test Case data declarations */
			float32 racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,  1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,  2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,  3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f,  4.f,  4.f,  4.f, 4.f,
				5.f,  5.f,  5.f, 5.f,  5.f,  5.f,  5.f, 5.f,
				6.f,  6.f,  6.f, 6.f,  6.f,  6.f,  6.f, 6.f,
				7.f,  7.f,  7.f, 7.f,  7.f,  7.f,  7.f, 7.f,
                8.f,  8.f,  8.f, 8.f,  8.f,  8.f,  8.f, 8.f
			};  

			 float32 expected_res[]  =    {   0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
                0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f
			};

			float32 f_res_temp[64]  = {   0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f,
                0.f,  0.f,  0.f, 0.f,  0.f,  0.f,  0.f, 0.f
			};

			cml::CMatrix<float32, 8, 8, true> rhs_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, true> inp_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, true> result(f_res_temp);
			cml::CMatrix<float32, 8, 8, true> expected_result(expected_res);


			/* Set global data */
			initialise_global_data();

			result.fill(4);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1(inp_MT) = \n";
			fprintf(fpTest, "input1(inp_MT) = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( inp_MT, fpTest);

			std::cout << "input2(rhs_MT) = \n";
			fprintf(fpTest, "input2(rhs_MT) = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( result, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( expected_result);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

            /* Call SUT */
           result.CML_STL_sub(inp_MT , rhs_MT);


#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1(inp_MT) = \n";
			fprintf(fpTest, "input1(inp_MT) = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( inp_MT, fpTest);

			std::cout << "input2(rhs_MT) = \n";
			fprintf(fpTest, "input2(rhs_MT) = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( rhs_MT, fpTest);

			std::cout << "result = \n";
			fprintf(fpTest, "result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, true >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, true >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */
			returnValue = expected_result.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Subtract Matrices of type float --> result.CML_STL_sub(A,B), and updates to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Subtract Matrices of type float --> result.CML_STL_sub(A,B), and updates to result (this)\n\n");

			std::cout << "Data Dimension ---> 8X8\n\n";
			fprintf(fpTest, "Data Dimension ---> 8X8\n\n");

			/* Test Case data declarations */
			const float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,  1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,  2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,  3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f,  4.f,  4.f,  4.f, 4.f,
				5.f,  5.f,  5.f, 5.f,  5.f,  5.f,  5.f, 5.f,
				6.f,  6.f,  6.f, 6.f,  6.f,  6.f,  6.f, 6.f,
				7.f,  7.f,  7.f, 7.f,  7.f,  7.f,  7.f, 7.f,
                8.f,  8.f,  8.f, 8.f,  8.f,  8.f,  8.f, 8.f
			};

			const float expected_res[]  =    {   0.f,  0.f,  0.f, 0.f, 0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f, 0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f, 0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f, 0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f, 0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f, 0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f, 0.f,  0.f,  0.f, 0.f,
				0.f,  0.f,  0.f, 0.f, 0.f,  0.f,  0.f, 0.f
			};

			cml::CMatrix<float32, 8, 8, false> rhs_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, false> inp_MT(racMatrix);
			cml::CMatrix<float32, 8, 8, false> result;
			cml::CMatrix<float32, 8, 8, false> expected_result(expected_res);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( rhs_MT, fpTest);

			/* Set global data */
			initialise_global_data();

			result.fill(1);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( expected_result);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */


			result.CML_STL_sub(inp_MT , rhs_MT);


#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 8, 8, false >( result);
			check__vMatrixPrint_to_File< float32, 8, 8, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Subtract Matrices of type int --> result.CML_STL_sub(A,B), and updates to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Subtract Matrices of type int --> result.CML_STL_sub(A,B), and updates to result (this)\n\n");

			std::cout << "Data Dimension ---> 8X8\n\n";
			fprintf(fpTest, "Data Dimension ---> 8X8\n\n");

			/* Test Case data declarations */
			const sint32 racMatrix[]  = {   1,  1,  1, 1, 1,  1,  1, 1,
				2,  2,  2, 2, 2,  2,  2, 2,
				3,  3,  3, 3, 3,  3,  3, 3,
				4,  4,  4, 4, 4,  4,  4, 4,
				5,  5,  5, 5, 5,  5,  5, 5,
				6,  6,  6, 6, 6,  6,  6, 6,
				7,  7,  7, 7, 7,  7,  7, 7,
				8,  8,  8, 8, 8,  8,  8, 8
			};

			const sint32 expected_res[]  =    {   0,  0,  0, 0, 0,  0,  0, 0,
				0,  0,  0,  0, 0,  0,  0, 0,
				0,  0,  0,  0, 0,  0,  0, 0,
				0,  0,  0,  0, 0,  0,  0, 0,
				0,  0,  0,  0, 0,  0,  0, 0,
				0,  0,  0,  0, 0,  0,  0, 0,
				0,  0,  0,  0, 0,  0,  0, 0,
				0,  0,  0,  0, 0,  0,  0, 0
			};

			cml::CMatrix<sint32, 8, 8, false> rhs_MT(racMatrix);
			cml::CMatrix<sint32, 8, 8, false> inp_MT(racMatrix);
			cml::CMatrix<sint32, 8, 8, false> result;
			cml::CMatrix<sint32, 8, 8, false> expected_result(expected_res);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint32, 8, 8, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint32, 8, 8, false >( rhs_MT, fpTest);

			/* Set global data */
			initialise_global_data();

			result.fill(1);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 8, 8, false >( expected_result);
			check__vMatrixPrint_to_File< sint32, 8, 8, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */


			result.CML_STL_sub(inp_MT , rhs_MT);


#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 8, 8, false >( result);
			check__vMatrixPrint_to_File< sint32, 8, 8, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}


		{
			std::cout << "Test Case ---> Subtract Matrices of type short --> result.CML_STL_sub(A,B), and updates to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Subtract Matrices of type short --> result.CML_STL_sub(A,B), and updates to result (this)\n\n");

			std::cout << "Data Dimension ---> 8X8\n\n";
			fprintf(fpTest, "Data Dimension ---> 8X8\n\n");

			/* Test Case data declarations */
			const sint16 racMatrix[]  = {   1,  1,  1, 1, 1,  1,  1, 1,
				2,  2,  2, 2, 2,  2,  2, 2,
				3,  3,  3, 3, 3,  3,  3, 3,
				4,  4,  4, 4, 4,  4,  4, 4,
				5,  5,  5, 5, 5,  5,  5, 5,
				6,  6,  6, 6, 6,  6,  6, 6,
				7,  7,  7, 7, 7,  7,  7, 7,
				8,  8,  8, 8, 8,  8,  8, 8
			};  

			const sint16 expected_res[]  =    {   0,  0,  0, 0, 0,  0,  0, 0,
				0,  0,  0,  0, 0,  0,  0, 0,
				0,  0,  0,  0, 0,  0,  0, 0,
				0,  0,  0,  0, 0,  0,  0, 0,
				0,  0,  0,  0, 0,  0,  0, 0,
				0,  0,  0,  0, 0,  0,  0, 0,
				0,  0,  0,  0, 0,  0,  0, 0,
				0,  0,  0,  0, 0,  0,  0, 0
			};

			cml::CMatrix<sint16, 8, 8, false> rhs_MT(racMatrix);
			cml::CMatrix<sint16, 8, 8, false> inp_MT(racMatrix);
			cml::CMatrix<sint16, 8, 8, false> result;
			cml::CMatrix<sint16, 8, 8, false> expected_result(expected_res);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint16, 8, 8, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint16, 8, 8, false >( rhs_MT, fpTest);

			/* Set global data */
			initialise_global_data();

			result.fill(1);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 8, 8, false >( expected_result);
			check__vMatrixPrint_to_File< sint16, 8, 8, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			
			result.CML_STL_sub(inp_MT , rhs_MT);


#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 8, 8, false >( result);
			check__vMatrixPrint_to_File< sint16, 8, 8, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		
		{
			std::cout << "Test Case ---> Subtract Matrices of type char --> result.CML_STL_sub(A,B), and updates to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Subtract Matrices of type char --> result.CML_STL_sub(A,B), and updates to result (this)\n\n");

			std::cout << "Data Dimension ---> 8X8\n\n";
			fprintf(fpTest, "Data Dimension ---> 8X8\n\n");

			/* Test Case data declarations */
			const sint8 racMatrix[]  = {   1,  1,  1, 1, 1,  1,  1, 1,
				2,  2,  2, 2, 2,  2,  2, 2,
				3,  3,  3, 3, 3,  3,  3, 3,
				4,  4,  4, 4, 4,  4,  4, 4,
				5,  5,  5, 5, 5,  5,  5, 5,
				6,  6,  6, 6, 6,  6,  6, 6,
				7,  7,  7, 7, 7,  7,  7, 7,
				8,  8,  8, 8, 8,  8,  8, 8
			};

			const sint8 expected_res[]  =    {   0,  0,  0, 0, 0,  0,  0, 0,
				0,  0,  0,  0, 0,  0,  0, 0,
				0,  0,  0,  0, 0,  0,  0, 0,
				0,  0,  0,  0, 0,  0,  0, 0,
				0,  0,  0,  0, 0,  0,  0, 0,
				0,  0,  0,  0, 0,  0,  0, 0,
				0,  0,  0,  0, 0,  0,  0, 0,
				0,  0,  0,  0, 0,  0,  0, 0
			};

			cml::CMatrix<sint8, 8, 8, false> rhs_MT(racMatrix);
			cml::CMatrix<sint8, 8, 8, false> inp_MT(racMatrix);
			cml::CMatrix<sint8, 8, 8, false> result;
			cml::CMatrix<sint8, 8, 8, false> expected_result(expected_res);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 8, 8, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 8, 8, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint8, 8, 8, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint8, 8, 8, false >( rhs_MT, fpTest);

			/* Set global data */
			initialise_global_data();

			result.fill(1);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 8, 8, false >( expected_result);
			check__vMatrixPrint_to_File< sint8, 8, 8, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			result.CML_STL_sub(inp_MT , rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 8, 8, false >( result);
			check__vMatrixPrint_to_File< sint8, 8, 8, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

	}
	std::cout << "END ---> test_CML_STL_sub\n\n";
	fprintf(fpTest, "END ---> test_CML_STL_sub\n\n");

}




void TEST_CLASS_MATRIX::test_operatornegate(int doIt)
{
	std::cout << "START ---> test_operatornegate\n\n";		
	fprintf(fpTest, "START ---> test_operatornegate\n\n");

	std::cout << "Function Name ---> operator-()(Negate) \n\n";		
	fprintf(fpTest, "Function Name ---> operator-()(Negate) \n\n");
	if (doIt) 
	{

		{
			std::cout << "Test Case ---> Negate Matrix of type float --> result = -A\n\n";		
			fprintf(fpTest, "Test Case ---> Negate Matrix of type float --> result = -A\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			};  

			const float expected_res[]  =    {   -1.f,  -1.f,  -1.f, -1.f,
				-2.f,  -2.f,  -2.f, -2.f,
				-3.f,  -3.f,  -3.f, -3.f,
				-4.f,  -4.f,  -4.f, -4.f
			};  

			cml::CMatrix<float32, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, false> expected_result(expected_res);
			cml::CMatrix<float32, 4, 4, false> result;


			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input = \n";	
			fprintf(fpTest, "input = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( rhs_MT, fpTest);

			result.fill(0);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( expected_result);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */		
			result = -rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( result);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Negate Matrix of type int --> result = -A\n\n";		
			fprintf(fpTest, "Test Case ---> Negate Matrix of type int --> result = -A\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const sint32 racMatrix[]  = {   1,  1,  1, 1,
				2,  2,  2, 2,
				3,  3,  3, 3,
				4,  4,  4, 4
			};  

			const sint32 expected_res[]  =    {   -1,  -1,  -1, -1,
				-2,  -2,  -2, -2,
				-3,  -3,  -3, -3,
				-4,  -4,  -4, -4
			};  

			cml::CMatrix<sint32, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<sint32, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<sint32, 4, 4, false> expected_result(expected_res);
			cml::CMatrix<sint32, 4, 4, false> result;


			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input = \n";	
			fprintf(fpTest, "input = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( rhs_MT, fpTest);

			result.fill(0);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( expected_result);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */		
			result = -rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( result);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Negate Matrix of type short --> result = -A\n\n";		
			fprintf(fpTest, "Test Case ---> Negate Matrix of type short --> result = -A\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const sint16 racMatrix[]  = {   1,  1,  1, 1,
				2,  2,  2, 2,
				3,  3,  3, 3,
				4,  4,  4, 4
			};  

			const sint16 expected_res[]  =    {   -1,  -1,  -1, -1,
				-2,  -2,  -2, -2,
				-3,  -3,  -3, -3,
				-4,  -4,  -4, -4
			};  

			cml::CMatrix<sint16, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<sint16, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<sint16, 4, 4, false> expected_result(expected_res);
			cml::CMatrix<sint16, 4, 4, false> result;


			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input = \n";	
			fprintf(fpTest, "input = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( rhs_MT, fpTest);

			result.fill(0);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( expected_result);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */		
			result = -rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( result);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Negate Matrix of type char --> result = -A\n\n";		
			fprintf(fpTest, "Test Case ---> Negate Matrix of type char --> result = -A\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const sint8 racMatrix[]  = {   1,  1,  1, 1,
				2,  2,  2, 2,
				3,  3,  3, 3,
				4,  4,  4, 4
			};  

			const sint8 expected_res[]  =    {   -1,  -1,  -1, -1,
				-2,  -2,  -2, -2,
				-3,  -3,  -3, -3,
				-4,  -4,  -4, -4
			};  

			cml::CMatrix<sint8, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<sint8, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<sint8, 4, 4, false> expected_result(expected_res);
			cml::CMatrix<sint8, 4, 4, false> result;


			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input = \n";	
			fprintf(fpTest, "input = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( rhs_MT, fpTest);

			result.fill(0);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( expected_result);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */		
			result = -rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( result);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}
		
	}
	std::cout << "END ---> test_operatornegate\n\n";
	fprintf(fpTest, "END ---> test_operatornegate\n\n");
}


void TEST_CLASS_MATRIX::test_operatormultiplyassign(int doIt)
{
	std::cout << "START ---> test_operatormultiplyassign\n\n";
	fprintf(fpTest, "START ---> test_operatormultiplyassign\n\n");

	std::cout << "Function Name ---> operator*=()  \n\n";
	fprintf(fpTest, "Function Name ---> operator*=()  \n\n");
	if (doIt) 
	{

		/* inp_MT matrix is with internal memory with option EXT_MEM=false and rhs_MT matrix is with external memory with option EXT_MEM=true */
		{

			std::cout << "Test Case ---> Add Matrices of type float --> A *= B, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type float --> A *= B, assign to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			 float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			};  

			 float expected_result[]  =    {   10.f,  10.f,  10.f, 10.f,
				20.f,  20.f,  20.f, 20.f,
				30.f,  30.f,  30.f, 30.f,
				40.f,  40.f,  40.f, 40.f
			};

			cml::CMatrix<float32, 4, 4, true> rhs_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, false> inp_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, false> expected_inp_MT(expected_result);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 (inp_MT) = \n";
			fprintf(fpTest, "input1(inp_MT) = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			std::cout << "input2(rhs_MT) = \n";
			fprintf(fpTest, "input2(rhs_MT) = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";		
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( expected_inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( expected_inp_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT *= rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result (inp_MT) = \n";
			fprintf(fpTest, "actual_result (inp_MT) = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);
		
			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

/* inp_MT matrix is with external memory with option EXT_MEM=true and rhs_MT matrix is also external memory with option EXT_MEM=true */
		{

			std::cout << "Test Case ---> Add Matrices of type float --> A *= B, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type float --> A *= B, assign to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			 float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			};  

			 float expected_result[]  =    {   10.f,  10.f,  10.f, 10.f,
				20.f,  20.f,  20.f, 20.f,
				30.f,  30.f,  30.f, 30.f,
				40.f,  40.f,  40.f, 40.f
			};

			cml::CMatrix<float32, 4, 4, true> rhs_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, true> inp_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, true> expected_inp_MT(expected_result,16);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");


			std::cout << "input1 (inp_MT) = \n";
			fprintf(fpTest, "input1(inp_MT) = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( inp_MT, fpTest);

			std::cout << "input2(rhs_MT) = \n";
			fprintf(fpTest, "input2(rhs_MT) = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";		
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( expected_inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( expected_inp_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT *= rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result (inp_MT) = \n";
			fprintf(fpTest, "actual_result (inp_MT) = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( inp_MT, fpTest);
		
			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

/* inp_MT matrix is with external memory with option EXT_MEM=true and rhs_MT matrix is with internal memory with option EXT_MEM=false */
		{

			std::cout << "Test Case ---> Add Matrices of type float --> A *= B, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrices of type float --> A *= B, assign to this\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			 float racMatrix[]  = {   1.f,  1.f,  1.f, 1.f,
				2.f,  2.f,  2.f, 2.f,
				3.f,  3.f,  3.f, 3.f,
				4.f,  4.f,  4.f, 4.f
			};  

			 float expected_result[]  =    {   10.f,  10.f,  10.f, 10.f,
				20.f,  20.f,  20.f, 20.f,
				30.f,  30.f,  30.f, 30.f,
				40.f,  40.f,  40.f, 40.f
			};

			cml::CMatrix<float32, 4, 4, false> rhs_MT(racMatrix);
			cml::CMatrix<float32, 4, 4, true> inp_MT(racMatrix,16);
			cml::CMatrix<float32, 4, 4, true> expected_inp_MT(expected_result,16);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 (inp_MT) = \n";		
			fprintf(fpTest, "input1(inp_MT) = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( inp_MT, fpTest);

			std::cout << "input2(rhs_MT) = \n";
			fprintf(fpTest, "input2(rhs_MT) = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";		
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";		
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( expected_inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( expected_inp_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT *= rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result (inp_MT) = \n";
			fprintf(fpTest, "actual_result (inp_MT) = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, true >( inp_MT, fpTest);
		
			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = expected_inp_MT.getAlmostEqualRelativeAndAbs(inp_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}


		{
			std::cout << "Test Case ---> Multiply Matrices of type float --> A = A * B, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Multiply Matrices of type float --> A = A * B, assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2, 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2, 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> rhs_MT;
			cml::CMatrix<float32, 2, 2, false> inp_MT;		
			cml::CMatrix<float32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 1;

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 0;
			rhs_MT(1,0) = 0;
			rhs_MT(1,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 1;
			expected_result_MT(0,1) = 0;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 1;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT *= rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = inp_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}


		{
			std::cout << "Test Case ---> Multiply Matrices of type float --> A = A * B, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Multiply Matrices of type float --> A = A * B, assign to this\n\n");

			std::cout << "Data Dimension ---> 3X2, 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 3X2, 2X2\n\n");

			/* Test Case data declarations */
			float32 expected_result[] = { 2, 4,
				3, 6,
				4, 8 };
			cml::CMatrix<float32, 2, 2, false> rhs_MT;
			cml::CMatrix<float32, 3, 2, false> inp_MT;	
			cml::CMatrix<float32, 3, 2, false> result(expected_result);

			/* Set global data */
			initialise_global_data();

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 2;
			rhs_MT(1,0) = 1;
			rhs_MT(1,1) = 2;

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 1;
			inp_MT(1,0) = 1;
			inp_MT(1,1) = 2;
			inp_MT(2,0) = 3;
			inp_MT(2,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 3, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 3, 2, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 3, 2, false >( result);
			check__vMatrixPrint_to_File< float32, 3, 2, false >( result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT *= rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 3, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 3, 2, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = inp_MT.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Multiply Matrices of type int --> A = A * B, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Multiply Matrices of type int --> A = A * B, assign to this\n\n");

			std::cout << "Data Dimension ---> 3X2, 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 3X2, 2X2\n\n");

			/* Test Case data declarations */
			sint32 expected_result[] = { 2, 4,
				3, 6,
				4, 8 };
			cml::CMatrix<sint32, 2, 2, false> rhs_MT;
			cml::CMatrix<sint32, 3, 2, false> inp_MT;	
			cml::CMatrix<sint32, 3, 2, false> result(expected_result);

			/* Set global data */
			initialise_global_data();

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 2;
			rhs_MT(1,0) = 1;
			rhs_MT(1,1) = 2;

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 1;
			inp_MT(1,0) = 1;
			inp_MT(1,1) = 2;
			inp_MT(2,0) = 3;
			inp_MT(2,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 3, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 3, 2, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 3, 2, false >( result);
			check__vMatrixPrint_to_File< sint32, 3, 2, false >( result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT *= rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 3, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 3, 2, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = inp_MT.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Multiply Matrices of type short --> A = A * B, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Multiply Matrices of type short --> A = A * B, assign to this\n\n");

			std::cout << "Data Dimension ---> 3X2, 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 3X2, 2X2\n\n");

			/* Test Case data declarations */
			sint16 expected_result[] = { 2, 4,
				3, 6,
				4, 8 };
			cml::CMatrix<sint16, 2, 2, false> rhs_MT;
			cml::CMatrix<sint16, 3, 2, false> inp_MT;	
			cml::CMatrix<sint16, 3, 2, false> result(expected_result);

			/* Set global data */
			initialise_global_data();

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 2;
			rhs_MT(1,0) = 1;
			rhs_MT(1,1) = 2;

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 1;
			inp_MT(1,0) = 1;
			inp_MT(1,1) = 2;
			inp_MT(2,0) = 3;
			inp_MT(2,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 3, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 3, 2, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 3, 2, false >( result);
			check__vMatrixPrint_to_File< sint16, 3, 2, false >( result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT *= rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 3, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 3, 2, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = inp_MT.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Multiply Matrices of type char --> A = A * B, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Multiply Matrices of type char --> A = A * B, assign to this\n\n");

			std::cout << "Data Dimension ---> 3X2, 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 3X2, 2X2\n\n");

			/* Test Case data declarations */
			sint8 expected_result[] = { 2, 4,
				3, 6,
				4, 8 };
			cml::CMatrix<sint8, 2, 2, false> rhs_MT;
			cml::CMatrix<sint8, 3, 2, false> inp_MT;	
			cml::CMatrix<sint8, 3, 2, false> result(expected_result);

			/* Set global data */
			initialise_global_data();

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 2;
			rhs_MT(1,0) = 1;
			rhs_MT(1,1) = 2;

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 1;
			inp_MT(1,0) = 1;
			inp_MT(1,1) = 2;
			inp_MT(2,0) = 3;
			inp_MT(2,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 3, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 3, 2, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 3, 2, false >( result);
			check__vMatrixPrint_to_File< sint8, 3, 2, false >( result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT *= rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 3, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 3, 2, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = inp_MT.getAlmostEqualRelativeAndAbs(result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

	}
	std::cout << "END ---> test_operatormultiplyassign\n\n";
	fprintf(fpTest, "END ---> test_operatormultiplyassign\n\n");
}

void TEST_CLASS_MATRIX::test_operatormultiply(int doIt)
{
	std::cout << "START ---> test_operatormultiply\n\n";		
	fprintf(fpTest, "START ---> test_operatormultiply\n\n");

	std::cout << "Function Name ---> operator*() \n\n";	
	fprintf(fpTest, "Function Name ---> operator*() \n\n");
	if (doIt) 
	{
		{
			std::cout << "Test Case ---> Multiply Matrices of type float --> result = A * B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Multiply Matrices of type float --> result = A * B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 2X2, 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2, 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> result_MT;
			cml::CMatrix<float32, 2, 2, false> rhs_MT;
			cml::CMatrix<float32, 2, 2, false> inp_MT;		
			cml::CMatrix<float32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 1;

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 0;
			rhs_MT(1,0) = 0;
			rhs_MT(1,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 1;
			expected_result_MT(0,1) = 0;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 1;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT * rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}


		{
			std::cout << "Test Case ---> Multiply Matrices of type float --> result = A * B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Multiply Matrices of type float --> result = A * B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 2X3, 3X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X3, 3X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> result_MT;
			cml::CMatrix<float32, 3, 2, false> rhs_MT;
			cml::CMatrix<float32, 2, 3, false> inp_MT;		
			cml::CMatrix<float32, 2, 2, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 2;
			inp_MT(0,2) = 1;
			inp_MT(1,0) = 2;
			inp_MT(1,1) = 3;
			inp_MT(1,2) = 4;

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 1;
			rhs_MT(1,0) = 1;
			rhs_MT(1,1) = 2;
			rhs_MT(2,0) = 3;
			rhs_MT(2,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 3, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 3, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 3, 2, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 6;
			expected_result_MT(0,1) = 6;
			expected_result_MT(1,0) = 17;
			expected_result_MT(1,1) = 12;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT * rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		{
			std::cout << "Test Case ---> Multiply Matrices of type int --> result = A * B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Multiply Matrices of type int --> result = A * B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 2X3, 3X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X3, 3X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint32, 2, 2, false> result_MT;
			cml::CMatrix<sint32, 3, 2, false> rhs_MT;
			cml::CMatrix<sint32, 2, 3, false> inp_MT;		
			cml::CMatrix<sint32, 2, 2, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 2;
			inp_MT(0,2) = 1;
			inp_MT(1,0) = 2;
			inp_MT(1,1) = 3;
			inp_MT(1,2) = 4;

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 1;
			rhs_MT(1,0) = 1;
			rhs_MT(1,1) = 2;
			rhs_MT(2,0) = 3;
			rhs_MT(2,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 2, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 2, 3, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint32, 3, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint32, 3, 2, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 6;
			expected_result_MT(0,1) = 6;
			expected_result_MT(1,0) = 17;
			expected_result_MT(1,1) = 12;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT * rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( result_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		{
			std::cout << "Test Case ---> Multiply Matrices of type short --> result = A * B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Multiply Matrices of type short --> result = A * B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 2X3, 3X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X3, 3X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint16, 2, 2, false> result_MT;
			cml::CMatrix<sint16, 3, 2, false> rhs_MT;
			cml::CMatrix<sint16, 2, 3, false> inp_MT;		
			cml::CMatrix<sint16, 2, 2, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 2;
			inp_MT(0,2) = 1;
			inp_MT(1,0) = 2;
			inp_MT(1,1) = 3;
			inp_MT(1,2) = 4;

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 1;
			rhs_MT(1,0) = 1;
			rhs_MT(1,1) = 2;
			rhs_MT(2,0) = 3;
			rhs_MT(2,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 2, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 2, 3, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint16, 3, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint16, 3, 2, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 6;
			expected_result_MT(0,1) = 6;
			expected_result_MT(1,0) = 17;
			expected_result_MT(1,1) = 12;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT * rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( result_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		{
			std::cout << "Test Case ---> Multiply Matrices of type char --> result = A * B, without assigning to this\n\n";		
			fprintf(fpTest, "Test Case ---> Multiply Matrices of type char --> result = A * B, without assigning to this\n\n");

			std::cout << "Data Dimension ---> 2X3, 3X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X3, 3X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint8, 2, 2, false> result_MT;
			cml::CMatrix<sint8, 3, 2, false> rhs_MT;
			cml::CMatrix<sint8, 2, 3, false> inp_MT;		
			cml::CMatrix<sint8, 2, 2, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 2;
			inp_MT(0,2) = 1;
			inp_MT(1,0) = 2;
			inp_MT(1,1) = 3;
			inp_MT(1,2) = 4;

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 1;
			rhs_MT(1,0) = 1;
			rhs_MT(1,1) = 2;
			rhs_MT(2,0) = 3;
			rhs_MT(2,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 2, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 2, 3, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint8, 3, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint8, 3, 2, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 6;
			expected_result_MT(0,1) = 6;
			expected_result_MT(1,0) = 17;
			expected_result_MT(1,1) = 12;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT * rhs_MT;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( result_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}
	}
	std::cout << "END ---> test_operatormultiply\n\n";
	fprintf(fpTest, "END ---> test_operatormultiply\n\n");
}

void TEST_CLASS_MATRIX::test_CML_STL_mul(int doIt)
{
	std::cout << "START ---> test_CML_STL_mul\n\n";
	fprintf(fpTest, "START ---> test_CML_STL_mul\n\n");

	std::cout << "Function Name ---> CML_STL_mul() \n\n";
	fprintf(fpTest, "Function Name ---> CML_STL_mul() \n\n");
	if (doIt) 
	{
#if EXT_MEM_TEST_FAIL
		 /* result_MT.CML_STL_mul(inp_MT , rhs_MT) , result_MT(EXT_MEM=false), inp_MT (EXT_MEM=true)  and rhs_MT (EXT_MEM=false) */
		{
			std::cout << "Test Case ---> Multiply Matrices of type float --> result.CML_STL_mul(A , B) and updates product to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Multiply Matrices of type float --> result.CML_STL_mul(A , B) and updates product to result (this)\n\n");

			std::cout << "Data Dimension ---> 2X2, 2X2\n\n";
			fprintf(fpTest, "Data Dimension ---> 2X2, 2X2\n\n");

			float racMatrix[]  = {   1.f,  2.f,
					3.f,  4.f
					};

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> result_MT;
			cml::CMatrix<float32, 2, 2, false> rhs_MT;
			cml::CMatrix<float32, 2, 2, true> inp_MT(racMatrix);
			cml::CMatrix<float32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1.f;
			inp_MT(0,1) = 2.f;
			inp_MT(1,0) = 3.f;
			inp_MT(1,1) = 4.f;

			rhs_MT(0,0) = 1.f;
			rhs_MT(0,1) = 2.f;
			rhs_MT(1,0) = 3.f;
			rhs_MT(1,1) = 4.f;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 7.f;
			expected_result_MT(0,1) = 10.f;
			expected_result_MT(1,0) = 15.f;
			expected_result_MT(1,1) = 22.f;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		  /* Call SUT */
          result_MT.CML_STL_mul(inp_MT , rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}
#endif
		 /* result_MT.CML_STL_mul(inp_MT , rhs_MT) , result_MT(EXT_MEM=false), inp_MT (EXT_MEM=false)  and rhs_MT (EXT_MEM=true) */
		{
			std::cout << "Test Case ---> Multiply Matrices of type float --> result.CML_STL_mul(A , B) and updates product to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Multiply Matrices of type float --> result.CML_STL_mul(A , B) and updates product to result (this)\n\n");

			std::cout << "Data Dimension ---> 2X2, 2X2\n\n";
			fprintf(fpTest, "Data Dimension ---> 2X2, 2X2\n\n");

			float racMatrix[]  = {   0.f,  0.f,
					0.f,  0.f
					};

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> result_MT;
			cml::CMatrix<float32, 2, 2, true> rhs_MT(racMatrix);
			cml::CMatrix<float32, 2, 2, false> inp_MT;
			cml::CMatrix<float32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1.f;
			inp_MT(0,1) = 2.f;
			inp_MT(1,0) = 3.f;
			inp_MT(1,1) = 4.f;

			rhs_MT(0,0) = 1.f;
			rhs_MT(0,1) = 2.f;
			rhs_MT(1,0) = 3.f;
			rhs_MT(1,1) = 4.f;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 7.f;
			expected_result_MT(0,1) = 10.f;
			expected_result_MT(1,0) = 15.f;
			expected_result_MT(1,1) = 22.f;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		  /* Call SUT */
          result_MT.CML_STL_mul(inp_MT , rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}
#if EXT_MEM_TEST_FAIL
		/* result_MT.CML_STL_mul(inp_MT , rhs_MT) , result_MT(EXT_MEM=true), inp_MT (EXT_MEM=false)  and rhs_MT (EXT_MEM=false) */
		{
			std::cout << "Test Case ---> Multiply Matrices of type float --> result.CML_STL_mul(A , B) and updates product to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Multiply Matrices of type float --> result.CML_STL_mul(A , B) and updates product to result (this)\n\n");

			std::cout << "Data Dimension ---> 2X2, 2X2\n\n";
			fprintf(fpTest, "Data Dimension ---> 2X2, 2X2\n\n");

			float racMatrix[]  = {   0.f,  0.f,
					0.f,  0.f
					};

			float racMatrix_res[]  = {   1.f,  1.f,
					1.f,  1.f
					};

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, true> result_MT(racMatrix);
			cml::CMatrix<float32, 2, 2, false> rhs_MT;
			cml::CMatrix<float32, 2, 2, false> inp_MT;
			cml::CMatrix<float32, 2, 2, true> expected_result_MT(racMatrix_res);
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1.f;
			inp_MT(0,1) = 0.f;
			inp_MT(1,0) = 0.f;
			inp_MT(1,1) = 1.f;

			rhs_MT(0,0) = 1.f;
			rhs_MT(0,1) = 0.f;
			rhs_MT(1,0) = 0.f;
			rhs_MT(1,1) = 1.f;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 7.f;
			expected_result_MT(0,1) = 10.f;
			expected_result_MT(1,0) = 15.f;
			expected_result_MT(1,1) = 22.f;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, true >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		  /* Call SUT */
          result_MT.CML_STL_mul(inp_MT , rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, true >( result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		/* in-complete */
			 /* result_MT.CML_STL_mul(inp_MT , rhs_MT) , result_MT(EXT_MEM=true), inp_MT (EXT_MEM=false)  and rhs_MT (EXT_MEM=true) */
		{
			std::cout << "Test Case ---> Multiply Matrices of type float --> result.CML_STL_mul(A , B) and updates product to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Multiply Matrices of type float --> result.CML_STL_mul(A , B) and updates product to result (this)\n\n");

			std::cout << "Data Dimension ---> 2X2, 2X2\n\n";
			fprintf(fpTest, "Data Dimension ---> 2X2, 2X2\n\n");

			float racMatrix[]  = {   0.f,  0.f,
					0.f,  0.f
					};
			float racMatrix_res[]  = {   1.f,  1.f,
					1.f,  1.f
					};

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, true> result_MT;
			cml::CMatrix<float32, 2, 2, true> rhs_MT(racMatrix);
			cml::CMatrix<float32, 2, 2, false> inp_MT;
			cml::CMatrix<float32, 2, 2, true> expected_result_MT(racMatrix_res);
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1.f;
			inp_MT(0,1) = 2.f;
			inp_MT(1,0) = 3.f;
			inp_MT(1,1) = 4.f;

			rhs_MT(0,0) = 1.f;
			rhs_MT(0,1) = 2.f;
			rhs_MT(1,0) = 3.f;
			rhs_MT(1,1) = 4.f;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 7.f;
			expected_result_MT(0,1) = 10.f;
			expected_result_MT(1,0) = 15.f;
			expected_result_MT(1,1) = 22.f;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		  /* Call SUT */
          result_MT.CML_STL_mul(inp_MT , rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}
 

		 /* result_MT.CML_STL_mul(inp_MT , rhs_MT) , result_MT(EXT_MEM=true), inp_MT (EXT_MEM=true)  and rhs_MT (EXT_MEM=true) */
		{
			std::cout << "Test Case ---> Multiply Matrices of type float --> result.CML_STL_mul(A , B) and updates product to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Multiply Matrices of type float --> result.CML_STL_mul(A , B) and updates product to result (this)\n\n");

			std::cout << "Data Dimension ---> 2X2, 2X2\n\n";
			fprintf(fpTest, "Data Dimension ---> 2X2, 2X2\n\n");

			float racMatrix[]  = {   0.f,  0.f,
					0.f,  0.f
					};
			float temp_inp[]  = {   0.f,  0.f,
					0.f,  0.f
					};
			float racMatrix_res[]  = {   1.f,  1.f,
					1.f,  1.f
					};
				float expe_res[]  = {   1.f,  1.f,
					1.f,  1.f
					};

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, true> result_MT(racMatrix_res);
			cml::CMatrix<float32, 2, 2, true> rhs_MT(racMatrix);
			cml::CMatrix<float32, 2, 2, true> inp_MT(temp_inp);
			cml::CMatrix<float32, 2, 2, true> expected_result_MT(expe_res);
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1.f;
			inp_MT(0,1) = 2.f;
			inp_MT(1,0) = 3.f;
			inp_MT(1,1) = 4.f;

			rhs_MT(0,0) = 1.f;
			rhs_MT(0,1) = 2.f;
			rhs_MT(1,0) = 3.f;
			rhs_MT(1,1) = 4.f;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, true >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, true >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 7.f;
			expected_result_MT(0,1) = 10.f;
			expected_result_MT(1,0) = 15.f;
			expected_result_MT(1,1) = 22.f;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, true >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		  /* Call SUT */
          result_MT.CML_STL_mul(inp_MT , rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, true >( result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, true >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}
#endif

		{
			std::cout << "Test Case ---> Multiply Matrices of type float --> result.CML_STL_mul(A , B) and updates product to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Multiply Matrices of type float --> result.CML_STL_mul(A , B) and updates product to result (this)\n\n");

			std::cout << "Data Dimension ---> 2X2, 2X2\n\n";
			fprintf(fpTest, "Data Dimension ---> 2X2, 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> result_MT;
			cml::CMatrix<float32, 2, 2, false> rhs_MT;
			cml::CMatrix<float32, 2, 2, false> inp_MT;
			cml::CMatrix<float32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1.f;
			inp_MT(0,1) = 0.f;
			inp_MT(1,0) = 0.f;
			inp_MT(1,1) = 1.f;

			rhs_MT(0,0) = 1.f;
			rhs_MT(0,1) = 0.f;
			rhs_MT(1,0) = 0.f;
			rhs_MT(1,1) = 1.f;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 1.f;
			expected_result_MT(0,1) = 0.f;
			expected_result_MT(1,0) = 0.f;
			expected_result_MT(1,1) = 1.f;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		  /* Call SUT */
          result_MT.CML_STL_mul(inp_MT , rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Evaluates expression result =  ((A+B)*C - D) by calling add,multiply and sub functions\n\n";
			fprintf(fpTest, "Test Case ---> Evaluates expression result =  ((A+B)*C - D) by calling add,multiply and sub functions\n\n");

			std::cout << "Data Dimension ---> 2X2, 2X3, 3X2\n\n";
			fprintf(fpTest, "Data Dimension ---> 2X2, 2X3, 3X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> result_MT;
			cml::CMatrix<float32, 3, 2, false> rhs_MT;
			cml::CMatrix<float32, 2, 3, false> inp_MT1,inp_MT2;
			cml::CMatrix<float32, 2, 2, false> expected_result_MT;

			cml::CMatrix<float32, 2, 2, false> sub_MT;

			/* Set global data */
			initialise_global_data();

			sub_MT(0,0) = 1.f;
			sub_MT(0,1) = 2.f;
			sub_MT(1,0) = 3.f;
			sub_MT(1,1) = 4.f;

			inp_MT1(0,0) = 1.f;
			inp_MT1(0,1) = 2.f;
			inp_MT1(0,2) = 1.f;
			inp_MT1(1,0) = 2.f;
			inp_MT1(1,1) = 3.f;
			inp_MT1(1,2) = 4.f;

			
			inp_MT2(0,0) = 1.f;
			inp_MT2(0,1) = 2.f;
			inp_MT2(0,2) = 3.f;
			inp_MT2(1,0) = 4.f;
			inp_MT2(1,1) = 5.f;
			inp_MT2(1,2) = 6.f;

			rhs_MT(0,0) = 1.f;
			rhs_MT(0,1) = 1.f;
			rhs_MT(1,0) = 1.f;
			rhs_MT(1,1) = 2.f;
			rhs_MT(2,0) = 3.f;
			rhs_MT(2,1) = 1.f;

			cml::CMatrix<float32, 2, 2, false> t1;
			cml::CMatrix<float32, 2, 3, false> t2;
			
			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 3, false >( inp_MT1);
			check__vMatrixPrint_to_File< float32, 2, 3, false >( inp_MT1, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 2, 3, false >( inp_MT2);
			check__vMatrixPrint_to_File< float32, 2, 3, false >( inp_MT2, fpTest);

			std::cout << "input3 = \n";
			fprintf(fpTest, "input3 = \n");

			check__vMatrixPrint_to_console< float32, 3, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 3, 2, false >( rhs_MT, fpTest);

			std::cout << "input4 = \n";
			fprintf(fpTest, "input4 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( sub_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( sub_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 17.f;
			expected_result_MT(0,1) = 12.f;
			expected_result_MT(1,0) = 41.f;
			expected_result_MT(1,1) = 28.f;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT.CML_STL_sub(t1.CML_STL_mul(t2.CML_STL_add(inp_MT1,inp_MT2),rhs_MT),sub_MT);
			/* 
			   The above function call equivalent to below expression with the result being stored in result_MT.
			   result_MT = ((inp_MT+inp_MT2)*rhs_MT - sub_MT);
			*/

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		{
			std::cout << "Test Case ---> Multiply Matrices of type int --> result.CML_STL_mul(A , B) and updates product to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Multiply Matrices of type int --> result.CML_STL_mul(A , B) and updates product to result (this)\n\n");

			std::cout << "Data Dimension ---> 2X3, 3X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X3, 3X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint32, 2, 2, false> result_MT;
			cml::CMatrix<sint32, 3, 2, false> rhs_MT;
			cml::CMatrix<sint32, 2, 3, false> inp_MT;
			cml::CMatrix<sint32, 2, 2, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 2;
			inp_MT(0,2) = 1;
			inp_MT(1,0) = 2;
			inp_MT(1,1) = 3;
			inp_MT(1,2) = 4;

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 1;
			rhs_MT(1,0) = 1;
			rhs_MT(1,1) = 2;
			rhs_MT(2,0) = 3;
			rhs_MT(2,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 2, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 2, 3, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint32, 3, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint32, 3, 2, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 6;
			expected_result_MT(0,1) = 6;
			expected_result_MT(1,0) = 17;
			expected_result_MT(1,1) = 12;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			result_MT.CML_STL_mul(inp_MT,rhs_MT);


#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( result_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}


		{
			std::cout << "Test Case ---> Multiply Matrices of type short --> result.CML_STL_mul(A , B) and updates product to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Multiply Matrices of type short --> result.CML_STL_mul(A , B) and updates product to result (this)\n\n");

			std::cout << "Data Dimension ---> 2X3, 3X2\n\n";
			fprintf(fpTest, "Data Dimension ---> 2X3, 3X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint16, 2, 2, false> result_MT;
			cml::CMatrix<sint16, 3, 2, false> rhs_MT;
			cml::CMatrix<sint16, 2, 3, false> inp_MT;
			cml::CMatrix<sint16, 2, 2, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 2;
			inp_MT(0,2) = 1;
			inp_MT(1,0) = 2;
			inp_MT(1,1) = 3;
			inp_MT(1,2) = 4;

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 1;
			rhs_MT(1,0) = 1;
			rhs_MT(1,1) = 2;
			rhs_MT(2,0) = 3;
			rhs_MT(2,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 2, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 2, 3, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint16, 3, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint16, 3, 2, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 6;
			expected_result_MT(0,1) = 6;
			expected_result_MT(1,0) = 17;
			expected_result_MT(1,1) = 12;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			result_MT.CML_STL_mul(inp_MT,rhs_MT);


#ifdef ENABLE_PROFILER
			stop_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( result_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		{
			std::cout << "Test Case ---> Multiply Matrices of type char --> result.CML_STL_mul(A , B) and updates product to result (this)\n\n";
			fprintf(fpTest, "Test Case ---> Multiply Matrices of type char --> result.CML_STL_mul(A , B) and updates product to result (this)\n\n");

			std::cout << "Data Dimension ---> 2X3, 3X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X3, 3X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint8, 2, 2, false> result_MT;
			cml::CMatrix<sint8, 3, 2, false> rhs_MT;
			cml::CMatrix<sint8, 2, 3, false> inp_MT;
			cml::CMatrix<sint8, 2, 2, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 2;
			inp_MT(0,2) = 1;
			inp_MT(1,0) = 2;
			inp_MT(1,1) = 3;
			inp_MT(1,2) = 4;

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 1;
			rhs_MT(1,0) = 1;
			rhs_MT(1,1) = 2;
			rhs_MT(2,0) = 3;
			rhs_MT(2,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 2, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 2, 3, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint8, 3, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint8, 3, 2, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 6;
			expected_result_MT(0,1) = 6;
			expected_result_MT(1,0) = 17;
			expected_result_MT(1,1) = 12;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			result_MT.CML_STL_mul(inp_MT,rhs_MT);


#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( result_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

	}
	std::cout << "END ---> test_CML_STL_mul\n\n";
	fprintf(fpTest, "END ---> test_CML_STL_mul\n\n");
}

void TEST_CLASS_MATRIX::test_operatormultiplyassign_with_constant(int doIt)
{
	std::cout << "START ---> test_operatormultiplyassign_with_constant\n\n";		
	fprintf(fpTest, "START ---> test_operatormultiplyassign_with_constant\n\n");

	std::cout << "Function Name ---> operator*=()(scalar_multiply)  \n\n";
	fprintf(fpTest, "Function Name ---> operator*=()(scalar_multiply)  \n\n");
	if (doIt) 
	{
		{
			std::cout << "Test Case ---> Multiply Matrix of type float with constant value --> A = A * scale_value, assign to this \n\n";		
			fprintf(fpTest, "Test Case ---> Multiply Matrix of type float with constant value --> A = A * scale_value, assign to this \n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> inp_MT;		
			cml::CMatrix<float32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 2;
			expected_result_MT(0,1) = 0;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 2;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT *= 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = inp_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Multiply Matrix of type int with constant value --> A = A * scale_value, assign to this \n\n";		
			fprintf(fpTest, "Test Case ---> Multiply Matrix of type int with constant value --> A = A * scale_value, assign to this \n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint32, 2, 2, false> inp_MT;		
			cml::CMatrix<sint32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 2;
			expected_result_MT(0,1) = 0;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 2;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT *= 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = inp_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Multiply Matrix of type short with constant value --> A = A * scale_value, assign to this \n\n";		
			fprintf(fpTest, "Test Case ---> Multiply Matrix of type short with constant value --> A = A * scale_value, assign to this \n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint16, 2, 2, false> inp_MT;		
			cml::CMatrix<sint16, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 2;
			expected_result_MT(0,1) = 0;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 2;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT *= 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = inp_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Multiply Matrix of type char with constant value --> A = A * scale_value, assign to this \n\n";		
			fprintf(fpTest, "Test Case ---> Multiply Matrix of type char with constant value --> A = A * scale_value, assign to this \n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint8, 2, 2, false> inp_MT;		
			cml::CMatrix<sint8, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 2;
			expected_result_MT(0,1) = 0;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 2;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT *= 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = inp_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}
	}
	std::cout << "END ---> test_operatormultiplyassign_with_constant\n\n";
	fprintf(fpTest, "END ---> test_operatormultiplyassign_with_constant\n\n");
}

void TEST_CLASS_MATRIX::test_operatordivideassign_with_constant(int doIt)
{
	std::cout << "START ---> test_operatordivideassign_with_constant\n\n";		
	fprintf(fpTest, "START ---> test_operatordivideassign_with_constant\n\n");

	std::cout << "Function Name ---> operator/=()(scalar_division)  \n\n";		
	fprintf(fpTest, "Function Name ---> operator/=()(scalar_division)  \n\n");
	if (doIt) 
	{
		{
			std::cout << "Test Case ---> Devide Matrix of type float with constant value --> A = A / scale_value, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Devide Matrix of type float with constant value --> A = A / scale_value, assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> inp_MT;		
			cml::CMatrix<float32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 1;
			expected_result_MT(0,1) = 0;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 1;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT /= 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "ctual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = inp_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Devide Matrix of type int with constant value --> A = A / scale_value, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Devide Matrix of type int with constant value --> A = A / scale_value, assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint32, 2, 2, false> inp_MT;		
			cml::CMatrix<sint32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 1;
			expected_result_MT(0,1) = 0;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 1;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT /= 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = inp_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Devide Matrix of type short with constant value --> A = A / scale_value, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Devide Matrix of type short with constant value --> A = A / scale_value, assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint16, 2, 2, false> inp_MT;		
			cml::CMatrix<sint16, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 1;
			expected_result_MT(0,1) = 0;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 1;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT /= 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = inp_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Devide Matrix of type char with constant value --> A = A / scale_value, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Devide Matrix of type char with constant value --> A = A / scale_value, assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint8, 2, 2, false> inp_MT;		
			cml::CMatrix<sint8, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 1;
			expected_result_MT(0,1) = 0;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 1;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT /= 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = inp_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}
	}

	std::cout << "END ---> test_operatordivideassign_with_constant\n\n";
	fprintf(fpTest, "END ---> test_operatordivideassign_with_constant\n\n");
}

void TEST_CLASS_MATRIX::test_operatorAddassign_with_constant(int doIt)
{
	std::cout << "START ---> test_operatorAddassign_with_constant\n\n";		
	fprintf(fpTest, "START ---> test_operatorAddassign_with_constant\n\n");

	std::cout << "Function Name ---> operator+=()(scalar_addition)  \n\n";	
	fprintf(fpTest, "Function Name ---> operator+=()(scalar_addition)  \n\n");
	if (doIt) 
	{
		{
			std::cout << "Test Case ---> Add Matrix of type float with constant value --> A = A + scale_value, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrix of type float with constant value --> A = A + scale_value, assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> inp_MT;		
			cml::CMatrix<float32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 3;
			expected_result_MT(0,1) = 1;
			expected_result_MT(1,0) = 1;
			expected_result_MT(1,1) = 3;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT += 1;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = inp_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Add Matrix of type int with constant value --> A = A + scale_value, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrix of type int with constant value --> A = A + scale_value, assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint32, 2, 2, false> inp_MT;		
			cml::CMatrix<sint32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 3;
			expected_result_MT(0,1) = 1;
			expected_result_MT(1,0) = 1;
			expected_result_MT(1,1) = 3;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT += 1;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = inp_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Add Matrix of type short with constant value --> A = A + scale_value, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrix of type short with constant value --> A = A + scale_value, assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint16, 2, 2, false> inp_MT;		
			cml::CMatrix<sint16, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 3;
			expected_result_MT(0,1) = 1;
			expected_result_MT(1,0) = 1;
			expected_result_MT(1,1) = 3;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT += 1;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = inp_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Add Matrix of type char with constant value --> A = A + scale_value, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrix of type char with constant value --> A = A + scale_value, assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint8, 2, 2, false> inp_MT;		
			cml::CMatrix<sint8, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 3;
			expected_result_MT(0,1) = 1;
			expected_result_MT(1,0) = 1;
			expected_result_MT(1,1) = 3;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT += 1;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = inp_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

	}

	std::cout << "END ---> test_operatorAddassign_with_constant\n\n";
	fprintf(fpTest, "END ---> test_operatorAddassign_with_constant\n\n");
}

void TEST_CLASS_MATRIX::test_operatorsubtractassign_with_constant(int doIt)
{
	std::cout << "START ---> test_operatorsubtractassign_with_constant\n\n";		
	fprintf(fpTest, "START ---> test_operatorsubtractassign_with_constant\n\n");

	std::cout << "Function Name ---> operator-=()(scalar_subtraction)  \n\n";	
	fprintf(fpTest, "Function Name ---> operator-=()(scalar_subtraction)  \n\n");
	if (doIt) 
	{
		{
			std::cout << "Test Case ---> Subtract Matrix of type float with constant value --> A = A - scale_value, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Subtract Matrix of type float with constant value --> A = A - scale_value, assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> inp_MT;		
			cml::CMatrix<float32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 0;
			expected_result_MT(0,1) = -2;
			expected_result_MT(1,0) = -2;
			expected_result_MT(1,1) = 0;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT -= 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = inp_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Subtract Matrix of type int with constant value --> A = A - scale_value, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Subtract Matrix of type int with constant value --> A = A - scale_value, assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint32, 2, 2, false> inp_MT;		
			cml::CMatrix<sint32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 0;
			expected_result_MT(0,1) = -2;
			expected_result_MT(1,0) = -2;
			expected_result_MT(1,1) = 0;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT -= 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = inp_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Subtract Matrix of type short with constant value --> A = A - scale_value, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Subtract Matrix of type short with constant value --> A = A - scale_value, assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint16, 2, 2, false> inp_MT;		
			cml::CMatrix<sint16, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 0;
			expected_result_MT(0,1) = -2;
			expected_result_MT(1,0) = -2;
			expected_result_MT(1,1) = 0;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT -= 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = inp_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Subtract Matrix of type char with constant value --> A = A - scale_value, assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Subtract Matrix of type char with constant value --> A = A - scale_value, assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint8, 2, 2, false> inp_MT;		
			cml::CMatrix<sint8, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 0;
			expected_result_MT(0,1) = -2;
			expected_result_MT(1,0) = -2;
			expected_result_MT(1,1) = 0;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			inp_MT -= 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( inp_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = inp_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

	}
	std::cout << "END ---> test_operatorsubtractassign_with_constant\n\n";
	fprintf(fpTest, "END ---> test_operatorsubtractassign_with_constant\n\n");
}

void TEST_CLASS_MATRIX::test_operatormultiply_with_constant(int doIt)
{
	std::cout << "START ---> test_operatormultiply_with_constant\n\n";		
	fprintf(fpTest, "START ---> test_operatormultiply_with_constant\n\n");

	std::cout << "Function Name ---> operator*()(scalar_multiply)  \n\n";	
	fprintf(fpTest, "Function Name ---> operator*()(scalar_multiply)  \n\n");
	if (doIt) 
	{
		{
			std::cout << "Test Case ---> Multiply Matrix of type float with constant value --> result = A * scale_value, without assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Multiply Matrix of type float with constant value --> result = A * scale_value, without assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> inp_MT;	
			cml::CMatrix<float32, 2, 2, false> result;	
			cml::CMatrix<float32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 2;
			expected_result_MT(0,1) = 0;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 2;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result_MT = \n";	
			fprintf(fpTest, "expected_result_MT = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT * 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( result);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Multiply Matrix of type int with constant value --> result = A * scale_value, without assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Multiply Matrix of type int with constant value --> result = A * scale_value, without assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint32, 2, 2, false> inp_MT;	
			cml::CMatrix<sint32, 2, 2, false> result;	
			cml::CMatrix<sint32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 2;
			expected_result_MT(0,1) = 0;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 2;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result_MT = \n";	
			fprintf(fpTest, "expected_result_MT = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT * 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( result);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Multiply Matrix of type short with constant value --> result = A * scale_value, without assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Multiply Matrix of type short with constant value --> result = A * scale_value, without assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint16, 2, 2, false> inp_MT;	
			cml::CMatrix<sint16, 2, 2, false> result;	
			cml::CMatrix<sint16, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 2;
			expected_result_MT(0,1) = 0;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 2;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result_MT = \n";	
			fprintf(fpTest, "expected_result_MT = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT * 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( result);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Multiply Matrix of type char with constant value --> result = A * scale_value, without assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Multiply Matrix of type char with constant value --> result = A * scale_value, without assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint8, 2, 2, false> inp_MT;	
			cml::CMatrix<sint8, 2, 2, false> result;	
			cml::CMatrix<sint8, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 2;
			expected_result_MT(0,1) = 0;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 2;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result_MT = \n";	
			fprintf(fpTest, "expected_result_MT = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT * 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( result);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

	}
	std::cout << "END ---> test_operatormultiply_with_constant\n\n";
	fprintf(fpTest, "END ---> test_operatormultiply_with_constant\n\n");
}

void TEST_CLASS_MATRIX::test_operatordivide_with_constant(int doIt)
{
	std::cout << "START ---> test_operatordivide_with_constant\n\n";		
	fprintf(fpTest, "START ---> test_operatordivide_with_constant\n\n");

	std::cout << "Function Name ---> operator/()(scalar_devide)  \n\n";	
	fprintf(fpTest, "Function Name ---> operator/()(scalar_devide)  \n\n");
	if (doIt) 
	{
		{
			std::cout << "Test Case ---> Devide Matrix of type float with constant value --> result = A / scale_value, without assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Devide Matrix of type float with constant value --> result = A / scale_value, without assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> inp_MT;	
			cml::CMatrix<float32, 2, 2, false> result;
			cml::CMatrix<float32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 1;
			expected_result_MT(0,1) = 0;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 1;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT/2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( result);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Devide Matrix of type int with constant value --> result = A / scale_value, without assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Devide Matrix of type int with constant value --> result = A / scale_value, without assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint32, 2, 2, false> inp_MT;	
			cml::CMatrix<sint32, 2, 2, false> result;
			cml::CMatrix<sint32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 1;
			expected_result_MT(0,1) = 0;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 1;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT/2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( result);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Devide Matrix of type short with constant value --> result = A / scale_value, without assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Devide Matrix of type short with constant value --> result = A / scale_value, without assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint16, 2, 2, false> inp_MT;	
			cml::CMatrix<sint16, 2, 2, false> result;
			cml::CMatrix<sint16, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 1;
			expected_result_MT(0,1) = 0;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 1;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT/2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( result);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Devide Matrix of type char with constant value --> result = A / scale_value, without assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Devide Matrix of type char with constant value --> result = A / scale_value, without assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint8, 2, 2, false> inp_MT;	
			cml::CMatrix<sint8, 2, 2, false> result;
			cml::CMatrix<sint8, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";		
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 1;
			expected_result_MT(0,1) = 0;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 1;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT/2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( result);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

	}
	std::cout << "END ---> test_operatordivide_with_constant\n\n";
	fprintf(fpTest, "END ---> test_operatordivide_with_constant\n\n");
}

void TEST_CLASS_MATRIX::test_operatorAdd_with_constant(int doIt)
{
	std::cout << "START ---> test_operatorAdd_with_constant\n\n";		
	fprintf(fpTest, "START ---> test_operatorAdd_with_constant\n\n");

	std::cout << "Function Name ---> operator+()(scalar_addition)  \n\n";	
	fprintf(fpTest, "Function Name ---> operator+()(scalar_addition)  \n\n");
	if (doIt) 
	{
		{
			std::cout << "Test Case ---> Add Matrix of type float with constant value --> result = A + scale_value, without assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrix of type float with constant value --> result = A + scale_value, without assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> inp_MT;
			cml::CMatrix<float32, 2, 2, false> result;
			cml::CMatrix<float32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 3;
			expected_result_MT(0,1) = 1;
			expected_result_MT(1,0) = 1;
			expected_result_MT(1,1) = 3;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT + 1;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( result);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Add Matrix of type int with constant value --> result = A + scale_value, without assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrix of type int with constant value --> result = A + scale_value, without assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint32, 2, 2, false> inp_MT;
			cml::CMatrix<sint32, 2, 2, false> result;
			cml::CMatrix<sint32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 3;
			expected_result_MT(0,1) = 1;
			expected_result_MT(1,0) = 1;
			expected_result_MT(1,1) = 3;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT + 1;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( result);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Add Matrix of type short with constant value --> result = A + scale_value, without assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrix of type short with constant value --> result = A + scale_value, without assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint16, 2, 2, false> inp_MT;
			cml::CMatrix<sint16, 2, 2, false> result;
			cml::CMatrix<sint16, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 3;
			expected_result_MT(0,1) = 1;
			expected_result_MT(1,0) = 1;
			expected_result_MT(1,1) = 3;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT + 1;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( result);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Add Matrix of type char with constant value --> result = A + scale_value, without assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Add Matrix of type char with constant value --> result = A + scale_value, without assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint8, 2, 2, false> inp_MT;
			cml::CMatrix<sint8, 2, 2, false> result;
			cml::CMatrix<sint8, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 3;
			expected_result_MT(0,1) = 1;
			expected_result_MT(1,0) = 1;
			expected_result_MT(1,1) = 3;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT + 1;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( result);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

	}
	std::cout << "END ---> test_operatorAdd_with_constant\n\n";
	fprintf(fpTest, "END ---> test_operatorAdd_with_constant\n\n");
}

void TEST_CLASS_MATRIX::test_operatorsubtract_with_constant(int doIt)
{
	std::cout << "START ---> test_operatorsubtract_with_constant\n\n";		
	fprintf(fpTest, "START ---> test_operatorsubtract_with_constant\n\n");

	std::cout << "Function Name ---> operator-()(scalar_subtraction)  \n\n";	
	fprintf(fpTest, "Function Name ---> operator-()(scalar_subtraction)  \n\n");
	if (doIt) 
	{
		{
			std::cout << "Test Case ---> Subtract Matrix of type float with constant value --> result = A - scale_value, without assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Subtract Matrix of type float with constant value --> result = A - scale_value, without assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> inp_MT;	
			cml::CMatrix<float32, 2, 2, false> result;
			cml::CMatrix<float32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 0;
			expected_result_MT(0,1) = -2;
			expected_result_MT(1,0) = -2;
			expected_result_MT(1,1) = 0;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT - 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( result);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Subtract Matrix of type int with constant value --> result = A - scale_value, without assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Subtract Matrix of type int with constant value --> result = A - scale_value, without assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint32, 2, 2, false> inp_MT;	
			cml::CMatrix<sint32, 2, 2, false> result;
			cml::CMatrix<sint32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 0;
			expected_result_MT(0,1) = -2;
			expected_result_MT(1,0) = -2;
			expected_result_MT(1,1) = 0;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT - 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( result);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Subtract Matrix of type short with constant value --> result = A - scale_value, without assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Subtract Matrix of type short with constant value --> result = A - scale_value, without assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint16, 2, 2, false> inp_MT;	
			cml::CMatrix<sint16, 2, 2, false> result;
			cml::CMatrix<sint16, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 0;
			expected_result_MT(0,1) = -2;
			expected_result_MT(1,0) = -2;
			expected_result_MT(1,1) = 0;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT - 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( result);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Subtract Matrix of type char with constant value --> result = A - scale_value, without assign to this\n\n";		
			fprintf(fpTest, "Test Case ---> Subtract Matrix of type char with constant value --> result = A - scale_value, without assign to this\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint8, 2, 2, false> inp_MT;	
			cml::CMatrix<sint8, 2, 2, false> result;
			cml::CMatrix<sint8, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 2;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 2;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 0;
			expected_result_MT(0,1) = -2;
			expected_result_MT(1,0) = -2;
			expected_result_MT(1,1) = 0;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = inp_MT - 2;

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( result);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

	}
	std::cout << "END ---> test_operatorsubtract_with_constant\n\n";
	fprintf(fpTest, "END ---> test_operatorsubtract_with_constant\n\n");
}

void TEST_CLASS_MATRIX::test_getCholesky(int doIt)
{
	std::cout << "START ---> test_getCholesky\n\n";		
	fprintf(fpTest, "START ---> test_getCholesky\n\n");

	std::cout << "Function Name ---> getCholesky()  \n\n";	
	fprintf(fpTest, "Function Name ---> getCholesky()  \n\n");
	if (doIt) 
	{
		{
			std::cout << "Test Case ---> Cholesky factorization of int Matrix --> result = cholesky(A)\n\n";		
			fprintf(fpTest, "Test Case ---> Cholesky factorization of int Matrix --> result = cholesky(A)\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			
	/*		const sint32 racMatrix2[]  = {  1,   2,   3,   4, 
				2,  29,  36,  43,
				3,  36, 109, 126,
				4,  43, 126, 246,
			};   

			const sint32 expected_res2[]  = {  1,  0,  0,  0,
				2,  5,  0,  0,
				3,  6,  8,  0,
				4,  7,  9, 10,
			};   
*/
           const sint32 racMatrix2[]  = {  1,   4,   5,   6,
	4,  32,  40,  48,
	5,  40,  75,  90,
	6,  48,  90, 144,
	};

	const sint32 expected_res2[]  = {  1,  0,  0,  0,
	4,  4,  0,  0,
	5,  5,  5,  0,
	6,  6,  6,  6,
	}; 


			cml::CMatrix<sint32, 4, 4, false> result_MT2;
			cml::CMatrix<sint32, 4, 4, false> inp_MT2(racMatrix2);
			cml::CMatrix<sint32, 4, 4, false> expected_result2(expected_res2);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( inp_MT2);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( inp_MT2, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( expected_result2);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( expected_result2, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT2 = inp_MT2.getCholesky();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( result_MT2);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( result_MT2, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT2.getAlmostEqualRelativeAndAbs(expected_result2);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Cholesky factorization of float Matrix --> result = cholesky(A)\n\n";		
			fprintf(fpTest, "Test Case ---> Cholesky factorization of float Matrix --> result = cholesky(A)\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */

			const float racMatrix1[]  = {  1.f,   4.f,   5.f,   6.f, 
				4.f,  32.f,  40.f,  48.f,
				5.f,  40.f,  75.f,  90.f,
				6.f,  48.f,  90.f, 144.f,
			};   

			const float expected_res1[]  = {  1.f,  0.f,  0.f,  0.f,
				4.f,  4.f,  0.f,  0.f,
				5.f,  5.f,  5.f,  0.f,
				6.f,  6.f,  6.f,  6.f,
			};   

			cml::CMatrix<float32, 4, 4, false> result_MT1;
			cml::CMatrix<float32, 4, 4, false> inp_MT1(racMatrix1);
			cml::CMatrix<float32, 4, 4, false> expected_result1(expected_res1);
			
			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT1);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT1, fpTest);
			
			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( expected_result1);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( expected_result1, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT1 = inp_MT1.getCholesky();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
			
			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( result_MT1);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( result_MT1, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT1.getAlmostEqualRelativeAndAbs(expected_result1);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}		

		{
			std::cout << "Test Case ---> Cholesky factorization of float Matrix --> result = cholesky(A)\n\n";		
			fprintf(fpTest, "Test Case ---> Cholesky factorization of float Matrix --> result = cholesky(A)\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			const float racMatrix2[]  = { 1e-20F,   2.f,   3.f,   4.f, 
				2.f, 1e-20F,  36.f,  43.f,
				3.f,  36.f, 1e-20F, 126.f,
				4.f,  43.f, 126.f, 1e-20F,
			};   

			const float expected_res[]  = {  1.f,  0.f,  0.f,  0.f,
				2.f,  5.f,  0.f,  0.f,
				3.f,  6.f,  8.f,  0.f,
				4.f,  7.f,  9.f, 10.f,
			};   

			cml::CMatrix<float32, 4, 4, false> result_MT;
			cml::CMatrix<float32, 4, 4, false> inp_MT(racMatrix2);
			cml::CMatrix<float32, 4, 4, false> expected_result(expected_res);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( expected_result);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT.getCholesky();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( result_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result);

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
			std::cout << "Remarks ---> This test case is for coverage purpose, expected result is not relevant, results may differ\n\n";  
			fprintf(fpTest, "Remarks ---> This test case is for coverage purpose, expected result is not relevant, results may differ\n\n");
		}

		{
			std::cout << "Test Case ---> Cholesky factorization of float Matrix --> result = cholesky(A)\n\n";		
			fprintf(fpTest, "Test Case ---> Cholesky factorization of float Matrix --> result = cholesky(A)\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			
			const float racMatrix2[]  = {  1.f,   2.f,   3.f,   4.f, 
				2.f,  29.f,  36.f,  43.f,
				3.f,  36.f, 109.f, 126.f,
				4.f,  43.f, 126.f, 246.f,
			};   

			const float expected_res2[]  = {  1.f,  0.f,  0.f,  0.f,
				2.f,  5.f,  0.f,  0.f,
				3.f,  6.f,  8.f,  0.f,
				4.f,  7.f,  9.f, 10.f,
			};   

			cml::CMatrix<float32, 4, 4, false> result_MT2;
			cml::CMatrix<float32, 4, 4, false> inp_MT2(racMatrix2);
			cml::CMatrix<float32, 4, 4, false> expected_result2(expected_res2);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */			
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT2);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT2, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( expected_result2);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( expected_result2, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT2 = inp_MT2.getCholesky();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( result_MT2);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( result_MT2, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT2.getAlmostEqualRelativeAndAbs(expected_result2);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		

		{
			std::cout << "Test Case ---> Cholesky factorization of short Matrix --> result = cholesky(A)\n\n";		
			fprintf(fpTest, "Test Case ---> Cholesky factorization of short Matrix --> result = cholesky(A)\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			
/*			const sint16 racMatrix2[]  = {  1,   2,   3,   4, 
				2,  29,  36,  43,
				3,  36, 109, 126,
				4,  43, 126, 246,
			}; */  

			const sint16 racMatrix2[]  = {  1,   4,   5,   6,
					4,  32,  40,  48,
					5,  40,  75,  90,
					6,  48,  90, 144
			};

			const sint16 expected_res2[]  = {  1,  0,  0,  0,
				2,  5,  0,  0,
				3,  6,  8,  0,
				4,  7,  9, 10,
			};   

			cml::CMatrix<sint16, 4, 4, false> result_MT2;
			cml::CMatrix<sint16, 4, 4, false> inp_MT2(racMatrix2);
			cml::CMatrix<sint16, 4, 4, false> expected_result2(expected_res2);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( inp_MT2);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( inp_MT2, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( expected_result2);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( expected_result2, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT2 = inp_MT2.getCholesky();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( result_MT2);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( result_MT2, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT2.getAlmostEqualRelativeAndAbs(expected_result2);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Cholesky factorization of char Matrix --> result = cholesky(A)\n\n";		
			fprintf(fpTest, "Test Case ---> Cholesky factorization of char Matrix --> result = cholesky(A)\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			
			const sint8 racMatrix2[]  = {  1,   2,   3,   4, 
				2,  29,  36,  43,
				3,  36, 109, 126,
				4,  43, 126, 246,
			};   

			const sint8 expected_res2[]  = {  1,  0,  0,  0,
				2,  5,  0,  0,
				3,  6,  8,  0,
				4,  7,  9, 10,
			};   

			cml::CMatrix<sint8, 4, 4, false> result_MT2;
			cml::CMatrix<sint8, 4, 4, false> inp_MT2(racMatrix2);
			cml::CMatrix<sint8, 4, 4, false> expected_result2(expected_res2);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( inp_MT2);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( inp_MT2, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( expected_result2);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( expected_result2, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT2 = inp_MT2.getCholesky();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( result_MT2);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( result_MT2, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT2.getAlmostEqualRelativeAndAbs(expected_result2);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

	}
	std::cout << "END ---> test_getCholesky\n\n";
	fprintf(fpTest, "END ---> test_getCholesky\n\n");
}

void TEST_CLASS_MATRIX::test_getLowTriaSqr(int doIt)
{
	std::cout << "START ---> test_getLowTriaSqr\n\n";		
	fprintf(fpTest, "START ---> test_getLowTriaSqr\n\n");

	std::cout << "Function Name ---> getLowTriaSqr() \n\n";
	fprintf(fpTest, "Function Name ---> getLowTriaSqr() \n\n");
	if (doIt) 
	{
		{
			std::cout << "Test Case ---> Low triangular square of type float\n\n";		
			fprintf(fpTest, "Test Case ---> Low triangular square of type float\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */

			const float racMatrix1[]  = {  1.f,   0.f,   0.f,   0.f, 
				4.f,  32.f,  0.f,  0.f,
				5.f,  40.f,  75.f,  0.f,
				6.f,  48.f,  90.f, 144.f,
			};   

			const float expected_res1[]  = { 1.f,   4.f,      5.f,     6.f,
				4.f, 1040.f,  1300.f,  1560.f,
				5.f, 1300.f,  7250.f,  8700.f,
				6.f, 1560.f,  8700.f, 31176.f,
			};   

			cml::CMatrix<float32, 4, 4, false> result_MT1;
			cml::CMatrix<float32, 4, 4, false> inp_MT1(racMatrix1);
			cml::CMatrix<float32, 4, 4, false> expected_result1(expected_res1);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT1);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT1, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( expected_result1);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( expected_result1, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT1 = inp_MT1.getLowTriaSqr();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( result_MT1);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( result_MT1, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT1.getAlmostEqualRelativeAndAbs(expected_result1);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Low triangular square of type int\n\n";		
			fprintf(fpTest, "Test Case ---> Low triangular square of type int\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */

			const sint32 racMatrix1[]  = {  1,   0,   0,   0, 
				4,  32,  0,  0,
				5,  40,  75,  0,
				6,  48,  90, 144,
			};   

			const sint32 expected_res1[]  = { 1,   4,      5,     6,
				4, 1040,  1300,  1560,
				5, 1300,  7250,  8700,
				6, 1560,  8700, 31176,
			};   

			cml::CMatrix<sint32, 4, 4, false> result_MT1;
			cml::CMatrix<sint32, 4, 4, false> inp_MT1(racMatrix1);
			cml::CMatrix<sint32, 4, 4, false> expected_result1(expected_res1);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( inp_MT1);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( inp_MT1, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( expected_result1);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( expected_result1, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT1 = inp_MT1.getLowTriaSqr();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( result_MT1);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( result_MT1, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT1.getAlmostEqualRelativeAndAbs(expected_result1);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Low triangular square of type short\n\n";		
			fprintf(fpTest, "Test Case ---> Low triangular square of type short\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */

			const sint16 racMatrix1[]  = {  1,   0,   0,   0, 
				4,  32,  0,  0,
				5,  40,  75,  0,
				6,  48,  90, 144,
			};   

			const sint16 expected_res1[]  = { 1,   4,      5,     6,
				4, 1040,  1300,  1560,
				5, 1300,  7250,  8700,
				6, 1560,  8700, 31176,
			};   

			cml::CMatrix<sint16, 4, 4, false> result_MT1;
			cml::CMatrix<sint16, 4, 4, false> inp_MT1(racMatrix1);
			cml::CMatrix<sint16, 4, 4, false> expected_result1(expected_res1);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( inp_MT1);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( inp_MT1, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( expected_result1);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( expected_result1, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT1 = inp_MT1.getLowTriaSqr();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( result_MT1);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( result_MT1, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT1.getAlmostEqualRelativeAndAbs(expected_result1);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Low triangular square of type char\n\n";		
			fprintf(fpTest, "Test Case ---> Low triangular square of type char\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */

			const sint8 racMatrix1[]  = {  1,   0,   0,   0, 
				4,  32,  0,  0,
				5,  40,  75,  0,
				6,  48,  90, 144,
			};   

			const sint8 expected_res1[]  = { 1,   4,      5,     6,
				4, 1040,  1300,  1560,
				5, 1300,  7250,  8700,
				6, 1560,  8700, 31176,
			};   

			cml::CMatrix<sint8, 4, 4, false> result_MT1;
			cml::CMatrix<sint8, 4, 4, false> inp_MT1(racMatrix1);
			cml::CMatrix<sint8, 4, 4, false> expected_result1(expected_res1);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( inp_MT1);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( inp_MT1, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( expected_result1);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( expected_result1, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT1 = inp_MT1.getLowTriaSqr();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( result_MT1);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( result_MT1, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT1.getAlmostEqualRelativeAndAbs(expected_result1);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

	}
	std::cout << "END ---> test_getLowTriaSqr\n\n";
	fprintf(fpTest, "END ---> test_getLowTriaSqr\n\n");
}


void TEST_CLASS_MATRIX::test_getUppTriaSqr(int doIt)
{
	std::cout << "START ---> test_getUppTriaSqr\n\n";		
	fprintf(fpTest, "START ---> test_getUppTriaSqr\n\n");

	std::cout << "Function Name ---> getUppTriaSqr() \n\n";		
	fprintf(fpTest, "Function Name ---> getUppTriaSqr() \n\n");
	if (doIt) 
	{

		{
			std::cout << "Test Case ---> Upper triangular square of type float\n\n";		
			fprintf(fpTest, "Test Case ---> Upper triangular square of type float\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */

			const float racMatrix1[]  = {  1.f,   4.f,   5.f,   6.f, 
				0.f,  32.f,  40.f,  48.f,
				0.f,   0.f,  75.f,  90.f,
				0.f,   0.f,   0.f, 144.f,
			};   

			const float expected_res1[]  = {  78.f,   616.f,    915.f,    864.f,
				616.f,  4928.f,   7320.f,   6912.f,
				915.f,  7320.f,  13725.f,  12960.f,
				864.f,  6912.f,  12960.f,  20736.f,
			};   

			cml::CMatrix<float32, 4, 4, false> result_MT1;
			cml::CMatrix<float32, 4, 4, false> expected_result1(expected_res1);
			cml::CMatrix<float32, 4, 4, false> inp_MT1(racMatrix1);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT1);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT1, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( expected_result1);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( expected_result1, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT1 = inp_MT1.getUppTriaSqr();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( result_MT1);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( result_MT1, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT1.getAlmostEqualRelativeAndAbs(expected_result1);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Upper triangular square of type int\n\n";		
			fprintf(fpTest, "Test Case ---> Upper triangular square of type int\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */

			const sint32 racMatrix1[]  = {  1,   4,   5,   6, 
				0,  32,  40,  48,
				0,   0,  75,  90,
				0,   0,   0, 144,
			};   

			const sint32 expected_res1[]  = {  78,   616,    915,    864,
				616,  4928,   7320,   6912,
				915,  7320,  13725,  12960,
				864,  6912,  12960,  20736,
			};   

			cml::CMatrix<sint32, 4, 4, false> result_MT1;
			cml::CMatrix<sint32, 4, 4, false> expected_result1(expected_res1);
			cml::CMatrix<sint32, 4, 4, false> inp_MT1(racMatrix1);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( inp_MT1);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( inp_MT1, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( expected_result1);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( expected_result1, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT1 = inp_MT1.getUppTriaSqr();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( result_MT1);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( result_MT1, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT1.getAlmostEqualRelativeAndAbs(expected_result1);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Upper triangular square of type short\n\n";		
			fprintf(fpTest, "Test Case ---> Upper triangular square of type short\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */

			const sint16 racMatrix1[]  = {  1,   4,   5,   6, 
				0,  32,  40,  48,
				0,   0,  75,  90,
				0,   0,   0, 144,
			};   

			const sint16 expected_res1[]  = {  78,   616,    915,    864,
				616,  4928,   7320,   6912,
				915,  7320,  13725,  12960,
				864,  6912,  12960,  20736,
			};   

			cml::CMatrix<sint16, 4, 4, false> result_MT1;
			cml::CMatrix<sint16, 4, 4, false> expected_result1(expected_res1);
			cml::CMatrix<sint16, 4, 4, false> inp_MT1(racMatrix1);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( inp_MT1);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( inp_MT1, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( expected_result1);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( expected_result1, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT1 = inp_MT1.getUppTriaSqr();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( result_MT1);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( result_MT1, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT1.getAlmostEqualRelativeAndAbs(expected_result1);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Upper triangular square of type char\n\n";		
			fprintf(fpTest, "Test Case ---> Upper triangular square of type char\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */

			const sint8 racMatrix1[]  = {  1,   4,   5,   6, 
				0,  32,  40,  48,
				0,   0,  75,  90,
				0,   0,   0, 144,
			};   

			const sint8 expected_res1[]  = {  78,   616,    915,    864,
				616,  4928,   7320,   6912,
				915,  7320,  13725,  12960,
				864,  6912,  12960,  20736,
			};   

			cml::CMatrix<sint8, 4, 4, false> result_MT1;
			cml::CMatrix<sint8, 4, 4, false> expected_result1(expected_res1);
			cml::CMatrix<sint8, 4, 4, false> inp_MT1(racMatrix1);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( inp_MT1);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( inp_MT1, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( expected_result1);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( expected_result1, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT1 = inp_MT1.getUppTriaSqr();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( result_MT1);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( result_MT1, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT1.getAlmostEqualRelativeAndAbs(expected_result1);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

	}
	std::cout << "END ---> test_getUppTriaSqr\n\n";
	fprintf(fpTest, "END ---> test_getUppTriaSqr\n\n");
}

void TEST_CLASS_MATRIX::test_transpose(int doIt)
{
	std::cout << "START ---> test_transpose\n\n";		
	fprintf(fpTest, "START ---> test_transpose\n\n");

	std::cout << "Function Name ---> transpose() \n\n";	
	fprintf(fpTest, "Function Name ---> transpose() \n\n");
	if (doIt) 
	{

		{
			std::cout << "Test Case ---> Transpose of a Matrix of type float --> result = Transpose(A)\n\n";
			fprintf(fpTest, "Test Case ---> Transpose of a Matrix of type float --> result = Transpose(A)\n\n");

			std::cout << "Data Dimension ---> 3X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 3X2\n\n");

			/* Test Case data declarations */
			float input[] = {1,2,3,
				2,3,4};

			float result[] = {1,2,
				2,3,
				3,4};

			cml::CMatrix<float32, 2, 3, false> inp_MT(input);		
			cml::CMatrix<float32, 3, 2, false> expected_result_MT(result);
			cml::CMatrix<float32, 3, 2, false> result_MT;

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 3, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 3, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 3, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT.transpose();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 3, 2, false >( result_MT);
			check__vMatrixPrint_to_File< float32, 3, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Transpose of a Matrix of type int --> result = Transpose(A)\n\n";
			fprintf(fpTest, "Test Case ---> Transpose of a Matrix of type int --> result = Transpose(A)\n\n");

			std::cout << "Data Dimension ---> 3X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 3X2\n\n");

			/* Test Case data declarations */
			sint32 input[] = {1,2,3,
				2,3,4};

			sint32 result[] = {1,2,
				2,3,
				3,4};

			cml::CMatrix<sint32, 2, 3, false> inp_MT(input);		
			cml::CMatrix<sint32, 3, 2, false> expected_result_MT(result);
			cml::CMatrix<sint32, 3, 2, false> result_MT;

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 2, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 2, 3, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 3, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint32, 3, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT.transpose();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 3, 2, false >( result_MT);
			check__vMatrixPrint_to_File< sint32, 3, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Transpose of a Matrix of type short --> result = Transpose(A)\n\n";
			fprintf(fpTest, "Test Case ---> Transpose of a Matrix of type short --> result = Transpose(A)\n\n");

			std::cout << "Data Dimension ---> 3X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 3X2\n\n");

			/* Test Case data declarations */
			sint16 input[] = {1,2,3,
				2,3,4};

			sint16 result[] = {1,2,
				2,3,
				3,4};

			cml::CMatrix<sint16, 2, 3, false> inp_MT(input);		
			cml::CMatrix<sint16, 3, 2, false> expected_result_MT(result);
			cml::CMatrix<sint16, 3, 2, false> result_MT;

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 2, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 2, 3, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 3, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint16, 3, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT.transpose();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 3, 2, false >( result_MT);
			check__vMatrixPrint_to_File< sint16, 3, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> Transpose of a Matrix of type char --> result = Transpose(A)\n\n";
			fprintf(fpTest, "Test Case ---> Transpose of a Matrix of type char --> result = Transpose(A)\n\n");

			std::cout << "Data Dimension ---> 3X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 3X2\n\n");

			/* Test Case data declarations */
			sint8 input[] = {1,2,3,
				2,3,4};

			sint8 result[] = {1,2,
				2,3,
				3,4};

			cml::CMatrix<sint8, 2, 3, false> inp_MT(input);		
			cml::CMatrix<sint8, 3, 2, false> expected_result_MT(result);
			cml::CMatrix<sint8, 3, 2, false> result_MT;

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 2, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 2, 3, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 3, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint8, 3, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT.transpose();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 3, 2, false >( result_MT);
			check__vMatrixPrint_to_File< sint8, 3, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

	}
	std::cout << "END ---> test_transpose\n\n";
	fprintf(fpTest, "END ---> test_transpose\n\n");
}

void TEST_CLASS_MATRIX::test_mulSym(int doIt)
{
	std::cout << "START ---> test_mulSym\n\n";		
	fprintf(fpTest, "START ---> test_mulSym\n\n");

	std::cout << "Function Name ---> mulSym() \n\n";		
	fprintf(fpTest, "Function Name ---> mulSym() \n\n");
	if (doIt) 
	{

		{
			std::cout << "Test Case ---> Multiplication of two matrices type float if the result is known to be a symmetric   --> result  = A * B\n\n";
			fprintf(fpTest, "Test Case ---> Multiplication of two matrices type float if the result is known to be a symmetric   --> result  = A * B\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> result_MT;
			cml::CMatrix<float32, 2, 2, false> rhs_MT;
			cml::CMatrix<float32, 2, 2, false> inp_MT;		
			cml::CMatrix<float32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 1;

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 0;
			rhs_MT(1,0) = 0;
			rhs_MT(1,1) = 1;


			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();
			expected_result_MT(0,0) = 1;
			expected_result_MT(0,1) = 0;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 1;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT.mulSym(rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		{
			std::cout << "Test Case ---> Multiplication of two matrices type float if the result is known to be a symmetric   --> result  = A * B\n\n";
			fprintf(fpTest, "Test Case ---> Multiplication of two matrices type float if the result is known to be a symmetric   --> result  = A * B\n\n");

			std::cout << "Data Dimension ---> 3X3\n\n";		
			fprintf(fpTest, "Data Dimension ---> 3X3\n\n");

			/* Test Case data declarations */
			const float racMatrix1[]  = {  1.f,  1.f,  1.f,
				2.f,  2.f,  2.f,
				3.f,  3.f,  3.f,
			};   

			const float racMatrix2[]  = {  1.f,  2.f,  3.f,
				1.f,  2.f,  3.f,
				1.f,  2.f,  3.f,
			};   

			float racResult[]   = {  3,  6,  9,
				6, 12, 18,
				9, 18, 27,
			};  

			cml::CMatrix<float32, 3, 3, false> result_MT;
			cml::CMatrix<float32, 3, 3, false> rhs_MT(racMatrix2);
			cml::CMatrix<float32, 3, 3, false> inp_MT(racMatrix1);		
			cml::CMatrix<float32, 3, 3, false> expected_result_MT(racResult);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 3, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 3, 3, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 3, 3, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 3, 3, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 3, 3, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 3, 3, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT.mulSym(rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 3, 3, false >( result_MT);
			check__vMatrixPrint_to_File< float32, 3, 3, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		{
			std::cout << "Test Case ---> Multiplication of two matrices type int if the result is known to be a symmetric   --> result  = A * B\n\n";
			fprintf(fpTest, "Test Case ---> Multiplication of two matrices type int if the result is known to be a symmetric   --> result  = A * B\n\n");

			std::cout << "Data Dimension ---> 3X3\n\n";		
			fprintf(fpTest, "Data Dimension ---> 3X3\n\n");

			/* Test Case data declarations */
			const sint32 racMatrix1[]  = {  1.f,  1.f,  1.f,
				2.f,  2.f,  2.f,
				3.f,  3.f,  3.f,
			};   

			const sint32 racMatrix2[]  = {  1.f,  2.f,  3.f,
				1.f,  2.f,  3.f,
				1.f,  2.f,  3.f,
			};   

			sint32 racResult[]   = {  3,  6,  9,
				6, 12, 18,
				9, 18, 27,
			};  

			cml::CMatrix<sint32, 3, 3, false> result_MT;
			cml::CMatrix<sint32, 3, 3, false> rhs_MT(racMatrix2);
			cml::CMatrix<sint32, 3, 3, false> inp_MT(racMatrix1);		
			cml::CMatrix<sint32, 3, 3, false> expected_result_MT(racResult);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 3, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 3, 3, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint32, 3, 3, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint32, 3, 3, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 3, 3, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint32, 3, 3, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT.mulSym(rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 3, 3, false >( result_MT);
			check__vMatrixPrint_to_File< sint32, 3, 3, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		{
			std::cout << "Test Case ---> Multiplication of two matrices type short if the result is known to be a symmetric   --> result  = A * B\n\n";
			fprintf(fpTest, "Test Case ---> Multiplication of two matrices type short if the result is known to be a symmetric   --> result  = A * B\n\n");

			std::cout << "Data Dimension ---> 3X3\n\n";		
			fprintf(fpTest, "Data Dimension ---> 3X3\n\n");

			/* Test Case data declarations */
			const sint16 racMatrix1[]  = {  1.f,  1.f,  1.f,
				2.f,  2.f,  2.f,
				3.f,  3.f,  3.f,
			};   

			const sint16 racMatrix2[]  = {  1.f,  2.f,  3.f,
				1.f,  2.f,  3.f,
				1.f,  2.f,  3.f,
			};   

			sint16 racResult[]   = {  3,  6,  9,
				6, 12, 18,
				9, 18, 27,
			};  

			cml::CMatrix<sint16, 3, 3, false> result_MT;
			cml::CMatrix<sint16, 3, 3, false> rhs_MT(racMatrix2);
			cml::CMatrix<sint16, 3, 3, false> inp_MT(racMatrix1);		
			cml::CMatrix<sint16, 3, 3, false> expected_result_MT(racResult);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 3, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 3, 3, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint16, 3, 3, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint16, 3, 3, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 3, 3, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint16, 3, 3, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT.mulSym(rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 3, 3, false >( result_MT);
			check__vMatrixPrint_to_File< sint16, 3, 3, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		{
			std::cout << "Test Case ---> Multiplication of two matrices type char if the result is known to be a symmetric   --> result  = A * B\n\n";
			fprintf(fpTest, "Test Case ---> Multiplication of two matrices type char if the result is known to be a symmetric   --> result  = A * B\n\n");

			std::cout << "Data Dimension ---> 3X3\n\n";		
			fprintf(fpTest, "Data Dimension ---> 3X3\n\n");

			/* Test Case data declarations */
			const sint8 racMatrix1[]  = {  1.f,  1.f,  1.f,
				2.f,  2.f,  2.f,
				3.f,  3.f,  3.f,
			};   

			const sint8 racMatrix2[]  = {  1.f,  2.f,  3.f,
				1.f,  2.f,  3.f,
				1.f,  2.f,  3.f,
			};   

			sint8 racResult[]   = {  3,  6,  9,
				6, 12, 18,
				9, 18, 27,
			};  

			cml::CMatrix<sint8, 3, 3, false> result_MT;
			cml::CMatrix<sint8, 3, 3, false> rhs_MT(racMatrix2);
			cml::CMatrix<sint8, 3, 3, false> inp_MT(racMatrix1);		
			cml::CMatrix<sint8, 3, 3, false> expected_result_MT(racResult);

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 3, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 3, 3, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint8, 3, 3, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint8, 3, 3, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 3, 3, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint8, 3, 3, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT.mulSym(rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 3, 3, false >( result_MT);
			check__vMatrixPrint_to_File< sint8, 3, 3, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}
	}
	std::cout << "END ---> test_mulSym\n\n";
	fprintf(fpTest, "END ---> test_mulSym\n\n");
}

void TEST_CLASS_MATRIX::test_mulTrnsp(int doIt)
{
	std::cout << "START ---> test_mulTrnsp\n\n";		
	fprintf(fpTest, "START ---> test_mulTrnsp\n\n");


	std::cout << "Function Name ---> mulTrnsp()\n\n";		
	fprintf(fpTest, "Function Name ---> mulTrnsp()\n\n");
	if (doIt) 
	{

		{
			std::cout << "Test Case ---> Multiplication of two matrices type float with B transpose   --> result  = A * B'\n\n";
			fprintf(fpTest, "Test Case ---> Multiplication of two matrices type float with B transpose   --> result  = A * B'\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> result_MT;
			cml::CMatrix<float32, 2, 2, false> rhs_MT;
			cml::CMatrix<float32, 2, 2, false> inp_MT;		
			cml::CMatrix<float32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 1;

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 0;
			rhs_MT(1,0) = 0;
			rhs_MT(1,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 1;
			expected_result_MT(0,1) = 0;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 1;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT.mulTrnsp(rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		{
			std::cout << "Test Case ---> Multiplication of two matrices type float with B transpose   --> result  = A * B'\n\n";
			fprintf(fpTest, "Test Case ---> Multiplication of two matrices type float with B transpose   --> result  = A * B'\n\n");

			std::cout << "Data Dimension ---> 2X3, 2X3\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X3, 2X3\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> result_MT;
			cml::CMatrix<float32, 2, 3, false> rhs_MT;
			cml::CMatrix<float32, 2, 3, false> inp_MT;		
			cml::CMatrix<float32, 2, 2, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 2;
			inp_MT(0,2) = 1;
			inp_MT(1,0) = 2;
			inp_MT(1,1) = 3;
			inp_MT(1,2) = 4;

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 1;
			rhs_MT(0,2) = 1;
			rhs_MT(1,0) = 2;
			rhs_MT(1,1) = 3;
			rhs_MT(1,2) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 3, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 2, 3, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 3, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 4;
			expected_result_MT(0,1) = 9;
			expected_result_MT(1,0) = 9;
			expected_result_MT(1,1) = 17;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT.mulTrnsp(rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		{
			std::cout << "Test Case ---> Multiplication of two matrices type int with B transpose   --> result  = A * B'\n\n";
			fprintf(fpTest, "Test Case ---> Multiplication of two matrices type int with B transpose   --> result  = A * B'\n\n");

			std::cout << "Data Dimension ---> 2X3, 2X3\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X3, 2X3\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint32, 2, 2, false> result_MT;
			cml::CMatrix<sint32, 2, 3, false> rhs_MT;
			cml::CMatrix<sint32, 2, 3, false> inp_MT;		
			cml::CMatrix<sint32, 2, 2, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 2;
			inp_MT(0,2) = 1;
			inp_MT(1,0) = 2;
			inp_MT(1,1) = 3;
			inp_MT(1,2) = 4;

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 1;
			rhs_MT(0,2) = 1;
			rhs_MT(1,0) = 2;
			rhs_MT(1,1) = 3;
			rhs_MT(1,2) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 2, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 2, 3, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint32, 2, 3, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint32, 2, 3, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 4;
			expected_result_MT(0,1) = 9;
			expected_result_MT(1,0) = 9;
			expected_result_MT(1,1) = 17;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT.mulTrnsp(rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 2, 2, false >( result_MT);
			check__vMatrixPrint_to_File< sint32, 2, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		{
			std::cout << "Test Case ---> Multiplication of two matrices type short with B transpose   --> result  = A * B'\n\n";
			fprintf(fpTest, "Test Case ---> Multiplication of two matrices type short with B transpose   --> result  = A * B'\n\n");

			std::cout << "Data Dimension ---> 2X3, 2X3\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X3, 2X3\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint16, 2, 2, false> result_MT;
			cml::CMatrix<sint16, 2, 3, false> rhs_MT;
			cml::CMatrix<sint16, 2, 3, false> inp_MT;		
			cml::CMatrix<sint16, 2, 2, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 2;
			inp_MT(0,2) = 1;
			inp_MT(1,0) = 2;
			inp_MT(1,1) = 3;
			inp_MT(1,2) = 4;

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 1;
			rhs_MT(0,2) = 1;
			rhs_MT(1,0) = 2;
			rhs_MT(1,1) = 3;
			rhs_MT(1,2) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 2, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 2, 3, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint16, 2, 3, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint16, 2, 3, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 4;
			expected_result_MT(0,1) = 9;
			expected_result_MT(1,0) = 9;
			expected_result_MT(1,1) = 17;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT.mulTrnsp(rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 2, 2, false >( result_MT);
			check__vMatrixPrint_to_File< sint16, 2, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		{
			std::cout << "Test Case ---> Multiplication of two matrices type char with B transpose   --> result  = A * B'\n\n";
			fprintf(fpTest, "Test Case ---> Multiplication of two matrices type char with B transpose   --> result  = A * B'\n\n");

			std::cout << "Data Dimension ---> 2X3, 2X3\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X3, 2X3\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint8, 2, 2, false> result_MT;
			cml::CMatrix<sint8, 2, 3, false> rhs_MT;
			cml::CMatrix<sint8, 2, 3, false> inp_MT;		
			cml::CMatrix<sint8, 2, 2, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 2;
			inp_MT(0,2) = 1;
			inp_MT(1,0) = 2;
			inp_MT(1,1) = 3;
			inp_MT(1,2) = 4;

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 1;
			rhs_MT(0,2) = 1;
			rhs_MT(1,0) = 2;
			rhs_MT(1,1) = 3;
			rhs_MT(1,2) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 2, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 2, 3, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint8, 2, 3, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint8, 2, 3, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 4;
			expected_result_MT(0,1) = 9;
			expected_result_MT(1,0) = 9;
			expected_result_MT(1,1) = 17;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT.mulTrnsp(rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 2, 2, false >( result_MT);
			check__vMatrixPrint_to_File< sint8, 2, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}
	}
	std::cout << "END ---> test_mulTrnsp\n\n";
	fprintf(fpTest, "END ---> test_mulTrnsp\n\n");
}

void TEST_CLASS_MATRIX::test_trnspMul(int doIt)
{
	std::cout << "START ---> test_trnspMul\n\n";		
	fprintf(fpTest, "START ---> test_trnspMul\n\n");

	std::cout << "Function Name ---> trnspMul()\n\n";	
	fprintf(fpTest, "Function Name ---> trnspMul()\n\n");
	if (doIt) 
	{

		{
			std::cout << "Test Case ---> Multiplication of two matrices type float with A transpose   --> result  = A' * B\n\n";
			fprintf(fpTest, "Test Case ---> Multiplication of two matrices type float with A transpose   --> result  = A' * B\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 2, 2, false> result_MT;
			cml::CMatrix<float32, 2, 2, false> rhs_MT;
			cml::CMatrix<float32, 2, 2, false> inp_MT;		
			cml::CMatrix<float32, 2, 2, false> expected_result_MT;
			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 0;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 1;

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 0;
			rhs_MT(1,0) = 0;
			rhs_MT(1,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 1;
			expected_result_MT(0,1) = 0;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 1;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT.trnspMul(rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		{
			std::cout << "Test Case ---> Multiplication of two matrices type float with A transpose   --> result  = A' * B\n\n";
			fprintf(fpTest, "Test Case ---> Multiplication of two matrices type float with A transpose   --> result  = A' * B\n\n");

			std::cout << "Data Dimension ---> 2X3, 2X3\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X3, 2X3\n\n");

			/* Test Case data declarations */
			cml::CMatrix<float32, 3, 3, false> result_MT;
			cml::CMatrix<float32, 2, 3, false> rhs_MT;
			cml::CMatrix<float32, 2, 3, false> inp_MT;		
			cml::CMatrix<float32, 3, 3, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 2;
			inp_MT(0,2) = 1;
			inp_MT(1,0) = 2;
			inp_MT(1,1) = 3;
			inp_MT(1,2) = 4;

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 1;
			rhs_MT(0,2) = 1;
			rhs_MT(1,0) = 2;
			rhs_MT(1,1) = 3;
			rhs_MT(1,2) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 2, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 3, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< float32, 2, 3, false >( rhs_MT);
			check__vMatrixPrint_to_File< float32, 2, 3, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 5;
			expected_result_MT(0,1) = 7;
			expected_result_MT(0,2) = 3;
			expected_result_MT(1,0) = 8;
			expected_result_MT(1,1) = 11;
			expected_result_MT(1,2) = 5;
			expected_result_MT(2,0) = 9;
			expected_result_MT(2,1) = 13;
			expected_result_MT(2,2) = 5;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 3, 3, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 3, 3, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT.trnspMul(rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 3, 3, false >( result_MT);
			check__vMatrixPrint_to_File< float32, 3, 3, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		{
			std::cout << "Test Case ---> Multiplication of two matrices type int with A transpose   --> result  = A' * B\n\n";
			fprintf(fpTest, "Test Case ---> Multiplication of two matrices type int with A transpose   --> result  = A' * B\n\n");

			std::cout << "Data Dimension ---> 2X3, 2X3\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X3, 2X3\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint32, 3, 3, false> result_MT;
			cml::CMatrix<sint32, 2, 3, false> rhs_MT;
			cml::CMatrix<sint32, 2, 3, false> inp_MT;		
			cml::CMatrix<sint32, 3, 3, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 2;
			inp_MT(0,2) = 1;
			inp_MT(1,0) = 2;
			inp_MT(1,1) = 3;
			inp_MT(1,2) = 4;

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 1;
			rhs_MT(0,2) = 1;
			rhs_MT(1,0) = 2;
			rhs_MT(1,1) = 3;
			rhs_MT(1,2) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 2, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< sint32, 2, 3, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint32, 2, 3, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint32, 2, 3, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 5;
			expected_result_MT(0,1) = 7;
			expected_result_MT(0,2) = 3;
			expected_result_MT(1,0) = 8;
			expected_result_MT(1,1) = 11;
			expected_result_MT(1,2) = 5;
			expected_result_MT(2,0) = 9;
			expected_result_MT(2,1) = 13;
			expected_result_MT(2,2) = 5;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 3, 3, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint32, 3, 3, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT.trnspMul(rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 3, 3, false >( result_MT);
			check__vMatrixPrint_to_File< sint32, 3, 3, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		{
			std::cout << "Test Case ---> Multiplication of two matrices type short with A transpose   --> result  = A' * B\n\n";
			fprintf(fpTest, "Test Case ---> Multiplication of two matrices type short with A transpose   --> result  = A' * B\n\n");

			std::cout << "Data Dimension ---> 2X3, 2X3\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X3, 2X3\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint16, 3, 3, false> result_MT;
			cml::CMatrix<sint16, 2, 3, false> rhs_MT;
			cml::CMatrix<sint16, 2, 3, false> inp_MT;		
			cml::CMatrix<sint16, 3, 3, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 2;
			inp_MT(0,2) = 1;
			inp_MT(1,0) = 2;
			inp_MT(1,1) = 3;
			inp_MT(1,2) = 4;

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 1;
			rhs_MT(0,2) = 1;
			rhs_MT(1,0) = 2;
			rhs_MT(1,1) = 3;
			rhs_MT(1,2) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 2, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< sint16, 2, 3, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint16, 2, 3, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint16, 2, 3, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 5;
			expected_result_MT(0,1) = 7;
			expected_result_MT(0,2) = 3;
			expected_result_MT(1,0) = 8;
			expected_result_MT(1,1) = 11;
			expected_result_MT(1,2) = 5;
			expected_result_MT(2,0) = 9;
			expected_result_MT(2,1) = 13;
			expected_result_MT(2,2) = 5;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 3, 3, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint16, 3, 3, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT.trnspMul(rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 3, 3, false >( result_MT);
			check__vMatrixPrint_to_File< sint16, 3, 3, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		{
			std::cout << "Test Case ---> Multiplication of two matrices type char with A transpose   --> result  = A' * B\n\n";
			fprintf(fpTest, "Test Case ---> Multiplication of two matrices type char with A transpose   --> result  = A' * B\n\n");

			std::cout << "Data Dimension ---> 2X3, 2X3\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X3, 2X3\n\n");

			/* Test Case data declarations */
			cml::CMatrix<sint8, 3, 3, false> result_MT;
			cml::CMatrix<sint8, 2, 3, false> rhs_MT;
			cml::CMatrix<sint8, 2, 3, false> inp_MT;		
			cml::CMatrix<sint8, 3, 3, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 2;
			inp_MT(0,2) = 1;
			inp_MT(1,0) = 2;
			inp_MT(1,1) = 3;
			inp_MT(1,2) = 4;

			rhs_MT(0,0) = 1;
			rhs_MT(0,1) = 1;
			rhs_MT(0,2) = 1;
			rhs_MT(1,0) = 2;
			rhs_MT(1,1) = 3;
			rhs_MT(1,2) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 2, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< sint8, 2, 3, false >( inp_MT, fpTest);

			std::cout << "input2 = \n";	
			fprintf(fpTest, "input2 = \n");

			check__vMatrixPrint_to_console< sint8, 2, 3, false >( rhs_MT);
			check__vMatrixPrint_to_File< sint8, 2, 3, false >( rhs_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_result_MT(0,0) = 5;
			expected_result_MT(0,1) = 7;
			expected_result_MT(0,2) = 3;
			expected_result_MT(1,0) = 8;
			expected_result_MT(1,1) = 11;
			expected_result_MT(1,2) = 5;
			expected_result_MT(2,0) = 9;
			expected_result_MT(2,1) = 13;
			expected_result_MT(2,2) = 5;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 3, 3, false >( expected_result_MT);
			check__vMatrixPrint_to_File< sint8, 3, 3, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result_MT = inp_MT.trnspMul(rhs_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 3, 3, false >( result_MT);
			check__vMatrixPrint_to_File< sint8, 3, 3, false >( result_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}
	}
	std::cout << "END ---> test_trnspMul\n\n";
	fprintf(fpTest, "END ---> test_trnspMul\n\n");
}

//void setIdentity()
void TEST_CLASS_MATRIX::test_setIdentity(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_setIdentity\n\n";
		fprintf(fpTest, "START ---> test_setIdentity\n\n");

		std::cout << "Function Name ---> setIdentity()\n\n";	
	    fprintf(fpTest, "Function Name ---> setIdentity()\n\n");
							
		/* Float Matrix :  4X4 Matrix */
		{
			std::cout << "Test Case ---> Set identity Matrix of type float --> A = I(A) \n\n";
			fprintf(fpTest, "Test Case ---> Set identity Matrix of type float --> A = I(A)\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

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
			
			typedef cml::CMatrix <float32, 4, 4, false> self;

			cml::CMatrix<float32, 4, 4, false> testMatrix1(A);

			self result_matrix(result);

			const float32 scale_value = 1.0;

			cml::boolean_t returnValue; 	

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( testMatrix1);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( testMatrix1, fpTest);

			/* Set global data */
			initialise_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( result_matrix);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( result_matrix, fpTest);
			

			/* Call Function Under Test */			
			testMatrix1.setIdentity();	 

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( testMatrix1);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( testMatrix1, fpTest);

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

#ifdef ENABLE_PROFILER
			std::cout << "Clock Cycles ---> \n";		
			fprintf(fpTest, "Clock Cycles ---> \n");

			total_cycles = stop_clock - start_clock - overhead;

			check__PrintValue_to_console(total_cycles);
			check__PrintValue_to_File(total_cycles, fpTest);	
			fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

			std::cout << "Remarks ---> \n\n";
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		/* int Matrix :  4X4 Matrix */
		{
			std::cout << "Test Case ---> Set identity Matrix of type int --> A = I(A) \n\n";
			fprintf(fpTest, "Test Case ---> Set identity Matrix of type int --> A = I(A)\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

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
			
			typedef cml::CMatrix <sint32, 4, 4, false> self;

			cml::CMatrix<sint32, 4, 4, false> testMatrix1(A);

			self result_matrix(result);

			const float32 scale_value = 1.0;

			cml::boolean_t returnValue; 	

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( testMatrix1);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( testMatrix1, fpTest);

			/* Set global data */
			initialise_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( result_matrix);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( result_matrix, fpTest);
			

			/* Call Function Under Test */			
			testMatrix1.setIdentity();	 

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 4, 4, false >( testMatrix1);
			check__vMatrixPrint_to_File< sint32, 4, 4, false >( testMatrix1, fpTest);

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

#ifdef ENABLE_PROFILER
			std::cout << "Clock Cycles ---> \n";		
			fprintf(fpTest, "Clock Cycles ---> \n");

			total_cycles = stop_clock - start_clock - overhead;

			check__PrintValue_to_console(total_cycles);
			check__PrintValue_to_File(total_cycles, fpTest);	
			fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

			std::cout << "Remarks ---> \n\n";
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		/* short Matrix :  4X4 Matrix */
		{
			std::cout << "Test Case ---> Set identity Matrix of type short --> A = I(A) \n\n";
			fprintf(fpTest, "Test Case ---> Set identity Matrix of type short --> A = I(A)\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

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
			
			typedef cml::CMatrix <sint16, 4, 4, false> self;

			cml::CMatrix<sint16, 4, 4, false> testMatrix1(A);

			self result_matrix(result);

			const float32 scale_value = 1.0;

			cml::boolean_t returnValue; 	

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( testMatrix1);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( testMatrix1, fpTest);

			/* Set global data */
			initialise_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( result_matrix);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( result_matrix, fpTest);
			

			/* Call Function Under Test */			
			testMatrix1.setIdentity();	 

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 4, 4, false >( testMatrix1);
			check__vMatrixPrint_to_File< sint16, 4, 4, false >( testMatrix1, fpTest);

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

#ifdef ENABLE_PROFILER
			std::cout << "Clock Cycles ---> \n";		
			fprintf(fpTest, "Clock Cycles ---> \n");

			total_cycles = stop_clock - start_clock - overhead;

			check__PrintValue_to_console(total_cycles);
			check__PrintValue_to_File(total_cycles, fpTest);	
			fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

			std::cout << "Remarks ---> \n\n";
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		/* char Matrix :  4X4 Matrix */
		{
			std::cout << "Test Case ---> Set identity Matrix of type char --> A = I(A) \n\n";
			fprintf(fpTest, "Test Case ---> Set identity Matrix of type char --> A = I(A)\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

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
			
			typedef cml::CMatrix <sint8, 4, 4, false> self;

			cml::CMatrix<sint8, 4, 4, false> testMatrix1(A);

			self result_matrix(result);

			const float32 scale_value = 1.0;

			cml::boolean_t returnValue; 	

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( testMatrix1);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( testMatrix1, fpTest);

			/* Set global data */
			initialise_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");
			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( result_matrix);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( result_matrix, fpTest);
			

			/* Call Function Under Test */			
			testMatrix1.setIdentity();	 

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 4, 4, false >( testMatrix1);
			check__vMatrixPrint_to_File< sint8, 4, 4, false >( testMatrix1, fpTest);

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

#ifdef ENABLE_PROFILER
			std::cout << "Clock Cycles ---> \n";		
			fprintf(fpTest, "Clock Cycles ---> \n");

			total_cycles = stop_clock - start_clock - overhead;

			check__PrintValue_to_console(total_cycles);
			check__PrintValue_to_File(total_cycles, fpTest);	
			fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

			std::cout << "Remarks ---> \n\n";
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		std::cout << "END ---> test_setIdentity\n\n";
		fprintf(fpTest, "END ---> test_setIdentity\n\n");
	}
}


void TEST_CLASS_MATRIX::test_invert_NXN(int doIt)
{
	std::cout << "START ---> test_invert_NXN\n\n";		
	fprintf(fpTest, "START ---> test_invert_NXN\n\n");

	std::cout << "Function Name ---> invert()\n\n";	
	fprintf(fpTest, "Function Name ---> invert()\n\n");
	if (doIt) 
	{

		{
			std::cout << "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n";
			fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n");

			std::cout << "Data Dimension ---> 1X1\n\n";		
			fprintf(fpTest, "Data Dimension ---> 1X1\n\n");

			/* Test Case data declarations */
			bool invertibility, expected_invertibilty;
			cml::CMatrix<float32, 1, 1, false> res_MT;
			cml::CMatrix<float32, 1, 1, false> inp_MT;
			cml::CMatrix<float32, 1, 1, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT.fill(2);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input = \n";	
			fprintf(fpTest, "input = \n");

			check__vMatrixPrint_to_console< float32, 1, 1, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 1, 1, false >( inp_MT, fpTest);
								
			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_invertibilty = 1;
			expected_result_MT.fill(0.5);

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 1, 1, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 1, 1, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			invertibility = cml::CMatrix <float32, 1, 1, false>::SInvert<float32, 1, 1, false>::invert(res_MT,inp_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 1, 1, false >( res_MT);
			check__vMatrixPrint_to_File< float32, 1, 1, false >( res_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = res_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
				
		}

		{

			std::cout << "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n";
			fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n");

			std::cout << "Data Dimension ---> 1X1\n\n";		
			fprintf(fpTest, "Data Dimension ---> 1X1\n\n");

			/* Test Case data declarations */
			bool invertibility, expected_invertibilty;
			cml::CMatrix<float32, 1, 1, false> res_MT;
			cml::CMatrix<float32, 1, 1, false> inp_MT;
			cml::CMatrix<float32, 1, 1, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT.fill(0);

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input = \n";	
			fprintf(fpTest, "input = \n");

			check__vMatrixPrint_to_console< float32, 1, 1, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 1, 1, false >( inp_MT, fpTest);


			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_invertibilty = 0;
			expected_result_MT.fill(0);

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 1, 1, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 1, 1, false >( expected_result_MT, fpTest);


			res_MT.fill(0);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			invertibility = cml::CMatrix <float32, 1, 1, false>::SInvert<float32, 1, 1, false>::invert(res_MT,inp_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 1, 1, false >( res_MT);
			check__vMatrixPrint_to_File< float32, 1, 1, false >( res_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = res_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

			if(invertibility == 0)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status ---> FAIL\n\n";    
				fprintf(fpTest, "Status ---> FAIL\n\n");
			}

#ifdef ENABLE_PROFILER
			std::cout << "Clock Cycles ---> \n";		
			fprintf(fpTest, "Clock Cycles ---> \n");

			total_cycles = stop_clock - start_clock - overhead;

			check__PrintValue_to_console(total_cycles);
			check__PrintValue_to_File(total_cycles, fpTest);	
			fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

			/* Remarks */
			std::cout << "Remarks ---> Matrix is singular to working precision! \n\n";  
			fprintf(fpTest, "Remarks ---> Matrix is singular to working precision! \n\n");

		}

		{
			std::cout << "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n";
			fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			bool invertibility, expected_invertibilty;
			cml::CMatrix<float32, 2, 2, false> res_MT;
			cml::CMatrix<float32, 2, 2, false> inp_MT;
			cml::CMatrix<float32, 2, 2, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 1;
			inp_MT(1,0) = 0;
			inp_MT(1,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input = \n";	
			fprintf(fpTest, "input = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);
			

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_invertibilty = 1;

			expected_result_MT(0,0) = 1;
			expected_result_MT(0,1) = -1;
			expected_result_MT(1,0) = 0;
			expected_result_MT(1,1) = 1;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			invertibility = cml::CMatrix <float32, 2, 2, false>::SInvert<float32, 2, 2, false>::invert(res_MT,inp_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( res_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( res_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = res_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}		

		{
			std::cout << "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n";
			fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			bool invertibility, expected_invertibilty;
			cml::CMatrix<float32, 2, 2, false> res_MT;
			cml::CMatrix<float32, 2, 2, false> inp_MT;
			cml::CMatrix<float32, 2, 2, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 1;
			inp_MT(1,0) = 1;
			inp_MT(1,1) = 1;

			res_MT(0,0) = 1;
			res_MT(0,1) = 1;
			res_MT(1,0) = 1;
			res_MT(1,1) = 1;

			expected_result_MT(0,0) = 1;
			expected_result_MT(0,1) = 1;
			expected_result_MT(1,0) = 1;
			expected_result_MT(1,1) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input = \n";	
			fprintf(fpTest, "input = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( inp_MT, fpTest);
			

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_invertibilty = 0;
			
			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			invertibility = cml::CMatrix <float32, 2, 2, false>::SInvert<float32, 2, 2, false>::invert(res_MT,inp_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( res_MT);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( res_MT, fpTest);

			if(invertibility == 0)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status ---> FAIL\n\n";    
				fprintf(fpTest, "Status ---> FAIL\n\n");
			}

#ifdef ENABLE_PROFILER
			std::cout << "Clock Cycles ---> \n";		
			fprintf(fpTest, "Clock Cycles ---> \n");

			total_cycles = stop_clock - start_clock - overhead;

			check__PrintValue_to_console(total_cycles);
			check__PrintValue_to_File(total_cycles, fpTest);	
			fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

			/* Remarks */
			std::cout << "Remarks ---> Matrix is singular to working precision! \n\n";  
			fprintf(fpTest, "Remarks ---> Matrix is singular to working precision! \n\n");

		}

		{
			std::cout << "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n";
			fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n");

			std::cout << "Data Dimension ---> 3X3\n\n";		
			fprintf(fpTest, "Data Dimension ---> 3X3\n\n");

			/* Test Case data declarations */
			bool invertibility, expected_invertibilty;
			cml::CMatrix<float32, 3, 3, false> res_MT;
			cml::CMatrix<float32, 3, 3, false> inp_MT;
			cml::CMatrix<float32, 3, 3, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 2;
			inp_MT(0,2) = 3;
			inp_MT(1,0) = 1;
			inp_MT(1,1) = 3;
			inp_MT(1,2) = 4;
			inp_MT(2,0) = 4;
			inp_MT(2,1) = 5;
			inp_MT(2,2) = 6;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input = \n";	
			fprintf(fpTest, "input = \n");

			check__vMatrixPrint_to_console< float32, 3, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 3, 3, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_invertibilty = 1;

			expected_result_MT(0,0) =  0.666666666666666f;
			expected_result_MT(0,1) = -1.000000000000000f;
			expected_result_MT(0,2) =  0.333333333333333f;
			expected_result_MT(1,0) = -3.333333333333333f;
			expected_result_MT(1,1) =  2.000000000000000f;
			expected_result_MT(1,2) =  0.333333333333333f;
			expected_result_MT(2,0) =  2.333333333333333f;
			expected_result_MT(2,1) = -1.000000000000000f;
			expected_result_MT(2,2) = -0.333333333333333f;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 3, 3, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 3, 3, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			invertibility = cml::CMatrix <float32, 3, 3, false>::SInvert<float32, 3, 3, false>::invert(res_MT,inp_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 3, 3, false >( res_MT);
			check__vMatrixPrint_to_File< float32, 3, 3, false >( res_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = res_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> Precision difference is expected \n\n";  
			fprintf(fpTest, "Remarks ---> Precision difference is expected \n\n");

		}		

		{
			std::cout << "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n";
			fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n");

			std::cout << "Data Dimension ---> 3X3\n\n";		
			fprintf(fpTest, "Data Dimension ---> 3X3\n\n");

			/* Test Case data declarations */
			bool invertibility, expected_invertibilty;
			cml::CMatrix<float32, 3, 3, false> res_MT;
			cml::CMatrix<float32, 3, 3, false> inp_MT;
			cml::CMatrix<float32, 3, 3, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 1;
			inp_MT(0,2) = 1;
			inp_MT(1,0) = 1;
			inp_MT(1,1) = 1;
			inp_MT(1,2) = 1;
			inp_MT(2,0) = 1;
			inp_MT(2,1) = 1;
			inp_MT(2,2) = 1;

			expected_result_MT(0,0) = 1;
			expected_result_MT(0,1) = 1;
			expected_result_MT(0,2) = 1;
			expected_result_MT(1,0) = 1;
			expected_result_MT(1,1) = 1;
			expected_result_MT(1,2) = 1;
			expected_result_MT(2,0) = 1;
			expected_result_MT(2,1) = 1;
			expected_result_MT(2,2) = 1;

			res_MT(0,0) = 1;
			res_MT(0,1) = 1;
			res_MT(0,2) = 1;
			res_MT(1,0) = 1;
			res_MT(1,1) = 1;
			res_MT(1,2) = 1;
			res_MT(2,0) = 1;
			res_MT(2,1) = 1;
			res_MT(2,2) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input = \n";	
			fprintf(fpTest, "input = \n");

			check__vMatrixPrint_to_console< float32, 3, 3, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 3, 3, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_invertibilty = 0;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 3, 3, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 3, 3, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			invertibility = cml::CMatrix <float32, 3, 3, false>::SInvert<float32, 3, 3, false>::invert(res_MT,inp_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 3, 3, false >( res_MT);
			check__vMatrixPrint_to_File< float32, 3, 3, false >( res_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = res_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

			if(invertibility == 0)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status ---> FAIL\n\n";    
				fprintf(fpTest, "Status ---> FAIL\n\n");
			}

#ifdef ENABLE_PROFILER
			std::cout << "Clock Cycles ---> \n";		
			fprintf(fpTest, "Clock Cycles ---> \n");

			total_cycles = stop_clock - start_clock - overhead;

			check__PrintValue_to_console(total_cycles);
			check__PrintValue_to_File(total_cycles, fpTest);	
			fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

			/* Remarks */
			std::cout << "Remarks ---> Matrix is singular to working precision! \n\n";  
			fprintf(fpTest, "Remarks ---> Matrix is singular to working precision! \n\n");

		}	

		{
			std::cout << "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n";
			fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			bool invertibility, expected_invertibilty;
			cml::CMatrix<float32, 4, 4, false> res_MT;
			cml::CMatrix<float32, 4, 4, false> inp_MT;
			cml::CMatrix<float32, 4, 4, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 2;
			inp_MT(0,2) = 3;
			inp_MT(0,3) = 4;
			inp_MT(1,0) = 1;
			inp_MT(1,1) = 3;
			inp_MT(1,2) = 1;
			inp_MT(1,3) = 3;
			inp_MT(2,0) = 4;
			inp_MT(2,1) = 5;
			inp_MT(2,2) = 6;
			inp_MT(2,3) = 2;
			inp_MT(3,0) = 1;
			inp_MT(3,1) = 5;
			inp_MT(3,2) = 5;
			inp_MT(3,3) = 5;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input = \n";	
			fprintf(fpTest, "input = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_invertibilty = 1;

			expected_result_MT(0,0) =  0.340909090909091f;
			expected_result_MT(0,1) =  0.284090909090909f;
			expected_result_MT(0,2) =  0.227272727272727f;
			expected_result_MT(0,3) = -0.534090909090909f;
			expected_result_MT(1,0) = -0.500000000000000f;
			expected_result_MT(1,1) =  0.250000000000000f;
			expected_result_MT(1,2) =  0.0f;
			expected_result_MT(1,3) =  0.250000000000000f;
			expected_result_MT(2,0) =  0.068181818181818f;
			expected_result_MT(2,1) = -0.443181818181818f;
			expected_result_MT(2,2) =  0.045454545454545f;
			expected_result_MT(2,3) =  0.193181818181818f;
			expected_result_MT(3,0) =  0.363636363636364f;
			expected_result_MT(3,1) =  0.136363636363636f;
			expected_result_MT(3,2) = -0.090909090909091f;
			expected_result_MT(3,3) = -0.136363636363636f;

			res_MT(0,0) = 0.3409f;
			res_MT(0,1) = 0.2841f;
			res_MT(0,2) = 0.2273f;
			res_MT(0,3) = -0.5341f;
			res_MT(1,0) = -0.5000f;
			res_MT(1,1) = 0.2500f;
			res_MT(1,2) = 0;
			res_MT(1,3) = 0.2500f;
			res_MT(2,0) = 0.0682f;
			res_MT(2,1) = -0.4432f;
			res_MT(2,2) = 0.0455f;
			res_MT(2,3) = 0.1932f;
			res_MT(3,0) = 0.3636;
			res_MT(3,1) = 0.1364f;
			res_MT(3,2) = -0.0909f;
			res_MT(3,3) = -0.1364;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			invertibility = cml::CMatrix <float32, 4, 4, false>::SInvert<float32, 4, 4, false>::invert(res_MT,inp_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( res_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( res_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = res_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

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
			std::cout << "Remarks ---> Precision difference is expected \n\n";  
			fprintf(fpTest, "Remarks ---> Precision difference is expected \n\n");

		}

		{
			std::cout << "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n";
			fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n");

			std::cout << "Data Dimension ---> 4X4\n\n";		
			fprintf(fpTest, "Data Dimension ---> 4X4\n\n");

			/* Test Case data declarations */
			bool invertibility, expected_invertibilty;
			cml::CMatrix<float32, 4, 4, false> res_MT;
			cml::CMatrix<float32, 4, 4, false> inp_MT;
			cml::CMatrix<float32, 4, 4, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 1;
			inp_MT(0,2) = 1;
			inp_MT(0,3) = 1;
			inp_MT(1,0) = 1;
			inp_MT(1,1) = 1;
			inp_MT(1,2) = 1;
			inp_MT(1,3) = 1;
			inp_MT(2,0) = 1;
			inp_MT(2,1) = 1;
			inp_MT(2,2) = 1;
			inp_MT(2,3) = 1;
			inp_MT(3,0) = 1;
			inp_MT(3,1) = 1;
			inp_MT(3,2) = 1;
			inp_MT(3,3) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input = \n";	
			fprintf(fpTest, "input = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_invertibilty = 0;

			expected_result_MT(0,0) = 1;
			expected_result_MT(0,1) = 0;
			expected_result_MT(0,2) = 0;
			expected_result_MT(0,3) = 0;
			expected_result_MT(1,0) = -1;
			expected_result_MT(1,1) = 1;
			expected_result_MT(1,2) = 0;
			expected_result_MT(1,3) = 0;
			expected_result_MT(2,0) = -1;
			expected_result_MT(2,1) = 0;
			expected_result_MT(2,2) = 1;
			expected_result_MT(2,3) = 0;
			expected_result_MT(3,0) = -1;
			expected_result_MT(3,1) = 0;
			expected_result_MT(3,2) = 0;
			expected_result_MT(3,3) = 1;

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			invertibility = cml::CMatrix <float32, 4, 4, false>::SInvert<float32, 4, 4, false>::invert(res_MT,inp_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 4, 4, false >( res_MT);
			check__vMatrixPrint_to_File< float32, 4, 4, false >( res_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = res_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

			if(invertibility == 0)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status ---> FAIL\n\n";    
				fprintf(fpTest, "Status ---> FAIL\n\n");
			}

#ifdef ENABLE_PROFILER
			std::cout << "Clock Cycles ---> \n";		
			fprintf(fpTest, "Clock Cycles ---> \n");

			total_cycles = stop_clock - start_clock - overhead;

			check__PrintValue_to_console(total_cycles);
			check__PrintValue_to_File(total_cycles, fpTest);	
			fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

			/* Remarks */
			std::cout << "Remarks ---> Matrix is singular to working precision! \n\n";  
			fprintf(fpTest, "Remarks ---> Matrix is singular to working precision! \n\n");

		}

		{
			std::cout << "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n";
			fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type float --> result  = inv(A)\n\n");

			std::cout << "Data Dimension ---> 5X5\n\n";		
			fprintf(fpTest, "Data Dimension ---> 5X5\n\n");

			/* Test Case data declarations */
			bool invertibility, expected_invertibilty;
			cml::CMatrix<float32, 5, 5, false> res_MT;
			cml::CMatrix<float32, 5, 5, false> inp_MT;
			cml::CMatrix<float32, 5, 5, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			inp_MT(0,0) = 1;
			inp_MT(0,1) = 1;
			inp_MT(0,2) = 1;
			inp_MT(0,3) = 1;
			inp_MT(0,4) = 1;
			inp_MT(1,0) = 1;
			inp_MT(1,1) = 1;
			inp_MT(1,2) = 1;
			inp_MT(1,3) = 1;
			inp_MT(1,4) = 1;
			inp_MT(2,0) = 1;
			inp_MT(2,1) = 1;
			inp_MT(2,2) = 1;
			inp_MT(2,3) = 1;
			inp_MT(2,4) = 1;
			inp_MT(3,0) = 1;
			inp_MT(3,1) = 1;
			inp_MT(3,2) = 1;
			inp_MT(3,3) = 1;
			inp_MT(3,4) = 1;
			inp_MT(4,0) = 1;
			inp_MT(4,1) = 1;
			inp_MT(4,2) = 1;
			inp_MT(4,3) = 1;
			inp_MT(4,4) = 1;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input = \n";	
			fprintf(fpTest, "input = \n");

			check__vMatrixPrint_to_console< float32, 5, 5, false >( inp_MT);
			check__vMatrixPrint_to_File< float32, 5, 5, false >( inp_MT, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_invertibilty = 0;

			expected_result_MT(0,0) = 1;
			expected_result_MT(0,1) = 0;
			expected_result_MT(0,2) = 0;
			expected_result_MT(0,3) = 0;
			expected_result_MT(0,4) = 0;
			expected_result_MT(1,0) = -1;
			expected_result_MT(1,1) = 1;
			expected_result_MT(1,2) = 0;
			expected_result_MT(1,3) = 0;
			expected_result_MT(1,4) = 0;
			expected_result_MT(2,0) = -1;
			expected_result_MT(2,1) = 0;
			expected_result_MT(2,2) = 1;
			expected_result_MT(2,3) = 0;
			expected_result_MT(2,4) = 0;
			expected_result_MT(3,0) = -1;
			expected_result_MT(3,1) = 0;
			expected_result_MT(3,2) = 0;
			expected_result_MT(3,3) = 1;
			expected_result_MT(3,4) = 0;
			expected_result_MT(4,0) = -1;
			expected_result_MT(4,1) = 0;
			expected_result_MT(4,2) = 0;
			expected_result_MT(4,3) = 0;
			expected_result_MT(4,4) = 1;


			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 5, 5, false >( expected_result_MT);
			check__vMatrixPrint_to_File< float32, 5, 5, false >( expected_result_MT, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			invertibility = cml::CMatrix <float32, 5, 5, false>::SInvert<float32, 5, 5, false>::invert(res_MT,inp_MT);

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 5, 5, false >( res_MT);
			check__vMatrixPrint_to_File< float32, 5, 5, false >( res_MT, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = res_MT.getAlmostEqualRelativeAndAbs(expected_result_MT);

			if(invertibility == 0)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status ---> FAIL\n\n";    
				fprintf(fpTest, "Status ---> FAIL\n\n");
			}

#ifdef ENABLE_PROFILER
			std::cout << "Clock Cycles ---> \n";		
			fprintf(fpTest, "Clock Cycles ---> \n");

			total_cycles = stop_clock - start_clock - overhead;

			check__PrintValue_to_console(total_cycles);
			check__PrintValue_to_File(total_cycles, fpTest);	
			fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

			/* Remarks */
			std::cout << "Remarks ---> Matrix is singular to working precision! \n\n";  
			fprintf(fpTest, "Remarks ---> Matrix is singular to working precision! \n\n");

		}

		/* Invert Hilbert_3-Matrix :  3X3 Matrix */
		{
			std::cout << "Test Case ---> Inverse of a Hilbert_3 matrix  of type float --> result  = inv(A)\n\n";
			fprintf(fpTest, "Test Case ---> Inverse of a Hilbert_3 matrix  of type float --> result  = inv(A)\n\n");

			std::cout << "Data Dimension ---> 3X3\n\n";		
			fprintf(fpTest, "Data Dimension ---> 3X3\n\n");

			/* Test case input data declarations */
			float32 A[9] = {
				1.f,    1.f/2,   1.f/3,
                1.f/2,  1.f/3,   1.f/4,
                1.f/3,  1.f/4,   1.f/5
			};

			float32 result[9] = {
				 8.9999856948853f,  -35.9999389648437f,   29.9999389648437f,
				-35.9999389648437f,   191.9996643066406f,  -179.9996795654297f,
				 29.9999389648437f,  -179.9996795654297f,   179.9996948242188f
			};

			typedef cml::CMatrix <float32, 3, 3, false> self;

			cml::CMatrix<float32, 3, 3, false> testMatrix1(A);

			self result_matrix(result);

			cml::CMatrix<float32, 3, 3, false> return_matrix;
				
			cml::boolean_t returnValue;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input = \n";	
			fprintf(fpTest, "input = \n");

			check__vMatrixPrint_to_console< float32, 3, 3, false >( testMatrix1);
			check__vMatrixPrint_to_File< float32, 3, 3, false >( testMatrix1, fpTest);
					
			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 3, 3, false >( result_matrix);
			check__vMatrixPrint_to_File< float32, 3, 3, false >( result_matrix, fpTest);
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call Function Under Test */			
			return_matrix = testMatrix1.invert();  /* Overloaded Multiplication operator */	

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 3, 3, false >( return_matrix);
			check__vMatrixPrint_to_File< float32, 3, 3, false >( return_matrix, fpTest);

			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

#ifdef ENABLE_PROFILER
			std::cout << "Clock Cycles ---> \n";		
			fprintf(fpTest, "Clock Cycles ---> \n");

			total_cycles = stop_clock - start_clock - overhead;

			check__PrintValue_to_console(total_cycles);
			check__PrintValue_to_File(total_cycles, fpTest);	
			fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

			/* Remarks */
			std::cout << "Remarks ---> Precision differences\n\n";  
			fprintf(fpTest, "Remarks ---> Precision differences\n\n");
		}

		
		/* Invert Hilbert_5-Matrix :  5X5 Matrix */
		{
			std::cout << "Test Case ---> Inverse of a Hilbert_5 matrix  of type float --> result  = inv(A)\n\n";
			fprintf(fpTest, "Test Case ---> Inverse of a Hilbert_5 matrix  of type float --> result  = inv(A)\n\n");

			std::cout << "Data Dimension ---> 5X5\n\n";		
			fprintf(fpTest, "Data Dimension ---> 5X5\n\n");

			/* Test case input data declarations */
			float32 A[25] = {
				1.,    1./2,  1./3,  1./4,  1./5,
                1./2,  1./3,  1./4,  1./5,  1./6,  
                1./3,  1./4,  1./5,  1./6,  1./7,  
                1./4,  1./5,  1./6,  1./7,  1./8,  
                1./5,  1./6,  1./7,  1./8,  1./9  
			};			

			float32 result[25] = {
				  24.9872436523f,    -299.7612304687f,     1048.9687500000f,    -1398.4472656250f,    629.2363281250f,
				-299.7612304687f,    4795.3662109375f,   -18879.9648437500f,    26849.6738281250f, -12585.1269531250f,
				1048.9687500000f,  -18879.9648437500f,    79291.0859375000f,  -117465.3750000000f,  56634.0039062500f,
			   -1398.4472656250f,   26849.6738281250f,  -117465.3750000000f,   178992.4687500000f, -88098.2812500000f,
				 629.2363281250f,  -12585.1269531250f,    56634.0039062500f,   -88098.2812500000f,  44049.4765625000f 
				     
			};

			typedef cml::CMatrix <float32, 5, 5, false> self;

			cml::CMatrix<float32, 5, 5, false> testMatrix1(A);

			self result_matrix(result);

			cml::CMatrix<float32, 5, 5, false> return_matrix;
				
			cml::boolean_t returnValue;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input = \n";	
			fprintf(fpTest, "input = \n");

			check__vMatrixPrint_to_console< float32, 5, 5, false >( testMatrix1);
			check__vMatrixPrint_to_File< float32, 5, 5, false >( testMatrix1, fpTest);
					
			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 5, 5, false >( result_matrix);
			check__vMatrixPrint_to_File< float32, 5, 5, false >( result_matrix, fpTest);
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call Function Under Test */			
			return_matrix = testMatrix1.invert(); /* Overloaded Multiplication operator */	

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 5, 5, false >( return_matrix);
			check__vMatrixPrint_to_File< float32, 5, 5, false >( return_matrix, fpTest);

			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";    
				fprintf(fpTest, "Status --->  FAIL\n");
			}

#ifdef ENABLE_PROFILER
			std::cout << "Clock Cycles ---> \n";		
			fprintf(fpTest, "Clock Cycles ---> \n");

			total_cycles = stop_clock - start_clock - overhead;

			check__PrintValue_to_console(total_cycles);
			check__PrintValue_to_File(total_cycles, fpTest);	
			fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

			/* Remarks */
			std::cout << "Remarks ---> Precision differences\n\n"; 
			fprintf(fpTest, "Remarks ---> Precision differences\n\n");
		}

		
		/* Invert int Matrix :  3X3 Matrix  */
		{
			std::cout << "Test Case ---> Inverse of a matrix  of type int --> result  = inv(A)\n\n";
			fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type int --> result  = inv(A)\n\n");

			std::cout << "Data Dimension ---> 3X3\n\n";		
			fprintf(fpTest, "Data Dimension ---> 3X3\n\n");

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
						
			typedef cml::CMatrix <sint32, 3, 3, false> self;

			cml::CMatrix<sint32, 3, 3, false> testMatrix1(A);

			self result_matrix(result);

			cml::CMatrix<sint32, 3, 3, false> return_matrix;
				
			cml::boolean_t returnValue;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input = \n";	
			fprintf(fpTest, "input = \n");

			check__vMatrixPrint_to_console< sint32, 3, 3, false >( testMatrix1);
			check__vMatrixPrint_to_File< sint32, 3, 3, false >( testMatrix1, fpTest);
					
			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint32, 3, 3, false >( result_matrix);
			check__vMatrixPrint_to_File< sint32, 3, 3, false >( result_matrix, fpTest);
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call Function Under Test */			
			return_matrix = testMatrix1.invert(); /* Overloaded Multiplication operator */	

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint32, 3, 3, false >( return_matrix);
			check__vMatrixPrint_to_File< sint32, 3, 3, false >( return_matrix, fpTest);

			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";  
				fprintf(fpTest, "Status --->  FAIL\n");
			}

#ifdef ENABLE_PROFILER
			std::cout << "Clock Cycles ---> \n";		
			fprintf(fpTest, "Clock Cycles ---> \n");

			total_cycles = stop_clock - start_clock - overhead;

			check__PrintValue_to_console(total_cycles);
			check__PrintValue_to_File(total_cycles, fpTest);	
			fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

			/* Remarks */
			std::cout << "Remarks ---> Inverse of non-float matrix may give wrong result due to fractional division\n\n"; 
			fprintf(fpTest, "Remarks ---> Inverse of non-float matrix may give wrong result due to fractional division\n\n");
		}	

		
		/* Invert short Matrix :  3X3 Matrix  */
		{
			std::cout << "Test Case ---> Inverse of a matrix  of type short --> result  = inv(A)\n\n";
			fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type short --> result  = inv(A)\n\n");

			std::cout << "Data Dimension ---> 3X3\n\n";		
			fprintf(fpTest, "Data Dimension ---> 3X3\n\n");

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
						
			typedef cml::CMatrix <sint16, 3, 3, false> self;

			cml::CMatrix<sint16, 3, 3, false> testMatrix1(A);

			self result_matrix(result);

			cml::CMatrix<sint16, 3, 3, false> return_matrix;
				
			cml::boolean_t returnValue;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input = \n";	
			fprintf(fpTest, "input = \n");

			check__vMatrixPrint_to_console< sint16, 3, 3, false >( testMatrix1);
			check__vMatrixPrint_to_File< sint16, 3, 3, false >( testMatrix1, fpTest);
					
			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint16, 3, 3, false >( result_matrix);
			check__vMatrixPrint_to_File< sint16, 3, 3, false >( result_matrix, fpTest);

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call Function Under Test */			
			return_matrix = testMatrix1.invert(); /* Overloaded Multiplication operator */	

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint16, 3, 3, false >( return_matrix);
			check__vMatrixPrint_to_File< sint16, 3, 3, false >( return_matrix, fpTest);

			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";  
				fprintf(fpTest, "Status --->  FAIL\n");
			}

#ifdef ENABLE_PROFILER
			std::cout << "Clock Cycles ---> \n";		
			fprintf(fpTest, "Clock Cycles ---> \n");

			total_cycles = stop_clock - start_clock - overhead;

			check__PrintValue_to_console(total_cycles);
			check__PrintValue_to_File(total_cycles, fpTest);	
			fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

			/* Remarks */
			std::cout << "Remarks ---> Inverse of non-float matrix may give wrong result due to fractional division\n\n";
			fprintf(fpTest, "Remarks ---> Inverse of non-float matrix may give wrong result due to fractional division\n\n");
		}
				
		/* Invert char Matrix :  3X3 Matrix  */
		{
			std::cout << "Test Case ---> Inverse of a matrix  of type char --> result  = inv(A)\n\n";
			fprintf(fpTest, "Test Case ---> Inverse of a matrix  of type char --> result  = inv(A)\n\n");

			std::cout << "Data Dimension ---> 3X3\n\n";		
			fprintf(fpTest, "Data Dimension ---> 3X3\n\n");

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
						
			typedef cml::CMatrix <sint8, 3, 3, false> self;

			cml::CMatrix<sint8, 3, 3, false> testMatrix1(A);

			self result_matrix(result);

			cml::CMatrix<sint8, 3, 3, false> return_matrix;
				
			cml::boolean_t returnValue; 	

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input = \n";	
			fprintf(fpTest, "input = \n");

			check__vMatrixPrint_to_console< sint8, 3, 3, false >( testMatrix1);
			check__vMatrixPrint_to_File< sint8, 3, 3, false >( testMatrix1, fpTest);
					
			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< sint8, 3, 3, false >( result_matrix);
			check__vMatrixPrint_to_File< sint8, 3, 3, false >( result_matrix, fpTest);
			
			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
			
			/* Call Function Under Test */			
			returnValue = testMatrix1.invert(return_matrix); /* Overloaded Multiplication operator */

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";	
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< sint8, 3, 3, false >( return_matrix);
			check__vMatrixPrint_to_File< sint8, 3, 3, false >( return_matrix, fpTest);

			/* Copy the result matrix to this */
			testMatrix1 = return_matrix;

			/* Checks on global data */			
			returnValue = testMatrix1.getAlmostEqualRelativeAndAbs(result_matrix);

			if(returnValue)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Status --->  FAIL\n";  
				fprintf(fpTest, "Status --->  FAIL\n");
			}

#ifdef ENABLE_PROFILER
			std::cout << "Clock Cycles ---> \n";		
			fprintf(fpTest, "Clock Cycles ---> \n");

			total_cycles = stop_clock - start_clock - overhead;

			check__PrintValue_to_console(total_cycles);
			check__PrintValue_to_File(total_cycles, fpTest);	
			fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */

			/* Remarks */
			std::cout << "Remarks ---> Inverse of non-float matrix may give wrong result due to fractional division\n\n";
			fprintf(fpTest, "Remarks ---> Inverse of non-float matrix may give wrong result due to fractional division\n\n");
		}
#if 0
		{
			/* Test Case data declarations */
			bool invertibility, expected_invertibilty;
			cml::CMatrix<float32, 255, 255, false> *res_MT = new cml::CMatrix<float32, 255, 255, false>;
			cml::CMatrix<float32, 255, 255, false> *inp_MT = new cml::CMatrix<float32, 255, 255, false>;
			cml::CMatrix<float32, 255, 255, false> expected_result_MT;

			/* Set global data */
			initialise_global_data();

			res_MT->fill(0);
			inp_MT->fill(1);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			expected_invertibilty = 0;

			/* Call SUT */
			invertibility = cml::CMatrix <float32, 255, 255, false>::SInvert<float32, 255, 255, false>::invert(*res_MT,*inp_MT);

		}
#endif
		
	}

	std::cout << "END ---> test_invert_NXN\n\n";
	fprintf(fpTest, "END ---> test_invert_NXN\n\n");

}

void TEST_CLASS_MATRIX::test_getLowTriaInverse(int doIt)
{
	std::cout << "START ---> test_getLowTriaInverse\n\n";		
	fprintf(fpTest, "START ---> test_getLowTriaInverse\n\n");

	std::cout << "Function Name ---> getLowTriaInverse() \n\n";	
	fprintf(fpTest, "Function Name ---> getLowTriaInverse() \n\n");
	if (doIt) 
	{

		{
			std::cout << "Test Case ---> test_getLowTriaInverse_001\n\n";
			fprintf(fpTest, "Test Case ---> test_getLowTriaInverse_001\n\n");

			std::cout << "Data Dimension ---> 3X3\n\n";		
			fprintf(fpTest, "Data Dimension ---> 3X3\n\n");

			/* Test Case data declarations */

			float racMatrix1[]  = { 
				1.f,   0.f,   0.f,  
				1.f,   1.f,   0.f, 
				1.f,   1.f,   1.f, 
			};   

			float racResult1[]  = { 
				1.f,   0.f,   0.f,
				-1.f,   1.f,   0.f,
				0.f,  -1.f,   1.f,
			};   

			typedef cml::CMatrix <float32, 3, 3, false> self;
			self testMatrix(racMatrix1);
			self result, expected_result(racResult1);			

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 3, 3, false >( testMatrix);
			check__vMatrixPrint_to_File< float32, 3, 3, false >( testMatrix, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 3, 3, false >( expected_result);
			check__vMatrixPrint_to_File< float32, 3, 3, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = testMatrix.getLowTriaInverse();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 3, 3, false >( result);
			check__vMatrixPrint_to_File< float32, 3, 3, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");

		}

		{
			std::cout << "Test Case ---> test_getLowTriaInverse_002\n\n";
			fprintf(fpTest, "Test Case ---> test_getLowTriaInverse_002\n\n");

			std::cout << "Data Dimension ---> 3X3\n\n";		
			fprintf(fpTest, "Data Dimension ---> 3X3\n\n");

			/* Test Case data declarations */

			float racMatrix2[]  = { 
				1.f,   0.f,   0.f,
				3.f,   0.5f,  0.f,
				1.f,   4.f,   0.5f,
			};   

			float racResult2[]  = {  
				1.f,    0.f,   0.f,
				-6.f,    2.f,   0.f,
				46.f,  -16.f,   2.f,
			};   

			typedef cml::CMatrix <float32, 3, 3, false> self;
			self testMatrix(racMatrix2);
			self result, expected_result(racResult2);			

			/* Set global data */
			initialise_global_data();

			/* Input Matrix */
			std::cout << "\nInput ---> \n";	
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input1 = \n";	
			fprintf(fpTest, "input1 = \n");

			check__vMatrixPrint_to_console< float32, 3, 3, false >( testMatrix);
			check__vMatrixPrint_to_File< float32, 3, 3, false >( testMatrix, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";	
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";	
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 3, 3, false >( expected_result);
			check__vMatrixPrint_to_File< float32, 3, 3, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = testMatrix.getLowTriaInverse();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";	
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 3, 3, false >( result);
			check__vMatrixPrint_to_File< float32, 3, 3, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result);

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
			std::cout << "Remarks ---> \n\n";  
			fprintf(fpTest, "Remarks ---> \n\n");
		}

		{
			std::cout << "Test Case ---> test_getLowTriaInverse_003\n\n";
			fprintf(fpTest, "Test Case ---> test_getLowTriaInverse_003\n\n");

			std::cout << "Data Dimension ---> 2X2\n\n";		
			fprintf(fpTest, "Data Dimension ---> 2X2\n\n");

			/* Test Case data declarations */
			typedef cml::CMatrix <float32, 2, 2, false> self;
			self testMatrix;
			self result, expected_result;

			sint32 size = 4;

			/* Set global data */
			initialise_global_data();

			//testMatrix.fill(1.175);
			testMatrix(0,0) = 1e-20F;
			testMatrix(0,1) = 1e-20F;
			testMatrix(1,0) = 1e-20F;
			testMatrix(1,1) = 1e-20F;

			expected_result(0,0) = 0;
			expected_result(0,1) = 0;
			expected_result(1,0) = 0;
			expected_result(1,1) = 0;

			/* Input Matrix */
			std::cout << "\nInput ---> \n";
			fprintf(fpTest, "\nInput ---> \n");

			std::cout << "input = \n";
			fprintf(fpTest, "input = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( testMatrix);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( testMatrix, fpTest);

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Expected Result Matrix */
			std::cout << "Expected Result ---> \n";
			fprintf(fpTest, "Expected Result ---> \n");

			std::cout << "expected_result = \n";
			fprintf(fpTest, "expected_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( expected_result);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( expected_result, fpTest);

#ifdef ENABLE_PROFILER
			start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			/* Call SUT */
			result = testMatrix.getLowTriaInverse();

#ifdef ENABLE_PROFILER
			stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			/* Actual Result Matrix */
			std::cout << "Actual Result ---> \n";
			fprintf(fpTest, "Actual Result ---> \n");

			std::cout << "actual_result = \n";
			fprintf(fpTest, "actual_result = \n");

			check__vMatrixPrint_to_console< float32, 2, 2, false >( result);
			check__vMatrixPrint_to_File< float32, 2, 2, false >( result, fpTest);

			/* Test Case checks */
			cml::boolean_t returnValue;

			/* Checks on global data */			
			returnValue = result.getAlmostEqualRelativeAndAbs(expected_result);

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
			std::cout << "Remarks ---> This test case is for coverage purpose, expected result is not relevant, results may differ\n\n";  
			fprintf(fpTest, "Remarks ---> This test case is for coverage purpose, expected result is not relevant, results may differ\n\n");

		}
	}
	std::cout << "END ---> test_getLowTriaInverse\n\n";
	fprintf(fpTest, "END ---> test_getLowTriaInverse\n\n");
}


#if 0
#ifndef NDEBUG
void TEST_CLASS_MATRIX::test_getAlmostEqualRelativeAndAbs(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_getAlmostEqualRelativeAndAbs_001",
			"Description:\
			- cml_stl_matrix.h : cml::CMatrix<int, 1, 1, false>::boolean_t getAlmostEqualRelativeAndAbs( const self& rhs ) \
			- Testing: interface \
			- Overview: verify that the getAlmostEqualRelativeAndAbs works properly and cover all possible paths of implementation \
			- Entry conditions: if( !getElementsAlmostEqualRelativeAndAbs( operator[](rci+j), rhs[rci+j])) : True for all elements\
			- Expected results: returnValue = true");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Test Case data declarations */
			int temp_Data[1] = {1};
		typedef cml::CMatrix <int, 1, 1, false> self;
		cml::CMatrix<int, 1, 1, false> *testMatrix = new cml::CMatrix<int, 1, 1, false>;
		self a;
		cml::boolean_t returnValue, expected_returnValue; 			
		sint32 size = 1;

		/* Set global data */
		initialise_global_data();

		testMatrix->fill(1.175);
		a.fill(1.175);

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_returnValue = 1;

		/* Call SUT */
		returnValue = testMatrix->getAlmostEqualRelativeAndAbs(a);

		/* Test Case checks */

		CHECK(returnValue, expected_returnValue);

		/* Checks on global data */
		check_global_data();
		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();

		START_TEST("test_getAlmostEqualRelativeAndAbs_002",
			"Description:\
			- cml_stl_matrix.h : cml::CMatrix<int, 1, 1, false>::boolean_t getAlmostEqualRelativeAndAbs( const self& rhs ) \
			- Testing: interface \
			- Overview: verify that the getAlmostEqualRelativeAndAbs works properly and cover all possible paths of implementation \
			- Entry conditions: if( !getElementsAlmostEqualRelativeAndAbs( operator[](rci+j), rhs[rci+j])) : false for all elements\
			- Expected results: returnValue = false");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Test Case data declarations */
			int temp_Data[1] = {1};
		typedef cml::CMatrix <int, 1, 1, false> self;
		cml::CMatrix<int, 1, 1, false> *testMatrix = new cml::CMatrix<int, 1, 1, false>;
		self a;
		cml::boolean_t returnValue, expected_returnValue; 			
		sint32 size = 1;

		/* Set global data */
		initialise_global_data();

		testMatrix->fill(1.5);
		a.fill(2);

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		expected_returnValue = 0;

		/* Call SUT */
		returnValue = testMatrix->getAlmostEqualRelativeAndAbs(a);

		/* Test Case checks */

		CHECK(returnValue, expected_returnValue);

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
void TEST_CLASS_MATRIX::test_CML_f_AbsGen(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_CML_f_AbsGen",
			"<Insert Test Case description here>");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Test Case data declarations */
			float32 x = DEFAULT_VALUE;
		float32 expected_returnValue = DEFAULT_VALUE;
		float32 returnValue;
		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* Call SUT */
		returnValue = CML_f_AbsGen(x);

		/* Test Case checks */
		CHECK(returnValue, expected_returnValue);
		/* Checks on global data */
		check_global_data();
		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_MATRIX::test_CML_f_MinGen(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_CML_f_MinGen",
			"<Insert Test Case description here>");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Test Case data declarations */
			float32 x = DEFAULT_VALUE;
		float32 y = DEFAULT_VALUE;
		float32 expected_returnValue = DEFAULT_VALUE;
		float32 returnValue;
		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* Call SUT */
		returnValue = CML_f_MinGen(x, y);

		/* Test Case checks */
		CHECK(returnValue, expected_returnValue);
		/* Checks on global data */
		check_global_data();
		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_MATRIX::test_CML_f_MaxGen(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_CML_f_MaxGen",
			"<Insert Test Case description here>");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Test Case data declarations */
			float32 x = DEFAULT_VALUE;
		float32 y = DEFAULT_VALUE;
		float32 expected_returnValue = DEFAULT_VALUE;
		float32 returnValue;
		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* Call SUT */
		returnValue = CML_f_MaxGen(x, y);

		/* Test Case checks */
		CHECK(returnValue, expected_returnValue);
		/* Checks on global data */
		check_global_data();
		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_MATRIX::test_CML_f_Round2FloatGen(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_CML_f_Round2FloatGen",
			"<Insert Test Case description here>");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Test Case data declarations */
			float32 x = DEFAULT_VALUE;
		float32 expected_returnValue = DEFAULT_VALUE;
		float32 returnValue;
		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* Call SUT */
		returnValue = CML_f_Round2FloatGen(x);

		/* Test Case checks */
		CHECK(returnValue, expected_returnValue);
		/* Checks on global data */
		check_global_data();
		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_MATRIX::test_CML_s_Round2IntGen(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_CML_s_Round2IntGen",
			"<Insert Test Case description here>");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Test Case data declarations */
			float32 x = DEFAULT_VALUE;
		sint32 expected_returnValue = DEFAULT_VALUE;
		sint32 returnValue;
		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* Call SUT */
		returnValue = CML_s_Round2IntGen(x);

		/* Test Case checks */
		CHECK(returnValue, expected_returnValue);
		/* Checks on global data */
		check_global_data();
		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_MATRIX::test_CML_u_Round2UintGen(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_CML_u_Round2UintGen",
			"<Insert Test Case description here>");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Test Case data declarations */
			float32 x = DEFAULT_VALUE;
		uint32 expected_returnValue = DEFAULT_VALUE;
		uint32 returnValue;
		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* Call SUT */
		returnValue = CML_u_Round2UintGen(x);

		/* Test Case checks */
		CHECK(returnValue, expected_returnValue);
		/* Checks on global data */
		check_global_data();
		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_MATRIX::test_CML_f_Floor2FloatGen(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_CML_f_Floor2FloatGen",
			"<Insert Test Case description here>");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Test Case data declarations */
			float32 f_x = DEFAULT_VALUE;
		float32 expected_returnValue = DEFAULT_VALUE;
		float32 returnValue;
		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* Call SUT */
		returnValue = CML_f_Floor2FloatGen(f_x);

		/* Test Case checks */
		CHECK(returnValue, expected_returnValue);
		/* Checks on global data */
		check_global_data();
		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_MATRIX::test_CML_f_Ceil2FloatGen(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_CML_f_Ceil2FloatGen",
			"<Insert Test Case description here>");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Test Case data declarations */
			float32 f_x = DEFAULT_VALUE;
		float32 expected_returnValue = DEFAULT_VALUE;
		float32 returnValue;
		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* Call SUT */
		returnValue = CML_f_Ceil2FloatGen(f_x);

		/* Test Case checks */
		CHECK(returnValue, expected_returnValue);
		/* Checks on global data */
		check_global_data();
		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_MATRIX::test_CML_f_MultAddGen(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_CML_f_MultAddGen",
			"<Insert Test Case description here>");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Test Case data declarations */
			float32 a = DEFAULT_VALUE;
		float32 b = DEFAULT_VALUE;
		float32 d = DEFAULT_VALUE;
		float32 expected_returnValue = DEFAULT_VALUE;
		float32 returnValue;
		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* Call SUT */
		returnValue = CML_f_MultAddGen(a, b, d);

		/* Test Case checks */
		CHECK(returnValue, expected_returnValue);
		/* Checks on global data */
		check_global_data();
		NO_EXCEPTIONS
			END_EXCEPTION
			END_CALLS();
		END_TEST();
	}
}

void TEST_CLASS_MATRIX::test_CML_a_InitMatrixHeader(int doIt)
{
	if (doIt) 
	{
		START_TEST("test_CML_a_InitMatrixHeader",
			"<Insert Test Case description here>");

		/* Expected Call Sequence  */
		EXPECTED_CALLS("");
		START_EXCEPTION
			/* Test Case data declarations */
			uint32 u_ColNr = DEFAULT_VALUE;
		uint32 u_RowNr = DEFAULT_VALUE;
		float32* p_f_MtrxData = DEFAULT_VALUE;
		CML_t_Matrix expected_returnValue = DEFAULT_VALUE;
		CML_t_Matrix returnValue;
		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* Call SUT */
		returnValue = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxData);

		/* Test Case checks */
		CHECK(returnValue, expected_returnValue);
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
#if 0
float32 CML_f_SqrtApprox(float32 f_radicand)
{
	sint32 s_expo;
	uint32 u_tmp;
	float32 f_Sample ,f_SampleSquare;
	float32 f_A, f_B, f_A_plus_B;
	float32 f_ret;

	/*! union for doing bit-wise manipulation on the floating point representation */
	/* Deactivate QA-C warning 3629; Reviewer: S. Schwarzkopf; Date: 04.12.2014; 
	Reason: This function uses union on purpose to easily access IEEE float 
	properties.
	Review-ID: 3942463 */
	/* PRQA S 3629 3 */
	union
	{
		float32 f_value; /* this is the number of interest as float */
		uint32  u_value; /* in here we hold the same number as int on which we can do bit-wise manipulations */
	} x_tmp;

	/* Deactivate QA-C warning 3112; Reviewer: S. Schwarzkopf; 
	Date: 04.12.2014; Reason: macro will be routed to assert() in simulation 
	environment.
	Review-ID: 3942463 */
	/* PRQA S 3112 2 */
	/* check for x < 0 or x = NaN */
	CML_ASSERT(f_radicand >= 0.f);

	/* copy input value to union where we can manipulate it directly */
	x_tmp.f_value = f_radicand;

	/* check for negative or zero or denormalized */
	if (  ((x_tmp.u_value >> 31) > 0U)    /* sign bit set? */
		|| ((x_tmp.u_value >> 23) == 0u) ) /* exponent is zero? */
	{
		f_ret = 0.f;
	}
	/* check for infinity */
	else if ((x_tmp.u_value >> 23) >= 0xffu)
	{
		x_tmp.u_value = 0x7f7fffffu;
		f_ret         = x_tmp.f_value; /* return max_float */
	}
	else
	{
		/* calculate start value by dividing exponent by two */
		u_tmp   = x_tmp.u_value >> CML_SqrtApprox_NumExpo;
		s_expo  = (sint32)(u_tmp);
		s_expo -= CML_SqrtApprox_ExponentOffset;
		if (s_expo < 0)
		{
			/* Deactivate QA-C warnings 0502, 4130, 0274; Reviewer: S. Schwarzkopf; 
			Date: 04.12.2014; Reason: Translate MISRA/PCLINT suppression below.
			Review-ID: 3942463 */
			/* PRQA S 0502, 4130, 0274 4 */
			/* <ln_offset:2to3 MISRA Rule 12.7: reviewer name: Daniel Meschenmoser date: 2013-05-06 reason: right shift of the signed quantity is safeguarded by filling the highest bit with one afterwards */
			/* <ln_offset:+1 PCLINT Error 704: reviewer name: Daniel Meschenmoser date: 2013-05-06 reason: right shift of the signed quantity is safeguarded by filling the highest bit with one afterwards */
			s_expo >>= 1; /* without the following line this would be unsafe because right shift of an unsigned int is machine dependent (sign fill vs. zero fill) */
			s_expo |= (sint32) 0x80000000U; /* -> fill highest bit with sign (one) after shift to make it safe */
		}
		else
		{
			/* Deactivate QA-C warning 0502; Reviewer: S. Schwarzkopf; 
			Date: 04.12.2014; Reason: Translate MISRA/PCLINT suppression below.
			Review-ID: 3942463 */
			/* PRQA S 0502, 4130, 0274 3 */
			/* <ln_offset:+2 MISRA Rule 12.7: reviewer name: Daniel Meschenmoser date: 2013-05-06 reason: right shift of the signed quantity is safe because the sign is zero -> sign fill = zero fill */
			/* <ln_offset:+1 PCLINT Error 704: reviewer name: Daniel Meschenmoser date: 2013-05-06 reason: right shift of the signed quantity is safe because the sign is zero -> sign fill = zero fill */
			s_expo >>= 1; /* for positive expo sign = 0 -> sign fill = zero fill */
		}
		s_expo  += CML_SqrtApprox_ExponentOffset;
		x_tmp.u_value &= CML_SqrtApprox_MantissaMask;
		x_tmp.u_value += ((uint32)s_expo << CML_SqrtApprox_NumExpo);
		f_Sample = x_tmp.f_value;

		/* two iterations are enough */
		/* iteration one */
		f_SampleSquare = CML_Sqr(f_Sample);
		f_A = 2.f * (f_SampleSquare + f_radicand);
		f_B = f_SampleSquare - f_radicand;
		f_A_plus_B = f_A + f_B;
		if (CML_f_Abs(f_A_plus_B) < CML_SqrtApprox_AlmostZero)
		{
			f_ret = 0.f;
		}
		else
		{
			f_Sample *= ( (f_A - f_B) / (f_A_plus_B) );
			/* iteration two */
			f_SampleSquare = CML_Sqr(f_Sample);
			f_A = 2.f * (f_SampleSquare + f_radicand);
			f_B = f_SampleSquare - f_radicand;

			f_A_plus_B = f_A + f_B;
			f_Sample  *= ( (f_A - f_B) / (f_A_plus_B) );
			f_ret = f_Sample;
		}
	}

	return f_ret;
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
