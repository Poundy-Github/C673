/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 ERRIO_VehCustom.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.2 $


  ---*/ /*---
  CHANGES:                   $Log: ERRIO_VehCustom.h  $
  CHANGES:                   Revision 1.2 2020/06/11 12:37:39CEST Grosu, George (uidl9584) 
  CHANGES:                   Remove checks for VehPar because parameters must not be checked for allive.
  CHANGES:                   Revision 1.1 2020/03/25 13:44:31CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/00_Projects/MFC431BD10/LCF/LCF_DPU/LCFERR/project.pj
  CHANGES:                   Revision 1.4 2019/04/10 04:08:49CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF files for auxcodegen v4.0
  CHANGES:                   Revision 1.3 2019/03/24 09:16:22CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   1st check-in of files from AuxCodeGen 4.0
  CHANGES:                   Revision 1.8 2019/03/22 15:18:52CET Grosu, George (uidl9584) 
  CHANGES:                   review update
  CHANGES:                   Revision 1.7 2019/03/13 12:58:37CET Grosu, George (uidl9584) 
  CHANGES:                   Silent LCFERR
  CHANGES:                   Revision 1.6 2019/02/24 17:21:58CET Grosu, George (uidl9584) 
  CHANGES:                   Update quality checks for all functions in veh
  CHANGES:                   Revision 1.5 2019/02/19 13:10:11CET Grosu, George (uidl9584) 
  CHANGES:                   add Intertask errors. Use algo signal names
  CHANGES:                   Revision 1.4 2018/09/14 16:16:17CEST Grosu, George (uidl9584) 
  CHANGES:                   Split naming for Error Handler
  CHANGES:                   Revision 1.3 2018/09/11 16:19:18CEST Grosu, George (uidl9584) 
  CHANGES:                   Update error handler
  CHANGES:                   Revision 1.2 2018/05/25 11:57:31CEST Grosu, George (uidl9584) 
  CHANGES:                   Resolve compiler errors
  CHANGES:                   Revision 1.1 2018/05/25 08:07:49CEST Grosu, George (uidl9584) 
  CHANGES:                   update LCFERR

**************************************************************************** */

#ifndef __ERRIO_VehCustom_H__
#define __ERRIO_VehCustom_H__

#include "lcf_veh_ext.h"
#include "LCFERR_VehCustom.h"
#include "lcf_veh_iface.h"

#define LCF_ERR_INC_STEP             (3u)
#define LCF_ERR_DEC_STEP             (3u)
#define LCF_ERR_MAXINC               (9u)

/* Data Types */
/* Enum for action index used in ACT module */
typedef enum ERRIOVEH_enReqHeaders
{
    ERRIOVEH_enSigHeadBCD = (uint8)0,
    ERRIOVEH_enSigHeadABD,
    ERRIOVEH_enSigHeadLcfIn,
#if defined(LCF_IUC_USED) && (LCF_IUC_USED == 1)
    ERRIOVEH_enSigHeadI2S,
#endif
    ERRIOVEH_enSigHeadS2V,
    ERRIOVEH_enSigHeadSenOut,
    ERRIOVEH_enSigHeadVDY,
    /*ERRIOVEH_enSigHeadVPar,*/
    ERRIOVEH_enSigHeadVSig,
	ERRIOVEH_enSigHeadVOffset,
    ERRIOVEH_enSigHeadNumber
   
} ERRIOVEH_enReqHeaders_t;

#include "LCFERR/errio.h"

/* Configuration arrays for each signal source */
extern ERRIO_ErrConfigData ERRIOVEH_ErrConfigNormData[];


extern ERRIO_ErrConfigData ERRIOVEH_ErrConfigVehDynData[];

extern ERRIO_ErrConfigData ERRIOVEH_ErrConfigVehSigAddData[];

extern ERRIO_ErrConfigData ERRIOVEH_ErrConfigVehSigMainData[];

extern ERRIO_ErrConfigData ERRIOVEH_ErrConfigVehSigBrakeData[];

extern uint8 ERRIOVEH_size_ErrConfigNormData;
extern uint8 ERRIOVEH_size_ErrConfigVehDynData;
extern uint8 ERRIOVEH_size_ErrConfigVehSigAddData;
extern uint8 ERRIOVEH_size_ErrConfigVehSigMainData;
extern uint8 ERRIOVEH_size_ErrConfigVehSigBrakeData;

extern uint32 ERRIOVEH_RngChkFailed_btf;

/* ***********************************************************************
  @fn               ERRIOVEH_InputsCheck */ /*!

  @brief            check status of relevant inputs

  @description      

  @param[in]        pReqPorts required ports
  @param[out]       
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */  
void ERRIOVEH_InputsCheck(const reqLcfVehPrtList_t *pReqPorts);
void ERRIOVEH_CheckAllive(void);
void ERRIOVEH_VehSetHeader(const reqLcfVehPrtList_t *pReqPorts);
void ERRIOVEH_ResetSigHdrConstCycles(void);



#endif
