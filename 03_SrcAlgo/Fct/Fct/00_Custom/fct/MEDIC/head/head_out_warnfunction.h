/*! \file **********************************************************************
  
COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_out_warnfunction.h

DESCRIPTION:               header of the head generic warn function output

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/06/14 02:15:44CEST $

VERSION:                   $Revision: 1.3.1.6 $

LEGACY VERSION:            1.7

**************************************************************************** */
/**
@ingroup head_out_warnfunction
@{ **/
#ifndef HEAD_OUT_WARNFUNCTION_H_INCLUDED
#define HEAD_OUT_WARNFUNCTION_H_INCLUDED
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
******************************************************************************/
/* ****************************************************************
    TYPEDEF STRUCT HEADModuleOutputWarnFunctionInternal_t
    **************************************************************** */
/*! @brief HEAD Module Output Warning Internal Function Structure

    @general HEAD Module Output Warning Internal Function Structure

    @conseq [None]

    @attention [None]

    */
typedef struct 
{
  /*internal state variables*/
  eEBASignalState_t  eSignal;	 /*!< EBA Signal State*/
  eEBAFctChan_t      eFctChan; /*!< EBA FCt Channel*/
  uint8              uActiveHyp;	/*!< Active Hypothesis number*/
} HEADModuleOutputWarnFunctionInternal_t;

/* ****************************************************************
    TYPEDEF STRUCT HEADModuleOutputWarnFunction_t
    **************************************************************** */
/*! @brief HEAD Module Output Warning Function Structure

    @general HEAD Module Output Warning Function Structure

    @conseq [None]

    @attention [None]

    */
typedef struct 
{
  /*header*/
  HEADModuleCustomOutput_ft *fpCustomOutput; /*!< HEAD Module Output*/
  /*internal state variables*/
  eEBASignalState_t* peSignal;/*!< EBA Signal State*/
  eEBAFctChan_t*     peFctChan;/*!< EBA FCt Channel*/
  uint8*             puActiveHyp;/*!< Active Hypothesis number*/
} HEADModuleOutputWarnFunction_t;            /*!@ref HEADModuleOutputInterface_t*/

/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/
extern eGDBError_t HEADOutWarnFunction(const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule, boolean bInit);

/*** END OF SINLGE INCLUDE SECTION ******************************************/

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */

#endif /* _HEAD_OUT_BRAKEFUNCTION_H_INCLUDED */
/**@}*/ 
