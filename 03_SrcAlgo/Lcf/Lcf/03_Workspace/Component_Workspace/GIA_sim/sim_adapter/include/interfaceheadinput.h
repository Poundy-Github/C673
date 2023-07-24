/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            interfaceheadinput.h

  DESCRIPTION:          Define different version of HEAD input interface

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: interfaceheadinput.h  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:25CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/include/project.pj
  CHANGES:              Revision 1.13 2016/11/16 14:04:32CET Dagli, Goekhan (uidj7850) 
  CHANGES:              + V7_D1
  CHANGES:              + V9_MI
  CHANGES:              Revision 1.12 2016/09/21 13:05:16CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + namespace HEADInputCustomV9
  CHANGES:              Revision 1.11 2016/09/14 13:47:37CEST Dagli-EXT, Goekhan (uidj7850) 
  CHANGES:              +V10 (Hyundayi)
  CHANGES:              Revision 1.10 2016/03/03 17:31:43CET Roedelsperger-EXT, Sabine (uidp2902) 
  CHANGES:              Added types for V9_GY (Geely)
  CHANGES:              Revision 1.9 2015/12/14 09:34:41CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              Update with V9 (actually V9a because only for ARS4D1 and ARS4D2)
  CHANGES:              Revision 1.8 2015/05/29 13:49:35CEST Diepolder, Thomas (diepoldert) 
  CHANGES:              Updated adapter to enable x-simulation D1/B0 D2/T0
  CHANGES:              - Added comments -  diepoldert [May 29, 2015 1:49:35 PM CEST]
  CHANGES:              Change Package : 343338:1 http://mks-psad:7002/im/viewissue?selection=343338
  CHANGES:              Revision 1.7 2014/07/22 19:18:31CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Revisions V7 and V8
  CHANGES:              --- Added comments ---  berndtt1 [Jul 25, 2014 8:38:23 AM CEST]
  CHANGES:              Change Package : 221167:21 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.6 2012/04/18 14:10:32CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Add head input custom v4b (long live the exponential complexity explosion of interfaces!)
  CHANGES:              --- Added comments ---  ungvaryg [Apr 18, 2012 2:10:33 PM CEST]
  CHANGES:              Change Package : 111577:1 http://mks-psad:7002/im/viewissue?selection=111577
  CHANGES:              Revision 1.5 2012/03/15 09:01:43CET Froehlich, Dominik01 (froehlichd1) 
  CHANGES:              * change: updated adapter to RTE change for FCM inhibit
  CHANGES:              --- Added comments ---  froehlichd1 [Mar 15, 2012 9:01:45 AM CET]
  CHANGES:              Change Package : 102796:3 http://mks-psad:7002/im/viewissue?selection=102796
  CHANGES:              Revision 1.4 2012/02/21 17:46:16CET Diepolder, Thomas (diepoldert) 
  CHANGES:              New adaptations for ars353 version 3 headinputcustom
  CHANGES:              --- Added comments ---  diepoldert [Feb 21, 2012 5:46:17 PM CET]
  CHANGES:              Change Package : 97173:1 http://mks-psad:7002/im/viewissue?selection=97173
  CHANGES:              Revision 1.3 2012/01/19 10:08:25CET Froehlich, Dominik01 (froehlichd1) 
  CHANGES:              * change: support of HEADInputCustom interface changes
  CHANGES:              --- Added comments ---  froehlichd1 [Jan 19, 2012 10:08:25 AM CET]
  CHANGES:              Change Package : 30337:8 http://mks-psad:7002/im/viewissue?selection=30337
  CHANGES:              Revision 1.2 2011/03/03 14:54:22CET Diepolder Thomas (diepoldert) (diepoldert) 
  CHANGES:              Fixed compilation error for ARS315, missing tpye ucCameraStatus_t added, since no defined in rte_type.h
  CHANGES:              --- Added comments ---  diepoldert [Mar 3, 2011 2:54:22 PM CET]
  CHANGES:              Change Package : 59660:2 http://mks-psad:7002/im/viewissue?selection=59660
  CHANGES:              Revision 1.1 2011/03/02 13:46:05CET Thomas Diepolder (diepoldert) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS301/06_Algorithm/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/include/project.pj

