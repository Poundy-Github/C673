/*! \file **********************************************************************

  COMPANY:                Continental Temic, PL FAS, A.D.C. GmbH

  PROJECT:                none

  CPU:                    Pentium

  COMPONENT:              Parameter reader

  MODULNAME:              param.h

  @brief                  Routines for dynamic parameter handling

  @author                 Timo Seifert

  CREATION DATE:          09.05.2005

  VERSION:                $Revision: 1.1 $

  CHANGES:                
  ---*/ /*---
  CHANGE:                 $Log: param.h  $
  CHANGE:                 Revision 1.1 2017/02/28 15:31:24CET Fischer, Stephan02 (uidg9447) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Components/HLA_HeadLightAssist/04_Engineering/03_Workspace/Component_Workspace/HLA_sim/sim_swc_hla/utils/project.pj
  CHANGE:                 Revision 1.1 2014/03/19 16:34:44CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/03_Workspace/algo/hla_sim/sim_swc_hla/utils/project.pj
  CHANGE:                 Revision 1.4 2011/06/15 19:03:58CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - use the std::map container from STL for storing the parameters. Benefit is that the GetParamxxx() functions are a lot faster due to std::map binary tree search. Be careful to choose a C++ compiler for param.c because it is no longer pure Ansi C
  CHANGE:                 - fixed a memory leak (ClearParameters() removed the parameter list but not the memory for the parameter values)
  CHANGE:                 --- Added comments ---  uidt9253 [Jun 15, 2011 7:03:59 PM CEST]
  CHANGE:                 Change Package : 63192:1 http://mks-psad:7002/im/viewissue?selection=63192
  CHANGE:                 Revision 1.3 2009/06/25 15:44:52CEST rmueller 
  CHANGE:                 - added ClearIniFileInfo()
  CHANGE:                 --- Added comments ---  rmueller [2009/06/25 13:44:52Z]
  CHANGE:                 Change Package : 25385:1 http://LISS014:6001/im/viewissue?selection=25385
  CHANGE:                 Revision 1.2 2007/08/29 15:38:01CEST tseifert 
  CHANGE:                 MAX_PARAMS now 2048
  CHANGE:                 --- Added comments ---  tseifert [2007/08/29 13:38:01Z]
  CHANGE:                 Change Package : 4941:1 http://liss014:6001/im/viewissue?selection=4941
  CHANGE:                 Revision 1.1 2007/04/20 10:41:11CEST mbrunn 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/customer/Base_ARS3xx_ISF1xx/3_development/4_sw/dev/appl/pc_sim/calibration/src/param/project.pj
  CHANGE:                 Revision 1.7 2007/03/23 21:43:41CET aroth 
  CHANGE:                 ccs compiler warning
  CHANGE:                 --- Added comments ---  aroth [2007/03/23 20:43:41Z]
  CHANGE:                 Change Package : 1635:1 http://liss014:6001/im/viewissue?selection=1635
  CHANGE:                 Revision 1.6 2007/03/15 12:45:11CET aroth 
  CHANGE:                 last change was buggy!!
  CHANGE:                 --- Added comments ---  aroth [2007/03/15 11:45:11Z]
  CHANGE:                 Change Package : 1635:1 http://liss014:6001/im/viewissue?selection=1635
  CHANGE:                 Revision 1.5 2007/03/13 12:58:34CET astohr 
  CHANGE:                 fix prototypes and make them conform with exsiting code style
  CHANGE:                 --- Added comments ---  astohr [2007/03/13 11:58:34Z]
  CHANGE:                 Change Package : 577:24 http://liss014:6001/im/viewissue?selection=577
  CHANGE:                 Revision 1.4 2007/03/08 18:54:21CET aroth 
  CHANGE:                 - c/c++ compatibility
  CHANGE:                 --- Added comments ---  aroth [2007/03/08 17:54:21Z]
  CHANGE:                 Change Package : 1635:1 http://liss014:6001/im/viewissue?selection=1635
  CHANGE:                 Revision 1.3 2007/03/08 17:12:33CET aroth 
  CHANGE:                 - added return values
  CHANGE:                 - added clearparams()
  CHANGE:                 --- Added comments ---  aroth [2007/03/08 16:12:33Z]
  CHANGE:                 Change Package : 1635:1 http://liss014:6001/im/viewissue?selection=1635
  CHANGE:                 Revision 1.2 2006/12/13 16:12:14CET sheinric 
  CHANGE:                 - some changes
  CHANGE:                 Revision 1.8  2006/01/17 10:37:20  seifertt
  CHANGE:                 - read boolean parameters from INI file, store as integer
  CHANGE:                 - c++ comments allowed [T.Seifert]
  CHANGE:
  CHANGE:                 Revision 1.7  2005/12/14 15:03:49  seifertt
  CHANGE:                 - sort the params by number of read requests to increase speed [T.Seifert]
  CHANGE:
  CHANGE:                 Revision 1.6  2005/12/09 12:43:22  seifertt
  CHANGE:                 - track of changes possible in file header [T.Seifert]
  CHANGE:
**************************************************************************** */

