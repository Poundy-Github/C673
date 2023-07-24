/**
 * \file Cpr_Lcfg.h
 *
 * \brief This file contains related data types of Cpr.
 *
 * \version refer the Cpr_Core.h.
 *
 */

#ifndef _CPR_LCFG_H_
#define _CPR_LCFG_H_

/*==================[inclusions]============================================*/
#include "Cpr_Type.h"
#include "Cpr_Cfg.h"
#include "Com.h"
#include "Rte_Cpr.h"
/*==================[macros]=================================================*/
#define CPR_Notify_SignalStatusUpdated      Cpr_Notify_SignalStatusUpdated 
/*==================[type definitions]=======================================*/


/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/
extern const s_Cpr_ReceiveSignalConfig_t Cpr_ReceiveSignalConfigTable[CPR_REVEIVE_SIGNAL_NUMBER];

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/



#endif /* _CPR_LCFG_H_ */
