#include "stdafx.h"

#include "sim_hla_sound.h"

#include "param.h"


CSimHlaSound::CSimHlaSound( CSimSwcBase* pSimPlgBase )
: m_pSimPlgBase(pSimPlgBase),
  m_simSound(pSimPlgBase)
{
}

CSimHlaSound::~CSimHlaSound()
{
}

void CSimHlaSound::init( const std::string& dllPath )
{
  // reset state
  state.reset();

  // store root path
  const size_t posSlash = dllPath.find_last_of('/');
  const size_t posBackSlash = dllPath.find_last_of('\\');
  size_t pos;

  if (posSlash == std::string::npos)
  {
    pos = posBackSlash;
  }
  else if (posBackSlash == std::string::npos)
  {
    pos = posSlash;
  }
  else
  {
    pos = (posBackSlash > posSlash) ? posBackSlash : posSlash;
  }

  if (dllPath.find('.', pos+1))
  {
    rootPath = dllPath.substr(0, pos+1);
  }
}

void CSimHlaSound::generateSounds(/* simulation output from DLL */
                                  RTE_HLAF_HighBeamState*               pRteHighBeamState,
                                  /* MCU output from camera */
                                  const RTE_HLAF_HeadlightControl_Common_t*   pHlaf_HeadlightControlCommon_MCU /* Measfreeze from MCU */
                                  )
{
  char filename[256];

  state.totalCnt++;

  if (pHlaf_HeadlightControlCommon_MCU)
  {
    /* highway */
    if (GetParamInt("sound", "playHighway", 0))
    {
      if(pHlaf_HeadlightControlCommon_MCU->MotorwayState == RTE_HLAF_MTWY_MOTORWAY)
      {
        if (! state.highway)
        {
          state.highway = true;
          GetParamString("sound", "fileHighwayOn", sizeof(filename), filename);
          m_simSound.play(rootPath + filename);
        }
      }
      else
      {
        if (state.highway)
        {
          state.highway = false;
          GetParamString("sound", "fileHighwayOff", sizeof(filename), filename);
          m_simSound.play(rootPath + filename);
        }
      }
    }

    /* city */
    if (GetParamInt("sound", "playCity", 0))
    {
      if(pHlaf_HeadlightControlCommon_MCU->CityState == RTE_HLAR_CITY_DTCD)
      {
        if (! state.city)
        {
          state.city = true;
          GetParamString("sound", "fileCityOn", sizeof(filename), filename);
          m_simSound.play(rootPath + filename);
        }
      }
      else
      {
        if (state.city)
        {
          state.city = false;
          GetParamString("sound", "fileCityOff", sizeof(filename), filename);
          m_simSound.play(rootPath + filename);
        }
      }
    }
  }

  if (pRteHighBeamState)
  {
    /* DLL high beam state */
    if (GetParamInt("sound", "playDllHighBeamState", 0))
    {
      if (*pRteHighBeamState == RTE_HLAF_HB_STATE_FULL_ON)
      {
        if (! state.dllHighBeamState)
        {
          state.dllHighBeamState = true;
          GetParamString("sound", "fileDllHighBeamStateOn", sizeof(filename), filename);
          m_simSound.play(rootPath + filename);
        }
      }
      else
      {
        if (state.dllHighBeamState)
        {
          state.dllHighBeamState = false;
          GetParamString("sound", "fileDllHighBeamStateOff", sizeof(filename), filename);
          m_simSound.play(rootPath + filename);
        }
      }
    }
  }
}
