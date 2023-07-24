#pragma once

#pragma warning( disable : 4481 )
#pragma warning( disable : 4100 )
#include "sim_converter_base.h"
#include <cassert>
#include <map>

class CAdapterConverterBase: public CSimConverterBase
{
private:
  long refCount;
  friend class CSimAdapter;

public:

  void IncrementRefCount()
  {
    refCount++;
  }
  virtual void Destroy()
  {
    refCount--;
    assert(refCount>=0);
    if(refCount==0)
    {
      delete this;
    }
  }

 virtual bool AreVersionsCompatible(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo) override
 {
   return true;
 }

  CAdapterConverterBase():CSimConverterBase(NULL, 0), refCount(1){};
  virtual ~CAdapterConverterBase(){};
};

typedef std::map<std::wstring, CAdapterConverterBase*(*)()> t_AdapterConverterConstructorMap;