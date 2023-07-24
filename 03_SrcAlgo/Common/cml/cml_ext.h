/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_ext.h

  DESCRIPTION:               External header for the Common Math Library

  AUTHOR:                    Jochen Spruck

  CREATION DATE:             03.02.2010

  VERSION:                   $Revision: 1.24 $

  ---*/ /*---
  CHANGES:                   $Log: cml_ext.h  $
  CHANGES:                   Revision 1.24 2017/09/27 05:58:46CEST A, Nandu (uidr5428) (uidr5428) 
  CHANGES:                   Merged from branch with Detailed Design
  CHANGES:                   Revision 1.23 2017/05/25 14:47:21CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Moved the macro for using c66x simulation in MSVC to respective files.
  CHANGES:                   Revision 1.22 2016/11/18 06:47:58CET Jagannath-EXT, Anu (uid42056) 
  CHANGES:                   Added C66x simulator code for MSVC
  CHANGES:                   Revision 1.21 2016/02/01 13:23:02CET Naik, Balachandra (uidp1547) 
  CHANGES:                   Added cml_type.h under CML_NO_RTE_DEPENDENCY macro switch for RTE dependency removal
  CHANGES:                   Revision 1.20 2015/04/28 15:25:12CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Removed unused cml beam processing module from the project
  CHANGES:                   - Added comments -  uidr5428 [Apr 28, 2015 3:25:13 PM CEST]
  CHANGES:                   Change Package : 316995:1 http://mks-psad:7002/im/viewissue?selection=316995
  CHANGES:                   Revision 1.19 2014/12/10 11:41:22CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - included interpolation functions header because interpolation functions have been extracted from cml_misc
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 10, 2014 11:41:23 AM CET]
  CHANGES:                   Change Package : 266613:11 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.18 2014/03/25 11:30:07CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed Doxygen comments
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 25, 2014 11:30:08 AM CET]
  CHANGES:                   Change Package : 227281:1 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.17 2014/02/04 15:10:36CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - improve code quality
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 4, 2014 3:10:36 PM CET]
  CHANGES:                   Change Package : 159154:34 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.16 2013/10/30 14:33:46CET Heidenreich, Philipp (uidv9899) 
  CHANGES:                   include for new module beam_processing
  CHANGES:                   --- Added comments ---  uidv9899 [Oct 30, 2013 2:33:46 PM CET]
  CHANGES:                   Change Package : 176454:1 http://mks-psad:7002/im/viewissue?selection=176454
  CHANGES:                   Revision 1.15 2013/05/03 09:56:41CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - drop algo_common from CML
  CHANGES:                   --- Added comments ---  uidu0849 [May 3, 2013 9:56:41 AM CEST]
  CHANGES:                   Change Package : 159154:27 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.14 2013/03/28 20:16:46CET Exner, Christian (uidt8578) 
  CHANGES:                   - reverted everything back to pre-cpp times and solved it differently: if you want to use the cpp classes, you have to include the cml_ext_cpp.h instead. so cml_ext.h is the entry point for ansi-c, cml_ext_cpp.h is the entry point for ansi-cpp.
  CHANGES:                   --- Added comments ---  uidt8578 [Mar 28, 2013 8:16:46 PM CET]
  CHANGES:                   Change Package : 177321:2 http://mks-psad:7002/im/viewissue?selection=177321
  CHANGES:                   Revision 1.13 2013/03/28 14:44:30CET Exner, Christian (uidt8578) 
  CHANGES:                   - bugfix: the extern "C++" linkage shall not influence further includes in subsequent headers. therefore moved the linkage specification to the inner headers, and cared about influencing the additional includes
  CHANGES:                   Revision 1.12 2013/03/22 09:43:07CET Friebertshaeuser, Markus (uidt0551) 
  CHANGES:                   - finally removed define
  CHANGES:                   - removed unneccessary ";" due to TI compiler warning
  CHANGES:                   --- Added comments ---  uidt0551 [Mar 22, 2013 9:43:07 AM CET]
  CHANGES:                   Change Package : 162889:10 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:                   Revision 1.11 2013/03/20 15:18:25CET Exner, Christian (uidt8578) 
  CHANGES:                   - check USE_OLD_ADC_CODING_STYLE_TYPEDEFS before definig
  CHANGES:                   --- Added comments ---  uidt8578 [Mar 20, 2013 3:18:26 PM CET]
  CHANGES:                   Change Package : 177491:2 http://mks-psad:7002/im/viewissue?selection=177491
  CHANGES:                   Revision 1.10 2013/03/19 15:25:20CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - add define to use old style standard types (only used in MFC)
  CHANGES:                   --- Added comments ---  uidu0849 [Mar 19, 2013 3:25:21 PM CET]
  CHANGES:                   Change Package : 159154:18 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.9 2013/03/15 16:13:29CET Defatsch, Simon (uidv1229) 
  CHANGES:                   stl list added
  CHANGES:                   --- Added comments ---  uidv1229 [Mar 15, 2013 4:13:30 PM CET]
  CHANGES:                   Change Package : 155416:1 http://mks-psad:7002/im/viewissue?selection=155416
  CHANGES:                   Revision 1.8 2013/02/22 09:32:59CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - add comment
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 22, 2013 9:32:59 AM CET]
  CHANGES:                   Change Package : 159154:16 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.7 2013/02/12 14:11:41CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - remove compiler warnings
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 12, 2013 2:11:41 PM CET]
  CHANGES:                   Change Package : 159154:14 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.6 2012/12/12 15:07:02CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - delete definition of namespace cml
  CHANGES:                   - surround templates with extern "C++"
  CHANGES:                   --- Added comments ---  uidu0849 [Dec 12, 2012 3:07:05 PM CET]
  CHANGES:                   Change Package : 159154:13 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.5 2012/12/07 15:54:38CET Friebertshaeuser, Markus (uidt0551) 
  CHANGES:                   Added C++ STL template classes
  CHANGES:                   --- Added comments ---  uidt0551 [Dec 7, 2012 3:54:40 PM CET]
  CHANGES:                   Change Package : 162889:10 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:                   Revision 1.4 2012/10/17 14:41:54CEST Diewald, Fabian (uidt8878) 
  CHANGES:                   added cml_complex.h
  CHANGES:                   --- Added comments ---  uidt8878 [Oct 17, 2012 2:41:54 PM CEST]
  CHANGES:                   Change Package : 93108:17 http://mks-psad:7002/im/viewissue?selection=93108
  CHANGES:                   Revision 1.3 2012/09/25 13:42:31CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - include function fastlog10 and CalculatePolygonValue
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 25, 2012 1:42:31 PM CEST]
  CHANGES:                   Change Package : 159154:6 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.2 2012/09/20 13:29:44CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - delete old log in file header
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 20, 2012 1:29:44 PM CEST]
  CHANGES:                   Change Package : 159154:3 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.1 2012/09/14 14:31:05CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

/**
@defgroup cml CML (Common Math Library)
  @ingroup algo
@{ */

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/
#ifndef _CML_EXT_INCLUDED
#define _CML_EXT_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#ifdef CML_NO_RTE_DEPENDENCY
#include "cml_type.h"
#else
#include "Rte_type.h"
#endif

#include "cml_bayes.h"
#include "cml_cfg.h"
#include "cml_complex.h"
#include "cml_const.h"
#include "cml_ecu_emul.h"
#include "cml_fourier.h"
#include "cml_kafi.h"
#include "cml_mapping.h"
#include "cml_mat.h"
#include "cml_misc.h"
#include "cml_radar.h"
#include "cml_mtrx.h"
#include "cml_stat.h"
#include "cml_trigo.h"
#include "cml_vector.h"
#include "cml_interpol.h"
#include "cml_ver.h"

/*****************************************************************************
  MACROS
*****************************************************************************/

#define CML_UNREFERENCED_FORMAL_PARAMETER(x) (void)(x)   ///< Macro to disable some level-4 warnings 

#endif /* #ifndef _CML_EXT_INCLUDED */

/** @} end defgroup */
