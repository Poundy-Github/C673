/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_visu_menu.cpp

  DESCRIPTION:            Providing menu utilities like (de-)activating items, store and load configuration, etc.

  CPU:                    Independent

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.4 $

  ---*/ /*---

**************************************************************************** */

#include <sstream>
#include "sim_visu_menusub.h"

/************************************************************************/
/* CSimMenuCell                                                        */
/************************************************************************/
CSimMenuCell::CSimMenuCell( const string text, const color_e color, const char character )
{
  m_text  = text;
  m_color = color;
  m_character = character;
}

CSimMenuCell::~CSimMenuCell()
{

}

void CSimMenuCell::SetText(const string text)
{
  m_text = text;
}
void CSimMenuCell::SetTextColor(const color_e color)
{
  m_color = color;
}
void CSimMenuCell::SetCharacter(const char character)
{
  m_character = character;
}

string CSimMenuCell::GetText() const
{
  return m_text;
}
color_e CSimMenuCell::GetTextColor() const
{
  return m_color;
}
char CSimMenuCell::GetCharacter() const
{
  return m_character;
}

bool CSimMenuCell::IsNotEmpty() const
{
  return !(m_text.empty());
}


/************************************************************************/
/*  CSimVisuSubMenu                                                   */
/************************************************************************/
CSimVisuSubMenu::CSimVisuSubMenu()
: CSimFont("Arial", 7)
, m_name("")
, m_rows(0)
, m_cols(0)
, m_xPos(0)
, m_yPos(0)
, m_Items(0)
, m_SubItems(0)
, m_character('#')
, m_menuWidth(0)
, m_colWidth(SIM_MENU_COL_WIDTH_DEFAULT)
, m_widthActual(false)
{
  UpdateContentSize(m_rows, m_cols);
  setCell(0,0, m_name, color_black);
}

CSimVisuSubMenu::CSimVisuSubMenu( const std::string name,
                                  const char        character, /* '#' */
                                  const uint16      xPos, /* = 0 */
                                  const uint16      yPos, /* = 0 */
                                  const uint16      rows, /* = 0*/
                                  const uint16      cols, /* =0 */
                                  const uint16      colWidth /* = 0*/)
: CSimFont("Arial", 7)
, m_widthActual(false)
{
  m_rows        = 0;
  m_cols        = 0;
  m_menuWidth   = 0;
  m_Items       = 0;
  m_SubItems    = 0;
  m_colWidth    = colWidth == 0 ? SIM_MENU_COL_WIDTH_DEFAULT : colWidth;
  m_name        = name;
  m_xPos        = xPos;
  m_yPos        = yPos;
  m_character = ExtractCharFromString(name, character);

  UpdateContentSize(rows, cols);
  setCell(0, 0, m_name, color_green, m_character);
  /* Activate menu by default */
  SetRowActivation(0, SIM_ROW_ACTIVATED);
}

CSimVisuSubMenu::~CSimVisuSubMenu()
{
}

/************************************************************************/
/* save                                                                 */
/************************************************************************/
void CSimVisuSubMenu::save (fstream &outFile)
{
  outFile.write(reinterpret_cast<const char *>(&m_rowColList[0]), sizeof(m_rowColList[0])*m_rowColList.size());

  outFile.write(reinterpret_cast<const char *>(&m_colActive[0]), sizeof(m_colActive[0])*m_colActive.size());

  outFile.write(reinterpret_cast<const char *>(&m_activatedRows[0]), sizeof(m_activatedRows[0])*m_activatedRows.size());

  return;
}

/************************************************************************/
/* load                                                               */
/************************************************************************/
void CSimVisuSubMenu::load (fstream &inFile)
{
  inFile.read((char *)(&m_rowColList[0]), sizeof(m_rowColList[0])*m_rows);

  inFile.read((char *)(&m_colActive[0]), sizeof(m_colActive[0])*m_rows);

  inFile.read((char *)(&m_activatedRows[0]), sizeof(m_activatedRows[0])*m_rows);

  return;
}

/************************************************************************/
/* SetContext                                                           */
/************************************************************************/
void CSimVisuSubMenu::SetContext( const ISimRenderContext* const pContext )
{
  SetFontContext(*pContext);
}

