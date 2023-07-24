#ifndef _labelDB_h
#define _labelDB_h


#include "stdafx.h"

#include <map>
#include <stdio.h>
#include <stdlib.h>

#include "sim_swc_hla.h"
#include "DB_wrapper.h"

using namespace std;


// Key used to identify entries with a certain timestamp belonging to a certain type
typedef struct {

  unsigned __int64 timestamp;
  unsigned int imgType;

} LabelDB_Key;


struct SLabelDate_t {

  unsigned int uiYear;
  unsigned int uiMonth;
  unsigned int uiDay;
  unsigned int uiHour;
  unsigned int uiMin;
  unsigned int uiSec;

  bool operator >(SLabelDate_t op2) {

    if(this->uiYear > op2.uiYear) {
      return true;
    }
    else if(this->uiYear == op2.uiYear) {
      if(this->uiMonth > op2.uiMonth) {
        return true;
      }
      else if(this->uiMonth == op2.uiMonth) {
        if(this->uiDay > op2.uiDay) {
          return true;
        }
        else if(this->uiDay == op2.uiDay) {
          if(this->uiHour > op2.uiHour) {
            return true;
          }
          else if(this->uiHour == op2.uiHour) {
            if(this->uiMin > op2.uiMin) {
              return true;
            }
            else if(this->uiMin == op2.uiMin) {
              if(this->uiSec > op2.uiSec) {
                return true;
              }
              else {
                return false;
              }
            }
            else {
              return false;
            }
          }
          else {
            return false;
          }
        }
        else {
          return false;
        }
      }
      else {
        return false;
      }
    }
    else {
      return false;
    }


  }
  

};


// Comparison class for LabelDB_Key
struct LabelDB_Key_Comp {

  bool operator() (const LabelDB_Key &key_a, const LabelDB_Key &key_b) const {
    if(key_a.timestamp < key_b.timestamp)
      return true;
    else if (key_a.timestamp == key_b.timestamp) {
      if(key_a.imgType < key_b.imgType)
        return true;
      else
        return false;
    }
    else
      return false;    
  }

};

/* The LabelDB class is derived from the DB wrapper template class and provides database access methods tailored to
the data to be retrieved from the Label DB. It uses a multimap to access data with a key that contains a timestamp
and the image type (left/right MFC image, short/long illumination)

Example:

 Buffer *buffer
 LabelDB<Buffer> myDB;
 myDB.openDBSession();
 myDB.createRowset(GetRecFileName());

 unsigned int nNumberOfEntries = getNumberOfEntries((unsigned long)GetInterestTimestamp(), getImageType());

 myDB.moveFirst((unsigned long)GetInterestTimestamp(), getImageType());
 for(unsigned int i=0; i<nNumberOfEntries; i++) {
   buffer = myDB.getData();
   // Do something with data ...
   myDB.moveNext();
 }

 !!!!!!!!

 Please note, that in the current version of this library the first three entries in the buffer class must be:
 timestamp, cycle id and cycle counter
 
 Otherwise the internal data handling will not work properly!

 class Buffer_MFC300_HLA_LDROI {
public:
  UINT  FrameMtLDROITimeStamp;
  UINT  LDROI_CYCLE_ID;
  UINT  LDROI_CYCLE_COUNTER;
  // additional member variables ...

  BEGIN_COLUMN_MAP(Buffer_MFC300_HLA_LDROI)
    COLUMN_ENTRY(3, FrameMtLDROITimeStamp)     // timestamp is in the 3rd column of the table
    COLUMN_ENTRY(4, LDROI_CYCLE_ID)            // cycle id is in the 4th column of the table
    COLUMN_ENTRY(5, LDROI_CYCLE_COUNTER)       // cycle counter is in the 5th column of the table
    // binding of additional member variables ...
    END_COLUMN_MAP()
};

 !!!!!!!


  
*/
template<class T>
class LabelDB : public DB_Wrapper<T> {

protected:
  multimap<LabelDB_Key, T, LabelDB_Key_Comp> datamap;
  unsigned int DB_is_open;
  typename multimap<LabelDB_Key, T, LabelDB_Key_Comp>::iterator it_first, it_last, it_cursor;
  LabelDB_Key getKey(unsigned __int64 timestamp, const TCHAR* ldroi_datatype);

public:
  LabelDB();
  HRESULT createRowset(const char* sRecFileName, const char* selectString, const char* sCondition = NULL);
  unsigned int getNumberOfEntries(unsigned __int64 timestamp, unsigned int imgType);
  unsigned int getNumberOfEntries(LabelDB_Key key);
  unsigned int moveFirst(unsigned __int64 timestamp, unsigned int imgType);
  unsigned int moveFirst(LabelDB_Key key);
  unsigned int moveNext();
  T* getData();
  SLabelDate_t getLabelDate(const char *strTAN);

};


// Key used to identify entries with the row number
typedef struct {
  unsigned int nRecFile;
} LabelDB_LDSS_Key;

// Comparison class for LabelDB_LDSS_Key_Comp
struct LabelDB_LDSS_Key_Comp {

  bool operator() (const LabelDB_LDSS_Key &key_a, const LabelDB_LDSS_Key &key_b) const {
    if(key_a.nRecFile < key_b.nRecFile)
    {
      return true;
    }
    else
    {
      return false;    
    }
  }
};

template<class T>
class LabelDB_LDSS : public DB_Wrapper<T> {

protected:
  multimap<LabelDB_LDSS_Key, T, LabelDB_LDSS_Key_Comp> datamap;
  unsigned int DB_is_open;
  typename multimap<LabelDB_LDSS_Key, T, LabelDB_LDSS_Key_Comp>::iterator it_first, it_last, it_cursor;

public:
  LabelDB_LDSS();
  T Data;
  HRESULT createRowset(const char* sRecFileName, const char* selectString, const char* sCondition = NULL);
  unsigned int getNumberOfEntries();
  unsigned int moveFirst();
  unsigned int moveNext();
  T* getData();
  SLabelDate_t getLabelDate(const char *strTAN);
  unsigned int NbOfRecFile;
};

#endif

