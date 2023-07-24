/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_visu_table.h

  DESCRIPTION:            Provides table class which has
                          basic table operations like setting cells, rows, etc.

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.3 $

  ---*/ /*---

**************************************************************************** */
#ifndef SIM_HLA_VISU_TABLE_H
#define SIM_HLA_VISU_TABLE_H

#include "stdafx.h"
#include <vector>
#include <string>
#include <sstream>

#include "sim_visu_color.h"
#include "sim_visu_font.h"

#include "hla_defs.h"

using namespace std;


/* defines ----------------------------------------------------------------- */
// define maximum number of rows
#define SIM_TABLE_ROW_MAX             100
// define maximum number of columns
#define SIM_TABLE_COL_MAX             50
// define maximum column width
#define SIM_TABLE_COL_WIDTH_MAX       500
// define default column width 
#define SIM_TABLE_COL_WIDTH_DEFAULT   20

// define number of column
#define COL_0                         0
#define COL_1                         1
#define COL_2                         2
#define COL_3                         3
#define COL_4                         4
#define COL_5                         5


/* classes ---------------------------------------------------------------- */
/************************************************************************/
/*  CSimTableCell                                                       */
/************************************************************************/
class CSimTableCell
{
public:
  CSimTableCell( const string text = "", const color_e color = color_noColor );
  ~CSimTableCell();

  void      SetText(const string text);
  void      SetTextColor(const color_e color);

  string    GetText();
  color_e   GetTextColor();
protected:
private:
  string    m_text;
  color_e   m_color;
};


/************************************************************************/
/*  CSimTable                                                           */
/************************************************************************/
class CSimTable
  : public CSimFont
  , public CSimColor
{
public:
  CSimTable();
  CSimTable(const unsigned int fSize, 
            const string       fName = "Arial",
            const color_e bgheader = color_light_grey,
            const color_e bgBodyEven = color_dark_grey,
            const color_e bgBodyOdd = color_grey,
            const float32 alpha = 1.0f
            );
  CSimTable(const string name,
            const uint16 xPos,
            const uint16 yPos,
            const uint16 colWidth,
            const color_e bgheader = color_light_grey,
            const color_e bgBodyEven = color_dark_grey,
            const color_e bgBodyOdd = color_grey,
            const float32 alpha = 1.0f,
            const uint16 cols = 0,
            const uint16 rows = 0
            );
  ~CSimTable();

  void SetPos ( const uint16 xPos, const uint16 yPos );

  /*template <typename T>
  void SetCell( const uint16 row, const uint16 col, const T content, const color_e textcolor );*/
  void SetCell( const uint16 row, const uint16 col);
  void SetCell( const uint16 row, const uint16 col, const string text, const color_e textcolor );
  void SetCell( const uint16 row, const uint16 col, const char* text, const color_e textcolor );
  void SetCell( const uint16 row, const uint16 col, const uint32 content, const color_e textcolor );
  void SetCell( const uint16 row, const uint16 col, const sint32 content, const color_e textcolor );
  void SetCell( const uint16 row, const uint16 col, const float32 content, const color_e textcolor );

  /* two columns */
  template <typename C0, typename C1> 
  void SetRow( const uint16 row, const color_e textcolor, const C0 col0, const C1 col1 );
  template <             typename C1> 
  void SetRow( const uint16 row, const color_e textcolor, const char* col0, const C1 col1 );
  /* three columns */
  template <typename C0, typename C1, typename C2> 
  void SetRow( const uint16 row, const color_e textcolor, const C0 col0, const C1 col1 , const C2 col2);
  template <             typename C1, typename C2> 
  void SetRow( const uint16 row, const color_e textcolor, const char* col0, const C1 col1 , const C2 col2);
  /* four columns */
  template <typename C0, typename C1, typename C2, typename C3> 
  void SetRow( const uint16 row, const color_e textcolor, const C0 col0, const C1 col1 , const C2 col2, const C3 col3);
  /* five columns */
  template <typename C0, typename C1, typename C2, typename C3, typename C4> 
  void SetRow( const uint16 row, const color_e textcolor, const C0 col0, const C1 col1 , const C2 col2, const C3 col3, const C4 col4);
  /* six columns */
  template <typename C0, typename C1, typename C2, typename C3, typename C4, typename C5> 
  void SetRow( const uint16 row, const color_e textcolor, const C0 col0, const C1 col1 , const C2 col2, const C3 col3, const C4 col4, const C5 col5);

  void draw( const ISimRenderContext* pContext, color_e frameColor = color_noColor );

  uint16 getTableHeight();
  uint16 getTableWidth();
protected:

private:

  void draw();
  void drawFrame(color_e frameColor);
  void UpdateContentSize( const uint16 rows, const uint16 cols );
  void UpdateColWidth();
  void drawRectangle(const float32 xPos,
                     const float32 yPos,
                     const float32 width,
                     const float32 height,
                     const color_e color = color_noColor,
                     const bool    filled = false,
                     const float32 alpha = 1.0f,
                     const color_e borderColor = color_noColor
                     );
  void drawText(const string text, 
                const uint16 xPos, 
                const uint16 yPos, 
                const color_e textColor 
                );
  /*void UpdateColWidth( const uint16 col, const uint16 width );*/

  float32                         m_alphaBckG;      /* transparent background */
  uint16                          m_cols;           /* number of columns */
  uint16                          m_rows;           /* number of rows */
  uint16                          m_xPos;           /* x position to draw at */
  uint16                          m_yPos;           /* y position to draw at */
  string                          m_name;           /* table name */
  uint16                          m_minColWidth;    /* minimum width of every column */
  bool                            m_widthActual;    /* signalizes if width of menu have to be updated */
  color_e                         m_bgheader;       /* backgound color of header */
  color_e                         m_bgBodyEven;     /* backgound color of even rows */
  color_e                         m_bgBodyOdd;      /* backgound color of odd rows */

  vector<vector<CSimTableCell>>   m_Content;        /* table content */
  vector<uint16>                  m_columnWidths;   /* list all column widths */

};

