/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_main.h

DESCRIPTION:               header of the head process

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2019/07/26 14:48:19CEST $

VERSION:                   $Revision: 1.6 $

LEGACY VERSION:            1.6

**************************************************************************** */
/**
@ingroup head
@{ **/
#ifndef HEAD_MAIN_H_INCLUDED
#define HEAD_MAIN_H_INCLUDED
/*** START OF SINGLE INCLUDE SECTION ****************************************/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/
/*!  @cond Doxygen_Suppress */
extern HEADHypothesisList_t HEADHypothesisList;
/*! @endcond */

/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/
extern eGDBError_t HEADInitialize(HEADMTSStaticData_t *pMTSStaticData, HEADModuleList_t *pModuleList);

extern eGDBError_t HEADUpdateHypothesisList(uint8 *pMaxHypoIndex, uint8 *pMaxHypKin);

/*** END OF SINLGE INCLUDE SECTION ******************************************/

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */

#endif /* HEAD_MAIN_H_INCLUDED */
/**@}*/

