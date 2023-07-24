/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_visu_table.cpp

  DESCRIPTION:            Provides table class which has
                          basic table operations like setting cells, rows, etc.

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.1 $

  ---*/ /*---

**************************************************************************** */

#include "sim_hla_visu_table.h"

/************************************************************************/
/* CSimTableCell                                                        */
/************************************************************************/
CSimTableCell::CSimTableCell( const string text, const color_e color )
{
  m_text  = text;
  m_color = color;
}

CSimTableCell::~CSimTableCell()
{

}


void CSimTableCell::SetText(const string text)
{
  m_text = text;
}
void CSimTableCell::SetTextColor(const color_e color)
{
  m_color = color;
}

string CSimTableCell::GetText()
{
  return m_text;
}
color_e CSimTableCell::GetTextColor()
{
  return m_color;
}


/************************************************************************/
/*  CSimTable                                                           */
/************************************************************************/
CSimTable::CSimTable()
: m_name("")
, m_rows(0)
, m_cols(0)
, m_xPos(0)
, m_yPos(0)
, m_minColWidth(SIM_TABLE_COL_WIDTH_DEFAULT)
, m_widthActual(true)
, m_bgheader(color_light_grey)
, m_bgBodyEven(color_dark_grey)
, m_bgBodyOdd(color_grey)
, m_alphaBckG(1.0f)
{
  UpdateContentSize(m_rows, m_cols);
  SetCell(0, 0, m_name, color_black);
}

CSimTable::CSimTable(const unsigned int fSize, 
                     const string fName /* ="Arial" */,
                     const color_e bgheader /* = color_light_grey */,
                     const color_e bgBodyEven /* = color_dark_grey */,
                     const color_e bgBodyOdd /* = color_grey */,
                     const float32 alpha /* = 1.0f */
                     )
:CSimFont(fName, fSize)
,m_name("")
, m_rows(0)
, m_cols(0)
, m_xPos(0)
, m_yPos(0)
, m_minColWidth(SIM_TABLE_COL_WIDTH_DEFAULT)
, m_widthActual(true)
, m_bgheader(bgheader)
, m_bgBodyEven(bgBodyEven)
, m_bgBodyOdd(bgBodyOdd)
, m_alphaBckG(1.0f)
{
  UpdateContentSize(m_rows, m_cols);
  SetCell(0, 0, m_name, color_black);
}

CSimTable::CSimTable(const std::string name,
                     const uint16  xPos,
                     const uint16  yPos,
                     const uint16  minColWidth,
                     const color_e bgheader /*= color_light_grey */,
                     const color_e bgBodyEven /*= color_dark_grey */,
                     const color_e bgBodyOdd /*= color_grey */,
                     const float32 alpha /*= 1.0f */,
                     const uint16  cols /*= 0 */,
                     const uint16  rows /*= 0 */)
{
  m_cols        = cols;
  m_rows        = rows;
  m_name        = name;
  m_xPos        = xPos;
  m_yPos        = yPos;
  m_minColWidth = minColWidth == 0 ? SIM_TABLE_COL_WIDTH_DEFAULT : minColWidth;
  m_widthActual = true;
  m_bgheader    = bgheader;
  m_bgBodyOdd   = bgBodyOdd;
  m_bgBodyEven  = bgBodyEven;
  m_alphaBckG   = alpha;

  m_columnWidths.resize(1);
  m_columnWidths[0] = m_minColWidth;

  UpdateContentSize(rows, cols);
  SetCell(0, 0, m_name, color_black);
}

CSimTable::~CSimTable()
{
}

/************************************************************************/
/*  SetPos                                                              */
/************************************************************************/
void CSimTable::SetPos( const uint16 xPos, const uint16 yPos )
{
  m_xPos = xPos;
  m_yPos = yPos;
}

/************************************************************************/
/*  SetCell                                                             */
/************************************************************************/
void CSimTable::SetCell( const uint16 row, const uint16 col)
{
  UpdateContentSize(row, col);
  m_Content[row][col] = CSimTableCell("",color_black);
  m_widthActual = false;
  return;
}

void CSimTable::SetCell( const uint16 row, const uint16 col, const string text, const color_e textcolor )
{
  UpdateContentSize(row, col);
  m_Content[row][col] = CSimTableCell(text,textcolor);
  m_widthActual = false;
  return;
}

