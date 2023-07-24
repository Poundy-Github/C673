/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_em

  MODULNAME:            sim_conv_vdyerrors.cpp

  DESCRIPTION:          

  AUTHOR:               Manuel Olejua

  CREATION DATE:        

  VERSION:              $$

  ---*/ /*---

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_conv_vdyerrors.h"
#include "sim_versioninfo_impl.h"
#include <tchar.h>

typedef float float32;
typedef unsigned __int8 boolean, uint8;
typedef unsigned __int32 uint32;


/* typedef VDYCtrlState_t */
#ifndef VDY_CTRL_STATE_STARTUP
  #define VDY_CTRL_STATE_STARTUP (0U)
#endif
#ifndef VDY_CTRL_STATE_INIT
  #define VDY_CTRL_STATE_INIT (1U)
#endif
#ifndef VDY_CTRL_STATE_RUNNING
  #define VDY_CTRL_STATE_RUNNING (2U)
#endif


/* typedef AlgoSignalState_t */
#ifndef AL_SIG_STATE_INIT
  #define AL_SIG_STATE_INIT (0U)
#endif
#ifndef AL_SIG_STATE_OK
  #define AL_SIG_STATE_OK (1U)
#endif


// VDYErrors_t_ARS4xx_V2         
namespace VDYErrors_t_ARS4xx_V2
{
  typedef unsigned short AlgoDataTimeStamp_t       /* Algo data time-stamp type @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char VDYErrState_t             /* the vdy error state type @min: 0 @max:2 @values: enum { VDY_ERR_STATE_INACTIVE=2,VDY_ERR_STATE_ACTIVE=1,VDY_ERR_STATE_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;

  typedef struct OutPutErrors_t			/* [Satisfies_rte sws 1191] */
  {
    VDYErrState_t YwrOffsRg;
    VDYErrState_t SwaOffsRg;
    VDYErrState_t AyOffsRg;
    VDYErrState_t VelCorrRg;
    VDYErrState_t NVMYwrOffsRg;
    VDYErrState_t NVMSwaOffsRg;
    VDYErrState_t NVMAyOffsRg;
    VDYErrState_t NVMVelCorrRg;
    VDYErrState_t VelCorrWin;
    VDYErrState_t VelMon;
    VDYErrState_t VelMonLt;
    VDYErrState_t VelocityErr;
    VDYErrState_t YawRateErr;
    VDYErrState_t YwrMonVehHalt;
    VDYErrState_t YwrMonVehDOff;
    VDYErrState_t YwrMonAdmWdrwl;
    VDYErrState_t YwrACCMonAlignm;
    VDYErrState_t YwrCGMonAlignm;
    VDYErrState_t YwrMonVehHaltCal;
    VDYErrState_t VDY_FS_YR_VS_WSP;
    VDYErrState_t VDY_FS_YR_VS_AY;
    VDYErrState_t VDY_FS_YR_VS_SWA;
    VDYErrState_t VDY_VEH_VEL_NOT_AVAILABLE;
    VDYErrState_t VDY_VEH_YWR_NOT_AVAILABLE;
   } OutPutErrors_t;			/* Output values and internalal errors */

  typedef struct ParInputErrors_t			/* [Satisfies_rte sws 1191] */
  {
	  VDYErrState_t InputParameterError;
   } ParInputErrors_t;			/* Parameter input errors */

  typedef struct SignalInputErrors_t			/* [Satisfies_rte sws 1191] */
  {
	  VDYErrState_t InputSignalError;
 	  VDYErrState_t InputSignalPeakError;
   } SignalInputErrors_t;			/* Signal input errors */

  typedef struct VDYErrors_t                 /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    SignalInputErrors_t SignalInputErrors;
    ParInputErrors_t ParInputErrors;
    OutPutErrors_t OutPutErrors;
  } VDYErrors_t;                             
}

