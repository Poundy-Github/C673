/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM

PACKAGENAME:               dim_autoversion.h

DESCRIPTION:               header file of auto version information of DIM

AUTHOR:                    $Author: Ramachandra, Rashmi (uids9858) $

CREATION DATE:             $Date: 2019/11/22 10:41:44CET $

VERSION:                   $Revision: 1.4 $

LEGACY VERSION:            1.17

**************************************************************************** */
/**
@ingroup Medic_dim
@{ **/
#ifndef DIM_AUTOVER_H_INCLUDED
#define DIM_AUTOVER_H_INCLUDED
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

/* DIM version number: */
/*! @brief       FCTDIM_SW_MAIN_VER_NO
    @general     -
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     0x02uL   @unit -     @min -   @max -   */
#define FCTDIM_SW_MAIN_VER_NO       0x02uL

/*! @brief       FCTDIM_SW_SUB_VER_NO
    @general     -
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     0x00uL   @unit -     @min -   @max -   */
#define FCTDIM_SW_SUB_VER_NO        0x00uL

/*! @brief       FCTDIM_SW_BUG_FIX_LEV
    @general     -
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     0x00uL   @unit -     @min -   @max -   */
#define FCTDIM_SW_BUG_FIX_LEV       0x00uL

  /*! @brief       FCTDIM_SW_VERSION_NUMBER
    @general     -
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     -   @unit -     @min -   @max -   */
#define FCTDIM_SW_VERSION_NUMBER   ((FCTDIM_SW_MAIN_VER_NO << 16u) | (FCTDIM_SW_SUB_VER_NO << 8u) | (FCTDIM_SW_BUG_FIX_LEV))


/* As long as automatic generation of version number is not implemented use manual defined one !*/
  
/*CHECKSUMCODE*/

    /*! @brief       DIM_AUTOVERSION
    @general     -
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     FCTDIM_SW_VERSION_NUMBER   @unit -     @min -   @max -   */
#define DIM_AUTOVERSION FCTDIM_SW_VERSION_NUMBER
/*/CHECKSUMCODE*/

#ifdef __cplusplus
};
#endif

/*** END OF SINLGE INCLUDE SECTION ******************************************/
#endif /* DIM_AUTOVER_H_INCLUDED */
/**@}*/

