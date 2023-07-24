/*! \file **********************************************************************

  COMPANY:                Continental AG

  PROJECT:                MFC400

  COMPONENT:              SAC

  MODULNAME:              sac_legacy_typeDefs.h

  DESCRIPTION:            Adds flag for algo_glob.h to activate the old coding
                          style type definitions

  AUTHOR:                 s. MKS

  CREATION DATE:          11.03.2013

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: sac_legacy_typeDefs.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:24:35CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:35:30CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/project.pj
  CHANGE:                 Revision 1.4 2013/12/05 11:25:49CET uidw8579 
  CHANGE:                 - #ifndef added in to remove the macro redefinition warning
  CHANGE:                 - Added comments -  uidw8579 [Dec 5, 2013 11:25:50 AM CET]
  CHANGE:                 Change Package : 208886:4 http://mks-psad:7002/im/viewissue?selection=208886
  CHANGE:                 Revision 1.3 2013/12/04 15:51:11CET Chen-EXT, Hu (uidw8579) 
  CHANGE:                 - newline added to the end of file
  CHANGE:                 --- Added comments ---  uidw8579 [Dec 4, 2013 3:51:11 PM CET]
  CHANGE:                 Change Package : 208886:4 http://mks-psad:7002/im/viewissue?selection=208886
  CHANGE:                 Revision 1.2 2013/07/23 11:36:54CEST Mueller, Reik (muellerr5) 
  CHANGE:                 - moved old style typedefs to legacy header, due to RTE change
  CHANGE:                 --- Added comments ---  muellerr5 [Jul 23, 2013 11:36:55 AM CEST]
  CHANGE:                 Change Package : 184575:1 http://mks-psad:7002/im/viewissue?selection=184575
  CHANGE:                 Revision 1.1 2013/03/11 14:16:53CET Ruland, Thomas (uidw0251) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/algo/sac/kernel/project.pj

**************************************************************************** */

#ifndef SAC_LEGACY_TYPE_DEFS_H
#define SAC_LEGACY_TYPE_DEFS_H

//activate old ADC-style type definitions
#ifndef USE_OLD_ADC_CODING_STYLE_TYPEDEFS
#define USE_OLD_ADC_CODING_STYLE_TYPEDEFS
#endif
#include "algo_glob.h"

// BEGIN - OLD STYLE TYPEDEFS
// Deprecated types -> should not be used
// Must not be used in interface structures any more !
// May be used in algo kernel
typedef uint8   UInt8;
typedef uint8   enum_t;
typedef bool8   bool_t;
typedef sint32  i32_t;
typedef sint16  i16_t;
typedef sint8   i8_t;
typedef uint32  ui32_t;
typedef uint16  ui16_t;
typedef uint8   ui8_t;
typedef float32 f32_t;
typedef uint64  ui64_t;
typedef sint64  i64_t;
// END - OLD STYLE TYPEDEFS


#endif //SAC_LEGACY_TYPE_DEFS_H
