/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 TP (Target Planner)

PACKAGENAME:               targetplanner_main.h

DESCRIPTION:               Header of TP component

AUTHOR:                    $Author: Sekar, Balaji02 (uids6618) $

CREATION DATE:             $Date: 2020/10/19 08:24:25CEST $

VERSION:                   $Revision: 1.8 $

LEGACY VERSION:            
 
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#ifndef TP_MAIN_H_INCLUDED
#define TP_MAIN_H_INCLUDED

#include "frame_medic/medic_int.h"
#include "head20/head20_int.h"

/*****************************************************************************
  MACROS
*****************************************************************************/
/*! @brief Default Stop Distance Longitudinal */
#define DEFAULT_STOP_DISTANCE (0.6f)

/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
extern eGDBError_t TPRun(void);
extern float32 TPLongDistMinCalc(float32 angleToTraj);
#endif /*!< TP_MAIN_H_INCLUDED */

