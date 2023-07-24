/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_cfg.h

  DESCRIPTION:               Configuration file for the CML component

  AUTHOR:                    D. Meschenmoser

  CREATION DATE:             28.08.2012

  VERSION:                   $Revision: 1.8 $

  ---*/ /*---
  CHANGES:                   $Log: cml_cfg.h  $
  CHANGES:                   Revision 1.8 2017/09/27 05:58:37CEST A, Nandu (uidr5428) (uidr5428) 
  CHANGES:                   Merged from branch with Detailed Design
  CHANGES:                   Revision 1.7 2015/05/19 13:27:32CEST Sauer, Stefan (uidg5644) 
  CHANGES:                   - Switch off QA-C warning for CML_ASSERT
  CHANGES:                   - Added comments -  uidg5644 [May 19, 2015 1:27:33 PM CEST]
  CHANGES:                   Change Package : 334078:1 http://mks-psad:7002/im/viewissue?selection=334078
  CHANGES:                   Revision 1.6 2014/04/07 10:28:46CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed erroneous include protection
  CHANGES:                   --- Added comments ---  uidg6516 [Apr 7, 2014 10:28:46 AM CEST]
  CHANGES:                   Change Package : 227281:3 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.5 2014/02/04 15:09:40CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - improve code quality
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 4, 2014 3:09:40 PM CET]
  CHANGES:                   Change Package : 159154:34 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.4 2013/05/03 10:31:46CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - fix CML_ASSERT
  CHANGES:                   --- Added comments ---  uidu0849 [May 3, 2013 10:31:46 AM CEST]
  CHANGES:                   Change Package : 159154:27 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.3 2013/05/03 09:55:23CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - fix CML_ASSERT
  CHANGES:                   - define CML_enum_t
  CHANGES:                   --- Added comments ---  uidu0849 [May 3, 2013 9:55:23 AM CEST]
  CHANGES:                   Change Package : 159154:27 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.2 2013/04/23 10:42:14CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - introduce CML_ASSERT()
  CHANGES:                   --- Added comments ---  uidu0849 [Apr 23, 2013 10:42:15 AM CEST]
  CHANGES:                   Change Package : 159154:26 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.1 2012/09/25 11:53:22CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

/* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
  /* date: 2015-05-18, reviewer: S. Schwarzkopf, S. Sauer, reason:  
     Macro CML_ASSERT can be set up platform dependent and is intended to have 
     no side effects here.
     Review-ID: 
  */
  #pragma PRQA_MACRO_MESSAGES_OFF "CML_ASSERT" 3112
#endif /* #ifdef PRQA_SIZE_T */

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/

/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef _CML_EXT_INCLUDED
  #pragma message(__FILE__": Inclusion of cml_cfg.h is discouraged. It exists only for compatibility with ARS3xx and might be deleted without prior notice. Include cml_ext.h instead.")
#endif /* #ifdef _CML_EXT_INCLUDED */

#ifndef _CML_CFG_INCLUDED
#define _CML_CFG_INCLUDED ///< To avoid multiple inclusion of the file


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#if (defined(WIN32) && !defined(__PDO__))
  #include <assert.h>
#endif


/*****************************************************************************
  CONSTANTS
*****************************************************************************/

/*! Turns matrix size check on/off - influences speed */
/*!   turn ON  for development/debugging -> SLOW but safer */
/*!   turn OFF for release   -> FAST */
#define CML_MatrixBoundsCheckOn (0)  ///< \brief Switch to enable/disable input structure condition checks in the matrix operations \description The switch checks the basic conditions required for matrix operations. May be kept ON for development/ debugging (safer and slower). and OFF for release (faster).


/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

typedef uint8 CML_enum_t;


/*****************************************************************************
  MACROS
*****************************************************************************/

/* use assertions to check critical conditions - only in simulation */
#if (defined(WIN32) && !defined(__PDO__))
  #define CML_ASSERT(cond) assert(cond)   ///< Assertion for the critical condition checks in CML. This is active only for simulation.
#else
  #define CML_ASSERT(cond) ((void)0)      ///< Assertion for the critical condition checks in CML. This is active only for simulation.
#endif

#endif /* #ifndef _CML_CFG_INCLUDED */

