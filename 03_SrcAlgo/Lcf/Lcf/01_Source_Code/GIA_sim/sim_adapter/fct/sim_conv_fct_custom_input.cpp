/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_fct_custom_input.cpp

  DESCRIPTION:          

  AUTHOR:               Gergely Ungvary

  CREATION DATE:        16.06.2010

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_fct_custom_input.cpp  $
  CHANGES:              Revision 1.1 2021/12/13 17:20:59CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:15:16CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.17 2016/11/16 14:05:02CET Dagli, Goekhan (uidj7850) 
  CHANGES:              + V17
  CHANGES:              Revision 1.16 2016/10/26 17:01:09CEST Dagli-EXT, Goekhan (uidj7850) 
  CHANGES:              + V19
  CHANGES:              Revision 1.15 2016/06/29 12:25:25CEST Dagli-EXT, Goekhan (uidj7850) 
  CHANGES:              +V14 (same as V7)
  CHANGES:              Revision 1.14 2016/03/16 16:13:12CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + V12 for ARS4L0 (Converts from V7 and V11 for ARS4L0)
  CHANGES:              Revision 1.13 2016/02/03 14:33:23CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + V13
  CHANGES:              Revision 1.12 2016/01/22 10:16:32CET Dagli-EXT, Goekhan (uidj7850) 
  CHANGES:              - added V9
  CHANGES:              - added conversion from V11/V11D1 to V7/V9
  CHANGES:              Revision 1.11 2015/07/02 15:28:07CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Conversion V6 and V7 to V11. Actually V11d1 for BMW to Daimler Conversions
  CHANGES:              - Added comments -  berndtt1 [Jul 2, 2015 3:38:50 PM CEST]
  CHANGES:              Change Package : 221167:45 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.10 2015/04/20 10:26:43CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Begin of V11
  CHANGES:              --- Added comments ---  berndtt1 [May 7, 2015 10:29:47 AM CEST]
  CHANGES:              Change Package : 335739:1 http://mks-psad:7002/im/viewissue?selection=335739
  CHANGES:              Revision 1.9 2013/05/21 18:04:26CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Modify for ARS4xx 'big' adapter: remove class declarations and complex includes from individual headers (only leaving factory
  CHANGES:              function external declaration there), moving class declaration and all additional includes into cpp file. Add single factory function
  CHANGES:              per data conversion stream.
  CHANGES:              Note: otherwise no functional changes made, thus the new revisions perform the exact same conversions (ARS3xx) as previously
  CHANGES:              --- Added comments ---  ungvaryg [May 21, 2013 6:04:26 PM CEST]
  CHANGES:              Change Package : 172401:1 http://mks-psad:7002/im/viewissue?selection=172401
  CHANGES:              Revision 1.8 2012/06/25 14:14:30CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Add support for version 6 of FCT custom input (addition of Eco-pro flag to FCT custom input)
  CHANGES:              --- Added comments ---  ungvaryg [Jun 25, 2012 2:14:36 PM CEST]
  CHANGES:              Change Package : 125668:1 http://mks-psad:7002/im/viewissue?selection=125668
  CHANGES:              Revision 1.7 2012/04/11 12:07:29CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Added versions 4 and 5 of FCT_CUSTOM_INPUT_INTFVER, which are identical to versions 2 and 3
  CHANGES:              --- Added comments ---  berndtt1 [Apr 11, 2012 12:13:38 PM CEST]
  CHANGES:              Change Package : 105371:5 http://mks-psad:7002/im/viewissue?selection=105371
  CHANGES:              Revision 1.6 2012/02/16 16:41:55CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + version 3 (same as version 2)
  CHANGES:              --- Added comments ---  berndtt1 [Feb 16, 2012 4:44:19 PM CET]
  CHANGES:              Change Package : 97762:2 http://mks-psad:7002/im/viewissue?selection=97762
  CHANGES:              Revision 1.5 2011/02/28 16:25:15CET Ungvary, Gergely (ungvaryg) 
  CHANGES:              Fix compilation issue
  CHANGES:              --- Added comments ---  ungvaryg [Feb 28, 2011 4:25:16 PM CET]
  CHANGES:              Change Package : 59406:1 http://mks-psad:7002/im/viewissue?selection=59406
  CHANGES:              Revision 1.4 2011/02/28 15:48:35CET Gergely Ungvary (ungvaryg) 
  CHANGES:              Update to allow conversion version 1 and 2 of FCTCustomInput
  CHANGES:              --- Added comments ---  ungvaryg [Feb 28, 2011 3:48:35 PM CET]
  CHANGES:              Change Package : 59406:1 http://mks-psad:7002/im/viewissue?selection=59406
  CHANGES:              Revision 1.3 2011/02/14 18:06:15CET Gergely Ungvary (ungvaryg) 
  CHANGES:              Remove dependence on CDataBuffer class - replace with object member buffer directly of given type
  CHANGES:              Revision 1.2 2010/08/09 09:31:53CEST Gergely Ungvary (ungvaryg) 
  CHANGES:              Add conversion accepting 1-1 bytewise copy of FCT Custom Input structure
  CHANGES:              Revision 1.1 2010/06/16 15:35:56CEST gungvary 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS301/06_Algorithm/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */ 
#include "stdafx.h"
#include "sim_conv_fct_custom_input.h"
#include "sim_versioninfo_impl.h"

// Conversion from 32-bit integer to tupple of major, minor, sub version tupple (triple)
#define CONV_I32VERSION_TO_TUPPLE(x)   (unsigned char)(((x) >> 16) & 0xFF), (unsigned char)(((x) >> 8) & 0xFF), (unsigned char)((x) & 0xFF)

#ifndef FSRFunctionInit
/* typedef eLongControlStatus_t eLongControlStatus_t; already defined */
typedef enum eLongControlStatusEnum_t {
  FSRFunctionInit,
  FSRFunctionDisabled,
  FSRFunctionEnabledHold,
  FSRFunctionEnabled,
} eLongControlStatusEnum_t;
#endif

namespace FCTCustomInputV1
{
  // Define autosar type aliases and known layouts here
  typedef unsigned __int8 uint8;
  typedef unsigned __int32 uint32;

  typedef uint8 eLongControlStatus_t                                           /* Type definition for the longitudional control status @min: 0 @max:3 @values: enum { FSRFunctionInit=0,FSRFunctionEnabledHold=2,FSRFunctionDisabled=1,FSRFunctionEnabled=3,} */ /* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    uint8 uiProbabilityLaneChangeLeft;                                         /* @min:0.0 @max:100.0 */
    uint8 uiProbabilityLaneChangeRight;                                        /* @min:0.0 @max:100.0 */
  } SIProbabilityLaneChange_t;                                                 /* @cycleid:FCT_ENV */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    eLongControlStatus_t eLongControlStatus;                  /* Type definition for the longitudional control status */
    uint8 uiSelectedObject;                    /* selected object @min:0.0 @max:63.0 */
  } sLongControlStatus_t;			/* @cycleid:FCT_ENV */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    uint32 uiVersionNumber;                     /* The output data version number @min:0.0 @max:16277215.0 */
    SIProbabilityLaneChange_t sProbabilityLaneChange;              /* @cycleid:FCT_ENV @cycleid:FCT_ENV */
    sLongControlStatus_t sLongControlStatus;                  /* @cycleid:FCT_ENV @cycleid:FCT_ENV */
  } FCTCustomInput_t;			/* Custom Inputs for functional requirements @vaddr:FCT_MEAS_ID_CUSTOM_INPUT @cycleid:FCT_ENV @vname:FCTCustomInputData */

};  // End of namespace FCTCustomInputV1

namespace FCTCustomInputV2
{
  typedef uint32 CodingValue_t              /* @min: 1 @max:2147483648 @values: enum { FCT_CODING_STAT_OBJ=2,FCT_CODING_IGN_SCHK=64,FCT_CODING_WARNING=1,FCT_CODING_COUNTRY=8,FCT_CODING_BRK_COND=32,FCT_CODING_PRE_BRK=16,FCT_CODING_LOW_SPEED=4,FCT_CODING_MAX=2147483648,FCT_CODING_PRE_BRK2=128,} */			/* [Satisfies_rte sws 1182], [Satisfies_rte sws 1265] */;

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    CodingValue_t CodingValue;
    boolean Valid;
  } CodingPar_t;			/* Coding byte form nv memory */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    uint32 uiVersionNumber;                     /* The output data version number @min:0.0 @max:16277215.0 */
    FCTCustomInputV1::SIProbabilityLaneChange_t sProbabilityLaneChange;              /* @cycleid:FCT_ENV @cycleid:FCT_ENV */
    FCTCustomInputV1::sLongControlStatus_t sLongControlStatus;                  /* @cycleid:FCT_ENV @cycleid:FCT_ENV */
    CodingPar_t CodingPar;                           /* Coding byte form nv memory */
  } FCTCustomInput_t;			/* Custom Inputs for functional requirements @vaddr:FCT_MEAS_ID_CUSTOM_INPUT @cycleid:FCT_ENV @vname:FCTCustomInputData */

};  // End of namespace FCTCustomInputV2

