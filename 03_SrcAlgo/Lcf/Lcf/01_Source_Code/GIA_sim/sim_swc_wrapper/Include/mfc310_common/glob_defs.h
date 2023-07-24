/*! \file **********************************************************************

  COMPANY:                Continental Automotive

  MODULENAME:             glob_defs.h

  DESCRIPTION:            This file contains all global definitions, 
                          needed in more then one component

  VERSION:                $Revision: 1.1 $

                  
  ---*/ /*---
    CHANGES:              $Log: glob_defs.h  $
    CHANGES:              Revision 1.1 2021/12/13 17:24:43CET Wang, David (Wangd3) 
    CHANGES:              Initial revision
    CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310_common/project.pj
    CHANGES:              Revision 1.0 2017/03/03 10:35:39CET Sorge, Sven (uidg3181) 
    CHANGES:              Initial revision
    CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310_common/project.pj
    CHANGES:              Revision 1.1 2014/03/13 15:11:14CET Sorge, Sven (uidg3181) 
    CHANGES:              Initial revision
    CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310_common/project.pj
    CHANGES:              Revision 1.2 2011/08/02 13:37:26CEST Achatz-EXT, Florian (uidt9222) 
    CHANGES:              + Boolean16 type added
    CHANGES:              --- Added comments ---  uidt9222 [Aug 2, 2011 1:37:26 PM CEST]
    CHANGES:              Change Package : 71982:1 http://mks-psad:7002/im/viewissue?selection=71982
    CHANGES:              Revision 1.1 2010/09/30 18:58:10CEST Fuehrmann Johann (x-fuehrmannj) (x-fuehrmannj) 
    CHANGES:              Initial revision
    CHANGES:              Member added to project /nfs/projekte1/PROJECTS/MFC300/05_Software/MCU/04_Engineering/01_Source_Code/SW/project.pj
    CHANGES:              Revision 1.4 2010/04/30 13:22:40CEST jfuehrman 
    CHANGES:              moved some defines to glob_defs.h
    CHANGES:              cleanup for MFC300
    CHANGES:              --- Added comments ---  jfuehrman [2010/04/30 11:22:40Z]
    CHANGES:              Change Package : 36194:1 http://LISS014:6001/im/viewissue?selection=36194
    CHANGES:              Revision 1.3 2010/04/27 14:11:12CEST Lars Perske (lperske) 
    CHANGES:              Exchanged old data types (bool_t, ui8_t) by new types
    CHANGES:              --- Added comments ---  lperske [2010/04/27 12:11:13Z]
    CHANGES:              Change Package : 38903:1 http://LISS014:6001/im/viewissue?selection=38903



*****************************************************************************/
#ifndef GLOB_DEFS_H
#define GLOB_DEFS_H


/* includes */

/** @defgroup glob_defs Global Makros and Definitions
        Here you will find global makros and definitions like TRUE, FALSE, MIN, MAX
  @{
 */


#ifdef WIN32
/* stub for target compilers __attribute__  ((aligned(x))) */
#define __attribute__(x) 
#endif


/* //////////////////////////////////// Pseudo Types /////////////////////////////  */




#ifndef b_FALSE
/*! boolean type where FALSE = (boolean)0 */
#define b_FALSE (boolean)0
#endif

#ifndef b_TRUE
/*! boolean type where TRUE = (boolean)1 */
#define b_TRUE (boolean)1
#endif

/*! NULL for pointer initialisation */
#ifndef NULL
#define NULL      ((void *)0)
#endif


/*! Bit conditions */
#define C_BIT_SET         1
#define C_BIT_RESET       0

/*! Pin conditions */
#define C_PIN_SET         1
#define C_PIN_RESET       0

/*! Flag conditions */
#define FLAG_SET        1
#define FLAG_RESET      0

/*! Switch conditions */
#define SWITCH_ON       1
#define SWITCH_OFF      0


/* //////////////////////////////////// Constant Values /////////////////////////// */
/*! Constant PI */
#define C_PI  (3.14159265359F)

/*! Constant gravity G */
#define C_GRAVITY  (9.80665F)

/*! Delta threshold value for 32 bit floating point equality tests  @see EQ_ZERO */
#define C_F32_DELTA  (0.0001F)

/*! Constant conversion km/h <-> m/s */
#define C_KMH_MS      (3.6F)

/*! Constant speed of light in vacuum c [m/s] */
#define C_V_LIGTH    (299792458.0F)

/* //////////////////////////////////// Macros ////////////////////////////////////  */


/*! Absolute value */
#define ABS(x)        (((x)<(0))?(-(x)):(x))

