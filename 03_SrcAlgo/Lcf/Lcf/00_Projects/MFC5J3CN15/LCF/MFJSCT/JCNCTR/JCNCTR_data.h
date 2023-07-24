/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : MFC5J3CN15
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : MFJSCT
  MODULE        : JCNCTR
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     JCNCTR_data.h
//! @brief     (JCNCTR) Module Data Header.

#ifndef JCNCTR_DATA_H_
#define JCNCTR_DATA_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_type.h"

//MFC5J3CN15
//#ifdef __cplusplus
//extern "C"
//{
//#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

extern const JCNCTR_SenDbgType* JCNCTR_SenGetDbgPtr(void);

/*!
 *	JCNCTR module sensor get function. Function gets JCNCTR sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>JCNCTR_SenOutPtr</b> Global static pointer to JCNCTR sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const JCNCTR_SenOutType* JCNCTR_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_JCNCTR_PrjSpecQu_btf
#define S_JCNCTR_PrjSpecQu_btf (JCNCTR_SenGetOutPtr()->S_JCNCTR_PrjSpecQu_btf) //!< JCNCTR output macro.
#define GET_S_JCNCTR_PrjSpecQu_btf() (S_JCNCTR_PrjSpecQu_btf) //!< JCNCTR output macro getter.
#endif // S_JCNCTR_PrjSpecQu_btf

#ifndef S_JCNCTR_LDWPrjSpecQu_btf
#define S_JCNCTR_LDWPrjSpecQu_btf (JCNCTR_SenGetDbgPtr()->S_JCNCTR_LDWPrjSpecQu_btf) //!< JCNCTR output macro.
#define GET_S_JCNCTR_LDWPrjSpecQu_btf() (S_JCNCTR_LDWPrjSpecQu_btf) //!< JCNCTR output macro getter.
#endif

#ifndef S_JCNCTR_LKAPrjSpecQu_btf
#define S_JCNCTR_LKAPrjSpecQu_btf (JCNCTR_SenGetDbgPtr()->S_JCNCTR_LKAPrjSpecQu_btf) //!< JCNCTR output macro.
#define GET_S_JCNCTR_LKAPrjSpecQu_btf() (S_JCNCTR_LKAPrjSpecQu_btf) //!< JCNCTR output macro getter.
#endif

#ifndef S_JCNCTR_ELKPrjSpecQu_btf
#define S_JCNCTR_ELKPrjSpecQu_btf (JCNCTR_SenGetDbgPtr()->S_JCNCTR_ELKPrjSpecQu_btf) //!< JCNCTR output macro.
#define GET_S_JCNCTR_ELKPrjSpecQu_btf() (S_JCNCTR_ELKPrjSpecQu_btf) //!< JCNCTR output macro getter.
#endif
//#ifdef __cplusplus
//}
//#endif

#endif // JCNCTR_DATA_H_