**************************************************************************** */
#ifndef INTERFACE_HEAD_INPUT_DATA_H
#define INTERFACE_HEAD_INPUT_DATA_H

typedef uint8 ucCameraObjectStatus_t;     /* Status of Camera Object enum { HEAD_CAMERA_OBJ_STATUS_NOT_OK=2,HEAD_CAMERA_OBJ_STATUS_TIMEOUT=3,HEAD_CAMERA_OBJ_STATUS_INIT=0,HEAD_CAMERA_OBJ_STATUS_OUT_OF_RANGE=4,HEAD_CAMERA_OBJ_STATUS_OK=1} */
typedef uint8 ucCameraStatus_t;           /* Camera Status @min: 0 @max:2 @values: enum { HEAD_CAMERA_AVAILABLE_TEMP_NO=2,HEAD_CAMERA_AVAILABLE_YES=1,HEAD_CAMERA_AVAILABLE_NO=0,} */
typedef uint8 eBuzzerState_t              /* @min: 0 @max:1 @values: enum { BUZZER_STATE_OK=0,BUZZER_STATE_INVALID=1,} */	/* [Satisfies_rte sws 1188] */;

namespace HEADInputCustomV1
{
  typedef struct
  {
    uint32  uiVersionNumber;                       /* The output data version number @min:0.0 @max:16277215.0 */
    uint8   CodingByte;                            /* ContiGuard Coding byte from EEPROM */
    boolean CodingByteValid;                       /* CodingByte information valid */
    ucCameraStatus_t ucCameraStatus;               /* Camera Status */
    ucCameraObjectStatus_t ucCameraObjectStatus;   /* Status of Camera Object Data */
  } HEADInputCustom_t;  /* Size: 8 byte */
}

namespace HEADInputCustomV2a
{
  typedef uint32 CodingParam_t;              /* ContiGuard Coding byte from EEPROM enum { HEAD_CODING_WARNING=1,HEAD_CODING_IGN_SCHK=64,HEAD_CODING_COUNTRY=8,HEAD_CODING_PRE_BRK=16,HEAD_CODING_LOW_SPEED=4,HEAD_CODING_STAT_OBJ=2,HEAD_CODING_BRK_COND=32,HEAD_CODING_PRE_BRK2=128,HEAD_CODING_MAX=2147483648} */

  typedef struct 
  {
    uint32 uiVersionNumber;                          /* The output data version number @min:0.0 @max:16277215.0 */
    CodingParam_t CodingParam;                       /* ContiGuard Coding byte from EEPROM */
    boolean CodingParamValid;                        /* CodingByte information valid */
    ucCameraStatus_t ucCameraStatus;                 /* Camera Status */
    ucCameraObjectStatus_t ucCameraObjectStatus;     /* Status of Camera Object Data */
  } HEADInputCustom_t;  /* Size: 12 byte */
}

namespace HEADInputCustomV2b {
  typedef uint32 CodingParam_t;              /* ContiGuard Coding byte from EEPROM enum { HEAD_CODING_WARNING=1,HEAD_CODING_IGN_SCHK=64,HEAD_CODING_COUNTRY=8,HEAD_CODING_PRE_BRK=16,HEAD_CODING_LOW_SPEED=4,HEAD_CODING_STAT_OBJ=2,HEAD_CODING_BRK_COND=32,HEAD_CODING_PRE_BRK2=128,HEAD_CODING_MAX=2147483648} */

  typedef uint8 FCMStateHist_t;              /* FCM State history enum { eFCMStateHist_Standby=1,eFCMStateHist_Off=0,} */
  typedef uint8 FCMTimingHist_t;             /* FCM Timing history enum { eFCMTimingHist_Near=1,eFCMTimingHist_Far=0,} */

	#ifndef   eFCMStateHist_Off
	  #define eFCMStateHist_Off	(0U)
	#endif
	#ifndef   eFCMStateHist_Standby
	  #define eFCMStateHist_Standby	(1U)
	#endif

	#ifndef   eFCMTimingHist_Far
	  #define eFCMTimingHist_Far	(0U)
	#endif
	#ifndef   eFCMTimingHist_Near
	  #define eFCMTimingHist_Near	(1U)
	#endif

