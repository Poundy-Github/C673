 /*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

  PROJECT:                

  COMPONENT:              

  MODULNAME:              polyspace_stubs_tic6000.c

  DESCRIPTION:            Polyspace Code Prover specific stub functions
                          of TI C6000 intrinsics

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2016-01-28

  VERSION:                $Revision: 1.1 $

*/

/*---------------------------------------------------*/
/*  INCLUDES                                         */
/*---------------------------------------------------*/
#include "polyspace_helper.h"
#include "c6x.h"

/*---------------------------------------------------*/
/*  MACROS                                           */
/*---------------------------------------------------*/



/*---------------------------------------------------*/
/*  TYPEDEFS                                         */
/*---------------------------------------------------*/


/*---------------------------------------------------*/
/*  GLOBAL VARIABLES                                 */
/*---------------------------------------------------*/

/*---------------------------------------------------*/
/*  LOCAL FUNCTION DECLARATIONS                      */
/*---------------------------------------------------*/


/*---------------------------------------------------*/
/*  GLOBAL FUNCTION DEFINITIONS                      */
/*---------------------------------------------------*/
long long _itoll(unsigned int a, unsigned int b)
{
  /* Limit to zero as only used for time measurements */
  long long retVal = 0;

  return retVal;
}


/*---------------------------------------------------*/
/*  LOCAL FUNCTION DEFINITIONS                       */
/*---------------------------------------------------*/