/****************************************************************************
   PARAM.H                  
   Routines for dynamic parameter handling
****************************************************************************/

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef _PARAM_H
#define _PARAM_H


#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  INCLUDES
*****************************************************************************/



/* ************************************************************************ */
/* Konfiguration                  */
/* ************************************************************************ */

/*****************************************************************************
  SYMBOLISCHE KONSTANTEN (KOMPONENTENEXTERN)
*****************************************************************************/
#define PARAM_MAX_INI_FILE_NAME_LENGTH 1024

/*****************************************************************************
  MACROS (KOMPONENTENEXTERN)
*****************************************************************************/




/*****************************************************************************
  TYPEDEFS (KOMPONENTENEXTERN)
*****************************************************************************/
typedef enum
{
  PTYPE_INT =0,
  PTYPE_FLOAT,
  PTYPE_DOUBLE,
  PTYPE_STRING,
  PTYPE_ARRAY,
  PTYPE_HEX,
  PTYPE_BOOL,
  PTYPE_MAX
}eParamType;


/*****************************************************************************
  KONSTANTEN (KOMPONENTENEXTERN)
*****************************************************************************/


/*****************************************************************************
  VARIABLEN (KOMPONENTENEXTERN)
*****************************************************************************/

extern char *strParamFileName;
/*****************************************************************************
  FUNKTIONEN (KOMPONENTENEXTERN)
*****************************************************************************/


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Handling:

  1. bei Programmstart die Variable <strParamFileName> mit Pfad und Namen der INI
     Datei ausfuellen : strncpy(strParamFileName,ininame, PARAM_MAX_INI_FILE_NAME_LENGTH);

  2. dann LoadParams() aufrufen -> Daten aus INI-File in RAM kopiert

  3. zyklisch LoadParams() aufrufen, um Daten zu aktualisieren

Struktur INI File:
  - Textdatei, Kommentare beginnen mit ';' oder '#'
  - Sektion in [] setzen
  - zwischen Variablennamen und '=' keine Leerzeichen
  Zyklisches Lesen konfigurieren:
  im INI-File:

  [param]
CYCLIC_READ=1    -> zyklisch lesen moeglich, wenn CYCLIC_READ=0 -> nur 1x aus Datei lesen

  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
void AddParam(char *section, char *Name, char *ValueString,eParamType Type, int nLen, unsigned char *pData);

int FindParam(char *section, char *Name);


int   GetParamInt(char *strSection, char *strName, int nDefaultVal);
void  SetParamInt(char *strSection, char *strName, int nVal);

float GetParamFloat(char *strSection, char *strName, float fDefaultVal);
void  SetParamFloat(char *strSection, char *strName, float fVal);

double GetParamDouble(char *strSection, char *strName, double dfDefaultVal);
void   SetParamDouble(char *strSection, char *strName, double dfVal);

unsigned char GetParamByte(char *strSection, char *strName, unsigned char ucDefaultVal);
void          SetParamByte(char *strSection, char *strName, unsigned char ucVal);

void  GetParamArray(char *strSection, char *strName, int nLen, unsigned char *pDestination);
void  SetParamArray(char *strSection, char *strName, int nLen, unsigned char *pSource);

void  GetParamString(char *strSection, char *strName, int nLen, char *pDestination);
void  SetParamString(char *strSection, char *strName, int nLen, char *pSource);

int CheckFile4Modifications(char *strFileName);
void ClearIniFileInfo(void);

int LoadParams(void);
void ClearParams(void);


#ifdef __cplusplus
}
#endif

/* avoid cyclic binding ---------------------------------------------------*/
#endif

