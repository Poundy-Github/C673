#ifndef keyboardState_h__
#define keyboardState_h__

#include <map>

class KeyboardState
{
  typedef std::map<WPARAM, bool> key_map;

  key_map keys;
  int     keysDown;

public:
  KeyboardState() : keysDown(0) {}

  void setDown(const WPARAM& keyCode)
  {
    if ( isDown( keyCode ) == false )
    {
      keys[keyCode] = true;
      keysDown += 1;
    }
  }

  void setUp(const WPARAM& keyCode)
  {
    if ( isDown( keyCode ) )
    {
      keys[keyCode] = false;
      keysDown -= 1;
    }
  }

  bool someDown() const { return keysDown != 0; }

  bool isDown(const WPARAM& keyCode) const
  {
    const key_map::const_iterator it = keys.find(keyCode);

    if (it == keys.end())
    {
      return false;
    }
    else
    {
      return it->second;
    }
  }

  bool isOnlyDown(const WPARAM& keyCode) const
  {
    return isDown( keyCode ) && ( keysDown == 1 );
  }
};

#endif // keyboardState_h__
