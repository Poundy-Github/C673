/*! \file **********************************************************************

  COMPANY:                Continental Temic, PL FAS, A.D.C. GmbH

  PROJECT:                none

  CPU:                    Pentium

  COMPONENT:              Parameter reader

  MODULNAME:              param.c

  @brief                  Routines for dynamic parameter handling

  @author                 Timo Seifert

  CREATION DATE:          09.05.2005

  VERSION:                Revision: 1.30 

  CHANGES:                
  ---*/ /*---
  CHANGE:                 Log: param.c,v 
  CHANGE:                 Revision 1.30  2007/04/02 12:01:39  heinrichs1
  CHANGE:                 - modifications from "Testwoche Wasserburg 070326 - 070330" (heinrich)
  CHANGE:
  CHANGE:                 Revision 1.29  2007/03/12 13:27:18  seifertt
  CHANGE:                 - variable static int  ReadCyclic must be 1 for the first call of LoadParams() ! [T.Seifert]
  CHANGE:
  CHANGE:                 Revision 1.28  2007/03/09 16:20:28  ulbrichtd
  CHANGE:                 default parameter settings adapted to ini-File (ulbricht)
  CHANGE:
  CHANGE:                 Revision 1.27  2007/01/25 14:35:46  x-hoerj
  CHANGE:                 deleted blank line just for test (jhoer)
  CHANGE:
  CHANGE:                 Revision 1.26  2007/01/25 08:58:48  x-hoerj
  CHANGE:                 - added blanc line (hoer)
  CHANGE:
  CHANGE:                 Revision 1.25  2007/01/19 13:44:25  seifertt
  CHANGE:                 - if READ_FIXED_PARAMS defined, read data from ini_parameters.h [T.Seifert]
  CHANGE:
  CHANGE:                 Revision 1.24  2006/01/23 15:03:49  seifertt
  CHANGE:                 - remove comments, if inside comment is "" [T.Seifert]
  CHANGE:
  CHANGE:                 Revision 1.23  2006/01/17 10:37:20  seifertt
  CHANGE:                 - read boolean parameters from INI file, store as integer
  CHANGE:                 - comments ";"   "//" "/*"  allowed [T.Seifert]
  CHANGE:
  CHANGE:                 Revision 1.22  2005/12/16 11:42:55  seifertt
  CHANGE:                 - stop sorting, if last entry of the top list reached 100 calls [T.Seifert]
  CHANGE:
  CHANGE:                 Revision 1.21  2005/12/14 15:03:49  seifertt
  CHANGE:                 - sort the params by number of read requests to increase speed [T.Seifert]
  CHANGE:
  CHANGE:                 Revision 1.20  2005/12/09 12:43:22  seifertt
  CHANGE:                 - track of changes possible in file header [T.Seifert]
  CHANGE:
**************************************************************************** */



/****************************************************************************
   PARAM.C                  
   Routines for dynamic parameter handling

****************************************************************************/


/***************************************************************************/
/* local includes -------------------------------------------------------- */
/***************************************************************************/
#include <stddef.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <map>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "param.h"

#pragma warning (disable: 4996)

/***************************************************************************/
/* local defines ----------------------------------------------------------*/
/***************************************************************************/

/***************************************************************************/
/* local macros -----------------------------------------------------------*/
/***************************************************************************/

/***************************************************************************/
/* local vars--------------------------------------------------------------*/
/***************************************************************************/

typedef struct
{
  unsigned char *pData;    /* parameter value as memdump */
  int nDataLen;            /* amount of bytes needed for pData */ 
  eParamType nType;        /* type of parameter */
} ParamValue_t;

/* hash table: key is a pair of section and name, value is the struct ParamValue_t */
typedef std::map< std::pair<std::string, std::string>, ParamValue_t> ParamMap;

static ParamMap   paramMap;
static int        ReadCyclic = 1;
static int        IniFileExist = 1;

static char strParamINIFile[PARAM_MAX_INI_FILE_NAME_LENGTH];
char *strParamFileName = strParamINIFile;
static struct _stat IniFileInfo; 

/***************************************************************************/
/* local function declarations --------------------------------------------*/
/***************************************************************************/