/************************************************************************/
/*  Set2Col                                                             */
/************************************************************************/
/* two columns */
template <typename C0, typename C1>
inline void CSimTable::SetRow( const uint16 row, const color_e textcolor, const C0 col0, const C1 col1 )
{
  SetCell(row, 0, col0, textcolor);
  SetCell(row, 1, col1, textcolor);
  return;
}
template <typename C1>
inline void CSimTable::SetRow( const uint16 row, const color_e textcolor, const char* col0, const C1 col1 )
{
  SetCell(row, 0, col0, textcolor);
  SetCell(row, 1, col1, textcolor);
  return;
}
/* three columns */
template <typename C0, typename C1, typename C2> 
inline void CSimTable::SetRow( const uint16 row, const color_e textcolor, const C0 col0, const C1 col1 , const C2 col2)
{
  SetCell(row, 0, col0, textcolor);
  SetCell(row, 1, col1, textcolor);
  SetCell(row, 2, col2, textcolor);
  return;
}
template <typename C1, typename C2> 
inline void CSimTable::SetRow( const uint16 row, const color_e textcolor, const char* col0, const C1 col1 , const C2 col2)
{
  SetCell(row, 0, col0, textcolor);
  SetCell(row, 1, col1, textcolor);
  SetCell(row, 2, col2, textcolor);
  return;
}
/* four columns */
template <typename C0, typename C1, typename C2, typename C3> 
inline void CSimTable::SetRow( const uint16 row, const color_e textcolor, const C0 col0, const C1 col1 , const C2 col2, const C3 col3 )
{
  SetCell(row, 0, col0, textcolor);
  SetCell(row, 1, col1, textcolor);
  SetCell(row, 2, col2, textcolor);
  SetCell(row, 3, col3, textcolor);
  return;
}
/* five columns */
template <typename C0, typename C1, typename C2, typename C3, typename C4> 
inline void CSimTable::SetRow( const uint16 row, const color_e textcolor, const C0 col0, const C1 col1 , const C2 col2, const C3 col3, const C4 col4 )
{
  SetCell(row, 0, col0, textcolor);
  SetCell(row, 1, col1, textcolor);
  SetCell(row, 2, col2, textcolor);
  SetCell(row, 3, col3, textcolor);
  SetCell(row, 4, col4, textcolor);
  return;
}
/* six columns */
template <typename C0, typename C1, typename C2, typename C3, typename C4, typename C5> 
inline void CSimTable::SetRow( const uint16 row, const color_e textcolor, const C0 col0, const C1 col1 , const C2 col2, const C3 col3, const C4 col4 , const C5 col5)
{
  SetCell(row, 0, col0, textcolor);
  SetCell(row, 1, col1, textcolor);
  SetCell(row, 2, col2, textcolor);
  SetCell(row, 3, col3, textcolor);
  SetCell(row, 4, col4, textcolor);
  SetCell(row, 5, col5, textcolor);
  return;
}

#endif /* SIM_HLA_VISU_TABLE_H */