/************************************************************************/
/* draw                                                                 */
/************************************************************************/
void CSimVisuSubMenu::draw()
{
  unsigned int yPos = m_yPos;
  unsigned int xPos = m_xPos;

  for (unsigned int row = 0; row < m_rows; row++)
  {
    unsigned int colWidthSum = 0;
    for(uint16 col = 0; col < std::min(2, (int)m_rowColList[row]); col++)
    {
      CSimMenuCell cell;
      color_e drawColor;
      if(col > 0)
      {
        cell = m_Content[row][m_colActive[row]];
        drawColor = setDrawColor(row,m_colActive[row]);
      }
      else
      {
        cell = m_Content[row][col];
        drawColor = setDrawColor(row,col);
      }
      if(cell.IsNotEmpty())
      {
        IGDVFont& font = (IGDVFont&)*GetFont();

        font.BeginRender2D();
        SetTextColor(drawColor, font);
        font.RenderTextf((GLdouble)xPos +5 +colWidthSum , (GLdouble)yPos, (GLdouble)0, cell.GetText().c_str());
        font.EndRender2D();
      }
      colWidthSum += m_colWidth;
    }
    yPos += GetTextHeight();
  }
  return;
}

/************************************************************************/
/* clickedInSubMenu                                                     */
/************************************************************************/
bool CSimVisuSubMenu::clickedInSubMenu( const t_MouseInfo& mouseInfo )
{
  sint16 Y1 = mouseInfo.singleClickLeft.y - m_yPos;
  sint16 X1 = mouseInfo.singleClickLeft.x - m_xPos;
  uint16 y2 = getSubMenuHeight();
  uint16 X2 = getSubMenuWidth();

  if(   (Y1 >  0)
      &&(Y1 < y2)
      &&(X1 >  0)
      &&(X1 < X2)
    )
  {
    return true;
  }
  else
  {
    return false;
  }
}

/************************************************************************/
/* mouseInSubMenu                                                       */
/************************************************************************/
bool CSimVisuSubMenu::mouseInSubMenu( const t_MouseInfo& mouseInfo )
{
  sint16 Y1 = mouseInfo.current.y - m_yPos;
  sint16 X1 = mouseInfo.current.x - m_xPos;
  uint16 y2 = getSubMenuHeight();
  uint16 X2 = getSubMenuWidth();

  if(   (Y1 >  0)
      &&(Y1 < y2)
      &&(X1 >  0)
      &&(X1 < X2)
    )
  {
    return true;
  }
  else
  {
    return false;
  }
}

/************************************************************************/
/* checkRowActivation                                                   */
/************************************************************************/
void CSimVisuSubMenu::checkRowActivation( const t_MouseInfo& mouseInfo )
{
  sint16 mouseY = mouseInfo.singleClickLeft.y - m_yPos;
  uint16 activateRow = CML_u_Round2Uint( CML_f_Floor((float32)mouseY/(float32)GetTextHeight()) );
  
  if(activateRow == 0)
  {
    if(m_activatedRows[0] == SIM_ROW_ACTIVATED)
    {
      m_activatedRows.assign(m_activatedRows.size(),SIM_ROW_DEACTIVATED);
      m_colActive.assign(m_colActive.size(),1);
    }
    else
    {
      m_activatedRows[0] = SIM_ROW_ACTIVATED;
    }
  }
  else
  {
  /* update list of clicked sub rows */
    if(m_activatedRows[0] == SIM_ROW_ACTIVATED)
    {
      for (uint16 row = 1; row < m_activatedRows.size(); row++)
      {
        if(row == activateRow)
        {
          if( m_rowColList[row] > 1)
          {
            m_colActive[row] = (m_colActive[row] >= (m_rowColList[row]-1) ) ? 1 : (++m_colActive[row]);
            /* check column content */
            m_activatedRows[row] = m_Content[row][m_colActive[row]].IsNotEmpty(); // matching SIM_ROW_ACTIVATED and SIM_ROW_DEACTIVATED
          }
          else
          {
            if(m_activatedRows[row] == SIM_ROW_DEACTIVATED)
            {
              m_activatedRows[row] = SIM_ROW_ACTIVATED;
            }
            else
            {
              m_activatedRows[row] = SIM_ROW_DEACTIVATED;
            }
          }
        }
      }
    }
  }
  return;
}