  typedef struct
  {
    	boolean bFCMMainSwitch;                      /* FCM Main Switch Status */
    	FCMStateHist_t eFCMStateHist;                       /* FCM State History */
    	FCMTimingHist_t eFCMTimingHist;                      /* FCM Timing History */
    	boolean bFCMHistValid;                       /* FCM History Valid */
  } HEADInCMB_t;

  typedef struct 
  {
    uint32 uiVersionNumber;                          /* The output data version number @min:0.0 @max:16277215.0 */
    CodingParam_t CodingParam;                       /* ContiGuard Coding byte from EEPROM */
    boolean CodingParamValid;                        /* CodingByte information valid */
    ucCameraStatus_t ucCameraStatus;                 /* Camera Status */
    ucCameraObjectStatus_t ucCameraObjectStatus;     /* Status of Camera Object Data */
    HEADInCMB_t sCMBInput; 
  } HEADInputCustom_t;  /* Size: 12 byte */
}


namespace HEADInputCustomV3a
{
  typedef uint32 CodingParam_t;              /* ContiGuard Coding byte from EEPROM enum { HEAD_CODING_WARNING=1,HEAD_CODING_IGN_SCHK=64,HEAD_CODING_COUNTRY=8,HEAD_CODING_PRE_BRK=16,HEAD_CODING_LOW_SPEED=4,HEAD_CODING_STAT_OBJ=2,HEAD_CODING_BRK_COND=32,HEAD_CODING_PRE_BRK2=128,HEAD_CODING_MAX=2147483648} */

  typedef uint8 FCMStateHist_t;              /* FCM State history enum { eFCMStateHist_Standby=1,eFCMStateHist_Off=0,} */
  typedef uint8 FCMTimingHist_t;             /* FCM Timing history enum { eFCMTimingHist_Near=1,eFCMTimingHist_Far=0,} */

	#ifndef   eFCMStateHist_Off
	  #define eFCMStateHist_Off	(0U)
	#endif
	#ifndef   eFCMStateHist_Standby
	  #define eFCMStateHist_Standby	(1U)
	#endif

	#ifndef   eFCMTimingHist_Far
	  #define eFCMTimingHist_Far	(0U)
	#endif
	#ifndef   eFCMTimingHist_Near
	  #define eFCMTimingHist_Near	(1U)
	#endif

  typedef struct
  {
    	boolean bFCMMainSwitch;                      /* FCM Main Switch Status */
    	FCMStateHist_t eFCMStateHist;                       /* FCM State History */
    	FCMTimingHist_t eFCMTimingHist;                      /* FCM Timing History */
    	boolean bFCMHistValid;                       /* FCM History Valid */
    	boolean bFCMShiftPos;                        /* FCM Shift Pos */
  } HEADInCMB_t;

  typedef struct 			
  {
    	uint32 uiVersionNumber;                     /* The output data version number @min:0.0 @max:16277215.0 */
    	CodingParam_t CodingParam;                         /* ContiGuard Coding byte from EEPROM */
    	boolean CodingParamValid;                    /* CodingByte information valid */
    	ucCameraStatus_t ucCameraStatus;                      /* Camera Status */
    	ucCameraObjectStatus_t ucCameraObjectStatus;                /* Status of Camera Object Data */
    	HEADInCMB_t sCMBInput;                           
  } HEADInputCustom_t;			
}

namespace HEADInputCustomV3b
{
  typedef uint32 CodingParam_t;              /* ContiGuard Coding byte from EEPROM enum { HEAD_CODING_WARNING=1,HEAD_CODING_IGN_SCHK=64,HEAD_CODING_COUNTRY=8,HEAD_CODING_PRE_BRK=16,HEAD_CODING_LOW_SPEED=4,HEAD_CODING_STAT_OBJ=2,HEAD_CODING_BRK_COND=32,HEAD_CODING_PRE_BRK2=128,HEAD_CODING_MAX=2147483648} */

  typedef struct 
  {
    uint32 uiVersionNumber;                          /* The output data version number @min:0.0 @max:16277215.0 */
    CodingParam_t CodingParam;                       /* ContiGuard Coding byte from EEPROM */
    boolean CodingParamValid;                        /* CodingByte information valid */
    ucCameraStatus_t ucCameraStatus;                 /* Camera Status */
    ucCameraObjectStatus_t ucCameraObjectStatus;     /* Status of Camera Object Data */
  } HEADInputCustom_t;  /* Size: 12 byte */
}

