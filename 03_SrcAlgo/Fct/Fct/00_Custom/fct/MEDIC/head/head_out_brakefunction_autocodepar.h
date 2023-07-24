/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_out_brakefunction_autocodepar.h

DESCRIPTION:               header file of autocode parameters (BrakeFunction) in the HEAD module

AUTHOR:                    $Author:$

CREATION DATE:             $Date:$

VERSION:                   $Revision:$

HPX:                       MFC5J3_EBA_Truck_Decel_Req_Test.hpx

**************************************************************************** */

/**

@ingroup head_out_brakefunction
@{ **/

/* DO NOT MANUALLY EDIT THIS FILE - use cgeb_head_generate_code.py instead! */

/*CHECKSUMCODE*/
#ifndef _HEAD_OUT_BRAKEFUNCTION_AUTOCODEPAR
#define _HEAD_OUT_BRAKEFUNCTION_AUTOCODEPAR

/*! @brief          HEAD output brakefunction  parameter

  @description      Define the output brakefunction deceleration

  */
typedef struct
{
  float32 AutoBrkParBrakeReactionTime;
  float32 AutoBrkParMaxCtrlVeloReduct[2*5];  /*!<@values:float32[5][2]*/
  uint8 AutoBrkParMaxCtrlVeloReduct_Rows;
  float32 AutoBrkParMaxAllowVeloReduct[2*5];  /*!<@values:float32[5][2]*/
  uint8 AutoBrkParMaxAllowVeloReduct_Rows;
  float32 AutoBrkParTabBrakeDecel[2*7];  /*!<@values:float32[7][2]*/
  uint8 AutoBrkParTabBrakeDecel_Rows;
  float32 AutoBrkParTabStatDecel[2*7];  /*!<@values:float32[7][2]*/
  uint8 AutoBrkParTabStatDecel_Rows;
  float32 AutoBrkParTabMovDecel[2*7];  /*!<@values:float32[7][2]*/
  uint8 AutoBrkParTabMovDecel_Rows;
  float32 AutoBrkParTabCommonDecel[2*7];  /*!<@values:float32[7][2]*/
  uint8 AutoBrkParTabCommonDecel_Rows;
  float32 AutoBrkParTabMaxDecel[2*5];  /*!<@values:float32[5][2]*/
  uint8 AutoBrkParTabMaxDecel_Rows;
  sint8 HEAD_BRK_ANEC_CTRL;
  float32 AutoBrkParCtrlMaxVelStat;
  float32 AutoBrkParCtrlMaxVelBrake;
  float32 AutoBrkParCtrlMaxVelMov;
  float32 AutoBrkParCtrlMaxStartVrel;
  float32 AutoBrkParRampOutGrad;
  float32 AutoBrkParTabDrvFdkToRampOut[2*5];  /*!<@values:float32[5][2]*/
  uint8 AutoBrkParTabDrvFdkToRampOut_Rows;
  sint8 AutoBrkParDrvActToRampOut;
  uint8 Veh_BrkLevelNr;
  sint8 HEAD_LAST_MODULE;
} HEADModOutBrakeFunctionPar_t;


#endif /*_HEAD_OUT_BRAKEFUNCTION_AUTOCODEPAR*/

/*/CHECKSUMCODE*/

/**@}*/

/*AUTOCHECKSUM_SHA256*/
/*a42541d5777058fa9b69fe256670aa970a5f62279752be601e0c732e1df3accd*/
/*/AUTOCHECKSUM_SHA256*/

