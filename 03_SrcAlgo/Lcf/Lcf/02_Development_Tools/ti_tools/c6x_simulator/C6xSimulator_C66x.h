/*  **********************************************************************

  COMPANY:                    Continental Automotive

  PROJECT:                    MFC400

  CPU:                        DSP 

  PACKAGE:                    SIB

  MODULNAME:                  C6xSimulator_C66x.h

  DESCRIPTION:                Defines neccessary for emulation of the C6740 Intrinsics on the Host PC

  CREATION DATE:              06.07.2016

**************************************************************************** */

#ifndef C6XSIMULATOR_C66x_H
#define C6XSIMULATOR_C66x_H


// disabled #if (!defined(_TMS320C6X)) && !defined(GUYS_BUILD_MESSAGE_COMPRESSOR)
// disabled    #pragma message ("- Including [" __TIMESTAMP__ "] " __FILE__ )
// disabled #endif // #ifndef _TMS320C6X

#define TMS320C66X

#define SIMULATION
#define LITTLE_ENDIAN_HOST

#endif // C6XSIMULATOR_VME_H

