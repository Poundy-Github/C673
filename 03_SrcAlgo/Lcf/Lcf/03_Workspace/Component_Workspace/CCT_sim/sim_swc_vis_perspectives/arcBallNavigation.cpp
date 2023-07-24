#include "stdafx.h"

#include "arcBallNavigation.h"

#include "gl/GL.h"
#include "gl/GLU.h"

#include <algorithm>

const double ArcBallNavigation::PI = 3.1415926535897932384626433832795;

void ArcBallNavigation::rotateGL()
{
  double pr[16];
  double mv[16];
  int    vp[4];

  // get scene setup
  glGetDoublev(GL_PROJECTION_MATRIX, pr);
  glGetDoublev(GL_MODELVIEW_MATRIX,  mv);
  glGetIntegerv(GL_VIEWPORT, vp);

  // get rotation point in view port coordinates
  double rotationPointVP[3];
  gluProject(
    m_rotationPoint[0], m_rotationPoint[1], m_rotationPoint[2],
    mv, pr, vp,
    &rotationPointVP[0], &rotationPointVP[1], &rotationPointVP[2]);

  // align rotation point to view port position
  // vp.x and vp.y are in gl coords starting at bottom of gl context and y pointing upwards
  // the roationPoint has to be converted in mouse coordinates starting at left/top of the window
  // with y pointing down
  rotationPointVP[0] = rotationPointVP[0] - vp[0];
  rotationPointVP[1] = vp[3] - (rotationPointVP[1] - vp[1]);

  // calculate rotation angle and rotation axis
  float axis[3];
  float angle;

  const int arcRadius = std::min( std::min(static_cast<int>(rotationPointVP[0]), static_cast<int>(rotationPointVP[1])), ARC_RADIUS);

  deformedBallQuarternion(
    m_navStartPoint[0], m_navStartPoint[1],
    m_navEndPoint[0],   m_navEndPoint[1],
    float(rotationPointVP[0]), float(rotationPointVP[1]),
    2*arcRadius, 2*arcRadius,
    axis[0], axis[1], axis[2], angle);

  // homogenize
  double axRot[4] = {axis[0], axis[1], axis[2], 0};
  // transform rot axis to object coordinates
  double axRotTransformed[4];
  mul4x4x1(m_lastModelViewMatrix, axRot, axRotTransformed);

  // nav guides
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0, vp[2] - 1, vp[3] - 1, 0, -1, 1);

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  {
    glLoadIdentity();
    // to window coordinates
    //glScaled(1, -1, 1);
    // to rotation point
    glTranslated(rotationPointVP[0], rotationPointVP[1], 0);

    // rotation center
    glLineWidth(3);
    glColor3ub(255, 255, 255);
    glBegin(GL_LINES);
    {
      glVertex2d(-20, 0);
      glVertex2d(+20, 0);

      glVertex2d(0, -20);
      glVertex2d(0, +20);
    }
    glEnd();

    // arc
    glLineWidth(1);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(3, 0xaaaa);

    glBegin(GL_LINE_LOOP);
    {
      for (int a = 0; a < 360; a += 10)
      {
        const double angle = a * PI / 180;
        glVertex2d(std::sin(angle) * arcRadius, std::cos(angle) * arcRadius);
      }
    }
    glEnd();
    glDisable(GL_LINE_STIPPLE);
  }
  glPopMatrix();

  glMatrixMode(GL_PROJECTION);
  glPopMatrix();

  glMatrixMode(GL_MODELVIEW);

  // do the rotation around the rotation point in ogl
  glTranslated(m_rotationPoint[0], m_rotationPoint[1], m_rotationPoint[2]);
  glRotated(angle * 180 / PI, axRotTransformed[0], axRotTransformed[1], axRotTransformed[2]);
  glTranslated(-m_rotationPoint[0], -m_rotationPoint[1], -m_rotationPoint[2]);
}