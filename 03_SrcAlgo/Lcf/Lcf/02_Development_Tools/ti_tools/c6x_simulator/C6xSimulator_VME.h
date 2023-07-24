/*  **********************************************************************

  COMPANY:                    Continental Automotive

  PROJECT:                    MFC400

  CPU:                        DSP Stereo

  PACKAGE:                    SIB

  MODULNAME:                  C6xSimulator_VME.h

  DESCRIPTION:                Defines neccessary for emulation of the C6740 Intrinsics on the Host PC

  CREATION DATE:              10.07.2013

**************************************************************************** */

#ifndef C6XSIMULATOR_VME_H
#define C6XSIMULATOR_VME_H


// disabled #if (!defined(_TMS320C6X)) && !defined(GUYS_BUILD_MESSAGE_COMPRESSOR)
// disabled    #pragma message ("- Including [" __TIMESTAMP__ "] " __FILE__ )
// disabled #endif // #ifndef _TMS320C6X


#define TMS320C6740
#define SIMULATION
#define LITTLE_ENDIAN_HOST

#endif // C6XSIMULATOR_VME_H

