#ifndef INTERFACE_BASE_H
#define INTERFACE_BASE_H

typedef signed __int8 sint8, i8_t;
typedef unsigned __int8 uint8, ui8_t, ubit8_t;
typedef signed __int16 sint16, i16_t;
typedef unsigned __int16 uint16, ui16_t, ubit16_t;
typedef signed __int32 sint32, i32_t;
typedef unsigned __int32 uint32, ui32_t, ubit32_t;
typedef signed __int64 sint64, i64_t;
typedef unsigned __int64 uint64, ui64_t;
typedef float f32_t, float32;
typedef double f64_t, float64;
typedef unsigned char boolean, bool_t;

typedef unsigned __int16 times_t;
typedef f32_t fVariance_t;
typedef f32_t fConfidence_t;
typedef f32_t fVelocity_t;
typedef f32_t fUncertainty_t;
typedef f32_t fAngle_t;
typedef f32_t fTemperature_t;
typedef f32_t fRatio_t;
typedef f32_t fWeight_t;
typedef f32_t fCurve_t;
typedef f32_t fGradient_t;
typedef f32_t fQuality_t;
typedef f32_t fSpeed_t;
typedef f32_t fYawRate_t;
typedef f32_t fAcceleration_t;


// Conversion from 32-bit integer to tupple of major, minor, sub version tupple (triple)
#define CONV_I32VERSION_TO_TUPPLE(x)         (unsigned char)(((x) >> 16) & 0xFF), (unsigned char)(((x) >> 8) & 0xFF), (unsigned char)((x) & 0xFF)

#ifndef C_PI
#define C_PI  (3.14159265359F)
#endif

/*! Constant gravity G */
#ifndef C_GRAVITY
#define C_GRAVITY  (9.80665F)
#endif

/*! Constant conversion km/h <-> m/s */
#ifndef C_KMH_MS
#define C_KMH_MS      (3.6F)
#endif

/*! Constant speed of light in vacuum c [m/s] */
#ifndef C_V_LIGHT
#define C_V_LIGHT    (299792458.0F)
#endif

#ifndef DEG2RAD
#define DEG2RAD(deg)  ((deg)*(C_PI / 180.f))
#endif

#endif