namespace FCTCustomInputV6
{
  typedef enum
  {
    FSRNormalMode,
    FSREcoMode
  } eEcoModeValues_t;

  typedef uint8 eEcoMode_t;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    FCTCustomInputV1::eLongControlStatus_t eLongControlStatus;                 /* Type definition for the longitudional control status */
    uint8 uiSelectedObject;                                                    /* selected object @min:0.0 @max:63.0 */
    eEcoMode_t eEcoMode;                                                       /* New in V6 : Eco mode */
  } sLongControlStatus_t;                                                      /* @cycleid:FCT_ENV */

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    uint32 uiVersionNumber;                                                    /* The output data version number @min:0.0 @max:16277215.0 */
    FCTCustomInputV1::SIProbabilityLaneChange_t sProbabilityLaneChange;        /* @cycleid:FCT_ENV @cycleid:FCT_ENV */
    sLongControlStatus_t sLongControlStatus;                                   /* @cycleid:FCT_ENV @cycleid:FCT_ENV */
    FCTCustomInputV2::CodingPar_t CodingPar;                                   /* Coding byte form nv memory */
  } FCTCustomInput_t;                                                          /* Custom Inputs for functional requirements @vaddr:FCT_MEAS_ID_CUSTOM_INPUT @cycleid:FCT_ENV @vname:FCTCustomInputData */
}; // FCTCustomInputV6

namespace FCTCustomInputV7
{
  typedef unsigned short AlgoCycleCounter_t                                    /* Algo cycle counter @min:0 @max:65535 */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned long AlgoDataTimeStamp_t                                    /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char AlgoSignalState_t                                      /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char eTurnIndicator_t                                       /* turn indicator information @min: 0 @max:4 @values: enum { eTurnIndicator_Right=2,eTurnIndicator_Invalid=4,eTurnIndicator_Left=1,eTurnIndicator_Off=0,eTurnIndicator_Both=3,} */ /* [Satisfies_rte sws 1188] */;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;                                                            /* Common header for all structured data types */

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;                                             /* The output data version number @min:0.0 @max:16277215.0 */
    SignalHeader_t sSigHeader;
    FCTCustomInputV1::SIProbabilityLaneChange_t sProbabilityLaneChange;        /* @cycleid:FCT_ENV @cycleid:FCT_ENV */
    FCTCustomInputV6::sLongControlStatus_t sLongControlStatus;                 /* @cycleid:FCT_ENV @cycleid:FCT_ENV */
    FCTCustomInputV2::CodingPar_t CodingPar;                                   /* Coding byte form nv memory */
    eTurnIndicator_t eTurnIndicator;
  } FCTCustomInput_t;                                                          /* Custom Inputs for functional requirements @vaddr:FCT_MEAS_ID_CUSTOM_INPUT @cycleid:FCT_ENV @vname:FCTCustomInputData */
}; // FCTCustomInputV7

namespace FCTCustomInputV7l0
{
  typedef unsigned char eLongControlStatus_t                                   /* Type definition for the longitudional control status @min: 0 @max:3 @values: enum { FSRFunctionInit=0,FSRFunctionEnabledHold=2,FSRFunctionDisabled=1,FSRFunctionEnabled=3,} */ /* [Satisfies_rte sws 1188] */;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    eLongControlStatus_t eLongControlStatus;                                   /* Type definition for the longitudional control status */
  } sLongControlStatus_t;                                                      /* @cycleid:FCT_ENV */

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    FCTCustomInputV7::SignalHeader_t sSigHeader;
    sLongControlStatus_t sLongControlStatus;
    FCTCustomInputV7::eTurnIndicator_t eTurnIndicator;
  } FCTCustomInput_t;                                                          /* Custom Inputs for functional requirements @vaddr:FCT_MEAS_ID_CUSTOM_INPUT @cycleid:FCT_ENV @vname:FCTCustomInputData */
}; // FCTCustomInputV7l0


namespace FCTCustomInputV11
{
  typedef unsigned char eLongControlStatus_t                                   /* Type definition for the longitudional control status @min: 0 @max:3 @values: enum { FSRFunctionInit=0,FSRFunctionEnabledHold=2,FSRFunctionDisabled=1,FSRFunctionEnabled=3,} */ /* [Satisfies_rte sws 1188] */;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    eLongControlStatus_t eLongControlStatus;                                   /* Type definition for the longitudional control status */
  } sLongControlStatus_t;                                                      /* @cycleid:FCT_ENV */

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    FCTCustomInputV7::SignalHeader_t sSigHeader;
    sLongControlStatus_t sLongControlStatus;
    FCTCustomInputV7::eTurnIndicator_t eTurnIndicator;
  } FCTCustomInput_t;                                                          /* Custom Inputs for functional requirements @vaddr:0x202B0000 @vaddr_defs: FCT_MEAS_ID_CUSTOM_INPUT @cycleid:FCT_ENV @vname:FCTCustomInputData */
}; // FCTCustomInputV11

namespace FCTCustomInputV11l0
{
  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    FCTCustomInputV7::SignalHeader_t sSigHeader;
    FCTCustomInputV7l0::sLongControlStatus_t sLongControlStatus;
    FCTCustomInputV7::eTurnIndicator_t eTurnIndicator;
  } FCTCustomInput_t;                                                          /* Custom Inputs for functional requirements @vaddr:0x202B0000 @vaddr_defs: FCT_MEAS_ID_CUSTOM_INPUT @cycleid:FCT_ENV @vname:FCTCustomInputData */
}; // FCTCustomInputV11l0

namespace FCTCustomInputV11d1
{
  typedef unsigned char FCTVehDPCMdASRq_t                                      /* Driving program control: assistance system mode request @min: 1 @max:5 @values: enum { ECO=5,COMFORT=1,SPORT=3,SPORT_PLUS=4,COMFORT_PLUS=2,} */ /* [Satisfies_rte sws 1188] */;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    FCTCustomInputV11::eLongControlStatus_t eLongControlStatus;                /* Type definition for the longitudional control status */
    FCTVehDPCMdASRq_t DPC_Md_AS_Rq;
  } sLongControlStatus_t;                                                      /* @cycleid:FCT_ENV */

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    FCTCustomInputV7::SignalHeader_t sSigHeader;
    sLongControlStatus_t sLongControlStatus;
    FCTCustomInputV7::eTurnIndicator_t eTurnIndicator;
  } FCTCustomInput_t;                                                          /* Custom Inputs for functional requirements @vaddr:0x202B0000 @vaddr_defs: FCT_MEAS_ID_CUSTOM_INPUT @cycleid:FCT_ENV @vname:FCTCustomInputData */
}; // FCTCustomInputV11d1

namespace FCTCustomInputV12l0
{
  typedef unsigned char FCTVehDPCMdASRq_t                                      /* Driving program control: assistance system mode request @min: 1 @max:5 @values: enum { ECO=5,COMFORT=1,SPORT=3,SPORT_PLUS=4,COMFORT_PLUS=2,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char VDYErrState;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    FCTCustomInputV7::SignalHeader_t sSigHeader;
    FCTCustomInputV11::sLongControlStatus_t sLongControlStatus;
    VDYErrState eVDYFSVehCorrMonState;
    FCTCustomInputV7::eTurnIndicator_t eTurnIndicator;
  } FCTCustomInput_t;                                                          /* Custom Inputs for functional requirements @vaddr:0x202B0000 @vaddr_defs: FCT_MEAS_ID_CUSTOM_INPUT @cycleid:FCT_ENV @vname:FCTCustomInputData */
}; // FCTCustomInputV12l0

namespace FCTCustomInputV13
{
  typedef unsigned char FCTVehDPCMdASRq_t;                                     /* Driving program control: assistance system mode request @min: 1 @max:5 @values: enum { ECO=5,COMFORT=1,SPORT=3,SPORT_PLUS=4,COMFORT_PLUS=2,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned long CodingValue_t;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    CodingValue_t CodingValue;
    boolean Valid;
  } CodingPar_t;                                                               /* Coding byte form nv memory */ /* @cycleid:FCT_ENV */

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    FCTCustomInputV7::SignalHeader_t sSigHeader;
    FCTCustomInputV1::SIProbabilityLaneChange_t sProbabilityLaneChange;
    FCTCustomInputV6::sLongControlStatus_t sLongControlStatus;
    CodingPar_t CodingPar;
    FCTCustomInputV7::eTurnIndicator_t eTurnIndicator;
  } FCTCustomInput_t;                                                          /* Custom Inputs for functional requirements @vaddr:0x202B0000 @vaddr_defs: FCT_MEAS_ID_CUSTOM_INPUT @cycleid:FCT_ENV @vname:FCTCustomInputData */
}; // FCTCustomInputV13

