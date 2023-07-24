/*! \file **********************************************************************

COMPANY:                   Continental India

CPU:                       CPU-Independent

COMPONENT:                 CML (Common Math Library)

MODULNAME:                 test_cml_stl_point.cpp

DESCRIPTION:               Test script for Point Computations Library

AUTHOR:                    Balachandra Naik

CREATION DATE:             05.01.2016

VERSION:                   $Revision: 1.1 $

**************************************************************************** */

/* Include files from software under test */
#include <iostream>
#include <stdio.h>
#include "cml_ext.h"
#include "cml_stl_point.h"

/* Test Log file */
extern FILE *fpTest;

/* Function declaration */
void test_cml_stl_point(void);



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
	void run_tests_point();
	void test_CML_CartesianPoint2D_Constructor(int);
	void test_CML_CartesianPoint2D_norm(int);
	void test_CML_CartesianPoint2D_normSq(int);
	void test_CML_CartesianPoint2D_scalarProduct(int);
	void test_CML_CartesianPoint2D_crossProduct(int);

	void test_CML_CartesianPoint3D_Constructor(int);
	void test_CML_CartesianPoint3D_norm(int);
	void test_CML_CartesianPoint3D_normSq(int);
	void test_CML_CartesianPoint3D_scalarProduct(int);
	void test_CML_CartesianPoint3D_crossProduct(int);
	
#ifndef NDEBUG
	
#endif
	
};

/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_stl_point(void)
{
	TEST_CLASS test_object;	

	std::cout << "******** Start Testing: Point Library functions ********\n\n";
	fprintf(fpTest, "******** Start Testing: Point Library functions ********\n\n");

	test_object.run_tests_point();

	std::cout << "End of Testing: Point Library functions\n\n";
	fprintf(fpTest, "End of Testing: Point Library functions\n\n");
	
}

/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests_matrix() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS::run_tests_point()
{	
	test_CML_CartesianPoint2D_Constructor(1);
	test_CML_CartesianPoint2D_norm(1);
	test_CML_CartesianPoint2D_normSq(1);
	test_CML_CartesianPoint2D_scalarProduct(1);
	test_CML_CartesianPoint2D_crossProduct(1);

	test_CML_CartesianPoint3D_Constructor(1);
	test_CML_CartesianPoint3D_norm(1);
	test_CML_CartesianPoint3D_normSq(1);
	test_CML_CartesianPoint3D_scalarProduct(1);
	test_CML_CartesianPoint3D_crossProduct(1);	
}

/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/

// CartesianPoint2D()
// CartesianPoint2D(const T& _x, const T& _y)
// CartesianPoint2D(const super& mat)
// T& x()
// T& y()
void TEST_CLASS::test_CML_CartesianPoint2D_Constructor(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_CML_CartesianPoint2D_Constructor\n";
		fprintf(fpTest, "START ---> test_CML_CartesianPoint2D_Constructor\n");

		/* Test case data declarations */
		typedef cml::CartesianPoint2D <float32>           self; 
		
		self testPoint;
		
		float32 x_cord = 100, y_cord = 200;

		self *testObj;

		testPoint.x() = 10.0;
		testPoint.y() = 20.0;


		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* Call Function Under Test */
		testObj = new cml::CartesianPoint2D<float32>();

		delete testObj;

		testObj = new cml::CartesianPoint2D<float32>(x_cord, y_cord);

		delete testObj;

		testObj = new cml::CartesianPoint2D<float32>(testPoint);

		delete testObj;

		/* Checks on global data */
		check_global_data();	

		std::cout << "END ---> test_CML_CartesianPoint2D_Constructor\n\n";
		fprintf(fpTest, "END ---> test_CML_CartesianPoint2D_Constructor\n\n");
	}
}

