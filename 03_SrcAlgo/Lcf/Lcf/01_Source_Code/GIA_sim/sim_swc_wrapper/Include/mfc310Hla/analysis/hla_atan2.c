/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  CPU:

  COMPONENT:              HLA

  MODULNAME:              hla_atan2.c

  DESCRIPTION:            Own implementation of approximated atan2 function. It should be much faster then the exact one.
                          This custom Atan2 uses vectorized cordic approximation of atan function. The implementation 
                          expects that the compiler supports right arithmetic bit shift

  AUTHOR:                 Roman Glebov

  CREATION DATE:          2014-02-19

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGE:                 $Log: hla_atan2.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:45CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:01CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:18CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.6 2014/03/25 18:32:12CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_atan2.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_atan2.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/analysis/project.pj.
  CHANGE:                 Revision 1.5 2014/03/19 16:31:29CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:29 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.4 2014/03/11 15:43:43CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Took cfg_project.h into use
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2014 3:43:43 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.3 2014/03/05 14:36:39CET Glebov, Roman (uidg4759) 
  CHANGE:                 speed tweak
  CHANGE:                 --- Added comments ---  uidg4759 [Mar 5, 2014 2:36:40 PM CET]
  CHANGE:                 Change Package : 217406:2 http://mks-psad:7002/im/viewissue?selection=217406
  CHANGE:                 Revision 1.2 2014/03/04 15:52:28CET Glebov, Roman (uidg4759) 
  CHANGE:                 using now sint32 in place of float32 for angle.
  CHANGE:                 
  CHANGE:                 changed directAngleFunction input arguments from float32 to sint16
  CHANGE:                 Revision 1.1 2014/03/04 10:04:19CET Glebov, Roman (uidg4759) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj

*/

/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include "hla_atan2.h"

/* size of the LUT, also controls the amount of for loops, the more for loops the greater is the precision.
12 Loops mean angle deviation of approx 0.3 Grad compared to the exact atan2 function. If you adjust this number do not 
forget to update the ATAN_2_I_LUT appropriately */

/* lut size of 5 means precision of +-2 Grad */
#define LUT_SIZE 5

/* this factors are used during float to fixed and fixed to float conversions */
#define SCALE_SHIFT 14

#define SCALE_FACTOR 16384


/* this is (uint32) PI * SCALE_FACTOR; pi-number in current fixpoint arithmetic representation */
#define FIXED_PI 51471

/* (uint32) 180 / pi, is used to convert radians to degrees */
#define FIXED_RAD2DEGFACTOR 57



static inline sint32 hla_cordic_atan (sint32 y, sint32 x);

/* fix point implementation of atan function */
static inline sint32 hla_cordic_atan (sint32 y, sint32 x)
{
  /* look up table with the values of atan(2^(-i)) in fixed point form */
static const sint32 ATAN_2_I_LUT[LUT_SIZE] =
{
  12868,
  7596,
  4014,
  2037,
  1023
  /*, factors which need to be added with additional number of iterations
  512,
  256,
  128*/
};

  sint32 res = 0;

  uint8 i;

  sint32 x0;

  for (i = 0; i < LUT_SIZE; i++)
  {
    x0 = x;

    if (y < 0)
    {
      x = x0 - (y >> i);
      y = y + (x0 >> i);
      res = res - ATAN_2_I_LUT[i];
    }
    else
    {
      x = x0 + (y >> i);
      y = y - (x0 >> i);
      res = res + ATAN_2_I_LUT[i];
    }
  }

  return res;
}


/* implemented after the mathematical definition of atan2 */
sint32 hla_atan2 (sint32 y, sint32 x)
{
  sint32 res = 0;

  /* converting to fixpoint form and passing to atan cordic function */
  res = hla_cordic_atan ( y << SCALE_SHIFT, abs ( x ) << SCALE_SHIFT);

  /* handling for second and third quadrant */
  if (x < 0)
  {
    if (y >= 0)
    {
      /* second quadrant */
      res = FIXED_PI - res;
    }
    else
    {
      /* third quadrant */
      res = -FIXED_PI - res;
    }
  }

  return ( (res * FIXED_RAD2DEGFACTOR) >> SCALE_SHIFT);
}/* PRQA S 861 1 */
