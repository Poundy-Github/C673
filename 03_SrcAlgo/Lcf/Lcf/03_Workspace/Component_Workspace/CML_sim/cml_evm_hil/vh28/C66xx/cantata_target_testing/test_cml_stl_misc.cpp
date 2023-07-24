/*****************************************************************************/
/*                            CML Swap Test Script                            */
/*****************************************************************************/
/*
*    Filename: test_cml_stl_misc.cpp
*    Author: uid33569
*    Generated on: 22-Jun-2018 16:53:36
*    Generated from: cml_stl_misc.cpp
*/
/*****************************************************************************/
/* Environment Definition                                                    */
/*****************************************************************************/

#ifndef cml_stl_misc_h__
#define cml_stl_misc_h__

/* Include files from software under test */
#include <stdio.h>
#include <iostream>
#include "cml_stl_misc.h"


/* Test Log file */
extern FILE *fpTest;

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
#if 0
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

#endif

/* This function checks global data against the expected values. */
static void check_global_data(){

	/* No global data */
	std::cout << "\nStatus ---> PASS\n\n"; 
	fprintf(fpTest, "\nStatus ---> PASS\n\n");
}

/*****************************************************************************/
/* Test class declaration                                                    */
/*****************************************************************************/
class TEST_CLASS_SWAP
{
public:
	void run_tests_swap();
	void test_CML_STL_swap(int);
	void test_CML_STL_swapfloat(int);
	//void test_CML_STL_swapdouble(int);

};

/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_stl_swap(void)
{
	TEST_CLASS_SWAP test_object;

	std::cout << "******** Start Testing: Swap Library functions ********\n\n";
	fprintf(fpTest, "******** Start Testing: Swap Library functions ********\n\n");

	test_object.run_tests_swap();

	std::cout << "End of Testing: Swap Library functions\n\n";
	fprintf(fpTest, "End of Testing: Swap Library functions\n\n");

	return ;
}

/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS_SWAP::run_tests_swap()
{
	test_CML_STL_swap(1);
	test_CML_STL_swapfloat(1);
	//test_CML_STL_swapdouble(1);
}

