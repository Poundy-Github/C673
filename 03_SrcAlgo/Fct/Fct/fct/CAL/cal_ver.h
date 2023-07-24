/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 CAL (Common ACC Library)

PACKAGENAME:               cal_ver.h

DESCRIPTION:               Version File for Common ACC Library module

AUTHOR:                    Shang, Hanyu

CREATION DATE:             27.02.2017

VERSION:                   $Revision: 1.24.1.1 $

LEGACY VERSION:            Revision: 2.0


**************************************************************************** */
#ifndef CAL_VER_H_INCLUDED
#define CAL_VER_H_INCLUDED

/*****************************************************************************
  CAL version number
*****************************************************************************/
/*!
@defgroup frame_ver VERSION
@ingroup frame


@brief              Contains the CAL version number of the current software.
@description        The Component version number is stored as 3 bytes: GEN.CTT.INT
                    SW_CAL_XX.YY.Z1Z2 with XX = GEN, YY = CTT, Z1Z2 = INT
                    XX is incremented for major functionality increases => GEN
                    YY is incremented for regular (biweekly) component releases => CTT
                    Z1 is incremented for manual component releases created in between => INT
                    Z2 is incremented for checkpoints on integration branches => INT
                    
                    GEN: Generation version number.
                         - This number describes the generation of the component
                         - The number starts with 01 for a new component
                         - The number is increased after major changes of the 
                           component architecture
                    CTT: Content version number.
                         - This number describes the functional content (component behaviour).
                         - The number is increased at every biweekly component release
                           the functional content of the component has changed
                    INT: Integration level number.
                         - The number describes the number of integration of the same functional 
                           content but with different bugfixes
                         - The number starts with 00
                         - The number is increased everytime a bugfix release of the component
                           is integrated
                         - The number is set back to 00 everytime CTT is incremented
@{
*/

/************************************************************************/
/*                    SYMBOLIC CONSTANTS                                */
/************************************************************************/
/*!   Generation version number.*/
#define CAL_GEN_VER_NO                      0x01
/*!   Content version number*/
#define CAL_CONTENT_VER_NO                  0x12
/*!   Integration level number*/
#define CAL_INT_LEV_NO                      0x01

/*! CAL version number: */
#define CAL_SW_VERSION_NUMBER    ((CAL_GEN_VER_NO<<16) | (CAL_CONTENT_VER_NO<<8) | (CAL_INT_LEV_NO))
/** @} end defgroup */
#endif /* CAL_VER_H_INCLUDED */