eParamType    CheckParamType (char *strVal);
static void   ElimEndSpaces  (char *strVal);
static void   ElimQuotations (char *strVal);
static int CheckFile4Modifications(char *strFileName);
static void ClearIniFileInfo(void);


/***************************************************************************/
/* public functions -------------------------------------------------------*/
/***************************************************************************/

/* **************************************************************************** 

  Functionname:  ClearParams                        */ /*!  

  @brief         clears the internal RAM param buffer

  @return        nothing - this always works!

  @pre           none
  @post          the internal RAM param buffer is empty

  @author        Steen Kristensen, 2007 Mar 02

**************************************************************************** */
void ClearParams()
{
  for (ParamMap::const_iterator it = paramMap.begin(); it != paramMap.end(); ++it)
  {
    free((*it).second.pData);
  }
  paramMap.clear();
  ReadCyclic = 1;
  memset(&strParamINIFile, 0, sizeof(strParamINIFile));
  strParamFileName = strParamINIFile;
// Commented out for hil (eval board) as param_mdc.c which includes ClearIniFileInfo() cannot be compiled for sys/bios (different file I/O)
#ifdef WIN32
  ClearIniFileInfo();
#endif
} /* end of ClearParams */

/*****************************************************************************
  FUNKTIONSNAME:           LoadParams() 
  AUFGABE:                Parameterliste aus Datei aufbauen

  RUECKGABEWERTE:         0 on success, -1 on failure
  EINGANGSPARAMETER:      - 
  AUSGANGSPARAMETER:      -
  
  VORBEDINGUNGEN:         - Struktur des Textfiles:
                             [SECTION]

                             NAME=value,TYPE


                           -> Section in eckiger Klammer
                              Kommentare beginnen mit ;
                              Namen nicht laenger als 64 Zeichen
                              TYPE: d -> integer
                                    c -> unsigned char
                                    f -> float
                                    h -> HEX-integer
                                    g -> double
                                    e -> double als X.XXe-YYY
                               
  NACHBEDINGUNGEN:        -
  SPEICHERBEDARF:         -
  LAUFZEIT:               -

  NAME DES ERSTELLERS:    Timo Seifert
  DATUM DER ERSTELLUNG:   02.12.2004
****************************************************************************/
int LoadParams()
{

/*--- FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/
  
/*--- FUNKTIONSLOKALE KONSTANTEN ---*/

/*--- FUNKTIONSLOKALE VARIABLEN ---*/
 FILE *hFile = NULL;
 char Line[1024];
 char *pos, *pos2, *pos3, *pos4;
 char AktSection[64]="";
 char AktName[256]="";
 char AktValue[1024]="";
 int nLen =0;
 unsigned int nVal;
 double dfVal;
 eParamType AktType;
 int i;
/*--- FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/

 if(ReadCyclic==0)
 {
   return (0);
 }
 if(IniFileExist == 0)
 {
   return (-1);
 }

#ifdef WIN32 /* doesn't work on linux and dsp (param.c does!!) */
 /* check modification date of parameter file */
 if(CheckFile4Modifications(strParamFileName)==0)
 {
   return (0);
 }
#endif
 
 /* read the parameter file */

 hFile = fopen(strParamFileName,"r");

 if(hFile != NULL)
 {

   IniFileExist = 1;

   while( fgets(Line,1024,hFile) != NULL) /* 1 Zeile lesen */
   {
      pos3 = strchr(Line,'"');
      pos = strchr(Line,';');
      if(pos!=NULL)
      {
        if(pos3==NULL)
          *pos = 0; /* Kommentar ";" abschneiden */
        else if(pos < pos3)
        {
          *pos = 0; /* Kommentar ";" vor dem String abschneiden */
          pos3 = NULL;
        }
      }

      pos4 = strstr(Line,"//");
      if(pos4!=NULL)
      {
        if(pos3==NULL)
          *pos4 = 0; /* Kommentar "//" abschneiden */
        else if(pos4 < pos3)
        {
          *pos4 = 0; /* Kommentar "//" vor dem String abschneiden */
          pos3 = NULL;
        }
      }

      pos4 = strstr(Line,"/*");
      if(pos4!=NULL)
      {
        if(pos3==NULL)
          *pos4 = 0; /* Kommentar abschneiden */
        else if(pos4 < pos3)
        {
          *pos4 = 0; /* Kommentar vor dem String abschneiden */
          pos3 = NULL;
        }
      }
      
      if(pos3!=NULL)
      {
        pos = pos3+1;
        pos3 = strchr(pos,'"');
        if(pos3) /* Zeiger hinter den String setzen */
        {
          pos = strchr(pos3,';');
          if(pos)
           *pos = 0; /* Kommentar ";" abschneiden */
          pos4 = strstr(pos3,"//");
          if((pos4!=NULL))
            *pos4 = 0; /* Kommentar "//" abschneiden */

          pos4 = strstr(pos3,"/*");
          if((pos4!=NULL))
            *pos4 = 0; /* Kommentar abschneiden */
        }
      }

      pos3 = strchr(Line,'"');
      /* Section identifizieren */
      pos = strchr(Line,'[');
      if(pos && (pos3==NULL))
      {
        /* section name found? */
         pos2 = strchr(Line,']');
         if(pos2)
         {
           nLen = (int)(pos2 - pos); 
           *pos2 = 0;
           strncpy(AktSection,pos+1,nLen <= 64? nLen: 64);/*section update */
         }
      }
      else
      {
        pos = strchr(Line,'=');
        if(pos)
        {
          /* value found?? */
          memset(AktName,0,sizeof(AktName));
          pos2 = &(Line[0]);
          while( ((*pos2) == ' ') && (pos2 != pos)) pos2++; /* ignore whitespaces before the name*/
          
          if(pos3)
          {
            pos3 = strchr(pos3+1,'"');
          }

          /* now pos2 points to the begin of the name -> check white spaces after the name */
          i =1;
         /* if(pos3==NULL) */
           while(  ( (*(pos-i)) == ' ') && ((pos-i) != pos2)   ) i++; 

          nLen = (int)(pos - pos2 - i + 1); 
          strncpy(AktName,pos2, nLen <= 255? nLen: 255 ); /* copy name */
 
          memset(AktValue,0,sizeof(AktValue));

          /* eliminate white spaces at the beginning of the value */
          pos ++;
          while( ((*pos) == ' ') || ((*pos) == '+') ) pos++;

         /* stop string after the first whitespace after the value */
          if(pos3==NULL)
            pos2 = strchr(pos,' ');
          else
            pos2 = strchr(pos3,' ');

          if(pos2) *(pos2)=0;
            nLen = (int)strlen(pos); 

          strncpy(AktValue,pos, nLen <= 1023? nLen: 1023 ); /* copy value string */

          AktType = CheckParamType(AktValue);

          if(AktType == PTYPE_MAX)
            return (-1);

          switch(AktType)
          {
            case PTYPE_INT:
              nVal = atoi(pos);
              AddParam(AktSection,AktName,AktValue,PTYPE_INT, 4, (unsigned char *)&nVal);
            break;

            case PTYPE_DOUBLE:
               dfVal = atof(pos);
               AddParam(AktSection,AktName,AktValue,PTYPE_DOUBLE, sizeof(dfVal), (unsigned char *)&dfVal);
            break;
            case PTYPE_STRING:
              ElimEndSpaces(AktValue);
              ElimQuotations(AktValue);
              nVal = (unsigned int)strlen(AktValue) +1;
               AddParam(AktSection,AktName,AktValue,PTYPE_STRING, nVal, (unsigned char *)AktValue);
            break;

            case PTYPE_HEX:
              if(strstr(pos,"0x")!=NULL)
                sscanf(pos,"0x%X",&nVal);
              else
                sscanf(pos,"%X",&nVal);
              AddParam(AktSection,AktName,AktValue,PTYPE_INT, 4, (unsigned char *)&nVal);
            break;

            case PTYPE_BOOL:
               if( (strstr(pos,"FALSE")!=NULL) || (strstr(pos,"false")!=NULL) )
               {
                 nVal = 0;
               }
               else if((strstr(pos,"TRUE")!=NULL)|| (strstr(pos,"true")!=NULL))
               {
                 nVal = 1;
               } 
               
               AddParam(AktSection,AktName,AktValue,PTYPE_INT, 4, (unsigned char *)&nVal);
            break;

            case PTYPE_ARRAY:
            break;
          }/* switch(AktType) */
        }/* if(pos) */
      }/* if(pos) */
   }/* while( fgets(Line,1024,hFile) != NULL) */

   fclose(hFile);
   ReadCyclic   = GetParamInt("param","CYCLIC_READ",1);

   return (0);
 }/* if(hFile != NULL) */
 else
 {
   IniFileExist = 0;
 }

 return (-1);

/*--- AUFHEBUNG FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/

}



int   GetParamInt(char *strSection, char *strName, int nDefaultVal)
{
  int nVal = nDefaultVal;

  const ParamMap::const_iterator it = paramMap.find(std::make_pair(strSection, strName));

  if(it != paramMap.end())
  {

    switch((*it).second.nType)
    {
      case PTYPE_INT:
         memcpy(&nVal, (*it).second.pData, (*it).second.nDataLen >= 4? 4: (*it).second.nDataLen);
      break;

      case PTYPE_DOUBLE:
        nVal = (int)( *( (double*)((*it).second.pData) ) );
      break;
      case PTYPE_STRING:
        nVal = atoi((char*)(*it).second.pData);
      break;
      case PTYPE_ARRAY:
      break;
    }/* switch(AktType) */
  
  }
