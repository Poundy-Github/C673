

#include "mtsinterface.h"
#include "mfc5xx_dataextraction_ifc.h"
#include <string>


class CExtractorIfcWrapper
{
public:
  CExtractorIfcWrapper();
  ~CExtractorIfcWrapper();

  ::MFC5XX::IMFC5xxDataExtraction*  GetExtractorInterfaceMfc5xx() { return m_pIMFC5xxDataExtraction; }
  std::string                       GetError()                    { return m_strError; }

private:
  void GetExtractorAccess();

  IInterfaceAccess*                 m_pIEngineAccess;
  ::MFC5XX::IMFC5xxDataExtraction*  m_pIMFC5xxDataExtraction;
  std::string                       m_strError;
};