// VDYErrors_t_ARS4xx_V2          
namespace VDYErrors_t_ARS4xx_V3
{
  typedef unsigned long AlgoDataTimeStamp_t      /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned short AlgoCycleCounter_t      /* Algo cycle counter @min:0 @max:65535 */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned char AlgoSignalState_t        /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned long AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char VDYErrState_t             /* the vdy error state type @min: 0 @max:2 @values: enum { VDY_ERR_STATE_INACTIVE=2,VDY_ERR_STATE_ACTIVE=1,VDY_ERR_STATE_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;

  typedef struct SignalHeader_t                  /* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;                              /* Common header for all structured data types */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    VDYErrState_t YwrOffsRg;
    VDYErrState_t SwaOffsRg;
    VDYErrState_t AyOffsRg;
    VDYErrState_t VelCorrRg;
    VDYErrState_t NVMYwrOffsRg;
    VDYErrState_t NVMSwaOffsRg;
    VDYErrState_t NVMAyOffsRg;
    VDYErrState_t NVMVelCorrRg;
    VDYErrState_t VelCorrWin;
    VDYErrState_t VelMon;
    VDYErrState_t VelMonLt;
    VDYErrState_t VelocityErr;
    VDYErrState_t YawRateErr;
    VDYErrState_t YwrMonVehHalt;
    VDYErrState_t YwrMonVehDOff;
    VDYErrState_t YwrMonAdmWdrwl;
    VDYErrState_t YwrACCMonAlignm;
    VDYErrState_t YwrCGMonAlignm;
    VDYErrState_t YwrMonVehHaltCal;
    VDYErrState_t VDY_FS_YR_VS_WSP;
    VDYErrState_t VDY_FS_YR_VS_AY;
    VDYErrState_t VDY_FS_YR_VS_SWA;
    VDYErrState_t VDY_VEH_VEL_NOT_AVAILABLE;
    VDYErrState_t VDY_VEH_YWR_NOT_AVAILABLE;
    VDYErrState_t VDY_FS_VEH_CORR_MON;
   } OutPutErrors_t;			/* Output values and internalal errors */

  typedef struct VDYErrors_t                 /* [Satisfies_rte sws 1191] */
  {
    AlgoInterfaceVersionNumber_t  uiVersionNumber;
    SignalHeader_t sSigHeader;
    VDYErrors_t_ARS4xx_V2::SignalInputErrors_t SignalInputErrors;
    VDYErrors_t_ARS4xx_V2::ParInputErrors_t ParInputErrors;
    OutPutErrors_t OutPutErrors;
  } VDYErrors_t;                             
}


class CConvVdyErrors : public CSimConverterBase
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

  VDYErrors_t_ARS4xx_V2::VDYErrors_t m_BufV2;
  VDYErrors_t_ARS4xx_V3::VDYErrors_t m_BufV3;

  static void InitV2(VDYErrors_t_ARS4xx_V2::VDYErrors_t & Params);
  static void InitV3(VDYErrors_t_ARS4xx_V3::VDYErrors_t & Params);

public:

  static const TCHAR *GetConverterTypeName()
  {
    return _T("VdyErrors");
  }

  CConvVdyErrors(void);
  virtual ~CConvVdyErrors(void);

  const TCHAR *GetTypeName()
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

  //static CVersionInfoImpl VERSION2;
  static CVersionInfoImpl VERSION2;
  static CVersionInfoImpl VERSION3;

  enum BSWAlgoParameters
  {
    VDY_ERROS_V2,
    VDY_ERROS_V3,
    //ALN_RTE_BSW_IN_V3,
    BSW_ALGO_PARAM_VERSION_COUNT
  };

  static const unsigned long SUPPORTED_SIZE[BSW_ALGO_PARAM_VERSION_COUNT];

};

//CVersionInfoImpl CConvVdyErrors::VERSION2(0, 0, 0);
CVersionInfoImpl CConvVdyErrors::VERSION2(0, 0, 2);
CVersionInfoImpl CConvVdyErrors::VERSION3(0, 0, 3);

const unsigned long CConvVdyErrors::SUPPORTED_SIZE[CConvVdyErrors::BSW_ALGO_PARAM_VERSION_COUNT] =
{
  sizeof(VDYErrors_t_ARS4xx_V2::VDYErrors_t),
  sizeof(VDYErrors_t_ARS4xx_V3::VDYErrors_t),
  //sizeof(RSP_t_InputActl_ARS4xx_V3::RSP_t_InputActl),
};

