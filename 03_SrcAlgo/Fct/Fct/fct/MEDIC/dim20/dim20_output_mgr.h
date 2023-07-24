/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim20_output_mgr.c

DESCRIPTION:               Header for DIM Output Manager

AUTHOR:                    $Author: Ramachandra, Rashmi (uids9858) $

CREATION DATE:             $Date: 2020/04/01 15:46:02CEST $

VERSION:                   $Revision: 1.10 $
  
**************************************************************************** */

#ifndef DIM20_OUTPUT_MGR_INCLUDED
#define DIM20_OUTPUT_MGR_INCLUDED

#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)

/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/

/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
/* extern functions */
extern void DIMInitOutputMgr(void);
extern void DIMFillBaseOutput( const GDB_DMHypothesis_t *hypIn, GDB_DMHypothesis_t hypOut[], uint8 uiHypNr, uint8 uiTotalHypNr);
extern void DIMFillOutput(void);
extern void DIMFillCustomOut(void);
extern uint8 DIMSelectSiganlsForHypo(uint8 index);

#endif /* MEDIC_CFG_DRIVER_INTENTION_MONITORING */
#endif /*DIM_OUTPUT_MGR_INCLUDED*/

