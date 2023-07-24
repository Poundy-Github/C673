#pragma once

#include "sim_swc_base.h"

#include "sim_sound.h"
#include <string>
#include <limits>

#include "hla_debug.h"


class CSimHlaSound
{
public:
  CSimHlaSound(CSimSwcBase* pSimPlgBase);
  ~CSimHlaSound();

  void init(const std::string& dllPath);
  void generateSounds( /* simulation output from DLL */
                       RTE_HLAF_HighBeamState*               pRteHighBeamState,
                       /* MCU output from camera */
                       const RTE_HLAF_HeadlightControl_Common_t*   pHlaf_HeadlightControlCommon_MCU /* Measfreeze from MCU */
                      );

private:

  CSimSwcBase* m_pSimPlgBase;
  CSimSound m_simSound;
  std::string rootPath;

  class State
  {
  public:
    void reset()
    {
      totalCnt = 0;

      highway = false;
      city = false;
      samplingAbortedCnt = std::numeric_limits<uint32>::max();
      samplingAbortedLastTriggered = 0;
      frameLostCnt = std::numeric_limits<uint32>::max();
      frameLostLastTriggered = 0;
      dllHighBeamState = false;
    }

    uint32 totalCnt;

    bool highway;
    bool city;
    uint32 samplingAbortedCnt;
    uint32 samplingAbortedLastTriggered;
    uint32 frameLostCnt;
    uint32 frameLostLastTriggered;
    bool dllHighBeamState;
  } state;
};
