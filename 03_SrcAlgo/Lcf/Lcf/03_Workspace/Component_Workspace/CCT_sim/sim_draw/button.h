#ifndef button_h__
#define button_h__

#include "geometric_tools.h"

#include "sim_swc_draw_base.h"
#include "sim_gl_tools.h"
#include "sim_gl_rgbacolor.h"

#include <sstream>

#ifdef GEOMETRIC_TOOLS_INTFVER
#if GEOMETRIC_TOOLS_INTFVER >= 1

#define BUTTON_INTFVER 1

// A simple button class that reacts to the cursor position of the mouse and the left mouse button clicking if the mouse state is provided.
class Button
{
public:
  static const int VIS_IDLE_CALL_COUNT = 2; ///< Number of vis calls that should be skipped, if set to 1 the mouseState gets updated to quickly while clicking.

  enum ButtonStyle
  {
    CIRCLE,       ///< Circular button.
    SOLID_CIRCLE, ///< Filled circular button.
    SQUARE,       ///< Squared button.
    SOLID_SQUARE, ///< Filled squared button.
    NONE          ///< No button form (just a clickable symbol/string).
  };

  explicit Button()
  {
    reset();
  }

  /// Reset button members to default values, i.e. status is deactivated, form is None etc.
  void reset()
  {
    // defaults
    m_isActivated      = false;
    m_isButtonStyleSet = false;
    m_isPositionSet    = false;
    m_symbol           = "";
    m_toolTip          = "";
    m_buttonStyle      = NONE;
    m_buttonFontSize   = 0.0F;
    m_buttonRadius     = 0.0F;
    m_centerX          = 0.0F;
    m_centerY          = 0.0F;
    m_idleCounter      = 0;
  }

  /// Sets the buttons center position in pixel coordinates.
  /// @param[in] centerX The x coordinate of the buttons center.
  /// @param[in] centerY The y coordinate of the buttons center.
  void setPosition(const float32 centerX, const float32 centerY)
  {
    m_centerX       = centerX;
    m_centerY       = centerY;
    m_isPositionSet = true;
  }

  /// Checks if the position of the button has been set already.
  //// @return True if the button position has been set already, false otherwise.
  bool isPositionSet()
  {
    return m_isPositionSet;
  }

  /// Sets the buttons style, i.e. radius, symbol and form.
  /// @param[in] buttonRadius The radius of the button in pixel.
  /// @param[in] buttonRadius The radius of the button in pixel.
  /// @param[in] symbol       The symbol of the button as a string.
  /// @param[in] buttonStyle  The style or form of the button, i.e. circular or squared.
  /// @param[in] toolTip The tooltip to be displayed when hovering over the button.
  void setButtonStyle(const float32 buttonRadius, const float32 buttonFontSize, std::string symbol, ButtonStyle buttonStyle,std::string toolTip = "")
  {
    m_buttonRadius     = buttonRadius;
    m_buttonFontSize   = buttonFontSize;
    m_symbol           = symbol;
    m_buttonStyle      = buttonStyle;
    m_isButtonStyleSet = true;
    if(!toolTip.empty())
    {
      m_toolTip = toolTip;
    }
  }

  /// Checks if the button style has been set already.
  //// @return True if the button style has been set already, false otherwise.
  bool isButtonStyleSet()
  {
    return m_isButtonStyleSet;
  }

  /// Returns the status of the button.
  /// @return True if the button status is active, else false.
  const bool isActivated()
  {
    return m_isActivated;
  }

  /// Checks if the cursor is hovering over the button.
  /// @param[in] cursorPositionX The current cursor x position.
  /// @param[in] cursorPositionY The current cursor y position.
  /// @return True if the mouse is hovering over the button, else false.
  const bool isCursorHovering(int cursorPositionX, int cursorPositionY)
  {
    if( (cml::sqrt( cml::pow<2>(cursorPositionX - m_centerX) + cml::pow<2>(cursorPositionY - m_centerY) ) <= m_buttonRadius) )
    {
      m_isHovering = true;
    }
    else
    {
      m_isHovering = false;
    }
    return m_isHovering;
  }

