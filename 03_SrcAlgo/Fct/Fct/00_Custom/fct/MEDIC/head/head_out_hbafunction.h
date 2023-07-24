/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_out_hbafunction.h

DESCRIPTION:               header of the head hba function output

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2019/07/26 14:49:31CEST $

VERSION:                   $Revision: 1.3.2.4 $

LEGACY VERSION:            1.15

**************************************************************************** */
/**
@ingroup head_out_hbafunction
@{ **/
#ifndef _HEAD_OUT_HBAFUNCTION_H_INCLUDED
#define _HEAD_OUT_HBAFUNCTION_H_INCLUDED
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

/*! @brief Data type for HBA output */
typedef struct 
{
  HEADModuleCustomOutput_ft *fpCustomOutput; /*!< Custom output */

  /*specific for this function*/
  const float32 *             pfHBADeceleration;  /*!< HBA deceleration @unit:mt/sec^2 */
  const uint8 *               puiHBALevel;        /*!< return value for the HBA function -> true: alert active, false: alert not active*/
  const HEADHypothesisNr_t *  pHypoNr;            /*!< pointer from activation hypotheses @unit:[-] */
  const eEBAFctChan_t *       pFctChannel;        /*!< pointer to FCT Channel */
} HEADModuleOutputHBAFunction_t;

/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/
extern eGDBError_t HEADOutHBAFunction(const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule, boolean bInit);

/*** END OF SINLGE INCLUDE SECTION ******************************************/

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */

#endif /* _HEAD_OUT_HBAFUNCTION_H_INCLUDED */
/**@}*/ 
