
/*! \file **********************************************************************

  COMPANY:                Continental Temic, PL FAS, A.D.C. GmbH

  PROJECT:                none

  CPU:                    Pentium

  COMPONENT:             Log file support

  MODULNAME:             log.c

  @brief

  @author                 Timo Seifert

  CREATION DATE:          09.03.2006

  VERSION:                Revision:

  CHANGES:                
  ---*/ /*---
  CHANGE:                 Log: log.c
  CHANGE:                 Revision 1.10  2007/04/02 12:01:38  heinrichs1
  CHANGE:                 - modifications from "Testwoche Wasserburg 070326 - 070330" (heinrich)
  CHANGE:
  CHANGE:                 Revision 1.9  2007/01/08 14:05:33  heinrichs1
  CHANGE:                 static char Line[32768]
  CHANGE:                 static char DataString[32768]
  CHANGE:                 static char HeadString[32768]        (heinrich)
  CHANGE:
  CHANGE:                 Revision 1.8  2006/12/21 16:26:39  muellerr5
  CHANGE:                 - bugfix: doubled size of string arrays Line[], DataString[] and HeadString[] according to doubled size of maxDataLen
  CHANGE:                 (Reik Müller)
  CHANGE:
  CHANGE:                 Revision 1.7  2006/12/20 17:01:52  muellerr5
  CHANGE:                 - changed maxDataLen to 256
  CHANGE:                 (Reik Müller)
  CHANGE:
  CHANGE:                 Revision 1.6  2006/12/18 16:28:44  muellerr5
  CHANGE:                 - added functions FinishCurrentLine(...) and SetColumnSeparator(...)
  CHANGE:                 (Reik Müller, Stefan Heinrich)
  CHANGE:
  CHANGE:                 Revision 1.5  2006/05/03 18:50:58  muellerr5
  CHANGE:                 - add "CloseLogFile()"    (R.Müller/S.Heinrich)
  CHANGE:
  CHANGE:                 Revision 1.4  2006/05/03 13:08:42  almeidac
  CHANGE:                 - Added tag "NEW_FILE_NO_OVERWRITE" (almeidac)
  CHANGE:
  CHANGE:                 Revision 1.3  2006/03/21 09:01:03  heinrichs1
  CHANGE:                 - added "WriteLogfileEntry(..)" functionality  (heinrich)
  CHANGE:
  CHANGE:                 Revision 1.2  2006/03/13 16:51:30  seifertt
  CHANGE:                 log.h now in \log [T.Seifert]
  CHANGE:
  CHANGE:                 Revision 1.1  2006/03/13 13:47:33  seifertt
  CHANGE:                 - logfile support added [T.Seifert]
  CHANGE:
  CHANGE:                 Revision 1.1  2006/03/10 13:09:00  seifertt
  CHANGE:                 - files to support generation of result reports [T.Seifert]
  CHANGE:
**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include <string.h>
#include <stdarg.h>
#include "log.h"

#pragma warning (disable: 4996)

/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  VARIABLES 
*****************************************************************************/
const int maxDataLen = 256;
static char FileName[1024];
FILE *pFile=NULL;
static char Line[32768];
static char DataString[32768];
static char HeadString[32768];
static char separator = ';';

/*****************************************************************************
  FUNCTION 
*****************************************************************************/

void InitLogGlobals(void)
{
  if (pFile != NULL)
  {
    fclose(pFile);
  }
  memset(&FileName, 0, sizeof(FileName));
  pFile=NULL;
  memset(&Line, 0, sizeof(Line));
  memset(&DataString, 0, sizeof(DataString));
  memset(&HeadString, 0, sizeof(HeadString));
  separator = ';';
}

/* **************************************************************************** 
  Functionname:     CreateLogFile                      */ /*!  
  Description:      


  @param[in,out]    char* path : directory for the file
  @param[in,out]    char* name : file name
  @param[in,out]    eLogFileAccess Access : append or new create mode

  @return           FILE *pFile : file pointer or NULL
  @pre              -
  @post             -
  @author           Timo Seifert
**************************************************************************** */
FILE *CreateLogFile  (char* path, char* name,eLogFileAccess Access, int *pRes)
{

/*--- (SYMBOLIC) CONSTANTS ---*/

/*--- VARIABLES ---*/
 int nRet = LOGFILE_CREATED;
 char Mode[3]={0,0,0};

 // set file name, check for valid path
 sprintf(FileName,"%s/%s",path,name);
 if (strlen(path)<1)  sprintf(FileName,"%s",name); 

 if(Access == APPEND_FILE)
 {
   Mode[0] = 'a';

   pFile = fopen(FileName,"r");
   if(pFile != NULL)
   {
     nRet = LOGFILE_EXISTS;
     fclose(pFile);
   }
 }
 else if (Access == NEW_FILE)
 {
   Mode[0] = 'w';
   Mode[1] = '+';
 }//if(Access == APPEND_FILE)
 else if (Access == NEW_FILE_NO_OVERWRITE)
 {
   Mode[0] = 'w';
   Mode[1] = '+';

   // check if file exists and return NULL if so.
   pFile = fopen(FileName,"r");
   if(pFile != NULL)
   {
     nRet = LOGFILE_EXISTS;
     fclose(pFile); 
     pFile=NULL;
     return NULL;
   }
   
 }//if(Access == APPEND_FILE)
 
 // reset data/header string on startup
 memset(DataString,0,sizeof(DataString));
 memset(HeadString,0,sizeof(HeadString));
 
 // open file using predefined mode
 pFile=fopen(FileName,Mode);
 
 *pRes = nRet;

 return pFile;

/*--- UNDEF SYMBOLIC CONSTANTS ---*/
}

