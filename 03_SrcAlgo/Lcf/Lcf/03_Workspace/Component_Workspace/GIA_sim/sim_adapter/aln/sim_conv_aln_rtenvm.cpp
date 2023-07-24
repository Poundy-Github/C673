/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter aln

  MODULNAME:       sim_conv_aln_rtenvm

  DESCRIPTION:     Conversion module

  AUTHOR:          Jakob Schluttig / Mohammad Altamash Yakoob

  CREATION DATE:   07.05.2014

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_aln_rtenvm.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:14:51CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/aln/project.pj
  CHANGES:         Revision 2.2 2017/05/31 12:16:37CEST Schmitz, David (uidq6182) 
  CHANGES:         * Change SimAdapter to the new structure 101->102
  CHANGES:           * Number of samples monopulse changed
  CHANGES:           * EolInspection structure added
  CHANGES:         Revision 2.1 2017/04/05 13:30:10CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         [ARS5xx/SRR5xx]
  CHANGES:         ? Remove A Sample compatilbility
  CHANGES:         ? Clean up SimAdapters
  CHANGES:         ? Only have version V100 and above
  CHANGES:         Revision 1.10 2017/02/15 15:55:40CET Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         [ARS510/SRR520] Update SimAdapter for the interface changes caused by removal of Elevation feature in SRR520
  CHANGES:         Revision 1.9 2016/09/13 10:16:16CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         Update Simulation adapters and Simulation plugin for ARS510
  CHANGES:         Revision 1.8 2014/12/01 16:05:12CET Schluttig, Jakob (uidv7098) 
  CHANGES:         bugfix
  CHANGES:         - Added comments -  uidv7098 [Dec 1, 2014 4:05:12 PM CET]
  CHANGES:         Change Package : 279548:1 http://mks-psad:7002/im/viewissue?selection=279548
  CHANGES:         Revision 1.7 2014/12/01 10:01:35CET Schluttig, Jakob (uidv7098) 
  CHANGES:         bugfix for Entry
  CHANGES:         --- Added comments ---  uidv7098 [Dec 1, 2014 10:01:35 AM CET]
  CHANGES:         Change Package : 279548:1 http://mks-psad:7002/im/viewissue?selection=279548
  CHANGES:         Revision 1.6 2014/11/11 15:19:51CET Schluttig, Jakob (uidv7098) 
  CHANGES:         bugfixed v9 for ARS
  CHANGES:         --- Added comments ---  uidv7098 [Nov 11, 2014 3:19:52 PM CET]
  CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
  CHANGES:         Revision 1.5 2014/11/07 08:42:34CET Manea, Gabriela (ManeaG) 
  CHANGES:         added version 9 ( ALN_Content_t extended by ALN_AzMonInitData_t)
  CHANGES:         --- Added comments ---  ManeaG [Nov 7, 2014 8:42:34 AM CET]
  CHANGES:         Change Package : 278885:1 http://mks-psad:7002/im/viewissue?selection=278885
  CHANGES:         Revision 1.4 2014/07/23 17:10:28CEST Schluttig, Jakob (uidv7098) 
  CHANGES:         added version 8 (including monopulse phase learn values)
  CHANGES:         --- Added comments ---  uidv7098 [Jul 23, 2014 5:10:28 PM CEST]
  CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
  CHANGES:         Revision 1.3 2014/07/08 16:23:59CEST Schluttig, Jakob (uidv7098) 
  CHANGES:         added new IF versions for direct copy
  CHANGES:         --- Added comments ---  uidv7098 [Jul 8, 2014 4:23:59 PM CEST]
  CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
  CHANGES:         Revision 1.2 2014/05/12 10:34:25CEST Schluttig, Jakob (uidv7098) 
  CHANGES:         also allow "version 0" -> old nvmout versions not correctly frozen :\
  CHANGES:         --- Added comments ---  uidv7098 [May 12, 2014 10:34:26 AM CEST]
  CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
  CHANGES:         Revision 1.1 2014/05/08 09:10:43CEST Schluttig, Jakob (uidv7098) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ALN_Alignment/04_Engineering/03_Workspace/algo/sim_adapter/aln/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_conv_aln_rtenvm.h"
#include "sim_versioninfo_impl.h"
#include "sim_adapter_cfg.h"

// Commonly used type definitions
typedef float float32;
typedef unsigned __int8 boolean, uint8;
typedef unsigned __int32 uint32;

typedef unsigned long AlgoDataTimeStamp_t;
typedef unsigned short AlgoCycleCounter_t;
typedef unsigned char AlgoSignalState_t;

typedef unsigned char u_Dummy_array_t_1[1];
typedef unsigned char u_Dummy_array_t_2[2];
typedef unsigned char u_Dummy_array_t_3[3];

typedef struct SignalHeader_t
{
  AlgoDataTimeStamp_t uiTimeStamp;
  AlgoCycleCounter_t uiMeasurementCounter;
  AlgoCycleCounter_t uiCycleCounter;
  AlgoSignalState_t eSigStatus;
} SignalHeader_t;