/*! Absolute value for type long */
#define iABS(x)        (((x)<(0L))?(-(x)):(x))

/*! Absolute value for floating point*/
#define fABS(x)        (((x)<(0.f))?(-(x)):(x))

/*! Comparision of floating point value to equal zero */
#define F32_IS_ZERO(value) (ABS(value) < C_F32_DELTA)

/*! Comparision of floating point value <= zero */
#define F32_IS_EQUAL_OR_LESS_ZERO(value) (value < C_F32_DELTA)

/*! Test whether the floating point value is approx. not zero (TRUE) or zero (FALSE)*/
#define F32_IS_NZERO(value) (ABS(value) >= C_F32_DELTA)

/*! Odd / even macros with bit operation (faster than using n%2) */
#define IS_ODD(n) ((n & 0x01) == 0x01)
#define IS_EVEN(n) ((n & 0x01) == 0x00)

/*! Get the corresponding Bit on the basis of the BITMASK */
#define GET_BIT(source, bitmask)   ( ((source) & (bitmask)) == (bitmask) )

/*! Set the corresponding Bit on the basis of the BITMASK */
#define SET_BIT(source, bitmask)   ((source) |=  (bitmask))

/*! Reset the corresponding Bit on the basis of the BITMASK */
#define CLEAR_BIT(source, bitmask) ((source) &= ~( bitmask) )

/*! Determines the number of elements of a one-dimensional field */
#define SIZEOF1(x)    (sizeof(x) / sizeof(x[0]))

/*! Determines the number of elements of a two-dimensional field */
#define SIZEOF2(x)    (sizeof(x) / sizeof(x[0][0]))

/*! Determines the number of elements in an array */
#define elementsof(_a) (sizeof ((_a)) / sizeof ((_a)[0]))

/*! Determines the smaller of two values   */
#define MIN(x,y)      (((x)<(y))?(x):(y))

/*! Determines  the larger  of two values */
#define MAX(x,y)      (((x)>(y))?(x):(y))

/*! Limit the number to a minimum and a maximum value
          Parameterfolge: Minwert , Maxwert , Zahl */
#define MINMAX(min,max,value) (MAX((MIN((value),(max))),(min)))


/*! Calculating the square (x*x) of a number */
#define SQR(x)        ((x)*(x))

/*! Determine the sign of a number 
0: Value equal 0 ||  1: Positiv Value || -1: Negativ Value */
#define SIGN(x)       (((x)==(0))?(0):(((x)>(0))?(1):(-1)))

#define fSIGN(x)      ((F32_IS_ZERO(x))?(0):((x > 0.F)?(1):(-1)))

/*! Rounds of positive and negative numbers with 0.5*/
#define ROUND(x)      (((x)>=0.F)?((x)+0.5F):((x)-0.5F))

/* rounding */
#define FROUND(x)     (((x) >= 0.0f) ? ((x) + 0.5f) : ((x) - 0.5f))

#define ROUND_TO_MULTIPLE_OF_N(ELCNT, _N)   ( ( ( (ELCNT) + (_N) - 1 ) / (_N)) * (_N) )
#define ROUND_TO_MULTIPLE_OF_8(ELCNT)       ROUND_TO_MULTIPLE_OF_N(ELCNT, 8)
#define ROUND_TO_MULTIPLE_OF_16(ELCNT)      ROUND_TO_MULTIPLE_OF_N(ELCNT, 16)
#define ROUND_TO_MULTIPLE_OF_32(ELCNT)      ROUND_TO_MULTIPLE_OF_N(ELCNT, 32)
#define ROUND_TO_MULTIPLE_OF_64(ELCNT)      ROUND_TO_MULTIPLE_OF_N(ELCNT, 64)
#define ROUND_TO_MULTIPLE_OF_128(ELCNT)     ROUND_TO_MULTIPLE_OF_N(ELCNT, 128)

/* the below macro rounds a table so that it will contain at least
   the specified number of elements with the given element size.
   more members will get added at the table end as long as the next
   alignment boundary wont get crossed, so maximum cache mem efficiency takes place.
   the return value is the count of elements after the growth.
   usage sample:
     t_table MyTable [ROUND_TABLE_TO_MULTIPLE_OF_128(MY_REQUIERD_ELEMENT_COUNT, sizeof (t_table))];
*/
#define ROUND_TABLE_TO_MULTIPLE_OF_128(ELCNT,ELSIZE)\
( ( ROUND_TO_MULTIPLE_OF_128((ELCNT) * (ELSIZE)) + (ELSIZE) - 1 ) \
  / (ELSIZE) \
)

