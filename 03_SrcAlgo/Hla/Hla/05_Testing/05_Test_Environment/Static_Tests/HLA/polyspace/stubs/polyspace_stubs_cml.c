 /*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

  PROJECT:                

  COMPONENT:              

  MODULNAME:              polyspace_stubs_cml.c

  DESCRIPTION:            Polyspace Code Prover specific stub functions
                          of CML functions.

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2016-01-28

  VERSION:                $Revision: 1.2 $

*/

/*---------------------------------------------------*/
/*  INCLUDES                                         */
/*---------------------------------------------------*/
#include "polyspace_helper.h"
#include "cml_ext.h"

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

float32 GDBatan_66(float32 x)
{
  float32 retVal = full_range_float32;

  /* Limit output to reasonable values */
  POLYSPACE_ASSERT(IS_RANGE_II(retVal, -C_HALFPI, C_HALFPI)) 

  return retVal;
}

float32 CML_sin66(float32 x)
{
  float32 retVal = full_range_float32;

  /* Limit output to reasonable values */
  POLYSPACE_ASSERT(IS_RANGE_II(retVal, -1, 1)) 

  return retVal;
}

float32 CML_cos66(float32 x)
{
  float32 retVal = full_range_float32;

  /* Limit output to reasonable values */
  POLYSPACE_ASSERT(IS_RANGE_II(retVal, -1, 1)) 

  return retVal;
}



/*---------------------------------------------------*/
/*  LOCAL FUNCTION DEFINITIONS                       */
/*---------------------------------------------------*/