namespace FCTCustomInputV17
{
  typedef unsigned char eEcoMode_t                                             /* eco mode state from longitudinal controller @min: 0 @max:1 @values: enum { FSRNormalMode=0,FSREcoMode=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char eACCS_CodingType_t                                     /* ACCS Coding Type @min: 0 @max:6 @values: enum { ACCS_CODING_TYPE_UNDEFINED=0,ACCS_CODING_TYPE_1=1,ACCS_CODING_TYPE_3=3,ACCS_CODING_TYPE_2=2,ACCS_CODING_TYPE_5=5,ACCS_CODING_TYPE_4=4,ACCS_CODING_TYPE_6=6,} */	/* [Satisfies_rte sws 1188] */;

typedef struct                                                                 /* [Satisfies_rte sws 1191] */
{
	FCTCustomInputV7l0::eLongControlStatus_t eLongControlStatus;
 	unsigned char uiSelectedObject;
 	eEcoMode_t eEcoMode;
 	FCTCustomInputV11d1::FCTVehDPCMdASRq_t DPC_Md_AS_Rq;
 	eACCS_CodingType_t eACCS_CodingType;
 } sLongControlStatus_t;                                                       /* @cycleid:FCT_ENV */

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;                                             /* The output data version number @min:0.0 @max:16277215.0 */
    FCTCustomInputV7::SignalHeader_t sSigHeader;
    FCTCustomInputV1::SIProbabilityLaneChange_t sProbabilityLaneChange;        /* @cycleid:FCT_ENV @cycleid:FCT_ENV */
    sLongControlStatus_t sLongControlStatus;                                   /* @cycleid:FCT_ENV @cycleid:FCT_ENV */
    FCTCustomInputV2::CodingPar_t CodingPar;                                   /* Coding byte form nv memory */
    FCTCustomInputV7::eTurnIndicator_t eTurnIndicator;
  } FCTCustomInput_t;                                                          /* Custom Inputs for functional requirements @vaddr:FCT_MEAS_ID_CUSTOM_INPUT @cycleid:FCT_ENV @vname:FCTCustomInputData */
}; // FCTCustomInputV17

namespace FCTCustomInputV19
{
  typedef unsigned char FCTVehDPCMdASRq_t;                                     /* Driving program control: assistance system mode request @min: 1 @max:5 @values: enum { ECO=5,COMFORT=1,SPORT=3,SPORT_PLUS=4,COMFORT_PLUS=2,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned long CodingValue_t;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    FCTCustomInputV7::SignalHeader_t sSigHeader;
    FCTCustomInputV7l0::sLongControlStatus_t sLongControlStatus;
    FCTCustomInputV13::CodingPar_t CodingPar;
    FCTCustomInputV7::eTurnIndicator_t eTurnIndicator;
  } FCTCustomInput_t;                                                          /* Custom Inputs for functional requirements @vaddr:0x202B0000 @vaddr_defs: FCT_MEAS_ID_CUSTOM_INPUT @cycleid:FCT_ENV @vname:FCTCustomInputData */
}; // FCTCustomInputV19

class CConvFctCustomInput :
  public CSimConverterBase
{
  // Buffer for holding converted data
  FCTCustomInputV1::FCTCustomInput_t  m_DataBufV0;
  FCTCustomInputV2::FCTCustomInput_t  m_DataBufV2;
  FCTCustomInputV6::FCTCustomInput_t  m_DataBufV6;
  FCTCustomInputV7::FCTCustomInput_t  m_DataBufV7;
  FCTCustomInputV11::FCTCustomInput_t  m_DataBufV11;
  FCTCustomInputV11d1::FCTCustomInput_t  m_DataBufV11d1;
  FCTCustomInputV12l0::FCTCustomInput_t  m_DataBufV12l0;
  FCTCustomInputV13::FCTCustomInput_t  m_DataBufV13;
  FCTCustomInputV7::FCTCustomInput_t  m_DataBufV14;
  FCTCustomInputV17::FCTCustomInput_t  m_DataBufV17;
  FCTCustomInputV19::FCTCustomInput_t  m_DataBufV19;

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here 
    DEP_COUNT
  };
  

public:

  static const char* GetConverterTypeName()
  {
    return "FctCustomInput";
  }

  CConvFctCustomInput(void);
  virtual ~CConvFctCustomInput(void);

  const char* GetTypeName()
  {
    return GetConverterTypeName();
  }

  void Destroy()
  {
    delete this;
  }

  /** returns: 
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_VALUE_FROM_PPORT - when the conversion is not implemented here
   *                                  and the value from Provide Port must be used
   */
  long ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo,
    void* pPPortData,
    void** pOutData, unsigned long& ulOutSize);
  
  /** returns: 
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implemented here
   *                                            and the default value from Request Port must be used
   */
  long GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    void** pDefaultData, unsigned long& ulDefaultSize);

protected:

  // used to check if an unversioned PPort is compatible with a certain version of RPort
  bool IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize);

  // used to check if ports are compatible between different versions
  bool AreVersionsCompatible(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo);
private:

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl VERSION1;
  static CVersionInfoImpl VERSION2;
  static CVersionInfoImpl VERSION3;
  static CVersionInfoImpl VERSION4;
  static CVersionInfoImpl VERSION5;
  static CVersionInfoImpl VERSION6;
  static CVersionInfoImpl VERSION7;
  static CVersionInfoImpl VERSION9;
  static CVersionInfoImpl VERSION11;
  static CVersionInfoImpl VERSION12;
  static CVersionInfoImpl VERSION13;
  static CVersionInfoImpl VERSION14;
  static CVersionInfoImpl VERSION17;
  static CVersionInfoImpl VERSION19;

  enum eFctCustomInputVersions
  {
    FCT_CUSTOM_INPUT_INTFVER1,
    FCT_CUSTOM_INPUT_INTFVER2,
    FCT_CUSTOM_INPUT_INTFVER3,
    FCT_CUSTOM_INPUT_INTFVER4,
    FCT_CUSTOM_INPUT_INTFVER5,
    FCT_CUSTOM_INPUT_INTFVER6,
    FCT_CUSTOM_INPUT_INTFVER7,
    FCT_CUSTOM_INPUT_INTFVER7L0,
    FCT_CUSTOM_INPUT_INTFVER9,
//    FCT_CUSTOM_INPUT_INTFVER11,
    FCT_CUSTOM_INPUT_INTFVER11D1,
    FCT_CUSTOM_INPUT_INTFVER12L0,
    FCT_CUSTOM_INPUT_INTFVER13,
    FCT_CUSTOM_INPUT_INTFVER14,
    FCT_CUSTOM_INPUT_INTFVER17,
    FCT_CUSTOM_INPUT_INTFVER19,
    FCT_CUSTOM_INPUT_NUM_VERSIONS
  };
  static const unsigned long SUPPORTED_SIZE[FCT_CUSTOM_INPUT_NUM_VERSIONS];
  static CVersionInfoImpl * const SUPPORTED_VERSIONS[FCT_CUSTOM_INPUT_NUM_VERSIONS];
};

// Define this to the maximum buffer size needed
#define MAX_BUFFER_SIZE_NEEDED    sizeof(CConvFctCustomInput::FCTCustomInputV0_t)

CVersionInfoImpl  CConvFctCustomInput::BASE_VERSION(0, 0, 0);
CVersionInfoImpl  CConvFctCustomInput::VERSION1(0, 0, 1);
CVersionInfoImpl  CConvFctCustomInput::VERSION2(0, 0, 2);
CVersionInfoImpl  CConvFctCustomInput::VERSION3(0, 0, 3);
CVersionInfoImpl  CConvFctCustomInput::VERSION4(0, 0, 4);
CVersionInfoImpl  CConvFctCustomInput::VERSION5(0, 0, 5);
CVersionInfoImpl  CConvFctCustomInput::VERSION6(0, 0, 6);
CVersionInfoImpl  CConvFctCustomInput::VERSION7(0, 0, 7);
CVersionInfoImpl  CConvFctCustomInput::VERSION9(0, 0, 9);
CVersionInfoImpl  CConvFctCustomInput::VERSION11(0, 0, 11);
CVersionInfoImpl  CConvFctCustomInput::VERSION12(0, 0, 12);
CVersionInfoImpl  CConvFctCustomInput::VERSION13(0, 0, 13);
CVersionInfoImpl  CConvFctCustomInput::VERSION14(0, 0, 14);
CVersionInfoImpl  CConvFctCustomInput::VERSION17(0, 0, 17);
CVersionInfoImpl  CConvFctCustomInput::VERSION19(0, 0, 19);

