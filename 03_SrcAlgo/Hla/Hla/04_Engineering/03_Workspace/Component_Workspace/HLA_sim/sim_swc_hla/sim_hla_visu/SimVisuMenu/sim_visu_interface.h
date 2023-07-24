/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_visu_interface.h

  DESCRIPTION:            Type definitions across all visu modules

  CPU:                    Independent

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.2 $

  ---*/ /*---

**************************************************************************** */
#ifndef SIM_VISU_INTERFACE_H
#define SIM_VISU_INTERFACE_H

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

typedef struct
{
  int count;
  char character;
} t_KeyboardInfo;

typedef struct
{
  struct s_current
  {
    int x;
    int y;
    int wheel;
  } current;

  struct s_singleClickLeft
  {
    int count;
    int x;
    int y;
    int tmpX;
    int tmpY;
  } singleClickLeft;

  struct s_doubleClickLeft
  {
    int count;
    int x;
    int y;
  } doubleClickLeft;

  struct s_singleClickMiddle
  {
    int count;
    int x;
    int y;
  } singleClickMiddle;

  struct s_rect
  {
    enum e_state
    {
      STATE_INVALID,
      STATE_FIRST_POINT_SET,
      STATE_VALID
    } eState;

    int left;
    int right;
    int top;
    int bottom;

  } rect;

} t_MouseInfo;


// mouse wheel enum
typedef enum 
{
  eWheelUp,
  eWheelDown
}e_MouseWheel;

#endif /* SIM_VISU_INTERFACE_H */
