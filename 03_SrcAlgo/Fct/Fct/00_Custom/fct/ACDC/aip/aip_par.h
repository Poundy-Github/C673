/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 AIP (ACDC Input Processing)

PACKAGENAME:               aip_par.h

DESCRIPTION:               parameter for the ACDC Input Processing module

AUTHOR:                    $Author: uidn4751 $

CREATION DATE:             $Date: 2019/06/03 16:53:49CEST $

VERSION:                   $Revision: 1.4 $
**************************************************************************** */
#ifndef AIP_PAR_H_INCLUDED
#define AIP_PAR_H_INCLUDED

#include "acdc_par.h"
#include "aip_cfg.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup aip_par Parameter
@ingroup aip
@brief    Contains the parameters of the AIP subcomponent.\n\n
@{
*/
/************* Object Offset for Testing ****************/

#if (ACDC_CFG_USE_ADD_OFFSET_SIMU)
/*! @brief      CD_LONG_OFFSET_SIMU
    @general     Simulate additional longitudinal offset, used to fake shorter longitudinal  
                 distance for the hypothesis calculation. This can be used by system test to 
                 simulate critical situation without risking a real accident. 
                 Sign convention: + increase distance, - decrease distance
                 CD parameters allow:oem_bmw*/
#define ACDC_LONG_OFFSET_SIMU                         CDParLongOffsetSimu_c  

/*! @brief Simulate additional longitudinal offset default value */
#define ACDC_LONG_OFFSET_SIMU_DEFAULT                 (         0.0f)


/*! @brief      
    @general    Simulate additional lateral offset, used to move adjacent 
                lane object to host vehicle driving path. This can be used 
                by system test to provoke intervention on target object beside 
                without risking a real accident
                Sign convention: + shift position left, - shift position right*/
#define ACDC_LAT_OFFSET_SIMU                          CDParLatOffsetSimu_c    /*!< CD parameters @allow:oem_bmw */

/*! @brief  Simulate additional lateral offset.
            @typical 0.0f, @unit [m]*/
#define ACDC_LAT_OFFSET_SIMU_DEFAULT                  (         0.0f)

#endif



///@}
#endif /*AIP_PAR_H_INCLUDED */

