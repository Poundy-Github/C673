/*! \file **********************************************************************

COMPANY:         Continental

PROJECT:         Simulation

COMPONENT:       sim_adapter aln

MODULNAME:       sim_conv_aln_siminit

DESCRIPTION:     Conversion module

AUTHOR:          Jakob Schluttig / Mohammad Altamash Yakoob

CREATION DATE:   15.02.2016

VERSION:         $Revision: 1.1 $

---*/ /*---
CHANGES:         $Log: sim_conv_aln_siminit.cpp  $
CHANGES:         Revision 1.1 2017/08/10 13:14:53CEST uid34177 
CHANGES:         Initial revision
CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/aln/project.pj
CHANGES:         Revision 2.2 2017/05/17 08:23:04CEST Schmitz, David (uidq6182) 
CHANGES:         * New version of the siminit structure added V103
CHANGES:         * Added the RAM monopulse curve to the siminit NVM structure (193 sint16 values)
CHANGES:         Revision 2.1 2017/04/05 13:30:06CEST Yakoob, Mohammad Altamash (uidj9850) 
CHANGES:         [ARS5xx/SRR5xx]
CHANGES:         ? Remove A Sample compatilbility
CHANGES:         ? Clean up SimAdapters
CHANGES:         ? Only have version V100 and above
CHANGES:         Revision 1.7 2017/03/22 12:47:12CET Yakoob, Mohammad Altamash (uidj9850) 
CHANGES:         [ARS5xx/SRR5xx]  Remove unused b_Changed flag from interface to RHC
CHANGES:         Revision 1.6 2017/03/09 11:32:55CET Yakoob, Mohammad Altamash (uidj9850) 
CHANGES:         [ARS5xx/SRR5xx] Update SimAdapters for ALN_SimInit V102 and ALN_SimInitMon V103
CHANGES:         Revision 1.5 2017/02/15 15:55:42CET Yakoob, Mohammad Altamash (uidj9850) 
CHANGES:         [ARS510/SRR520] Update SimAdapter for the interface changes caused by removal of Elevation feature in SRR520
CHANGES:         Revision 1.4 2016/11/18 08:01:12CET Yakoob, Mohammad Altamash (uidj9850) 
CHANGES:         [ARS510/SRR520] Fix: Allow both Amplitude and Phase to be adjusted to the NVM once in the current ignition cycle
CHANGES:         -> "ALM_SimInit" adapter changes
CHANGES:         Revision 1.3 2016/09/13 10:16:20CEST Yakoob, Mohammad Altamash (uidj9850) 
CHANGES:         Update Simulation adapters and Simulation plugin for ARS510
CHANGES:         Revision 1.2 2016/02/16 07:41:43CET Schluttig, Jakob (uidv7098) 
CHANGES:         activated adaption code line (mistakenly commented)
CHANGES:         Revision 1.1 2016/02/15 17:32:37CET Schluttig, Jakob (uidv7098) 
CHANGES:         Initial revision
CHANGES:         Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ALN_Alignment/04_Engineering/03_Workspace/algo/sim_adapter/aln/project.pj
CHANGES:         Revision 1.19 2015/07/30 09:34:20CEST Schluttig, Jakob (uidv7098) 
CHANGES:         + new IF version 10: added b_EolTargetIsCorner , updated interface version number, size is the same as V8_2 and V9_1
CHANGES:         - Added comments -  uidv7098 [Jul 30, 2015 9:34:20 AM CEST]
CHANGES:         Change Package : 361863:1 http://mks-psad:7002/im/viewissue?selection=361863
CHANGES:         Revision 1.18 2015/07/13 10:09:01CEST Berndt, Thomas01 (berndtt1) 
CHANGES:         + new IF version 9: added b_DrivingLevelDeadjusted, updated interface version number, size is the same as V8_2
CHANGES:         --- Added comments ---  berndtt1 [Jul 13, 2015 10:14:41 AM CEST]
CHANGES:         Change Package : 221167:45 http://mks-psad:7002/im/viewissue?selection=221167
CHANGES:         Revision 1.17 2014/11/10 16:07:08CET Schluttig, Jakob (uidv7098) 
CHANGES:         added new IF vers. 8 including b_EolInspection flag also for ARS400 (unfortunately, interface version number was not updated)
CHANGES:         --- Added comments ---  uidv7098 [Nov 10, 2014 4:07:08 PM CET]
CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
CHANGES:         Revision 1.16 2014/10/09 16:24:58CEST Manea, Gabriela (ManeaG) 
CHANGES:         small fix for V8 (SRR projects)
CHANGES:         --- Added comments ---  ManeaG [Oct 9, 2014 4:24:58 PM CEST]
CHANGES:         Change Package : 263320:1 http://mks-psad:7002/im/viewissue?selection=263320
CHANGES:         Revision 1.15 2014/09/29 17:23:26CEST Schluttig, Jakob (uidv7098) 
CHANGES:         added interface V8
CHANGES:         --- Added comments ---  uidv7098 [Sep 29, 2014 5:23:27 PM CEST]
CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
CHANGES:         Revision 1.14 2014/09/15 15:03:42CEST Schluttig, Jakob (uidv7098) 
CHANGES:         fixed intf. version 7 for ARS400
CHANGES:         --- Added comments ---  uidv7098 [Sep 15, 2014 3:03:42 PM CEST]
CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
CHANGES:         Revision 1.13 2014/07/23 17:10:57CEST Schluttig, Jakob (uidv7098) 
CHANGES:         always allow direct copy (do not explicitely check for intf version number in case of correct size)
CHANGES:         Revision 1.12 2014/07/10 15:48:03CEST Manea, Gabriela (ManeaG) 
CHANGES:         added intf-version-no. 7 for SRR
CHANGES:         --- Added comments ---  ManeaG [Jul 10, 2014 3:48:03 PM CEST]
CHANGES:         Change Package : 212023:2 http://mks-psad:7002/im/viewissue?selection=212023
CHANGES:         Revision 1.11 2014/07/08 16:23:57CEST Schluttig, Jakob (uidv7098) 
CHANGES:         added new IF versions for direct copy
CHANGES:         --- Added comments ---  uidv7098 [Jul 8, 2014 4:23:57 PM CEST]
CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
CHANGES:         Revision 1.10 2014/05/08 09:11:40CEST Schluttig, Jakob (uidv7098) 
CHANGES:         fixed compiler warning (implicit cast)
CHANGES:         --- Added comments ---  uidv7098 [May 8, 2014 9:11:41 AM CEST]
CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
CHANGES:         Revision 1.9 2014/04/04 11:27:51CEST Schluttig, Jakob (uidv7098) 
CHANGES:         added earlier Entry interface
CHANGES:         --- Added comments ---  uidv7098 [Apr 4, 2014 11:27:51 AM CEST]
CHANGES:         Change Package : 215877:1 http://mks-psad:7002/im/viewissue?selection=215877
CHANGES:         Revision 1.7 2014/03/24 14:51:28CET Schluttig, Jakob (uidv7098) 
CHANGES:         added intf-version-no. 5 for SRR
CHANGES:         --- Added comments ---  uidv7098 [Mar 24, 2014 2:51:28 PM CET]
CHANGES:         Change Package : 208727:1 http://mks-psad:7002/im/viewissue?selection=208727
CHANGES:         Revision 1.6 2014/03/20 12:15:09CET Schluttig, Jakob (uidv7098) 
CHANGES:         + ALN_BSWIn_t_ARS4xx_V6_1
CHANGES:         --- Added comments ---  uidv7098 [Mar 20, 2014 12:15:09 PM CET]
CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
CHANGES:         Revision 1.5 2014/02/19 12:57:36CET Manea, Gabriela (ManeaG) 
CHANGES:         Added SRR conversions , as a sigle adapter will be used for both projects. Updated ALN_BSWIn_t_ARS4xx_Gen
CHANGES:         --- Added comments ---  ManeaG [Feb 19, 2014 12:57:36 PM CET]
CHANGES:         Change Package : 212023:1 http://mks-psad:7002/im/viewissue?selection=212023
CHANGES:         Revision 1.4 2014/01/27 13:11:27CET Berndt, Thomas01 (berndtt1) 
CHANGES:         + ALN_BSWIn_t_ARS4xx_V4_2 
CHANGES:         + ALN_BSWIn_t_ARS4xx_Gen and new conversion strategy instead of N*N only N+N conversions
CHANGES:         --- Added comments ---  berndtt1 [Jan 27, 2014 2:36:33 PM CET]
CHANGES:         Change Package : 208935:9 http://mks-psad:7002/im/viewissue?selection=208935
CHANGES:         Revision 1.3 2014/01/13 07:45:13CET Schluttig, Jakob (uidv7098) 
CHANGES:         adapted to rare cases, where version number was set incorrectly (V3)
CHANGES:         --- Added comments ---  uidv7098 [Jan 13, 2014 7:45:14 AM CET]
CHANGES:         Change Package : 183794:1 http://mks-psad:7002/im/viewissue?selection=183794
CHANGES:         Revision 1.2 2013/11/29 14:47:22CET Berndt, Thomas01 (berndtt1) 
CHANGES:         Added V4 of ALN_BSWIn_t
CHANGES:         --- Added comments ---  berndtt1 [Nov 29, 2013 4:10:00 PM CET]
CHANGES:         Change Package : 208935:2 http://mks-psad:7002/im/viewissue?selection=208935
CHANGES:         Revision 1.1 2013/08/30 16:19:40CEST Berndt, Thomas01 (berndtt1) 
CHANGES:         Initial revision
CHANGES:         Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/aln/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_conv_aln_siminit.h"
#include "sim_versioninfo_impl.h"
#include "sim_adapter_cfg.h"

// Commonly used type definitions
typedef float float32;
typedef unsigned __int8 boolean, uint8;
typedef unsigned __int32 uint32;
typedef signed short sint16;
typedef unsigned long AlgoDataTimeStamp_t;
typedef unsigned short AlgoCycleCounter_t;
typedef unsigned char AlgoSignalState_t;

typedef struct SignalHeader_t
{
  AlgoDataTimeStamp_t uiTimeStamp;
  AlgoCycleCounter_t uiMeasurementCounter;
  AlgoCycleCounter_t uiCycleCounter;
  AlgoSignalState_t eSigStatus;
} SignalHeader_t;

typedef unsigned char e_AlnOpMode_t;

typedef struct
{
	signed short s_Real;
 	signed short s_Imag;
} t_Complex16;

/* Number of Channels */
#define ALN_SimInit_NumOfChannels         (12u)

