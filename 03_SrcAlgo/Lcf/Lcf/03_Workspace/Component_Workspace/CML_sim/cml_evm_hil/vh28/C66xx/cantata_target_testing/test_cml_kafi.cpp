/*****************************************************************************/
/*                            CML Target Test Script                         */
/*****************************************************************************/
/*
*    Filename: test_cml_kafi.cpp
*    Author: uidr5285
*    Generated on: 12-Feb-2016 15:43:28
*/
/*****************************************************************************/
/* Environment Definition                                                    */
/*****************************************************************************/

/* Include files from software under test */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <functional>
#include <random>
#include <iostream>
#include <memory>
#include <float.h>
#include <math.h>

extern "C" {
#include "cml_ext.h"
}

/* The default value used for test script variables and stub returns*/
#define DEFAULT_VALUE 0
#define DELIMITER ','

#include "csv_parser.h"

#ifndef LINKED_LIST_PARSER
extern float data_log_buffer[1000000];
#endif

/* Test Log file */
extern FILE *fpTest;

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
}

/*****************************************************************************/
/* Test class declaration                                                    */
/*****************************************************************************/
class TEST_CLASS_CML_KAFI
{
public:
	void run_tests_kafi();
	void test_cml_kalman_flow_1D(int doIt);
	void test_cml_kalman_flow_2D(int doIt);
	
};

/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_kafi(void)
{
	TEST_CLASS_CML_KAFI test_object;

	std::cout << "******** Start Testing: kalman Library functions ********\n\n";
	fprintf(fpTest, "******** Start Testing: kalman Library functions ********\n\n");

	test_object.run_tests_kafi();

	std::cout << "End of Testing: kalman Library functions\n\n";
	fprintf(fpTest, "End of Testing: kalman Library functions\n\n");

	return;
}


/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS_CML_KAFI::run_tests_kafi()
{
	//test_cml_kalman_flow_1D(1);
	test_cml_kalman_flow_2D(1);
}

/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/
void TEST_CLASS_CML_KAFI::test_cml_kalman_flow_1D(int doIt)
{
	std::cout << "START ---> test_cml_kalman_flow_1D\n\n";		
	fprintf(fpTest, "START ---> test_cml_kalman_flow_1D\n\n");

	fprintf(fpTest, "Function Name ---> Kalman filter for 1D Model \n\n");

	if (doIt) 
	{
		
		{

			CML_t_SimpleKafi temp_kalman_var;
			CML_t_SimpleKafi *kalman_var = &temp_kalman_var;
			float32 temp_A= 1;

			float32 temp_B = 0;

			float32 temp_x = 0;

			float32 temp_u = 0;

			float32 temp_P = 1;

			float32 temp_Q = 0;

			float32 temp_H = 1;

			float32 temp_Z_sensor[10] = { 0.39, 0.50, 0.48, 0.29, 0.25, 0.32, 0.34, 0.48, 0.41, 0.45 };

			float32 temp_Z = 0.39;

			float32 temp_R = 0.1;

			float32 temp_K = 0;


			float32 temp_T = 0;

			float32 temp_Tx = 0;

			float32 temp_T2 = 0 ;
			uint8 itr, ret;

				temp_kalman_var.A = &temp_A;
				temp_kalman_var.B = &temp_B;
				temp_kalman_var.B_x =  1;
				temp_kalman_var.H = &temp_H;
				temp_kalman_var.K = &temp_K;
				temp_kalman_var.P = &temp_P;
				temp_kalman_var.Q = &temp_Q;
				temp_kalman_var.R = &temp_R;
				temp_kalman_var.T = &temp_T;
				temp_kalman_var.T2 = &temp_T2;
				temp_kalman_var.tx = &temp_Tx;
				temp_kalman_var.u = &temp_u;
				temp_kalman_var.x = &temp_x;
				temp_kalman_var.x_y = 1;
				temp_kalman_var.z = &temp_Z;

				/* Set global data */
				initialise_global_data();

				for ( itr = 0; itr < 10; itr++ )
				{
					*(temp_kalman_var.z) = temp_Z_sensor[itr];
					CML_u_SimpleKafiPrediction(kalman_var);
					//CML_u_SimpleKafiInit(kalman_var);
					ret = CML_u_SimpleKafiUpdate(kalman_var);
					printf(" x = %f \t",*(temp_kalman_var.x));
					printf(" P = %f \t\n",*(temp_kalman_var.P));
			
				}
		}

	}

	std::cout << "END ---> test_cml_kalman_flow_1D\n\n";
	fprintf(fpTest, "END ---> test_cml_kalman_flow_1D\n\n");
}