const unsigned long CConvFctCustomInput::SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_NUM_VERSIONS]=
{
  sizeof(FCTCustomInputV1::FCTCustomInput_t),                        /* 8  */
  sizeof(FCTCustomInputV2::FCTCustomInput_t),                        /* 16 */
  sizeof(FCTCustomInputV2::FCTCustomInput_t),                        /* 16 */
  sizeof(FCTCustomInputV2::FCTCustomInput_t),                        /* 16 */
  sizeof(FCTCustomInputV2::FCTCustomInput_t),                        /* 16 */
  sizeof(FCTCustomInputV6::FCTCustomInput_t),                        /* 20 */
  sizeof(FCTCustomInputV7::FCTCustomInput_t),                        /* 36 */
  sizeof(FCTCustomInputV7l0::FCTCustomInput_t),                      /* 20 */
  sizeof(FCTCustomInputV7::FCTCustomInput_t),                        /* 36 */
//  sizeof(FCTCustomInputV11::FCTCustomInput_t),                     /* 20 */
  sizeof(FCTCustomInputV11d1::FCTCustomInput_t),                     /* 20 */
  sizeof(FCTCustomInputV12l0::FCTCustomInput_t),                     /* 20 */
  sizeof(FCTCustomInputV13::FCTCustomInput_t),                       /* 36 */
  sizeof(FCTCustomInputV7::FCTCustomInput_t),                        /* 36 */
  sizeof(FCTCustomInputV17::FCTCustomInput_t),                       /* 36 */
  sizeof(FCTCustomInputV19::FCTCustomInput_t)                        /* 32 */
};

CVersionInfoImpl * const CConvFctCustomInput::SUPPORTED_VERSIONS[FCT_CUSTOM_INPUT_NUM_VERSIONS] = 
{
  &VERSION1,
  &VERSION2,
  &VERSION3,
  &VERSION4,
  &VERSION5,
  &VERSION6,
  &VERSION7,
  &VERSION7,
  &VERSION9,
  &VERSION11,
  &VERSION12,
  &VERSION13,
  &VERSION14,
  &VERSION17,
  &VERSION19
};

CConvFctCustomInput::CConvFctCustomInput(void)
: CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_DataBufV0(), m_DataBufV2(), m_DataBufV6(), m_DataBufV7(), m_DataBufV11(), m_DataBufV11d1(), m_DataBufV12l0(), m_DataBufV13(), m_DataBufV14(), m_DataBufV17(), m_DataBufV19()
{
  memset(&m_DataBufV0, 0, sizeof(m_DataBufV0));
  memset(&m_DataBufV2, 0, sizeof(m_DataBufV2));
  memset(&m_DataBufV6, 0, sizeof(m_DataBufV6));
  memset(&m_DataBufV7, 0, sizeof(m_DataBufV7));
  memset(&m_DataBufV11, 0, sizeof(m_DataBufV11));
  memset(&m_DataBufV11d1, 0, sizeof(m_DataBufV11d1));
  memset(&m_DataBufV12l0, 0, sizeof(m_DataBufV12l0));
  memset(&m_DataBufV13, 0, sizeof(m_DataBufV13));
  memset(&m_DataBufV14, 0, sizeof(m_DataBufV14));
  memset(&m_DataBufV17, 0, sizeof(m_DataBufV17));
  memset(&m_DataBufV19, 0, sizeof(m_DataBufV19));
}

CConvFctCustomInput::~CConvFctCustomInput(void)
{
}

