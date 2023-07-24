#include <string.h>
#include "sim_hla_labelDB.h"
#include "sim_img_type.h"

template<class T>
LabelDB<T>::LabelDB() {

}

template<class T>
SLabelDate_t LabelDB<T>::getLabelDate(const char *strTAN) {

  SLabelDate_t sLabelDate;
  char strBuffer[50];
  memset(strBuffer,'\0',50);

  memcpy(strBuffer, strTAN, 4);  
  sLabelDate.uiYear = atoi(strBuffer);
  
  memset(strBuffer,'\0',50);
  memcpy(strBuffer, strTAN+4, 2);
  sLabelDate.uiMonth = atoi(strBuffer);

  memset(strBuffer,'\0',50);
  memcpy(strBuffer, strTAN+6, 2);
  sLabelDate.uiDay = atoi(strBuffer);


  memset(strBuffer,'\0',50);
  memcpy(strBuffer, strTAN+8, 2);
  sLabelDate.uiHour = atoi(strBuffer);


  memset(strBuffer,'\0',50);
  memcpy(strBuffer, strTAN+10, 2);
  sLabelDate.uiMin = atoi(strBuffer);


  memset(strBuffer,'\0',50);
  memcpy(strBuffer, strTAN+12, 2);
  sLabelDate.uiSec = atoi(strBuffer);

  return sLabelDate;

}



/* **************************************************************************** 
Functionname:    createRowset                      */ /*!  
@brief           This function creates a rowset which contains all rows of a specified table
                 belonging to a certain RecFile that satisfy a certain condition.

@pre             A database is opened and a session has been created.

@param[in]       Path to the RecFile
@param[in]       Name of the table
@param[in]       SQL condition
@return          HRESULT

@author          Andreas Steiger, Stefan Zechner
**************************************************************************** */
template<class T>
HRESULT LabelDB<T>::createRowset(const char* sRecFileName, const char* selectString, const char* sCondition)
{
  HRESULT hr;
  char sSchema[64];
  char sTable[64];
  LabelDB_Key key;
  T Data;
  char sRecIdFileName[1024];


  // Read the name of the DB schema and table to be used
  GetParamString("Label_Database", "Schema", 64, sSchema);
  GetParamString("Label_Database", "Table", 64, sTable);

  char sQuery[4096] = "SELECT ";
  strcat(sQuery, selectString);
  strcat(sQuery, " FROM ");

  //Get the name of the current RecFile
  sRecFileName = strrchr(const_cast<char*>(sRecFileName), 92);
  sRecFileName++;
  strcpy(sRecIdFileName, sRecFileName);

  /* remove the substring "_extract" */
  char* p = strstr(sRecIdFileName, "_extract");
  if (p != NULL)
  {
    strncpy(p, p+8, strlen(p-8));
  }


  //Construct an SQL statement using the passed information
  strcat(sQuery, sSchema);
  strcat(sQuery, ".");
  strcat(sQuery, sTable);
  strcat(sQuery, " WHERE \"RecIdFileName\" = '");
  strcat(sQuery, sRecIdFileName);
  strcat(sQuery, "'");
  if(sCondition) {
    strcat(sQuery, " AND ");
    strcat(sQuery, sCondition);
  }
  strcat(sQuery, " ORDER BY \"FrameMtLDROITimeStamp\"");

  hr = queryDB(sQuery);
  if(FAILED(hr))
    return hr;

  // Copy all rowset data to the local multimap
  while (hr == S_OK)
  {
    memcpy(&Data, Cmd.GetBuffer(), sizeof(T));

    // Create a key using: Timestamp, Cycle ID and Cycle Counter
    key = getKey(Cmd.FrameMtLDROITimeStamp, Cmd.LDROI_DATATYPE);
    datamap.insert(pair<LabelDB_Key, T>(key, Data));

    hr = Cmd.MoveNext();
  }

  hr = Cmd.MoveFirst();

  
  return hr;

}

/* **************************************************************************** 
Functionname:    getNumberOfEntries                     */ /*!  
@brief           This function returns the number of multimap entries with a certain key 

@param[in]       The key

@return          Number of entries

@author          Andreas Steiger
**************************************************************************** */
template<class T>
unsigned int LabelDB<T>::getNumberOfEntries(LabelDB_Key key) {

  return (unsigned int)datamap.count(key);

}

/* **************************************************************************** 
Functionname:    getNumberOfEntries                      */ /*!  
@brief           This function returns the number of multimap entries belonging to a certain
                 timestamp and image type.


@param[in]       The current timestamp
@param[in]       Image type

@return          Number of entries

@author          Andreas Steiger
**************************************************************************** */
template<class T>
unsigned int LabelDB<T>::getNumberOfEntries(unsigned __int64 timestamp, unsigned int imgType) {
  
  LabelDB_Key key;

  key.timestamp = timestamp;
  key.imgType = imgType & (simImg_MFC3Left_t | simImg_MFC3Right_t | simImg_MFC3ShortLeft | simImg_MFC3ShortRight | simImg_KAFAS_FLA_t);
  if(key.imgType == 0)
    return 0;

  return (unsigned int) datamap.count(key);

}