/* Number of PathCompensation Features */
#define ALN_NVM_u_PATH_COMP_NOF_FEATURES  (2u)

/* Number of Monopulse learning values in the NVM */
#define ALN_COMMON_u_MonopulseNvmNofSamples (193u)

// ALN_MTS_MEAS_t_SimInitMem version 100
namespace ALN_SimInit_t_Radar5xx_V100
{
  typedef struct 
  {
    uint32 ui32_BaseVersion;
    uint8  ui8_CustVersion;
    uint8  ui8_Project;
    uint8  u_MeasFreezeCounter;
    uint8  u_MeasFreezeCounterCallback;
  } ALN_MainVersion;

  typedef struct
  {
    e_AlnOpMode_t e_OpMode_Previous;
    uint8         ui8_NofCyclesWaitAfterHwConfigChanged;
    boolean       b_AzimuthErrorRaised;
    boolean       b_ElevationErrorRaised;
    e_AlnOpMode_t e_OpModeBeforePause;
    e_AlnOpMode_t e_InternalOpMode;
    uint8         Dummy[2];
  } ALN_MAIN_t_SimInit;

  typedef struct 
  {
    t_Complex16 a_PathCompApplied[ALN_SimInit_NumOfChannels];
    float32     f_ElevationApplied;
    uint32      u_CyclesSinceLastNvmUpdate;
    uint32      u_MinCyclesNvmUpdate;
    uint8       u_PathCompContingent[ALN_NVM_u_PATH_COMP_NOF_FEATURES];
    uint8       u_NofCyclesWaitForNvm;
    boolean     b_WaitForWrite;
    boolean     b_ElevationAppliedValid;
  } ALN_NVM_t_SimInit;

  typedef struct
  {
    uint32             u_VersionNumber;
    SignalHeader_t     sSigHeader;
    ALN_MAIN_t_SimInit s_Main;
    ALN_NVM_t_SimInit  s_Nvm;
    ALN_MainVersion    s_MainVersion;
  } ALN_SM_t_NonSharedMem;
}// ALN_MTS_MEAS_t_SimInitMem version 100


// ALN_MTS_MEAS_t_SimInitMem version 101
namespace ALN_SimInit_t_Radar5xx_V101
{
  typedef struct
  {
    e_AlnOpMode_t e_OpMode_Previous;
    uint8         ui8_NofCyclesWaitAfterHwConfigChanged;
    boolean       b_AzimuthErrorRaised;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    boolean       b_ElevationErrorRaised;
#endif            
    e_AlnOpMode_t e_OpModeBeforePause;
    e_AlnOpMode_t e_InternalOpMode;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    uint8         Dummy[2];
#else
    uint8         Dummy[3];
#endif
  } ALN_MAIN_t_SimInit;

  typedef struct 
  {
    t_Complex16 a_PathCompApplied[ALN_SimInit_NumOfChannels];
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    float32     f_ElevationApplied;
#endif
    uint32      u_CyclesSinceLastNvmUpdate;
    uint32      u_MinCyclesNvmUpdate;
    uint8       u_PathCompContingent[ALN_NVM_u_PATH_COMP_NOF_FEATURES];
    uint8       u_NofCyclesWaitForNvm;
    boolean     b_WaitForWrite;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    boolean     b_ElevationAppliedValid;
#else
    uint8       u_Dummy;
#endif
  } ALN_NVM_t_SimInit;

  typedef struct
  {
    uint32                                       u_VersionNumber;
    SignalHeader_t                               sSigHeader;
    ALN_MAIN_t_SimInit                           s_Main;
    ALN_NVM_t_SimInit                            s_Nvm;
    ALN_SimInit_t_Radar5xx_V100::ALN_MainVersion s_MainVersion;
  } ALN_SM_t_NonSharedMem;
}// ALN_MTS_MEAS_t_SimInitMem version 101


// ALN_MTS_MEAS_t_SimInitMem version 102
namespace ALN_SimInit_t_Radar5xx_V102
{
  typedef struct
  {
    AlgoDataTimeStamp_t   u_TimeStamp,
                          u_TimeStampLastCycle;
    float32               f_RadarCycleTime;
    e_AlnOpMode_t         e_OpMode_Previous;
    boolean               b_AzimuthErrorRaised;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    boolean               b_ElevationErrorRaised;
#endif
    e_AlnOpMode_t         e_OpModeBeforePause;
    e_AlnOpMode_t         e_InternalOpMode;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    uint8                 au_dummy[3u];
#endif
  } ALN_MAIN_t_SimInit;

  typedef struct
  {
    float32 f_Correction;
    boolean b_Valid;
    uint8   au_Dummy[3];
  } ALN_t_NvmMethodDirection;

  typedef struct 
  {
    t_Complex16                   a_PathCompApplied[ALN_SimInit_NumOfChannels];
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    ALN_t_NvmMethodDirection      ElevationApplied;
#endif
    float32                       f_TimeSinceLastNvmUpdate;
    float32                       f_MinTimeBetweenNvmUpdate;
    uint8                         au_PathCompContingent[ALN_NVM_u_PATH_COMP_NOF_FEATURES];
    uint8                         u_NofCyclesWaitAfterHWConfigChanged;
    uint8                         u_NofCyclesWaitForNvm;
    boolean                       b_WaitForWrite;
    uint8                         au_dummy[3u];
  } ALN_NVM_t_SimInit;