// float32 norm() const
// const T& x()
// const T& y()
void TEST_CLASS::test_CML_CartesianPoint2D_norm(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_CML_CartesianPoint2D_norm\n";
		fprintf(fpTest, "START ---> test_CML_CartesianPoint2D_norm\n");

		/* float Vector : 2X1 */
		{			
			float32 vectroLength = 0;

			/* Test case data declarations */
			cml::CartesianPoint2D <float32>     testPoint; 
					
			float32 expected_vectroLength = 22.3606798f; 	

			testPoint.x() = 10.0;
			testPoint.y() = 20.0;

			std::cout << "test_CML_CartesianPoint2D_norm -> Length of float vector :  2X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint2D_norm -> Length of float vector :  2X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint.norm();	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* int Vector : 2X1 */
		{			
			float32 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint2D <sint32>     self; 
		
			self testPoint;

			float32 expected_vectroLength = 22.3606798f; 

			testPoint.x() = 10;
			testPoint.y() = 20;

			std::cout << "test_CML_CartesianPoint2D_norm -> Length of int vector :  2X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint2D_norm -> Length of int vector :  2X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint.norm();	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* short Vector : 2X1 */
		{			
			float32 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint2D <sint16>     self; 
		
			self testPoint;

			float32 expected_vectroLength = 22.3606798f; 

			testPoint.x() = 10;
			testPoint.y() = 20;

			std::cout << "test_CML_CartesianPoint2D_norm -> Length of short vector :  2X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint2D_norm -> Length of short vector :  2X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint.norm();	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* char Vector : 2X1 */
		{			
			float32 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint2D <sint8>     self; 
		
			self testPoint;

			float32 expected_vectroLength = 7.8102497f; 	

			testPoint.x() = 5;
			testPoint.y() = 6;

			std::cout << "test_CML_CartesianPoint2D_norm -> Length of char vector :  2X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint2D_norm -> Length of char vector :  2X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint.norm();	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		std::cout << "END ---> test_CML_CartesianPoint2D_norm\n\n";
		fprintf(fpTest, "END ---> test_CML_CartesianPoint2D_norm\n\n");
	}
}

// float32 normSq() const
void TEST_CLASS::test_CML_CartesianPoint2D_normSq(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_CML_CartesianPoint2D_normSq\n";
		fprintf(fpTest, "START ---> test_CML_CartesianPoint2D_normSq\n");

		/* float Vector : 2X1 */
		{		

			float32 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint2D <float32>     self; 
		
			self testPoint;

			float32 expected_vectroLength = 500.0; 	

			testPoint.x() = 10.0;
			testPoint.y() = 20.0;

			std::cout << "test_CML_CartesianPoint2D_normSq -> Squared length of the float vector :  2X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint2D_normSq -> Squared length of the float vector :  2X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint.normSq();	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* int Vector : 2X1 */
		{			
			float32 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint2D <sint32>     self; 
		
			self testPoint;

			float32 expected_vectroLength = 500.0; 	

			testPoint.x() = 10;
			testPoint.y() = 20;

			std::cout << "test_CML_CartesianPoint2D_normSq -> Squared length of int vector :  2X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint2D_normSq -> Squared length of int vector :  2X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint.normSq();	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* short Vector : 2X1 */
		{
			float32 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint2D <sint16>     self; 
		
			self testPoint;

			float32 expected_vectroLength = 500.0; 	

			testPoint.x() = 10;
			testPoint.y() = 20;

			std::cout << "test_CML_CartesianPoint2D_normSq -> Squared length of short vector :  2X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint2D_normSq -> Squared length of short vector :  2X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint.normSq();	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* char Vector : 2X1 */
		{
			float32 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint2D <sint8>     self; 
		
			self testPoint;

			float32 expected_vectroLength = 61.0;

			testPoint.x() = 5;
			testPoint.y() = 6;

			std::cout << "test_CML_CartesianPoint2D_normSq -> Squared length of char vector :  2X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint2D_normSq -> Squared length of char vector :  2X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint.normSq();	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		std::cout << "END ---> test_CML_CartesianPoint2D_normSq\n\n";
		fprintf(fpTest, "END ---> test_CML_CartesianPoint2D_normSq\n\n");
	}
}

//T scalarProduct(const self& rhs) const
void TEST_CLASS::test_CML_CartesianPoint2D_scalarProduct(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_CML_CartesianPoint2D_scalarProduct\n";
		fprintf(fpTest, "START ---> test_CML_CartesianPoint2D_scalarProduct\n");

		/* float Vector : 2X1 */
		{			
			float32 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint2D <float32>     self; 
		
			self testPoint1, testPoint2;

			float32 expected_vectroLength = 2500.0; 

			testPoint1.x() = 10.0;
			testPoint1.y() = 20.0;

			testPoint2.x() = 50.0;
			testPoint2.y() = 100.0;

			std::cout << "test_CML_CartesianPoint2D_scalarProduct -> Scalar product of the float vectors :  2X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint2D_scalarProduct -> Scalar product of the float vector :  2X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint1.scalarProduct(testPoint2);	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* int Vector : 2X1 */
		{	
			sint32 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint2D <sint32>     self; 
		
			self testPoint1, testPoint2;

			sint32 expected_vectroLength = 2500; 	

			testPoint1.x() = 10;
			testPoint1.y() = 20;

			testPoint2.x() = 50;
			testPoint2.y() = 100;

			std::cout << "test_CML_CartesianPoint2D_scalarProduct -> Scalar product of int vector :  2X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint2D_scalarProduct -> Scalar product of int vector :  2X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint1.scalarProduct(testPoint2);	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* short Vector : 2X1 */
		{	
			sint16 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint2D <sint16>     self; 
		
			self testPoint1, testPoint2;

			sint16 expected_vectroLength = 2500; 

			testPoint1.x() = 10;
			testPoint1.y() = 20;

			testPoint2.x() = 50;
			testPoint2.y() = 100;

			std::cout << "test_CML_CartesianPoint2D_scalarProduct -> Scalar product of short vector :  2X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint2D_scalarProduct -> Scalar product of short vector :  2X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint1.scalarProduct(testPoint2);	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* char Vector : 2X1 */
		{
			sint8 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint2D <sint8>     self; 
		
			self testPoint1, testPoint2;

			sint8 expected_vectroLength = 80; 

			testPoint1.x() = 5;
			testPoint1.y() = 6;

			testPoint2.x() = 10;
			testPoint2.y() = 5;

			std::cout << "test_CML_CartesianPoint2D_scalarProduct -> Scalar product of char vector :  2X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint2D_scalarProduct -> Scalar product of char vector :  2X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint1.scalarProduct(testPoint2);	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		std::cout << "END ---> test_CML_CartesianPoint2D_scalarProduct\n\n";
		fprintf(fpTest, "END ---> test_CML_CartesianPoint2D_scalarProduct\n\n");
	}
}

//T crossProduct(const self& rhs) const
void TEST_CLASS::test_CML_CartesianPoint2D_crossProduct(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_CML_CartesianPoint2D_crossProduct\n";
		fprintf(fpTest, "START ---> test_CML_CartesianPoint2D_crossProduct\n");

		/* float Vector : 2X1 */
		{			

			float32 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint2D <float32>     self; 
		
			self testPoint1, testPoint2;

			testPoint1.x() = 10.0;
			testPoint1.y() = 20.0;

			testPoint2.x() = 50.0;
			testPoint2.y() = 100.0;

			float32 expected_vectroLength = 9000.0; 	

			std::cout << "test_CML_CartesianPoint2D_crossProduct -> Cross product of the float vectors :  2X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint2D_crossProduct -> Cross product of the float vector :  2X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint1.crossProduct(testPoint2);	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* int Vector : 2X1 */
		{	
			sint32 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint2D <sint32>     self; 
		
			self testPoint1, testPoint2;

			testPoint1.x() = 10;
			testPoint1.y() = 20;

			testPoint2.x() = 50;
			testPoint2.y() = 100;

			sint32 expected_vectroLength = 9000; 	

			std::cout << "test_CML_CartesianPoint2D_crossProduct -> Cross product of int vector :  2X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint2D_crossProduct -> Cross product of int vector :  2X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint1.crossProduct(testPoint2);	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* short Vector : 2X1 */
		{		
			sint16 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint2D <sint16>     self; 
		
			self testPoint1, testPoint2;

			testPoint1.x() = 10;
			testPoint1.y() = 20;

			testPoint2.x() = 50;
			testPoint2.y() = 100;

			sint16 expected_vectroLength = 9000; 	

			std::cout << "test_CML_CartesianPoint2D_crossProduct -> Cross product of short vector :  2X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint2D_crossProduct -> Cross product of short vector :  2X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint1.crossProduct(testPoint2);	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* char Vector : 2X1 */
		{
			sint8 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint2D <sint8>     self; 
		
			self testPoint1, testPoint2;

			testPoint1.x() = 25;
			testPoint1.y() = 6;

			testPoint2.x() = 10;
			testPoint2.y() = 5;

			sint8 expected_vectroLength = 65; 	

			std::cout << "test_CML_CartesianPoint2D_crossProduct -> Cross product of char vector :  2X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint2D_crossProduct -> Cross product of char vector :  2X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint1.crossProduct(testPoint2);	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		std::cout << "END ---> test_CML_CartesianPoint2D_crossProduct\n\n";
		fprintf(fpTest, "END ---> test_CML_CartesianPoint2D_crossProduct\n\n");
	}
}

/// CartesianPoint3D
/// CartesianPoint3D(const T& _x, const T& _y, const T& _z)
/// CartesianPoint3D(const super& mat)
/// T& x()
/// T& y()
/// T& z()
void TEST_CLASS::test_CML_CartesianPoint3D_Constructor(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_CML_CartesianPoint3D_Constructor\n";
		fprintf(fpTest, "START ---> test_CML_CartesianPoint3D_Constructor\n");

		float32 A[3] = {10.0, 20.0, 30.0};

		/* Test case data declarations */
		typedef cml::CartesianPoint3D <float32>    self; 
		cml::CartesianPoint3D <float32>      testPoint; 
		
		float32 x_cord = 100, y_cord = 200, z_cord = 300;

		testPoint.x() = 10.0;
		testPoint.y() = 20.0;
		testPoint.z() = 30.0;

		self *testObj;

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* Call Function Under Test */
		testObj = new cml::CartesianPoint3D<float32>();

		delete testObj;

		testObj = new cml::CartesianPoint3D<float32>(x_cord, y_cord, z_cord);

		delete testObj;

		testObj = new cml::CartesianPoint3D<float32>(testPoint);

		delete testObj;

		/* Checks on global data */
		check_global_data();	

		std::cout << "END ---> test_CML_CartesianPoint3D_Constructor\n\n";
		fprintf(fpTest, "END ---> test_CML_CartesianPoint3D_Constructor\n\n");
	}
}

// float32 norm() const
// const T& x()
// const T& y()
// const T& z()
void TEST_CLASS::test_CML_CartesianPoint3D_norm(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_CML_CartesianPoint3D_norm\n";
		fprintf(fpTest, "START ---> test_CML_CartesianPoint3D_norm\n");

		/* float Vector : 3X1 */
		{
			float32 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint3D <float32>     self; 
		
			self testPoint;

			testPoint.x() = 10.0;
			testPoint.y() = 20.0;
			testPoint.z() = 30.0;

			float32 expected_vectroLength = 37.416574f; 	

			std::cout << "test_CML_CartesianPoint3D_norm -> Length of float vector :  3X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint3D_norm -> Length of float vector :  3X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint.norm();	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* int Vector : 3X1 */
		{
			float32 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint3D <sint32>     self; 
		
			self testPoint;

			testPoint.x() = 10;
			testPoint.y() = 20;
			testPoint.z() = 30;

			float32 expected_vectroLength = 37.416574f; 	

			std::cout << "test_CML_CartesianPoint3D_norm -> Length of int vector :  3X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint3D_norm -> Length of int vector :  3X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint.norm();	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* short Vector : 3X1 */
		{
			float32 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint3D <sint16>     self; 
		
			self testPoint;

			testPoint.x() = 10;
			testPoint.y() = 20;
			testPoint.z() = 30;

			float32 expected_vectroLength = 37.416574f; 	

			std::cout << "test_CML_CartesianPoint3D_norm -> Length of short vector :  3X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint3D_norm -> Length of short vector :  3X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint.norm();	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* char Vector : 3X1 */
		{
			float32 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint3D <sint8>     self; 
		
			self testPoint;

			testPoint.x() = 5;
			testPoint.y() = 6;
			testPoint.z() = 7;

			float32 expected_vectroLength = 10.488089f; 	

			std::cout << "test_CML_CartesianPoint3D_norm -> Length of char vector :  3X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint3D_norm -> Length of char vector :  3X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint.norm();	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		std::cout << "END ---> test_CML_CartesianPoint3D_norm\n\n";
		fprintf(fpTest, "END ---> test_CML_CartesianPoint3D_norm\n\n");
	}
}

// float32 normSq() const
void TEST_CLASS::test_CML_CartesianPoint3D_normSq(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_CML_CartesianPoint3D_normSq\n";
		fprintf(fpTest, "START ---> test_CML_CartesianPoint3D_normSq\n");

		/* float Vector : 3X1 */
		{
			float32 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint3D <float32>     self; 
		
			self testPoint;

			testPoint.x() = 10.0;
			testPoint.y() = 20.0;
			testPoint.z() = 30.0;

			float32 expected_vectroLength = 1400.0; 	

			std::cout << "test_CML_CartesianPoint3D_normSq -> Squared length of the float vector :  3X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint3D_normSq -> Squared length of the float vector :  3X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint.normSq();	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* int Vector : 3X1 */
		{
			float32 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint3D <sint32>     self; 
		
			self testPoint;

			testPoint.x() = 10;
			testPoint.y() = 20;
			testPoint.z() = 30;

			float32 expected_vectroLength = 1400.0; 	

			std::cout << "test_CML_CartesianPoint3D_normSq -> Squared length of int vector :  3X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint3D_normSq -> Squared length of int vector :  3X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint.normSq();	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* short Vector : 3X1 */
		{
			float32 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint3D <sint16>     self; 
		
			self testPoint;

			testPoint.x() = 10;
			testPoint.y() = 20;
			testPoint.z() = 30;

			float32 expected_vectroLength = 1400.0; 	

			std::cout << "test_CML_CartesianPoint3D_normSq -> Squared length of short vector :  3X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint3D_normSq -> Squared length of short vector :  3X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint.normSq();	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* char Vector : 3X1 */
		{
			float32 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint3D <sint8>     self; 
		
			self testPoint;

			testPoint.x() = 5;
			testPoint.y() = 6;
			testPoint.z() = 7;

			float32 expected_vectroLength = 110.0; 	

			std::cout << "test_CML_CartesianPoint3D_normSq -> Squared length of char vector :  3X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint3D_normSq -> Squared length of char vector :  3X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint.normSq();	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		std::cout << "END ---> test_CML_CartesianPoint3D_normSq\n\n";
		fprintf(fpTest, "END ---> test_CML_CartesianPoint3D_normSq\n\n");
	}
}

//T scalarProduct(const self& rhs) const
void TEST_CLASS::test_CML_CartesianPoint3D_scalarProduct(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_CML_CartesianPoint3D_scalarProduct\n";
		fprintf(fpTest, "START ---> test_CML_CartesianPoint3D_scalarProduct\n");

		/* float Vector : 3X1 */
		{			
			float32 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint3D <float32>     self; 
		
			self testPoint1, testPoint2;

			testPoint1.x() = 10.0;
			testPoint1.y() = 20.0;
			testPoint1.z() = 30.0;

			testPoint2.x() = 50.0;
			testPoint2.y() = 100.0;
			testPoint2.z() = 300.0;

			float32 expected_vectroLength = 11500; 	

			std::cout << "test_CML_CartesianPoint3D_scalarProduct -> Scalar product of the float vectors :  3X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint3D_scalarProduct -> Scalar product of the float vector :  3X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint1.scalarProduct(testPoint2);	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* int Vector : 3X1 */
		{
			sint32 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint3D <sint32>     self; 
		
			self testPoint1, testPoint2;

			testPoint1.x() = 10;
			testPoint1.y() = 20;
			testPoint1.z() = 30;

			testPoint2.x() = 50;
			testPoint2.y() = 100;
			testPoint2.z() = 300;

			sint32 expected_vectroLength = 11500; 	

			std::cout << "test_CML_CartesianPoint3D_scalarProduct -> Scalar product of int vector :  3X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint3D_scalarProduct -> Scalar product of int vector :  3X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint1.scalarProduct(testPoint2);	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* short Vector : 3X1 */
		{
			sint16 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint3D <sint16>     self; 
		
			self testPoint1, testPoint2;

			testPoint1.x() = 10;
			testPoint1.y() = 20;
			testPoint1.z() = 30;

			testPoint2.x() = 50;
			testPoint2.y() = 100;
			testPoint2.z() = 300;

			sint16 expected_vectroLength = 11500; 	

			std::cout << "test_CML_CartesianPoint3D_scalarProduct -> Scalar product of short vector :  3X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint3D_scalarProduct -> Scalar product of short vector :  3X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint1.scalarProduct(testPoint2);	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		/* char Vector : 3X1 */
		{
			sint8 vectroLength = 0;

			/* Test case data declarations */
			typedef cml::CartesianPoint3D <sint8>     self; 
		
			self testPoint1, testPoint2;

			testPoint1.x() = 5;
			testPoint1.y() = 6;
			testPoint1.z() = 7;

			testPoint2.x() = 10;
			testPoint2.y() = 5;
			testPoint2.z() = 4;

			sint8 expected_vectroLength = 108; 	

			std::cout << "test_CML_CartesianPoint3D_scalarProduct -> Scalar product of char vector :  3X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint3D_scalarProduct -> Scalar product of char vector :  3X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			vectroLength = 	testPoint1.scalarProduct(testPoint2);	

			/* Checks on global data */
			if(vectroLength == expected_vectroLength)
			{
				check_global_data();
			}
			else
			{
				std::cout << "Test case: FAIL\n";    
				fprintf(fpTest, "Test case: FAIL\n");
			}
		}

		std::cout << "END ---> test_CML_CartesianPoint3D_scalarProduct\n\n";
		fprintf(fpTest, "END ---> test_CML_CartesianPoint3D_scalarProduct\n\n");
	}
}

//T crossProduct(const self& rhs) const
void TEST_CLASS::test_CML_CartesianPoint3D_crossProduct(int doIt)
{
	if (doIt) 
	{
		std::cout << "START ---> test_CML_CartesianPoint3D_crossProduct\n";
		fprintf(fpTest, "START ---> test_CML_CartesianPoint3D_crossProduct\n");

		/* float Vector : 3X1 */
		{				
			/* Test case data declarations */
			typedef cml::CartesianPoint3D <float32>     self; 
					
			self testPoint1, testPoint2, result;
			self result_matrix, expected_result;

			testPoint1.x() = 10.0;
			testPoint1.y() = 20.0;
			testPoint1.z() = 30.0;

			testPoint2.x() = 50.0;
			testPoint2.y() = 100.0;
			testPoint2.z() = 40.0;			

			result_matrix.x() = 0;
			result_matrix.y() = 0;
			result_matrix.z() = 0;

			expected_result.x() = -2200.0;
			expected_result.y() = -2500.0;
			expected_result.z() = 9000.0;

			cml::boolean_t returnValue = FALSE; 	

			std::cout << "test_CML_CartesianPoint3D_crossProduct -> Cross product of the float vectors :  3X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint3D_crossProduct -> Cross product of the float vector :  3X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = 	testPoint1.crossProduct(testPoint2);	

#ifndef NDEBUG
			/* Copy the result matrix to this */
			result_matrix = result;

			/* Checks on global data */			
			returnValue = result_matrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif

			/* Checks on global data */
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

		/* int Vector : 3X1 */
		{
			/* Test case data declarations */
			typedef cml::CartesianPoint3D <sint32>     self; 
			
			self testPoint1, testPoint2, result;
			self result_matrix, expected_result;

			testPoint1.x() = 10;
			testPoint1.y() = 20;
			testPoint1.z() = 30;

			testPoint2.x() = 50;
			testPoint2.y() = 100;
			testPoint2.z() = 40;
						
			result_matrix.x() = 0;
			result_matrix.y() = 0;
			result_matrix.z() = 0;

			expected_result.x() = -2200;
			expected_result.y() = -2500;
			expected_result.z() = 9000;

			cml::boolean_t returnValue = FALSE; 

			std::cout << "test_CML_CartesianPoint3D_crossProduct -> Cross product of int vector :  3X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint3D_crossProduct -> Cross product of int vector :  3X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = 	testPoint1.crossProduct(testPoint2);	

#ifndef NDEBUG
			/* Copy the result matrix to this */
			result_matrix = result;

			/* Checks on global data */			
			returnValue = result_matrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif

			/* Checks on global data */
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

		/* short Vector : 3X1 */
		{	
			/* Test case data declarations */
			typedef cml::CartesianPoint3D <sint16>     self; 
					
			self testPoint1, testPoint2, result;
			self result_matrix, expected_result;

			testPoint1.x() = 10;
			testPoint1.y() = 20;
			testPoint1.z() = 30;

			testPoint2.x() = 50;
			testPoint2.y() = 100;
			testPoint2.z() = 40;

			result_matrix.x() = 0;
			result_matrix.y() = 0;
			result_matrix.z() = 0;

			expected_result.x() = -2200;
			expected_result.y() = -2500;
			expected_result.z() = 9000;

			cml::boolean_t returnValue = FALSE; 	

			std::cout << "test_CML_CartesianPoint3D_crossProduct -> Cross product of short vector :  3X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint3D_crossProduct -> Cross product of short vector :  3X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = 	testPoint1.crossProduct(testPoint2);	

#ifndef NDEBUG
			/* Copy the result matrix to this */
			result_matrix = result;

			/* Checks on global data */			
			returnValue = result_matrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif

			/* Checks on global data */
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

		/* char Vector : 3X1 */
		{				
			/* Test case data declarations */
			typedef cml::CartesianPoint3D <sint8>     self; 
					
			self testPoint1, testPoint2, result;
			self result_matrix, expected_result;

			testPoint1.x() = 25;
			testPoint1.y() = 6;
			testPoint1.z() = 4;

			testPoint2.x() = 10;
			testPoint2.y() = 5;
			testPoint2.z() = 3;

			result_matrix.x() = 0;
			result_matrix.y() = 0;
			result_matrix.z() = 0;

			expected_result.x() = -2;
			expected_result.y() = -35;
			expected_result.z() = 65;
						
			cml::boolean_t returnValue = FALSE; 

			std::cout << "test_CML_CartesianPoint3D_crossProduct -> Cross product of char vector :  3X1 Matrix\n";
			fprintf(fpTest, "test_CML_CartesianPoint3D_crossProduct -> Cross product of char vector :  3X1 Matrix\n");

			/* Set global data */
			initialise_global_data();

			/* Set expected values for global data checks */
			initialise_expected_global_data();

			/* Call Function Under Test */
			result = 	testPoint1.crossProduct(testPoint2);	

#ifndef NDEBUG
			/* Copy the result matrix to this */
			result_matrix = result;

			/* Checks on global data */			
			returnValue = result_matrix.getAlmostEqualRelativeAndAbs(expected_result);
#endif

			/* Checks on global data */
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

		std::cout << "END ---> test_CML_CartesianPoint3D_crossProduct\n\n";
		fprintf(fpTest, "END ---> test_CML_CartesianPoint3D_crossProduct\n\n");
	}
}

// End of test cases      