namespace HEADInputCustomV4a {
  typedef uint32 CodingParam_t;              /* ContiGuard Coding byte from EEPROM enum { HEAD_CODING_WARNING=1,HEAD_CODING_IGN_SCHK=64,HEAD_CODING_COUNTRY=8,HEAD_CODING_PRE_BRK=16,HEAD_CODING_LOW_SPEED=4,HEAD_CODING_STAT_OBJ=2,HEAD_CODING_BRK_COND=32,HEAD_CODING_PRE_BRK2=128,HEAD_CODING_MAX=2147483648} */

  typedef uint8 FCMStateHist_t;              /* FCM State history enum { eFCMStateHist_Standby=1,eFCMStateHist_Off=0,} */
  typedef uint8 FCMTimingHist_t;             /* FCM Timing history enum { eFCMTimingHist_Near=1,eFCMTimingHist_Far=0,} */

	#ifndef   eFCMStateHist_Off
	  #define eFCMStateHist_Off	(0U)
	#endif
	#ifndef   eFCMStateHist_Standby
	  #define eFCMStateHist_Standby	(1U)
	#endif

	#ifndef   eFCMTimingHist_Far
	  #define eFCMTimingHist_Far	(0U)
	#endif
	#ifndef   eFCMTimingHist_Near
	  #define eFCMTimingHist_Near	(1U)
	#endif

  typedef struct
  {
    	boolean bFCMMainSwitch;                      /* FCM Main Switch Status */
    	FCMStateHist_t eFCMStateHist;                       /* FCM State History */
    	FCMTimingHist_t eFCMTimingHist;                      /* FCM Timing History */
    	boolean bFCMHistValid;                       /* FCM History Valid */
    	boolean bFCMShiftPos;                        /* FCM Shift Pos */
      boolean bFCMSysSilentInhibit;                /* FCM Silent Inhibit */ 
  } HEADInCMB_t;

  typedef struct 			
  {
    	uint32 uiVersionNumber;                     /* The output data version number @min:0.0 @max:16277215.0 */
    	CodingParam_t CodingParam;                         /* ContiGuard Coding byte from EEPROM */
    	boolean CodingParamValid;                    /* CodingByte information valid */
    	ucCameraStatus_t ucCameraStatus;                      /* Camera Status */
    	ucCameraObjectStatus_t ucCameraObjectStatus;                /* Status of Camera Object Data */
    	HEADInCMB_t sCMBInput;                           
  } HEADInputCustom_t;			
};


namespace HEADInputCustomV4b
{
  typedef uint32 CodingParam_t;              /* ContiGuard Coding byte from EEPROM enum { HEAD_CODING_WARNING=1,HEAD_CODING_IGN_SCHK=64,HEAD_CODING_COUNTRY=8,HEAD_CODING_PRE_BRK=16,HEAD_CODING_LOW_SPEED=4,HEAD_CODING_STAT_OBJ=2,HEAD_CODING_BRK_COND=32,HEAD_CODING_PRE_BRK2=128,HEAD_CODING_MAX=2147483648} */

  typedef struct
  {
    uint32 uiVersionNumber;                     /* The output data version number @min:0.0 @max:16277215.0 */
    CodingParam_t CodingParam;                         /* ContiGuard Coding byte from EEPROM */
    boolean CodingParamValid;                    /* CodingByte information valid */
    ucCameraStatus_t ucCameraStatus;                      /* Camera Status */
    ucCameraObjectStatus_t ucCameraObjectStatus;                /* Status of Camera Object Data */
  } HEADInputCustom_t;
};