  /// Prints a tooltip if the cursor is hovering over the button.
  /// @param[in] ctx             Sim render context.
  /// @param[in] cursorPositionX The current cursor x position.
  /// @param[in] cursorPositionY The current cursor y position.
  void printToolTipIfHovering(const ISimRenderContext& ctx, int cursorPositionX, int cursorPositionY)
  {
    if(isCursorHovering(cursorPositionX, cursorPositionY))
    {
      const set::gl::RGBAColor colorText(1.0F, 1.0F, 1.0F, 0.9F);
      IGDVFont& detailsFont = ctx.GetWindow().GetFontInterface("Arial", 8);

      const float32 lineWidth  = static_cast<float32>(detailsFont.GetTextWidth( m_toolTip.c_str()));
      const float32 lineHeight = static_cast<float32>(detailsFont.GetTextHeight(m_toolTip.c_str()));
      detailsFont.BeginRender();
      {
        detailsFont.SetTextColor(colorText.r, colorText.g, colorText.b, colorText.a);
        const float32 posX = -0.5F * lineWidth;
        const float32 posY = 0.5F * lineHeight;
        detailsFont.RenderText(m_toolTip.c_str(), posX + cursorPositionX + 40.0F, posY + cursorPositionY - 25.0F, 0);
      }
      detailsFont.EndRender();
    }
  }

  /// Updates the button status, i.e. if the button is activated or not.
  /// @note The updating checks for an idle counter to prevent to quick updating.
  /// @param[in] cursorPositionX        The current cursor x position.
  /// @param[in] cursorPositionY        The current cursor y position.
  /// @param[in] mouseStateLeftClicking The clicking state of the left mouse button.
  void updateButtonStatus(int cursorPositionX, int cursorPositionY, bool mouseStateLeftClicking)
  {
    if(isCursorHovering(cursorPositionX, cursorPositionY) && mouseStateLeftClicking && (m_idleCounter == 0))
    {
      m_isActivated = !m_isActivated;
    }
    m_idleCounter++;

    if(m_idleCounter > VIS_IDLE_CALL_COUNT)
    {
      m_idleCounter = 0;
    }
  }

  /// Redraws the button to show if the button is active or inactive.
  /// @note Call updateButtonStatus before redrawing the button to update the button status first.
  /// @param[in] ctx                 Sim render context.
  /// @param[in] colorSymbolActive   The color of the buttons symbol, if the button is active.
  /// @param[in] colorSymbolInActive The color of the buttons symbol, if the button is inactive.
  /// @param[in] colorButtonActive   The color of the buttons style, if the button is active.
  /// @param[in] colorButtonInactive The color of the buttons style and symbol, if the button is inactive.
  void redrawButton(const ISimRenderContext& ctx, const set::gl::RGBAColor colorSymbolActive, const set::gl::RGBAColor colorSymbolInActive, const set::gl::RGBAColor colorButtonActive, const set::gl::RGBAColor colorButtonInactive)
  {
    const float32 lineWidthActive   = 2.0F;
    const float32 lineWidthInactive = 1.0F;

    if(m_isActivated)
    {
      switch(m_buttonStyle)
      {
      case CIRCLE:
        {
          drawCircle(m_centerX, m_centerY, m_buttonRadius, lineWidthActive, colorButtonActive);
        }
        break;
      case SOLID_CIRCLE:
        {
          drawSolidCircle(m_centerX, m_centerY, m_buttonRadius, lineWidthActive, colorButtonActive);
        }
        break;
      case SQUARE:
        {
          drawSquare(m_centerX, m_centerY, m_buttonRadius, lineWidthActive, colorButtonActive);
        }
        break;
      case SOLID_SQUARE:
        {
          drawSolidSquare(m_centerX, m_centerY, m_buttonRadius, lineWidthActive, colorButtonActive);
        }
        break;
      case NONE:
      default:
        break;
      }
      drawSymbol(ctx, m_symbol, m_centerX, m_centerY, m_buttonFontSize, colorSymbolActive);
    }
    else
    {
      switch(m_buttonStyle)
      {
      case CIRCLE:
        {
          drawCircle(m_centerX, m_centerY, m_buttonRadius, lineWidthInactive, colorButtonInactive);
        }
        break;
      case SOLID_CIRCLE:
        {
          drawSolidCircle(m_centerX, m_centerY, m_buttonRadius, lineWidthInactive, colorButtonInactive);
        }
        break;
      case SQUARE:
        {
          drawSquare(m_centerX, m_centerY, m_buttonRadius, lineWidthInactive, colorButtonInactive);
        }
        break;
      case SOLID_SQUARE:
        {
          drawSolidSquare(m_centerX, m_centerY, m_buttonRadius, lineWidthInactive, colorButtonInactive);
        }
        break;
      case NONE:
      default:
        break;
      }
      drawSymbol(ctx, m_symbol, m_centerX, m_centerY, m_buttonFontSize, colorSymbolInActive);
    }
  }