  typedef struct
  {
    uint32                                        u_VersionNumber;
    SignalHeader_t                                sSigHeader;
    ALN_MAIN_t_SimInit                            s_Main;
    ALN_NVM_t_SimInit                             s_Nvm;
    ALN_SimInit_t_Radar5xx_V100::ALN_MainVersion  s_MainVersion;
  } ALN_SM_t_NonSharedMem;
}// ALN_MTS_MEAS_t_SimInitMem version 102

// ALN_MTS_MEAS_t_SimInitMem version 103
namespace ALN_SimInit_t_Radar5xx_V103
{
  typedef struct 
  {
    t_Complex16                   a_PathCompApplied[ALN_SimInit_NumOfChannels];
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    ALN_SimInit_t_Radar5xx_V102::ALN_t_NvmMethodDirection      ElevationApplied;
#endif
    float32                       f_TimeSinceLastNvmUpdate;
    float32                       f_MinTimeBetweenNvmUpdate;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    sint16                        a_MonopulseApplied[ALN_COMMON_u_MonopulseNvmNofSamples];
#endif
    uint8                         au_PathCompContingent[ALN_NVM_u_PATH_COMP_NOF_FEATURES];
    uint8                         u_NofCyclesWaitAfterHWConfigChanged;
    uint8                         u_NofCyclesWaitForNvm;
    boolean                       b_WaitForWrite;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    uint8                         au_dummy[1u];
#else
    uint8                         au_dummy[3u];
#endif
  } ALN_NVM_t_SimInit;

  typedef struct
  {
    uint32                                          u_VersionNumber;
    SignalHeader_t                                  sSigHeader;
    ALN_SimInit_t_Radar5xx_V102::ALN_MAIN_t_SimInit s_Main;
    ALN_NVM_t_SimInit                               s_Nvm;
    ALN_SimInit_t_Radar5xx_V100::ALN_MainVersion    s_MainVersion;
  } ALN_SM_t_NonSharedMem;
}// ALN_MTS_MEAS_t_SimInitMem version 103

// Generic ARS5xx & SRR5xx ALN_MTS_MEAS_t_SimInitMem
// Holds all possible structure members from all possible namespaces
namespace ALN_SimInit_t_Radar5xx_Gen
{
  typedef struct
  {
    uint32                                          u_VersionNumber;
    SignalHeader_t                                  sSigHeader;
    ALN_SimInit_t_Radar5xx_V100::ALN_MAIN_t_SimInit s_Main_v100;
    ALN_SimInit_t_Radar5xx_V101::ALN_MAIN_t_SimInit s_Main_v101;
    ALN_SimInit_t_Radar5xx_V102::ALN_MAIN_t_SimInit s_Main_v102;
    ALN_SimInit_t_Radar5xx_V100::ALN_NVM_t_SimInit  s_Nvm_v100;
    ALN_SimInit_t_Radar5xx_V101::ALN_NVM_t_SimInit  s_Nvm_v101;
    ALN_SimInit_t_Radar5xx_V102::ALN_NVM_t_SimInit  s_Nvm_v102;
    ALN_SimInit_t_Radar5xx_V103::ALN_NVM_t_SimInit  s_Nvm_v103;
    ALN_SimInit_t_Radar5xx_V100::ALN_MainVersion    s_MainVersion;
  } ALN_SM_t_NonSharedMem;
}


class CConvAlnSimInit : public CSimConverterBase
{
  // the list of dependency names used inside by the converter
  /*
  static const char *DEP_NAMES[];
  */

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here
    DEP_COUNT
  };

  ALN_SimInit_t_Radar5xx_Gen::ALN_SM_t_NonSharedMem m_BufGen;
  ALN_SimInit_t_Radar5xx_V100::ALN_SM_t_NonSharedMem m_BufV100;
  ALN_SimInit_t_Radar5xx_V101::ALN_SM_t_NonSharedMem m_BufV101;
  ALN_SimInit_t_Radar5xx_V102::ALN_SM_t_NonSharedMem m_BufV102;
  ALN_SimInit_t_Radar5xx_V103::ALN_SM_t_NonSharedMem m_BufV103;

  static void InitGen(ALN_SimInit_t_Radar5xx_Gen::ALN_SM_t_NonSharedMem & Params);
  static void InitV100(ALN_SimInit_t_Radar5xx_V100::ALN_SM_t_NonSharedMem & Params);
  static void InitV101(ALN_SimInit_t_Radar5xx_V101::ALN_SM_t_NonSharedMem & Params);
  static void InitV102(ALN_SimInit_t_Radar5xx_V102::ALN_SM_t_NonSharedMem & Params);
  static void InitV103(ALN_SimInit_t_Radar5xx_V103::ALN_SM_t_NonSharedMem & Params);

  // Conversions from provide port (input) to generic buffer
  void Convert_v100_to_Gen (ALN_SimInit_t_Radar5xx_Gen::ALN_SM_t_NonSharedMem & Dest, const ALN_SimInit_t_Radar5xx_V100::ALN_SM_t_NonSharedMem & Src);
  void Convert_v101_to_Gen (ALN_SimInit_t_Radar5xx_Gen::ALN_SM_t_NonSharedMem & Dest, const ALN_SimInit_t_Radar5xx_V101::ALN_SM_t_NonSharedMem & Src);
  void Convert_v102_to_Gen (ALN_SimInit_t_Radar5xx_Gen::ALN_SM_t_NonSharedMem & Dest, const ALN_SimInit_t_Radar5xx_V102::ALN_SM_t_NonSharedMem & Src);
  void Convert_v103_to_Gen (ALN_SimInit_t_Radar5xx_Gen::ALN_SM_t_NonSharedMem & Dest, const ALN_SimInit_t_Radar5xx_V103::ALN_SM_t_NonSharedMem & Src);

  // Conversions form generic buffer to receive port (output)
  void Convert_Gen_to_v100 (ALN_SimInit_t_Radar5xx_V100::ALN_SM_t_NonSharedMem & Dest, const ALN_SimInit_t_Radar5xx_Gen::ALN_SM_t_NonSharedMem & Src);
  void Convert_Gen_to_v101 (ALN_SimInit_t_Radar5xx_V101::ALN_SM_t_NonSharedMem & Dest, const ALN_SimInit_t_Radar5xx_Gen::ALN_SM_t_NonSharedMem & Src);
  void Convert_Gen_to_v102 (ALN_SimInit_t_Radar5xx_V102::ALN_SM_t_NonSharedMem & Dest, const ALN_SimInit_t_Radar5xx_Gen::ALN_SM_t_NonSharedMem & Src);
  void Convert_Gen_to_v103 (ALN_SimInit_t_Radar5xx_V103::ALN_SM_t_NonSharedMem & Dest, const ALN_SimInit_t_Radar5xx_Gen::ALN_SM_t_NonSharedMem & Src);

public:

  static const char *GetConverterTypeName()
  {
    return "Aln_SimInit";
  }

  CConvAlnSimInit(void);
  virtual ~CConvAlnSimInit(void);

  const char *GetTypeName()
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
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    void **pDefaultData, unsigned long &ulDefaultSize);

protected:

  // used to check if an unversioned PPort is compatible with a certain version of RPort
  bool IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize);

  // used to check if ports are compatible between different versions
  bool AreVersionsCompatible(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo);

private:

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl VERSION100;
  static CVersionInfoImpl VERSION101;
  static CVersionInfoImpl VERSION102;
  static CVersionInfoImpl VERSION103;

  enum ALNBswIn
  {
    ALN_SIM_INIT_V100,
    ALN_SIM_INIT_V101,
    ALN_SIM_INIT_V102,
    ALN_SIM_INIT_V103,
    ALN_SIM_INIT_VERSION_COUNT
  };

  static const unsigned long SUPPORTED_SIZE[ALN_SIM_INIT_VERSION_COUNT];
  static CVersionInfoImpl * const ALNSIMINITMON_VERSION_NUMBERS[ALN_SIM_INIT_VERSION_COUNT];

  bool PortSupported (SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * pPortVersionInfo = NULL) const;

};

