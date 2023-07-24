#include "DB_wrapper.h"
#include "param.h"


template<class T>
DB_Wrapper<T>::DB_Wrapper() {


}

template<class T>
DB_Wrapper<T>::~DB_Wrapper() {

  closeDBSession();

}

/* **************************************************************************** 
Functionname:    openDBSession                      */ /*!  
@brief           This function opens a database and creates a session for a user


@return          HRESULT

@author          Andreas Steiger
**************************************************************************** */
template<class T>
HRESULT DB_Wrapper<T>::openDBSession() {

  HRESULT hr;

  char sConnection[1024];

  GetParamString("Label_Database", "Connection", 1023, sConnection);

  /* convert the char-string to OLECHAR-string */
  OLECHAR *sOleText = new OLECHAR[strlen(sConnection)+1];  
  mbstowcs(sOleText, sConnection, strlen(sConnection)+1); // +1 means: don't forget the terminating null character

  /* open database using connection string */
  hr = database.OpenFromInitializationString(sOleText, true);

  /* free memory of the OLECHAR-string */
  delete sOleText;

  if(FAILED(hr))
    return hr;

  hr = session.Open(database);
  if(FAILED(hr)) {
    database.Close();
    return hr;
  }

  hr_saved = hr;

  return hr;

}


/* **************************************************************************** 
Functionname:    closeDBSession                      */ /*!  
@brief           Closes the Command and Session objects and the database


@author          Andreas Steiger
**************************************************************************** */
template<class T>
void DB_Wrapper<T>::closeDBSession() {

  Cmd.Close();
  Cmd.ReleaseCommand();
  session.Close();
  database.Close();

}

/* **************************************************************************** 
Functionname:    queryDB                      */ /*!  
@brief           This function gets an SQL statement as input and queries the database.
                 The Command object which is created provides access to rowset result of
                 the query.

@param[in]       The SQL statement

@return          HRESULT

@pre             A database is opened and a session has been created.

@author          Andreas Steiger
**************************************************************************** */
template<class T>
HRESULT DB_Wrapper<T>::queryDB(char *sQuery) {
  
  HRESULT hr;

  if(FAILED(hr_saved))
    return hr_saved;

  CDBPropSet propset(DBPROPSET_ROWSET);
  // This property is - among other things - necessary to determine the number of rows of a rowset
  propset.AddProperty(DBPROP_IRowsetScroll, true);

  // Close the previously opened Command object
  Cmd.Close();
  Cmd.ReleaseCommand();

  hr = Cmd.Open(session, sQuery, &propset, NULL, DBGUID_DEFAULT, true, 1);
  if(FAILED(hr))
    return hr;

  // Move the cursor to the first row of the rowset result
  return Cmd.MoveFirst();

}

/* **************************************************************************** 
Functionname:    nextRow                      */ /*!  
@brief           This function moves the cursor to the next row of the rowset result

@pre             A Command object with an open rowset exists

@author          Andreas Steiger
**************************************************************************** */
template<class T>
HRESULT DB_Wrapper<T>::nextRow() {

  if(FAILED(hr_saved))
    return hr_saved;
 
  return Cmd.MoveNext();

}

/* **************************************************************************** 
Functionname:    getCurrentData                      */ /*!  
@brief           This function returns a pointer to the current row data.

@pre             A Command object with an open rowset exists 

@return          Pointer to data

@author          Andreas Steiger
**************************************************************************** */
template<class T>
T* DB_Wrapper<T>::getCurrentData() {

  if(FAILED(hr_saved))
    return hr_saved;

  return (T*)Cmd.GetBuffer();

}
