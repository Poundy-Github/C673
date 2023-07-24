	/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Lcf

  MODULNAME:                 LCFSNDSEN_custom.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.2 $


  ---*/ /*--- 
  CHANGES:                   

**************************************************************************** */

#ifndef LCFSNDSEN_CUSTOM_H_
#define LCFSNDSEN_CUSTOM_H_

/*---------------------------------------------------------*
   I N C L U D E S
**---------------------------------------------------------*/

/*---------------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**---------------------------------------------------------*/

extern void LCFSND_SenCustomReset(void);
extern void LCFSND_SenCustomProcess(void);


/*---------------------------------------------------------*
   M A C R O S
 *---------------------------------------------------------*/
 
/* Custom mapping of the HMI signals(the commented signals are not available in the specific HMI) -----------*/
//#ifndef	S_HMIOC_LdwsLHWarning_bool
//#define	S_HMIOC_LdwsLHWarning_bool             GET_S_HMODFL_HapticWrnReqLeft_bool()
//#define	GET_S_HMIOC_LdwsLHWarning_bool()	   S_HMIOC_LdwsLHWarning_bool
//#endif

//#ifndef	S_HMIOC_LdwsRHWarning_bool
//#define	S_HMIOC_LdwsRHWarning_bool	        GET_S_HMODFL_HapticWrnReqRight_bool()
//#define	GET_S_HMIOC_LdwsRHWarning_bool()	S_HMIOC_LdwsRHWarning_bool
//#endif

//#ifndef	S_HMIOC_HaptWrnReqLeft_bool
//#define	S_HMIOC_HaptWrnReqLeft_bool	        GET_S_HMODFL_HapticWrnReqLeft_bool()
//#define	GET_S_HMIOC_HaptWrnReqLeft_bool()   S_HMIOC_HaptWrnReqLeft_bool
//#endif

//#ifndef	S_HMIOC_HaptWrnReqRight_bool
//#define	S_HMIOC_HaptWrnReqRight_bool	    GET_S_HMODFL_HapticWrnReqRight_bool()
//#define	GET_S_HMIOC_HaptWrnReqRight_bool()	S_HMIOC_HaptWrnReqRight_bool
//#endif

//#ifndef	S_HMIOC_HaptWrnReqCommon_bool
//#define S_HMIOC_HaptWrnReqCommon_bool         GET_S_HMODFL_HapticWrnReqCommon_bool()
//#define GET_S_HMIOC_HaptWrnReqCommon_bool()   S_HMIOC_HaptWrnReqCommon_bool 	
//#endif

//#ifndef	S_HMIOC_VisWrnReqLeft_bool
//#define S_HMIOC_VisWrnReqLeft_bool         GET_S_HMODFL_VisualWrnReqLeft_bool()	
//#define GET_S_HMIOC_VisWrnReqLeft_bool()   S_HMIOC_VisWrnReqLeft_bool
//#endif

//#ifndef	S_HMIOC_VisWrnReqRight_bool
//#define S_HMIOC_VisWrnReqRight_bool         GET_S_HMODFL_VisualWrnReqRight_bool()	
//#define GET_S_HMIOC_VisWrnReqRight_bool()   S_HMIOC_VisWrnReqRight_bool	
//#endif

//#ifndef	S_HMIOC_VisWrnReqCommon_bool
//#define S_HMIOC_VisWrnReqCommon_bool        GET_S_HMODFL_VisualWrnReqCommon_bool()	
//#define GET_S_HMIOC_VisWrnReqCommon_bool()  S_HMIOC_VisWrnReqCommon_bool	
//#endif

/* RO 782008 */
#ifndef	S_HMIOC_AvailableFunction_btf
#define S_HMIOC_AvailableFunction_btf        GET_S_HMODFL_AvailableFunction_btf()
#define GET_S_HMIOC_AvailableFunction_btf()  S_HMIOC_AvailableFunction_btf	
#endif

#ifndef	S_HMIOC_ActFctLevel_nu
#define S_HMIOC_ActFctLevel_nu  (1u)
#define	GET_S_HMIOC_ActFctLevel_nu() S_HMIOC_ActFctLevel_nu  
#endif


//#ifndef	S_HMIOC_AcWrnReqLeft_bool
//#define S_HMIOC_AcWrnReqLeft_bool         GET_S_HMODFL_AcousticWrnReqLeft_bool()
//#define GET_S_HMIOC_AcWrnReqLeft_bool()   S_HMIOC_AcWrnReqLeft_bool	
//#endif

//#ifndef	S_HMIOC_AcWrnReqRight_bool
//#define S_HMIOC_AcWrnReqRight_bool        GET_S_HMODFL_AcousticWrnReqRight_bool()
//#define GET_S_HMIOC_AcWrnReqRight_bool()  S_HMIOC_AcWrnReqRight_bool
//#endif

//#ifndef	S_HMIOC_HandsOffSysWarning_nu
//#define S_HMIOC_HandsOffSysWarning_nu        (0)
//#define GET_S_HMIOC_HandsOffSysWarning_nu()  S_HMIOC_HandsOffSysWarning_nu //TODO: GET_S_HMODFL_HandsOffSysWarning_bool(); not yet available
//#endif

//#ifndef	S_HMIOC_DFFunctActiveState_btf
//#define	S_HMIOC_DFFunctActiveState_btf          GET_S_HMODFL_DFFunctActiveState_btf()
//#define	GET_S_HMIOC_DFFunctActiveState_btf()	S_HMIOC_DFFunctActiveState_btf
//#endif

//#ifndef	S_HMIOC_LnBndLeValid4Fct_btf
//#define	S_HMIOC_LnBndLeValid4Fct_btf	    GET_S_HMODFL_LnBndLeValid4Fct_btf()
//#define	GET_S_HMIOC_LnBndLeValid4Fct_btf()	S_HMIOC_LnBndLeValid4Fct_btf
//#endif

//#ifndef	S_HMIOC_LnBndRiValid4Fct_btf
//#define	S_HMIOC_LnBndRiValid4Fct_btf	    GET_S_HMODFL_LnBndRiValid4Fct_btf()
//#define	GET_S_HMIOC_LnBndRiValid4Fct_btf()	S_HMIOC_LnBndRiValid4Fct_btf
//#endif

//#ifndef	S_HMIOC_DispLaneLeftDetected_nu
//#define	S_HMIOC_DispLaneLeftDetected_nu	        GET_S_HMODFL_DispLeLnDtct_nu()
//#define	GET_S_HMIOC_DispLaneLeftDetected_nu()	S_HMIOC_DispLaneLeftDetected_nu
//#endif

//#ifndef	S_HMIOC_DispLaneRightDetected_nu
//#define	S_HMIOC_DispLaneRightDetected_nu        GET_S_HMODFL_DispRiLnDtct_nu()
//#define	GET_S_HMIOC_DispLaneRightDetected_nu()	S_HMIOC_DispLaneRightDetected_nu
//#endif

/* END Custom mapping of the HMI signals -----------*/

#endif /* _LCFSNDSEN_CUSTOM_H_ */
