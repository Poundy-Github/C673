#include "stdafx.h"

#include "sim_sound.h"

#include <sstream>

CSimSwcBase* CSimSound::pSimPlgBase;
CRITICAL_SECTION CSimSound::criticalSection;
HANDLE CSimSound::playEvent;
HANDLE CSimSound::threadHandle;
bool CSimSound::exitRequest = false;
CSimSound::SoundMap CSimSound::mciData;
CSimSound::WavList CSimSound::wavList;

CSimSound::CSimSound( CSimSwcBase* _pSimPlgBase )
{
  pSimPlgBase = _pSimPlgBase;
  ::InitializeCriticalSection(&criticalSection);
  playEvent = ::CreateEvent(NULL, FALSE, FALSE, NULL);
  threadHandle = ::CreateThread(NULL, 0, CSimSound::playThread, 0, 0, 0);
}

CSimSound::~CSimSound()
{
  exitRequest = true;
  SetEvent(playEvent);

  WaitForSingleObject(threadHandle, INFINITE);

  for (SoundMap::iterator it = mciData.begin(); it != mciData.end(); ++it)
  {
    mciSendCommand(it->second.wDeviceID, MCI_CLOSE, MCI_WAIT, (DWORD_PTR)&(it->second));
  }
  ::CloseHandle(playEvent);
  ::DeleteCriticalSection(&criticalSection);
}

void CSimSound::play( const std::string& wavFile )
{
  ::EnterCriticalSection(&criticalSection);
  if (wavList.size() < 10)
  {
    wavList.push_back(wavFile);
    SetEvent(playEvent);
  }
  else
  {
    pSimPlgBase->ReportError(err_sev_warning, 0, "sound file queue is full");
  }
  ::LeaveCriticalSection(&criticalSection);
}

bool CSimSound::playFile(const std::string& wavFile)
{
  MCIERROR err;

  if (mciData.find(wavFile) == mciData.end())
  {
    // open mci audio
    MCI_WAVE_OPEN_PARMS mciWaveParams;
    mciWaveParams.lpstrDeviceType  = (LPCSTR)MCI_DEVTYPE_WAVEFORM_AUDIO;
    mciWaveParams.lpstrElementName = wavFile.c_str();
    err = ::mciSendCommand(0, MCI_OPEN, MCI_WAIT|MCI_OPEN_ELEMENT|MCI_OPEN_TYPE|MCI_OPEN_TYPE_ID, (DWORD_PTR)&mciWaveParams);
    if (err != 0)
    {
      printMCIError(err, wavFile, "MCI_OPEN");
      return false;
    }

    MCI_GENERIC_PARMS mciGenericParams;
    err = ::mciSendCommand(mciWaveParams.wDeviceID, MCI_CUE, 0, (DWORD_PTR)&mciGenericParams);
    if (err != 0)
    {
      printMCIError(err, wavFile, "MCI_CUE");
      return false;
    }

    // store mci device id
    mciData[wavFile] = mciWaveParams;
  }
  else
  {
    MCI_SEEK_PARMS seekParams;
    DWORD err = mciSendCommand(mciData[wavFile].wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD_PTR)&seekParams);
    if (err != 0)
    {
      printMCIError(err, wavFile, "MCI_SEEK");
      return false;
    }
  }

  MCI_PLAY_PARMS playParams;
  err = mciSendCommand(mciData[wavFile].wDeviceID, MCI_PLAY, MCI_WAIT, (DWORD_PTR)&playParams);
  if (err != 0)
  {
    printMCIError(err, wavFile, "MCI_PLAY");
    return false;
  }

  return true;
}

void CSimSound::printMCIError (const DWORD& err, const std::string& wavFile, const std::string& reason)
{
  char buffer[4096];
  mciGetErrorString (err, buffer, sizeof(buffer));

  std::stringstream errString;
  errString << "Error playing sound " << wavFile << " - " << reason << " : " << buffer;

  pSimPlgBase->ReportError(err_sev_warning, 0, errString.str().c_str());
}

DWORD WINAPI CSimSound::playThread( LPVOID lpParam ) 
{
  while (! exitRequest)
  {
    WaitForSingleObject(playEvent, INFINITE);

    while (! exitRequest)
    {
      std::string wavFile;
      size_t listSize;

      ::EnterCriticalSection(&criticalSection);
      listSize = wavList.size();
      if (listSize > 0)
      {
        wavFile = wavList.back();
        wavList.pop_back();
      }
      ::LeaveCriticalSection(&criticalSection);

      if (listSize > 0)
      {
        // new wav file in queue. Play it.
        playFile(wavFile);
      }

      if (listSize <= 1)
      {
        // no more files in queue. Finish processing the queue.
        break;
      }
    }
  }

  return 0;
}
