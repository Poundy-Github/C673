
template<typename T>
class GLType
{
public:
};

template<>
class GLType<unsigned char>
{
public:
  static const GLenum TYPE_ID = GL_UNSIGNED_BYTE;
};

template<>
class GLType<char>
{
public:
  static const GLenum TYPE_ID = GL_BYTE;
};

template<>
class GLType<unsigned short>
{
public:
  static const GLenum TYPE_ID = GL_UNSIGNED_SHORT;
};

template<>
class GLType<short>
{
public:
  static const GLenum TYPE_ID = GL_SHORT;
};

template<>
class GLType<unsigned int>
{
public:
  static const GLenum TYPE_ID = GL_UNSIGNED_INT;
};

template<>
class GLType<int>
{
public:
  static const GLenum TYPE_ID = GL_INT;
};

template<>
class GLType<float>
{
public:
  static const GLenum TYPE_ID = GL_FLOAT;
};

template<>
class GLType<double>
{
public:
  static const GLenum TYPE_ID = GL_DOUBLE;
};