void CSimVisuSubMenu::checkRowActivation( const t_KeyboardInfo& keyboardInfo )
{
  if(keyboardInfo.character == m_Content[0][0].GetCharacter())
  {
    if(m_activatedRows[0] == SIM_ROW_ACTIVATED)
    {
      m_activatedRows.assign(m_activatedRows.size(),SIM_ROW_DEACTIVATED);
      m_colActive.assign(m_colActive.size(),1);
    }
    else
    {
      m_activatedRows[0] = SIM_ROW_ACTIVATED;
    }
  }
  else
  {
    if(m_activatedRows[0] == SIM_ROW_ACTIVATED)
    {
      for (uint16 row = 1; row < m_activatedRows.size(); row++)
      {
        if(keyboardInfo.character == m_Content[row][0].GetCharacter())
        {
          if( m_rowColList[row] > 1)
          {
            m_colActive[row] = (m_colActive[row] >= (m_rowColList[row]-1) ) ? 1 : (++m_colActive[row]);
            /* check column content */
            m_activatedRows[row] = m_Content[row][m_colActive[row]].IsNotEmpty(); // matching SIM_ROW_ACTIVATED and SIM_ROW_DEACTIVATED
          }
          else
          {
            if(m_activatedRows[row] == SIM_ROW_DEACTIVATED)
            {
              m_activatedRows[row] = SIM_ROW_ACTIVATED;
            }
            else
            {
              m_activatedRows[row] = SIM_ROW_DEACTIVATED;
            }
          }
        }
        /* if you want to go back with upper case */
        //else if((uint8)keyboardInfo.character + 32 == (uint8)m_Content[row][0].GetCharacter())
        //{
        //  if( m_rowColList[row] > 1)
        //  {
        //    m_colActive[row] = (m_colActive[row] <= 1 ) ? (m_rowColList[row]-1) : (--m_colActive[row]);
        //    /* check column content */
        //    m_activatedRows[row] = m_Content[row][m_colActive[row]].IsNotEmpty(); // matching SIM_ROW_ACTIVATED and SIM_ROW_DEACTIVATED
        //  }
        //  else
        //  {
        //    if(m_activatedRows[row] == SIM_ROW_DEACTIVATED)
        //    {
        //      m_activatedRows[row] = SIM_ROW_ACTIVATED;
        //    }
        //    else
        //    {
        //      m_activatedRows[row] = SIM_ROW_DEACTIVATED;
        //    }
        //  }
        //}

      }
    }
  }
}

void CSimVisuSubMenu::checkRowActivation( const t_MouseInfo& mouseInfo, 
                                          const e_MouseWheel eWheel 
                                         )
{
  sint16 mouseY = mouseInfo.current.y - m_yPos;
  uint16 activateRow = CML_u_Round2Uint( CML_f_Floor((float32)mouseY/(float32)GetTextHeight()) );
  
  if(activateRow == 0)
  {
    if(m_activatedRows[0] == SIM_ROW_ACTIVATED)
    {
      m_activatedRows.assign(m_activatedRows.size(),SIM_ROW_DEACTIVATED);
      m_colActive.assign(m_colActive.size(),1);
    }
    else
    {
      m_activatedRows[0] = SIM_ROW_ACTIVATED;
    }
  }
  else
  {
  /* update list of clicked sub rows */
    if(m_activatedRows[0] == SIM_ROW_ACTIVATED)
    {
      for (uint16 row = 1; row < m_activatedRows.size(); row++)
      {
        if(row == activateRow)
        {
          if( m_rowColList[row] > 1)
          {
            if(eWheel == eWheelUp)
            {
              m_colActive[row] = (m_colActive[row] >= (m_rowColList[row]-1) ) ? 1 : (++m_colActive[row]);
            }
            else
            {
              m_colActive[row] = (m_colActive[row] <= 1 ) ? (m_rowColList[row]-1) : (--m_colActive[row]);
            }
            /* check column content */
            m_activatedRows[row] = m_Content[row][m_colActive[row]].IsNotEmpty(); // matching SIM_ROW_ACTIVATED and SIM_ROW_DEACTIVATED
          }
          else
          {
            if(m_activatedRows[row] == SIM_ROW_DEACTIVATED)
            {
              m_activatedRows[row] = SIM_ROW_ACTIVATED;
            }
            else
            {
              m_activatedRows[row] = SIM_ROW_DEACTIVATED;
            }
          }
        }
      }
    }
  }
  return;
}

/************************************************************************/
/* setItem                                                              */
/************************************************************************/
void CSimVisuSubMenu::setItem(const string text, const char character, const color_e textcolor)
{
  size_t i = 0;
  char found_character = ExtractCharFromString(text, character);

  /* increase item counter */
  m_Items++;
  /* reset subitem counter, since new item is created */
  m_SubItems = 0;

  /* create cell */
  setCell(m_Items, m_SubItems, text, textcolor, found_character);

}