void CSimTable::SetCell( const uint16 row, const uint16 col, const char* text, const color_e textcolor )
{
  UpdateContentSize(row, col);
  stringstream s;
  s << text;
  m_Content[row][col] = CSimTableCell(s.str(),textcolor);
  m_widthActual = false;
  return;
}

void CSimTable::SetCell( const uint16 row, const uint16 col, const uint32 content, const color_e textcolor )
{
    UpdateContentSize(row, col);

    /* convert content to string */
    ostringstream ss;
    string text;
    ss << content;
    text = ss.str();

    m_Content[row][col] = CSimTableCell(text,textcolor);
    m_widthActual = false;
    return;
};

void CSimTable::SetCell( const uint16 row, const uint16 col, const sint32 content, const color_e textcolor )
{
    UpdateContentSize(row, col);

    /* convert content to string */
    ostringstream ss;
    string text;
    ss << content;
    text = ss.str();

    m_Content[row][col] = CSimTableCell(text,textcolor);
    m_widthActual = false;
    return;
};

void CSimTable::SetCell( const uint16 row, const uint16 col, const float32 content, const color_e textcolor )
{
    UpdateContentSize(row, col);

    /* convert content to string */
    ostringstream ss;
    string text;
    ss << content;
    text = ss.str();

    m_Content[row][col] = CSimTableCell(text,textcolor);
    m_widthActual = false;
    return;
};

/************************************************************************/
/*  draw                                                             */
/************************************************************************/
void CSimTable::draw( const ISimRenderContext* pContext, color_e frameColor /* = color_noColor */ )
{
  SetFontContext(*pContext);
  draw();
  if(frameColor != color_noColor)
  {
    drawFrame(frameColor);
  }
}

void CSimTable::draw()
{
  color_e color;
  uint16 yPos = m_yPos;
  uint16 xPos = m_xPos;

  /* check if header available */
  if(strcmp(m_Content[0][0].GetText().c_str(),"")!= 0)
  {
    /* draw header */
    for (uint16 row = 0; row < 1; row++)
    {
      drawRectangle((float32)xPos,(float32)yPos, (float32)(getTableWidth()), (float32)(GetTextHeight()), m_bgheader, TRUE, m_alphaBckG );
      uint16 colWidthSum = 0;
      for (uint16 col = 0; col < m_cols; col++)
      {
        CSimTableCell cell = m_Content[row][col];
        if(strcmp(cell.GetText().c_str(),"")!= 0)
        {
          drawText( cell.GetText() , xPos + 5 + colWidthSum, yPos, cell.GetTextColor() );
        }
        colWidthSum += m_columnWidths[col];
      }
      yPos += GetTextHeight();
    }
  }
  /* draw body */
  for (uint16 row = 1; row < m_rows; row++)
  {
    uint16 colWidthSum = 0;
    if (row%2 == 0)
    {
      color = m_bgBodyEven;
    }
    else
    {
      color = m_bgBodyOdd;
    }
    drawRectangle( (float32)xPos, (float32)yPos, (float32)(getTableWidth()),(float32)(GetTextHeight()), color, TRUE, m_alphaBckG);
    for (uint16 col = 0; col < m_cols; col++)
    {
      CSimTableCell cell = m_Content[row][col];
      if(strcmp(cell.GetText().c_str(),"")!= 0)
      {
        drawText( cell.GetText() , xPos + 5 + colWidthSum, yPos, cell.GetTextColor() );
      }
      colWidthSum += m_columnWidths[col];
    }
    yPos += GetTextHeight();
  }
}

/************************************************************************/
/* getTableHeight                                                       */
/************************************************************************/
uint16 CSimTable::getTableHeight()
{
  /* check if header available */
  if(strcmp(m_Content[0][0].GetText().c_str(),"")!= 0)
  {
    return m_rows * GetTextHeight(); 
  }
  else
  {
    return (m_rows-1) * GetTextHeight();
  }
}

/************************************************************************/
/* getTableWidth                                                       */
/************************************************************************/
uint16 CSimTable::getTableWidth()
{
  if (m_widthActual == false)
  {
    UpdateColWidth();
  }
  uint16 tmpTableWidth = 0u;
  for(uint16 col = 0u; col < m_cols; col++)
  {
    tmpTableWidth += m_columnWidths[col];
  }

  /* Add another 3 pixels to make right border a bit smoother */
  tmpTableWidth += 3u;

  return tmpTableWidth;
}

