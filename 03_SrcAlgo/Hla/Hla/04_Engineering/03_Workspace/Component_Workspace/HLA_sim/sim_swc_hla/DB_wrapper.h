#ifndef _DB_WRAPPER_h
#define _DB_WRAPPER_h



#include <atldbcli.h>




/* A DB wrapper class to provide easy read access to a database. It mkaes use of the OLE DB consumer templates. 
The template type parameter determines the buffer class which will hold the data retrieved from an individual 
row of the result rowset.

Example of a buffer class (the used macro is defined by the OLE DB consumer templates):

class Buffer {
public:
  UINT  nNumber;
  TCHAR sName[50];

  BEGIN_COLUMN_MAP(Buffer_MFC300_HLA_LDROI)
    COLUMN_ENTRY(1, nNumber)
    COLUMN_ENTRY(3, sName)
    END_COLUMN_MAP()
};

The data members of the buffer class are mapped to column entries of the datable table which is queried. The user must
know the table structure und column data types in order to do the mapping. The data members are updated each time the 
cursor is moved to row of the result rowset. Not all column entries have to be mapped to members of the buffer class
to limit the data transfer between the server and the client.

Example usage:

DB_Wrapper<Buffer> myDB,
myDB.openDBSession();
myDB.queryDB("SELECT * FROM SCHEMA_NAME.TABLE_NAME WHERE AGE<25"); */
template<class T>
class DB_Wrapper {

protected:

  CDataSource database;
  CSession session;
  CCommand<CAccessor<T>> Cmd;
  //unsigned int DB_is_Open;
  
  HRESULT hr_saved;

public:
  DB_Wrapper();
  ~DB_Wrapper();
  HRESULT openDBSession();
  void closeDBSession();
  HRESULT queryDB(char *sQuery);
  HRESULT nextRow();
  T* getCurrentData();
  unsigned int isOpen();


};


#endif

