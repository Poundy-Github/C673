/***********************************************************************
  COMPANY:     Continental Automotive

  PROJECT:     MFC510

  COMPONENT:   MTSI

  VERSION:     $Revision: 1.1 $
 **********************************************************************/
#ifndef MTSI_Cfg_Int_H
#define MTSI_Cfg_Int_H

#include "MTSI_Types.h"

#ifdef __cplusplus
extern "C"
{
#endif

extern const t_MainControl MainControl[CFG_MTSI_NUMBER_OF_CORES];

extern const MTSI_t_StatisticControl StatisticControl[CFG_MTSI_NUMBER_OF_CORES];

#ifdef __cplusplus
}
#endif

#endif
