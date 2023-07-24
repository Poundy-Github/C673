
#include "extractor_ifc_wrapper.h"

extern "C" typedef IInterfaceAccess* (__cdecl *fpGetEngine_t)(void);


CExtractorIfcWrapper::CExtractorIfcWrapper()
  : m_pIEngineAccess(NULL)
  ,m_pIMFC5xxDataExtraction(NULL)
  , m_strError("")
{
  GetExtractorAccess();
}

CExtractorIfcWrapper::~CExtractorIfcWrapper()
{
}

void CExtractorIfcWrapper::GetExtractorAccess()
{
  // thing would be much easier if we go for including the 'mtsengine.h' but with that we would also have to link the according library and gain a load library dependency to the 'mtsengine.dll'
  // for now rather go with a runtime dependency and hence take some extra hurdles to get all the interfaces up and running

  HMODULE hModule = LoadLibrary(L"mtsengine.dll");
  if (!hModule)
  {
    m_strError = "Engine dll not loaded!!!";
    return;
  }

  fpGetEngine_t fpGetEngine = (fpGetEngine_t) GetProcAddress(hModule, "GetMTSEngine");
  if (!fpGetEngine)
  {
    m_strError = "Entry function of engine dll not found!!!";
    return;
  }

  m_pIEngineAccess = fpGetEngine();
  if (!m_pIEngineAccess)
  {
    m_strError = "Access interface of engine not received!!!";
    return;
  }

  IObjectAccess* pAccess = reinterpret_cast<IObjectAccess*>(m_pIEngineAccess->GetInterface(L"IObjectAccess"));
  if (!pAccess)
  {
    m_strError = "Engine did not provide the obj access interface!!!";
    return;
  }

  SFindObjectInfo sInfo = { FOI_MASK_CLASS, dataprocessor, L"MFC5xxDataExtractor", NULL, 0, 0 };
  IInterfaceAccess* pIIfcAccess = pAccess->GetObject( pAccess->FindObject( sInfo ) );
  if (!pIIfcAccess)
  {
    m_strError = "Extractor MO of class 'MFC5xxDataExtractor' not found!!!";
    return;
  }

  m_pIMFC5xxDataExtraction = reinterpret_cast<::MFC5XX::IMFC5xxDataExtraction*>(pIIfcAccess->GetInterface(L"MFC5XX::IMFC5xxDataExtraction"));
  if (!m_pIMFC5xxDataExtraction)
  {
    m_strError = "Extraction interface not received from extractor MO!!!";
    return;
  }

}

