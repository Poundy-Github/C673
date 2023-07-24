// COMPANY:   Continental Automotive
// COMPONENT: TYPES
// VERSION:   $Revision: 1.11 $
// 01_Source_Code\common\GLOB\glob_type.h
/// Wrapper for Platform_Types.h
/// @file

#ifndef GLOB_TYPE_H
#define GLOB_TYPE_H

// TODO   get nesting solved
// PRQA S 0810 19
// 2018-06-22; uidw1725
// Msg(3:0810) [L] '#include "D:/prj/ars441/m11_appl/norm/ars441_m11_appl_norm-kw25/04_Engineering/01_Source_Code/BASE_EB_ACG8/include/Std_Types.h"' causes nesting to exceed 8 levels - program does not conform strictly to ISO:C90.
//              Included from here.: IoHwAb_Types.h(13)
//                 Included from here.: IoHwAb_Signal.h(12)
//                   Included from here.: IoHwAb_Config.h(27)
//                     Included from here.: IoHwAb.h(38)
//                       Included from here.: PMC_ActionIoSetting.h(11)
//                         Included from here.: PMC_Action.h(13)
//                           Included from here.: PMC_State.h(13)
//                             Included from here.: PMC_State.c(10)
// reason: solve preliminary, SW architecture problem
// TODO   get nesting solved
// PRQA S 0388 6
// 2018-06-22; uidw1725
// Msg(3:0388) [L] '#include "D:/Jenkins_Slave/workspace/ARS441_Nightly_Static_Test/M11_Appl/04_Engineering/01_Source_Code/common/GLOB/Platform_Types.h"' causes nesting to exceed 15 levels - program does not conform strictly to ISO:C99.
//                             Included from here.: CDD_Mcem.c
// reason: solve preliminary, SW architecture problem
#include "Platform_Types.h"

#ifdef __cplusplus
extern "C"
{
#endif



#ifdef __cplusplus
}
#endif

#endif //-- GLOB_TYPE_H