namespace HEADInputCustomV7
{
  typedef unsigned long CodingParam_t             /* ContiGuard Coding byte from EEPROM @min: 1 @max:2147483648 @values: enum { HEAD_CODING_PED_WARN=1024,HEAD_CODING_IGN_SCHK=8,HEAD_CODING_COUNTRY=4,HEAD_CODING_PED_BRAKE=2048,HEAD_CODING_DEBUGMESSAGES=32,HEAD_CODING_OBJMOVE_BRAKE=32768,HEAD_CODING_MAX=2147483648,HEAD_CODING_IGNORE_ACT_SWITCH=128,HEAD_CODING_OBJSTAT_WARN=4096,HEAD_CODING_LOW_SPEED=2,HEAD_CODING_PED_PRECRASH=65536,HEAD_CODING_VCL_PRECRASH=524288,HEAD_CODING_OBJMOVE_PRECRASH=131072,HEAD_CODING_STAT_OBJ=1,HEAD_CODING_NO_FAILUREHANDLING=16,HEAD_CODING_OBJMOVE_WARN=16384,HEAD_CODING_OBJSTAT_PRECRASH=262144,HEAD_CODING_DISTANCELIMIT=64,HEAD_CODING_OBJSTAT_BRAKE=8192,HEAD_CODING_VEHICLES_BRAKE=512,HEAD_CODING_VEHICLES_WARN=256,} */	/* [Satisfies_rte sws 1188] */;

  typedef unsigned short AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned long AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;
  
  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;			/* Common header for all structured data types */
  
  typedef struct
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    CodingParam_t CodingParam;
    boolean CodingParamValid;
    ucCameraStatus_t ucCameraStatus;
    ucCameraObjectStatus_t ucCameraObjectStatus;
  } HEADInputCustom_t;
};

namespace HEADInputCustomV7_D1
{
  typedef unsigned long CodingParam_t             /* ContiGuard Coding byte from EEPROM @min: 1 @max:2147483648 @values: enum { HEAD_CODING_PED_WARN=1024,HEAD_CODING_IGN_SCHK=8,HEAD_CODING_COUNTRY=4,HEAD_CODING_PED_BRAKE=2048,HEAD_CODING_DEBUGMESSAGES=32,HEAD_CODING_OBJMOVE_BRAKE=32768,HEAD_CODING_MAX=2147483648,HEAD_CODING_IGNORE_ACT_SWITCH=128,HEAD_CODING_OBJSTAT_WARN=4096,HEAD_CODING_LOW_SPEED=2,HEAD_CODING_PED_PRECRASH=65536,HEAD_CODING_VCL_PRECRASH=524288,HEAD_CODING_OBJMOVE_PRECRASH=131072,HEAD_CODING_STAT_OBJ=1,HEAD_CODING_NO_FAILUREHANDLING=16,HEAD_CODING_OBJMOVE_WARN=16384,HEAD_CODING_OBJSTAT_PRECRASH=262144,HEAD_CODING_DISTANCELIMIT=64,HEAD_CODING_OBJSTAT_BRAKE=8192,HEAD_CODING_VEHICLES_BRAKE=512,HEAD_CODING_VEHICLES_WARN=256,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char SpeedUnitEnum_t;

  static const SpeedUnitEnum_t SPD_UNIT_KMH = 0U;
  static const SpeedUnitEnum_t SPD_UNIT_MPH = 1U;

  typedef struct
  {
    SpeedUnitEnum_t eSpeedometerUnit;
    float fSpeedometerSpeed;
  } sSpeedometerInput_t;

  typedef struct
  {
    unsigned long uiVersionNumber;
    HEADInputCustomV7::SignalHeader_t sSigHeader;
    CodingParam_t CodingParam;
    boolean CodingParamValid;
    sSpeedometerInput_t sSpeedometerInput;
  } HEADInputCustom_t;
};

namespace HEADInputCustomV8
{
  typedef struct
  {
    unsigned long uiVersionNumber;
    HEADInputCustomV7::SignalHeader_t sSigHeader;
    ucCameraStatus_t ucCameraStatus;
    ucCameraObjectStatus_t ucCameraObjectStatus;
  } HEADInputCustom_t;
};

namespace HEADInputCustomV8a
{
  typedef unsigned char SpeedUnitEnum_t;

  static const SpeedUnitEnum_t SPD_UNIT_KMH = 0U;
  static const SpeedUnitEnum_t SPD_UNIT_MPH = 1U;

  typedef struct
  {
    SpeedUnitEnum_t eSpeedometerUnit;
    float fSpeedometerSpeed;
  } sSpeedometerInput_t;

  typedef struct  
  {
    unsigned long uiVersionNumber;
    HEADInputCustomV7::SignalHeader_t sSigHeader;
    sSpeedometerInput_t sSpeedometerInput;
  } HEADInputCustom_t;
};

namespace HEADInputCustomV9
{
  typedef struct
  {
    unsigned long uiVersionNumber;
    HEADInputCustomV7::SignalHeader_t sSigHeader;
    ucCameraStatus_t ucCameraStatus;
    ucCameraObjectStatus_t ucCameraObjectStatus;
  } HEADInputCustom_t;
};

namespace HEADInputCustomV9_GY																				// Only for Geely
{
  typedef struct
  {
    unsigned long uiVersionNumber;
    HEADInputCustomV7::SignalHeader_t sSigHeader;
    ucCameraStatus_t ucCameraStatus;
    ucCameraObjectStatus_t ucCameraObjectStatus;
		eBuzzerState_t eBuzzerState;
  } HEADInputCustom_t;
};

namespace HEADInputCustomV9a                                         // Only for ARS4D1 and ARS4D2 !
{
  typedef struct
  {
    boolean bVehStopCoordActive;
  } sExtVehicleSystems_t;

  typedef struct
  {
    unsigned long uiVersionNumber;
    HEADInputCustomV7::SignalHeader_t sSigHeader;
    HEADInputCustomV8a::sSpeedometerInput_t sSpeedometerInput;
    sExtVehicleSystems_t sExtVehicleSystems;
  } HEADInputCustom_t;
};

namespace HEADInputCustomV9_MI                                       // Only for ARS430MI18
{
  typedef unsigned long FCMStateHist_t               /* FCM State History @min: None @max:None */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned long FCMTimingHist_t              /* FCM Timing History @min: None @max:None */	/* [Satisfies_rte sws 1188] */;
  typedef struct
  {
    	boolean bFCMMainSwitch;                      /* FCM Main Switch Status */
    	FCMStateHist_t eFCMStateHist;                /* FCM State History */
    	FCMTimingHist_t eFCMTimingHist;              /* FCM Timing History */
    	boolean bFCMHistValid;                       /* FCM History Valid */
    	boolean bFCMShiftPos;                        /* FCM Shift Pos */
      boolean bFCMSysSilentInhibit;                  /* FCM Silent Inhibit */ 
  } HEADInCMB_t;
  typedef struct
  {
    unsigned long uiVersionNumber;
    HEADInputCustomV7::SignalHeader_t sSigHeader;
    HEADInCMB_t sCMBInput;
    HEADInputCustomV8a::sSpeedometerInput_t sSpeedometerInput;
    HEADInputCustomV9a::sExtVehicleSystems_t sExtVehicleSystems;
  } HEADInputCustom_t;
};