/* **************************************************************************** 
  Functionname:     SetColumnSeparator()                      */ /*!  
  Description:      Sets the character used as column separator.    


  @param[in]        char colsep  

  @return           
  @pre              -
  @post             -
  @author           Reik Müller
**************************************************************************** */
void SetColumnSeparator(char colsep)
{
  separator = colsep;
}

/* **************************************************************************** 
  Functionname:     FinishCurrentLine()                      */ /*!  
  Description:      


  @param[in,out]    

  @return           
  @pre              -
  @post             -
  @author           Reik Müller
**************************************************************************** */
void FinishCurrentLine  (void){

  // check for LogFile present
  if(pFile == NULL) return;  
  
  // finish current data line and save file
  CloseLogFile();
  
  // reset data/header string on startup
  memset(DataString,0,sizeof(DataString));
  
  // reopen file for further writing
  pFile=fopen(FileName,"a");
  
}

/* **************************************************************************** 
  Functionname:     CloseLogFile                      */ /*!  
  Description:      


  @param[in,out]    

  @return           
  @pre              -
  @post             -
  @author           Reik Müller
**************************************************************************** */
void CloseLogFile  (void){

  // variables
  int maxColumn =  0;
  
  // check for LogFile present
  if(pFile == NULL) return;  
  
  // compute current column number
  while (HeadString[maxDataLen*maxColumn]!=0) {
    // accumulate max number of columns
    maxColumn++;
  }
  
  // write data string to file
  WriteLogfileLine(pFile, maxColumn, maxDataLen, DataString);
  
  // close LogFile
  fclose(pFile);
  pFile = NULL;
  
}

/* **************************************************************************** 
  Functionname:     WriteLogfileLine()                      */ /*!  
  Description:      


  @param[in,out]    FILE *file : file pointer
  @param[in,out]    int nColumns : number of strings to write
  @param[in,out]    int DataLen : max. length of each string
  @param[in,out]    char* Data: array of data strings

  @return           -1: error, else success
  @pre              -
  @post             -
  @author           Timo Seifert
**************************************************************************** */
int WriteLogfileLine(FILE *file, int nColumns,int DataLen, char* Data)
{
  /*--- (SYMBOLIC) CONSTANTS ---*/

  /*--- VARIABLES ---*/

  int i,Len,Pos;

  if(file == NULL)
    return -1;

  Line[0] = 0;

  for(i=0,Pos=0; (i<nColumns);i++)
  {
    memcpy(DataString, &(Data[i*DataLen]),DataLen >maxDataLen?maxDataLen:DataLen);

    Len = (int)strlen(DataString);

    if((Pos+Len+1) >4090)
      break;
    strcat(Line,DataString);
    strcat(Line,&separator);

    Pos += Len+1;
  }

  strcat(Line,"\n");

  fputs(Line,file);

  return 0;

  /*--- UNDEF SYMBOLIC CONSTANTS ---*/
}

