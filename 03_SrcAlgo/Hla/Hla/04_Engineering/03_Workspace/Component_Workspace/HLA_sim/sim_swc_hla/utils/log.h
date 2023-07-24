/*! \file **********************************************************************

  COMPANY:                Continental Temic, PL FAS, A.D.C. GmbH

  PROJECT:                none

  CPU:                    Pentium

  COMPONENT:             Logfile Support

  MODULNAME:              log.h

  @brief

  @author                 Timo Seifert

  CREATION DATE:          09.03.2006

  VERSION:                Revision: 

  CHANGES:                
  ---*/ /*---
  CHANGE:                 Log: log.h
  CHANGE:                 Revision 1.6  2007/04/02 12:01:39  heinrichs1
  CHANGE:                 - modifications from "Testwoche Wasserburg 070326 - 070330" (heinrich)
  CHANGE:
  CHANGE:                 Revision 1.5  2006/12/18 16:26:59  muellerr5
  CHANGE:                 - added functions FinishCurrentLine(...) and SetColumnSeparator(...)
  CHANGE:                 (Reik Müller, Stefan Heinrich)
  CHANGE:
  CHANGE:                 Revision 1.4  2006/05/03 18:50:58  muellerr5
  CHANGE:                 - add "CloseLogFile()"    (R.Müller/S.Heinrich)
  CHANGE:
  CHANGE:                 Revision 1.3  2006/05/03 13:08:42  almeidac
  CHANGE:                 - Added tag "NEW_FILE_NO_OVERWRITE" (almeidac)
  CHANGE:
  CHANGE:                 Revision 1.2  2006/03/21 08:59:25  heinrichs1
  CHANGE:                 - added "WriteLogfileEntry(..)" functionality  (heinrich)
  CHANGE:
  CHANGE:                 Revision 1.1  2006/03/13 13:47:33  seifertt
  CHANGE:                 - logfile support added [T.Seifert]
  CHANGE:
  CHANGE:                 Revision 1.1  2006/03/10 13:09:00  seifertt
  CHANGE:                 - files to support generation of result reports [T.Seifert]
  CHANGE:

**************************************************************************** */


/* avoid cyclic binding ---------------------------------------------------*/
#ifndef LOG_SUPPORT_INCLUDED
#define LOG_SUPPORT_INCLUDED

#include <stdio.h>

/*****************************************************************************
  SYMBOLISCHE KONSTANTEN (KOMPONENTENEXTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (KOMPONENTENEXTERN)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (KOMPONENTENEXTERN)
*****************************************************************************/
typedef enum
{
  NEW_FILE,
  APPEND_FILE,
  NEW_FILE_NO_OVERWRITE
}eLogFileAccess;

/*****************************************************************************
  KONSTANTEN (KOMPONENTENEXTERN)
*****************************************************************************/
#define LOGFILE_EXISTS  1
#define LOGFILE_CREATED 0



/*****************************************************************************
  VARIABLEN (KOMPONENTENEXTERN)
*****************************************************************************/


/*****************************************************************************
  FUNKTIONEN (KOMPONENTENEXTERN)
*****************************************************************************/

FILE *CreateLogFile  (char* path, char* name,eLogFileAccess Access, int *pRes);
int WriteLogfileLine  (FILE *file, int nColumns, int DataLen, char* Data);
int WriteLogfileEntry(char* ColumnHeader, char* ColumnData=NULL, ...);
void FinishCurrentLine  (void);
void CloseLogFile  (void);
void ReopenLogFile  (void);
void SetColumnSeparator(char separator);

void InitLogGlobals(void);


/* avoid cyclic binding ---------------------------------------------------*/
#endif
