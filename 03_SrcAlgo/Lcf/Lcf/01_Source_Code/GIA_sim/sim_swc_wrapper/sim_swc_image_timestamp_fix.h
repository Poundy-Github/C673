/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

*/
#ifndef sim_swc_image_timestamp_fix_h__
#define sim_swc_image_timestamp_fix_h__

#include "sim_swc_base.h"
#include "sim_versioninfo_impl.h"
#include "simReceivePort.h"

#include <map>

namespace MFC
{
  struct SImageInfoStruct
  {
    BYTE    m_bDarkStart1InfoLines;
    BYTE    m_bStart2InfoLines;
    BYTE    m_bEndInfoLines;
    UINT16  m_unHeight;
    UINT16  m_unWidth;
  };

  // pixel alignment of data coming from the MI-EMS
  // two 12bit pixels are packed into three bytes
  // Source data:
  // 1 24bit pixel A  A  A  A  A  A  A  A  B  B  B  B  B  B  B  B  C  C  C  C  C  C  C  C
  //              -----------------------------------------------------------------------
  // Dest. data    a  a  a  a  a  a  a  a  a  a  a  a  b  b  b  b  b  b  b  b  b  b  b  b
  //              07 06 05 04 03 02 01 00 11 10 09 08 03 02 01 00 11 10 09 08 07 06 05 04
  union PixelAlignment
  {
    BYTE bytes[3];
  };

  // - Registers
  // Line1: 152 regs (R0x3000 - R0x312F)
  // Line2:  93 regs (R0x3136 - R0x31BF, R0x31D0 - R0x31FF) 69 + 24
  static const USHORT sNoOfRegs = 245;
  struct SPairData
  {
    USHORT sAddress;
    USHORT sValue;
  };

  // - Statistics
  static const USHORT sNoOfHist = 244;
  static const USHORT sNoOfStats = sNoOfHist + 8;
  struct SLongPairData
  {
    USHORT sAddress;
    DWORD  sValue;
  };

  struct EmbeddedRegisters
  {
    SPairData regs[sNoOfRegs];
  };

  struct EmbeddedStatistics
  {
    SLongPairData stats[sNoOfStats];
  };

  struct MFCEmbeddedData
  {
    EmbeddedRegisters embeddedRegs;
    EmbeddedStatistics embeddedStats;
  };

  static const BYTE  m_bDefaultDarkInfoLines  = 16;
  static const BYTE  m_bImageUnitBytes        = 3;
  static const BYTE  m_bImageUnitPixels       = 2;
}

/// Class representing a SIM plugin to the SIM VFB MO in MTS
class CSimImageTimestampFix
{
public:
  /// Constructor of the class.
  /// Gets called when the plugin is loaded.
  CSimImageTimestampFix(CSimSwcBase* pBaseInstance);

  /// Destructor of the class.
  /// Gets called when the plugin is unloaded.
  ~CSimImageTimestampFix();


  void Reset();
  void Init();
  int Doit(bool bMFC400);

  static const unsigned long MAX_REPORTED_PORT_ERRORS = 100; ///< Maximum reported receive port errors

  /// @name provide port names
  /// @{
  static const char* PP_IMAGE_FRAMECOUNTER_LEFT;
  static const char* PP_IMAGE_FRAMECOUNTER_RIGHT;
  static const char* PP_IMAGE_TIMESTAMP_LEFT;
  static const char* PP_IMAGE_TIMESTAMP_RIGHT;
  static const char* PP_IMAGE_RAW_LEFT;
  static const char* PP_IMAGE_RAW_RIGHT;
  // TODO: place static const char* PP_<NAME> members
  /// @}

  /// @name provide ports
  /// @{
  // TODO: place static const char* PP_<NAME> members
  /// @}

  /// @name receive ports
  /// @{
  SimReceivePort<unsigned int,    simUI32_t>        m_rpTimestampToBeSet;
  SimReceivePort<unsigned short,  simUI16_t>        m_rpFramecounterToBeSet;
  SimReceivePort<unsigned int,    simUI32_t>        m_rpImageFramecounterLeft;
  SimReceivePort<unsigned int,    simUI32_t>        m_rpImageFramecounterRight;
  SimReceivePort<__int64,         simI64_t>         m_rpImageTimestampLeft;
  SimReceivePort<__int64,         simI64_t>         m_rpImageTimestampRight;
  SimReceivePort<BYTE*  ,         simREFERENCE_t>   m_rpImageRawLeft;
  SimReceivePort<BYTE*  ,         simREFERENCE_t>   m_rpImageRawRight;

  typedef std::map<unsigned short, unsigned short> REGISTER_MAP;
  REGISTER_MAP m_mapRegisterReplacements;

  /// Additional data to be memorized on a receive port
  struct SimReceivePortInfo
  {
    unsigned char errorCount;
    bool          checkForData;
  };

  /// Map type representing additional data per port
  typedef std::map<SimReceivePortBase*, SimReceivePortInfo> ReceivePortMap_t;

  /// Available receive ports with additional data
  ReceivePortMap_t m_receivePortMap;
  /// @}

  /// @name provide ports
  /// @{
  __int64 m_ppImageTimestampLeft;
  __int64 m_ppImageTimestampRight;
  void*   m_ppImageRawLeft;
  void*   m_ppImageRawRight;
  /// @}

  // base instance
  CSimSwcBase* m_pBaseInstance;

  unsigned int  m_uiNumMissedInput;
  bool          m_bCopiedDataInPPorts;

  int  ProcessData();
  bool IsRequiredDataAvailable();
  void SetupPorts();
  void ResetReceiveErrors();

  void ReplaceEmbeddedTimestamp(void* pData, unsigned int uiSize, unsigned __int64 uiTimestampToBeSet);
  int GetImageParameter(unsigned long providePortSize, MFC::SImageInfoStruct &imageInfo);
  INT32 ExtractEmbeddedData(void *SrcImage, void* pDestImage, UINT32 dwDestSize, unsigned long ulPPortSize, MFC::SImageInfoStruct &imageInfo);

  static CVersionInfoImpl CreateVersionInfoFromI32 (const long version);
};

#endif // sim_swc___template_h__