#ifdef WIN32
  else if(IniFileExist == 1)
  {
    if (!((strcmp(strName, "CYCLIC_READ") == 0) || (strcmp(strName, "TOP_HIT_LEN") == 0)))
    {
      fprintf(stderr, "warning: parser could not find entry %s in section %s, using default %d\n", strName, strSection, nDefaultVal);
    }
  }
#endif

  return nVal;
}

void  SetParamInt(char *strSection, char *strName, int nVal)
{

}

float GetParamFloat(char *strSection, char *strName, float fDefaultVal)
{
  float fVal = fDefaultVal;
  double dVal;

  const ParamMap::const_iterator it = paramMap.find(std::make_pair(strSection, strName));

  if(it != paramMap.end())
  {
    switch((*it).second.nType)
    {
      case PTYPE_INT:
         fVal = (float)( *((int*)((*it).second.pData)) );
      break;

      case PTYPE_DOUBLE:
         memcpy(&dVal, (*it).second.pData,
             (*it).second.nDataLen >= sizeof(dVal)? sizeof(dVal): (*it).second.nDataLen );
         fVal = (float)dVal;
      break;
      case PTYPE_STRING:
        fVal = (float)atof((char*)(*it).second.pData);
      break;
      case PTYPE_ARRAY:
      break;
    }/* switch(AktType) */

  }
#ifdef WIN32
  else if(IniFileExist == 1)
  {
    fprintf(stderr, "warning: parser could not find entry %s in section %s, using default %f\n", strName, strSection, fDefaultVal);
  }
#endif

  return fVal ;
}