void CSimVisuSubMenu::activateItem(const string itemText, const string subItemText)
{
  sint16 row = GetRowfromString(itemText);
  sint16 col = -1;

  /* row was found */
  if (row >= 0)
  {
    /* activate row */
    SetRowActivation((uint16)row, SIM_ROW_ACTIVATED);
    /* search for column; in case no subItemText was set -1 will be returned*/
    col = GetColfromString((uint16)row, subItemText);
  }

  /* column was found*/
  if (col >= 0)
  {
    /* activate column */
    SetRowActivation((uint16)row, SIM_ROW_ACTIVATED, (uint8)col);
  }
}

char CSimVisuSubMenu::ExtractCharFromString(const string text, const char character)
{
  size_t i = 0;
  char found_character = '#';

  /* if no character was set, search for activation character in string */
  if (character == '#')
  {
    /* search for open bracket */
    i = text.find("[");

    /* open bracket is not at end of string */
    if(i+1 <= text.length())
    {
      /* character after open bracket becomes the activation character*/
      found_character = text.at(i+1);
    }
  }
  else
  {
    /* use specified character*/
    found_character = character;
  }

  return found_character;
}

/************************************************************************/
/* setSubItem                                                              */
/************************************************************************/
void CSimVisuSubMenu::setSubItem(const string text, const char character, const color_e textcolor)
{
  /* increase sub item counter*/
  m_SubItems++;

  /* set cell */
  setCell(m_Items, m_SubItems, text, textcolor, character);
}

/************************************************************************/
/* setCell                                                              */
/************************************************************************/
void CSimVisuSubMenu::setCell( const uint16 row, const uint16 col, const string text, const color_e textcolor, const char character )
{
  UpdateContentSize(row, col);
  m_Content[row][col] = CSimMenuCell(text,textcolor, character);
  m_widthActual = false;
  return;
}

void CSimVisuSubMenu::setCell( const uint16 row, const uint16 col, const char* text, const color_e textcolor, const char character )
{
  UpdateContentSize(row, col);
  stringstream s;
  s << text;
  m_Content[row][col] = CSimMenuCell(s.str(),textcolor, character);
  m_widthActual = false;
  return;
}

/************************************************************************/
/* SetPos                                                               */
/************************************************************************/
void CSimVisuSubMenu::SetPos ( const uint16 xPos,
                               const uint16 yPos
                              )
{
  m_xPos = xPos;
  m_yPos = yPos;
  return;
}

/************************************************************************/
/* SetRowActivation                                                     */
/************************************************************************/
void CSimVisuSubMenu::SetRowActivation( const uint16 row, 
                                        const bool   activation, 
                                        const uint8  colactivation /* = 0 */
                                       )
{
  m_activatedRows[row] = (activation) ? 1 : 0;
  if(  (m_rowColList[row] > 1)
     &&(colactivation     > 0)
     &&(colactivation     < m_rowColList[row])
     )
  {
    m_colActive[row] = (activation) ? colactivation : 1;
  }
}

/************************************************************************/
/* getPos                                                               */
/************************************************************************/
void CSimVisuSubMenu::getPos(uint16 &xPos, uint16 &yPos) const
{ 
  xPos = m_xPos;
  yPos = m_yPos;
  return;
}

/************************************************************************/
/* getPos                                                               */
/************************************************************************/
char CSimVisuSubMenu::getCharacter(void) const
{ 
  return m_character;
}

/************************************************************************/
/* getSubMenuHeight                                                     */
/************************************************************************/
uint16 CSimVisuSubMenu::getSubMenuHeight() const
{ 
  return m_rows * GetTextHeight(); 
}

/************************************************************************/
/* getSubMenuWidth                                                      */
/************************************************************************/
uint16 CSimVisuSubMenu::getSubMenuWidth()
{
  if (m_widthActual == false)
  {
    updateMenuWidth();
  }
  return m_menuWidth;
}

/************************************************************************/
/* getActivation                                                        */
/************************************************************************/
uint16 CSimVisuSubMenu::getActivation( vector<uint8>& activatedRows, vector<uint16>& colActive ) const
{
  activatedRows = m_activatedRows;
  colActive = m_colActive;
  return m_rows;
}

/************************************************************************/
/* GetRowfromString                                                     */
/************************************************************************/
sint16 CSimVisuSubMenu::GetRowfromString( string rowName ) const
{
  /* loop through all elements of content vector */
  for (unsigned row=0; row<m_Content.size(); row++)
  {
    /* find position of row name*/
    if (m_Content[row][0].GetText().compare(rowName) == 0)
    {
      return row;
    }
  }

  return -1;
}