CConvVdyErrors::CConvVdyErrors(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufV2(), m_BufV3()
{
}

CConvVdyErrors::~CConvVdyErrors(void)
{
}

void CConvVdyErrors::InitV2(VDYErrors_t_ARS4xx_V2::VDYErrors_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber = 2u;
  Params.SignalInputErrors.InputSignalError     = 0;
  Params.SignalInputErrors.InputSignalPeakError = 0;
  Params.ParInputErrors.InputParameterError     = 0;
  Params.OutPutErrors.AyOffsRg                  = 0;
  Params.OutPutErrors.NVMAyOffsRg               = 0;
  Params.OutPutErrors.NVMSwaOffsRg              = 0;
  Params.OutPutErrors.NVMVelCorrRg              = 0;
  Params.OutPutErrors.NVMYwrOffsRg              = 0;
  Params.OutPutErrors.SwaOffsRg                 = 0;
  Params.OutPutErrors.VDY_FS_YR_VS_AY           = 0;
  Params.OutPutErrors.VDY_FS_YR_VS_SWA          = 0;
  Params.OutPutErrors.VDY_FS_YR_VS_WSP          = 0;
  Params.OutPutErrors.VDY_VEH_VEL_NOT_AVAILABLE = 0;
  Params.OutPutErrors.VDY_VEH_YWR_NOT_AVAILABLE = 0;
  Params.OutPutErrors.VelCorrRg                 = 0;
  Params.OutPutErrors.VelCorrWin                = 0;
  Params.OutPutErrors.VelMon                    = 0;
  Params.OutPutErrors.VelMonLt                  = 0;
  Params.OutPutErrors.VelocityErr               = 0;
  Params.OutPutErrors.YawRateErr                = 0;
  Params.OutPutErrors.YwrACCMonAlignm           = 0;
  Params.OutPutErrors.YwrCGMonAlignm            = 0;
  Params.OutPutErrors.YwrMonAdmWdrwl            = 0;
  Params.OutPutErrors.YwrMonVehDOff             = 0;
  Params.OutPutErrors.YwrMonVehHalt             = 0;
  Params.OutPutErrors.YwrMonVehHaltCal          = 0;
  Params.OutPutErrors.YwrOffsRg                 = 0;
}

void CConvVdyErrors::InitV3(VDYErrors_t_ARS4xx_V3::VDYErrors_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber = 3u;
  // Signal Header
  Params.sSigHeader.uiTimeStamp                  = 0;
  Params.sSigHeader.uiMeasurementCounter         = 0;
  Params.sSigHeader.uiCycleCounter               = 0;
  Params.sSigHeader.eSigStatus                   = AL_SIG_STATE_INIT;
  Params.SignalInputErrors.InputSignalError     = 0;
  Params.SignalInputErrors.InputSignalPeakError = 0;
  Params.ParInputErrors.InputParameterError     = 0;
  Params.OutPutErrors.AyOffsRg                  = 0;
  Params.OutPutErrors.NVMAyOffsRg               = 0;
  Params.OutPutErrors.NVMSwaOffsRg              = 0;
  Params.OutPutErrors.NVMVelCorrRg              = 0;
  Params.OutPutErrors.NVMYwrOffsRg              = 0;
  Params.OutPutErrors.SwaOffsRg                 = 0;
  Params.OutPutErrors.VDY_FS_YR_VS_AY           = 0;
  Params.OutPutErrors.VDY_FS_YR_VS_SWA          = 0;
  Params.OutPutErrors.VDY_FS_YR_VS_WSP          = 0;
  Params.OutPutErrors.VDY_VEH_VEL_NOT_AVAILABLE = 0;
  Params.OutPutErrors.VDY_VEH_YWR_NOT_AVAILABLE = 0;
  Params.OutPutErrors.VelCorrRg                 = 0;
  Params.OutPutErrors.VelCorrWin                = 0;
  Params.OutPutErrors.VelMon                    = 0;
  Params.OutPutErrors.VelMonLt                  = 0;
  Params.OutPutErrors.VelocityErr               = 0;
  Params.OutPutErrors.YawRateErr                = 0;
  Params.OutPutErrors.YwrACCMonAlignm           = 0;
  Params.OutPutErrors.YwrCGMonAlignm            = 0;
  Params.OutPutErrors.YwrMonAdmWdrwl            = 0;
  Params.OutPutErrors.YwrMonVehDOff             = 0;
  Params.OutPutErrors.YwrMonVehHalt             = 0;
  Params.OutPutErrors.YwrMonVehHaltCal          = 0;
  Params.OutPutErrors.YwrOffsRg                 = 0;
  Params.OutPutErrors.VDY_FS_VEH_CORR_MON       = 0;
}

long CConvVdyErrors::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  const uint32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<uint32*>(pPPortData)):(0);
  // First decide which version we are converting to
  if ((ulRPortSize == sizeof(m_BufV3)) && ((requestPortVersionInfo.Equals(&VERSION3)) || (requestPortVersionInfo.Equals(&VERSION2))))
  {
    // Destination port of V2_2
    VDYErrors_t_ARS4xx_V3::VDYErrors_t & Dest = m_BufV3;
    if ((ulPPortSize == ulRPortSize)
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION3)) || (pProvidePortVersionInfo->Equals(&VERSION2)))
      && ((uDataVer == 2u) || (uDataVer == 3)))
    {
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
    else if ((ulPPortSize == sizeof(m_BufV2))
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION3)) || (pProvidePortVersionInfo->Equals(&VERSION2)))
      && ((uDataVer == 2u) || (uDataVer == 3)))
    {
      const VDYErrors_t_ARS4xx_V2::VDYErrors_t & Src = *reinterpret_cast<VDYErrors_t_ARS4xx_V2::VDYErrors_t*>(pPPortData);
      Dest.uiVersionNumber                        = 3u;
      Dest.sSigHeader.uiTimeStamp                 = 0;
      Dest.sSigHeader.uiCycleCounter              = 0;
      Dest.sSigHeader.uiMeasurementCounter        = 0;
      Dest.sSigHeader.eSigStatus                  = AL_SIG_STATE_OK;
      Dest.SignalInputErrors.InputSignalError     = Src.SignalInputErrors.InputSignalError;
      Dest.SignalInputErrors.InputSignalPeakError = Src.SignalInputErrors.InputSignalPeakError;
      Dest.ParInputErrors.InputParameterError     = Src.ParInputErrors.InputParameterError;
      Dest.OutPutErrors.AyOffsRg                  = Src.OutPutErrors.AyOffsRg;
      Dest.OutPutErrors.NVMAyOffsRg               = Src.OutPutErrors.NVMAyOffsRg;
      Dest.OutPutErrors.NVMSwaOffsRg              = Src.OutPutErrors.NVMSwaOffsRg;
      Dest.OutPutErrors.NVMVelCorrRg              = Src.OutPutErrors.NVMVelCorrRg;
      Dest.OutPutErrors.NVMYwrOffsRg              = Src.OutPutErrors.NVMYwrOffsRg;
      Dest.OutPutErrors.SwaOffsRg                 = Src.OutPutErrors.SwaOffsRg;
      Dest.OutPutErrors.VDY_FS_YR_VS_AY           = Src.OutPutErrors.VDY_FS_YR_VS_AY;
      Dest.OutPutErrors.VDY_FS_YR_VS_SWA          = Src.OutPutErrors.VDY_FS_YR_VS_SWA;
      Dest.OutPutErrors.VDY_FS_YR_VS_WSP          = Src.OutPutErrors.VDY_FS_YR_VS_WSP;
      Dest.OutPutErrors.VDY_VEH_VEL_NOT_AVAILABLE = Src.OutPutErrors.VDY_VEH_VEL_NOT_AVAILABLE;
      Dest.OutPutErrors.VDY_VEH_YWR_NOT_AVAILABLE = Src.OutPutErrors.VDY_VEH_YWR_NOT_AVAILABLE;
      Dest.OutPutErrors.VelCorrRg                 = Src.OutPutErrors.VelCorrRg;
      Dest.OutPutErrors.VelCorrWin                = Src.OutPutErrors.VelCorrWin;
      Dest.OutPutErrors.VelMon                    = Src.OutPutErrors.VelMonLt;
      Dest.OutPutErrors.VelMonLt                  = Src.OutPutErrors.VelMonLt;
      Dest.OutPutErrors.VelocityErr               = Src.OutPutErrors.VelocityErr;
      Dest.OutPutErrors.YawRateErr                = Src.OutPutErrors.YawRateErr;
      Dest.OutPutErrors.YwrACCMonAlignm           = Src.OutPutErrors.YwrACCMonAlignm;
      Dest.OutPutErrors.YwrCGMonAlignm            = Src.OutPutErrors.YwrCGMonAlignm;
      Dest.OutPutErrors.YwrMonAdmWdrwl            = Src.OutPutErrors.YwrMonAdmWdrwl;
      Dest.OutPutErrors.YwrMonVehDOff             = Src.OutPutErrors.YwrMonVehDOff;
      Dest.OutPutErrors.YwrMonVehHalt             = Src.OutPutErrors.YwrMonVehHalt;
      Dest.OutPutErrors.YwrMonVehHaltCal          = Src.OutPutErrors.YwrMonVehHaltCal;
      Dest.OutPutErrors.YwrOffsRg                 = Src.OutPutErrors.YwrOffsRg;
      Dest.OutPutErrors.VDY_FS_VEH_CORR_MON       = 0;

      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
  }
  else if ((ulRPortSize == sizeof(m_BufV2)) && ((requestPortVersionInfo.Equals(&VERSION3)) || (requestPortVersionInfo.Equals(&VERSION2))))
  {
    // Destination port of V2_1
    VDYErrors_t_ARS4xx_V2::VDYErrors_t & Dest = m_BufV2;
    if ((ulPPortSize == sizeof(m_BufV3))
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION3)) || (pProvidePortVersionInfo->Equals(&VERSION2)))
      && ((uDataVer == 3u) || (uDataVer == 2)))
    {
      const VDYErrors_t_ARS4xx_V3::VDYErrors_t & Src = *reinterpret_cast<VDYErrors_t_ARS4xx_V3::VDYErrors_t*>(pPPortData);
      Dest.uiVersionNumber                        = 2u;
      Dest.SignalInputErrors.InputSignalError     = Src.SignalInputErrors.InputSignalError;
      Dest.SignalInputErrors.InputSignalPeakError = Src.SignalInputErrors.InputSignalPeakError;
      Dest.ParInputErrors.InputParameterError     = Src.ParInputErrors.InputParameterError;
      Dest.OutPutErrors.AyOffsRg                  = Src.OutPutErrors.AyOffsRg;
      Dest.OutPutErrors.NVMAyOffsRg               = Src.OutPutErrors.NVMAyOffsRg;
      Dest.OutPutErrors.NVMSwaOffsRg              = Src.OutPutErrors.NVMSwaOffsRg;
      Dest.OutPutErrors.NVMVelCorrRg              = Src.OutPutErrors.NVMVelCorrRg;
      Dest.OutPutErrors.NVMYwrOffsRg              = Src.OutPutErrors.NVMYwrOffsRg;
      Dest.OutPutErrors.SwaOffsRg                 = Src.OutPutErrors.SwaOffsRg;
      Dest.OutPutErrors.VDY_FS_YR_VS_AY           = Src.OutPutErrors.VDY_FS_YR_VS_AY;
      Dest.OutPutErrors.VDY_FS_YR_VS_SWA          = Src.OutPutErrors.VDY_FS_YR_VS_SWA;
      Dest.OutPutErrors.VDY_FS_YR_VS_WSP          = Src.OutPutErrors.VDY_FS_YR_VS_WSP;
      Dest.OutPutErrors.VDY_VEH_VEL_NOT_AVAILABLE = Src.OutPutErrors.VDY_VEH_VEL_NOT_AVAILABLE;
      Dest.OutPutErrors.VDY_VEH_YWR_NOT_AVAILABLE = Src.OutPutErrors.VDY_VEH_YWR_NOT_AVAILABLE;
      Dest.OutPutErrors.VelCorrRg                 = Src.OutPutErrors.VelCorrRg;
      Dest.OutPutErrors.VelCorrWin                = Src.OutPutErrors.VelCorrWin;
      Dest.OutPutErrors.VelMon                    = Src.OutPutErrors.VelMonLt;
      Dest.OutPutErrors.VelMonLt                  = Src.OutPutErrors.VelMonLt;
      Dest.OutPutErrors.VelocityErr               = Src.OutPutErrors.VelocityErr;
      Dest.OutPutErrors.YawRateErr                = Src.OutPutErrors.YawRateErr;
      Dest.OutPutErrors.YwrACCMonAlignm           = Src.OutPutErrors.YwrACCMonAlignm;
      Dest.OutPutErrors.YwrCGMonAlignm            = Src.OutPutErrors.YwrCGMonAlignm;
      Dest.OutPutErrors.YwrMonAdmWdrwl            = Src.OutPutErrors.YwrMonAdmWdrwl;
      Dest.OutPutErrors.YwrMonVehDOff             = Src.OutPutErrors.YwrMonVehDOff;
      Dest.OutPutErrors.YwrMonVehHalt             = Src.OutPutErrors.YwrMonVehHalt;
      Dest.OutPutErrors.YwrMonVehHaltCal          = Src.OutPutErrors.YwrMonVehHaltCal;
      Dest.OutPutErrors.YwrOffsRg                 = Src.OutPutErrors.YwrOffsRg;
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulPPortSize == ulRPortSize)
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION3)) || (pProvidePortVersionInfo->Equals(&VERSION2)))
      && ((uDataVer == 2u) || (uDataVer == 3)))
    {
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
  }
  return lRet;
}