// ALN_t_Nvm version 100
namespace ALN_t_Nvm_Radar5xx_V100
{
  typedef unsigned char u_Dummy_array_t_9[3];
  typedef struct
  {
    float f_Correction;
    boolean b_Valid;
    u_Dummy_array_t_9 u_Dummy;
  } ALN_t_NvmMethodDirection;
  typedef struct
  {
    ALN_t_NvmMethodDirection Elevation;
    ALN_t_NvmMethodDirection Azimuth;
  } ALN_t_NvmMethod;
  typedef struct
  {
    signed short s_Real;
    signed short s_Imag;
  } t_Complex16;
  typedef t_Complex16 FPGA_t_PathComp[12];
  typedef signed short Monopulse_array_t[384];

#if (CFG_ARS510_SWITCH == SWITCH_ON)
  typedef unsigned char u_Dummy_array_t_7[2];
#else
  typedef unsigned char u_Dummy_array_t_7[3];
#endif

  typedef struct
  {
    ALN_t_NvmMethod Current;
    ALN_t_NvmMethod Eol;
    ALN_t_NvmMethod Automatic;
    ALN_t_NvmMethod Service;
    float f_CurrentElevationStd;
    float f_CurrentAzimuthStd;
    FPGA_t_PathComp a_PathCompensations;
    #if (CFG_ARS510_SWITCH == SWITCH_ON)
    Monopulse_array_t Monopulse;
    #endif
    boolean b_PathCompensationsValid;
    #if (CFG_ARS510_SWITCH == SWITCH_ON)
    boolean b_MonopulseValid;
    #endif
    u_Dummy_array_t_7 u_Dummy;
  } ALN_Content_t;

  typedef unsigned char u_Dummy_array_t_8[3];

  typedef struct
  {
    unsigned long u_VersionNumber;
    SignalHeader_t sSigHeader;
    ALN_Content_t ALN_Content;
    boolean b_NvmContentValid;
    u_Dummy_array_t_8 u_Dummy;
  } ALN_t_Nvm;
}// ALN_t_Nvm version 100

// ALN_t_Nvm version 101
namespace ALN_t_Nvm_Radar5xx_V101
{
  typedef struct
  {
    #if (CFG_ARS510_SWITCH == SWITCH_ON)
    ALN_t_Nvm_Radar5xx_V100::ALN_t_NvmMethodDirection Elevation;
    #endif
    ALN_t_Nvm_Radar5xx_V100::ALN_t_NvmMethodDirection Azimuth;
  } ALN_t_NvmMethod;


  typedef struct
  {
    ALN_t_NvmMethod Current;
    ALN_t_NvmMethod Eol;
    ALN_t_NvmMethod Automatic;
    ALN_t_NvmMethod Service;
    #if (CFG_ARS510_SWITCH == SWITCH_ON)
    float f_CurrentElevationStd;
    #endif
    float f_CurrentAzimuthStd;
    ALN_t_Nvm_Radar5xx_V100::FPGA_t_PathComp a_PathCompensations;
    #if (CFG_ARS510_SWITCH == SWITCH_ON)
    ALN_t_Nvm_Radar5xx_V100::Monopulse_array_t Monopulse;
    #endif
    boolean b_PathCompensationsValid;
    #if (CFG_ARS510_SWITCH == SWITCH_ON)
    boolean b_MonopulseValid;
    #endif
    ALN_t_Nvm_Radar5xx_V100::u_Dummy_array_t_7 u_Dummy;
  } ALN_Content_t;

  typedef struct
  {
    unsigned long u_VersionNumber;
    SignalHeader_t sSigHeader;
    ALN_Content_t ALN_Content;
    boolean b_NvmContentValid;
    ALN_t_Nvm_Radar5xx_V100::u_Dummy_array_t_8 u_Dummy;
  } ALN_t_Nvm;
}// ALN_t_Nvm version 101

  // ALN_t_Nvm version 102
namespace ALN_t_Nvm_Radar5xx_V102
{
  typedef signed short Monopulse_array_t[193];
  typedef struct
  {
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    ALN_t_Nvm_Radar5xx_V100::ALN_t_NvmMethodDirection Elevation;
#endif
    ALN_t_Nvm_Radar5xx_V100::ALN_t_NvmMethodDirection Azimuth;
  } ALN_t_NvmMethod;


  typedef struct
  {
    ALN_t_NvmMethod Current;
    ALN_t_NvmMethod Eol;
    ALN_t_NvmMethod Automatic;
    ALN_t_NvmMethod Service;
    ALN_t_NvmMethod EolInspection;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    float f_CurrentElevationStd;
#endif
    float f_CurrentAzimuthStd;
    ALN_t_Nvm_Radar5xx_V100::FPGA_t_PathComp a_PathCompensations;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    Monopulse_array_t Monopulse;
#endif
    boolean b_PathCompensationsValid;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    boolean b_MonopulseValid;
#endif
#if (CFG_SRR520_SWITCH == SWITCH_ON)
    u_Dummy_array_t_3 u_Dummy;
#endif
  } ALN_Content_t;