CVersionInfoImpl CConvAlnSimInit::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvAlnSimInit::VERSION100(0, 0, 100);
CVersionInfoImpl CConvAlnSimInit::VERSION101(0, 0, 101);
CVersionInfoImpl CConvAlnSimInit::VERSION102(0, 0, 102);
CVersionInfoImpl CConvAlnSimInit::VERSION103(0, 0, 103);

const unsigned long CConvAlnSimInit::SUPPORTED_SIZE[CConvAlnSimInit::ALN_SIM_INIT_VERSION_COUNT] =
{
  sizeof(ALN_SimInit_t_Radar5xx_V100::ALN_SM_t_NonSharedMem),
  sizeof(ALN_SimInit_t_Radar5xx_V101::ALN_SM_t_NonSharedMem),
  sizeof(ALN_SimInit_t_Radar5xx_V102::ALN_SM_t_NonSharedMem),
  sizeof(ALN_SimInit_t_Radar5xx_V103::ALN_SM_t_NonSharedMem)
};

CVersionInfoImpl * const CConvAlnSimInit::ALNSIMINITMON_VERSION_NUMBERS[CConvAlnSimInit::ALN_SIM_INIT_VERSION_COUNT]=
{
  &VERSION100,
  &VERSION101,
  &VERSION102,
  &VERSION103
};

