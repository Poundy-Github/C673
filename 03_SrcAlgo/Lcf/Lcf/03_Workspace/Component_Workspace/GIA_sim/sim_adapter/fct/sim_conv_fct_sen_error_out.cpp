/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_em

  MODULNAME:            sim_conv_fct_sen_error_out.cpp

  DESCRIPTION:

  AUTHOR:               Manuel Olejua

  CREATION DATE:

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_fct_sen_error_out.cpp  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:17CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.6 2016/03/03 08:50:49CET Cretu, Teodora (CretuT) 
  CHANGES:              New version is added (V15) which has the same structure as V14
  CHANGES:              Revision 1.5 2015/06/16 12:31:16CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + version V14
  CHANGES:              - Added comments -  berndtt1 [Jun 16, 2015 12:55:02 PM CEST]
  CHANGES:              Change Package : 276620:8 http://mks-psad:7002/im/viewissue?selection=276620
  CHANGES:              Revision 1.4 2015/05/27 07:33:19CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + version V13
  CHANGES:              --- Added comments ---  berndtt1 [May 29, 2015 10:05:59 AM CEST]
  CHANGES:              Change Package : 334720:1 http://mks-psad:7002/im/viewissue?selection=334720
  CHANGES:              Revision 1.3 2015/04/01 11:49:02CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              * Updated to generic conversion strategy
  CHANGES:              + version V11 and V12
  CHANGES:              + conversion V9 (=V7_2)
  CHANGES:              --- Added comments ---  berndtt1 [Apr 1, 2015 12:00:49 PM CEST]
  CHANGES:              Change Package : 221167:45 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.2 2014/09/10 08:56:41CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Added 1:1 Conversion, changed TypeName to "FCTSenErrrorOut_t"
  CHANGES:              --- Added comments ---  berndtt1 [Sep 10, 2014 11:43:34 AM CEST]
  CHANGES:              Change Package : 221167:30 http://mks-psad:7002/im/viewissue?selection=221167

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_conv_fct_sen_error_out.h"
#include "sim_versioninfo_impl.h"

/* typedef AlgoSignalState_t */
#ifndef AL_SIG_STATE_INIT
  #define AL_SIG_STATE_INIT (0U)
#endif
#ifndef AL_SIG_STATE_OK
  #define AL_SIG_STATE_OK (1U)
#endif

#define DEFAULT_TSAFETYDISTANCEEBA (500.0f)

namespace FCTSenErrorOutV6
{
  typedef unsigned char AlgoErrorState_t                             /* Algo error state enumeration @min: 0 @max:2 @values: enum { AL_ERR_STATE_UNKNOWN=0,AL_ERR_STATE_ACTIVE=1,AL_ERR_STATE_INACTIVE=2,} */ /* [Satisfies_rte sws 1188] */;

  typedef struct FCTSenErrorOut_t                                    /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    AlgoErrorState_t ObjectNotMeasured;
    AlgoErrorState_t ObjectNotMeasTmp;
    AlgoErrorState_t Blockage;
    AlgoErrorState_t IncreaseBlockage;
    AlgoErrorState_t DecreaseBlockage;
    AlgoErrorState_t VeloInsuffAcc;
    AlgoErrorState_t YawRateInsuffAcc;
    AlgoErrorState_t InterferenceRange;
    AlgoErrorState_t SRDDampingState;
    boolean bObjSelectionActive;
    boolean bCollisionAvoidActive;
    boolean bRequestRoadBeam;
  } FCTSenErrorOut_t;
}; // End of namespace FCTSenErrorOutV6

namespace FCTSenErrorOutV7_1
{
  typedef struct FCTSenErrorOut_t                                    /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    FCTSenErrorOutV6::AlgoErrorState_t ObjectNotMeasured;
    FCTSenErrorOutV6::AlgoErrorState_t ObjectNotMeasTmp;
    FCTSenErrorOutV6::AlgoErrorState_t Blockage;
    FCTSenErrorOutV6::AlgoErrorState_t IncreaseBlockage;
    FCTSenErrorOutV6::AlgoErrorState_t DecreaseBlockage;
    FCTSenErrorOutV6::AlgoErrorState_t VeloInsuffAcc;
    FCTSenErrorOutV6::AlgoErrorState_t YawRateInsuffAcc;
    FCTSenErrorOutV6::AlgoErrorState_t InterferenceRange;
    FCTSenErrorOutV6::AlgoErrorState_t SRDDampingState;
    boolean bObjSelectionActive;
    boolean bCollisionAvoidActive;
    boolean bRequestRoadBeam;
  } FCTSenErrorOut_t;
}; // End of namespace FCTSenErrorOutV7_1

namespace FCTSenErrorOutV7_2
{
  typedef unsigned long AlgoDataTimeStamp_t                          /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned short AlgoCycleCounter_t                          /* Algo cycle counter @min:0 @max:65535 */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned char AlgoSignalState_t                            /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */  /* [Satisfies_rte sws 1188] */;

  typedef struct SignalHeader_t                                      /* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;                                                  /* Common header for all structured data types */

  typedef struct FCTSenErrorOut_t                                    /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    FCTSenErrorOutV6::AlgoErrorState_t ObjectNotMeasured;
    FCTSenErrorOutV6::AlgoErrorState_t ObjectNotMeasTmp;
    FCTSenErrorOutV6::AlgoErrorState_t Blockage;
    FCTSenErrorOutV6::AlgoErrorState_t IncreaseBlockage;
    FCTSenErrorOutV6::AlgoErrorState_t DecreaseBlockage;
    FCTSenErrorOutV6::AlgoErrorState_t VeloInsuffAcc;
    FCTSenErrorOutV6::AlgoErrorState_t YawRateInsuffAcc;
    FCTSenErrorOutV6::AlgoErrorState_t InterferenceRange;
    FCTSenErrorOutV6::AlgoErrorState_t SRDDampingState;
    boolean bObjSelectionActive;
    boolean bCollisionAvoidActive;
    boolean bRequestRoadBeam;
  } FCTSenErrorOut_t;                                                /* Custom Inputs for functional requirements @vaddr:FCT_MEAS_ID_CUSTOM_INPUT @cycleid:FCT_ENV @vname:FCTCustomInputData */
}; // End of namespace FCTSenErrorOutV7_2

namespace FCTSenErrorOutV11                                          // from fct_interface_types.xls revision 1.249
{
  typedef unsigned char SPM_t_e_Error;

