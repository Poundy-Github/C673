/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_autoversion.h

DESCRIPTION:               header file of auto version information of HEAD

AUTHOR:                    $Author: Nese, Raghavendra (uidp8028) $

CREATION DATE:             $Date: 2018/01/29 15:01:41CET $

VERSION:                   $Revision: 1.4 $

LEGACY VERSION:            1.10

**************************************************************************** */
/**
@ingroup Medic_head
@{ **/
#ifndef _HEAD_AUTOVERSION_H_INCLUDED
#define _HEAD_AUTOVERSION_H_INCLUDED
/*** START OF SINGLE INCLUDE SECTION ****************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*! Component version number as 3 byte BCD MM.SS.FF 
  MM: Main version number. This number is dependent on the external component 
      interface i.e. interface change enforces an increase. The number 
      starts with "01".
  SS: Sub version number. This number reflects functional changes within the main
      version of the component. The number starts with "00" at every new main 
      version number step. 
  FF: Bug fix level number. This number indicates exclusively error-correcting changes.
      If the sub version number in incremented the bug fix level restarts with "00".
*/

/*! @brief       HEAD version number : Main Version
    @general     HEAD version number : Main Version
    @conseq      @incp  
                 @decp  
    @attention   [None]
    @typical     0x01uL
    @unit        SI-unit
    
       */
#define HEAD_SW_MAIN_VER_NO       0x01uL
/*! @brief       HEAD version number : Sub Version
    @general     HEAD version number : Sub Version
    @conseq      @incp  
                 @decp  
    @attention   [None]
    @typical     0x04uL
    @unit        SI-unit
    
       */
#define HEAD_SW_SUB_VER_NO        0x06uL
/*! @brief       HEAD version number : Bug Fix Level
    @general     HEAD version number : Bug Fix Level
    @conseq      @incp  
                 @decp  
    @attention   [None]
    @typical     0x00uL
    @unit        SI-unit
    
       */
#define HEAD_SW_BUG_FIX_LEV       0x00uL
/*! @brief       HEAD version number : Software Version Number 
    @general     HEAD version number : Software Version Number 
    @conseq      @incp  
                 @decp  
    @attention   [None]
    @typical     ((HEAD_SW_MAIN_VER_NO << 16u) | (HEAD_SW_SUB_VER_NO << 8u) | (HEAD_SW_BUG_FIX_LEV))
    @unit        SI-unit
    
       */
#define HEAD_SW_VERSION_NUMBER   ((HEAD_SW_MAIN_VER_NO << 16u) | (HEAD_SW_SUB_VER_NO << 8u) | (HEAD_SW_BUG_FIX_LEV))

/*! @brief       HEAD Auto version number
    @general     HEAD Auto version number
    @conseq      @incp  
                 @decp  
    @attention   As long as automatic generation of version number is not implemented use manual defined one
    @typical     HEAD_SW_VERSION_NUMBER
    @unit        SI-unit
    
       */  
#define HEAD_AUTOVERSION HEAD_SW_VERSION_NUMBER

#ifdef __cplusplus
};
#endif


/*** END OF SINLGE INCLUDE SECTION ******************************************/
#endif
/**@}*/ 