  typedef struct
  {
    unsigned long u_VersionNumber;
    SignalHeader_t sSigHeader;
    ALN_Content_t ALN_Content;
    boolean b_NvmContentValid;
    ALN_t_Nvm_Radar5xx_V100::u_Dummy_array_t_8 u_Dummy;
  } ALN_t_Nvm;
}// ALN_t_Nvm version 102

// Generic ARS5xx & SRR5xx ALN_t_Nvm
// Holds all possible structure members from all possible namespaces
namespace ALN_t_Nvm_Radar5xx_Gen
{
  typedef struct
  {
    unsigned long u_VersionNumber;
    SignalHeader_t sSigHeader;
    ALN_t_Nvm_Radar5xx_V100::ALN_Content_t ALN_Content_V100;
    ALN_t_Nvm_Radar5xx_V101::ALN_Content_t ALN_Content_V101;
    ALN_t_Nvm_Radar5xx_V102::ALN_Content_t ALN_Content_V102;
    boolean b_NvmContentValid;
  } ALN_t_Nvm;
}

class CConvAlnRteNvm : public CSimConverterBase
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

  ALN_t_Nvm_Radar5xx_Gen::ALN_t_Nvm m_BufGen;
  ALN_t_Nvm_Radar5xx_V100::ALN_t_Nvm m_BufV100;
  ALN_t_Nvm_Radar5xx_V101::ALN_t_Nvm m_BufV101;
  ALN_t_Nvm_Radar5xx_V102::ALN_t_Nvm m_BufV102;

  // Initialization
  template <typename T> static void InitVersion (T & Dest, uint32 VersionNumber)
  {
    ::memset(&Dest, 0, sizeof(Dest));
    Dest.u_VersionNumber = VersionNumber;
  }

  // Conversions from provide port (input) to generic buffer
  void Convert_V100_to_Gen (const ALN_t_Nvm_Radar5xx_V100::ALN_t_Nvm & Src);
  void Convert_V101_to_Gen (const ALN_t_Nvm_Radar5xx_V101::ALN_t_Nvm & Src);
  void Convert_V102_to_Gen (const ALN_t_Nvm_Radar5xx_V102::ALN_t_Nvm & Src);

  // Conversions form generic buffer to receive port (output)
  void Convert_Gen_to_V100 (ALN_t_Nvm_Radar5xx_V100::ALN_t_Nvm & Dest);
  void Convert_Gen_to_V101 (ALN_t_Nvm_Radar5xx_V101::ALN_t_Nvm & Dest);
  void Convert_Gen_to_V102 (ALN_t_Nvm_Radar5xx_V102::ALN_t_Nvm & Dest);

public:

  static const char *GetConverterTypeName()
  {
    return "ALN_t_Nvm";
  }

  CConvAlnRteNvm(void);
  virtual ~CConvAlnRteNvm(void);

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

  enum SyncRefVersions
  {
    ALN_NVM_V100,
    ALN_NVM_V101,
    ALN_NVM_V102,
    ALN_NVM_VERSION_COUNT
  };

  static const unsigned long SUPPORTED_SIZE[ALN_NVM_VERSION_COUNT];

  static CVersionInfoImpl * const ALN_NVM_VERSION_NUMBERS[ALN_NVM_VERSION_COUNT];

  bool PortSupported (SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * pPortVersionInfo = NULL) const;

};

CVersionInfoImpl CConvAlnRteNvm::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvAlnRteNvm::VERSION100(0, 0, 100);
CVersionInfoImpl CConvAlnRteNvm::VERSION101(0, 0, 101);
CVersionInfoImpl CConvAlnRteNvm::VERSION102(0, 0, 102);

const unsigned long CConvAlnRteNvm::SUPPORTED_SIZE[CConvAlnRteNvm::ALN_NVM_VERSION_COUNT] =
{
  sizeof(ALN_t_Nvm_Radar5xx_V100::ALN_t_Nvm),
  sizeof(ALN_t_Nvm_Radar5xx_V101::ALN_t_Nvm),
  sizeof(ALN_t_Nvm_Radar5xx_V102::ALN_t_Nvm)
};

CVersionInfoImpl * const CConvAlnRteNvm::ALN_NVM_VERSION_NUMBERS[CConvAlnRteNvm::ALN_NVM_VERSION_COUNT]=
{
  &VERSION100,
  &VERSION101,
  &VERSION102
};