void  SetParamFloat(char *strSection, char *strName, float fVal)
{

}

double GetParamDouble(char *strSection, char *strName, double dfDefaultVal)
{
  double dVal = dfDefaultVal;
  int nLen = sizeof(dVal);

  const ParamMap::const_iterator it = paramMap.find(std::make_pair(strSection, strName));

  if(it != paramMap.end())
  {
    switch((*it).second.nType)
    {
      case PTYPE_INT:
         dVal = (double)( *((int*)((*it).second.pData)) );
      break;

      case PTYPE_DOUBLE:
         memcpy(&dVal, (*it).second.pData,
           (*it).second.nDataLen >= nLen? nLen: (*it).second.nDataLen );
      break;
      case PTYPE_STRING:
        dVal = atof((char*)(*it).second.pData);
      break;
      case PTYPE_ARRAY:
      break;
    }/* switch(AktType) */

  }

  return dVal;
}

void SetParamDouble(char *strSection, char *strName, double dfVal)
{

}

unsigned char GetParamByte(char *strSection, char *strName, unsigned char ucDefaultVal)
{
  unsigned char ucVal = ucDefaultVal;
  int nLen = sizeof(ucVal);

  const ParamMap::const_iterator it = paramMap.find(std::make_pair(strSection, strName));

  if(it != paramMap.end())
  {
    switch((*it).second.nType)
    {
      case PTYPE_INT:
         memcpy(&nLen, (*it).second.pData, (*it).second.nDataLen >= 4? 4: (*it).second.nDataLen);
         ucVal = (unsigned char)(nLen);
      break;

      case PTYPE_DOUBLE:
        ucVal = (unsigned char)( *( (double*)((*it).second.pData) ) );
      break;
      case PTYPE_STRING:
        ucVal = (unsigned char)atoi((char*)(*it).second.pData);
      break;
      case PTYPE_ARRAY:
      break;
    }/* switch(AktType) */

 
  }

  return ucVal;
}

