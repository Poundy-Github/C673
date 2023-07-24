/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter

  MODULNAME:            sim_conv_head_input_generic.cpp

  DESCRIPTION:          Convert pre cluster list header

  AUTHOR:               Stephan Kaelberer, Thomas Berndt

  CREATION DATE:        13.10.2015

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_head_input_generic.cpp  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:19CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.6 2016/11/09 10:15:38CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              * default set eFunctionSwitch with values extracted from a measurement
  CHANGES:              Revision 1.5 2016/11/08 16:16:58CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + uiVersionNumber == 3 and 0 for Hyndai using Toyota measurements
  CHANGES:              Revision 1.4 2016/09/30 07:32:04CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + Dest.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  CHANGES:              Revision 1.3 2016/08/31 13:51:10CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + V6 for ARS430BW18 and handling of V5 (equal to V4_4D2)
  CHANGES:              Revision 1.2 2016/05/09 14:25:13CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              * Corrected version number
  CHANGES:              Revision 1.1 2015/10/14 09:18:57CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/fct/project.pj

**************************************************************************** */

/* includes ---------------------------------------------------------------- */
#include <atlbase.h>                             // ATL includes
#include "sim_adapter_cfg.h"
#include "sim_conv_head_input_generic.h"
#include <math.h>

#include "sim_versioninfo_impl.h"

#define AL_SIG_STATE_INIT (0u)
#define AL_SIG_STATE_OK (1u)

#define _MINI(x,y) (x<y?x:y)

#define eFunctionSwitch_PedWarn       (1u)       /* x */
#define eFunctionSwitch_PedPreFill    (2u)
#define eFunctionSwitch_PedHBA        (4u)
#define eFunctionSwitch_PedBrakeL1    (8u)
#define eFunctionSwitch_PedBrakeL2    (16u)
#define eFunctionSwitch_PedBrakeL3    (32u)
#define eFunctionSwitch_PedPreCrash   (64u)
#define eFunctionSwitch_VehWarn       (128u)
#define eFunctionSwitch_VehLatentWarn (256u)
#define eFunctionSwitch_VehPreFill    (512u)
#define eFunctionSwitch_VehHBA        (1024u)
#define eFunctionSwitch_VehBrakeL1    (2048u)
#define eFunctionSwitch_VehBrakeL2    (4096u)
#define eFunctionSwitch_VehBrakeL3    (8192u)
#define eFunctionSwitch_VehPreCrash   (16384u)
#define eFunctionSwitch_ObjWarn       (32768u)   /* x */
#define eFunctionSwitch_ObjLatentWarn (65536u)   /* x */
#define eFunctionSwitch_ObjPreFill    (131072u)  /* x */
#define eFunctionSwitch_ObjHBA        (262144u)  /* x */
#define eFunctionSwitch_ObjBrakeL1    (524288u)  /* x */
#define eFunctionSwitch_ObjBrakeL2    (1048576u)
#define eFunctionSwitch_ObjBrakeL3    (2097152u)
#define eFunctionSwitch_ObjPreCrash   (4194304u) /* x */
#define eFunctionSwitch_MaxValue      (4294967295u)

typedef unsigned __int8 eMainSwitch_t                                /* @min: 0 @max:3 @values: enum { eMainSwitch_NotUsed=2,eMainSwitch_Inactive=1,eMainSwitch_Active=0,eMainSwitch_Invalid=3,} */	/* [Satisfies_rte sws 1188] */;
typedef unsigned long AlgoDataTimeStamp_t                            /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */ /* [Satisfies_rte sws 1188] */;
typedef unsigned short AlgoCycleCounter_t                            /* Algo cycle counter @min:0 @max:65535 */ /* [Satisfies_rte sws 1188] */;
typedef unsigned char AlgoSignalState_t                              /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */ /* [Satisfies_rte sws 1188] */;

