/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_out_hbafunction_autocodepar.h

DESCRIPTION:               header file of autocode parameters (HBAFunction) in the HEAD module

AUTHOR:                    $Author:$

CREATION DATE:             $Date:$

VERSION:                   $Revision:$

HPX:                       MFC5J3_EBA_Truck_Decel_Req.hpx

**************************************************************************** */

/**

@ingroup head_out_hbafunction
@{ **/

/* DO NOT MANUALLY EDIT THIS FILE - use cgeb_head_generate_code.py instead! */

/*CHECKSUMCODE*/
#ifndef _HEAD_OUT_HBAFUNCTION_AUTOCODEPAR
#define _HEAD_OUT_HBAFUNCTION_AUTOCODEPAR

/*! @brief          HEAD output hbafunction  parameter

  @description      Define the output hbafunction deceleration

  */
typedef struct
{
  uint8 HBADefaultLevel;
  float32 HEADHBAaNecToLevelRelation[2*3];  /*!<@values:float32[3][2]*/
  uint8 HEADHBAaNecToLevelRelation_Rows;
  uint8 HEADHBAEvalOrGroupToLevel;
  uint8 HEADHBAOrGroupToLevelTable[2*2];  /*!<@values:uint8[2][2]*/
  uint8 HEADHBAOrGroupToLevelTable_Rows;
  sint8 HEADHBAKeepLevelFirstOrGroup;
  uint8 HEADHBAUseLevelToReqDecel;
  float32 HEADHBALevelToReqDecelTable[2*3];  /*!<@values:float32[3][2]*/
  uint8 HEADHBALevelToReqDecelTable_Rows;
  float32 HEADHBAAccelerationOffset;
  uint8 FirstHBAModule;
} HEADModuleOutputHBAFunctionPar_t;


#endif /*_HEAD_OUT_HBAFUNCTION_AUTOCODEPAR*/

/*/CHECKSUMCODE*/

/**@}*/

/*AUTOCHECKSUM_SHA256*/
/*b502b6c763140978d83c41af52c9a02f7121f22b5bf02cfd33f5f255691f1153*/
/*/AUTOCHECKSUM_SHA256*/

