#ifndef arcBallNavigation_h__
#define arcBallNavigation_h__

#include <cmath>

class ArcBallNavigation
{
public:
  ArcBallNavigation()
  {
    m_lastModelViewMatrix[0] = 1;
    m_lastModelViewMatrix[1] = 0;
    m_lastModelViewMatrix[2] = 0;
    m_lastModelViewMatrix[3] = 0;

    m_lastModelViewMatrix[4] = 0;
    m_lastModelViewMatrix[5] = 1;
    m_lastModelViewMatrix[6] = 0;
    m_lastModelViewMatrix[7] = 0;

    m_lastModelViewMatrix[8]  = 0;
    m_lastModelViewMatrix[9]  = 0;
    m_lastModelViewMatrix[10] = 1;
    m_lastModelViewMatrix[11] = 0;

    m_lastModelViewMatrix[12] = 0;
    m_lastModelViewMatrix[13] = 0;
    m_lastModelViewMatrix[14] = 0;
    m_lastModelViewMatrix[15] = 1;

    m_rotationPoint[0] = 0;
    m_rotationPoint[1] = 0;
    m_rotationPoint[2] = 0;

    m_navStartPoint[0] = 0;
    m_navStartPoint[1] = 0;

    m_navEndPoint[0] = 0;
    m_navEndPoint[1] = 0;
  }

  void setRotationPoint3D (const double x, const double y, const double z)
  {
    m_rotationPoint[0] = x;
    m_rotationPoint[1] = y;
    m_rotationPoint[2] = z;
  }

  void setNavStartPoint2D (const int x, const int y)
  {
    m_navStartPoint[0] = x;
    m_navStartPoint[1] = y;
  }

  void setNavEndPoint2D   (const int x, const int y)
  {
    m_navEndPoint[0] = x;
    m_navEndPoint[1] = y;
  }

  void rotateGL();

  const double* lastModelMatrix() const { return m_lastModelViewMatrix; }
  double*       lastModelMatrix()       { return m_lastModelViewMatrix; }

  const double* rotationPoint() const { return m_rotationPoint; }
  const int*    navStartPoint() const { return m_navStartPoint; }
  const int*    navEndPoint()   const { return m_navEndPoint;   }

private:
  double m_lastModelViewMatrix[16];
  double m_rotationPoint[3];
  int    m_navStartPoint[2];
  int    m_navEndPoint[2];

  static const int    ARC_RADIUS = 200;
  static const double PI;

  static float projectOnBall(float x, float y)
  {
    // If you change the size value, change angle computation in deformedBallQuaternion().
    const float size       = 1.0f;
    const float size2      = size*size;
    const float size_limit = size2*0.5f;

    const float d = x*x + y*y;
    return d < size_limit ? std::sqrt(size2 - d) : size_limit / std::sqrt(d);
  }

  static void crossProduct (const float* a, const float* b, float* res)
  {
    res[0] = a[1]*b[2] - a[2]*b[1];
    res[1] = a[2]*b[0] - a[0]*b[2];
    res[2] = a[0]*b[1] - a[1]*b[0];
  }

  static float squaredNorm (const float* v)
  {
    return v[0]*v[0] + v[1]*v[1] + v[2]*v[2];
  }

  static void deformedBallQuarternion (
    const int x, const int y,
    const int prevX, const int prevY,
    const float cx, const float cy,
    const int width, const int height,
    float& axisX, float& axisY, float& axisZ,
    float& angle)
  {
    static const float ROTATION_SENSIVITY = 0.5f;
    // Points on the deformed ball
    float px = ROTATION_SENSIVITY * (prevX  - cx) / width;
    float py = ROTATION_SENSIVITY * (cy - prevY)  / height;
    float dx = ROTATION_SENSIVITY * (x - cx)      / width;
    float dy = ROTATION_SENSIVITY * (cy - y)      / height;

    const float p1[3] = {px, py, projectOnBall(px, py)};
    const float p2[3] = {dx, dy, projectOnBall(dx, dy)};

    // Approximation of rotation angle
    // Should be divided by the projectOnBall size, but it is 1.0
    float axis[3];
    crossProduct (p2, p1, axis);

    axisX = axis[0];
    axisY = axis[1];
    axisZ = axis[2];

    angle = 2.0f * std::asin(std::sqrt(squaredNorm(axis) / squaredNorm(p1) / squaredNorm(p2)));
  }

  static void mul4x4x1 (const double* mIn, const double* vIn, double* vOut)
  {
    for (size_t r = 0; r < 4; ++r)
    {
      vOut[r] = 0;
      const double* mInRow = mIn + r * 4;
      for (size_t c = 0; c < 4; ++c)
      {
        vOut[r] += mInRow[c] * vIn[c];
      }
    }
  }
};

#endif // arcBallNavigation_h__