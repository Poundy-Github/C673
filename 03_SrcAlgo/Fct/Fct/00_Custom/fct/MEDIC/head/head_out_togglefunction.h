/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_out_togglefunction.h

DESCRIPTION:               HEAD output module header for toggle functions like visual or audible alerts 

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/06/14 02:15:22CEST $

VERSION:                   $Revision: 1.7 $

LEGACY VERSION:            1.9

**************************************************************************** */
/**
@ingroup head_out_togglefunction
@{ **/
#ifndef HEAD_OUT_TOGGLEFUNCTION_H_INCLUDED
#define HEAD_OUT_TOGGLEFUNCTION_H_INCLUDED

#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)

/* ****************************************************************
    TYPEDEF STRUCT HEADModuleOutputToggleFunction_t
    **************************************************************** */
/*! @brief HEAD Module Output Toogle Function
    @general HEAD Module Output Toogle Function
    @conseq [None]
    @attention [None] */
typedef struct 
{
  /*header*/
  HEADModuleCustomOutput_ft *fpCustomOutput; /*!< HEAD Module Custom Output Structure */
  
  /*specific for this function*/
  HEADHypothesisNr_t  ActHypNr;             /*!< activation hypothesis nr for this module @unit:[-] */
  boolean             bOutFunctionActive;   /*!< return value for the toggle function -> true: alert active, false: alert not active*/
  eEBASignalState_t   eEBASignalState;      /*!< EBA Signal State */
  eEBAFctChan_t       eEBAFctChannel;       /*!< EBA FCT Channel */
} HEADModuleOutputToggleFunction_t;

extern eGDBError_t HEADOutToggleFunction(const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule, boolean bInit);

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */
#endif /* _HEAD_OUT_TOGGLEFUNCTION_H_INCLUDED */
/**@}*/ 