  /// Sets the button parameters, updates its status based on the cursor state and redraws the button.
  /// @param[in] centerX                The x coordinate of the buttons center.
  /// @param[in] centerY                The y coordinate of the buttons center.
  /// @param[in] radius                 The radius of the button in pixel.
  /// @param[in] fontsize               The radius of the button in pixel.
  /// @param[in] symbol                 The symbol of the button as a string.
  /// @param[in] buttonStyle            The style or form of the button, i.e. circular or squared.
  /// @param[in] cursorPositionX        The current cursor x position.
  /// @param[in] cursorPositionY        The current cursor y position.
  /// @param[in] mouseStateLeftClicking The clicking state of the left mouse button.
  /// @param[in] ctx                    Sim render context.
  /// @param[in] colorSymbolActive      The color of the buttons symbol, if the button is active.
  /// @param[in] colorSymbolInActive    The color of the buttons symbol, if the button is inactive.
  /// @param[in] colorButtonActive      The color of the buttons style, if the button is active.
  /// @param[in] colorButtonInactive    The color of the buttons style and symbol, if the button is inactive.
  /// @param[in] toolTip The tooltip to be displayed when hovering over the button.
  void setButtonAndRedraw(
    const float32            centerX,
    const float32            centerY,
    const float32            radius,
    const float32            fontsize,
    std::string              symbol,
    ButtonStyle              buttonStyle,
    int                      cursorPositionX,
    int                      cursorPositionY,
    bool                     mouseStateLeftClicking,
    const ISimRenderContext& ctx,
    const set::gl::RGBAColor colorSymbolActive,
    const set::gl::RGBAColor colorSymbolInActive,
    const set::gl::RGBAColor colorButtonActive,
    const set::gl::RGBAColor colorButtonInactive,
    std::string              toolTip = "")
  {
    setPosition(centerX, centerY);
    setButtonStyle(radius, fontsize, symbol, buttonStyle, toolTip);
    updateButtonStatus(cursorPositionX, cursorPositionY, mouseStateLeftClicking);
    redrawButton(ctx, colorSymbolActive, colorSymbolInActive, colorButtonActive, colorButtonInactive);
  }

private:
  bool        m_isActivated;      ///< Flag to indicate if the button is active (true) or not (false).
  bool        m_isHovering;       ///< Flag to indicate if the current mouse position is over the button or not.

  bool        m_isButtonStyleSet; ///< Flag to indicate if the button style has been set already.
  bool        m_isPositionSet;    ///< Flag to indicate if the button position has been set already.

  float32     m_centerX;          ///< X position of the button center in pixel.
  float32     m_centerY;          ///< Y position of the button center in pixel.

  std::string m_symbol;           ///< String symbol of the button.
  std::string m_toolTip;          ///< Multi-line string that is displayed if the mouse is hovering over the button.
  ButtonStyle m_buttonStyle;      ///< The form of the button (square, circle).
  float32     m_buttonRadius;     ///< The radius of the button.
  float32     m_buttonFontSize;   ///< The font size of the buttons symbol.

  int         m_idleCounter;      ///< A counter to skip excessive visualization calls/refreshs.
};

#endif // GEOMETRIC_TOOLS_INTFVER >= 1
#endif // GEOMETRIC_TOOLS_INTFVER
#endif // button_h__