void SetParamByte(char *strSection, char *strName, unsigned char ucVal)
{
}

void GetParamArray(char *strSection, char *strName, int nLen, unsigned char *pDestination)
{
  const ParamMap::const_iterator it = paramMap.find(std::make_pair(strSection, strName));

  if(it != paramMap.end())
  {
     memcpy(pDestination, (*it).second.pData, 
            (*it).second.nDataLen >= nLen? nLen: (*it).second.nDataLen);
  }
}

void SetParamArray(char *strSection, char *strName, int nLen, unsigned char *pSource)
{
}


void GetParamString(char *strSection, char *strName, int nLen, char *pDestination)
{
  int nVal;
  double dVal;
  int nCopyLen;

  const ParamMap::const_iterator it = paramMap.find(std::make_pair(strSection, strName));

  if(it != paramMap.end())
  {
     switch((*it).second.nType)
    {
      case PTYPE_INT:
         memcpy(&nVal, (*it).second.pData, (*it).second.nDataLen >= 4? 4: (*it).second.nDataLen);
         sprintf(pDestination,"%d",nVal);
      break;

      case PTYPE_DOUBLE:
         memcpy(&dVal, (*it).second.pData, (*it).second.nDataLen >= sizeof(dVal)? sizeof(dVal): (*it).second.nDataLen);
         sprintf(pDestination,"%f",dVal);
      break;
      case PTYPE_STRING:
         nCopyLen = nLen;
         if((*it).second.nDataLen <nLen )
           nCopyLen = (*it).second.nDataLen;
         if((*it).second.nDataLen >= nLen)
           nCopyLen = nLen; 
         memcpy(pDestination, (*it).second.pData, nCopyLen);
      break;
      case PTYPE_ARRAY:
      break;
    }/* switch(AktType) */

    
  }
}

void SetParamString(char *strSection, char *strName, int nLen, char *pSource)
{
}



/***************************************************************************/
/* prvate functions -------------------------------------------------------*/
/***************************************************************************/

/*****************************************************************************
  FUNKTIONSNAME:          AddParam()  
  AUFGABE:                Parameter in Array eintragen

  RUECKGABEWERTE:         - 
  EINGANGSPARAMETER:      - 
  AUSGANGSPARAMETER:      -
  
  VORBEDINGUNGEN:         -
  NACHBEDINGUNGEN:        -
  SPEICHERBEDARF:         -
  LAUFZEIT:               -

  NAME DES ERSTELLERS:    Timo Seifert
  DATUM DER ERSTELLUNG:   02.12.2004
****************************************************************************/
void AddParam(char *section, char *Name, char *ValueString,eParamType Type, int nLen, unsigned char *pData)
{
/*--- FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/

/*--- FUNKTIONSLOKALE KONSTANTEN ---*/

/*--- FUNKTIONSLOKALE VARIABLEN ---*/
  unsigned char *pVar;
/*--- FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/

  const ParamMap::iterator it = paramMap.find(std::make_pair(section, Name));

  if(it == paramMap.end())
  {
     /*neuer Eintrag */ 

     pVar = (unsigned char*)malloc(nLen);
     memcpy(pVar,pData,nLen);
     
     ParamValue_t paramValue;
     paramValue.pData = pVar;
     paramValue.nDataLen = nLen;
     paramValue.nType = Type;

     paramMap[std::make_pair(section, Name)] = paramValue;
  }
  else
  {
    if((*it).second.nDataLen != nLen)
    {
      /* Speicherbedarf anders -> neu anlegen */
      free((*it).second.pData);
      (*it).second.nDataLen = nLen;
      pVar = (unsigned char*)malloc(nLen);
      (*it).second.pData = pVar;
    }

    (*it).second.nType = Type;

    /* nur updaten */
    memcpy((*it).second.pData,pData,(*it).second.nDataLen >= nLen? nLen:(*it).second.nDataLen);

  }
