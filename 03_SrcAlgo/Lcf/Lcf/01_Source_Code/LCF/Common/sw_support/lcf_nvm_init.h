/*! \file **********************************************************************

  COMPANY:                   Continental AG

  PROJECT:                   MFC431

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 lcf_nvm_init.h

  DESCRIPTION:               Initializer code for LCF NVM data (L3D_ALGO_26020)

  AUTHOR:                    Elena Nastasa

  CREATION DATE:             2018-03-06

  VERSION:                   $$


  ---*/ /*---
  CHANGES:                   $$


*****************************************************************************/

#ifndef lcf_nvm_init_h__
#define lcf_nvm_init_h__

#include "algo_glob.h"

#ifdef __cplusplus
extern "C"
{
#endif

#if LCF_IUC2SOC_INTFVER >= 2
void NvmInitNVM_LcfLearningData (NVM_LcfLearningData_t * const Dest, boolean bCalibReset);
#else
void NvmInitNVM_LcfLearningData(void);
#endif

#ifdef __cplusplus
}
#endif

#endif 