/** returns:
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvVdyErrors::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if (VERSION2.Equals(&requestPortVersionInfo) || VERSION3.Equals(&requestPortVersionInfo))
    {
      if (ulRPortSize == sizeof(m_BufV3))
      {
        InitV3(m_BufV3);
        *pDefaultData = &m_BufV3;
        ulDefaultSize = sizeof(m_BufV3);
        lRet = SIM_ERR_OK;
      }
      else if (ulRPortSize == sizeof(m_BufV2))
      {
        InitV2(m_BufV2);
        *pDefaultData = &m_BufV2;
        ulDefaultSize = sizeof(m_BufV2);
        lRet = SIM_ERR_OK;
      }
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvVdyErrors::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
  {
  bool bResult = false;
  if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if (requestPortVersionInfo.Equals(&VERSION3) || requestPortVersionInfo.Equals(&VERSION2))
    {
      if (ulRPortSize == sizeof(m_BufV2))
      {
        if (ulPPortSize == sizeof(m_BufV2))
        {
          bResult = true;
        }
        else if (ulPPortSize == sizeof(m_BufV3))
        {
          bResult = true;
        }
      }
      else if (ulRPortSize == sizeof(m_BufV3))
      {
        if (ulPPortSize == sizeof(m_BufV2))
        {
          bResult = true;
        }
        else if (ulPPortSize == sizeof(m_BufV3))
        {
          bResult = true;
        }
      }
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvVdyErrors::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo)
{
  bool bResult = false;
  if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if (requestPortVersionInfo.Equals(&VERSION3) || requestPortVersionInfo.Equals(&VERSION2))
    {
      if (providePortVersionInfo.Equals(&VERSION3) || providePortVersionInfo.Equals(&VERSION2))
      {
        if (ulRPortSize == sizeof(m_BufV2))
        {
          if (ulPPortSize == sizeof(m_BufV2))
          {
            bResult = true;
          }
          else if (ulPPortSize == sizeof(m_BufV3))
          {
            bResult = true;
          }
        }
        else if (ulRPortSize == sizeof(m_BufV3))
        {
          if (ulPPortSize == sizeof(m_BufV2))
          {
            bResult = true;
          }
          else if (ulPPortSize == sizeof(m_BufV3))
          {
            bResult = true;
          }
        }
      }
    }
  }
  return bResult;
}

//
// Main factory class returning conversion class
//
IConverter * CreateVdyErrorsConvClass(void)
{
  return new CConvVdyErrors();
}