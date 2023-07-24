#include "stdafx.h"

uint32 convert_old_turnoffreason_to_new_turnoffreason(uint32 turnoffreason_old)
{
  /* old          = Value =        new    ->  old & new   */
  /* ONC          =     1 =         ONC   ->      1       */
  /* PREC         =     2 =        PREC   ->      1       */
  /* LOW_SPEED    =     4 =   LOW_SPEED   ->      1       */
  /* BRIGHTNESS   =     8 =  BRIGHTNESS   ->      1       */
  /* CITY         =    16 =        CITY   ->      1       */
  /* FOG          =    32 =         FOG   ->      1       */
  /* HIGHWAY      =    64 =    BLOCKAGE   ->      0       */
  /* DELAY        =   128 =       DELAY   ->      1       */
  /* BLOCKAGE     =   256 =         ---   ->      0       */
  /* TUNNEL       =   512 =         ---   ->      0       */
  /* TRAFFICSTYLE =  1024 =         ---   ->      0       */

  /* -> 1011 1111b == 191u               */
  uint32 turnoffreason_new = turnoffreason_old & 191u;
  uint32 blockageOld = 256;
  uint32 blockageNew = 64;
  if((turnoffreason_old & blockageOld)  > 0)
  {
    turnoffreason_new |= blockageNew;
  }
  return turnoffreason_new;
}

uint32 convert_new_turnoffreason_to_old_turnoffreason(uint32 turnoffreason_new)
{
  /* old          = Value =        new    ->  old & new   */
  /* ONC          =     1 =         ONC   ->      1       */
  /* PREC         =     2 =        PREC   ->      1       */
  /* LOW_SPEED    =     4 =   LOW_SPEED   ->      1       */
  /* BRIGHTNESS   =     8 =  BRIGHTNESS   ->      1       */
  /* CITY         =    16 =        CITY   ->      1       */
  /* FOG          =    32 =         FOG   ->      1       */
  /* HIGHWAY      =    64 =    BLOCKAGE   ->      0       */
  /* DELAY        =   128 =       DELAY   ->      1       */
  /* BLOCKAGE     =   256 =         ---   ->      0       */
  /* TUNNEL       =   512 =         ---   ->      0       */
  /* TRAFFICSTYLE =  1024 =         ---   ->      0       */

  /* -> 1011 1111b == 191u               */
  uint32 turnoffreason_old = turnoffreason_old & 191u;
  uint32 blockageOld = 256;
  uint32 blockageNew = 64;
  if((turnoffreason_new & blockageNew)  > 0)
  {
    turnoffreason_old |= blockageOld;
  }
  return turnoffreason_old;
}

uint8 switch_last_learned(uint8 last_learned)
{
  return (last_learned == 1) ? 2 : 1;
}

uint8 switch_learning_state(uint8 learning_state)
{
  return (learning_state < 5) ? learning_state + 3 : learning_state - 3;
}