long CConvFctCustomInput::ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo, 
    void* pPPortData,
    void** pOutData, unsigned long& ulOutSize)
{
  long RetVal = SIM_ERR_USE_VALUE_FROM_PPORT;
  __int32 uiVersion = (ulPPortSize >= 4) ? (*reinterpret_cast<__int32*>(pPPortData)) : 0;
  CVersionInfoImpl ProvidePortVersionInfoFromRPortData(CONV_I32VERSION_TO_TUPPLE(uiVersion));

  if ((ulPPortSize == 4) && (pProvidePortVersionInfo == NULL) && (ePPortType == simF32_t) && (eRPortType == simOPAQUE_t))
  {
    // Special case: allow connecting raw overtake assist float signal to complete struct
    if (ulRPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER6])
    {
      const float * pInput = static_cast<float *>(pPPortData);
      FCTCustomInputV6::FCTCustomInput_t * pOutput = &m_DataBufV6;
      // Convert data
      pOutput->uiVersionNumber  = 6;
      pOutput->sLongControlStatus.eLongControlStatus  = FSRFunctionEnabled;
      pOutput->sLongControlStatus.uiSelectedObject    = 0;
      pOutput->sLongControlStatus.eEcoMode            = FCTCustomInputV6::FSRNormalMode;
      pOutput->sProbabilityLaneChange.uiProbabilityLaneChangeLeft   = static_cast<FCTCustomInputV1::uint8>(*pInput);
      pOutput->sProbabilityLaneChange.uiProbabilityLaneChangeRight  = 0;
      pOutput->CodingPar.CodingValue  = 0;
      pOutput->CodingPar.Valid        = 0;
      // Now set output parameters
      *pOutData = pOutput;
      ulOutSize = sizeof(m_DataBufV6);
      RetVal    = SIM_ERR_OK;
    }
    else if (ulRPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER2])
    {
      const float * pInput = static_cast<float *>(pPPortData);
      FCTCustomInputV2::FCTCustomInput_t * pOutput = &m_DataBufV2;
      // Convert data
      pOutput->uiVersionNumber  = 2;
      pOutput->sLongControlStatus.eLongControlStatus  = FSRFunctionEnabled;
      pOutput->sLongControlStatus.uiSelectedObject    = 0;
      pOutput->sProbabilityLaneChange.uiProbabilityLaneChangeLeft   = static_cast<FCTCustomInputV1::uint8>(*pInput);
      pOutput->sProbabilityLaneChange.uiProbabilityLaneChangeRight  = 0;
      pOutput->CodingPar.CodingValue  = 0;
      pOutput->CodingPar.Valid        = 0;
      // Now set output parameters
      *pOutData = pOutput;
      ulOutSize = sizeof(m_DataBufV2);
      RetVal    = SIM_ERR_OK;
    }
    else if (ulRPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER1])
    {
      const float * pInput = static_cast<float *>(pPPortData);
      FCTCustomInputV1::FCTCustomInput_t * pOutput = &m_DataBufV0;
      // Convert data
      pOutput->uiVersionNumber  = 1;
      pOutput->sLongControlStatus.eLongControlStatus  = FSRFunctionEnabled;
      pOutput->sLongControlStatus.uiSelectedObject    = 0;
      pOutput->sProbabilityLaneChange.uiProbabilityLaneChangeLeft   = static_cast<FCTCustomInputV1::uint8>(*pInput);
      pOutput->sProbabilityLaneChange.uiProbabilityLaneChangeRight  = 0;
      // Now set output parameters
      *pOutData = pOutput;
      ulOutSize = sizeof(m_DataBufV0);
      RetVal    = SIM_ERR_OK;
    }
  }
  else if ((ulRPortSize == SUPPORTED_SIZE[FCT_CUSTOM_INPUT_INTFVER19]) &&
    (SUPPORTED_VERSIONS[FCT_CUSTOM_INPUT_INTFVER19]->Equals(&requestPortVersionInfo)))
  {
    FCTCustomInputV19::FCTCustomInput_t * const pDest = &m_DataBufV19;

    if ((ulPPortSize == SUPPORTED_SIZE[FCT_CUSTOM_INPUT_INTFVER13]) &&
      ((pProvidePortVersionInfo == NULL) || BASE_VERSION.Equals(pProvidePortVersionInfo) ||
      SUPPORTED_VERSIONS[FCT_CUSTOM_INPUT_INTFVER13]->Equals(pProvidePortVersionInfo)) &&
      (uiVersion == 13))
    {
      const FCTCustomInputV13::FCTCustomInput_t * const pSrc = static_cast<FCTCustomInputV13::FCTCustomInput_t*>(pPPortData);
      pDest->uiVersionNumber = 19;
      pDest->sSigHeader = pSrc->sSigHeader;
      pDest->sSigHeader.eSigStatus = 1;
      pDest->sLongControlStatus = pDest->sLongControlStatus;
      memset(&pDest->CodingPar, 0, sizeof(pDest->CodingPar));
      pDest->eTurnIndicator = pSrc->eTurnIndicator;
      // Set output parameters
      *pOutData = pDest;
      ulOutSize = sizeof(*pDest);
      RetVal = SIM_ERR_OK;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[FCT_CUSTOM_INPUT_INTFVER7L0]) &&
      ((pProvidePortVersionInfo == NULL) || BASE_VERSION.Equals(pProvidePortVersionInfo) ||
      SUPPORTED_VERSIONS[FCT_CUSTOM_INPUT_INTFVER7L0]->Equals(pProvidePortVersionInfo)) &&
      (uiVersion == 13))
    {
      const FCTCustomInputV7l0::FCTCustomInput_t * const pSrc = static_cast<FCTCustomInputV7l0::FCTCustomInput_t*>(pPPortData);
      pDest->uiVersionNumber = 19;
      pDest->sSigHeader = pSrc->sSigHeader;
      pDest->sSigHeader.eSigStatus = 1;
      pDest->sLongControlStatus = pSrc->sLongControlStatus;
      memset(&pDest->CodingPar, 0, sizeof(pDest->CodingPar));
      pDest->eTurnIndicator = pSrc->eTurnIndicator;
      // Set output parameters
      *pOutData = pDest;
      ulOutSize = sizeof(*pDest);
      RetVal = SIM_ERR_OK;
    }
  }
  else if ((ulRPortSize == SUPPORTED_SIZE[FCT_CUSTOM_INPUT_INTFVER17]) &&
    (SUPPORTED_VERSIONS[FCT_CUSTOM_INPUT_INTFVER17]->Equals(&requestPortVersionInfo)))
  {
    FCTCustomInputV17::FCTCustomInput_t * const pDest = &m_DataBufV17;

    if ((ulPPortSize == SUPPORTED_SIZE[FCT_CUSTOM_INPUT_INTFVER13]) &&
      ((pProvidePortVersionInfo == NULL) || BASE_VERSION.Equals(pProvidePortVersionInfo) ||
      SUPPORTED_VERSIONS[FCT_CUSTOM_INPUT_INTFVER13]->Equals(pProvidePortVersionInfo)) &&
      (uiVersion == 13))
    {
      const FCTCustomInputV13::FCTCustomInput_t * const pSrc = static_cast<FCTCustomInputV13::FCTCustomInput_t*>(pPPortData);
      pDest->uiVersionNumber = 17;
      pDest->sSigHeader = pSrc->sSigHeader;
      pDest->sSigHeader.eSigStatus = 1;
      pDest->sProbabilityLaneChange = pSrc->sProbabilityLaneChange;
      pDest->sLongControlStatus = pDest->sLongControlStatus;
      memset(&pDest->CodingPar, 0, sizeof(pDest->CodingPar));
      pDest->eTurnIndicator = pSrc->eTurnIndicator;
      // Set output parameters
      *pOutData = pDest;
      ulOutSize = sizeof(*pDest);
      RetVal = SIM_ERR_OK;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[FCT_CUSTOM_INPUT_INTFVER11D1]) &&
      ((pProvidePortVersionInfo == NULL) || BASE_VERSION.Equals(pProvidePortVersionInfo) ||
      SUPPORTED_VERSIONS[FCT_CUSTOM_INPUT_INTFVER11D1]->Equals(pProvidePortVersionInfo)) &&
      (uiVersion == 11))
    {
      const FCTCustomInputV11d1::FCTCustomInput_t * const pSrc = static_cast<FCTCustomInputV11d1::FCTCustomInput_t*>(pPPortData);
      pDest->uiVersionNumber       = 17;
      pDest->sSigHeader            = pSrc->sSigHeader;
      pDest->sSigHeader.eSigStatus = 1;

      pDest->sProbabilityLaneChange.uiProbabilityLaneChangeLeft  = 0;
      pDest->sProbabilityLaneChange.uiProbabilityLaneChangeRight = 0;

      pDest->sLongControlStatus.eLongControlStatus = pSrc->sLongControlStatus.eLongControlStatus;
      pDest->sLongControlStatus.DPC_Md_AS_Rq       = pSrc->sLongControlStatus.DPC_Md_AS_Rq;
      pDest->sLongControlStatus.uiSelectedObject   = 0;
      pDest->sLongControlStatus.eEcoMode           = FCTCustomInputV6::FSRNormalMode;
      pDest->sLongControlStatus.eACCS_CodingType   = 3;

      memset(&pDest->CodingPar, 0, sizeof(pDest->CodingPar));

      pDest->eTurnIndicator = pSrc->eTurnIndicator;
      // Set output parameters
      *pOutData = pDest;
      ulOutSize = sizeof(*pDest);
      RetVal = SIM_ERR_OK;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[FCT_CUSTOM_INPUT_INTFVER7L0]) &&
      ((pProvidePortVersionInfo == NULL) || BASE_VERSION.Equals(pProvidePortVersionInfo) ||
      SUPPORTED_VERSIONS[FCT_CUSTOM_INPUT_INTFVER7L0]->Equals(pProvidePortVersionInfo)) &&
      (uiVersion == 7))
    {
      const FCTCustomInputV7l0::FCTCustomInput_t * const pSrc = static_cast<FCTCustomInputV7l0::FCTCustomInput_t*>(pPPortData);
      pDest->uiVersionNumber       = 17;
      pDest->sSigHeader            = pSrc->sSigHeader;
      pDest->sSigHeader.eSigStatus = 1;

      pDest->sProbabilityLaneChange.uiProbabilityLaneChangeLeft  = 0;
      pDest->sProbabilityLaneChange.uiProbabilityLaneChangeRight = 0;

      pDest->sLongControlStatus.eLongControlStatus = pSrc->sLongControlStatus.eLongControlStatus;
      pDest->sLongControlStatus.uiSelectedObject   = 0;
      pDest->sLongControlStatus.eEcoMode           = FCTCustomInputV6::FSRNormalMode;
      pDest->sLongControlStatus.DPC_Md_AS_Rq       = 1;
      pDest->sLongControlStatus.eACCS_CodingType   = 3;

      memset(&pDest->CodingPar, 0, sizeof(pDest->CodingPar));

      pDest->eTurnIndicator = pSrc->eTurnIndicator;
      // Set output parameters
      *pOutData = pDest;
      ulOutSize = sizeof(*pDest);
      RetVal = SIM_ERR_OK;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[FCT_CUSTOM_INPUT_INTFVER7]) &&
      ((pProvidePortVersionInfo == NULL) || BASE_VERSION.Equals(pProvidePortVersionInfo) ||
      SUPPORTED_VERSIONS[FCT_CUSTOM_INPUT_INTFVER7]->Equals(pProvidePortVersionInfo)) &&
      (uiVersion == 7))
    {
      const FCTCustomInputV7::FCTCustomInput_t * const pSrc = static_cast<FCTCustomInputV7::FCTCustomInput_t*>(pPPortData);
      pDest->uiVersionNumber = 17;
      pDest->sSigHeader = pSrc->sSigHeader;
      pDest->sSigHeader.eSigStatus = 1;
      pDest->sProbabilityLaneChange = pSrc->sProbabilityLaneChange;
      pDest->sLongControlStatus = pDest->sLongControlStatus;
      pDest->CodingPar = pSrc->CodingPar;
      pDest->eTurnIndicator = pSrc->eTurnIndicator;
      // Set output parameters
      *pOutData = pDest;
      ulOutSize = sizeof(*pDest);
      RetVal = SIM_ERR_OK;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[FCT_CUSTOM_INPUT_INTFVER6]) &&
      ((pProvidePortVersionInfo == NULL) || BASE_VERSION.Equals(pProvidePortVersionInfo) ||
      SUPPORTED_VERSIONS[FCT_CUSTOM_INPUT_INTFVER6]->Equals(pProvidePortVersionInfo)) &&
      (uiVersion == 6))
    {
      const FCTCustomInputV6::FCTCustomInput_t * const pSrc = static_cast<FCTCustomInputV6::FCTCustomInput_t*>(pPPortData);
      pDest->uiVersionNumber = 17;
      memset(&pDest->sSigHeader, 0, sizeof(pDest->sSigHeader));
      pDest->sSigHeader.eSigStatus = 1;
      pDest->sProbabilityLaneChange = pSrc->sProbabilityLaneChange;
      pDest->sLongControlStatus.eEcoMode = pSrc->sLongControlStatus.eEcoMode;
      pDest->sLongControlStatus.eLongControlStatus = pSrc->sLongControlStatus.eLongControlStatus;
      pDest->sLongControlStatus.uiSelectedObject = pSrc->sLongControlStatus.uiSelectedObject;
      pDest->sLongControlStatus.DPC_Md_AS_Rq = 1;
      pDest->sLongControlStatus.eACCS_CodingType = 3;
      pDest->CodingPar = pSrc->CodingPar;
      pDest->eTurnIndicator = 0;
      // Set output parameters
      *pOutData = pDest;
      ulOutSize = sizeof(*pDest);
      RetVal = SIM_ERR_OK;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[FCT_CUSTOM_INPUT_INTFVER2]) &&
      ((pProvidePortVersionInfo == NULL) || BASE_VERSION.Equals(pProvidePortVersionInfo) ||
      SUPPORTED_VERSIONS[FCT_CUSTOM_INPUT_INTFVER2]->Equals(pProvidePortVersionInfo)) &&
      (uiVersion == 2))
    {
      const FCTCustomInputV2::FCTCustomInput_t * const pSrc = static_cast<FCTCustomInputV2::FCTCustomInput_t*>(pPPortData);
      pDest->uiVersionNumber = 17;
      memset(&pDest->sSigHeader, 0, sizeof(pDest->sSigHeader));
      pDest->sSigHeader.eSigStatus = 1;
      pDest->sProbabilityLaneChange = pSrc->sProbabilityLaneChange;
      pDest->sLongControlStatus.eLongControlStatus = pSrc->sLongControlStatus.eLongControlStatus;
      pDest->sLongControlStatus.uiSelectedObject = pSrc->sLongControlStatus.uiSelectedObject;
      pDest->sLongControlStatus.eEcoMode = FCTCustomInputV6::FSRNormalMode;
      pDest->sLongControlStatus.DPC_Md_AS_Rq = 1;
      pDest->sLongControlStatus.eACCS_CodingType = 3;
      pDest->CodingPar = pSrc->CodingPar;
      pDest->eTurnIndicator = 0;
      // Set output parameters
      *pOutData = pDest;
      ulOutSize = sizeof(*pDest);
      RetVal = SIM_ERR_OK;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[FCT_CUSTOM_INPUT_INTFVER1]) &&
      ((pProvidePortVersionInfo == NULL) || BASE_VERSION.Equals(pProvidePortVersionInfo) ||
      SUPPORTED_VERSIONS[FCT_CUSTOM_INPUT_INTFVER1]->Equals(pProvidePortVersionInfo)) &&
      (uiVersion == 1))
    {
      const FCTCustomInputV1::FCTCustomInput_t * const pSrc = static_cast<FCTCustomInputV1::FCTCustomInput_t*>(pPPortData);
      pDest->uiVersionNumber = 17;
      memset(&pDest->sSigHeader, 0, sizeof(pDest->sSigHeader));
      pDest->sSigHeader.eSigStatus = 1;
      pDest->sProbabilityLaneChange = pSrc->sProbabilityLaneChange;
      pDest->sLongControlStatus.eLongControlStatus = pSrc->sLongControlStatus.eLongControlStatus;
      pDest->sLongControlStatus.uiSelectedObject = pSrc->sLongControlStatus.uiSelectedObject;
      pDest->sLongControlStatus.eEcoMode = FCTCustomInputV6::FSRNormalMode;
      pDest->sLongControlStatus.DPC_Md_AS_Rq = 1;
      pDest->sLongControlStatus.eACCS_CodingType = 3;
      memset(&pDest->CodingPar, 0, sizeof(pDest->CodingPar));
      pDest->eTurnIndicator = 0;
      // Set output parameters
      *pOutData = pDest;
      ulOutSize = sizeof(*pDest);
      RetVal = SIM_ERR_OK;
    }
  }
  else if ((ulRPortSize == SUPPORTED_SIZE[FCT_CUSTOM_INPUT_INTFVER12L0]) &&
    (SUPPORTED_VERSIONS[FCT_CUSTOM_INPUT_INTFVER12L0]->Equals(&requestPortVersionInfo)))
  {
    /* This version 12 is only used by ARS4LO (up to now) !!! */
    /* There are existing measurements with version 7 and version 11 */
    FCTCustomInputV12l0::FCTCustomInput_t * const pDest = &m_DataBufV12l0;

    if ((ulPPortSize == SUPPORTED_SIZE[FCT_CUSTOM_INPUT_INTFVER11D1]) &&
      ((pProvidePortVersionInfo == NULL) || BASE_VERSION.Equals(pProvidePortVersionInfo) ||
      SUPPORTED_VERSIONS[FCT_CUSTOM_INPUT_INTFVER11D1]->Equals(pProvidePortVersionInfo)) &&
      (uiVersion == 11))
    {
      const FCTCustomInputV11l0::FCTCustomInput_t * const pSrc = static_cast<FCTCustomInputV11l0::FCTCustomInput_t*>(pPPortData);
      pDest->uiVersionNumber = 12;
      pDest->sSigHeader = pSrc->sSigHeader;
      pDest->sSigHeader.eSigStatus = 1;
      pDest->sLongControlStatus = pDest->sLongControlStatus;
      pDest->eVDYFSVehCorrMonState = 0;
      pDest->eTurnIndicator = pSrc->eTurnIndicator;
      // Set output parameters
      *pOutData = pDest;
      ulOutSize = sizeof(*pDest);
      RetVal = SIM_ERR_OK;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[FCT_CUSTOM_INPUT_INTFVER7L0]) &&
      ((pProvidePortVersionInfo == NULL) || BASE_VERSION.Equals(pProvidePortVersionInfo) ||
      SUPPORTED_VERSIONS[FCT_CUSTOM_INPUT_INTFVER7L0]->Equals(pProvidePortVersionInfo)) &&
      (uiVersion == 7))
    {
      const FCTCustomInputV7l0::FCTCustomInput_t * const pSrc = static_cast<FCTCustomInputV7l0::FCTCustomInput_t*>(pPPortData);
      pDest->uiVersionNumber = 12;
      pDest->sSigHeader = pSrc->sSigHeader;
      pDest->sSigHeader.eSigStatus = 1;
      pDest->sLongControlStatus = pDest->sLongControlStatus;
      pDest->eVDYFSVehCorrMonState = 0;
      pDest->eTurnIndicator = pSrc->eTurnIndicator;
      // Set output parameters
      *pOutData = pDest;
      ulOutSize = sizeof(*pDest);
      RetVal = SIM_ERR_OK;
    }
  }
  else if ((ePPortType == eRPortType) && (ulPPortSize == ulRPortSize) &&
    ((requestPortVersionInfo.Equals(pProvidePortVersionInfo)) ||
    ((pProvidePortVersionInfo == NULL) && (ProvidePortVersionInfoFromRPortData.Equals(&requestPortVersionInfo)))))
  {
    // Use data directly. Use it only for equal version numbers!
    *pOutData = pPPortData;
    ulOutSize = ulPPortSize;
    RetVal    = SIM_ERR_OK;
  }
  else if ((ulRPortSize == SUPPORTED_SIZE[FCT_CUSTOM_INPUT_INTFVER11D1]) &&
    (SUPPORTED_VERSIONS[FCT_CUSTOM_INPUT_INTFVER11D1]->Equals(&requestPortVersionInfo)))
  {
    FCTCustomInputV11d1::FCTCustomInput_t * const pDest = &m_DataBufV11d1;

    if ((ulPPortSize == SUPPORTED_SIZE[FCT_CUSTOM_INPUT_INTFVER7]) &&
      ((pProvidePortVersionInfo == NULL) || BASE_VERSION.Equals(pProvidePortVersionInfo) ||
      SUPPORTED_VERSIONS[FCT_CUSTOM_INPUT_INTFVER7]->Equals(pProvidePortVersionInfo)))
    {
      const FCTCustomInputV7::FCTCustomInput_t * const pSrc = static_cast<FCTCustomInputV7::FCTCustomInput_t*>(pPPortData);
      pDest->uiVersionNumber = 11;
      pDest->sSigHeader = pSrc->sSigHeader;
      pDest->sSigHeader.eSigStatus = 1;
      pDest->sLongControlStatus.eLongControlStatus = pSrc->sLongControlStatus.eLongControlStatus;
      pDest->sLongControlStatus.DPC_Md_AS_Rq = 1;                                                  // Comfort
      pDest->eTurnIndicator = pSrc->eTurnIndicator;
      // Set output parameters
      *pOutData = pDest;
      ulOutSize = sizeof(*pDest);
      RetVal = SIM_ERR_OK;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[FCT_CUSTOM_INPUT_INTFVER6]) &&
      ((pProvidePortVersionInfo == NULL) || BASE_VERSION.Equals(pProvidePortVersionInfo) ||
      SUPPORTED_VERSIONS[FCT_CUSTOM_INPUT_INTFVER6]->Equals(pProvidePortVersionInfo)))
    {
      const FCTCustomInputV6::FCTCustomInput_t * const pSrc = static_cast<FCTCustomInputV6::FCTCustomInput_t*>(pPPortData);
      pDest->uiVersionNumber = 11;
      pDest->sSigHeader.eSigStatus = 1;
      pDest->sLongControlStatus.eLongControlStatus = pSrc->sLongControlStatus.eLongControlStatus;
      pDest->sLongControlStatus.DPC_Md_AS_Rq = 1;                                                  // Comfort
      pDest->eTurnIndicator = 0;
      // Set output parameters
      *pOutData = pDest;
      ulOutSize = sizeof(*pDest);
      RetVal = SIM_ERR_OK;
    }

  }
  else if ((ulRPortSize == SUPPORTED_SIZE[FCT_CUSTOM_INPUT_INTFVER13]) &&
    (SUPPORTED_VERSIONS[FCT_CUSTOM_INPUT_INTFVER13]->Equals(&requestPortVersionInfo)))
  {
    FCTCustomInputV13::FCTCustomInput_t * const pDest = &m_DataBufV13;

    if ((ulPPortSize == SUPPORTED_SIZE[FCT_CUSTOM_INPUT_INTFVER11D1]) &&
      ((pProvidePortVersionInfo == NULL) || BASE_VERSION.Equals(pProvidePortVersionInfo) ||
      SUPPORTED_VERSIONS[FCT_CUSTOM_INPUT_INTFVER11D1]->Equals(pProvidePortVersionInfo)))
    {
      const FCTCustomInputV11::FCTCustomInput_t * const pSrc = static_cast<FCTCustomInputV11::FCTCustomInput_t*>(pPPortData);
      pDest->uiVersionNumber = 13;
      pDest->sSigHeader = pSrc->sSigHeader;
      pDest->sSigHeader.eSigStatus = 1;
      memset(&pDest->sProbabilityLaneChange, 0, sizeof(pDest->sProbabilityLaneChange));
      pDest->sLongControlStatus = pDest->sLongControlStatus;
      memset(&pDest->CodingPar, 0, sizeof(pDest->CodingPar));
      pDest->eTurnIndicator = pSrc->eTurnIndicator;
      // Set output parameters
      *pOutData = pDest;
      ulOutSize = sizeof(*pDest);
      RetVal = SIM_ERR_OK;
    }
  }
  else if ((ulRPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER6]) &&
    (requestPortVersionInfo.Equals(&VERSION6)))
  {
    FCTCustomInputV6::FCTCustomInput_t * const pOutput = &m_DataBufV6;
    if (   (ulPPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER1])
        && (   (pProvidePortVersionInfo == NULL)
            || (BASE_VERSION.Equals(pProvidePortVersionInfo))
            || (VERSION1.Equals(pProvidePortVersionInfo))
           )
       )
    {
      const FCTCustomInputV1::FCTCustomInput_t * const pInput = static_cast<FCTCustomInputV1::FCTCustomInput_t*>(pPPortData);
      pOutput->uiVersionNumber  = 6;
      pOutput->sProbabilityLaneChange       = pInput->sProbabilityLaneChange;
      pOutput->sLongControlStatus.eLongControlStatus  = pInput->sLongControlStatus.eLongControlStatus;
      pOutput->sLongControlStatus.uiSelectedObject    = pInput->sLongControlStatus.uiSelectedObject;
      pOutput->sLongControlStatus.eEcoMode            = FCTCustomInputV6::FSRNormalMode;
      pOutput->CodingPar.CodingValue  = 0;
      pOutput->CodingPar.Valid        = 0;
      // Set output parameters
      *pOutData = pOutput;
      ulOutSize = sizeof(*pOutput);
      RetVal = SIM_ERR_OK;
    }
    else if (   (ePPortType == eRPortType)
             && (ulPPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER2])
             && ((pProvidePortVersionInfo == NULL)
                 || VERSION2.Equals(pProvidePortVersionInfo)
                 || VERSION3.Equals(pProvidePortVersionInfo)
                 || VERSION4.Equals(pProvidePortVersionInfo)
                 || VERSION5.Equals(pProvidePortVersionInfo)
                )
            )
    {
      const FCTCustomInputV2::FCTCustomInput_t * const pInput = static_cast<FCTCustomInputV2::FCTCustomInput_t*>(pPPortData);
      pOutput->uiVersionNumber  = 6;
      pOutput->sProbabilityLaneChange                 = pInput->sProbabilityLaneChange;
      pOutput->sLongControlStatus.eLongControlStatus  = pInput->sLongControlStatus.eLongControlStatus;
      pOutput->sLongControlStatus.uiSelectedObject    = pInput->sLongControlStatus.uiSelectedObject;
      pOutput->sLongControlStatus.eEcoMode            = FCTCustomInputV6::FSRNormalMode;
      pOutput->CodingPar                              = pInput->CodingPar;
      // Set output parameters
      *pOutData = pOutput;
      ulOutSize = sizeof(*pOutput);
      RetVal = SIM_ERR_OK;
    }
    else if ((ePPortType == eRPortType)
      && (ulPPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER6])
             && (pProvidePortVersionInfo != NULL)
             && (VERSION6.Equals(pProvidePortVersionInfo))
             )
    {
      // Use data directly
      *pOutData = pPPortData;
      ulOutSize = ulPPortSize;
      RetVal    = SIM_ERR_OK;
    }
  }
  else if (   (ulRPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER2])
           && (   requestPortVersionInfo.Equals(&VERSION2)
               || requestPortVersionInfo.Equals(&VERSION3)
               || requestPortVersionInfo.Equals(&VERSION4)
               || requestPortVersionInfo.Equals(&VERSION5)
              )
          )
  {
    FCTCustomInputV2::FCTCustomInput_t * const pOutput = &m_DataBufV2;
    if (   (ulPPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER1])
        && (   (pProvidePortVersionInfo == NULL)
            || (BASE_VERSION.Equals(pProvidePortVersionInfo))
            || (VERSION1.Equals(pProvidePortVersionInfo))
           )
       )
    {
      const FCTCustomInputV1::FCTCustomInput_t * const pInput = static_cast<FCTCustomInputV1::FCTCustomInput_t*>(pPPortData);
      pOutput->uiVersionNumber  = 2;
      pOutput->sProbabilityLaneChange = pInput->sProbabilityLaneChange;
      pOutput->sLongControlStatus     = pInput->sLongControlStatus;
      pOutput->CodingPar.CodingValue  = 0;
      pOutput->CodingPar.Valid        = 0;
      // Set output parameters
      *pOutData = pOutput;
      ulOutSize = sizeof(*pOutput);
      RetVal = SIM_ERR_OK;
    }
    else if ((ePPortType == eRPortType)
      && (ulPPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER6])
      && (     (pProvidePortVersionInfo == NULL)
          ||  (VERSION6.Equals(pProvidePortVersionInfo)))
          )
    {
      const FCTCustomInputV6::FCTCustomInput_t * const pInput = static_cast<FCTCustomInputV6::FCTCustomInput_t*>(pPPortData);
      pOutput->uiVersionNumber  = 2;
      pOutput->sProbabilityLaneChange = pInput->sProbabilityLaneChange;
      pOutput->sLongControlStatus.eLongControlStatus  = pInput->sLongControlStatus.eLongControlStatus;
      pOutput->sLongControlStatus.uiSelectedObject    = pInput->sLongControlStatus.uiSelectedObject;
      pOutput->CodingPar = pInput->CodingPar;
      // Set output parameters
      *pOutData = pOutput;
      ulOutSize = sizeof(*pOutput);
      RetVal = SIM_ERR_OK;
    }
    else if (   (ePPortType == eRPortType)
             && (ulPPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER2])
             && ((pProvidePortVersionInfo == NULL)
                 || VERSION2.Equals(pProvidePortVersionInfo)
                 || VERSION3.Equals(pProvidePortVersionInfo)
                 || VERSION4.Equals(pProvidePortVersionInfo)
                 || VERSION5.Equals(pProvidePortVersionInfo)
                )
            )
    {
      // Use data directly
      *pOutData = pPPortData;
      ulOutSize = ulPPortSize;
      RetVal    = SIM_ERR_OK;
    }
  }
  else if (   (ulRPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER1])
           && (requestPortVersionInfo.Equals(SUPPORTED_VERSIONS[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER1]))
          )
  {
    FCTCustomInputV1::FCTCustomInput_t * const pOutput = &m_DataBufV0;
    if (   (ulPPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER2])
        && (   (pProvidePortVersionInfo == NULL)
            || (BASE_VERSION.Equals(pProvidePortVersionInfo))
            || (VERSION2.Equals(pProvidePortVersionInfo))
            || (VERSION3.Equals(pProvidePortVersionInfo))
            || (VERSION4.Equals(pProvidePortVersionInfo))
            || (VERSION5.Equals(pProvidePortVersionInfo))
           )
       )
    {
      const FCTCustomInputV2::FCTCustomInput_t * pInput = static_cast<FCTCustomInputV2::FCTCustomInput_t *>(pPPortData);
      // Do a 1-1 copy
      pOutput->uiVersionNumber  = 1;
      pOutput->sProbabilityLaneChange = pInput->sProbabilityLaneChange;
      pOutput->sLongControlStatus     = pInput->sLongControlStatus;
      // Now set output parameters
      *pOutData = pOutput;
      ulOutSize = sizeof(*pOutput);
      RetVal    = SIM_ERR_OK;
    }
    else if (   (ulPPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER6])
        && (   (pProvidePortVersionInfo == NULL)
            || (BASE_VERSION.Equals(pProvidePortVersionInfo))
            || (VERSION6.Equals(pProvidePortVersionInfo))
           )
       )
    {
      const FCTCustomInputV6::FCTCustomInput_t * pInput = static_cast<FCTCustomInputV6::FCTCustomInput_t *>(pPPortData);
      // Do a 1-1 copy
      pOutput->uiVersionNumber  = 1;
      pOutput->sProbabilityLaneChange = pInput->sProbabilityLaneChange;
      pOutput->sLongControlStatus.eLongControlStatus  = pInput->sLongControlStatus.eLongControlStatus;
      pOutput->sLongControlStatus.uiSelectedObject    = pInput->sLongControlStatus.uiSelectedObject;
      // Now set output parameters
      *pOutData = pOutput;
      ulOutSize = sizeof(*pOutput);
      RetVal    = SIM_ERR_OK;
    }
  }
  else if (ulPPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER11D1])
  {
    if ((ulRPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER7]) ||
      (ulRPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER9]) ||
      (ulRPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER14]))
    {
      const FCTCustomInputV11d1::FCTCustomInput_t * const pInput = static_cast<FCTCustomInputV11d1::FCTCustomInput_t*>(pPPortData);
      FCTCustomInputV7::FCTCustomInput_t * pOutput = &m_DataBufV7;
      // Convert data from V11 or V11D1 to V7, V9 or V14
      if (requestPortVersionInfo.Equals(SUPPORTED_VERSIONS[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER7]))
      {
        pOutput->uiVersionNumber                                   = 7;
      }
      else if (requestPortVersionInfo.Equals(SUPPORTED_VERSIONS[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER9]))
      {
        pOutput->uiVersionNumber                                   = 9;
      }
      else if (requestPortVersionInfo.Equals(SUPPORTED_VERSIONS[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER14]))
      {
        pOutput->uiVersionNumber                                   = 14;
      }
      pOutput->sSigHeader                                          = pInput->sSigHeader;
      pOutput->sProbabilityLaneChange.uiProbabilityLaneChangeLeft  = 0;
      pOutput->sProbabilityLaneChange.uiProbabilityLaneChangeRight = 0;
      pOutput->sLongControlStatus.eLongControlStatus               = pInput->sLongControlStatus.eLongControlStatus;
      pOutput->sLongControlStatus.uiSelectedObject                 = 0;
      pOutput->sLongControlStatus.eEcoMode                         = FCTCustomInputV6::FSRNormalMode;
      pOutput->CodingPar.CodingValue                               = 0;
      pOutput->CodingPar.Valid                                     = 0;
      pOutput->eTurnIndicator                                      = pInput->eTurnIndicator;
      // Now set output parameters
      *pOutData = pOutput;
      ulOutSize = sizeof(m_DataBufV7);
      RetVal    = SIM_ERR_OK;
    }
  }
  else if ((ePPortType == eRPortType) && (ulPPortSize == ulRPortSize) &&
    ((pProvidePortVersionInfo == NULL) || (requestPortVersionInfo.Equals(pProvidePortVersionInfo))))
  {
    // Use data directly, this is not appropriate for equally sized input and output data with different version numbers!
    // Therefore this comes at last stage as stopgap
    *pOutData = pPPortData;
    ulOutSize = ulPPortSize;
    RetVal    = SIM_ERR_OK;
  }
  return RetVal;
}
  