  typedef struct FCTSenErrorOut_t                                    /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    FCTSenErrorOutV7_2::SignalHeader_t sSigHeader;
    FCTSenErrorOutV6::AlgoErrorState_t ObjectNotMeasured;
    FCTSenErrorOutV6::AlgoErrorState_t ObjectNotMeasTmp;
    FCTSenErrorOutV6::AlgoErrorState_t Blockage;
    FCTSenErrorOutV6::AlgoErrorState_t IncreaseBlockage;
    FCTSenErrorOutV6::AlgoErrorState_t DecreaseBlockage;
    boolean b_ACCPerformanceDist;
    SPM_t_e_Error e_PerfDegrExeedQuota;
    FCTSenErrorOutV6::AlgoErrorState_t InterferenceRange;
    FCTSenErrorOutV6::AlgoErrorState_t SRDDampingState;
    boolean bObjSelectionActive;
    boolean bCollisionAvoidActive;
    boolean bRequestRoadBeam;
  } FCTSenErrorOut_t;
}; // End of namespace FCTSenErrorOutV11

namespace FCTSenErrorOutV12                                          // from fct_interface_types.xls revision 1.280
{
  typedef struct FCTSenErrorOut_t                                    /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    FCTSenErrorOutV7_2::SignalHeader_t sSigHeader;
    FCTSenErrorOutV6::AlgoErrorState_t ObjectNotMeasured;
    FCTSenErrorOutV6::AlgoErrorState_t ObjectNotMeasTmp;
    FCTSenErrorOutV6::AlgoErrorState_t Blockage;
    FCTSenErrorOutV6::AlgoErrorState_t IncreaseBlockage;
    FCTSenErrorOutV6::AlgoErrorState_t DecreaseBlockage;
    FCTSenErrorOutV6::AlgoErrorState_t BelowMinPerfDist_AZ;
    FCTSenErrorOutV6::AlgoErrorState_t BelowMinPerfDist_VDY;
    FCTSenErrorOutV6::AlgoErrorState_t BelowMinPerfDist_EL;
    FCTSenErrorOutV6::AlgoErrorState_t InterferenceRange;
    FCTSenErrorOutV6::AlgoErrorState_t SRDDampingState;
    boolean bObjSelectionActive;
    boolean bCollisionAvoidActive;
    boolean bRequestRoadBeam;
  } FCTSenErrorOut_t;
}; // End of namespace FCTSenErrorOutV12

namespace FCTSenErrorOutV13                                          // from fct_interface_types.xls revision 1.280
{
  typedef struct FCTSenErrorOut_t                                    /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    FCTSenErrorOutV7_2::SignalHeader_t sSigHeader;
    FCTSenErrorOutV6::AlgoErrorState_t ObjectNotMeasured;
    FCTSenErrorOutV6::AlgoErrorState_t ObjectNotMeasTmp;
    FCTSenErrorOutV6::AlgoErrorState_t Blockage;
    FCTSenErrorOutV6::AlgoErrorState_t IncreaseBlockage;
    FCTSenErrorOutV6::AlgoErrorState_t DecreaseBlockage;
    FCTSenErrorOutV6::AlgoErrorState_t BelowMinPerfDist_AZ;
    FCTSenErrorOutV6::AlgoErrorState_t BelowMinPerfDist_VDY;
    FCTSenErrorOutV6::AlgoErrorState_t BelowMinPerfDist_EL;
    FCTSenErrorOutV6::AlgoErrorState_t InterferenceRange;
    FCTSenErrorOutV6::AlgoErrorState_t SRDDampingState;
    boolean bObjSelectionActive;
    boolean bCollisionAvoidActive;
    boolean bRequestRoadBeam;
    float tSafetyDistanceEBA;
  } FCTSenErrorOut_t;
}; // End of namespace FCTSenErrorOutV13

namespace FCTSenErrorOutV14                                          // from fct_interface_types.xls revision 1.280
{
  typedef struct FCTSenErrorOut_t                                    /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    FCTSenErrorOutV7_2::SignalHeader_t sSigHeader;
    FCTSenErrorOutV6::AlgoErrorState_t ObjectNotMeasured;
    FCTSenErrorOutV6::AlgoErrorState_t ObjectNotMeasTmp;
    FCTSenErrorOutV6::AlgoErrorState_t Blockage;
    FCTSenErrorOutV6::AlgoErrorState_t IncreaseBlockage;
    FCTSenErrorOutV6::AlgoErrorState_t DecreaseBlockage;
    unsigned __int8 uiNoOfObjLosses;
    FCTSenErrorOutV6::AlgoErrorState_t BelowMinPerfDist_AZ;
    FCTSenErrorOutV6::AlgoErrorState_t BelowMinPerfDist_VDY;
    FCTSenErrorOutV6::AlgoErrorState_t BelowMinPerfDist_EL;
    FCTSenErrorOutV6::AlgoErrorState_t InterferenceRange;
    FCTSenErrorOutV6::AlgoErrorState_t SRDDampingState;
    boolean bObjSelectionActive;
    boolean bCollisionAvoidActive;
    boolean bRequestRoadBeam;
    float tSafetyDistanceEBA;
  } FCTSenErrorOut_t;
}; // End of namespace FCTSenErrorOutV14

namespace FCTSenErrorOutGen
{
  typedef struct FCTSenErrorOut_t                                    /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    FCTSenErrorOutV7_2::SignalHeader_t sSigHeader;
    FCTSenErrorOutV6::AlgoErrorState_t ObjectNotMeasured;
    FCTSenErrorOutV6::AlgoErrorState_t ObjectNotMeasTmp;
    FCTSenErrorOutV6::AlgoErrorState_t Blockage;
    FCTSenErrorOutV6::AlgoErrorState_t IncreaseBlockage;
    FCTSenErrorOutV6::AlgoErrorState_t DecreaseBlockage;
    unsigned __int8 uiNoOfObjLosses;
    FCTSenErrorOutV6::AlgoErrorState_t VeloInsuffAcc;
    FCTSenErrorOutV6::AlgoErrorState_t YawRateInsuffAcc;
    boolean b_ACCPerformanceDist;
    FCTSenErrorOutV11::SPM_t_e_Error e_PerfDegrExeedQuota;
    FCTSenErrorOutV6::AlgoErrorState_t BelowMinPerfDist_AZ;
    FCTSenErrorOutV6::AlgoErrorState_t BelowMinPerfDist_VDY;
    FCTSenErrorOutV6::AlgoErrorState_t BelowMinPerfDist_EL;
    FCTSenErrorOutV6::AlgoErrorState_t InterferenceRange;
    FCTSenErrorOutV6::AlgoErrorState_t SRDDampingState;
    boolean bObjSelectionActive;
    boolean bCollisionAvoidActive;
    boolean bRequestRoadBeam;
    float tSafetyDistanceEBA;
  } FCTSenErrorOut_t;
}; // End of namespace FCTSenErrorOutGen