/*--- AUFHEBUNG FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/
}


/*****************************************************************************
  FUNKTIONSNAME:          FindParam()  
  AUFGABE:                Parameter im Array finden

  RUECKGABEWERTE:         - <0 : nicht gefunden, sonst Array-Position
  EINGANGSPARAMETER:      - 
  AUSGANGSPARAMETER:      -
  
  VORBEDINGUNGEN:         -
  NACHBEDINGUNGEN:        -
  SPEICHERBEDARF:         -
  LAUFZEIT:               -

  NAME DES ERSTELLERS:    Timo Seifert
  DATUM DER ERSTELLUNG:   02.12.2004
****************************************************************************/
int FindParam(char *section, char *Name)
{
  const ParamMap::iterator it = paramMap.find(std::make_pair(section, Name));

  if(it == paramMap.end())
  {
    return -1;
  }
  else
  {
    return 0;
  }
}


/*****************************************************************************
  FUNKTIONSNAME:          CheckParamType()  
  AUFGABE:                check the type of a parameter string

  RUECKGABEWERTE:         - eParamType : Parameter type identifier
  EINGANGSPARAMETER:      - char *strVal : parameter string
  AUSGANGSPARAMETER:      -
  
  VORBEDINGUNGEN:         -
  NACHBEDINGUNGEN:        -
  SPEICHERBEDARF:         -
  LAUFZEIT:               -

  NAME DES ERSTELLERS:    Timo Seifert
  DATUM DER ERSTELLUNG:   13.12.2004
****************************************************************************/
eParamType CheckParamType(char *strVal)
{
/*--- FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/

/*--- FUNKTIONSLOKALE KONSTANTEN ---*/

/*--- FUNKTIONSLOKALE VARIABLEN ---*/
 char *pos, *pos2;
 char Text1[64];
 unsigned nVal;
 int i;
 int HexFound=0;
/*--- FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/
  
 pos = strchr(strVal,'.');
 
 pos2 =  strchr(strVal,'"');

 if(pos2 != NULL)
 {
   return PTYPE_STRING;
 }

 if( (strstr(strVal,"FALSE")!=NULL) 
    || (strstr(strVal,"false")!=NULL)
    || (strstr(strVal,"TRUE")!=NULL)
    || (strstr(strVal,"true")!=NULL)
   )
   return PTYPE_BOOL;

 if(pos != NULL)
 {
   /* evtl. float?? */
   if(pos != strVal)
   {
     /* '.' nicht am Anfang -> auf Zahlen pruefen */
     memset(Text1,0,sizeof(Text1));
     strncpy(Text1,strVal, pos - strVal);

     nVal = atoi(Text1);
     if(Text1[0]=='+')                        /* e.g. "+3.56" */
       sprintf(Text1,"+%d",nVal);
     else if((nVal==0) && (Text1[0]=='-') )   /* e.g. "-0.66" */
       sprintf(Text1,"-%d",nVal);
     else
       sprintf(Text1,"%d",nVal);
     
     if((int)strlen(Text1) == (pos - strVal))
     {
       /* nur Ziffern vor dem '.' */
       return PTYPE_DOUBLE;
     }
     else
       return PTYPE_STRING;
   }/*if(pos != strVal) */
 }
 else
 {

   /*evtl. Integer? */
   pos = strchr(strVal,',');
   if(pos!=NULL)
     *pos=0;

   nVal = (int) strlen(strVal);
   if(nVal)
   {

     /* auf HEX Darstellung pruefen */
     for(i=0;i<(int)nVal;i++)
     {
       if(    (strVal[i] < '0') 
           && (strVal[i] > '9')  
           && (strVal[i] != ' ')
           && (strVal[i] != 'x')
           && (strVal[i] != '-')
           && (strVal[i] != '+')
           && (strVal[i]< 'a')
           && (strVal[i]> 'f')
           && (strVal[i]< 'A')
           && (strVal[i]> 'F'))
         break;

       if((strVal[i]>= 'a')
           && (strVal[i]<= 'f'))
        HexFound++;

       if((strVal[i]>= 'A')
           && (strVal[i]<= 'F'))
        HexFound++;

       if(strVal[i]=='x')
         HexFound++;

     }

     if((i == (int)nVal) && (HexFound))
       return PTYPE_HEX; /* nur 'a'..'f', 'A'..'F', '0'..'9' gefunden*/
    

     for(i=0;i<(int)nVal;i++)
     {
       if( (strVal[i] < '0')   && (strVal[i] > '9')  && (strVal[i] != ' ') 
         && (strVal[i] != '-') && (strVal[i] != '+')  )
         return PTYPE_STRING; /* Zeichen gefunden, dass keine Ziffer oder Leerzeichen ist */
     }

     return PTYPE_INT;
   }/* if(strlen(strVal)) */
 }/* if(pos != NULL) */



 return PTYPE_MAX;
