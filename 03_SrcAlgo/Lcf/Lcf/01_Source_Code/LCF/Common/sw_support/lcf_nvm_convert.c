/*! \file **********************************************************************

  COMPANY:                   Continental AG

  PROJECT:                   MFC431

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 lcf_nvm_convert.c

  DESCRIPTION:               Conversion code for LCF NVM data (L3D_ALGO_26014)

  AUTHOR:                    Elena Nastasa

  CREATION DATE:             2018-03-06

  VERSION:                   $$


  ---*/ /*---
  CHANGES:                   $$


*****************************************************************************/

/****************************************************************************
* INCLUDES
*****************************************************************************/
#include <string.h>
#include "lcf_nvm_convert.h"

#if LCF_IUC2SOC_INTFVER >= 2

/****************************************************************************
* LOCAL TYPEDEFS
*****************************************************************************/
 typedef struct  
 {
  AlgoInterfaceVersionNumber_t uiVersionNumber;     /*!< Version number of NVM data header */
  SignalHeader_t sSigHeader;                        /*!< signal header of NVM data header */
 } LcfNvmDataHeader_t;
 
/****************************************************************************
* GLOBAL FUNCTIONS DEFINTION
*****************************************************************************/

sint32 NvmConvertNVM_LcfLearningData(const void* const pSource, NVM_LcfLearningData_t* const pDest)
{
  sint32 retVal = -1;
  const LcfNvmDataHeader_t* pSourceCopy;

  if ((pSource != NULL) && (pDest != NULL))
  { 
    /* Extract interface version number of to-be-converted NVM learning values */
    pSourceCopy = (const LcfNvmDataHeader_t*)pSource;

    /* Check whether a conversion is really needed. */
    if (pSourceCopy->uiVersionNumber == LCF_LEARNDATA_INTFVER)
    {
      /* No conversion needed -> Simply copy existing data */
      (void)memcpy((void*)pDest, pSource, sizeof(NVM_LcfLearningData_t));
    }
    else /* Conversion needed */
    {
      /* LCF NVM data is at its initial version, so there is no older version --> conversion means simply initializing with default values */
	  /* TODO: update this memset when a new RTE version for NVM_LcfLearningData_t appears (copy existing members from pSource and initialize with default only new members */
      (void)memset((void*)pDest, 0, sizeof(NVM_LcfLearningData_t));

      /* Set new interface version number */
      pDest->uiVersionNumber = LCF_LEARNDATA_INTFVER;
      /* Set signal state to VALID */
      pDest->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
      /* Copy counters from source */
      pDest->sSigHeader.uiCycleCounter       = pSourceCopy->sSigHeader.uiCycleCounter;
      pDest->sSigHeader.uiMeasurementCounter = pSourceCopy->sSigHeader.uiMeasurementCounter;
      pDest->sSigHeader.uiTimeStamp          = pSourceCopy->sSigHeader.uiTimeStamp;
    }

    retVal = 0;
  }
  else
  {
  }
  return retVal;
}

#else
void NvmConvertNVM_LcfLearningData(void)
{
}
#endif