typedef struct SignalHeader_t                                        /* [Satisfies_rte sws 1191] */
{
  AlgoDataTimeStamp_t uiTimeStamp;
  AlgoCycleCounter_t uiMeasurementCounter;
  AlgoCycleCounter_t uiCycleCounter;
  AlgoSignalState_t eSigStatus;
} SignalHeader_t;                                                    /* Common header for all structured data types */


namespace HEADInputGeneric_V4_4L1
{
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    eMainSwitch_t eMainSwitch;
  } HEADInputGeneric_t;                                              /* @vaddr:0x20230500 @vaddr_defs: FCT_MEAS_ID_HEAD_INPUT_GENERIC @cycleid:FCT_VEH_IN @vname:HEADInputGeneric */
}


namespace HEADInputGeneric_V4_4D2
{
  typedef unsigned long eFunctionSwitch_t                            /* @min: 1 @max:4294967295 @values: enum { eFunctionSwitch_ObjPreCrash=4194304,eFunctionSwitch_ObjBrakeL2=1048576,eFunctionSwitch_ObjBrakeL3=2097152,eFunctionSwitch_ObjBrakeL1=524288,eFunctionSwitch_PedBrakeL2=16,eFunctionSwitch_PedWarn=1,eFunctionSwitch_PedPreCrash=64,eFunctionSwitch_ObjLatentWarn=65536,eFunctionSwitch_VehPreCrash=16384,eFunctionSwitch_MaxValue=4294967295,eFunctionSwitch_VehLatentWarn=256,eFunctionSwitch_ObjPreFill=131072,eFunctionSwitch_ObjHBA=262144,eFunctionSwitch_PedBrakeL3=32,eFunctionSwitch_VehHBA=1024,eFunctionSwitch_PedBrakeL1=8,eFunctionSwitch_PedHBA=4,eFunctionSwitch_VehWarn=128,eFunctionSwitch_VehPreFill=512,eFunctionSwitch_VehBrakeL1=2048,eFunctionSwitch_VehBrakeL2=4096,eFunctionSwitch_VehBrakeL3=8192,eFunctionSwitch_PedPreFill=2,eFunctionSwitch_ObjWarn=32768,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned long eObjectSwitch_t                              /* @min: 1 @max:4294967295 @values: enum { eObjectSwitch_Vehicles=2,eObjectSwitch_MaxValue=4294967295,eObjectSwitch_Obstacle=4,eObjectSwitch_Pedestrians=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    eMainSwitch_t eMainSwitch;
    eFunctionSwitch_t eFunctionSwitch;
    eObjectSwitch_t eObjectSwitch;
  } HEADInputGeneric_t;                                              /* @vaddr:0x20230500 @vaddr_defs: FCT_MEAS_ID_HEAD_INPUT_GENERIC @cycleid:FCT_VEH_IN @vname:HEADInputGeneric */
}

namespace HEADInputGeneric_V6                                        /* ARS430BW18 */
{
  const unsigned char eDriverSetting_Early = 0;
  const unsigned char eEBASen0State_Avail = 1;
  const unsigned char eEBASen2State_Avail = 16;