/** returns: 
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvFctCustomInput::GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    void** pDefaultData, unsigned long& ulDefaultSize)
{
  if (   eRPortType == simOPAQUE_t
      && ulRPortSize == sizeof(m_DataBufV17)
      && (VERSION17.Equals(&requestPortVersionInfo))
     )
  {
    FCTCustomInputV17::FCTCustomInput_t * pOutput = &m_DataBufV17;
    // Convert data
    pOutput->uiVersionNumber  = 0;
    pOutput->sProbabilityLaneChange.uiProbabilityLaneChangeLeft   = 0;
    pOutput->sProbabilityLaneChange.uiProbabilityLaneChangeRight  = 0;
    pOutput->sLongControlStatus.eLongControlStatus  = FSRFunctionEnabled;
    pOutput->sLongControlStatus.uiSelectedObject    = 0;
    pOutput->sLongControlStatus.eEcoMode            = 0;
    pOutput->sLongControlStatus.DPC_Md_AS_Rq        = 0;
    pOutput->sLongControlStatus.eACCS_CodingType    = 0;
    pOutput->CodingPar.CodingValue  = 0;
    pOutput->CodingPar.Valid        = 0;
    // And return
    *pDefaultData = pOutput;
    ulDefaultSize = sizeof(*pOutput);
    return SIM_ERR_OK;
  }
  else if (   eRPortType == simOPAQUE_t
      && ulRPortSize == sizeof(m_DataBufV2)
      && (   VERSION2.Equals(&requestPortVersionInfo)
          || VERSION3.Equals(&requestPortVersionInfo)
          || VERSION4.Equals(&requestPortVersionInfo)
          || VERSION5.Equals(&requestPortVersionInfo)
         )
     )
  {
    FCTCustomInputV2::FCTCustomInput_t * pOutput = &m_DataBufV2;
    // Convert data
    pOutput->uiVersionNumber  = 0;
    pOutput->sLongControlStatus.eLongControlStatus  = FSRFunctionEnabled;
    pOutput->sLongControlStatus.uiSelectedObject    = 0;
    pOutput->sProbabilityLaneChange.uiProbabilityLaneChangeLeft   = 0;
    pOutput->sProbabilityLaneChange.uiProbabilityLaneChangeRight  = 0;
    pOutput->CodingPar.CodingValue  = 0;
    pOutput->CodingPar.Valid        = 0;
    // And return
    *pDefaultData = pOutput;
    ulDefaultSize = sizeof(*pOutput);
    return SIM_ERR_OK;
  }
  else if (eRPortType == simOPAQUE_t
    && ulRPortSize == sizeof(m_DataBufV0)
    && BASE_VERSION.Equals(&requestPortVersionInfo))
  {
    FCTCustomInputV1::FCTCustomInput_t * pOutput = &m_DataBufV0;
    // Convert data
    pOutput->uiVersionNumber  = 0;
    pOutput->sLongControlStatus.eLongControlStatus  = FSRFunctionEnabled;
    pOutput->sLongControlStatus.uiSelectedObject    = 0;
    pOutput->sProbabilityLaneChange.uiProbabilityLaneChangeLeft   = 0;
    pOutput->sProbabilityLaneChange.uiProbabilityLaneChangeRight  = 0;
    // And return
    *pDefaultData = pOutput;
    ulDefaultSize = sizeof(*pOutput);
    return SIM_ERR_OK;
  }
  return SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvFctCustomInput::IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  if ((ulPPortSize == 4) && (ePPortType == simF32_t) && (eRPortType == simOPAQUE_t))
  {
    if ((ulRPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER2]) ||
        (ulRPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER1]))
    {
      bResult = true;
    }
  }
  else if  ((ulPPortSize == ulRPortSize) && (ePPortType == eRPortType))
  {
    // Assume they can match based on the size
    bResult = true;
  }
  else
  {
    bool bReqSupported = false;
    bool bProSupported = false;
    for (unsigned int i =0;(i<CConvFctCustomInput::FCT_CUSTOM_INPUT_NUM_VERSIONS) && ((!bReqSupported) || (!bProSupported));i++)
    {
      if ((ulRPortSize == SUPPORTED_SIZE[i]) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(SUPPORTED_VERSIONS[i]))))
      {
        bReqSupported = true;
      }
      if (ulPPortSize == SUPPORTED_SIZE[i])
      {
        bProSupported = true;
      }
    }
    bResult = bReqSupported && bProSupported;
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvFctCustomInput::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo)
{
  bool bResult = false;

  bool bPortsAreCompatible = false, bP=false, bR=false;
  for (unsigned int nI=0; (nI<FCT_CUSTOM_INPUT_NUM_VERSIONS) && !bP && !bR; nI++)
  {
    if (providePortVersionInfo.Equals(SUPPORTED_VERSIONS[nI])) bP=true;
    if (requestPortVersionInfo.Equals(SUPPORTED_VERSIONS[nI])) bR=true;
    if (bP && bR) bPortsAreCompatible=true;
  }

  if ((ulPPortSize == 4) && (ePPortType == simF32_t) &&
      (ulRPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER2]) && (eRPortType == simOPAQUE_t))
  {
    bResult = true;
  }
  else if ((ulPPortSize == 4) && (ePPortType == simF32_t) &&
      (ulRPortSize == SUPPORTED_SIZE[CConvFctCustomInput::FCT_CUSTOM_INPUT_INTFVER1]) && (eRPortType == simOPAQUE_t))
  {
    bResult = true;
  }
  else if ((ulPPortSize == ulRPortSize) && (eRPortType == ePPortType) && (bPortsAreCompatible==true))
  {
    bResult = true;
  }
  else
  {
    for (unsigned int i=0;i<CConvFctCustomInput::FCT_CUSTOM_INPUT_NUM_VERSIONS;i++)
    {
      bResult |= (ePPortType == eRPortType && ulRPortSize == sizeof(m_DataBufV0)&& ulPPortSize == SUPPORTED_SIZE[i] && BASE_VERSION.Equals(&requestPortVersionInfo));
    }
  }
  return bResult;
}

//
// Factory function
//
IConverter * CreateFctCustomInputConvInstance(void)
{
  return new CConvFctCustomInput();
}