class CConvFctSenErrorOut : public CSimConverterBase
{

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here
    DEP_COUNT
  };

  // Buffer for holding converted data
  FCTSenErrorOutV6::FCTSenErrorOut_t m_BufV6;
  FCTSenErrorOutV7_1::FCTSenErrorOut_t m_BufV7_1;
  FCTSenErrorOutV7_2::FCTSenErrorOut_t m_BufV7_2;
  FCTSenErrorOutV11::FCTSenErrorOut_t m_BufV11;
  FCTSenErrorOutV12::FCTSenErrorOut_t m_BufV12;
  FCTSenErrorOutV13::FCTSenErrorOut_t m_BufV13;
  FCTSenErrorOutV14::FCTSenErrorOut_t m_BufV14;
  FCTSenErrorOutGen::FCTSenErrorOut_t m_BufGen;

    // Initialization
  template <typename T> static void Init (T & Dest, uint32 VersionNumber)
  {
    ::memset(&Dest, 0, sizeof(Dest));
    Dest.uiVersionNumber = VersionNumber;
  }

public:

  static const char* GetConverterTypeName()
  {
    return "FCTSenErrorOut_t";
  }

  CConvFctSenErrorOut(void);
  virtual ~CConvFctSenErrorOut(void);

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
  static void Convert_V6_to_Gen   (FCTSenErrorOutGen::FCTSenErrorOut_t & Dest, const FCTSenErrorOutV6::FCTSenErrorOut_t   & Src);
  static void Convert_V7_1_to_Gen (FCTSenErrorOutGen::FCTSenErrorOut_t & Dest, const FCTSenErrorOutV7_1::FCTSenErrorOut_t & Src);
  static void Convert_V7_2_to_Gen (FCTSenErrorOutGen::FCTSenErrorOut_t & Dest, const FCTSenErrorOutV7_2::FCTSenErrorOut_t & Src);
  static void Convert_V11_to_Gen  (FCTSenErrorOutGen::FCTSenErrorOut_t & Dest, const FCTSenErrorOutV11::FCTSenErrorOut_t  & Src);
  static void Convert_V12_to_Gen  (FCTSenErrorOutGen::FCTSenErrorOut_t & Dest, const FCTSenErrorOutV12::FCTSenErrorOut_t  & Src);
  static void Convert_V13_to_Gen  (FCTSenErrorOutGen::FCTSenErrorOut_t & Dest, const FCTSenErrorOutV13::FCTSenErrorOut_t  & Src);
  static void Convert_V14_to_Gen  (FCTSenErrorOutGen::FCTSenErrorOut_t & Dest, const FCTSenErrorOutV14::FCTSenErrorOut_t  & Src);

  static void Convert_Gen_to_V6   (FCTSenErrorOutV6::FCTSenErrorOut_t   & Dest, const FCTSenErrorOutGen::FCTSenErrorOut_t & Src);
  static void Convert_Gen_to_V7_2 (FCTSenErrorOutV7_2::FCTSenErrorOut_t & Dest, const FCTSenErrorOutGen::FCTSenErrorOut_t & Src);
  static void Convert_Gen_to_V7_1 (FCTSenErrorOutV7_1::FCTSenErrorOut_t & Dest, const FCTSenErrorOutGen::FCTSenErrorOut_t & Src);
  static void Convert_Gen_to_V11  (FCTSenErrorOutV11::FCTSenErrorOut_t  & Dest, const FCTSenErrorOutGen::FCTSenErrorOut_t & Src);
  static void Convert_Gen_to_V12  (FCTSenErrorOutV12::FCTSenErrorOut_t  & Dest, const FCTSenErrorOutGen::FCTSenErrorOut_t & Src);
  static void Convert_Gen_to_V13  (FCTSenErrorOutV13::FCTSenErrorOut_t  & Dest, const FCTSenErrorOutGen::FCTSenErrorOut_t & Src);
  static void Convert_Gen_to_V14  (FCTSenErrorOutV14::FCTSenErrorOut_t  & Dest, const FCTSenErrorOutGen::FCTSenErrorOut_t & Src);


  //static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl VERSION6;
  static CVersionInfoImpl VERSION7;
  static CVersionInfoImpl VERSION9;
  static CVersionInfoImpl VERSION11;
  static CVersionInfoImpl VERSION12;
  static CVersionInfoImpl VERSION13;
  static CVersionInfoImpl VERSION14;
  static CVersionInfoImpl VERSION15;

  enum FCTSenErrorOut_e
  {
    FCT_SEN_ERROR_OUT_INTFVER6,
    FCT_SEN_ERROR_OUT_INTFVER7_1,
    FCT_SEN_ERROR_OUT_INTFVER7_2,
    FCT_SEN_ERROR_OUT_INTFVER9,
    FCT_SEN_ERROR_OUT_INTFVER11,
    FCT_SEN_ERROR_OUT_INTFVER12,
    FCT_SEN_ERROR_OUT_INTFVER13,
    FCT_SEN_ERROR_OUT_INTFVER14,
    FCT_SEN_ERROR_OUT_INTFVER15,
    FCT_SEN_ERROR_OUT_VERSION_COUNT
  };

  static const CVersionInfoImpl * const FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_VERSION_COUNT];

  static const unsigned long SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_VERSION_COUNT];

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < FCT_SEN_ERROR_OUT_VERSION_COUNT; nI++)
    {
      if ((pPortVersion == NULL) || pPortVersion->Equals(FCT_SEN_ERROR_OUT_VERSIONS[nI]))
      {
        if (ulPortSize == SUPPORTED_SIZE[nI])
        {
          return true;
        }
      }
    };
    return false;
  };
};

//CVersionInfoImpl  CConvFctSenErrorOut::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvFctSenErrorOut::VERSION6(0, 0, 6);
CVersionInfoImpl CConvFctSenErrorOut::VERSION7(0, 0, 7);
CVersionInfoImpl CConvFctSenErrorOut::VERSION9(0, 0, 9);
CVersionInfoImpl CConvFctSenErrorOut::VERSION11(0, 0, 11);
CVersionInfoImpl CConvFctSenErrorOut::VERSION12(0, 0, 12);
CVersionInfoImpl CConvFctSenErrorOut::VERSION13(0, 0, 13);
CVersionInfoImpl CConvFctSenErrorOut::VERSION14(0, 0, 14);
CVersionInfoImpl CConvFctSenErrorOut::VERSION15(0, 0, 15);

