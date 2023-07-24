/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_visu_menu.h

  DESCRIPTION:            Providing menu utilities like (de-)activating items, store and load configuration, etc.

  CPU:                    Independent

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.4 $

  ---*/ /*---

**************************************************************************** */
#ifndef SIM_VISU_MENUSUB_H
#define SIM_VISU_MENUSUB_H

#include "stdafx.h"
#include <string>
#include <vector>
#include <fstream>

#include "sim_visu_interface.h"
#include "sim_visu_color.h"
#include "sim_visu_font.h"

#include "glob_type.h"
#include "cml_ext.h"

using namespace std;

/* defines ----------------------------------------------------------------- */
// define maximum number of rows
#define SIM_MENU_ROW_MAX             100
// define maximum number of columns
#define SIM_MENU_COL_MAX             50
// define maximum column width
#define SIM_MENU_COL_WIDTH_MAX       500
// define default column width 
#define SIM_MENU_COL_WIDTH_DEFAULT   50

/* ------------------------------------------------------------------------- */
// define row activation
#define SIM_ROW_ACTIVATED            1
#define SIM_ROW_DEACTIVATED          0




/* classes ----------------------------------------------------------------- */
/************************************************************************/
/*  CSimMenuCell                                                       */
/************************************************************************/
class CSimMenuCell
{
public:
  CSimMenuCell( const string text = "", const color_e color = color_noColor, const char character = '#');
  ~CSimMenuCell();

  void      SetText(const string text);
  void      SetTextColor(const color_e color);
  void      SetCharacter(const char character);

  string    GetText() const;
  color_e   GetTextColor() const;
  char      GetCharacter() const;
  bool      IsNotEmpty() const;

protected:

private:

  string    m_text;
  color_e   m_color;
  char      m_character;
};


/************************************************************************/
/*  CSimVisuSubMenu                                                      */
/************************************************************************/
class CSimVisuSubMenu 
  : public CSimFont
  , public CSimColor
{
public:
  CSimVisuSubMenu ();
  CSimVisuSubMenu ( const string      name,
                    const char        character = '#',
                    const uint16      xPos = 0,
                    const uint16      yPos = 0,
                    const uint16      rows = 0,
                    const uint16      cols = 0,
                    const uint16      colWidth = 0
                  );
  ~CSimVisuSubMenu ();

  void save (fstream& outFile);
  void load (fstream& inFile);

  void SetContext ( const ISimRenderContext* const pContext );
  void SetPos ( const uint16 xPos, 
                const uint16 yPos
               );
  void SetRowActivation( const uint16 row, 
                         const bool   activation, 
                         const uint8  colactivation = 0
                        );
  void draw ();

  bool clickedInSubMenu ( const t_MouseInfo& mouseInfo );
  bool mouseInSubMenu ( const t_MouseInfo& mouseInfo );
  void checkRowActivation ( const t_MouseInfo& mouseInfo );
  void checkRowActivation ( const t_KeyboardInfo& keyboardInfo );
  void checkRowActivation ( const t_MouseInfo& mouseInfo, 
                            const e_MouseWheel eWheel 
                           );
  bool getItemActivation( const string rowName, const string colName = "#") const;

  void setItem(const string text, const char character = '#', const color_e textcolor = color_magenta);
  void setSubItem(const string text, const char character = '#', const color_e textcolor = color_yellow);
  void activateItem(const string itemText, const string subItemText = "#");

  void   getPos(uint16 &xPos, uint16 &yPos) const;
  char   getCharacter(void) const;
  uint16 getSubMenuHeight() const;
  uint16 getSubMenuWidth();

  uint16 getActivation( vector<uint8>& activatedRows, vector<uint16>& colActive ) const;
  string getCellText( const uint16 row, const uint16 col ) const;

  void reset();
  
protected:

private:

  void setCell( const uint16 row, const uint16 col, const string text, const color_e textcolor, const char character = '#');
  void setCell( const uint16 row, const uint16 col, const char* text, const color_e textcolor, const char character = '#');  

  void UpdateContentSize( const uint16 rows, const unsigned int cols );
  void updateMenuWidth ();
  color_e setDrawColor( const uint16 row,
                        const uint16 col
                       ) const;
  char ExtractCharFromString(const string text, const char character);
  sint16 GetRowfromString( string rowName ) const;
  sint16 GetColfromString(uint16 row, string colName ) const;

  uint16 m_xPos;      /* x postion to draw at */
  uint16 m_yPos;      /* y postion to draw at */
  uint8  m_cols;      /* number of columns */
  uint16 m_rows;      /* number of rows */
  uint16 m_colWidth;  /* width of the columns */
  uint16 m_menuWidth; /* width of widest row */
  string m_name;      /* submenu name */
  char   m_character; /* activation character of submenu*/

  uint8 m_Items;
  uint8 m_SubItems;

  bool m_widthActual; /* signalizes if m_menuWidth have to be updated */
  
  vector<vector<CSimMenuCell>> m_Content;   /* submenu content */
  vector<uint16>         m_rowColList;      /* (1 ..)list of the number of columns in a the secific row */
  vector<uint16>         m_colActive;       /* (1 ..m_rowColList-1)list of second columns to draw in specific row */
  vector<uint8>          m_activatedRows;   /* list of all by mouse or keyboard activated rows */
};

#endif /* SIM_VISU_MENUSUB_H */
