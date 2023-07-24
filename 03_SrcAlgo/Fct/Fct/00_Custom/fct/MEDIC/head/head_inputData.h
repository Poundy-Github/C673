/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_inputData.h

DESCRIPTION:               Implementation of the head output arbitration

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/06/14 02:13:54CEST $

VERSION:                   $Revision: 1.4.2.6 $

LEGACY VERSION:            1.5

**************************************************************************** */
/**
@ingroup head_inputData
@{ **/
#ifndef HEAD_INPUTDATA_H_INCLUDED
#define HEAD_INPUTDATA_H_INCLUDED

/** @cond */
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
/** @endcond */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
/* ****************************************************************
    TYPEDEF STRUCT HEADExtraInputValueList_t
    **************************************************************** */
/*! @brief HEAD Extra Input Value List
    @general HEAD Extra Input Value List
    @conseq [None]
    @attention [None] */
typedef struct 
{
  struct HEADInputValue_t ExtPreBrakeSetting;  /*!< ExtPreBrakeSetting*/
  struct HEADInputValue_t DIMInputsValid;      /*!< DIMInputsValid*/
} HEADExtraInputValueList_t;

/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/
/*!  @cond Doxygen_Suppress */

/*! @brief HEAD Extra Input Value List*/
extern HEADExtraInputValueList_t HEADExtraInputValueList;

 /*!Bool variable to indicate the HEAD is Initialized or not*/
extern boolean bHEADInitialized;

/*! @endcond */

/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/
extern void HEADGetInputData(const float32 fCycleTime);
extern eGDBError_t HEADSetupInputHypRef(void);
extern const HEADExtraInputValueList_t *HEADGetExtraInputValueList(void);
extern eGDBError_t HEADInitInput(HEADModuleList_t *pModuleList, float32 fCycleTime);

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */
#endif /*_HEAD_INPUTDATA_H_INCLUDED*/

/**@}*/ 
