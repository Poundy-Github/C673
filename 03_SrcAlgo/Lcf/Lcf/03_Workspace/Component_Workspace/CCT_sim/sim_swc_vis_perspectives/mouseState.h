#ifndef mouseState_h__
#define mouseState_h__

struct MouseState
{
  struct ButtonState
  {
    bool down;
    bool clicked;
    bool doubleClicked;

    void setDown()       { down = true;  clicked = false; doubleClicked = false; }
    void setClicked()    { down = false; clicked = true;  doubleClicked = false; }
    void setDblClicked() { down = false; clicked = false; doubleClicked = true;  }

    void reset()  { down = false; clicked = false; doubleClicked = false;  }

    ButtonState() : down(false), clicked(false), doubleClicked(false) {}
  };

  int x;
  int y;
  int scroll;

  ButtonState left;
  ButtonState right;
  ButtonState middle;

  bool shift;
  bool control;

  MouseState() : x(0), y(0), scroll(0), shift(false), control(false) {}

  void setPos     (const int& _x, const int& _y) { x = _x; y = _y;   }
  void setWheel   (const int& _scroll)           { scroll = _scroll; } 

  void setShift   (const bool& isShift) { shift   = isShift; }
  void setControl (const bool& isCtrl ) { control = isCtrl;  }
};

#endif // mouseState_h__