/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/
void TEST_CLASS_SWAP::test_CML_STL_swap(int doIt)
{
		if (doIt) 
		{
			{
				std::cout << "Test Case ---> test_CML_STL_swap_001\n\n";
				fprintf(fpTest, "Test Case ---> test_CML_STL_swap_001\n\n");

				/* Test case data declarations */
				uint8 Val=0x56;
				uint8 Expected_Result=0x56;
				uint8 Actual_Result;

				/* Input*/
				std::cout << "Input ---> \n";	
				fprintf(fpTest, "Input ---> \n");

				/* Expected Result*/
				std::cout << "Expected Result ---> \n";	
				fprintf(fpTest, "Expected Result ---> \n");

				#ifdef ENABLE_PROFILER
				start_clock = get_clock();
				#endif /* #ifdef ENABLE_PROFILER */

				/* Call SUT */
				Actual_Result = cml::CML_STL_swap(Val);

				#ifdef ENABLE_PROFILER
				stop_clock = get_clock();			
				#endif /* #ifdef ENABLE_PROFILER */

				/* Actual Result */
				std::cout << "Actual Result ---> \n";
				fprintf(fpTest, "Actual Result ---> \n");

				if(Actual_Result==Expected_Result)
				{
					check_global_data();
				}
				else
				{
					std::cout << "Status ---> FAIL\n\n";    
					fprintf(fpTest, "Status ---> FAIL\n\n");
				}

#ifdef ENABLE_PROFILER
			std::cout << "Clock Cycles ---> \n";		
			fprintf(fpTest, "Clock Cycles ---> \n");

			total_cycles = stop_clock - start_clock - overhead;

			check__PrintValue_to_console(total_cycles);
			check__PrintValue_to_File(total_cycles, fpTest);
			fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */
			}
			{
				std::cout << "Test Case ---> test_CML_STL_swap_002\n\n";
				fprintf(fpTest, "Test Case ---> test_CML_STL_swap_002\n\n");

				/* Test case data declarations */
				uint16 Val=0xABC;
				uint16 Expected_Result=0xBC0A;
				uint16 Actual_Result;

				/* Input*/
				std::cout << "Input ---> \n";	
				fprintf(fpTest, "Input ---> \n");

				/* Expected Result*/
				std::cout << "Expected Result ---> \n";	
				fprintf(fpTest, "Expected Result ---> \n");

				#ifdef ENABLE_PROFILER
				start_clock = get_clock();
				#endif /* #ifdef ENABLE_PROFILER */

				/* Call SUT */
				Actual_Result = cml::CML_STL_swap(Val);

				#ifdef ENABLE_PROFILER
				stop_clock = get_clock();			
				#endif /* #ifdef ENABLE_PROFILER */

				/* Actual Result */
				std::cout << "Actual Result ---> \n";
				fprintf(fpTest, "Actual Result ---> \n");

				if(Actual_Result==Expected_Result)
				{
					check_global_data();
				}
				else
				{
					std::cout << "Status ---> FAIL\n\n";    
					fprintf(fpTest, "Status ---> FAIL\n\n");
				}
#ifdef ENABLE_PROFILER
			std::cout << "Clock Cycles ---> \n";		
			fprintf(fpTest, "Clock Cycles ---> \n");

			total_cycles = stop_clock - start_clock - overhead;

			check__PrintValue_to_console(total_cycles);
			check__PrintValue_to_File(total_cycles, fpTest);
			fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */
			}

			{
				std::cout << "Test Case ---> test_CML_STL_swap_003\n\n";
				fprintf(fpTest, "Test Case ---> test_CML_STL_swap_003\n\n");

				/* Test case data declarations */
				uint32 Val=0xABCDEF87;
				uint32 Expected_Result=0x87EFCDAB;
				uint32 Actual_Result;

				/* Input*/
				std::cout << "Input ---> \n";	
				fprintf(fpTest, "Input ---> \n");

				/* Expected Result*/
				std::cout << "Expected Result ---> \n";	
				fprintf(fpTest, "Expected Result ---> \n");

				#ifdef ENABLE_PROFILER
				start_clock = get_clock();
				#endif /* #ifdef ENABLE_PROFILER */

				/* Call SUT */
				Actual_Result = cml::CML_STL_swap(Val);

				#ifdef ENABLE_PROFILER
				stop_clock = get_clock();			
				#endif /* #ifdef ENABLE_PROFILER */

				/* Actual Result */
				std::cout << "Actual Result ---> \n";
				fprintf(fpTest, "Actual Result ---> \n");

				if(Actual_Result==Expected_Result)
				{
					check_global_data();
				}
				else
				{
					std::cout << "Status ---> FAIL\n\n";    
					fprintf(fpTest, "Status ---> FAIL\n\n");
				}

#ifdef ENABLE_PROFILER
			std::cout << "Clock Cycles ---> \n";		
			fprintf(fpTest, "Clock Cycles ---> \n");

			total_cycles = stop_clock - start_clock - overhead;

			check__PrintValue_to_console(total_cycles);
			check__PrintValue_to_File(total_cycles, fpTest);
			fprintf(fpTest, "\n\n");
#endif /* #ifdef ENABLE_PROFILER */
		}
		{
				std::cout << "Test Case ---> test_CML_STL_swap_004\n\n";
				fprintf(fpTest, "Test Case ---> test_CML_STL_swap_004\n\n");

				/* Test case data declarations */
				uint64 Val=0xABCDEF00ABCDEF00;
				uint64 Expected_Result=0x00EFCDAB00EFCDAB;
				uint64 Actual_Result;

				/* Input*/
				std::cout << "Input ---> \n";	
				fprintf(fpTest, "Input ---> \n");

				/* Expected Result*/
				std::cout << "Expected Result ---> \n";	
				fprintf(fpTest, "Expected Result ---> \n");

				#ifdef ENABLE_PROFILER
				start_clock = get_clock();
				#endif /* #ifdef ENABLE_PROFILER */

				/* Call SUT */
				Actual_Result = cml::CML_STL_swap(Val);

				#ifdef ENABLE_PROFILER
				stop_clock = get_clock();			
				#endif /* #ifdef ENABLE_PROFILER */

				/* Actual Result */
				std::cout << "Actual Result ---> \n";
				fprintf(fpTest, "Actual Result ---> \n");

				if(Actual_Result==Expected_Result)
				{
					check_global_data();
				}
				else
				{
					std::cout << "Status ---> FAIL\n\n";    
					fprintf(fpTest, "Status ---> FAIL\n\n");
				}

				#ifdef ENABLE_PROFILER
							std::cout << "Clock Cycles ---> \n";		
							fprintf(fpTest, "Clock Cycles ---> \n");

							total_cycles = stop_clock - start_clock - overhead;

							check__PrintValue_to_console(total_cycles);
							check__PrintValue_to_File(total_cycles, fpTest);
							fprintf(fpTest, "\n\n");
				#endif /* #ifdef ENABLE_PROFILER */
		}
		{
				std::cout << "Test Case ---> test_CML_STL_swap_005\n\n";
				fprintf(fpTest, "Test Case ---> test_CML_STL_swap_005\n\n");

				/* Test case data declarations */
				sint8 Val=0x56;
				sint8 Expected_Result=0x56;
				sint8 Actual_Result;

				/* Input*/
				std::cout << "Input ---> \n";	
				fprintf(fpTest, "Input ---> \n");

				/* Expected Result*/
				std::cout << "Expected Result ---> \n";	
				fprintf(fpTest, "Expected Result ---> \n");

				#ifdef ENABLE_PROFILER
				start_clock = get_clock();
				#endif /* #ifdef ENABLE_PROFILER */

				/* Call SUT */
				Actual_Result = cml::CML_STL_swap(Val);

				#ifdef ENABLE_PROFILER
				stop_clock = get_clock();			
				#endif /* #ifdef ENABLE_PROFILER */

				/* Actual Result */
				std::cout << "Actual Result ---> \n";
				fprintf(fpTest, "Actual Result ---> \n");

				if(Actual_Result==Expected_Result)
				{
					check_global_data();
				}
				else
				{
					std::cout << "Status ---> FAIL\n\n";    
					fprintf(fpTest, "Status ---> FAIL\n\n");
				}
				#ifdef ENABLE_PROFILER
							std::cout << "Clock Cycles ---> \n";		
							fprintf(fpTest, "Clock Cycles ---> \n");

							total_cycles = stop_clock - start_clock - overhead;

							check__PrintValue_to_console(total_cycles);
							check__PrintValue_to_File(total_cycles, fpTest);
							fprintf(fpTest, "\n\n");
				#endif /* #ifdef ENABLE_PROFILER */
		}
			{
				std::cout << "Test Case ---> test_CML_STL_swap_006\n\n";
				fprintf(fpTest, "Test Case ---> test_CML_STL_swap_006\n\n");

				/* Test case data declarations */
				sint16 Val=0xABC;
				sint16 Expected_Result=0xBC0A;
				sint16 Actual_Result;

				/* Input*/
				std::cout << "Input ---> \n";	
				fprintf(fpTest, "Input ---> \n");

				/* Expected Result*/
				std::cout << "Expected Result ---> \n";	
				fprintf(fpTest, "Expected Result ---> \n");

				#ifdef ENABLE_PROFILER
				start_clock = get_clock();
				#endif /* #ifdef ENABLE_PROFILER */

				/* Call SUT */
				Actual_Result = cml::CML_STL_swap(Val);

				#ifdef ENABLE_PROFILER
				stop_clock = get_clock();			
				#endif /* #ifdef ENABLE_PROFILER */

				/* Actual Result */
				std::cout << "Actual Result ---> \n";
				fprintf(fpTest, "Actual Result ---> \n");

				if(Actual_Result==Expected_Result)
				{
					check_global_data();
				}
				else
				{
					std::cout << "Status ---> FAIL\n\n";    
					fprintf(fpTest, "Status ---> FAIL\n\n");
				}
				#ifdef ENABLE_PROFILER
							std::cout << "Clock Cycles ---> \n";		
							fprintf(fpTest, "Clock Cycles ---> \n");

							total_cycles = stop_clock - start_clock - overhead;

							check__PrintValue_to_console(total_cycles);
							check__PrintValue_to_File(total_cycles, fpTest);
							fprintf(fpTest, "\n\n");
				#endif /* #ifdef ENABLE_PROFILER */
			}

			{
				std::cout << "Test Case ---> test_CML_STL_swap_007\n\n";
				fprintf(fpTest, "Test Case ---> test_CML_STL_swap_007\n\n");

				/* Test case data declarations */
				sint32 Val=0xABCDEF;
				sint32 Expected_Result=0xEFCDAB00;
				sint32 Actual_Result;

				/* Input*/
				std::cout << "Input ---> \n";	
				fprintf(fpTest, "Input ---> \n");

				/* Expected Result*/
				std::cout << "Expected Result ---> \n";	
				fprintf(fpTest, "Expected Result ---> \n");

				#ifdef ENABLE_PROFILER
				start_clock = get_clock();
				#endif /* #ifdef ENABLE_PROFILER */

				/* Call SUT */
				Actual_Result = cml::CML_STL_swap(Val);

				#ifdef ENABLE_PROFILER
				stop_clock = get_clock();			
				#endif /* #ifdef ENABLE_PROFILER */

				/* Actual Result */
				std::cout << "Actual Result ---> \n";
				fprintf(fpTest, "Actual Result ---> \n");

				if(Actual_Result==Expected_Result)
				{
					check_global_data();
				}
				else
				{
					std::cout << "Status ---> FAIL\n\n";    
					fprintf(fpTest, "Status ---> FAIL\n\n");
				}
				#ifdef ENABLE_PROFILER
							std::cout << "Clock Cycles ---> \n";		
							fprintf(fpTest, "Clock Cycles ---> \n");

							total_cycles = stop_clock - start_clock - overhead;

							check__PrintValue_to_console(total_cycles);
							check__PrintValue_to_File(total_cycles, fpTest);
							fprintf(fpTest, "\n\n");
				#endif /* #ifdef ENABLE_PROFILER */
		}
		{
				std::cout << "Test Case ---> test_CML_STL_swap_008\n\n";
				fprintf(fpTest, "Test Case ---> test_CML_STL_swap_008\n\n");

				/* Test case data declarations */
				sint64 Val=0xABCDEF00ABCDEF00;
				sint64 Expected_Result=0x00EFCDAB00EFCDAB;
				sint64 Actual_Result;

				/* Input*/
				std::cout << "Input ---> \n";	
				fprintf(fpTest, "Input ---> \n");

				/* Expected Result*/
				std::cout << "Expected Result ---> \n";	
				fprintf(fpTest, "Expected Result ---> \n");

				#ifdef ENABLE_PROFILER
				start_clock = get_clock();
				#endif /* #ifdef ENABLE_PROFILER */

				/* Call SUT */
				Actual_Result = cml::CML_STL_swap(Val);

				#ifdef ENABLE_PROFILER
				stop_clock = get_clock();			
				#endif /* #ifdef ENABLE_PROFILER */

				/* Actual Result */
				std::cout << "Actual Result ---> \n";
				fprintf(fpTest, "Actual Result ---> \n");

				if(Actual_Result==Expected_Result)
				{
					check_global_data();
				}
				else
				{
					std::cout << "Status ---> FAIL\n\n";    
					fprintf(fpTest, "Status ---> FAIL\n\n");
				}
				#ifdef ENABLE_PROFILER
							std::cout << "Clock Cycles ---> \n";		
							fprintf(fpTest, "Clock Cycles ---> \n");

							total_cycles = stop_clock - start_clock - overhead;

							check__PrintValue_to_console(total_cycles);
							check__PrintValue_to_File(total_cycles, fpTest);
							fprintf(fpTest, "\n\n");
				#endif /* #ifdef ENABLE_PROFILER */
		}
	}
}