CConvAlnSimInit::CConvAlnSimInit(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufGen(), m_BufV100(), m_BufV101(), m_BufV102(), m_BufV103()
{
}

CConvAlnSimInit::~CConvAlnSimInit(void)
{
}

bool CConvAlnSimInit::PortSupported(SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * pPortVersionInfo) const
{
  bool bResult = false;
  unsigned int i;

  if (ePortType == simOPAQUE_t)
  {
    for (i=0; (i<CConvAlnSimInit::ALN_SIM_INIT_VERSION_COUNT) && (false == bResult); i++)
    {
      if (ulPortSize == SUPPORTED_SIZE[i])
      {
        // Check if version information is compatible - with extra care for simulators that do not set the version number at all...
        if ((pPortVersionInfo == NULL) || (pPortVersionInfo->Equals(ALNSIMINITMON_VERSION_NUMBERS[i])) || (pPortVersionInfo->Equals(&BASE_VERSION)))
        {
          bResult = true;
        }
      }
    }
  }
  return bResult;
}


void CConvAlnSimInit::InitV100(ALN_SimInit_t_Radar5xx_V100::ALN_SM_t_NonSharedMem & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber = 100u;
}

void CConvAlnSimInit::InitV101(ALN_SimInit_t_Radar5xx_V101::ALN_SM_t_NonSharedMem & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber = 101u;
}

void CConvAlnSimInit::InitV102(ALN_SimInit_t_Radar5xx_V102::ALN_SM_t_NonSharedMem & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber = 102u;
}

void CConvAlnSimInit::InitV103(ALN_SimInit_t_Radar5xx_V103::ALN_SM_t_NonSharedMem & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber = 103u;
}

void CConvAlnSimInit::InitGen(ALN_SimInit_t_Radar5xx_Gen::ALN_SM_t_NonSharedMem & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  // Set to the highest number
  Params.u_VersionNumber = 103u;
}

void CConvAlnSimInit::Convert_v100_to_Gen (ALN_SimInit_t_Radar5xx_Gen::ALN_SM_t_NonSharedMem & Dest, const ALN_SimInit_t_Radar5xx_V100::ALN_SM_t_NonSharedMem & Src)
{
  Dest.u_VersionNumber                 = Src.u_VersionNumber;
  Dest.sSigHeader                      = Src.sSigHeader;
  Dest.s_MainVersion                   = Src.s_MainVersion;

  /* V100 */
  Dest.s_Main_v100                     = Src.s_Main;
  Dest.s_Nvm_v100                      = Src.s_Nvm;

  /*V101*/
  Dest.s_Main_v101.e_OpMode_Previous                      = Src.s_Main.e_OpMode_Previous;
  Dest.s_Main_v101.ui8_NofCyclesWaitAfterHwConfigChanged  = Src.s_Main.ui8_NofCyclesWaitAfterHwConfigChanged;
  Dest.s_Main_v101.b_AzimuthErrorRaised                   = Src.s_Main.b_AzimuthErrorRaised;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_Main_v101.b_ElevationErrorRaised                 = Src.s_Main.b_ElevationErrorRaised;
#endif
  Dest.s_Main_v101.e_OpModeBeforePause                    = Src.s_Main.e_OpModeBeforePause;
  Dest.s_Main_v101.e_InternalOpMode                       = Src.s_Main.e_InternalOpMode;
  Dest.s_Nvm_v101.b_WaitForWrite              = Src.s_Nvm.b_WaitForWrite;
  Dest.s_Nvm_v101.u_CyclesSinceLastNvmUpdate  = Src.s_Nvm.u_CyclesSinceLastNvmUpdate;
  Dest.s_Nvm_v101.u_NofCyclesWaitForNvm       = Src.s_Nvm.u_NofCyclesWaitForNvm;
  Dest.s_Nvm_v101.u_PathCompContingent[0]     = Src.s_Nvm.u_PathCompContingent[0];
  Dest.s_Nvm_v101.u_PathCompContingent[1]     = Src.s_Nvm.u_PathCompContingent[1];
  memcpy(&(Dest.s_Nvm_v101.a_PathCompApplied), &(Src.s_Nvm.a_PathCompApplied[0]), sizeof(Dest.s_Nvm_v101.a_PathCompApplied));
  Dest.s_Nvm_v101.u_MinCyclesNvmUpdate        = Src.s_Nvm.u_MinCyclesNvmUpdate;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_Nvm_v101.f_ElevationApplied          = Src.s_Nvm.f_ElevationApplied;
  Dest.s_Nvm_v101.b_ElevationAppliedValid     = Src.s_Nvm.b_ElevationAppliedValid;
#endif

  /* V102 */
  Dest.s_Main_v102.u_TimeStamp                            = 0u;
  Dest.s_Main_v102.u_TimeStampLastCycle                   = 0u;
  Dest.s_Main_v102.f_RadarCycleTime                       = 0.f;
  Dest.s_Main_v102.e_OpMode_Previous                      = Dest.s_Main_v101.e_OpMode_Previous;
  Dest.s_Main_v102.b_AzimuthErrorRaised                   = Dest.s_Main_v101.b_AzimuthErrorRaised;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_Main_v102.b_ElevationErrorRaised                 = Dest.s_Main_v101.b_ElevationErrorRaised;
#endif
  Dest.s_Main_v102.e_OpModeBeforePause                    = Dest.s_Main_v101.e_OpModeBeforePause;
  Dest.s_Main_v102.e_InternalOpMode                       = Dest.s_Main_v101.e_InternalOpMode;
  Dest.s_Nvm_v102.b_WaitForWrite              = Dest.s_Nvm_v101.b_WaitForWrite;
  Dest.s_Nvm_v102.f_TimeSinceLastNvmUpdate    = 0.f;
  Dest.s_Nvm_v102.f_MinTimeBetweenNvmUpdate   = 600.f; // Default = 10min = 600sec
  Dest.s_Nvm_v102.u_NofCyclesWaitForNvm       = Dest.s_Nvm_v101.u_NofCyclesWaitForNvm;
  Dest.s_Nvm_v102.u_NofCyclesWaitAfterHWConfigChanged     = Dest.s_Main_v101.ui8_NofCyclesWaitAfterHwConfigChanged;
  Dest.s_Nvm_v102.au_PathCompContingent[0]    = Dest.s_Nvm_v101.u_PathCompContingent[0];
  Dest.s_Nvm_v102.au_PathCompContingent[1]    = Dest.s_Nvm_v101.u_PathCompContingent[1];
  memcpy(&(Dest.s_Nvm_v102.a_PathCompApplied), &(Dest.s_Nvm_v101.a_PathCompApplied[0]), sizeof(Dest.s_Nvm_v102.a_PathCompApplied));
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_Nvm_v102.ElevationApplied.f_Correction = Dest.s_Nvm_v101.f_ElevationApplied;
  Dest.s_Nvm_v102.ElevationApplied.b_Valid      = Dest.s_Nvm_v101.b_ElevationAppliedValid;
#endif

  /* V103 */
  Dest.s_Nvm_v103.b_WaitForWrite              = Dest.s_Nvm_v101.b_WaitForWrite;
  Dest.s_Nvm_v103.f_TimeSinceLastNvmUpdate    = 0.f;
  Dest.s_Nvm_v103.f_MinTimeBetweenNvmUpdate   = 600.f; // Default = 10min = 600sec
  Dest.s_Nvm_v103.u_NofCyclesWaitForNvm       = Dest.s_Nvm_v101.u_NofCyclesWaitForNvm;
  Dest.s_Nvm_v103.u_NofCyclesWaitAfterHWConfigChanged     = Dest.s_Main_v101.ui8_NofCyclesWaitAfterHwConfigChanged;
  Dest.s_Nvm_v103.au_PathCompContingent[0]    = Dest.s_Nvm_v101.u_PathCompContingent[0];
  Dest.s_Nvm_v103.au_PathCompContingent[1]    = Dest.s_Nvm_v101.u_PathCompContingent[1];
  memcpy(&(Dest.s_Nvm_v103.a_PathCompApplied), &(Dest.s_Nvm_v101.a_PathCompApplied[0]), sizeof(Dest.s_Nvm_v103.a_PathCompApplied));
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_Nvm_v103.ElevationApplied.f_Correction = Dest.s_Nvm_v101.f_ElevationApplied;
  Dest.s_Nvm_v103.ElevationApplied.b_Valid      = Dest.s_Nvm_v101.b_ElevationAppliedValid;
  memset(&Dest.s_Nvm_v103.a_MonopulseApplied, 0, sizeof(Dest.s_Nvm_v103.a_MonopulseApplied));
#endif

}

void CConvAlnSimInit::Convert_v101_to_Gen (ALN_SimInit_t_Radar5xx_Gen::ALN_SM_t_NonSharedMem & Dest, const ALN_SimInit_t_Radar5xx_V101::ALN_SM_t_NonSharedMem & Src)
{
  Dest.u_VersionNumber                 = Src.u_VersionNumber;
  Dest.sSigHeader                      = Src.sSigHeader;
  Dest.s_MainVersion                   = Src.s_MainVersion;

  /* V100 */
  Dest.s_Main_v100.e_OpMode_Previous                      = Src.s_Main.e_OpMode_Previous;
  Dest.s_Main_v100.ui8_NofCyclesWaitAfterHwConfigChanged  = Src.s_Main.ui8_NofCyclesWaitAfterHwConfigChanged;
  Dest.s_Main_v100.b_AzimuthErrorRaised                   = Src.s_Main.b_AzimuthErrorRaised;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_Main_v100.b_ElevationErrorRaised                 = Src.s_Main.b_ElevationErrorRaised;
#endif
  Dest.s_Main_v100.e_OpModeBeforePause                    = Src.s_Main.e_OpModeBeforePause;
  Dest.s_Main_v100.e_InternalOpMode                       = Src.s_Main.e_InternalOpMode;
  Dest.s_Nvm_v100.b_WaitForWrite              = Src.s_Nvm.b_WaitForWrite;
  Dest.s_Nvm_v100.u_CyclesSinceLastNvmUpdate  = Src.s_Nvm.u_CyclesSinceLastNvmUpdate;
  Dest.s_Nvm_v100.u_NofCyclesWaitForNvm       = Src.s_Nvm.u_NofCyclesWaitForNvm;
  Dest.s_Nvm_v100.u_PathCompContingent[0]     = Src.s_Nvm.u_PathCompContingent[0];
  Dest.s_Nvm_v100.u_PathCompContingent[1]     = Src.s_Nvm.u_PathCompContingent[1];
  memcpy(&(Dest.s_Nvm_v100.a_PathCompApplied), &(Src.s_Nvm.a_PathCompApplied[0]), sizeof(Dest.s_Nvm_v100.a_PathCompApplied));
  Dest.s_Nvm_v100.u_MinCyclesNvmUpdate        = Src.s_Nvm.u_MinCyclesNvmUpdate;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_Nvm_v100.f_ElevationApplied          = Src.s_Nvm.f_ElevationApplied;
  Dest.s_Nvm_v100.b_ElevationAppliedValid     = Src.s_Nvm.b_ElevationAppliedValid;
#endif

  /* V101 */
  Dest.s_Main_v101                     = Src.s_Main;
  Dest.s_Nvm_v101                      = Src.s_Nvm;

  /* V102 */
  Dest.s_Main_v102.u_TimeStamp                            = 0u;
  Dest.s_Main_v102.u_TimeStampLastCycle                   = 0u;
  Dest.s_Main_v102.f_RadarCycleTime                       = 0.f;
  Dest.s_Main_v102.e_OpMode_Previous                      = Src.s_Main.e_OpMode_Previous;
  Dest.s_Main_v102.b_AzimuthErrorRaised                   = Src.s_Main.b_AzimuthErrorRaised;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_Main_v102.b_ElevationErrorRaised                 = Src.s_Main.b_ElevationErrorRaised;
#endif
  Dest.s_Main_v102.e_OpModeBeforePause                    = Src.s_Main.e_OpModeBeforePause;
  Dest.s_Main_v102.e_InternalOpMode                       = Src.s_Main.e_InternalOpMode;
  Dest.s_Nvm_v102.b_WaitForWrite              = Src.s_Nvm.b_WaitForWrite;
  Dest.s_Nvm_v102.f_TimeSinceLastNvmUpdate    = 0.f;
  Dest.s_Nvm_v102.f_MinTimeBetweenNvmUpdate   = 600.f; // Default = 10min = 600sec
  Dest.s_Nvm_v102.u_NofCyclesWaitForNvm       = Src.s_Nvm.u_NofCyclesWaitForNvm;
  Dest.s_Nvm_v102.u_NofCyclesWaitAfterHWConfigChanged  = Src.s_Main.ui8_NofCyclesWaitAfterHwConfigChanged;
  Dest.s_Nvm_v102.au_PathCompContingent[0]    = Src.s_Nvm.u_PathCompContingent[0];
  Dest.s_Nvm_v102.au_PathCompContingent[1]    = Src.s_Nvm.u_PathCompContingent[1];
  memcpy(&(Dest.s_Nvm_v102.a_PathCompApplied), &(Src.s_Nvm.a_PathCompApplied[0]), sizeof(Dest.s_Nvm_v102.a_PathCompApplied));
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_Nvm_v102.ElevationApplied.f_Correction = Src.s_Nvm.f_ElevationApplied;
  Dest.s_Nvm_v102.ElevationApplied.b_Valid      = Src.s_Nvm.b_ElevationAppliedValid;
#endif

  /* V103 */
  Dest.s_Nvm_v103.b_WaitForWrite              = Src.s_Nvm.b_WaitForWrite;
  Dest.s_Nvm_v103.f_TimeSinceLastNvmUpdate    = 0.f;
  Dest.s_Nvm_v103.f_MinTimeBetweenNvmUpdate   = 600.f; // Default = 10min = 600sec
  Dest.s_Nvm_v103.u_NofCyclesWaitForNvm       = Src.s_Nvm.u_NofCyclesWaitForNvm;
  Dest.s_Nvm_v103.u_NofCyclesWaitAfterHWConfigChanged  = Src.s_Main.ui8_NofCyclesWaitAfterHwConfigChanged;
  Dest.s_Nvm_v103.au_PathCompContingent[0]    = Src.s_Nvm.u_PathCompContingent[0];
  Dest.s_Nvm_v103.au_PathCompContingent[1]    = Src.s_Nvm.u_PathCompContingent[1];
  memcpy(&(Dest.s_Nvm_v103.a_PathCompApplied), &(Src.s_Nvm.a_PathCompApplied[0]), sizeof(Dest.s_Nvm_v103.a_PathCompApplied));
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_Nvm_v103.ElevationApplied.f_Correction = Src.s_Nvm.f_ElevationApplied;
  Dest.s_Nvm_v103.ElevationApplied.b_Valid      = Src.s_Nvm.b_ElevationAppliedValid;
  memset(&(Dest.s_Nvm_v103.a_MonopulseApplied), 0, sizeof(Dest.s_Nvm_v103.a_MonopulseApplied));
#endif
}

void CConvAlnSimInit::Convert_v102_to_Gen (ALN_SimInit_t_Radar5xx_Gen::ALN_SM_t_NonSharedMem & Dest, const ALN_SimInit_t_Radar5xx_V102::ALN_SM_t_NonSharedMem & Src)
{
  Dest.u_VersionNumber                 = Src.u_VersionNumber;
  Dest.sSigHeader                      = Src.sSigHeader;
  Dest.s_MainVersion                   = Src.s_MainVersion;

  /* V100 */
  Dest.s_Main_v100.e_OpMode_Previous                      = Src.s_Main.e_OpMode_Previous;
  Dest.s_Main_v100.ui8_NofCyclesWaitAfterHwConfigChanged  = Src.s_Nvm.u_NofCyclesWaitAfterHWConfigChanged;
  Dest.s_Main_v100.b_AzimuthErrorRaised                   = Src.s_Main.b_AzimuthErrorRaised;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_Main_v100.b_ElevationErrorRaised                 = Src.s_Main.b_ElevationErrorRaised;
#endif
  Dest.s_Main_v100.e_OpModeBeforePause                    = Src.s_Main.e_OpModeBeforePause;
  Dest.s_Main_v100.e_InternalOpMode                       = Src.s_Main.e_InternalOpMode;
  Dest.s_Nvm_v100.b_WaitForWrite              = Src.s_Nvm.b_WaitForWrite;
  Dest.s_Nvm_v100.u_CyclesSinceLastNvmUpdate  = 0u;
  Dest.s_Nvm_v100.u_NofCyclesWaitForNvm       = Src.s_Nvm.u_NofCyclesWaitForNvm;
  Dest.s_Nvm_v100.u_PathCompContingent[0]     = Src.s_Nvm.au_PathCompContingent[0];
  Dest.s_Nvm_v100.u_PathCompContingent[1]     = Src.s_Nvm.au_PathCompContingent[1];
  memcpy(&(Dest.s_Nvm_v100.a_PathCompApplied), &(Src.s_Nvm.a_PathCompApplied[0]), sizeof(Dest.s_Nvm_v100.a_PathCompApplied));
  Dest.s_Nvm_v100.u_MinCyclesNvmUpdate        = 12000u; // Default  = 10min = 12000 cycles (0.05 radar cycle time)
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_Nvm_v100.f_ElevationApplied          = Src.s_Nvm.ElevationApplied.f_Correction;
  Dest.s_Nvm_v100.b_ElevationAppliedValid     = Src.s_Nvm.ElevationApplied.b_Valid;
#endif

  /* V101 */
  Dest.s_Main_v101.e_OpMode_Previous                      = Src.s_Main.e_OpMode_Previous;
  Dest.s_Main_v101.ui8_NofCyclesWaitAfterHwConfigChanged  = Src.s_Nvm.u_NofCyclesWaitAfterHWConfigChanged;
  Dest.s_Main_v101.b_AzimuthErrorRaised                   = Src.s_Main.b_AzimuthErrorRaised;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_Main_v101.b_ElevationErrorRaised                 = Src.s_Main.b_ElevationErrorRaised;
#endif
  Dest.s_Main_v101.e_OpModeBeforePause                    = Src.s_Main.e_OpModeBeforePause;
  Dest.s_Main_v101.e_InternalOpMode                       = Src.s_Main.e_InternalOpMode;
  Dest.s_Nvm_v101.b_WaitForWrite              = Src.s_Nvm.b_WaitForWrite;
  Dest.s_Nvm_v101.u_CyclesSinceLastNvmUpdate  = 0u;
  Dest.s_Nvm_v101.u_MinCyclesNvmUpdate        = 12000u; // Default  = 10min = 12000 cycles (0.05 radar cycle time)
  Dest.s_Nvm_v101.u_NofCyclesWaitForNvm       = Src.s_Nvm.u_NofCyclesWaitForNvm;
  Dest.s_Nvm_v101.u_PathCompContingent[0]     = Src.s_Nvm.au_PathCompContingent[0];
  Dest.s_Nvm_v101.u_PathCompContingent[1]     = Src.s_Nvm.au_PathCompContingent[1];
  memcpy(&(Dest.s_Nvm_v101.a_PathCompApplied), &(Src.s_Nvm.a_PathCompApplied[0]), sizeof(Dest.s_Nvm_v101.a_PathCompApplied));
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_Nvm_v101.f_ElevationApplied          = Src.s_Nvm.ElevationApplied.f_Correction;
  Dest.s_Nvm_v101.b_ElevationAppliedValid     = Src.s_Nvm.ElevationApplied.b_Valid;
#endif
  
  /* V102 */
  Dest.s_Main_v102                     = Src.s_Main;
  Dest.s_Nvm_v102                      = Src.s_Nvm;

  /* V103 */
  Dest.s_Nvm_v103.b_WaitForWrite              = Src.s_Nvm.b_WaitForWrite;
  Dest.s_Nvm_v103.f_TimeSinceLastNvmUpdate    = Src.s_Nvm.f_MinTimeBetweenNvmUpdate;
  Dest.s_Nvm_v103.f_MinTimeBetweenNvmUpdate   = Src.s_Nvm.f_MinTimeBetweenNvmUpdate;
  Dest.s_Nvm_v103.u_NofCyclesWaitForNvm       = Src.s_Nvm.u_NofCyclesWaitForNvm;
  Dest.s_Nvm_v103.u_NofCyclesWaitAfterHWConfigChanged  = Src.s_Nvm.u_NofCyclesWaitAfterHWConfigChanged;
  Dest.s_Nvm_v103.au_PathCompContingent[0]    = Src.s_Nvm.au_PathCompContingent[0];
  Dest.s_Nvm_v103.au_PathCompContingent[1]    = Src.s_Nvm.au_PathCompContingent[1];
  memcpy(&(Dest.s_Nvm_v102.a_PathCompApplied), &(Src.s_Nvm.a_PathCompApplied[0]), sizeof(Dest.s_Nvm_v102.a_PathCompApplied));
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_Nvm_v103.ElevationApplied.f_Correction = Src.s_Nvm.ElevationApplied.f_Correction;
  Dest.s_Nvm_v103.ElevationApplied.b_Valid      = Src.s_Nvm.ElevationApplied.b_Valid;
  memset(&(Dest.s_Nvm_v103.a_MonopulseApplied), 0, sizeof(Dest.s_Nvm_v103.a_MonopulseApplied));
#endif

}

void CConvAlnSimInit::Convert_v103_to_Gen (ALN_SimInit_t_Radar5xx_Gen::ALN_SM_t_NonSharedMem & Dest, const ALN_SimInit_t_Radar5xx_V103::ALN_SM_t_NonSharedMem & Src)
{
  Dest.u_VersionNumber                 = Src.u_VersionNumber;
  Dest.sSigHeader                      = Src.sSigHeader;
  Dest.s_MainVersion                   = Src.s_MainVersion;

  /* V100 */
  Dest.s_Main_v100.e_OpMode_Previous                      = Src.s_Main.e_OpMode_Previous;
  Dest.s_Main_v100.ui8_NofCyclesWaitAfterHwConfigChanged  = Src.s_Nvm.u_NofCyclesWaitAfterHWConfigChanged;
  Dest.s_Main_v100.b_AzimuthErrorRaised                   = Src.s_Main.b_AzimuthErrorRaised;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_Main_v100.b_ElevationErrorRaised                 = Src.s_Main.b_ElevationErrorRaised;
#endif
  Dest.s_Main_v100.e_OpModeBeforePause                    = Src.s_Main.e_OpModeBeforePause;
  Dest.s_Main_v100.e_InternalOpMode                       = Src.s_Main.e_InternalOpMode;
  Dest.s_Nvm_v100.b_WaitForWrite              = Src.s_Nvm.b_WaitForWrite;
  Dest.s_Nvm_v100.u_CyclesSinceLastNvmUpdate  = 0u;
  Dest.s_Nvm_v100.u_NofCyclesWaitForNvm       = Src.s_Nvm.u_NofCyclesWaitForNvm;
  Dest.s_Nvm_v100.u_PathCompContingent[0]     = Src.s_Nvm.au_PathCompContingent[0];
  Dest.s_Nvm_v100.u_PathCompContingent[1]     = Src.s_Nvm.au_PathCompContingent[1];
  memcpy(&(Dest.s_Nvm_v100.a_PathCompApplied), &(Src.s_Nvm.a_PathCompApplied[0]), sizeof(Dest.s_Nvm_v100.a_PathCompApplied));
  Dest.s_Nvm_v100.u_MinCyclesNvmUpdate        = 12000u; // Default  = 10min = 12000 cycles (0.05 radar cycle time)
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_Nvm_v100.f_ElevationApplied          = Src.s_Nvm.ElevationApplied.f_Correction;
  Dest.s_Nvm_v100.b_ElevationAppliedValid     = Src.s_Nvm.ElevationApplied.b_Valid;
#endif

  /* V101 */
  Dest.s_Main_v101.e_OpMode_Previous                      = Src.s_Main.e_OpMode_Previous;
  Dest.s_Main_v101.ui8_NofCyclesWaitAfterHwConfigChanged  = Src.s_Nvm.u_NofCyclesWaitAfterHWConfigChanged;
  Dest.s_Main_v101.b_AzimuthErrorRaised                   = Src.s_Main.b_AzimuthErrorRaised;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_Main_v101.b_ElevationErrorRaised                 = Src.s_Main.b_ElevationErrorRaised;
#endif
  Dest.s_Main_v101.e_OpModeBeforePause                    = Src.s_Main.e_OpModeBeforePause;
  Dest.s_Main_v101.e_InternalOpMode                       = Src.s_Main.e_InternalOpMode;
  Dest.s_Nvm_v101.b_WaitForWrite              = Src.s_Nvm.b_WaitForWrite;
  Dest.s_Nvm_v101.u_CyclesSinceLastNvmUpdate  = 0u;
  Dest.s_Nvm_v101.u_MinCyclesNvmUpdate        = 12000u; // Default  = 10min = 12000 cycles (0.05 radar cycle time)
  Dest.s_Nvm_v101.u_NofCyclesWaitForNvm       = Src.s_Nvm.u_NofCyclesWaitForNvm;
  Dest.s_Nvm_v101.u_PathCompContingent[0]     = Src.s_Nvm.au_PathCompContingent[0];
  Dest.s_Nvm_v101.u_PathCompContingent[1]     = Src.s_Nvm.au_PathCompContingent[1];
  memcpy(&(Dest.s_Nvm_v101.a_PathCompApplied), &(Src.s_Nvm.a_PathCompApplied[0]), sizeof(Dest.s_Nvm_v101.a_PathCompApplied));
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_Nvm_v101.f_ElevationApplied          = Src.s_Nvm.ElevationApplied.f_Correction;
  Dest.s_Nvm_v101.b_ElevationAppliedValid     = Src.s_Nvm.ElevationApplied.b_Valid;
#endif

  /* V102 */
  Dest.s_Main_v102                            = Src.s_Main;
  Dest.s_Nvm_v102.b_WaitForWrite              = Src.s_Nvm.b_WaitForWrite;
  Dest.s_Nvm_v102.f_TimeSinceLastNvmUpdate    = Src.s_Nvm.f_MinTimeBetweenNvmUpdate;
  Dest.s_Nvm_v102.f_MinTimeBetweenNvmUpdate   = Src.s_Nvm.f_MinTimeBetweenNvmUpdate;
  Dest.s_Nvm_v102.u_NofCyclesWaitForNvm       = Src.s_Nvm.u_NofCyclesWaitForNvm;
  Dest.s_Nvm_v102.u_NofCyclesWaitAfterHWConfigChanged  = Src.s_Nvm.u_NofCyclesWaitAfterHWConfigChanged;
  Dest.s_Nvm_v102.au_PathCompContingent[0]    = Src.s_Nvm.au_PathCompContingent[0];
  Dest.s_Nvm_v102.au_PathCompContingent[1]    = Src.s_Nvm.au_PathCompContingent[1];
  memcpy(&(Dest.s_Nvm_v102.a_PathCompApplied), &(Src.s_Nvm.a_PathCompApplied[0]), sizeof(Dest.s_Nvm_v102.a_PathCompApplied));
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_Nvm_v102.ElevationApplied.f_Correction = Src.s_Nvm.ElevationApplied.f_Correction;
  Dest.s_Nvm_v102.ElevationApplied.b_Valid      = Src.s_Nvm.ElevationApplied.b_Valid;
#endif

  /* V103 */
  Dest.s_Nvm_v103                      = Src.s_Nvm;
}


void CConvAlnSimInit::Convert_Gen_to_v100 (ALN_SimInit_t_Radar5xx_V100::ALN_SM_t_NonSharedMem & Dest, const ALN_SimInit_t_Radar5xx_Gen::ALN_SM_t_NonSharedMem & Src)
{
  Dest.u_VersionNumber = 100u;
  Dest.sSigHeader                      = Src.sSigHeader;
  Dest.s_MainVersion                   = Src.s_MainVersion;
  Dest.s_Main                          = Src.s_Main_v100;
  Dest.s_Nvm                           = Src.s_Nvm_v100;
}

void CConvAlnSimInit::Convert_Gen_to_v101 (ALN_SimInit_t_Radar5xx_V101::ALN_SM_t_NonSharedMem & Dest, const ALN_SimInit_t_Radar5xx_Gen::ALN_SM_t_NonSharedMem & Src)
{
  Dest.u_VersionNumber = 101u;
  Dest.sSigHeader                      = Src.sSigHeader;
  Dest.s_MainVersion                   = Src.s_MainVersion;
  Dest.s_Main                          = Src.s_Main_v101;
  Dest.s_Nvm                           = Src.s_Nvm_v101;
}

void CConvAlnSimInit::Convert_Gen_to_v102 (ALN_SimInit_t_Radar5xx_V102::ALN_SM_t_NonSharedMem & Dest, const ALN_SimInit_t_Radar5xx_Gen::ALN_SM_t_NonSharedMem & Src)
{
  Dest.u_VersionNumber = 102u;
  Dest.sSigHeader                      = Src.sSigHeader;
  Dest.s_MainVersion                   = Src.s_MainVersion;
  Dest.s_Main                          = Src.s_Main_v102;
  Dest.s_Nvm                           = Src.s_Nvm_v102;
}

void CConvAlnSimInit::Convert_Gen_to_v103 (ALN_SimInit_t_Radar5xx_V103::ALN_SM_t_NonSharedMem & Dest, const ALN_SimInit_t_Radar5xx_Gen::ALN_SM_t_NonSharedMem & Src)
{
  Dest.u_VersionNumber = 103u;
  Dest.sSigHeader                      = Src.sSigHeader;
  Dest.s_MainVersion                   = Src.s_MainVersion;
  Dest.s_Main                          = Src.s_Main_v102;
  Dest.s_Nvm                           = Src.s_Nvm_v103;
}

long CConvAlnSimInit::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  bool bGenBufferFilled = false;
  const uint32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<uint32*>(pPPortData)):(0);
  // If direct one:one copy possible then do that
  const CVersionInfoImpl uDataReqVersionInfo(0, 0, uDataVer);
  // If direct one:one copy possible then do that
  if ((ulPPortSize == ulRPortSize)
    && ((pProvidePortVersionInfo == NULL) /*|| (pProvidePortVersionInfo->Equals(&VERSION11)) */
    || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    /* do not explicitely check data version -> if size fits, just use it */
    && (requestPortVersionInfo.Equals(&uDataReqVersionInfo)))
  {
    lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
  }
  // First decide from which version we are converting and fill the generic buffer accordingly
  else if ((ulPPortSize == sizeof(ALN_SimInit_t_Radar5xx_V103::ALN_SM_t_NonSharedMem))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION103)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    && ((uDataVer == 103u) || (uDataVer == 0)))
  {
    // Source Port V103
    CConvAlnSimInit::InitGen(m_BufGen);
    const ALN_SimInit_t_Radar5xx_V103::ALN_SM_t_NonSharedMem & Src = *reinterpret_cast<ALN_SimInit_t_Radar5xx_V103::ALN_SM_t_NonSharedMem*>(pPPortData);
    Convert_v103_to_Gen(m_BufGen, Src);
    bGenBufferFilled = true;
  }
  else if ((ulPPortSize == sizeof(ALN_SimInit_t_Radar5xx_V102::ALN_SM_t_NonSharedMem))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION102)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    && ((uDataVer == 102u) || (uDataVer == 0)))
  {
    // Source Port V102
    CConvAlnSimInit::InitGen(m_BufGen);
    const ALN_SimInit_t_Radar5xx_V102::ALN_SM_t_NonSharedMem & Src = *reinterpret_cast<ALN_SimInit_t_Radar5xx_V102::ALN_SM_t_NonSharedMem*>(pPPortData);
    Convert_v102_to_Gen(m_BufGen, Src);
    bGenBufferFilled = true;
  }
  else if ((ulPPortSize == sizeof(ALN_SimInit_t_Radar5xx_V101::ALN_SM_t_NonSharedMem))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION101)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    && ((uDataVer == 101u) || (uDataVer == 0)))
  {
    // Source Port V101
    CConvAlnSimInit::InitGen(m_BufGen);
    const ALN_SimInit_t_Radar5xx_V101::ALN_SM_t_NonSharedMem & Src = *reinterpret_cast<ALN_SimInit_t_Radar5xx_V101::ALN_SM_t_NonSharedMem*>(pPPortData);
    Convert_v101_to_Gen(m_BufGen, Src);
    bGenBufferFilled = true;
  }
  else if ((ulPPortSize == sizeof(ALN_SimInit_t_Radar5xx_V100::ALN_SM_t_NonSharedMem))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION100)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    && ((uDataVer == 100u) || (uDataVer == 0)))
  {
    // Source Port V100
    CConvAlnSimInit::InitGen(m_BufGen);
    const ALN_SimInit_t_Radar5xx_V100::ALN_SM_t_NonSharedMem & Src = *reinterpret_cast<ALN_SimInit_t_Radar5xx_V100::ALN_SM_t_NonSharedMem*>(pPPortData);
    Convert_v100_to_Gen(m_BufGen, Src);
    bGenBufferFilled = true;
  }

  if (bGenBufferFilled == true)
  {
    // Second decide to which version we are converting
    // and take the generic buffer to fill the destination buffer
    if ((ulRPortSize == sizeof(ALN_SimInit_t_Radar5xx_V103::ALN_SM_t_NonSharedMem)) && ((requestPortVersionInfo.Equals(&VERSION103)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
  {
    // Destination port of V103
    CConvAlnSimInit::InitV103(m_BufV103);
    ALN_SimInit_t_Radar5xx_V103::ALN_SM_t_NonSharedMem & Dest = m_BufV103;
    Convert_Gen_to_v103(Dest, m_BufGen);
    *pOutData = &Dest;
    ulOutSize = sizeof(Dest);
    lRet = SIM_ERR_OK;
  }
    else if ((ulRPortSize == sizeof(ALN_SimInit_t_Radar5xx_V102::ALN_SM_t_NonSharedMem)) && ((requestPortVersionInfo.Equals(&VERSION102)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V102
      CConvAlnSimInit::InitV102(m_BufV102);
      ALN_SimInit_t_Radar5xx_V102::ALN_SM_t_NonSharedMem & Dest = m_BufV102;
      Convert_Gen_to_v102(Dest, m_BufGen);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_SimInit_t_Radar5xx_V101::ALN_SM_t_NonSharedMem)) && ((requestPortVersionInfo.Equals(&VERSION101)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V101
      CConvAlnSimInit::InitV101(m_BufV101);
      ALN_SimInit_t_Radar5xx_V101::ALN_SM_t_NonSharedMem & Dest = m_BufV101;
      Convert_Gen_to_v101(Dest, m_BufGen);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_SimInit_t_Radar5xx_V100::ALN_SM_t_NonSharedMem)) && ((requestPortVersionInfo.Equals(&VERSION100)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V100
      CConvAlnSimInit::InitV100(m_BufV100);
      ALN_SimInit_t_Radar5xx_V100::ALN_SM_t_NonSharedMem & Dest = m_BufV100;
      Convert_Gen_to_v100(Dest, m_BufGen);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
  }
  return lRet;
}

/** returns:
*   SIM_ERR_OK - when this value can be used
*   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
*                                            and the default value from Request Port must be used
*/
long CConvAlnSimInit::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(ALN_SimInit_t_Radar5xx_V100::ALN_SM_t_NonSharedMem)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION100.Equals(&requestPortVersionInfo))))
    {
      InitV100(m_BufV100);
      *pDefaultData = &m_BufV100;
      ulDefaultSize = sizeof(ALN_SimInit_t_Radar5xx_V100::ALN_SM_t_NonSharedMem);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_SimInit_t_Radar5xx_V101::ALN_SM_t_NonSharedMem)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION101.Equals(&requestPortVersionInfo))))
    {
      InitV101(m_BufV101);
      *pDefaultData = &m_BufV101;
      ulDefaultSize = sizeof(ALN_SimInit_t_Radar5xx_V101::ALN_SM_t_NonSharedMem);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_SimInit_t_Radar5xx_V102::ALN_SM_t_NonSharedMem)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION102.Equals(&requestPortVersionInfo))))
    {
      InitV102(m_BufV102);
      *pDefaultData = &m_BufV102;
      ulDefaultSize = sizeof(ALN_SimInit_t_Radar5xx_V102::ALN_SM_t_NonSharedMem);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_SimInit_t_Radar5xx_V103::ALN_SM_t_NonSharedMem)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION103.Equals(&requestPortVersionInfo))))
    {
      InitV103(m_BufV103);
      *pDefaultData = &m_BufV103;
      ulDefaultSize = sizeof(ALN_SimInit_t_Radar5xx_V103::ALN_SM_t_NonSharedMem);
      lRet = SIM_ERR_OK;
    }
    else
    {
      // No conversion available
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvAlnSimInit::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize))
  {
    bResult = true;
  }
  else
  {
    bResult = (PortSupported(eRPortType, ulRPortSize, &requestPortVersionInfo) && PortSupported(ePPortType, ulPPortSize));
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvAlnSimInit::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo)
{
  bool bResult = false;
  // Always allow same type/size ports to be bound together
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize) && (providePortVersionInfo.Equals(&requestPortVersionInfo)))
  {
    bResult = true;
  }
  else
  {
    // Ports are different: conversion necessary and possible if provide & request port known
    bResult = PortSupported(eRPortType, ulRPortSize, &requestPortVersionInfo) && PortSupported(ePPortType, ulPPortSize, &providePortVersionInfo);
  }
  return bResult;
}

//
// Main factory class returning conversion class
//
IConverter * CreateAlnSimInitConvClass(void)
{
  return new CConvAlnSimInit();
}
