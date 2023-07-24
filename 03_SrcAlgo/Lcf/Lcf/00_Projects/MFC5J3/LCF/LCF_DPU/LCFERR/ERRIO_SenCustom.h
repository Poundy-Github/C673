/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 ERRIO_SenCustom.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   $Log: ERRIO_SenCustom.h  $
  CHANGES:                   Revision 1.1 2020/03/25 13:44:31CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/00_Projects/MFC431BD10/LCF/LCF_DPU/LCFERR/project.pj
  CHANGES:                   Revision 1.5 2019/11/26 13:47:48CET Grosu, George (uidl9584) 
  CHANGES:                   Bring changes from TA19 to trunk
  CHANGES:                   Revision 1.4 2019/04/10 04:08:48CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF files for auxcodegen v4.0
  CHANGES:                   Revision 1.3 2019/03/24 09:16:22CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   1st check-in of files from AuxCodeGen 4.0
  CHANGES:                   Revision 1.8 2019/03/22 15:18:50CET Grosu, George (uidl9584) 
  CHANGES:                   review update
  CHANGES:                   Revision 1.7 2019/03/13 12:58:46CET Grosu, George (uidl9584) 
  CHANGES:                   Silent LCFERR
  CHANGES:                   Revision 1.6 2019/02/24 18:01:32CET Grosu, George (uidl9584) 
  CHANGES:                   Update Quality tables
  CHANGES:                   Revision 1.5 2019/01/31 09:17:07CET Grosu, George (uidl9584) 
  CHANGES:                   Add range checks
  CHANGES:                   Revision 1.4 2018/10/31 15:40:56CET Grosu, George (uidl9584) 
  CHANGES:                   Remove cycle counter check for VehPar
  CHANGES:                   Revision 1.3 2018/09/14 16:16:15CEST Grosu, George (uidl9584) 
  CHANGES:                   Split naming for Error Handler
  CHANGES:                   Revision 1.2 2018/05/24 13:06:15CEST Grosu, George (uidl9584) 
  CHANGES:                   Update LCFERR
  CHANGES:                   Revision 1.1 2018/05/22 16:35:02CEST Grosu, George (uidl9584) 
  CHANGES:                   Reorder files

**************************************************************************** */

#ifndef __ERRIO_SenCustom_H__
#define __ERRIO_SenCustom_H__

#include "lcf_sen_ext.h"
#include "LCFERR_SenCustom.h"

#define LCF_ERR_INC_STEP             (5u)
#define LCF_ERR_DEC_STEP             (3u)
#define LCF_ERR_MAXINC               (9u)

/* Data Types */
/* Enum for action index used in ACT module */
typedef enum ERRIOSEN_enReqHeaders
{
    ERRIOSEN_enSigHeadBCD = (uint8)0,
    ERRIOSEN_enSigHeadABD,
#if defined(LCF_CAMOBJ_USED) && (LCF_CAMOBJ_USED == 1)
    ERRIOSEN_enSigHeadCAMObj,
    ERRIOSEN_enSigHeadGENObj,
#endif
    ERRIOSEN_enSigHeadLcfIn,
#if defined(LCF_IUC_USED) && (LCF_IUC_USED == 1)
    ERRIOSEN_enSigHeadI2S,
#endif
    ERRIOSEN_enSigHeadV2S,
    ERRIOSEN_enSigHeadVehOut,
    ERRIOSEN_enSigHeadVDY,
    //ERRIOSEN_enSigHeadVPar,//GeGr: Parameters must not be checked for cycle counter
    ERRIOSEN_enSigHeadVSig,
    ERRIOSEN_enSigHeadNumber
   
} ERRIOSEN_enReqHeaders_t;

#include "LCFERR/errio.h"

/* Configuration arrays for each signal source */
extern ERRIO_ErrConfigData ERRIOSEN_ErrConfigNormData[];


extern ERRIO_ErrConfigData ERRIOSEN_ErrConfigVehDynData[];

extern ERRIO_ErrConfigData ERRIOSEN_ErrConfigVehSigAddData[];

extern ERRIO_ErrConfigData ERRIOSEN_ErrConfigVehSigMainData[];

extern ERRIO_ErrConfigData ERRIOSEN_ErrConfigVehSigBrakeData[];

extern uint8 ERRIOSEN_size_ErrConfigNormData;
extern uint8 ERRIOSEN_size_ErrConfigVehDynData;
extern uint8 ERRIOSEN_size_ErrConfigVehSigAddData;
extern uint8 ERRIOSEN_size_ErrConfigVehSigMainData;
extern uint8 ERRIOSEN_size_ErrConfigVehSigBrakeData;

extern uint32 ERRIOSEN_RngChkFailed_btf;

/* ***********************************************************************
  @fn               ERRIOSEN_InputsCheck */ /*!

  @brief            check status of relevant inputs

  @description      

  @param[in]        pReqPorts required ports
  @param[out]       
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */  
void ERRIOSEN_InputsCheck(const reqLcfSenPrtList_t *pReqPorts);
void ERRIOSEN_CheckAllive(void);
void ERRIOSEN_SenSetHeader(const reqLcfSenPrtList_t *pReqPorts);
void ERRIOSEN_ResetSigHdrConstCycles(void);



#endif