  typedef unsigned long eFunctionSwitch_t;                           /* @min: 1 @max:4294967295 @values: enum { eFunctionSwitch_ObjPreCrash=4194304,eFunctionSwitch_ObjBrakeL2=1048576,eFunctionSwitch_ObjBrakeL3=2097152,eFunctionSwitch_ObjBrakeL1=524288,eFunctionSwitch_PedBrakeL2=16,eFunctionSwitch_PedWarn=1,eFunctionSwitch_PedPreCrash=64,eFunctionSwitch_ObjLatentWarn=65536,eFunctionSwitch_VehPreCrash=16384,eFunctionSwitch_MaxValue=4294967295,eFunctionSwitch_VehLatentWarn=256,eFunctionSwitch_ObjPreFill=131072,eFunctionSwitch_ObjHBA=262144,eFunctionSwitch_PedBrakeL3=32,eFunctionSwitch_VehHBA=1024,eFunctionSwitch_PedBrakeL1=8,eFunctionSwitch_PedHBA=4,eFunctionSwitch_VehWarn=128,eFunctionSwitch_VehPreFill=512,eFunctionSwitch_VehBrakeL1=2048,eFunctionSwitch_VehBrakeL2=4096,eFunctionSwitch_VehBrakeL3=8192,eFunctionSwitch_PedPreFill=2,eFunctionSwitch_ObjWarn=32768,} */ /* [Satisfies_rte sws 1188] */
  typedef unsigned char eDriverSetting_t;                            /* @min: 0 @max:3 @values: enum { eDriverSetting_Invalid=3,eDriverSetting_Late=2,eDriverSetting_Early=0,eDriverSetting_Middle=1,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char eEBASensorState_t;                           /* Describes the global sensor state delivering object data. Four sensor with three states can be described @min: 0 @max:192 @values: enum { eEBASenState_Invalid=0,eEBASen0State_Avail=1,eEBASen0State_Invalid=3,eEBASen0State_Degr=2,eEBASen3State_Invalid=192,eEBASen2State_Invalid=48,eEBASen3State_Avail=64,eEBASen1State_Invalid=12,eEBASen3State_Degr=128,eEBASen2State_Degr=32,eEBASen2State_Avail=16,eEBASen1State_Degr=8,eEBASen1State_Avail=4,} */ /* [Satisfies_rte sws 1188] */;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    eMainSwitch_t eMainSwitch;
    eFunctionSwitch_t eFunctionSwitch;
    eDriverSetting_t eDriverSetting;
    eEBASensorState_t eObjSensorState;
  } HEADInputGeneric_t;                                              /* @vaddr:0x20230500 @vaddr_defs: FCT_MEAS_ID_HEAD_INPUT_GENERIC @cycleid:FCT_VEH_IN @vname:HEADInputGeneric */
}


namespace HEADInputGeneric_GenAll
{
  typedef unsigned long eFunctionSwitch_t                            /* @min: 1 @max:4294967295 @values: enum { eFunctionSwitch_ObjPreCrash=4194304,eFunctionSwitch_ObjBrakeL2=1048576,eFunctionSwitch_ObjBrakeL3=2097152,eFunctionSwitch_ObjBrakeL1=524288,eFunctionSwitch_PedBrakeL2=16,eFunctionSwitch_PedWarn=1,eFunctionSwitch_PedPreCrash=64,eFunctionSwitch_ObjLatentWarn=65536,eFunctionSwitch_VehPreCrash=16384,eFunctionSwitch_MaxValue=4294967295,eFunctionSwitch_VehLatentWarn=256,eFunctionSwitch_ObjPreFill=131072,eFunctionSwitch_ObjHBA=262144,eFunctionSwitch_PedBrakeL3=32,eFunctionSwitch_VehHBA=1024,eFunctionSwitch_PedBrakeL1=8,eFunctionSwitch_PedHBA=4,eFunctionSwitch_VehWarn=128,eFunctionSwitch_VehPreFill=512,eFunctionSwitch_VehBrakeL1=2048,eFunctionSwitch_VehBrakeL2=4096,eFunctionSwitch_VehBrakeL3=8192,eFunctionSwitch_PedPreFill=2,eFunctionSwitch_ObjWarn=32768,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned long eObjectSwitch_t                              /* @min: 1 @max:4294967295 @values: enum { eObjectSwitch_Vehicles=2,eObjectSwitch_MaxValue=4294967295,eObjectSwitch_Obstacle=4,eObjectSwitch_Pedestrians=1,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char eDriverSetting_t;                            /* @min: 0 @max:3 @values: enum { eDriverSetting_Invalid=3,eDriverSetting_Late=2,eDriverSetting_Early=0,eDriverSetting_Middle=1,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char eEBASensorState_t;                           /* Describes the global sensor state delivering object data. Four sensor with three states can be described @min: 0 @max:192 @values: enum { eEBASenState_Invalid=0,eEBASen0State_Avail=1,eEBASen0State_Invalid=3,eEBASen0State_Degr=2,eEBASen3State_Invalid=192,eEBASen2State_Invalid=48,eEBASen3State_Avail=64,eEBASen1State_Invalid=12,eEBASen3State_Degr=128,eEBASen2State_Degr=32,eEBASen2State_Avail=16,eEBASen1State_Degr=8,eEBASen1State_Avail=4,} */ /* [Satisfies_rte sws 1188] */;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    eMainSwitch_t eMainSwitch;
    eFunctionSwitch_t eFunctionSwitch;
    eObjectSwitch_t eObjectSwitch;
    eDriverSetting_t eDriverSetting;
    eEBASensorState_t eObjSensorState;
  } HEADInputGeneric_t;                                              /* @vaddr:0x20230500 @vaddr_defs: FCT_MEAS_ID_HEAD_INPUT_GENERIC @cycleid:FCT_VEH_IN @vname:HEADInputGeneric */
}


