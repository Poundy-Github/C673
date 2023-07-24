/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_visu_font.h

  DESCRIPTION:            Definitions and utilities regarding fonts

  CPU:                    Independent

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.2 $

  ---*/ /*---

**************************************************************************** */
#ifndef SIM_VISU_FONT_H
#define SIM_VISU_FONT_H

/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include <cstdlib>

#include <string>

#include "sim_swc_gdv_ifc.h"
#include "sim_gdvfont_ifc.h"
#include "sim_rendercontext_ifc.h"

using namespace std;

/* main class -------------------------------------------------------------- */
/************************************************************************/
/*  CSimTableCell                                                       */
/************************************************************************/
class CSimFont
{
public:
  CSimFont                     ( const string fName = "Arial", const unsigned int fSize = 8 );
  ~CSimFont                    ();
 
  void SetFontContext          ( const ISimRenderContext& ctx  );
  const ISimRenderContext* GetContext() const;

  void SetFontSize             ( const unsigned int fsize );
  void SetFontName             ( const string fname );
  void ResetFont               ();
  void UpdateFont              ( const string fname, const unsigned int fsize );
  unsigned int GetTextHeight   () const;
  unsigned int GetTextWidth    ( const string str ) const;
  IGDVFont* GetFont            () const;


private:

  const ISimRenderContext             *m_pContext;
  unsigned int                        m_fontSize;
  string                              m_fontName;
  IGDVFont*                           m_pFont;

  unsigned int                        m_deafultFontSize;
  string                              m_deafultFontName;


};

/************************************************************************/
/* default constructor                                                  */
/************************************************************************/
inline CSimFont::CSimFont( const string fName /*= "Arial"*/, const unsigned int fSize /*= 8*/ )
: m_pFont(NULL)
{
  m_fontName = fName;
  m_fontSize = fSize;
  m_deafultFontSize = fSize;
  m_deafultFontName = fName;
  m_pContext = NULL;
}

/************************************************************************/
/* Destructor                                                           */
/************************************************************************/
inline CSimFont::~CSimFont()
{
}

/************************************************************************/
/* ResetFont                                                            */
/************************************************************************/
inline void CSimFont::ResetFont()
{
  m_fontName = m_deafultFontName;
  m_fontSize = m_deafultFontSize;
}

/************************************************************************/
/* UpdateFont                                                           */
/************************************************************************/
inline void CSimFont::UpdateFont( const string fname, const unsigned int fsize )
{
  m_fontName = fname;
  m_fontSize = fsize;
}

/************************************************************************/
/* GetTextHeight                                                        */
/************************************************************************/
inline unsigned int CSimFont::GetTextHeight() const
{
  if(m_pContext)
  {
    return (unsigned int)m_pContext->GetWindow().GetFontInterface(m_fontName.c_str(),m_fontSize).GetTextHeight("X");
  }
  else
  {
    return 0;
  }
}

/************************************************************************/
/* GetTextWidth                                                         */
/************************************************************************/
inline unsigned int CSimFont::GetTextWidth( const string str ) const
{
  if(m_pContext)
  {
    int wchars_num =  MultiByteToWideChar( CP_UTF8 , 0 , str.c_str() , -1, NULL , 0 );
    wchar_t* wstr = new wchar_t[wchars_num];
    MultiByteToWideChar( CP_UTF8 , 0 , str.c_str() , -1, wstr , wchars_num );
    unsigned int textLength = (unsigned int)m_pContext->GetWindow().GetFontInterface(m_fontName.c_str(),m_fontSize).GetTextWidth(wstr);
    delete[] wstr;
    return textLength;
  }
  else
  {
    return 0;
  }
}

/************************************************************************/
/* SetFontSize                                                          */
/************************************************************************/
inline void CSimFont::SetFontSize( const unsigned int fsize )
{
  m_fontSize = fsize;
}

/************************************************************************/
/* SetFontName                                                          */
/************************************************************************/
inline void CSimFont::SetFontName( const std::string fname )
{
  m_fontName = fname;
}

/************************************************************************/
/* SetFontContext                                                       */
/************************************************************************/
inline void CSimFont::SetFontContext( const ISimRenderContext& ctx  )
{
  m_pContext = &ctx;
  m_pFont = &m_pContext->GetWindow().GetFontInterface(m_fontName.c_str(), m_fontSize);

}

/************************************************************************/
/* GetFont                                                              */
/************************************************************************/
inline IGDVFont* CSimFont::GetFont() const
{
  return m_pFont;
}

/************************************************************************/
/* GetContext                                                           */
/************************************************************************/
inline const ISimRenderContext* CSimFont::GetContext() const
{
  return m_pContext;
}

#endif // SIM_VISU_FONT_H
