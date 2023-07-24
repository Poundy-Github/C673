#pragma once

#include <map>
#include <vector>
#include <string>

#include "sim_swc_base.h"


class CSimSound
{
public:
  CSimSound(CSimSwcBase* pSimPlgBase);
  ~CSimSound();

  void play(const std::string& wavFile);

private:
  static void printMCIError (const DWORD& err, const std::string& wavFile, const std::string& reason);
  static bool playFile(const std::string& wavFile);

  static DWORD WINAPI playThread( LPVOID lpParam );

  static CSimSwcBase* pSimPlgBase;

  static CRITICAL_SECTION criticalSection;
  static HANDLE playEvent;
  static HANDLE threadHandle;
  static bool exitRequest;

  typedef std::map<std::string, MCI_WAVE_OPEN_PARMS> SoundMap;
  static SoundMap mciData;

  typedef std::vector<std::string> WavList;
  static WavList wavList;
};