class CConvHeadInputGeneric : public CSimConverterBase
{
  // the list of dependency names used inside by the converter
  //static const TCHAR *DEP_NAMES[];

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here
    DEP_COUNT
  };

  HEADInputGeneric_GenAll::HEADInputGeneric_t m_Buf_GenAll;
  HEADInputGeneric_V4_4L1::HEADInputGeneric_t m_Buf_V4_4L1;
  HEADInputGeneric_V4_4D2::HEADInputGeneric_t m_Buf_V4_4D2;
  HEADInputGeneric_V6::HEADInputGeneric_t m_Buf_V6;

  // Initialization of header
  template <typename T> static void InitHeadInputGeneric (T & Dest, unsigned long VersionNumber)
  {
    ::memset(&(Dest), 0, sizeof(Dest));
    Dest.uiVersionNumber = VersionNumber;
  }

public:

  CConvHeadInputGeneric(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT)
  {
    InitHeadInputGeneric(m_Buf_V4_4L1, 4);
    InitHeadInputGeneric(m_Buf_V4_4D2, 4);
    InitHeadInputGeneric(m_Buf_V6, 6);
    InitHeadInputGeneric(m_Buf_GenAll, 4);
  };

  // Not implemented copy constructor to get linker error
  CConvHeadInputGeneric(const CConvHeadInputGeneric & init);

  virtual ~CConvHeadInputGeneric(void)
  {
  };

  // IConverterDestroy::Destroy implementation
  virtual void Destroy()
  {
    delete this;
  };

  // IConverter::GetTypeName implementation
  virtual const char *GetTypeName(void)
  {
    return "HEADInputGeneric_t";
  };

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < HEADINPUTGENERIC_VERSION_COUNT; nI++)
    {
      if ((pPortVersion == NULL) || pPortVersion->Equals(VERSION_NUMBERS[nI]))
      {
        if (ulPortSize == SUPPORTED_SIZE[nI])
        {
          return true;
        }
      }
    };
    return false;
  };

  bool VersionNumbersEqual(const unsigned __int32 uDataVer, const IVersionInfo &requestPortVersionInfo, const IVersionInfo *pProvidePortVersionInfo)
  {
    bool retval = false;

    if (requestPortVersionInfo.Equals(VERSION_NUMBERS[HEADINPUTGENERIC_V6]) && (uDataVer == 6u))
    {
      retval = true;
    }
    if (requestPortVersionInfo.Equals(VERSION_NUMBERS[HEADINPUTGENERIC_V5]) && (uDataVer == 5u))
    {
      retval = true;
    }
    if (requestPortVersionInfo.Equals(VERSION_NUMBERS[HEADINPUTGENERIC_V4_4D2]) && (uDataVer == 4u))
    {
      retval = true;
    }
    if (requestPortVersionInfo.Equals(VERSION_NUMBERS[HEADINPUTGENERIC_V4_4L1]) && (uDataVer == 4u))
    {
      retval = true;
    }
    return retval;
  }

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_VALUE_FROM_PPORT - when the conversion is not implemented here
   *                                  and the value from Provide Port must be used
   */
  long ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
    void *pPPortData,
    void **pOutData, unsigned long &ulOutSize);

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implemented here
   *                                            and the default value from Request Port must be used
   */
  long GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    void **pDefaultData, unsigned long& ulDefaultSize);

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
  static CVersionInfoImpl Version3;
  static CVersionInfoImpl Version4;
  static CVersionInfoImpl Version5;
  static CVersionInfoImpl Version6;

  enum eHeadInputGeneric
  {
    HEADINPUTGENERIC_V3_4T0,
    HEADINPUTGENERIC_V4_4L1,
    HEADINPUTGENERIC_V4_4D2,
    HEADINPUTGENERIC_V5,
    HEADINPUTGENERIC_V6,
    HEADINPUTGENERIC_VERSION_COUNT
  };

  static const unsigned long SUPPORTED_SIZE[HEADINPUTGENERIC_VERSION_COUNT];

  static const CVersionInfoImpl * const VERSION_NUMBERS[HEADINPUTGENERIC_VERSION_COUNT];
};