/* **************************************************************************** 
Functionname:    getKey                     */ /*!  
@brief           This function creates a key for a row of the result rowset

@param[in]       Timestamp
@param[in]       LDROI_DATATYPE

@return          The key

@author          Andreas Steiger, Stefan Zechner
**************************************************************************** */
template<class T>
LabelDB_Key LabelDB<T>::getKey(unsigned __int64 timestamp, const TCHAR* ldroi_datatype)
{
  
  LabelDB_Key key = {0, simImg_None_t};

  key.timestamp = timestamp;

  /* according to Sascha Sautner and Jochen Bader this is the coding for the LDROI_DATATYPE column in our HLA label

      Long Left       : AAH///////8=
      Long Right      : AAL///////8=
      Short Left      : AAX///////8=
      Short Right     : AAb///////8=
                  ?   : AAP///////8=
  */

  switch (ldroi_datatype[2])
  {
  case 'H':
    key.imgType = simImg_MFC3Left_t;
    break;

  case 'L':
    key.imgType = simImg_MFC3Right_t;
    break;

  case 'X':
    key.imgType = simImg_MFC3ShortLeft;
    break;

  case 'b':
    key.imgType = simImg_MFC3ShortRight;
    break;

  case 'P':
    key.imgType = simImg_KAFAS_FLA_t;
    break;
  }

  return key;
}


/* **************************************************************************** 
Functionname:    moveFirst                      */ /*!  
@brief           This function sets iterators to the first and last entries of the map with a certain key

@param[in]       Key

@return          1 on success

@author          Andreas Steiger
**************************************************************************** */
template<class T>
unsigned int LabelDB<T>::moveFirst(LabelDB_Key key) {

  if(datamap.empty())
    return 0;
  
  it_first = datamap.lower_bound(key);
  if(it_first == datamap.end())
    return 0;

  it_last = datamap.upper_bound(key);
  it_cursor = it_first;

  return 1;

}

/* **************************************************************************** 
Functionname:    moveFirst                      */ /*!  
@brief           This function sets iterators to the first and last entries of the map with a certain key

@param[in]       Timestamp
@param[in]       Image Type

@return          1 on success

@author          Andreas Steiger
**************************************************************************** */
template<class T>
unsigned int LabelDB<T>::moveFirst(unsigned __int64 timestamp, unsigned int imgType) {

  LabelDB_Key key;

  key.timestamp = timestamp;
  // We are only interested in certain flags of the image tyoe value
  key.imgType = imgType & (simImg_MFC3Left_t | simImg_MFC3Right_t | simImg_MFC3ShortLeft | simImg_MFC3ShortRight | simImg_KAFAS_FLA_t);
  if(key.imgType == 0)
    return 0;

  return moveFirst(key);

}


/* **************************************************************************** 
Functionname:    moveNext                      */ /*!  
@brief           This function moves the cursor iterator to the next multimap entry with the same key

@pre             A database is opened and a session has been created.

@return          1 on success

@author          Andreas Steiger
**************************************************************************** */
template<class T>
unsigned int LabelDB<T>::moveNext() {

  if(datamap.empty())
    return 0;

  it_cursor++;
  if(it_cursor == it_last)
    return 0;
  else
    return 1;

}

/* **************************************************************************** 
Functionname:    getData                      */ /*!  
@brief           This function returns a pointer to the data of the current cursor iterator position

@return          Pointer to data on success. Otherwise NULL

@author          Andreas Steiger
**************************************************************************** */
template<class T>
T* LabelDB<T>::getData() {

  if(datamap.empty())
    return NULL;

  if(it_cursor != datamap.end())  
    return &(it_cursor->second);
  else
    return NULL;

}
  

  


template<class T>
LabelDB_LDSS<T>::LabelDB_LDSS() {

}

template<class T>
SLabelDate_t LabelDB_LDSS<T>::getLabelDate(const char *strTAN) {

  SLabelDate_t sLabelDate;
  char strBuffer[50];
  memset(strBuffer,'\0',50);

  memcpy(strBuffer, strTAN, 4);  
  sLabelDate.uiYear = atoi(strBuffer);
  
  memset(strBuffer,'\0',50);
  memcpy(strBuffer, strTAN+4, 2);
  sLabelDate.uiMonth = atoi(strBuffer);

  memset(strBuffer,'\0',50);
  memcpy(strBuffer, strTAN+6, 2);
  sLabelDate.uiDay = atoi(strBuffer);


  memset(strBuffer,'\0',50);
  memcpy(strBuffer, strTAN+8, 2);
  sLabelDate.uiHour = atoi(strBuffer);


  memset(strBuffer,'\0',50);
  memcpy(strBuffer, strTAN+10, 2);
  sLabelDate.uiMin = atoi(strBuffer);


  memset(strBuffer,'\0',50);
  memcpy(strBuffer, strTAN+12, 2);
  sLabelDate.uiSec = atoi(strBuffer);

  return sLabelDate;

}