/* processor specific rounding */
#if   defined(WIN32)
  /* indifferent since only a DLL platform, this is anyways rather CPU dependent */
  #define ROUND_TO_MULTIPLE_OF_CACHELINE(ELCNT)               ROUND_TO_MULTIPLE_OF_128(ELCNT)
  #define ROUND_TABLE_TO_MULTIPLE_OF_CACHELINE(ELCNT,ELSIZE)  ROUND_TABLE_TO_MULTIPLE_OF_128(ELCNT,ELSIZE)
#elif defined(TARGET_DSP)
  /* C6446 has a cache line size of 128 */
  #define ROUND_TO_MULTIPLE_OF_CACHELINE(ELCNT)               ROUND_TO_MULTIPLE_OF_128(ELCNT)
  #define ROUND_TABLE_TO_MULTIPLE_OF_CACHELINE(ELCNT,ELSIZE)  ROUND_TABLE_TO_MULTIPLE_OF_128(ELCNT,ELSIZE)
#elif defined(__M32R__)
  #define ROUND_TO_MULTIPLE_OF_CACHELINE(ELCNT)               error - cache line size of M32R got not yet determined!
  #define ROUND_TABLE_TO_MULTIPLE_OF_CACHELINE(ELCNT,ELSIZE)  error - cache line size of M32R got not yet determined!
#else
  #define ROUND_TO_MULTIPLE_OF_CACHELINE(ELCNT)               error - unknown platform!
  #define ROUND_TABLE_TO_MULTIPLE_OF_CACHELINE(ELCNT,ELSIZE)  error - unknown platform!
#endif

/* compiler specific rounding */
#if   defined(WIN32)
  #define ROUND_TO_MULTIPLE_OF_CALIGN(ELCNT)  ROUND_TO_MULTIPLE_OF_32(ELCNT) /* MSVC 6.0 SP5 */
#elif defined(TARGET_DSP)
  #define ROUND_TO_MULTIPLE_OF_CALIGN(ELCNT)  ROUND_TO_MULTIPLE_OF_8(ELCNT) /* CCS 3.3 beta 2 */
#elif defined(__M32R__)
  #define ROUND_TO_MULTIPLE_OF_CALIGN(ELCNT)  ROUND_TO_MULTIPLE_OF_8(ELCNT) /* todo - c alignment value of M32R got not yet determined! */
#else
  #define ROUND_TO_MULTIPLE_OF_CALIGN(ELCNT)  error - unknown platform!
#endif


/*! Simple low-pass filter of values, all formats. */
#define LP_FILTER(New, Old, FilterT, SampleT) \
          (((FilterT) / (SampleT) * (Old) + (New)) / (1 + (FilterT) / (SampleT)))


/*! Internally used macro, never use outside of this file. */
#define STRING_INTERNAL_QUOTE(x)  #x

/*! Macro to convert a token/define to string. Useful for names etc. Note how
the internally used macro is needed by this function. Otherwise define
replacement wouldn't take place */
#define STRING_QUOTE(x) STRING_INTERNAL_QUOTE(x)

/*! Conversion of angle from degree to radian unit */
#define DEG2RAD(deg_)  ((deg_)*(C_PI/180.F))

/*! Conversion of angle from radian to degree unit */
#define RAD2DEG(rad_)  ((rad_)*(180.F/C_PI))

/*! Utility macro to get the lower byte from an unsigned 16 bit value */
#define GET_UI16_LOWBYTE(x)       (uint8)((x) & 0xFF)

/*! Utility macro to get the high byte from an unsigned 16 bit value */
#define GET_UI16_HIGHBYTE(x)      (uint8)(((x) >> 8) & 0xFF)

/*! Utility macro to get the lowest byte from an unsigned 32 bit value */
#define GET_UI32_LOWBYTE(x)       (uint8)((x) & 0xFF)

/*! Utility macro to get the 2nd lowest byte from an unsigned 32 bit value */
#define GET_UI32_LMIDBYTE(x)      (uint8)(((x) >> 8) & 0xFF)

/*! Utility macro to get the 2nd highest byte from an unsigned 32 bit value */
#define GET_UI32_HMIDBYTE(x)      (uint8)(((x) >> 16) & 0xFF)

/*! Utility macro to get the highest byte from an unsigned 32 bit value */
#define GET_UI32_HIGHBYTE(x)      (uint8)(((x) >> 24) & 0xFF)

/* TRUE an FALSE with secure 16-bit-pattern */
typedef enum
{
  TRUE16  = 0xA5A5,
  FALSE16 = 0x5A5A
}boolean16;

#endif

/** @} */ 