void TEST_CLASS_SWAP::test_CML_STL_swapfloat(int doIt)
{
	if (doIt) 
	{
		{
				std::cout << "Test Case ---> test_CML_STL_swapfloat_001\n\n";
				fprintf(fpTest, "Test Case ---> test_CML_STL_swapfloat_001\n\n");

				/* Test case data declarations  to enter NAN check functions*/
				uint32 uval = 0x0000807F;
				float32 Val=*reinterpret_cast<float32*>(&uval);
				float32 Expected_Result= std::numeric_limits<float32>::quiet_NaN ();
				float32 Actual_Result ;

				/* Input*/
				std::cout << "Input ---> \n";	
				fprintf(fpTest, "Input ---> \n");

				/* Expected Result*/
				std::cout << "Expected Result ---> \n";	
				fprintf(fpTest, "Expected Result ---> \n");

				#ifdef ENABLE_PROFILER
				start_clock = get_clock();
				#endif /* #ifdef ENABLE_PROFILER */

				/* Call SUT */
				Actual_Result = cml::CML_STL_swapfloat(&Val);

				#ifdef ENABLE_PROFILER
				stop_clock = get_clock();			
				#endif /* #ifdef ENABLE_PROFILER */

				/* Actual Result */
				std::cout << "Actual Result ---> \n";
				fprintf(fpTest, "Actual Result ---> \n");

				if(Actual_Result!=Expected_Result)
				{
					check_global_data();
				}
				else
				{
					std::cout << "Status ---> FAIL\n\n";    
					fprintf(fpTest, "Status ---> FAIL\n\n");
				}
				#ifdef ENABLE_PROFILER
					std::cout << "Clock Cycles ---> \n";		
					fprintf(fpTest, "Clock Cycles ---> \n");

					total_cycles = stop_clock - start_clock - overhead;

					check__PrintValue_to_console(total_cycles);
					check__PrintValue_to_File(total_cycles, fpTest);
					fprintf(fpTest, "\n\n");
				#endif /* #ifdef ENABLE_PROFILER */
		}

		{
				std::cout << "Test Case ---> test_CML_STL_swapfloat_002\n\n";
				fprintf(fpTest, "Test Case ---> test_CML_STL_swapfloat_002\n\n");

				/* Test case data declarations */
				//uint32 uval = 0x0000807F;
				float32 Val=-3.4e38f;
				float32 Expected_Result=-2.1334641e-020;
				float32 Actual_Result;

				/* Input*/
				std::cout << "Input ---> \n";	
				fprintf(fpTest, "Input ---> \n");

				/* Expected Result*/
				std::cout << "Expected Result ---> \n";	
				fprintf(fpTest, "Expected Result ---> \n");

				#ifdef ENABLE_PROFILER
				start_clock = get_clock();
				#endif /* #ifdef ENABLE_PROFILER */

				/* Call SUT */
				Actual_Result = cml::CML_STL_swapfloat(&Val);

				#ifdef ENABLE_PROFILER
				stop_clock = get_clock();			
				#endif /* #ifdef ENABLE_PROFILER */

				/* Actual Result */
				std::cout << "Actual Result ---> \n";
				fprintf(fpTest, "Actual Result ---> \n");

				if(Actual_Result==Expected_Result)
				{
					check_global_data();
				}
				else
				{
					std::cout << "Status ---> FAIL\n\n";    
					fprintf(fpTest, "Status ---> FAIL\n\n");
				}
				#ifdef ENABLE_PROFILER
							std::cout << "Clock Cycles ---> \n";		
							fprintf(fpTest, "Clock Cycles ---> \n");

							total_cycles = stop_clock - start_clock - overhead;

							check__PrintValue_to_console(total_cycles);
							check__PrintValue_to_File(total_cycles, fpTest);
							fprintf(fpTest, "\n\n");
				#endif /* #ifdef ENABLE_PROFILER */
		}

		{
				std::cout << "Test Case ---> test_CML_STL_swapfloat_003\n\n";
				fprintf(fpTest, "Test Case ---> test_CML_STL_swapfloat_003\n\n");

				/* Test case data declarations */
				//uint32 uval = 0x0000807F;
				float32 Val=+3.4e38f;
				float32 Expected_Result=-2.1334434e-020;
				float32 Actual_Result;

				/* Input*/
				std::cout << "Input ---> \n";	
				fprintf(fpTest, "Input ---> \n");

				/* Expected Result*/
				std::cout << "Expected Result ---> \n";	
				fprintf(fpTest, "Expected Result ---> \n");

				#ifdef ENABLE_PROFILER
				start_clock = get_clock();
				#endif /* #ifdef ENABLE_PROFILER */

				/* Call SUT */
				Actual_Result = cml::CML_STL_swapfloat(&Val);

				#ifdef ENABLE_PROFILER
				stop_clock = get_clock();			
				#endif /* #ifdef ENABLE_PROFILER */

				/* Actual Result */
				std::cout << "Actual Result ---> \n";
				fprintf(fpTest, "Actual Result ---> \n");

				if(Actual_Result==Expected_Result)
				{
					check_global_data();
				}
				else
				{
					std::cout << "Status ---> FAIL\n\n";    
					fprintf(fpTest, "Status ---> FAIL\n\n");
				}
				#ifdef ENABLE_PROFILER
							std::cout << "Clock Cycles ---> \n";		
							fprintf(fpTest, "Clock Cycles ---> \n");

							total_cycles = stop_clock - start_clock - overhead;

							check__PrintValue_to_console(total_cycles);
							check__PrintValue_to_File(total_cycles, fpTest);
							fprintf(fpTest, "\n\n");
				#endif /* #ifdef ENABLE_PROFILER */
		}
		
		{
				std::cout << "Test Case ---> test_CML_STL_swapfloat_004\n\n";
				fprintf(fpTest, "Test Case ---> test_CML_STL_swapfloat_004\n\n");

				/* Test case data declarations */
				//uint32 uval = 0x0000807F;
				float32 Val=0.0f;
				float32 Expected_Result=0.0f;
				float32 Actual_Result;

				/* Input*/
				std::cout << "Input ---> \n";	
				fprintf(fpTest, "Input ---> \n");

				/* Expected Result*/
				std::cout << "Expected Result ---> \n";	
				fprintf(fpTest, "Expected Result ---> \n");

				#ifdef ENABLE_PROFILER
				start_clock = get_clock();
				#endif /* #ifdef ENABLE_PROFILER */

				/* Call SUT */
				Actual_Result = cml::CML_STL_swapfloat(&Val);

				#ifdef ENABLE_PROFILER
				stop_clock = get_clock();			
				#endif /* #ifdef ENABLE_PROFILER */

				/* Actual Result */
				std::cout << "Actual Result ---> \n";
				fprintf(fpTest, "Actual Result ---> \n");

				if(Actual_Result==Expected_Result)
				{
					check_global_data();
				}
				else
				{
					std::cout << "Status ---> FAIL\n\n";    
					fprintf(fpTest, "Status ---> FAIL\n\n");
				}
				#ifdef ENABLE_PROFILER
							std::cout << "Clock Cycles ---> \n";		
							fprintf(fpTest, "Clock Cycles ---> \n");

							total_cycles = stop_clock - start_clock - overhead;

							check__PrintValue_to_console(total_cycles);
							check__PrintValue_to_File(total_cycles, fpTest);
							fprintf(fpTest, "\n\n");
				#endif /* #ifdef ENABLE_PROFILER */
		}

	}
}
/* function CML_STL_swapdouble(0 is not included in the file cml_stl_misc.h file.
  so test case not required.*/