/* **************************************************************************** 
Functionname:    createRowset                      */ /*!  
@brief           This function creates a rowset which contains all rows of a specified table
                 belonging to a certain RecFile that satisfy a certain condition.

@pre             A database is opened and a session has been created.

@param[in]       Path to the RecFile
@param[in]       Name of the table
@param[in]       SQL condition
@return          HRESULT

@author          Andreas Steiger, Boris Lugez, Stefan Zechner
**************************************************************************** */
template<class T>
HRESULT LabelDB_LDSS<T>::createRowset(const char* sRecFileName, const char* selectString, const char* sCondition)
{
  HRESULT hr;
  char sSchema[64];
  char sTable[64];
  LabelDB_LDSS_Key key;
  T Data;
  memset(&Data,0,sizeof(Data));
  NbOfRecFile ++;  
  char sRecIdFileName[1024];


  // Read the name of the DB schema and table to be used
  GetParamString("Label_Database_LDSS", "Schema", 64, sSchema);
  GetParamString("Label_Database_LDSS", "Table", 64, sTable);

  char sQuery[4096] = "SELECT ";
  strcat(sQuery, selectString);
  strcat(sQuery, " FROM ");

  //Get the name of the current RecFile
  sRecFileName = strrchr(const_cast<char*>(sRecFileName), 92);
  sRecFileName++;
  strcpy(sRecIdFileName, sRecFileName);

  /* remove the substring "_extract" */
  char* p = strstr(sRecIdFileName, "_extract");
  if (p != NULL)
  {
    strncpy(p, p+8, strlen(p-8));
  }


  //Construct an SQL statement using the passed information
  strcat(sQuery, sSchema);
  strcat(sQuery, ".");
  strcat(sQuery, sTable);
  strcat(sQuery, " WHERE \"RecIdFileName\" = '");
  strcat(sQuery, sRecIdFileName);
  strcat(sQuery, "'");
  if(sCondition) {
    strcat(sQuery, " AND ");
    strcat(sQuery, sCondition);
  }
  strcat(sQuery, " ORDER BY \"FrameMtLDSSTimeStampStart\"");

  hr = queryDB(sQuery);
  if(FAILED(hr))
    return hr;

  /* The key is the number of the current row */
  key.nRecFile = NbOfRecFile;

  // Copy all rowset data to the local multimap
  while (hr == S_OK)
  {
    memcpy(&Data, Cmd.GetBuffer(), sizeof(T));

    // Create a key using: Timestamp, Cycle ID and Cycle Counter
    datamap.insert(pair<LabelDB_LDSS_Key, T>(key, Data));

    hr = Cmd.MoveNext();
  } 

  hr = Cmd.MoveFirst();
  
  return hr;

}

/* **************************************************************************** 
Functionname:    moveFirst                      */ /*!  
@brief           This function sets iterators to the first and last entries of the map with a certain key

@param[in]       Timestamp
@param[in]       Image Type

@return          1 on success

@author          Andreas Steiger, Boris Lugez
**************************************************************************** */
template<class T>
unsigned int LabelDB_LDSS<T>::moveFirst() {
  LabelDB_LDSS_Key key;
  key.nRecFile = NbOfRecFile;

  if(datamap.empty())
    return 0;
  
  it_first = datamap.lower_bound(key);
  if(it_first == datamap.end())
    return 0;

  it_last = datamap.end();
  it_cursor = it_first;

  return 1;

}
/* **************************************************************************** 
Functionname:    moveNext                      */ /*!  
@brief           This function moves the cursor iterator to the next multimap entry with the same key

@pre             A database is opened and a session has been created.

@return          1 on success

@author          Andreas Steiger, Boris Lugez
**************************************************************************** */
template<class T>
unsigned int LabelDB_LDSS<T>::moveNext() {

  if(datamap.empty())
    return 0;

  it_cursor++;
  if(it_cursor == it_last)
    return 0;
  else
    return 1;
}

/* **************************************************************************** 
Functionname:    getData                      */ /*!  
@brief           This function returns a pointer to the data of the current cursor iterator position

@return          Pointer to data on success. Otherwise NULL

@author          Andreas Steiger, Boris Lugez
**************************************************************************** */
template<class T>
T* LabelDB_LDSS<T>::getData() {

  if(datamap.empty())
    return NULL;

  if(it_cursor != datamap.end())  
    return &(it_cursor->second);
  else
    return NULL;
}

/* **************************************************************************** 
Functionname:    getNumberOfEntries                     */ /*!  
@brief           This function returns the number of multimap entries with a certain key 

@param[in]       The key

@return          Number of entries

@author          Andreas Steiger, Boris Lugez
**************************************************************************** */
template<class T>
unsigned int LabelDB_LDSS<T>::getNumberOfEntries() {
  LabelDB_LDSS_Key key;
  key.nRecFile = NbOfRecFile;

  return (unsigned int)datamap.count(key);

}