/************************************************************************/
/* GetColfromString                                                     */
/************************************************************************/
sint16 CSimVisuSubMenu::GetColfromString(uint16 row, string colName ) const
{
  for(unsigned col=0; col<m_Content[row].size(); col++)
  {
    string test = m_Content[row][col].GetText();
    if (m_Content[row][col].GetText().compare(colName) == 0)
    {
      return col;
    }
  }
  return -1;
}

/************************************************************************/
/* getItemActivation                                                    */
/************************************************************************/
bool CSimVisuSubMenu::getItemActivation( const string rowName, const string colName ) const
{
  sint16 row = GetRowfromString(rowName);
  sint16 col = -1;

  if (row >= 0)
  {
    /* return true if it is activated */
    if (m_activatedRows[row] == 1)
    {
      if (colName.compare("#") == 0)
      {
        return true;
      }
      else
      {
        col = GetColfromString(row, colName);
        if (col >= 0)
        {
          if (m_colActive[row] == col)
          {
            return true;
          }
        }
      }
    }
  }

  return false;
}

/************************************************************************/
/* getCellText                                                          */
/************************************************************************/
string CSimVisuSubMenu::getCellText( const uint16 row, const uint16 col ) const
{
  return m_Content[row][col].GetText();
}

/************************************************************************/
/* reset                                                      */
/************************************************************************/
void CSimVisuSubMenu::reset ()
{
  m_activatedRows.assign(m_activatedRows.size(),SIM_ROW_DEACTIVATED);
  m_colActive.assign(m_colActive.size(),1);
  /* Activate menu by default */
  SetRowActivation(0, SIM_ROW_ACTIVATED);
}

/************************************************************************/
/* UpdateContentSize                                                    */
/************************************************************************/
void CSimVisuSubMenu::UpdateContentSize ( const uint16 rows, const unsigned int cols )
{

  uint16 incRows = rows > SIM_MENU_ROW_MAX ? SIM_MENU_ROW_MAX : rows+1;
  uint16 incCols = cols > SIM_MENU_COL_MAX ? SIM_MENU_COL_MAX : cols+1;
  // new row added
  if ( m_rows < incRows )
  {
    // resize number of rows
    m_Content.resize(incRows);
    m_Content[incRows-1].resize(incCols);
    m_activatedRows.resize(incRows);
    m_rowColList.resize(incRows);
    m_colActive.resize(incRows);
    m_rowColList[incRows-1] = incCols;
    m_colActive[incRows-1] = 1;//incCols-1;
    m_rows = incRows;
  }
  else if( m_rowColList[incRows-1] < incCols )
  {
    m_Content[incRows-1].resize(incCols);
    m_rowColList[incRows-1] = incCols;
    m_colActive[incRows-1] = 1; //incCols-1;
  }
  return;
}

/************************************************************************/
/* updateMenuWidth                                                      */
/************************************************************************/
void CSimVisuSubMenu::updateMenuWidth ()
{
  m_widthActual = true;
  bool tmpTwoCol = false;
  for(uint16 row = 0; row < m_Content.size(); row++)
  {
    for(uint16 col = 0; col < m_Content[row].size(); col++)
    {
      if (col == 0)
      {
        uint16 tmpWidth = GetTextWidth(m_Content[row][col].GetText()) + 5;
        if ( m_colWidth < tmpWidth)
        {
          m_colWidth = tmpWidth;
        }
      }
      else
      {
        tmpTwoCol = true;
        uint16 tmpWidth = GetTextWidth(m_Content[row][col].GetText()) + m_colWidth;
        if ( m_menuWidth < tmpWidth)
        {
          m_menuWidth = tmpWidth;
        }
      }
    }
  }
  if(tmpTwoCol == false)
  {
    m_menuWidth = m_colWidth;
  }
  return;
}

/************************************************************************/
/* setDrawColor                                                      */
/************************************************************************/
color_e CSimVisuSubMenu::setDrawColor( const uint16 row, 
                                       const uint16 col
                                      ) const
{
  color_e drawColor;
  if(row == 0)
  {
    if(m_activatedRows[0] == SIM_ROW_DEACTIVATED)
    {
      drawColor = color_red;
    }
    else
    {
      drawColor = color_green;
    }
  }
  else
  {
    if(m_activatedRows[0] == SIM_ROW_DEACTIVATED)
    {
      drawColor= color_black;
    }
    else if(m_activatedRows[row] == SIM_ROW_ACTIVATED)
    {
      drawColor = m_Content[row][col].GetTextColor();
    }
    else
    {
      drawColor = color_red;
    }
  }
  return drawColor;
}