/*--- AUFHEBUNG FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/
}


/*****************************************************************************
  FUNKTIONSNAME:          ElimEndSpaces()  
  AUFGABE:                Whitespaces am Ende von Strings loeschen

  RUECKGABEWERTE:         - 
  EINGANGSPARAMETER:      - 
  AUSGANGSPARAMETER:      - char *strVal : zu bearbeitender String
  
  VORBEDINGUNGEN:         -
  NACHBEDINGUNGEN:        -
  SPEICHERBEDARF:         -
  LAUFZEIT:               -

  NAME DES ERSTELLERS:    Timo Seifert
  DATUM DER ERSTELLUNG:   16.12.2004
****************************************************************************/
void   ElimEndSpaces(char *strVal)
{
/*--- FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/

/*--- FUNKTIONSLOKALE KONSTANTEN ---*/

/*--- FUNKTIONSLOKALE VARIABLEN ---*/
 int i, nLen;
/*--- FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/
 nLen = (int) strlen(strVal);

 for(i=nLen-1;i>=0;i--)
 {
   if((strVal[i] == ' ') || (strVal[i] ==0x0A) || (strVal[i] ==0x0D))
     strVal[i] =0;
   else
     break;
 }
}

/*****************************************************************************
FUNKTIONSNAME:          ElimQuotations()  
AUFGABE:                Whitespaces am Ende von Strings loeschen

  RUECKGABEWERTE:         - 
  EINGANGSPARAMETER:      - 
  AUSGANGSPARAMETER:      - char *strVal : zu bearbeitender String
  
    VORBEDINGUNGEN:         -
    NACHBEDINGUNGEN:        -
    SPEICHERBEDARF:         -
    LAUFZEIT:               -
    
      NAME DES ERSTELLERS:    Timo Seifert
      DATUM DER ERSTELLUNG:   16.12.2004
****************************************************************************/
void   ElimQuotations(char *strVal)
{
  /*--- FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/
  
  /*--- FUNKTIONSLOKALE KONSTANTEN ---*/
  
  /*--- FUNKTIONSLOKALE VARIABLEN ---*/
  int i, nLen;
  char* s = strVal;  /* source */
  char* d = strVal;  /* destination  */
  
  /*--- FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/
  nLen = (int) strlen(strVal);
  
  for(i=0;i<nLen;i++)
  {
    if(*s == '"') {
      s++;
    }
    else {
      *d=*s;
      s++; d++;
    }
  }
  *d=0; /* terminate string */

  /*--- AUFHEBUNG FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/
}

static int CheckFile4Modifications(char *strFileName)
{
/*--- FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/

/*--- FUNKTIONSLOKALE KONSTANTEN ---*/

/*--- FUNKTIONSLOKALE VARIABLEN ---*/
 int nRet =0;
 int fh;
 int nLen;
 struct _stat FileInfo; 

/*--- FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/
 /* check modification date of parameter file */
 fh = _open( strFileName,  _O_RDONLY);
 if(fh != -1)
 {
   nLen = _fstat(fh,&FileInfo);
    _close( fh );
  
   if(FileInfo.st_mtime == IniFileInfo.st_mtime)
     nRet = 0; /* wenn die Datei nicht veraendert wurde, nicht nochmals lesen */
   else
     nRet = 1;

  IniFileInfo = FileInfo;
 }
 else
 {
   IniFileExist = 0;
 }

 return nRet;
/*--- AUFHEBUNG FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/
}

static void ClearIniFileInfo(void)
{
  memset(&IniFileInfo, 0, sizeof(IniFileInfo));
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

/*--- UNDEF SYMBILIC CONSTANTS ---*/

/* ------------------------------------------------------------------------ */
