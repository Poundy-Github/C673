/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Lcf

  MODULNAME:                 LCFSNDSEN_common.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.1.1.5 $


  ---*/ /*--- 
  CHANGES:                   

**************************************************************************** */

#ifndef LCFSNDSEN_COMMON_H_
#define LCFSNDSEN_COMMON_H_

/*---------------------------------------------------------*
   I N C L U D E S
**---------------------------------------------------------*/
#include "lcf_sen_main.h"
#include "LCFERR/errio.h"

/*---------------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**---------------------------------------------------------*/

extern void LCFSND_SenCommonReset  (void);
extern void LCFSND_SenCommonProcess(void);
extern uint8 Get_T_LCFSND_ActToi_nu(void);

/*---------------------------------------------------------*
   E X T E R N A L   V A R I A B L E S
**---------------------------------------------------------*/

/*---------------------------------------------------------*
   M A C R O S
**---------------------------------------------------------*/

#ifndef	S_HMIOC_LdwsLHWarning_bool
#define	S_HMIOC_LdwsLHWarning_bool	(0u)
#define	GET_S_HMIOC_LdwsLHWarning_bool()  S_HMIOC_LdwsLHWarning_bool
#endif

#ifndef	S_HMIOC_LdwsRHWarning_bool
#define	S_HMIOC_LdwsRHWarning_bool	(0u)
#define GET_S_HMIOC_LdwsRHWarning_bool()  S_HMIOC_LdwsRHWarning_bool
#endif

#ifndef	S_HMIOC_ActFctLevel_nu
#define S_HMIOC_ActFctLevel_nu  (0u)
#define	GET_S_HMIOC_ActFctLevel_nu() S_HMIOC_ActFctLevel_nu  
#endif


#ifndef	S_HMIOC_DFFunctActiveState_btf
#define	S_HMIOC_DFFunctActiveState_btf	(0u)
#define	GET_S_HMIOC_DFFunctActiveState_btf() S_HMIOC_DFFunctActiveState_btf 
#endif

#ifndef	S_HMIOC_LnBndLeValid4Fct_btf
#define	S_HMIOC_LnBndLeValid4Fct_btf	(0u)
#define GET_S_HMIOC_LnBndLeValid4Fct_btf() S_HMIOC_LnBndLeValid4Fct_btf
#endif

#ifndef	S_HMIOC_LnBndRiValid4Fct_btf
#define	S_HMIOC_LnBndRiValid4Fct_btf	(0u)
#define	GET_S_HMIOC_LnBndRiValid4Fct_btf()	S_HMIOC_LnBndRiValid4Fct_btf
#endif

#ifndef	S_HMIOC_DispLaneLeftDetected_nu
#define S_HMIOC_DispLaneLeftDetected_nu (0u)
#define	GET_S_HMIOC_DispLaneLeftDetected_nu() 	S_HMIOC_DispLaneLeftDetected_nu
#endif

#ifndef	S_HMIOC_DispLaneRightDetected_nu
#define	S_HMIOC_DispLaneRightDetected_nu	(0u)
#define GET_S_HMIOC_DispLaneRightDetected_nu() S_HMIOC_DispLaneRightDetected_nu
#endif

#ifndef	S_HMIOC_AcWrnReqLeft_bool
#define S_HMIOC_AcWrnReqLeft_bool (0u)	
#define GET_S_HMIOC_AcWrnReqLeft_bool() S_HMIOC_AcWrnReqLeft_bool
#endif

#ifndef	S_HMIOC_AcWrnReqRight_bool
#define S_HMIOC_AcWrnReqRight_bool (0u)
#define GET_S_HMIOC_AcWrnReqRight_bool() S_HMIOC_AcWrnReqRight_bool
#endif

#ifndef	S_HMIOC_HandsOffSysWarning_nu
#define S_HMIOC_HandsOffSysWarning_nu  (0u)
#define GET_S_HMIOC_HandsOffSysWarning_nu() S_HMIOC_HandsOffSysWarning_nu
#endif

#ifndef	S_HMIOC_HaptWrnReqCommon_bool
#define S_HMIOC_HaptWrnReqCommon_bool (0u)	
#define GET_S_HMIOC_HaptWrnReqCommon_bool() S_HMIOC_HaptWrnReqCommon_bool 
#endif

#ifndef	S_HMIOC_HaptWrnReqLeft_bool
#define S_HMIOC_HaptWrnReqLeft_bool (0u)	
#define GET_S_HMIOC_HaptWrnReqLeft_bool() S_HMIOC_HaptWrnReqLeft_bool
#endif

#ifndef	S_HMIOC_HaptWrnReqRight_bool
#define S_HMIOC_HaptWrnReqRight_bool (0u)
#define GET_S_HMIOC_HaptWrnReqRight_bool() S_HMIOC_HaptWrnReqRight_bool
#endif 

#ifndef	S_HMIOC_VisWrnReqCommon_bool
#define S_HMIOC_VisWrnReqCommon_bool (0u)	
#define GET_S_HMIOC_VisWrnReqCommon_bool() S_HMIOC_VisWrnReqCommon_bool
#endif

#ifndef	S_HMIOC_VisWrnReqLeft_bool
#define S_HMIOC_VisWrnReqLeft_bool (0u)	
#define GET_S_HMIOC_VisWrnReqLeft_bool() S_HMIOC_VisWrnReqLeft_bool
#endif

#ifndef	S_HMIOC_VisWrnReqRight_bool
#define S_HMIOC_VisWrnReqRight_bool (0u)
#define GET_S_HMIOC_VisWrnReqRight_bool() S_HMIOC_VisWrnReqRight_bool
#endif 

#ifndef S_HMIOC_SysWarning_nu
#define S_HMIOC_SysWarning_nu         (0u)
#define GET_S_HMIOC_SysWarning_nu()  S_HMIOC_SysWarning_nu
#endif

#ifndef S_HMIOC_AvailableFunction_btf
#define S_HMIOC_AvailableFunction_btf     (0u)
#define GET_S_HMIOC_AvailableFunction_btf()  S_HMIOC_AvailableFunction_btf
#endif

#ifndef S_LCFERR_SenErrorToVeh_btf
#define S_LCFERR_SenErrorToVeh_btf   ( (ERRIOSEN_ErrStateArray[LCF_ERRHNDL_LATDMC]&0x01) << LCF_ERRHNDL_LATDMC)/*1 bit for now*/
#define GET_S_LCFERR_SenErrorToVeh_btf() S_LCFERR_SenErrorToVeh_btf
#endif

#endif /* _LCFSNDSEN_COMMON_H_ */