const CVersionInfoImpl * const CConvFctSenErrorOut::FCT_SEN_ERROR_OUT_VERSIONS[CConvFctSenErrorOut::FCT_SEN_ERROR_OUT_VERSION_COUNT] =
{
  &VERSION6,
  &VERSION7,
  &VERSION7,
  &VERSION9,
  &VERSION11,
  &VERSION12,
  &VERSION13,
  &VERSION14,
  &VERSION15
};

const unsigned long CConvFctSenErrorOut::SUPPORTED_SIZE[CConvFctSenErrorOut::FCT_SEN_ERROR_OUT_VERSION_COUNT]=
{
  sizeof(FCTSenErrorOutV6::FCTSenErrorOut_t),
  sizeof(FCTSenErrorOutV7_1::FCTSenErrorOut_t),
  sizeof(FCTSenErrorOutV7_2::FCTSenErrorOut_t),
  sizeof(FCTSenErrorOutV7_2::FCTSenErrorOut_t),
  sizeof(FCTSenErrorOutV11::FCTSenErrorOut_t),
  sizeof(FCTSenErrorOutV12::FCTSenErrorOut_t),
  sizeof(FCTSenErrorOutV13::FCTSenErrorOut_t),
  sizeof(FCTSenErrorOutV14::FCTSenErrorOut_t),
  sizeof(FCTSenErrorOutV14::FCTSenErrorOut_t)
};