//const TCHAR *CConvHeadInputGeneric::DEP_NAMES[CConvHeadInputGeneric::DEP_COUNT] = {_T(""), _T(""), _T("")};

CVersionInfoImpl CConvHeadInputGeneric::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvHeadInputGeneric::Version3(0, 0, 3);
CVersionInfoImpl CConvHeadInputGeneric::Version4(0, 0, 4);
CVersionInfoImpl CConvHeadInputGeneric::Version5(0, 0, 5);
CVersionInfoImpl CConvHeadInputGeneric::Version6(0, 0, 6);

const unsigned long CConvHeadInputGeneric::SUPPORTED_SIZE[CConvHeadInputGeneric::HEADINPUTGENERIC_VERSION_COUNT]=
{
  sizeof(HEADInputGeneric_V4_4D2::HEADInputGeneric_t),
  sizeof(HEADInputGeneric_V4_4L1::HEADInputGeneric_t),
  sizeof(HEADInputGeneric_V4_4D2::HEADInputGeneric_t),
  sizeof(HEADInputGeneric_V4_4D2::HEADInputGeneric_t),
  sizeof(HEADInputGeneric_V6::HEADInputGeneric_t)
};

const CVersionInfoImpl * const CConvHeadInputGeneric::VERSION_NUMBERS[CConvHeadInputGeneric::HEADINPUTGENERIC_VERSION_COUNT] =
{
  &Version3,
  &Version4,
  &Version4,
  &Version5,
  &Version6
};


static void Convert_V4_4L1_to_Gen(HEADInputGeneric_GenAll::HEADInputGeneric_t & Dest, const HEADInputGeneric_V4_4L1::HEADInputGeneric_t & Src)
{
  Dest.uiVersionNumber = Src.uiVersionNumber;
  Dest.sSigHeader = Src.sSigHeader;
  Dest.eMainSwitch = Src.eMainSwitch;
  Dest.eFunctionSwitch = 0xBFFFFFFF;
  Dest.eObjectSwitch = 0;
  Dest.eDriverSetting = HEADInputGeneric_V6::eDriverSetting_Early;
  Dest.eObjSensorState = HEADInputGeneric_V6::eEBASen0State_Avail | HEADInputGeneric_V6::eEBASen2State_Avail;
}