/* **************************************************************************** 
  Functionname:     WriteLogfileHead()                      */ /*!  
  Description:      


  @param[in,out]    ILE *file : file pointer
  @param[in,out]    int nColumns : number of strings to write
  @param[in,out]    int DataLen : max. length of each string
  @param[in,out]    char* Data: array of data strings

  @return           -1: error, else success
  @pre              -
  @post             -
  @author           Stefan Heinrich
**************************************************************************** */
int WriteLogfileHead(FILE *file, int nColumns,int DataLen, char* Data)
{
  /*--- (SYMBOLIC) CONSTANTS ---*/

  /*--- VARIABLES ---*/

  int i,Len,Pos;

  // check for LogFile present
  if(pFile == NULL) return -1;  

  // close current file, copy to dummy file, reopen file
  char dmy[1024];
  strcpy(dmy,FileName); *strrchr(dmy,'.')=0; strcat(dmy,".dmy");
  fclose(pFile); 
  rename(FileName,dmy);
  FILE* dummy = fopen(dmy,"r"); 
  pFile = fopen(FileName,"w"); fclose(pFile); pFile = fopen(FileName,"a");
  file = pFile;


  /////////////////////////////////////////////////////
  // write new header line to file
  
  Line[0] = 0;
  for(i=0,Pos=0; (i<nColumns);i++)
  {
    Len = (int)strlen(&Data[i*maxDataLen]);

    if((Pos+Len+1) >4090)
      break;
    strcat(Line,&Data[i*maxDataLen]);
    strcat(Line,&separator);

    Pos += Len+1;
  }
  strcat(Line,"\n");
  fputs(Line,pFile);


  //////////////////////////////////////////////////////
  // copy data from dummy => file
  fgets(Line,4096,dummy);
  while(fgets(Line,4096,dummy)!=NULL) {
    fputs(Line,pFile);
  }


  //////////////////////////////////////////////////////
  // remove dummy file
  fclose(dummy); 
  remove(dmy);


  return 0;

  /*--- UNDEF SYMBOLIC CONSTANTS ---*/
}

/* **************************************************************************** 
  Functionname:     ReopenLogFile                      */ /*!  
  Description:      


  @param[in,out]    

  @return           
  @pre              -
  @post             -
  @author           Reik Müller
**************************************************************************** */
void ReopenLogFile  (void)
{
  /*--- (SYMBOLIC) CONSTANTS ---*/
  
  /*--- VARIABLES ---*/
  int maxColumn =  0;
  
  // check for LogFile present
  if(pFile != NULL) return;  
  
  // reopen file for further writing
  pFile=fopen(FileName,"a");

  // compute current column number
  while (HeadString[maxDataLen*maxColumn]!=0) {
    // accumulate max number of columns
    maxColumn++;
  }

  // write header to file
  WriteLogfileHead(pFile, maxColumn, maxDataLen, HeadString);

}

/* **************************************************************************** 
  Functionname:     WriteLogfileEntry()                      */ /*!  
  Description:      


  @param[in,out]    char* ColumnHeader: column header tag
  @param[in,out]    char* ColumnData:   format string for column data data

  @return           -1: error, else success
  @pre              -
  @post             -
  @author           Stefan Heinrich
**************************************************************************** */
int WriteLogfileEntry(char* ColumnHeader, char* ColumnData, ...)
{
  /*--- (SYMBOLIC) CONSTANTS ---*/
  
  /*--- VARIABLES ---*/

  int nColumn   = -1;
  int maxColumn =  0;
  va_list argPointer;
  va_start(argPointer,ColumnData);

  
  // check for LogFile present
  if(pFile == NULL) return -1;  
  
  
  /////////////////////////////////////////////////////////////////////
  // compute current column number
  
  while (HeadString[maxDataLen*maxColumn]!=0) {
    // check if column header found
    if(strcmp(&HeadString[maxDataLen*maxColumn],ColumnHeader)==0) nColumn=maxColumn;
    // accumulate max number of columns
    maxColumn++;
  }
  

  ////////////////////////////////////////////////////////////////////
  // add new data column to Data/Header-String

  if (nColumn<0) { 
    // set current collumn number 
    nColumn=maxColumn; 
    // increment max column number
    maxColumn++; 
    // add new entry to header string
    if (ColumnHeader!=NULL) memcpy(HeadString+maxDataLen*nColumn, ColumnHeader, strlen(ColumnHeader)>maxDataLen?maxDataLen:strlen(ColumnHeader));
    // write header to file
    WriteLogfileHead(pFile, maxColumn, maxDataLen, HeadString);
  }
  

  ////////////////////////////////////////////////////////////////////
  // write data entry to file

  // check for valid ColumnData
  if (ColumnData!=NULL) {
    // data entry already present => write data string to file, reset data string
    if (DataString[maxDataLen*nColumn]!=0) {
      WriteLogfileLine(pFile, maxColumn, maxDataLen, DataString);
      memset(DataString,0,sizeof(DataString));
    }
    // copy data to data string
    vsprintf(DataString+maxDataLen*nColumn, ColumnData, argPointer);
  }
  
  // return on success
  return 0;

  /*--- UNDEF SYMBOLIC CONSTANTS ---*/
}

















/* **************************************************************************** 
  Functionname:     functionXXX                      */ /*!  
  Description:      


  @param[in,out]    x description
  @param[in,out]    y description

  @return           int description
  @pre              -
  @post             -
  @author           Timo Seifert
**************************************************************************** */


/*--- (SYMBOLIC) CONSTANTS ---*/

/*--- VARIABLES ---*/

/*--- UNDEF SYMBOLIC CONSTANTS ---*/