CConvFctSenErrorOut::CConvFctSenErrorOut(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufV6(), m_BufV7_1(), m_BufV7_2(), m_BufV11(), m_BufV12()
{
}

CConvFctSenErrorOut::~CConvFctSenErrorOut(void)
{
}

void CConvFctSenErrorOut::Convert_V6_to_Gen (FCTSenErrorOutGen::FCTSenErrorOut_t & Dest, const FCTSenErrorOutV6::FCTSenErrorOut_t & Src)
{
  //Dest.uiVersionNumber = Src.uiVersionNumber;
  //Dest.sSigHeader.uiTimeStamp = 0;
  //Dest.sSigHeader.uiMeasurementCounter = 0;
  //Dest.sSigHeader.uiCycleCounter = 0;
  Dest.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  Dest.ObjectNotMeasured     = Src.ObjectNotMeasured;
  Dest.ObjectNotMeasTmp      = Src.ObjectNotMeasTmp;
  Dest.Blockage              = Src.Blockage;
  Dest.IncreaseBlockage      = Src.IncreaseBlockage;
  Dest.DecreaseBlockage      = Src.DecreaseBlockage;
  Dest.uiNoOfObjLosses       = 0;
  Dest.VeloInsuffAcc         = Src.VeloInsuffAcc;
  Dest.YawRateInsuffAcc      = Src.YawRateInsuffAcc;
  Dest.b_ACCPerformanceDist  = 0;
  Dest.e_PerfDegrExeedQuota  = 0;
  Dest.BelowMinPerfDist_AZ   = 0;
  Dest.BelowMinPerfDist_VDY  = 0;
  Dest.BelowMinPerfDist_EL   = 0;
  Dest.InterferenceRange     = Src.InterferenceRange;
  Dest.SRDDampingState       = Src.SRDDampingState;
  Dest.bObjSelectionActive   = Src.bObjSelectionActive;
  Dest.bCollisionAvoidActive = Src.bCollisionAvoidActive;
  Dest.bRequestRoadBeam      = Src.bRequestRoadBeam;
  Dest.tSafetyDistanceEBA    = DEFAULT_TSAFETYDISTANCEEBA;
}

void CConvFctSenErrorOut::Convert_V7_1_to_Gen (FCTSenErrorOutGen::FCTSenErrorOut_t & Dest, const FCTSenErrorOutV7_1::FCTSenErrorOut_t & Src)
{
  //Dest.uiVersionNumber = Src.uiVersionNumber;
  //Dest.sSigHeader.uiTimeStamp = 0;
  //Dest.sSigHeader.uiMeasurementCounter = 0;
  //Dest.sSigHeader.uiCycleCounter = 0;
  Dest.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  Dest.ObjectNotMeasured     = Src.ObjectNotMeasured;
  Dest.ObjectNotMeasTmp      = Src.ObjectNotMeasTmp;
  Dest.Blockage              = Src.Blockage;
  Dest.IncreaseBlockage      = Src.IncreaseBlockage;
  Dest.DecreaseBlockage      = Src.DecreaseBlockage;
  Dest.uiNoOfObjLosses       = 0;
  Dest.VeloInsuffAcc         = Src.VeloInsuffAcc;
  Dest.YawRateInsuffAcc      = Src.YawRateInsuffAcc;
  Dest.b_ACCPerformanceDist  = 0;
  Dest.e_PerfDegrExeedQuota  = 0;
  Dest.BelowMinPerfDist_AZ   = 0;
  Dest.BelowMinPerfDist_VDY  = 0;
  Dest.BelowMinPerfDist_EL   = 0;
  Dest.InterferenceRange     = Src.InterferenceRange;
  Dest.SRDDampingState       = Src.SRDDampingState;
  Dest.bObjSelectionActive   = Src.bObjSelectionActive;
  Dest.bCollisionAvoidActive = Src.bCollisionAvoidActive;
  Dest.bRequestRoadBeam      = Src.bRequestRoadBeam;
  Dest.tSafetyDistanceEBA    = DEFAULT_TSAFETYDISTANCEEBA;
}

void CConvFctSenErrorOut::Convert_V7_2_to_Gen (FCTSenErrorOutGen::FCTSenErrorOut_t & Dest, const FCTSenErrorOutV7_2::FCTSenErrorOut_t & Src)
{
  //Dest.uiVersionNumber = Src.uiVersionNumber;
  Dest.sSigHeader            = Src.sSigHeader;
  Dest.sSigHeader.eSigStatus = 1;
  Dest.ObjectNotMeasured     = Src.ObjectNotMeasured;
  Dest.ObjectNotMeasTmp      = Src.ObjectNotMeasTmp;
  Dest.Blockage              = Src.Blockage;
  Dest.IncreaseBlockage      = Src.IncreaseBlockage;
  Dest.DecreaseBlockage      = Src.DecreaseBlockage;
  Dest.uiNoOfObjLosses       = 0;
  Dest.VeloInsuffAcc         = Src.VeloInsuffAcc;
  Dest.YawRateInsuffAcc      = Src.YawRateInsuffAcc;
  Dest.b_ACCPerformanceDist  = 0;
  Dest.e_PerfDegrExeedQuota  = 0;
  Dest.BelowMinPerfDist_AZ   = 0;
  Dest.BelowMinPerfDist_VDY  = 0;
  Dest.BelowMinPerfDist_EL   = 0;
  Dest.InterferenceRange     = Src.InterferenceRange;
  Dest.SRDDampingState       = Src.SRDDampingState;
  Dest.bObjSelectionActive   = Src.bObjSelectionActive;
  Dest.bCollisionAvoidActive = Src.bCollisionAvoidActive;
  Dest.bRequestRoadBeam      = Src.bRequestRoadBeam;
  Dest.tSafetyDistanceEBA    = DEFAULT_TSAFETYDISTANCEEBA;
}

void CConvFctSenErrorOut::Convert_V11_to_Gen (FCTSenErrorOutGen::FCTSenErrorOut_t & Dest, const FCTSenErrorOutV11::FCTSenErrorOut_t & Src)
{
  //Dest.uiVersionNumber = Src.uiVersionNumber;
  Dest.sSigHeader            = Src.sSigHeader;
  Dest.ObjectNotMeasured     = Src.ObjectNotMeasured;
  Dest.ObjectNotMeasTmp      = Src.ObjectNotMeasTmp;
  Dest.Blockage              = Src.Blockage;
  Dest.IncreaseBlockage      = Src.IncreaseBlockage;
  Dest.DecreaseBlockage      = Src.DecreaseBlockage;
  Dest.uiNoOfObjLosses       = 0;
  Dest.VeloInsuffAcc         = 0;
  Dest.YawRateInsuffAcc      = 0;
  Dest.b_ACCPerformanceDist  = Src.b_ACCPerformanceDist;
  Dest.e_PerfDegrExeedQuota  = Src.e_PerfDegrExeedQuota;
  Dest.BelowMinPerfDist_AZ   = 0;
  Dest.BelowMinPerfDist_VDY  = 0;
  Dest.BelowMinPerfDist_EL   = 0;
  Dest.InterferenceRange     = Src.InterferenceRange;
  Dest.SRDDampingState       = Src.SRDDampingState;
  Dest.bObjSelectionActive   = Src.bObjSelectionActive;
  Dest.bCollisionAvoidActive = Src.bCollisionAvoidActive;
  Dest.bRequestRoadBeam      = Src.bRequestRoadBeam;
  Dest.tSafetyDistanceEBA    = DEFAULT_TSAFETYDISTANCEEBA;
}

void CConvFctSenErrorOut::Convert_V12_to_Gen (FCTSenErrorOutGen::FCTSenErrorOut_t & Dest, const FCTSenErrorOutV12::FCTSenErrorOut_t & Src)
{
  Dest.sSigHeader            = Src.sSigHeader;
  Dest.ObjectNotMeasured     = Src.ObjectNotMeasured;
  Dest.ObjectNotMeasTmp      = Src.ObjectNotMeasTmp;
  Dest.Blockage              = Src.Blockage;
  Dest.IncreaseBlockage      = Src.IncreaseBlockage;
  Dest.DecreaseBlockage      = Src.DecreaseBlockage;
  Dest.uiNoOfObjLosses       = 0;
  Dest.VeloInsuffAcc         = 0;
  Dest.YawRateInsuffAcc      = 0;
  Dest.b_ACCPerformanceDist  = 0;
  Dest.e_PerfDegrExeedQuota  = 0;
  Dest.BelowMinPerfDist_AZ   = Src.BelowMinPerfDist_AZ;
  Dest.BelowMinPerfDist_VDY  = Src.BelowMinPerfDist_VDY;
  Dest.BelowMinPerfDist_EL   = Src.BelowMinPerfDist_EL;
  Dest.InterferenceRange     = Src.InterferenceRange;
  Dest.SRDDampingState       = Src.SRDDampingState;
  Dest.bObjSelectionActive   = Src.bObjSelectionActive;
  Dest.bCollisionAvoidActive = Src.bCollisionAvoidActive;
  Dest.bRequestRoadBeam      = Src.bRequestRoadBeam;
  Dest.tSafetyDistanceEBA    = DEFAULT_TSAFETYDISTANCEEBA;
}

void CConvFctSenErrorOut::Convert_V13_to_Gen (FCTSenErrorOutGen::FCTSenErrorOut_t & Dest, const FCTSenErrorOutV13::FCTSenErrorOut_t & Src)
{
  Dest.sSigHeader            = Src.sSigHeader;
  Dest.ObjectNotMeasured     = Src.ObjectNotMeasured;
  Dest.ObjectNotMeasTmp      = Src.ObjectNotMeasTmp;
  Dest.Blockage              = Src.Blockage;
  Dest.IncreaseBlockage      = Src.IncreaseBlockage;
  Dest.DecreaseBlockage      = Src.DecreaseBlockage;
  Dest.uiNoOfObjLosses       = 0;
  Dest.VeloInsuffAcc         = 0;
  Dest.YawRateInsuffAcc      = 0;
  Dest.b_ACCPerformanceDist  = 0;
  Dest.e_PerfDegrExeedQuota  = 0;
  Dest.BelowMinPerfDist_AZ   = Src.BelowMinPerfDist_AZ;
  Dest.BelowMinPerfDist_VDY  = Src.BelowMinPerfDist_VDY;
  Dest.BelowMinPerfDist_EL   = Src.BelowMinPerfDist_EL;
  Dest.InterferenceRange     = Src.InterferenceRange;
  Dest.SRDDampingState       = Src.SRDDampingState;
  Dest.bObjSelectionActive   = Src.bObjSelectionActive;
  Dest.bCollisionAvoidActive = Src.bCollisionAvoidActive;
  Dest.bRequestRoadBeam      = Src.bRequestRoadBeam;
  Dest.tSafetyDistanceEBA    = Src.tSafetyDistanceEBA;
}

void CConvFctSenErrorOut::Convert_V14_to_Gen (FCTSenErrorOutGen::FCTSenErrorOut_t & Dest, const FCTSenErrorOutV14::FCTSenErrorOut_t & Src)
{
  Dest.sSigHeader            = Src.sSigHeader;
  Dest.ObjectNotMeasured     = Src.ObjectNotMeasured;
  Dest.ObjectNotMeasTmp      = Src.ObjectNotMeasTmp;
  Dest.Blockage              = Src.Blockage;
  Dest.IncreaseBlockage      = Src.IncreaseBlockage;
  Dest.DecreaseBlockage      = Src.DecreaseBlockage;
  Dest.uiNoOfObjLosses       = Src.uiNoOfObjLosses;
  Dest.VeloInsuffAcc         = 0;
  Dest.YawRateInsuffAcc      = 0;
  Dest.b_ACCPerformanceDist  = 0;
  Dest.e_PerfDegrExeedQuota  = 0;
  Dest.BelowMinPerfDist_AZ   = Src.BelowMinPerfDist_AZ;
  Dest.BelowMinPerfDist_VDY  = Src.BelowMinPerfDist_VDY;
  Dest.BelowMinPerfDist_EL   = Src.BelowMinPerfDist_EL;
  Dest.InterferenceRange     = Src.InterferenceRange;
  Dest.SRDDampingState       = Src.SRDDampingState;
  Dest.bObjSelectionActive   = Src.bObjSelectionActive;
  Dest.bCollisionAvoidActive = Src.bCollisionAvoidActive;
  Dest.bRequestRoadBeam      = Src.bRequestRoadBeam;
  Dest.tSafetyDistanceEBA    = Src.tSafetyDistanceEBA;
}


void CConvFctSenErrorOut::Convert_Gen_to_V6 (FCTSenErrorOutV6::FCTSenErrorOut_t & Dest, const FCTSenErrorOutGen::FCTSenErrorOut_t & Src)
{
  Dest.ObjectNotMeasTmp      = Src.ObjectNotMeasTmp;
  Dest.Blockage              = Src.Blockage;
  Dest.IncreaseBlockage      = Src.IncreaseBlockage;
  Dest.DecreaseBlockage      = Src.DecreaseBlockage;
  Dest.VeloInsuffAcc         = Src.VeloInsuffAcc;
  Dest.YawRateInsuffAcc      = Src.YawRateInsuffAcc;
  Dest.InterferenceRange     = Src.InterferenceRange;
  Dest.SRDDampingState       = Src.SRDDampingState;
  Dest.bObjSelectionActive   = Src.bObjSelectionActive;
  Dest.bCollisionAvoidActive = Src.bCollisionAvoidActive;
  Dest.bRequestRoadBeam      = Src.bRequestRoadBeam;
}

void CConvFctSenErrorOut::Convert_Gen_to_V7_2 (FCTSenErrorOutV7_2::FCTSenErrorOut_t & Dest, const FCTSenErrorOutGen::FCTSenErrorOut_t & Src)
{
  Dest.ObjectNotMeasured     = Src.ObjectNotMeasured;
  Dest.ObjectNotMeasTmp      = Src.ObjectNotMeasTmp;
  Dest.Blockage              = Src.Blockage;
  Dest.IncreaseBlockage      = Src.IncreaseBlockage;
  Dest.DecreaseBlockage      = Src.DecreaseBlockage;
  Dest.VeloInsuffAcc         = Src.VeloInsuffAcc;
  Dest.YawRateInsuffAcc      = Src.YawRateInsuffAcc;
  Dest.InterferenceRange     = Src.InterferenceRange;
  Dest.SRDDampingState       = Src.SRDDampingState;
  Dest.bObjSelectionActive   = Src.bObjSelectionActive;
  Dest.bCollisionAvoidActive = Src.bCollisionAvoidActive;
  Dest.bRequestRoadBeam      = Src.bRequestRoadBeam;
}

void CConvFctSenErrorOut::Convert_Gen_to_V7_1 (FCTSenErrorOutV7_1::FCTSenErrorOut_t & Dest, const FCTSenErrorOutGen::FCTSenErrorOut_t & Src)
{
  Dest.ObjectNotMeasured     = Src.ObjectNotMeasured;
  Dest.ObjectNotMeasTmp      = Src.ObjectNotMeasTmp;
  Dest.Blockage              = Src.Blockage;
  Dest.IncreaseBlockage      = Src.IncreaseBlockage;
  Dest.DecreaseBlockage      = Src.DecreaseBlockage;
  Dest.VeloInsuffAcc         = Src.VeloInsuffAcc;
  Dest.YawRateInsuffAcc      = Src.YawRateInsuffAcc;
  Dest.InterferenceRange     = Src.InterferenceRange;
  Dest.SRDDampingState       = Src.SRDDampingState;
  Dest.bObjSelectionActive   = Src.bObjSelectionActive;
  Dest.bCollisionAvoidActive = Src.bCollisionAvoidActive;
  Dest.bRequestRoadBeam      = Src.bRequestRoadBeam;
}

void CConvFctSenErrorOut::Convert_Gen_to_V11 (FCTSenErrorOutV11::FCTSenErrorOut_t & Dest, const FCTSenErrorOutGen::FCTSenErrorOut_t & Src)
{
  Dest.sSigHeader            = Src.sSigHeader;
  Dest.ObjectNotMeasured     = Src.ObjectNotMeasured;
  Dest.ObjectNotMeasTmp      = Src.ObjectNotMeasTmp;
  Dest.Blockage              = Src.Blockage;
  Dest.IncreaseBlockage      = Src.IncreaseBlockage;
  Dest.DecreaseBlockage      = Src.DecreaseBlockage;
  Dest.b_ACCPerformanceDist  = Src.b_ACCPerformanceDist;
  Dest.e_PerfDegrExeedQuota  = Src.e_PerfDegrExeedQuota;
  Dest.InterferenceRange     = Src.InterferenceRange;
  Dest.SRDDampingState       = Src.SRDDampingState;
  Dest.bObjSelectionActive   = Src.bObjSelectionActive;
  Dest.bCollisionAvoidActive = Src.bCollisionAvoidActive;
  Dest.bRequestRoadBeam      = Src.bRequestRoadBeam;
}

void CConvFctSenErrorOut::Convert_Gen_to_V12 (FCTSenErrorOutV12::FCTSenErrorOut_t & Dest, const FCTSenErrorOutGen::FCTSenErrorOut_t & Src)
{
  Dest.sSigHeader            = Src.sSigHeader;
  Dest.ObjectNotMeasured     = Src.ObjectNotMeasured;
  Dest.ObjectNotMeasTmp      = Src.ObjectNotMeasTmp;
  Dest.Blockage              = Src.Blockage;
  Dest.IncreaseBlockage      = Src.IncreaseBlockage;
  Dest.DecreaseBlockage      = Src.DecreaseBlockage;
  Dest.BelowMinPerfDist_AZ   = Src.BelowMinPerfDist_AZ;
  Dest.BelowMinPerfDist_VDY  = Src.BelowMinPerfDist_VDY;
  Dest.BelowMinPerfDist_EL   = Src.BelowMinPerfDist_EL;
  Dest.InterferenceRange     = Src.InterferenceRange;
  Dest.SRDDampingState       = Src.SRDDampingState;
  Dest.bObjSelectionActive   = Src.bObjSelectionActive;
  Dest.bCollisionAvoidActive = Src.bCollisionAvoidActive;
  Dest.bRequestRoadBeam      = Src.bRequestRoadBeam;
}

void CConvFctSenErrorOut::Convert_Gen_to_V13 (FCTSenErrorOutV13::FCTSenErrorOut_t & Dest, const FCTSenErrorOutGen::FCTSenErrorOut_t & Src)
{
  Dest.sSigHeader            = Src.sSigHeader;
  Dest.ObjectNotMeasured     = Src.ObjectNotMeasured;
  Dest.ObjectNotMeasTmp      = Src.ObjectNotMeasTmp;
  Dest.Blockage              = Src.Blockage;
  Dest.IncreaseBlockage      = Src.IncreaseBlockage;
  Dest.DecreaseBlockage      = Src.DecreaseBlockage;
  Dest.BelowMinPerfDist_AZ   = Src.BelowMinPerfDist_AZ;
  Dest.BelowMinPerfDist_VDY  = Src.BelowMinPerfDist_VDY;
  Dest.BelowMinPerfDist_EL   = Src.BelowMinPerfDist_EL;
  Dest.InterferenceRange     = Src.InterferenceRange;
  Dest.SRDDampingState       = Src.SRDDampingState;
  Dest.bObjSelectionActive   = Src.bObjSelectionActive;
  Dest.bCollisionAvoidActive = Src.bCollisionAvoidActive;
  Dest.bRequestRoadBeam      = Src.bRequestRoadBeam;
  Dest.tSafetyDistanceEBA    = Src.tSafetyDistanceEBA;
}

void CConvFctSenErrorOut::Convert_Gen_to_V14 (FCTSenErrorOutV14::FCTSenErrorOut_t & Dest, const FCTSenErrorOutGen::FCTSenErrorOut_t & Src)
{
  Dest.sSigHeader            = Src.sSigHeader;
  Dest.ObjectNotMeasured     = Src.ObjectNotMeasured;
  Dest.ObjectNotMeasTmp      = Src.ObjectNotMeasTmp;
  Dest.Blockage              = Src.Blockage;
  Dest.IncreaseBlockage      = Src.IncreaseBlockage;
  Dest.DecreaseBlockage      = Src.DecreaseBlockage;
  Dest.uiNoOfObjLosses       = Src.uiNoOfObjLosses;
  Dest.BelowMinPerfDist_AZ   = Src.BelowMinPerfDist_AZ;
  Dest.BelowMinPerfDist_VDY  = Src.BelowMinPerfDist_VDY;
  Dest.BelowMinPerfDist_EL   = Src.BelowMinPerfDist_EL;
  Dest.InterferenceRange     = Src.InterferenceRange;
  Dest.SRDDampingState       = Src.SRDDampingState;
  Dest.bObjSelectionActive   = Src.bObjSelectionActive;
  Dest.bCollisionAvoidActive = Src.bCollisionAvoidActive;
  Dest.bRequestRoadBeam      = Src.bRequestRoadBeam;
  Dest.tSafetyDistanceEBA    = Src.tSafetyDistanceEBA;
}


long CConvFctSenErrorOut::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  bool bGenBufferFilled = false;
  const uint32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<uint32*>(pPPortData)):(0);
  if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    // First decide from which version we are converting and fill the generic buffer accordingly
    if ((ulPPortSize == SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER14])
      && ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER14]) || pProvidePortVersionInfo->Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER15]))
      && ((uDataVer == 14u) || (uDataVer == 15u)))
    {
      // Source Port V14 and V15
      Init(m_BufGen, 14);
      const FCTSenErrorOutV14::FCTSenErrorOut_t & Src = *reinterpret_cast<FCTSenErrorOutV14::FCTSenErrorOut_t*>(pPPortData);
      Convert_V14_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER13])
      && ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER13]))
      && (uDataVer == 13u))
    {
      // Source Port V13
      Init(m_BufGen, 13);
      const FCTSenErrorOutV13::FCTSenErrorOut_t & Src = *reinterpret_cast<FCTSenErrorOutV13::FCTSenErrorOut_t*>(pPPortData);
      Convert_V13_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER12])
      && ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER12]))
      && (uDataVer == 12u))
    {
      // Source Port V12
      Init(m_BufGen, 12);
      const FCTSenErrorOutV12::FCTSenErrorOut_t & Src = *reinterpret_cast<FCTSenErrorOutV12::FCTSenErrorOut_t*>(pPPortData);
      Convert_V12_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER11])
      && ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER11]))
      && (uDataVer == 11u))
    {
      // Source Port V11
      Init(m_BufGen, 11);
      const FCTSenErrorOutV11::FCTSenErrorOut_t & Src = *reinterpret_cast<FCTSenErrorOutV11::FCTSenErrorOut_t*>(pPPortData);
      Convert_V11_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER9])
      && ((pProvidePortVersionInfo == NULL)
      || pProvidePortVersionInfo->Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER9]))
      && ((uDataVer == 9u)))
    {
      // Source Port V7_2 (With version 9)
      Init(m_BufGen, 7);
      const FCTSenErrorOutV7_2::FCTSenErrorOut_t & Src = *reinterpret_cast<FCTSenErrorOutV7_2::FCTSenErrorOut_t*>(pPPortData);
      Convert_V7_2_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER7_2])
      && ((pProvidePortVersionInfo == NULL)
      || pProvidePortVersionInfo->Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER7_2])
      || pProvidePortVersionInfo->Equals(&VERSION6))
      && ((uDataVer == 6u) || (uDataVer == 7u)))
    {
      // Source Port V7_2
      Init(m_BufGen, 7);
      const FCTSenErrorOutV7_2::FCTSenErrorOut_t & Src = *reinterpret_cast<FCTSenErrorOutV7_2::FCTSenErrorOut_t*>(pPPortData);
      Convert_V7_2_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER7_1])
      && ((pProvidePortVersionInfo == NULL)
      || pProvidePortVersionInfo->Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER7_1])
      || pProvidePortVersionInfo->Equals(&VERSION6))
      && ((uDataVer == 6u) || (uDataVer == 7u)))
    {
      // Source Port V7_1
      Init(m_BufGen, 7);
      const FCTSenErrorOutV7_1::FCTSenErrorOut_t & Src = *reinterpret_cast<FCTSenErrorOutV7_1::FCTSenErrorOut_t*>(pPPortData);
      Convert_V7_1_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER6])
      && ((pProvidePortVersionInfo == NULL)
      || pProvidePortVersionInfo->Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER6])
      || pProvidePortVersionInfo->Equals(&VERSION7))
      && ((uDataVer == 6u) || (uDataVer == 7u)))
    {
      // Source Port V6
      Init(m_BufGen, 6);
      const FCTSenErrorOutV6::FCTSenErrorOut_t & Src = *reinterpret_cast<FCTSenErrorOutV6::FCTSenErrorOut_t*>(pPPortData);
      Convert_V6_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    // At last check if one:one is possible. This is because there are versions with equal size and different members
    else if (ulRPortSize == ulPPortSize)
    {
      // If ports equal, then always compatible
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }

    if (bGenBufferFilled == true)
    {
      // Second decide to which version we are converting
      // and take the generic buffer to fill the destination buffer
      if ((ulRPortSize == SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER15])
        && (requestPortVersionInfo.Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER15])))
      {
        // Destination port of V14 (with version 15)
        Init(m_BufV14, 15);
        Convert_Gen_to_V14(m_BufV14, m_BufGen);
        *pOutData = &m_BufV14;
        ulOutSize = sizeof(m_BufV14);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER14])
        && (requestPortVersionInfo.Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER14])))
      {
        // Destination port of V14
        Init(m_BufV14, 14);
        Convert_Gen_to_V14(m_BufV14, m_BufGen);
        *pOutData = &m_BufV14;
        ulOutSize = sizeof(m_BufV14);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER13])
        && (requestPortVersionInfo.Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER13])))
      {
        // Destination port of V13
        Init(m_BufV13, 13);
        Convert_Gen_to_V13(m_BufV13, m_BufGen);
        *pOutData = &m_BufV13;
        ulOutSize = sizeof(m_BufV13);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER12])
        && (requestPortVersionInfo.Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER12])))
      {
        // Destination port of V12
        Init(m_BufV12, 12);
        Convert_Gen_to_V12(m_BufV12, m_BufGen);
        *pOutData = &m_BufV12;
        ulOutSize = sizeof(m_BufV12);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER11])
        && (requestPortVersionInfo.Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER11])))
      {
        // Destination port of V11
        Init(m_BufV11, 11);
        Convert_Gen_to_V11(m_BufV11, m_BufGen);
        *pOutData = &m_BufV11;
        ulOutSize = sizeof(m_BufV11);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER9])
        && (requestPortVersionInfo.Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER9])))
      {
        // Destination port of V7_2 (With version 9)
        Init(m_BufV7_2, 9);
        Convert_Gen_to_V7_2(m_BufV7_2, m_BufGen);
        *pOutData = &m_BufV7_2;
        ulOutSize = sizeof(m_BufV7_2);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER7_2])
        && (requestPortVersionInfo.Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER7_2])
        || requestPortVersionInfo.Equals(&VERSION6)))
      {
        // Destination port of V7_2
        Init(m_BufV7_2, 7);
        Convert_Gen_to_V7_2(m_BufV7_2, m_BufGen);
        *pOutData = &m_BufV7_2;
        ulOutSize = sizeof(m_BufV7_2);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER7_1])
        && (requestPortVersionInfo.Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER7_1])
        || requestPortVersionInfo.Equals(&VERSION6)))
      {
        // Destination port of V7_1
        Init(m_BufV7_1, 7);
        Convert_Gen_to_V7_1(m_BufV7_1, m_BufGen);
        *pOutData = &m_BufV7_1;
        ulOutSize = sizeof(m_BufV7_1);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER6])
        && (requestPortVersionInfo.Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER6])
        || requestPortVersionInfo.Equals(&VERSION7)))
      {
        // Destination port of V6
        Init(m_BufV6, 6);
        Convert_Gen_to_V6(m_BufV6, m_BufGen);
        *pOutData = &m_BufV6;
        ulOutSize = sizeof(m_BufV6);
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
long CConvFctSenErrorOut::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER14]) && requestPortVersionInfo.Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER14]))
    {
      Init(m_BufV14, 14u);
      *pDefaultData = &m_BufV14;
      ulDefaultSize = SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER14];
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER13]) && requestPortVersionInfo.Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER13]))
    {
      Init(m_BufV13, 13u);
      *pDefaultData = &m_BufV13;
      ulDefaultSize = SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER13];
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER12]) && requestPortVersionInfo.Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER12]))
    {
      Init(m_BufV12, 12u);
      *pDefaultData = &m_BufV12;
      ulDefaultSize = SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER12];
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER11]) && requestPortVersionInfo.Equals(FCT_SEN_ERROR_OUT_VERSIONS[FCT_SEN_ERROR_OUT_INTFVER11]))
    {
      Init(m_BufV11, 11u);
      *pDefaultData = &m_BufV11;
      ulDefaultSize = SUPPORTED_SIZE[FCT_SEN_ERROR_OUT_INTFVER11];
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(FCTSenErrorOutV7_2::FCTSenErrorOut_t)) && ((VERSION7.Equals(&requestPortVersionInfo)) || (VERSION6.Equals(&requestPortVersionInfo))))
    {
      Init(m_BufV7_2, 7u);
      *pDefaultData = &m_BufV7_2;
      ulDefaultSize = sizeof(FCTSenErrorOutV7_2::FCTSenErrorOut_t);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(FCTSenErrorOutV7_1::FCTSenErrorOut_t)) && ((VERSION7.Equals(&requestPortVersionInfo)) || (VERSION6.Equals(&requestPortVersionInfo))))
    {
      Init(m_BufV7_1, 7u);
      *pDefaultData = &m_BufV7_1;
      ulDefaultSize = sizeof(FCTSenErrorOutV7_1::FCTSenErrorOut_t);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(FCTSenErrorOutV6::FCTSenErrorOut_t)) && ((VERSION6.Equals(&requestPortVersionInfo)) || (VERSION7.Equals(&requestPortVersionInfo))))
    {
      Init(m_BufV6, 6u);
      *pDefaultData = &m_BufV6;
      ulDefaultSize = sizeof(FCTSenErrorOutV6::FCTSenErrorOut_t);
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
bool CConvFctSenErrorOut::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
  {
    bResult = true;
  }
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, NULL)))
    {
      bResult = true;
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvFctSenErrorOut::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
  {
    bResult = true;
  }
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, &providePortVersionInfo)))
    {
      bResult = true;
    }
  }
  return bResult;
}

//
// Main factory class returning conversion class
//
IConverter * CreateFctSenErrorOutConvInstance(void)
{
  return new CConvFctSenErrorOut();
}