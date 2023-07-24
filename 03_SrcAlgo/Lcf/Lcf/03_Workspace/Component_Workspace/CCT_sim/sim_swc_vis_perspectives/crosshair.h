#ifndef crosshair_h__
#define crosshair_h__

struct IGDVFont;

class Crosshair
{
public:
  Crosshair();

  /// Draws required information e.g. the current position with text information.
  /// @param[in] xMouse mouse x position in window coordinates.
  /// @param[in] yMouse mouse y position in window coordinates.
  void draw( const int xMouse, const int yMouse, IGDVFont& font );

  /// Change between drawing actions.
  void toggleAction ();

private:
  /// Shows a text showing relevant information measurement e.g. dx, dy and distance between the last and current crosshair position.
  /// The last crosshair position is set by a mouse click.
  /// @param[in] xWorld,yWorld Absolute difference in x and y between last and current mouse world coordinates.
  void drawCrosshairInfoMeas( const double xWorld, const double yWorld ) const;

  /// Shows a text showing the current location in mouse world coordinates.
  /// @param[in] xWorld,yWorld Current world coordinates.
  void drawCrosshairInfoNoMeas( const double xWorld, const double yWorld ) const;

  /// Shows text information.
  /// @param[in] xWorld,yWorld x and y coordinates of the text.
  /// @param[in] format        Text output format.
  /// @param[in] showMeas      True if (dx, dy, distance) measurements should be shown insted of current (x,y) mouse position.
  void drawCrosshairInfo( const double xWorld, const double yWorld, const char format[], const bool showMeas ) const;

  /// Draws a cross at specified position.
  /// @warning The modelview matrix remained changed.
  /// @param[in] xPos,yPos Cross location.
  void drawCrossAt( const double xPos, const double yPos ) const;

  /// Draws a dotted line at specified position.
  /// @param[in] xPos,yPos Position of dotted line.
  void drawRefMeasRect( const double xPos, const double yPos ) const;

  /// Draws a dotted circle at position (0,0) and a line from (0,0) to specified position.
  /// @param[in] xPos,yPos Specifies the end of the line and the radius of the circle.
  void drawRefMeasCirc( const double xPos, const double yPos ) const;

  /// Represents which information to show when drawing crosshair
  enum CrosshairAction
  {
    CH_ACTION_NONE = 0, ///< Do not show measurement information
    CH_ACTION_MEAS      ///< Show measuremnt information e.g. (dx, dy, sqrt(dx*dx + dy*dy))
  };

  CrosshairAction m_currentAction;            ///< Defines whether to show the simple crosshair or measurement information.
  int             m_viewport[4];              ///< Viewport of window.
  double          m_mv[16];                   ///< Modelview matrix.
  double          m_pv[16];                   ///< Projection matrix.
  double          m_xWorld, m_yWorld;         ///< Projected world cooridnates on the z-plane of the mouse.
  int             m_xVp, m_yVp;               ///< Mouse coordinates.
  double          m_prevXworld, m_prevYworld; ///< Previously projected world cooridnates on the z-plane of the mouse. It is used for drawing measurements.
  IGDVFont*       m_font;                     ///< Font used for visualization.
};

#endif // crosshair_h__