namespace HEADInputCustomV10
{
  typedef uint8 FCTSubChainQualifier_t;
  typedef uint8 SpeedUnitEnum_t;

  typedef struct
  {
    SpeedUnitEnum_t eSpeedometerUnit;
    float fSpeedometerSpeed;
  } sSpeedometerInput_t;

  typedef HEADInputCustomV9a::sExtVehicleSystems_t sExtVehicleSystems_t;

  typedef struct
  {
    unsigned long uiVersionNumber;
 	  HEADInputCustomV7::SignalHeader_t sSigHeader;
 	  FCTSubChainQualifier_t eQualifierBrakeChain;
 	  FCTSubChainQualifier_t eQualifierWarnChain;
 	  FCTSubChainQualifier_t eQualifierPrefill;
 	  FCTSubChainQualifier_t eQualifierHBA;
 	  eBuzzerState_t eBuzzerState;
 	  sSpeedometerInput_t sSpeedometerInput;
 	  sExtVehicleSystems_t sExtVehicleSystems;
  } HEADInputCustom_t;
};

namespace HEADInputCustomV10_2
{
  typedef uint8 FCTSubChainQualifier_t;

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
	  HEADInputCustomV7::SignalHeader_t sSigHeader;
	  FCTSubChainQualifier_t eQualifierBrakeChain;
	  FCTSubChainQualifier_t eQualifierWarnChain;
	  FCTSubChainQualifier_t eQualifierPrefill;
	  FCTSubChainQualifier_t eQualifierHBA;
  } HEADInputCustom_t;
};


#endif /* INTERFACE_HEAD_INPUT_DATA_H */