void TEST_CLASS_CML_KAFI::test_cml_kalman_flow_2D(int doIt)
{

	std::cout << "START ---> test_cml_kalman_flow_2D\n\n";		
	fprintf(fpTest, "START ---> test_cml_kalman_flow_2D\n\n");

	fprintf(fpTest, "Function Name ---> Kalman filter for 2D Model \n\n");

	if (doIt) 
	{
			std::default_random_engine generator;
			std::normal_distribution<float32> distribution(0.0,4.0);
			CML_t_SimpleKafi *kalman_var =(CML_t_SimpleKafi *) malloc(sizeof(CML_t_SimpleKafi));
			float32 temp_A[16]= { 1, 0.1, 0,   0,
								  0, 1,   0, 0,
								  0, 0,   1, 0.1,
								  0, 0,   0,   1 };

			float32 temp_B[16] = { 0, 0,  0,  0,
								   0, 0,  0,  0,
								   0, 0,  0,  0,
								   0, 0,  0,  0 };

			float32 temp_x[4] = { 110.0,
								  22.0,
								  110.0,
								  12.0 };// intial state matrix

			float32 temp_u[4] = { 0,
								  0,
								  0,
								  0 };//control input matrix

			float32 temp_P[16] = { 4, 0,  0,  0,
								   0, 4,  0,  0,
								   0, 0,  4,  0,
								   0, 0,  0,  4 };// inital covarience matrix
			float32 dt = 0.1; // delta time

			float32 temp_Q[16] = { (1/3)*(dt*dt*dt*dt), 0.5*(dt*dt*dt),   0,  0,
								       0.5*(dt*dt*dt),        (dt*dt),   0,  0,
								                    0,	            0,   (1/3)*(dt*dt*dt*dt),   0.5*(dt*dt*dt),
													0,              0,       0.5*(dt*dt*dt),         (dt*dt) };// process noise matrix

			float32 temp_H[8] = { 1, 0,  0,  0,
								  0, 0,  1,  0};// measurement Matrix

			float32 temp_G[8] = { 0.5*(dt*dt), 0,
										   dt,	0,
											0, 0.5*(dt*dt),
											0,  dt}; //iterative matrix to generate samples

			float32 temp_Z[10] ;

			float32 temp_W[2] ;

			float32 temp_R[4] = { 4,
								  0,
								  0,
								  4 };// measurement nOISE

			float32 temp_K[16] = { 1, 1,  1,  1,
								   1, 1,  1,  1,
								   1, 1,  1,  1,
								   1, 1,  1,  1 };//Kalmann Gain 


			float32 temp_T[16] = { 0, 0,  0,  0,
								   0, 0,  0,  0,
								   0, 0,  0,  0,
								   0, 0,  0,  0 };

			float32 temp_Tx[4] = { 0,
								  0,
								  0,
								  0 };

			float32 temp_A_x_X_Result[4] = { 0,
								  0,
								  0,
								  0 };

			float32 temp_G_x_W_Result[4] = { 0,
								  0,
								  0,
								  0 };

			float32 temp_T2[16] = { 0, 0,  0,  0,
								   0, 0,  0,  0,
								   0, 0,  0,  0,
								   0, 0,  0,  0 };

			float32 *Process_Vector[200];
			float32 *G = temp_G;
			float32 *W = temp_W;
			float32 *A_x_X_Result = &temp_A_x_X_Result[0];
			float32 *G_x_W_Result = &temp_G_x_W_Result[0];
			float32 *Measured_Vector[200];
			uint8 itr, ret;

			kalman_var->A = temp_A;
			kalman_var->B = temp_B;
			kalman_var->B_x = 4;
			kalman_var->H = temp_H;
			kalman_var->K = temp_K;
			kalman_var->P = temp_P;
			kalman_var->Q = temp_Q;
			kalman_var->R = temp_R;
			kalman_var->T = temp_T;
			kalman_var->T2 = temp_T2;
			kalman_var->tx = temp_Tx;
			kalman_var->u = temp_u;
			kalman_var->x = temp_x;
			kalman_var->x_y = 4;
			kalman_var->z = temp_Z;

			Process_Vector[0] = (float32 *) malloc(sizeof(float32)*4);
			Measured_Vector[0] = (float32 *) malloc(sizeof(float32)*4);

			*(Process_Vector[0]) = temp_x[0];
			*(Process_Vector[0]+1) = temp_x[1];
			*(Process_Vector[0]+2) = temp_x[2];
			*(Process_Vector[0]+3) = temp_x[3];

			*(Measured_Vector[0]) = temp_x[0] + distribution(generator);
			*(Measured_Vector[0]+1) = temp_x[1] + distribution(generator);
			*(Measured_Vector[0]+2) = temp_x[2] + distribution(generator);
			*(Measured_Vector[0]+3) = temp_x[3] + distribution(generator);

			*(kalman_var->x)   = *(Process_Vector[0]);  
			*(kalman_var->x+1) = *(Process_Vector[0]+1);
			*(kalman_var->x+2) = *(Process_Vector[0]+2);
			*(kalman_var->x+3) = *(Process_Vector[0]+3);

			/* Set global data */
			initialise_global_data();
			
			for ( itr = 1; itr < 40; itr++ )
			{
				Process_Vector[itr] = (float32 *) malloc(sizeof(float32)*4);
				Measured_Vector[itr] = (float32 *) malloc(sizeof(float32)*4);
				temp_W[0] =  distribution(generator);
				temp_W[1] =  distribution(generator);
				CML_u_MatrixMultiplication(kalman_var->A, Process_Vector[itr-1], A_x_X_Result, 4, 4, 1);
				CML_u_MatrixMultiplication(G, W, G_x_W_Result, 2, 4, 1);
				CML_u_MatrixAddition(A_x_X_Result, G_x_W_Result, Process_Vector[itr], 4, 1);
				*(Measured_Vector[itr]) =    *(Process_Vector[itr])  + distribution(generator);
				*(Measured_Vector[itr]+1) =  *(Process_Vector[itr]+1)  + distribution(generator);
				*(Measured_Vector[itr]+2) =  *(Process_Vector[itr]+2)  + distribution(generator);
				*(Measured_Vector[itr]+3) =  *(Process_Vector[itr]+3)  + distribution(generator);
			}

			fprintf(fpTest,"\n\n");

			fprintf(fpTest,"Process_Vector_x\t\t");
			fprintf(fpTest,"Process_Vector_x' \t\t");
			fprintf(fpTest,"Process_Vector_y\t\t");
			fprintf(fpTest,"Process_Vector_y'\t\t");

			fprintf(fpTest,"Measured_Vector_x \t\t");
			fprintf(fpTest,"Measured_Vector_x' \t\t");
			fprintf(fpTest,"Measured_Vector_y \t\t");
			fprintf(fpTest,"Measured_Vector_y'\t\t");

			fprintf(fpTest,"Predicted_Vector_x\t\t");
			fprintf(fpTest,"Predicted_Vector_x' \t\t");
			fprintf(fpTest,"Predicted_Vector_y\t\t");
			fprintf(fpTest,"Predicted_Vector_y'\t\n");
			
			for ( itr = 0; itr < 40; itr++ )
			{
				*(kalman_var->z) = *(Measured_Vector[itr]);
				*(kalman_var->z+1) = *(Measured_Vector[itr]+1);
				*(kalman_var->z+2) = *(Measured_Vector[itr]+2);
				*(kalman_var->z+3) = *(Measured_Vector[itr]+3);
			
				CML_u_SimpleKafiPrediction(kalman_var);
				//CML_u_SimpleKafiInit(kalman_var);
				CML_u_SimpleKafiUpdate(kalman_var);

				fprintf(fpTest,"%.4f\t\t\t\t",*(Process_Vector[itr]));
				fprintf(fpTest," %.4f\t\t\t\t",*(Process_Vector[itr]+1));
				fprintf(fpTest," %.4f\t\t\t\t",*(Process_Vector[itr]+2));
				fprintf(fpTest," %.4f\t\t\t\t",*(Process_Vector[itr]+3));

				fprintf(fpTest,"%.4f\t\t\t\t",*(Measured_Vector[itr]));
				fprintf(fpTest," %.4f\t\t\t\t",*(Measured_Vector[itr]+1));
				fprintf(fpTest," %.4f\t\t\t\t",*(Measured_Vector[itr]+2));
				fprintf(fpTest," %.4f\t\t\t\t",*(Measured_Vector[itr]+3));

				fprintf(fpTest,"%.4f \t\t\t\t\t",*(kalman_var->x));
				fprintf(fpTest,"%.4f \t\t\t\t\t",*(kalman_var->x+1));
				fprintf(fpTest,"%.4f \t\t\t\t\t",*(kalman_var->x+2));
				fprintf(fpTest,"%.4f \t\t\t\t\t\n",*(kalman_var->x+3));
			}

		fprintf(fpTest,"\n\n");

	}

	std::cout << "END ---> test_cml_kalman_flow_2D\n\n";
	fprintf(fpTest, "END ---> test_cml_kalman_flow_2D\n\n");
}