/************************************************************************/
/* UpdateContentSize                                                    */
/************************************************************************/
void CSimTable::UpdateContentSize( const uint16 rows, const uint16 cols )
{
  uint16 incRows = rows > SIM_TABLE_ROW_MAX ? SIM_TABLE_ROW_MAX : rows+1;
  uint16 incCols = cols > SIM_TABLE_COL_MAX ? SIM_TABLE_COL_MAX : cols+1;

  // new row added
  if ( m_rows < incRows )
  {
    // resize number of rows
    m_Content.resize(incRows);
    m_rows = incRows;
    // resize number of columns to align with all rows
    m_Content[incRows-1].resize(m_cols);
  }
  // number of columns increased
  if ( m_cols < incCols )
  {
    for (uint16 r = 0; r < m_rows; r++)
    {
      // align all columns
      m_Content[r].resize(incCols);
      // align colWidth
      m_columnWidths.resize(incCols);
      m_columnWidths[incCols-1] = m_minColWidth;
    }
    m_cols = incCols;
  }
}

/************************************************************************/
/* UpdateColWidth                                                       */
/************************************************************************/
void CSimTable::UpdateColWidth ()
{
  m_widthActual = true;
  for(uint16 row = 0; row < m_Content.size(); row++)
  {
    for(uint16 col = 0; col < m_Content[row].size(); col++)
    {
      uint16 tmpColWidth = GetTextWidth(m_Content[row][col].GetText()) + 5;
      if (m_columnWidths[col] < tmpColWidth)
      {
        m_columnWidths[col] = tmpColWidth;
      }
    }
  }
  return;
}

/************************************************************************/
/* DrawRectangle                                                        */
/************************************************************************/
void CSimTable::drawRectangle( const float32 xPos,
                               const float32 yPos,
                               const float32 width,
                               const float32 height,
                               const color_e color /*= color_noColor*/,
                               const bool    filled /*= FALSE*/,
                               const float32 alpha /*= 1.0f*/,
                               const color_e borderColor /*= color_noColor*/)
{
  GLfloat top_left_x = xPos;
  GLfloat top_left_y = yPos;
  GLfloat top_right_x = xPos + width;
  GLfloat top_right_y = top_left_y;
  GLfloat bottom_right_x = top_right_x;
  GLfloat bottom_right_y = yPos + height;
  GLfloat bottom_left_x = top_left_x;
  GLfloat bottom_left_y = bottom_right_y;

  uint16 mode = GL_LINE_LOOP;
  if(filled == TRUE)
  {
    mode = GL_QUADS;
  }
  SetColor(color, alpha);
  glBegin(mode);
  glVertex3d(top_left_x, top_left_y,2);
  glVertex3d( top_right_x, top_right_y,2);
  glVertex3d( bottom_right_x,bottom_right_y,2);
  glVertex3d(bottom_left_x,bottom_left_y,2);
  glVertex3d(top_left_x, top_left_y,2);
  glEnd();

  /* draw border */
  if( borderColor != color_noColor )
  {
    SetColor(borderColor);
    glBegin(GL_LINE_LOOP);
    glVertex3d(top_left_x, top_left_y,2);
    glVertex3d( top_right_x, top_right_y,2);
    glVertex3d( bottom_right_x,bottom_right_y,2);
    glVertex3d(bottom_left_x,bottom_left_y,2);
    glVertex3d(top_left_x, top_left_y,2);
    glEnd();
  }
  
}

/************************************************************************/
/* drawText                                                             */
/************************************************************************/
void CSimTable::drawText( const string text, const uint16 xPos, const uint16 yPos, const color_e textColor )
{
  float red, green, blue;
  IGDVFont& font = (IGDVFont&)*GetFont();

  ConvertColor(textColor, red, green, blue);
  font.BeginRender2D();
  font.SetTextColor((GLdouble)red, (GLdouble)green, (GLdouble)blue, (GLdouble)1);
  font.RenderText(text.c_str(), (GLdouble)xPos, (GLdouble)yPos, (GLdouble)0);
  font.EndRender2D();
}

/************************************************************************/
/*  drawFrame                                                           */
/************************************************************************/
void CSimTable::drawFrame(color_e frameColor)
{
  drawRectangle((float32)m_xPos-1,(float32)m_yPos-1, (float32)(getTableWidth())+1, (float32)(getTableHeight())+1, color_noColor, false, 1.0f, frameColor );
}