static void Convert_V4_4D2_to_Gen(HEADInputGeneric_GenAll::HEADInputGeneric_t & Dest, const HEADInputGeneric_V4_4D2::HEADInputGeneric_t & Src)
{
  Dest.uiVersionNumber = Src.uiVersionNumber;
  Dest.sSigHeader = Src.sSigHeader;
  Dest.eMainSwitch = Src.eMainSwitch;
  Dest.eFunctionSwitch = Src.eFunctionSwitch;
  Dest.eObjectSwitch = Src.eObjectSwitch;
  Dest.eDriverSetting = HEADInputGeneric_V6::eDriverSetting_Early;
  Dest.eObjSensorState = HEADInputGeneric_V6::eEBASen0State_Avail | HEADInputGeneric_V6::eEBASen2State_Avail;
  // Workaround for Dest.sSigHeader.eSigStatus == 0
  // Introduced for ARS410GY18 and ARS410HI17: Works for Toyota Measurements with PPort Version 4 and different RPort Version (E.g.: 5)
  if (Dest.sSigHeader.eSigStatus == AL_SIG_STATE_INIT)
  {
    Dest.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
    if (Dest.eFunctionSwitch == 0)
    {
      Dest.eFunctionSwitch =
        eFunctionSwitch_PedWarn +
        eFunctionSwitch_ObjWarn +
        eFunctionSwitch_ObjLatentWarn +
        eFunctionSwitch_ObjPreFill +
        eFunctionSwitch_ObjHBA +
        eFunctionSwitch_ObjBrakeL1 +
        eFunctionSwitch_ObjPreCrash;
    }
  }
}

static void Convert_V6_to_Gen(HEADInputGeneric_GenAll::HEADInputGeneric_t & Dest, const HEADInputGeneric_V6::HEADInputGeneric_t & Src)
{
  Dest.uiVersionNumber = Src.uiVersionNumber;
  Dest.sSigHeader = Src.sSigHeader;
  Dest.eMainSwitch = Src.eMainSwitch;
  Dest.eFunctionSwitch = Src.eFunctionSwitch;
  Dest.eObjectSwitch = 0;
  Dest.eDriverSetting = Src.eDriverSetting;
  Dest.eObjSensorState = Src.eObjSensorState;
}

static void Convert_Gen_to_V4_4D2(HEADInputGeneric_V4_4D2::HEADInputGeneric_t & Dest, const HEADInputGeneric_GenAll::HEADInputGeneric_t & Src)
{
  //Dest.uiVersionNumber = /*Src.uiVersionNumber*/ 4u; // Version number set by InitHeadInputGeneric. Therefore must be called before!
  Dest.sSigHeader = Src.sSigHeader;
  Dest.eMainSwitch = Src.eMainSwitch;
  Dest.eFunctionSwitch = Src.eFunctionSwitch;
  Dest.eObjectSwitch = Src.eObjectSwitch;
}

static void Convert_Gen_to_V4_4L1(HEADInputGeneric_V4_4L1::HEADInputGeneric_t & Dest, const HEADInputGeneric_GenAll::HEADInputGeneric_t & Src)
{
  //Dest.uiVersionNumber = /*Src.uiVersionNumber*/ 4u; // Version number set by InitHeadInputGeneric. Therefore must be called before!
  Dest.sSigHeader = Src.sSigHeader;
  Dest.eMainSwitch = Src.eMainSwitch;
}

static void Convert_Gen_to_V6(HEADInputGeneric_V6::HEADInputGeneric_t & Dest, const HEADInputGeneric_GenAll::HEADInputGeneric_t & Src)
{
  //Dest.uiVersionNumber = /*Src.uiVersionNumber*/ 4u; // Version number set by InitHeadInputGeneric. Therefore must be called before!
  Dest.sSigHeader = Src.sSigHeader;
  Dest.eMainSwitch = Src.eMainSwitch;
  Dest.eFunctionSwitch = Src.eFunctionSwitch;
  Dest.eDriverSetting = Src.eDriverSetting;
  Dest.eObjSensorState = Src.eObjSensorState;
}


