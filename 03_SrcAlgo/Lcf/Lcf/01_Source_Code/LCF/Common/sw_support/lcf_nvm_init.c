/*! \file **********************************************************************

  COMPANY:                   Continental AG

  PROJECT:                   MFC431

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 lcf_nvm_init.c

  DESCRIPTION:               Initializer code for LCF NVM data (L3D_ALGO_26020)

  AUTHOR:                    Elena Nastasa

  CREATION DATE:             2018-03-06

  VERSION:                   $$


  ---*/ /*---
  CHANGES:                   $$


*****************************************************************************/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "lcf_nvm_init.h"

#ifndef LCF_NUM_ELEM_ADP_CORR_ARR
#define LCF_NUM_ELEM_ADP_CORR_ARR  20u //TODO: it's better to place this define in RTE excel (sheets NVM_LcfLearningData and Static Variables)
#endif

#if LCF_IUC2SOC_INTFVER >= 2

/*****************************************************************************
  FUNCTION
*****************************************************************************/
void NvmInitNVM_LcfLearningData (NVM_LcfLearningData_t* const Dest, boolean bCalibReset)
{
  uint8 i;
  /* set values when valid pointer */
  if (Dest != NULL)
  {
     Dest->uiVersionNumber                 = LCF_LEARNDATA_INTFVER;
     Dest->sSigHeader.eSigStatus           = AL_SIG_STATE_OK;
	   Dest->sSigHeader.uiCycleCounter       = 0u;
     Dest->sSigHeader.uiMeasurementCounter = 0u;
     Dest->sSigHeader.uiTimeStamp          = 0u;

     /* Reset Learning Values : EOL */
	 for (i = 0; i < LCF_NUM_ELEM_ADP_CORR_ARR; i++)
	 {
		 Dest->AdpCorrFactorPos_nu[i]  = 0x00;    
		 Dest->AdpCorrCounterPos_nu[i] = 0x00;
		 Dest->AdpCorrFactorNeg_nu[i]  = 0x00;
		 Dest->AdpCorrCounterNeg_nu[i]  = 0x00;
	 }
   Dest->AngleOff_nu = 0x00;
   Dest->AngleOffCalibCnt_nu = 0x00;
  }
  else
  {
  }
  (void)bCalibReset;
}

#else
void NvmInitNVM_LcfLearningData(void)
{
}
#endif