#if 0
void TEST_CLASS_SWAP::test_CML_STL_swapdouble(int doIt)
{
	if (doIt) 
	{
		{
				std::cout << "Test Case ---> test_CML_STL_swapdouble_001\n\n";
				fprintf(fpTest, "Test Case ---> test_CML_STL_swapdouble_001\n\n");

				/* Test case data declarations */
				float64 Val=12345.678;
				float64 Expected_Result=0.0f;
				float64 Actual_Result;

				/* Input*/
				std::cout << "Input ---> \n";	
				fprintf(fpTest, "Input ---> \n");

				/* Expected Result*/
				std::cout << "Expected Result ---> \n";	
				fprintf(fpTest, "Expected Result ---> \n");

				#ifdef ENABLE_PROFILER
				start_clock = get_clock();
				#endif /* #ifdef ENABLE_PROFILER */

				/* Call SUT */
				Actual_Result = cml::CML_STL_swapdouble(&Val);

				#ifdef ENABLE_PROFILER
				stop_clock = get_clock();			
				#endif /* #ifdef ENABLE_PROFILER */

				/* Actual Result */
				std::cout << "Actual Result ---> \n";
				fprintf(fpTest, "Actual Result ---> \n");

				if(Actual_Result==Expected_Result)
				{
					check_global_data();
				}
				else
				{
					std::cout << "Status ---> FAIL\n\n";    
					fprintf(fpTest, "Status ---> FAIL\n\n");
				}
		}
	}
}
#endif


#endif
/*****************************************************************************/
/* Call Interface Control                                                    */
/*****************************************************************************/
/* pragma qas cantata testscript end */
/*****************************************************************************/
/* End of test script                                                        */
/*****************************************************************************/