long CConvHeadInputGeneric::ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
    void *pPPortData,
    void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  bool bGenBufferFilled = false;

  const unsigned __int32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<unsigned __int32*>(pPPortData)):(0);

  // First decide which version we are converting to
  if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    // If ports equal, then always compatible
    if ((ulRPortSize == ulPPortSize) && VersionNumbersEqual(uDataVer, requestPortVersionInfo, pProvidePortVersionInfo))
    {
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
    // First decide from which version we are converting and fill the generic buffer accordingly
    else if ((ulPPortSize == SUPPORTED_SIZE[HEADINPUTGENERIC_V6])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(VERSION_NUMBERS[HEADINPUTGENERIC_V6])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer == 6u))
    {
      // Source Port V6 of ARS430B18
      InitHeadInputGeneric(m_Buf_GenAll, 6);
      const HEADInputGeneric_V6::HEADInputGeneric_t & Src = *reinterpret_cast<HEADInputGeneric_V6::HEADInputGeneric_t*>(pPPortData);
      Convert_V6_to_Gen(m_Buf_GenAll, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[HEADINPUTGENERIC_V5])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(VERSION_NUMBERS[HEADINPUTGENERIC_V5])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer == 5u))
    {
      // Source Port V5 of ARS430B18 (is equal to V4_ARS4D2!)
      InitHeadInputGeneric(m_Buf_GenAll, 5);
      const HEADInputGeneric_V4_4D2::HEADInputGeneric_t & Src = *reinterpret_cast<HEADInputGeneric_V4_4D2::HEADInputGeneric_t*>(pPPortData);
      Convert_V4_4D2_to_Gen(m_Buf_GenAll, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[HEADINPUTGENERIC_V4_4D2])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(VERSION_NUMBERS[HEADINPUTGENERIC_V4_4D2])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer == 4u))
    {
      // Source Port V4 of ARS4D2
      InitHeadInputGeneric(m_Buf_GenAll, 4);
      const HEADInputGeneric_V4_4D2::HEADInputGeneric_t & Src = *reinterpret_cast<HEADInputGeneric_V4_4D2::HEADInputGeneric_t*>(pPPortData);
      Convert_V4_4D2_to_Gen(m_Buf_GenAll, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[HEADINPUTGENERIC_V4_4L1])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(VERSION_NUMBERS[HEADINPUTGENERIC_V4_4L1])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer == 4u))
    {
      // Source Port V4 of ARS4L1
      InitHeadInputGeneric(m_Buf_GenAll, 4);
      const HEADInputGeneric_V4_4L1::HEADInputGeneric_t & Src = *reinterpret_cast<HEADInputGeneric_V4_4L1::HEADInputGeneric_t*>(pPPortData);
      Convert_V4_4L1_to_Gen(m_Buf_GenAll, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[HEADINPUTGENERIC_V3_4T0])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(VERSION_NUMBERS[HEADINPUTGENERIC_V3_4T0])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 3u) || (uDataVer == 0)))
    {
      // Source Port V3 of ARS4T0
      InitHeadInputGeneric(m_Buf_GenAll, 3);
      const HEADInputGeneric_V4_4D2::HEADInputGeneric_t & Src = *reinterpret_cast<HEADInputGeneric_V4_4D2::HEADInputGeneric_t*>(pPPortData);
      Convert_V4_4D2_to_Gen(m_Buf_GenAll, Src);
      bGenBufferFilled = true;
    }

    if (bGenBufferFilled == true)
    {
      // Second decide to which version we are converting
      // and take the generic buffer to fill the destination buffer
      if ((ulRPortSize == SUPPORTED_SIZE[HEADINPUTGENERIC_V6]) && (requestPortVersionInfo.Equals(VERSION_NUMBERS[HEADINPUTGENERIC_V6])))
      {
        // Destination port of V6
        InitHeadInputGeneric(m_Buf_V6, 6);
        Convert_Gen_to_V6(m_Buf_V6, m_Buf_GenAll);
        *pOutData = &m_Buf_V6;
        ulOutSize = sizeof(m_Buf_V6);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[HEADINPUTGENERIC_V4_4D2]) && (requestPortVersionInfo.Equals(VERSION_NUMBERS[HEADINPUTGENERIC_V5])))
      {
        // Destination port of V5 of ARS430BW18 (same as 4D2)
        InitHeadInputGeneric(m_Buf_V4_4D2, 5);
        Convert_Gen_to_V4_4D2(m_Buf_V4_4D2, m_Buf_GenAll);
        *pOutData = &m_Buf_V4_4D2;
        ulOutSize = sizeof(m_Buf_V4_4D2);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[HEADINPUTGENERIC_V4_4D2]) && (requestPortVersionInfo.Equals(VERSION_NUMBERS[HEADINPUTGENERIC_V4_4D2])))
      {
        // Destination port of V4 of 4D2
        InitHeadInputGeneric(m_Buf_V4_4D2, 4);
        Convert_Gen_to_V4_4D2(m_Buf_V4_4D2, m_Buf_GenAll);
        *pOutData = &m_Buf_V4_4D2;
        ulOutSize = sizeof(m_Buf_V4_4D2);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[HEADINPUTGENERIC_V4_4L1]) && (requestPortVersionInfo.Equals(VERSION_NUMBERS[HEADINPUTGENERIC_V4_4L1])))
      {
        // Destination port of V4 of 4L1
        InitHeadInputGeneric(m_Buf_V4_4L1, 4);
        Convert_Gen_to_V4_4L1(m_Buf_V4_4L1, m_Buf_GenAll);
        *pOutData = &m_Buf_V4_4L1;
        ulOutSize = sizeof(m_Buf_V4_4L1);
        lRet = SIM_ERR_OK;
      }
    }
  }
  return lRet;
}