CConvAlnRteNvm::CConvAlnRteNvm(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufGen(), m_BufV100(), m_BufV101(), m_BufV102()
{
}

CConvAlnRteNvm::~CConvAlnRteNvm(void)
{
}

bool CConvAlnRteNvm::PortSupported(SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * pPortVersionInfo) const
{
  bool bResult = false;
  unsigned int i;

  if (ePortType == simOPAQUE_t)
  {
    for (i=0; (i<CConvAlnRteNvm::ALN_NVM_VERSION_COUNT) && (false == bResult); i++)
    {
      if (ulPortSize == SUPPORTED_SIZE[i])
      {
        // Check if version information is compatible - with extra care for simulators that do not set the version number at all...
        if ((pPortVersionInfo == NULL) || (pPortVersionInfo->Equals(ALN_NVM_VERSION_NUMBERS[i])) || (pPortVersionInfo->Equals(&BASE_VERSION)))
        {
          bResult = true;
        }
      }
    }
  }
  return bResult;
}


void CConvAlnRteNvm::Convert_V100_to_Gen (const ALN_t_Nvm_Radar5xx_V100::ALN_t_Nvm & Src)
{
  m_BufGen.u_VersionNumber                      = Src.u_VersionNumber;
  m_BufGen.sSigHeader                           = Src.sSigHeader;
  m_BufGen.b_NvmContentValid                    = Src.b_NvmContentValid;
  /* fill Content_V100 */
  m_BufGen.ALN_Content_V100 = Src.ALN_Content;

  /* fill Content_V101 */
  memset(&m_BufGen.ALN_Content_V101, 0, sizeof(m_BufGen.ALN_Content_V101));
  /*Current*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V101.Current.Elevation.f_Correction = Src.ALN_Content.Current.Elevation.f_Correction;
  m_BufGen.ALN_Content_V101.Current.Elevation.b_Valid = Src.ALN_Content.Current.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V101.Current.Azimuth.f_Correction = Src.ALN_Content.Current.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V101.Current.Azimuth.b_Valid = Src.ALN_Content.Current.Azimuth.b_Valid;
  /*Eol*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V101.Eol.Elevation.f_Correction = Src.ALN_Content.Eol.Elevation.f_Correction;
  m_BufGen.ALN_Content_V101.Eol.Elevation.b_Valid = Src.ALN_Content.Eol.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V101.Eol.Azimuth.f_Correction = Src.ALN_Content.Eol.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V101.Eol.Azimuth.b_Valid = Src.ALN_Content.Eol.Azimuth.b_Valid;
  /*Automatic*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V101.Automatic.Elevation.f_Correction = Src.ALN_Content.Automatic.Elevation.f_Correction;
  m_BufGen.ALN_Content_V101.Automatic.Elevation.b_Valid = Src.ALN_Content.Automatic.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V101.Automatic.Azimuth.f_Correction = Src.ALN_Content.Automatic.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V101.Automatic.Azimuth.b_Valid = Src.ALN_Content.Automatic.Azimuth.b_Valid;
  /*Service*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V101.Service.Elevation.f_Correction = Src.ALN_Content.Service.Elevation.f_Correction;
  m_BufGen.ALN_Content_V101.Service.Elevation.b_Valid = Src.ALN_Content.Service.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V101.Service.Azimuth.f_Correction = Src.ALN_Content.Service.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V101.Service.Azimuth.b_Valid = Src.ALN_Content.Service.Azimuth.b_Valid;
  
  memcpy(&(m_BufGen.ALN_Content_V101.a_PathCompensations[0]), &(Src.ALN_Content.a_PathCompensations[0]), sizeof(Src.ALN_Content.a_PathCompensations));
  m_BufGen.ALN_Content_V101.b_PathCompensationsValid = Src.ALN_Content.b_PathCompensationsValid;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  memcpy(&(m_BufGen.ALN_Content_V101.Monopulse[0]), &(Src.ALN_Content.Monopulse[0]), sizeof(Src.ALN_Content.Monopulse));
  m_BufGen.ALN_Content_V101.b_MonopulseValid = Src.ALN_Content.b_MonopulseValid;
#endif
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V101.f_CurrentElevationStd = Src.ALN_Content.f_CurrentElevationStd;
#endif
  m_BufGen.ALN_Content_V101.f_CurrentAzimuthStd = Src.ALN_Content.f_CurrentAzimuthStd;

  /* fill Content_V102 */
  memset(&m_BufGen.ALN_Content_V102, 0, sizeof(m_BufGen.ALN_Content_V102));
  /*Current*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V102.Current.Elevation.f_Correction = Src.ALN_Content.Current.Elevation.f_Correction;
  m_BufGen.ALN_Content_V102.Current.Elevation.b_Valid = Src.ALN_Content.Current.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V102.Current.Azimuth.f_Correction = Src.ALN_Content.Current.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V102.Current.Azimuth.b_Valid = Src.ALN_Content.Current.Azimuth.b_Valid;
  /*Eol*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V102.Eol.Elevation.f_Correction = Src.ALN_Content.Eol.Elevation.f_Correction;
  m_BufGen.ALN_Content_V102.Eol.Elevation.b_Valid = Src.ALN_Content.Eol.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V102.Eol.Azimuth.f_Correction = Src.ALN_Content.Eol.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V102.Eol.Azimuth.b_Valid = Src.ALN_Content.Eol.Azimuth.b_Valid;
  /*Automatic*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V102.Automatic.Elevation.f_Correction = Src.ALN_Content.Automatic.Elevation.f_Correction;
  m_BufGen.ALN_Content_V102.Automatic.Elevation.b_Valid = Src.ALN_Content.Automatic.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V102.Automatic.Azimuth.f_Correction = Src.ALN_Content.Automatic.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V102.Automatic.Azimuth.b_Valid = Src.ALN_Content.Automatic.Azimuth.b_Valid;
  /*Service*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V102.Service.Elevation.f_Correction = Src.ALN_Content.Service.Elevation.f_Correction;
  m_BufGen.ALN_Content_V102.Service.Elevation.b_Valid = Src.ALN_Content.Service.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V102.Service.Azimuth.f_Correction = Src.ALN_Content.Service.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V102.Service.Azimuth.b_Valid = Src.ALN_Content.Service.Azimuth.b_Valid;

  memcpy(&(m_BufGen.ALN_Content_V102.a_PathCompensations[0]), &(Src.ALN_Content.a_PathCompensations[0]), sizeof(Src.ALN_Content.a_PathCompensations));
  m_BufGen.ALN_Content_V102.b_PathCompensationsValid = Src.ALN_Content.b_PathCompensationsValid;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V102.b_MonopulseValid = Src.ALN_Content.b_MonopulseValid;
#endif
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V102.f_CurrentElevationStd = Src.ALN_Content.f_CurrentElevationStd;
#endif
  m_BufGen.ALN_Content_V102.f_CurrentAzimuthStd = Src.ALN_Content.f_CurrentAzimuthStd;

}

void CConvAlnRteNvm::Convert_V101_to_Gen (const ALN_t_Nvm_Radar5xx_V101::ALN_t_Nvm & Src)
{
  m_BufGen.u_VersionNumber                      = Src.u_VersionNumber;
  m_BufGen.sSigHeader                           = Src.sSigHeader;
  m_BufGen.b_NvmContentValid                    = Src.b_NvmContentValid;

  /* fill Content_V100 */
  memset(&m_BufGen.ALN_Content_V100, 0, sizeof(m_BufGen.ALN_Content_V100));
  /*Current*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V100.Current.Elevation.f_Correction = Src.ALN_Content.Current.Elevation.f_Correction;
  m_BufGen.ALN_Content_V100.Current.Elevation.b_Valid = Src.ALN_Content.Current.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V100.Current.Azimuth.f_Correction = Src.ALN_Content.Current.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V100.Current.Azimuth.b_Valid = Src.ALN_Content.Current.Azimuth.b_Valid;
  /*Eol*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V100.Eol.Elevation.f_Correction = Src.ALN_Content.Eol.Elevation.f_Correction;
  m_BufGen.ALN_Content_V100.Eol.Elevation.b_Valid = Src.ALN_Content.Eol.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V100.Eol.Azimuth.f_Correction = Src.ALN_Content.Eol.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V100.Eol.Azimuth.b_Valid = Src.ALN_Content.Eol.Azimuth.b_Valid;
  /*Automatic*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V100.Automatic.Elevation.f_Correction = Src.ALN_Content.Automatic.Elevation.f_Correction;
  m_BufGen.ALN_Content_V100.Automatic.Elevation.b_Valid = Src.ALN_Content.Automatic.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V100.Automatic.Azimuth.f_Correction = Src.ALN_Content.Automatic.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V100.Automatic.Azimuth.b_Valid = Src.ALN_Content.Automatic.Azimuth.b_Valid;
  /*Service*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V100.Service.Elevation.f_Correction = Src.ALN_Content.Service.Elevation.f_Correction;
  m_BufGen.ALN_Content_V100.Service.Elevation.b_Valid = Src.ALN_Content.Service.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V100.Service.Azimuth.f_Correction = Src.ALN_Content.Service.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V100.Service.Azimuth.b_Valid = Src.ALN_Content.Service.Azimuth.b_Valid;

  memcpy(&(m_BufGen.ALN_Content_V100.a_PathCompensations[0]), &(Src.ALN_Content.a_PathCompensations[0]), sizeof(Src.ALN_Content.a_PathCompensations));
  m_BufGen.ALN_Content_V100.b_PathCompensationsValid = Src.ALN_Content.b_PathCompensationsValid;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  memcpy(&(m_BufGen.ALN_Content_V100.Monopulse[0]), &(Src.ALN_Content.Monopulse[0]), sizeof(Src.ALN_Content.Monopulse));
  m_BufGen.ALN_Content_V100.b_MonopulseValid = Src.ALN_Content.b_MonopulseValid;
#endif
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V100.f_CurrentElevationStd = Src.ALN_Content.f_CurrentElevationStd;
#endif
  m_BufGen.ALN_Content_V100.f_CurrentAzimuthStd = Src.ALN_Content.f_CurrentAzimuthStd;

  /* fill Content_V101 */
  m_BufGen.ALN_Content_V101 = Src.ALN_Content;

  /* fill Content_V102 */
  memset(&m_BufGen.ALN_Content_V102, 0, sizeof(m_BufGen.ALN_Content_V102));
  /*Current*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V102.Current.Elevation.f_Correction = Src.ALN_Content.Current.Elevation.f_Correction;
  m_BufGen.ALN_Content_V102.Current.Elevation.b_Valid = Src.ALN_Content.Current.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V102.Current.Azimuth.f_Correction = Src.ALN_Content.Current.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V102.Current.Azimuth.b_Valid = Src.ALN_Content.Current.Azimuth.b_Valid;
  /*Eol*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V102.Eol.Elevation.f_Correction = Src.ALN_Content.Eol.Elevation.f_Correction;
  m_BufGen.ALN_Content_V102.Eol.Elevation.b_Valid = Src.ALN_Content.Eol.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V102.Eol.Azimuth.f_Correction = Src.ALN_Content.Eol.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V102.Eol.Azimuth.b_Valid = Src.ALN_Content.Eol.Azimuth.b_Valid;
  /*Automatic*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V102.Automatic.Elevation.f_Correction = Src.ALN_Content.Automatic.Elevation.f_Correction;
  m_BufGen.ALN_Content_V102.Automatic.Elevation.b_Valid = Src.ALN_Content.Automatic.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V102.Automatic.Azimuth.f_Correction = Src.ALN_Content.Automatic.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V102.Automatic.Azimuth.b_Valid = Src.ALN_Content.Automatic.Azimuth.b_Valid;
  /*Service*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V102.Service.Elevation.f_Correction = Src.ALN_Content.Service.Elevation.f_Correction;
  m_BufGen.ALN_Content_V102.Service.Elevation.b_Valid = Src.ALN_Content.Service.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V102.Service.Azimuth.f_Correction = Src.ALN_Content.Service.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V102.Service.Azimuth.b_Valid = Src.ALN_Content.Service.Azimuth.b_Valid;

  memcpy(&(m_BufGen.ALN_Content_V102.a_PathCompensations[0]), &(Src.ALN_Content.a_PathCompensations[0]), sizeof(Src.ALN_Content.a_PathCompensations));
  m_BufGen.ALN_Content_V102.b_PathCompensationsValid = Src.ALN_Content.b_PathCompensationsValid;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V102.b_MonopulseValid = Src.ALN_Content.b_MonopulseValid;
#endif
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V102.f_CurrentElevationStd = Src.ALN_Content.f_CurrentElevationStd;
#endif
  m_BufGen.ALN_Content_V102.f_CurrentAzimuthStd = Src.ALN_Content.f_CurrentAzimuthStd;
}

void CConvAlnRteNvm::Convert_V102_to_Gen (const ALN_t_Nvm_Radar5xx_V102::ALN_t_Nvm & Src)
{
  m_BufGen.u_VersionNumber                      = Src.u_VersionNumber;
  m_BufGen.sSigHeader                           = Src.sSigHeader;
  m_BufGen.b_NvmContentValid                    = Src.b_NvmContentValid;

  /* fill Content_V100 */
  memset(&m_BufGen.ALN_Content_V100, 0, sizeof(m_BufGen.ALN_Content_V100));
  /*Current*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V100.Current.Elevation.f_Correction = Src.ALN_Content.Current.Elevation.f_Correction;
  m_BufGen.ALN_Content_V100.Current.Elevation.b_Valid = Src.ALN_Content.Current.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V100.Current.Azimuth.f_Correction = Src.ALN_Content.Current.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V100.Current.Azimuth.b_Valid = Src.ALN_Content.Current.Azimuth.b_Valid;
  /*Eol*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V100.Eol.Elevation.f_Correction = Src.ALN_Content.Eol.Elevation.f_Correction;
  m_BufGen.ALN_Content_V100.Eol.Elevation.b_Valid = Src.ALN_Content.Eol.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V100.Eol.Azimuth.f_Correction = Src.ALN_Content.Eol.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V100.Eol.Azimuth.b_Valid = Src.ALN_Content.Eol.Azimuth.b_Valid;
  /*Automatic*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V100.Automatic.Elevation.f_Correction = Src.ALN_Content.Automatic.Elevation.f_Correction;
  m_BufGen.ALN_Content_V100.Automatic.Elevation.b_Valid = Src.ALN_Content.Automatic.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V100.Automatic.Azimuth.f_Correction = Src.ALN_Content.Automatic.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V100.Automatic.Azimuth.b_Valid = Src.ALN_Content.Automatic.Azimuth.b_Valid;
  /*Service*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V100.Service.Elevation.f_Correction = Src.ALN_Content.Service.Elevation.f_Correction;
  m_BufGen.ALN_Content_V100.Service.Elevation.b_Valid = Src.ALN_Content.Service.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V100.Service.Azimuth.f_Correction = Src.ALN_Content.Service.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V100.Service.Azimuth.b_Valid = Src.ALN_Content.Service.Azimuth.b_Valid;

  memcpy(&(m_BufGen.ALN_Content_V100.a_PathCompensations[0]), &(Src.ALN_Content.a_PathCompensations[0]), sizeof(Src.ALN_Content.a_PathCompensations));
  m_BufGen.ALN_Content_V100.b_PathCompensationsValid = Src.ALN_Content.b_PathCompensationsValid;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  memcpy(&(m_BufGen.ALN_Content_V100.Monopulse[0]), &(Src.ALN_Content.Monopulse[0]), sizeof(Src.ALN_Content.Monopulse));
  m_BufGen.ALN_Content_V100.b_MonopulseValid = Src.ALN_Content.b_MonopulseValid;
#endif
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V100.f_CurrentElevationStd = Src.ALN_Content.f_CurrentElevationStd;
#endif
  m_BufGen.ALN_Content_V100.f_CurrentAzimuthStd = Src.ALN_Content.f_CurrentAzimuthStd;

  /* fill Content_V101 */
  /* fill Content_V101 */
  memset(&m_BufGen.ALN_Content_V101, 0, sizeof(m_BufGen.ALN_Content_V101));
  /*Current*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V101.Current.Elevation.f_Correction = Src.ALN_Content.Current.Elevation.f_Correction;
  m_BufGen.ALN_Content_V101.Current.Elevation.b_Valid = Src.ALN_Content.Current.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V101.Current.Azimuth.f_Correction = Src.ALN_Content.Current.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V101.Current.Azimuth.b_Valid = Src.ALN_Content.Current.Azimuth.b_Valid;
  /*Eol*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V101.Eol.Elevation.f_Correction = Src.ALN_Content.Eol.Elevation.f_Correction;
  m_BufGen.ALN_Content_V101.Eol.Elevation.b_Valid = Src.ALN_Content.Eol.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V101.Eol.Azimuth.f_Correction = Src.ALN_Content.Eol.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V101.Eol.Azimuth.b_Valid = Src.ALN_Content.Eol.Azimuth.b_Valid;
  /*Automatic*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V101.Automatic.Elevation.f_Correction = Src.ALN_Content.Automatic.Elevation.f_Correction;
  m_BufGen.ALN_Content_V101.Automatic.Elevation.b_Valid = Src.ALN_Content.Automatic.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V101.Automatic.Azimuth.f_Correction = Src.ALN_Content.Automatic.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V101.Automatic.Azimuth.b_Valid = Src.ALN_Content.Automatic.Azimuth.b_Valid;
  /*Service*/
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V101.Service.Elevation.f_Correction = Src.ALN_Content.Service.Elevation.f_Correction;
  m_BufGen.ALN_Content_V101.Service.Elevation.b_Valid = Src.ALN_Content.Service.Elevation.b_Valid;
#endif
  m_BufGen.ALN_Content_V101.Service.Azimuth.f_Correction = Src.ALN_Content.Service.Azimuth.f_Correction;
  m_BufGen.ALN_Content_V101.Service.Azimuth.b_Valid = Src.ALN_Content.Service.Azimuth.b_Valid;

  memcpy(&(m_BufGen.ALN_Content_V101.a_PathCompensations[0]), &(Src.ALN_Content.a_PathCompensations[0]), sizeof(Src.ALN_Content.a_PathCompensations));
  m_BufGen.ALN_Content_V101.b_PathCompensationsValid = Src.ALN_Content.b_PathCompensationsValid;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  memcpy(&(m_BufGen.ALN_Content_V101.Monopulse[0]), &(Src.ALN_Content.Monopulse[0]), sizeof(Src.ALN_Content.Monopulse));
  m_BufGen.ALN_Content_V101.b_MonopulseValid = Src.ALN_Content.b_MonopulseValid;
#endif
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.ALN_Content_V101.f_CurrentElevationStd = Src.ALN_Content.f_CurrentElevationStd;
#endif
  m_BufGen.ALN_Content_V101.f_CurrentAzimuthStd = Src.ALN_Content.f_CurrentAzimuthStd;

  /* fill Content_V102 */
  m_BufGen.ALN_Content_V102 = Src.ALN_Content;
}


void CConvAlnRteNvm::Convert_Gen_to_V100 (ALN_t_Nvm_Radar5xx_V100::ALN_t_Nvm & Dest)
{
  Dest.u_VersionNumber          = 100u;
  Dest.sSigHeader               = m_BufGen.sSigHeader;
  Dest.ALN_Content              = m_BufGen.ALN_Content_V100;
  Dest.b_NvmContentValid        = m_BufGen.b_NvmContentValid;
}


void CConvAlnRteNvm::Convert_Gen_to_V101 (ALN_t_Nvm_Radar5xx_V101::ALN_t_Nvm & Dest)
{
  Dest.u_VersionNumber          = 101u;
  Dest.sSigHeader               = m_BufGen.sSigHeader;
  Dest.ALN_Content              = m_BufGen.ALN_Content_V101;
  Dest.b_NvmContentValid        = m_BufGen.b_NvmContentValid;
}

void CConvAlnRteNvm::Convert_Gen_to_V102 (ALN_t_Nvm_Radar5xx_V102::ALN_t_Nvm & Dest)
{
  Dest.u_VersionNumber          = 102u;
  Dest.sSigHeader               = m_BufGen.sSigHeader;
  Dest.ALN_Content              = m_BufGen.ALN_Content_V102;
  Dest.b_NvmContentValid        = m_BufGen.b_NvmContentValid;
}



long CConvAlnRteNvm::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  bool bGenBufferFilled = false;
  const uint32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<uint32*>(pPPortData)):(0);
  // If direct one:one copy possible then do that
  if ((ulPPortSize == ulRPortSize)
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION102)) || (pProvidePortVersionInfo->Equals(&VERSION101)) || (pProvidePortVersionInfo->Equals(&VERSION100)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    /* do not explicitly check data version -> if size fits, just use it */
    )
  {
    lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
  }
  // First decide from which version we are converting and fill the generic buffer accordingly
  else if ((ulPPortSize == sizeof(ALN_t_Nvm_Radar5xx_V100::ALN_t_Nvm))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION100)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    && ((uDataVer == 100u) || (uDataVer == 0)))
  {
    // Source Port V100
    CConvAlnRteNvm::InitVersion(m_BufGen,100u);
    const ALN_t_Nvm_Radar5xx_V100::ALN_t_Nvm & Src = *reinterpret_cast<ALN_t_Nvm_Radar5xx_V100::ALN_t_Nvm*>(pPPortData);
    Convert_V100_to_Gen(Src);
    bGenBufferFilled = true;
  }
  else if ((ulPPortSize == sizeof(ALN_t_Nvm_Radar5xx_V101::ALN_t_Nvm))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION101)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    && ((uDataVer == 101u) || (uDataVer == 0)))
  {
    // Source Port V101
    CConvAlnRteNvm::InitVersion(m_BufGen,101u);
    ALN_t_Nvm_Radar5xx_V101::ALN_t_Nvm & Src = *reinterpret_cast<ALN_t_Nvm_Radar5xx_V101::ALN_t_Nvm*>(pPPortData);
    Convert_V101_to_Gen(Src);
    bGenBufferFilled = true;
  }
  else if ((ulPPortSize == sizeof(ALN_t_Nvm_Radar5xx_V102::ALN_t_Nvm))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION102)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    && ((uDataVer == 102u) || (uDataVer == 0)))
  {
    // Source Port V102
    CConvAlnRteNvm::InitVersion(m_BufGen,102u);
    ALN_t_Nvm_Radar5xx_V102::ALN_t_Nvm & Src = *reinterpret_cast<ALN_t_Nvm_Radar5xx_V102::ALN_t_Nvm*>(pPPortData);
    Convert_V102_to_Gen(Src);
    bGenBufferFilled = true;
  }

  if (bGenBufferFilled == true)
  {
    // Second decide to which version we are converting
    // and take the generic buffer to fill the destination buffer
    if ((ulRPortSize == sizeof(ALN_t_Nvm_Radar5xx_V102::ALN_t_Nvm)) && ((requestPortVersionInfo.Equals(&VERSION102)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V102
      CConvAlnRteNvm::InitVersion(m_BufV102,102u);
      ALN_t_Nvm_Radar5xx_V102::ALN_t_Nvm & Dest = /*reinterpret_cast<ALN_t_Nvm_Radar5xx_V102::ALN_t_Nvm &>*/(m_BufV102);
      Convert_Gen_to_V102(Dest);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_t_Nvm_Radar5xx_V101::ALN_t_Nvm)) && ((requestPortVersionInfo.Equals(&VERSION101)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V101
      CConvAlnRteNvm::InitVersion(m_BufV101,101u);
      ALN_t_Nvm_Radar5xx_V101::ALN_t_Nvm & Dest = /*reinterpret_cast<ALN_t_Nvm_Radar5xx_V101::ALN_t_Nvm &>*/(m_BufV101);
      Convert_Gen_to_V101(Dest);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_t_Nvm_Radar5xx_V100::ALN_t_Nvm)) && ((requestPortVersionInfo.Equals(&VERSION100)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V100
      CConvAlnRteNvm::InitVersion(m_BufV100,100u);
      ALN_t_Nvm_Radar5xx_V100::ALN_t_Nvm & Dest = /*reinterpret_cast<ALN_t_Nvm_Radar5xx_V100::ALN_t_Nvm &>*/(m_BufV100);
      Convert_Gen_to_V100(Dest);
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
long CConvAlnRteNvm::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(ALN_t_Nvm_Radar5xx_V100::ALN_t_Nvm)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(&VERSION100))))
    {
      InitVersion(m_BufV100, 100u);
      *pDefaultData = &m_BufV100;
      ulDefaultSize = sizeof(m_BufV100);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_t_Nvm_Radar5xx_V101::ALN_t_Nvm)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(&VERSION101))))
    {
      InitVersion(m_BufV101, 101u);
      *pDefaultData = &m_BufV101;
      ulDefaultSize = sizeof(m_BufV101);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_t_Nvm_Radar5xx_V102::ALN_t_Nvm)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(&VERSION102))))
    {
      InitVersion(m_BufV102, 102u);
      *pDefaultData = &m_BufV102;
      ulDefaultSize = sizeof(m_BufV102);
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
bool CConvAlnRteNvm::IsVersionCompatibleWithType(
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
bool CConvAlnRteNvm::AreVersionsCompatible(
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
IConverter * CreateAlnRteNvmConvClass(void)
{
  return new CConvAlnRteNvm();
}