/** returns:
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvHeadInputGeneric::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == SUPPORTED_SIZE[HEADINPUTGENERIC_V6]) &&
      (VERSION_NUMBERS[HEADINPUTGENERIC_V6]->Equals(&requestPortVersionInfo)))
    {
      HEADInputGeneric_V6::HEADInputGeneric_t & Dest = m_Buf_V6;
      InitHeadInputGeneric(Dest, 6);
      Dest.eFunctionSwitch = 0xBFFFFFFF;
      Dest.eDriverSetting = HEADInputGeneric_V6::eDriverSetting_Early;
      Dest.eObjSensorState = HEADInputGeneric_V6::eEBASen0State_Avail | HEADInputGeneric_V6::eEBASen2State_Avail;
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[HEADINPUTGENERIC_V4_4D2]) &&
      (VERSION_NUMBERS[HEADINPUTGENERIC_V4_4D2]->Equals(&requestPortVersionInfo)))
    {
      HEADInputGeneric_V4_4D2::HEADInputGeneric_t & Dest = m_Buf_V4_4D2;
      InitHeadInputGeneric(Dest, 4);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[HEADINPUTGENERIC_V4_4L1]) &&
      (VERSION_NUMBERS[HEADINPUTGENERIC_V4_4L1]->Equals(&requestPortVersionInfo)))
    {
      HEADInputGeneric_V4_4L1::HEADInputGeneric_t & Dest = m_Buf_V4_4L1;
      InitHeadInputGeneric(Dest, 4);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvHeadInputGeneric::IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
  {
    bResult = true;
  }
  else
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, NULL)))
    {
      bResult = true;
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvHeadInputGeneric::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo)
{
  bool bResult = false;
  // If ports equal, then always compatible
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize) && (requestPortVersionInfo.Equals(&providePortVersionInfo)))
  {
    bResult = true;
  }
  else
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, &providePortVersionInfo)))
    {
      bResult = true;
    }
  }
  return bResult;
}

//
// The one and only externally visible factory function
//
IConverter * CreateHeadInputGenericConvInstance(void)
{
  return new CConvHeadInputGeneric();
}