#ifndef IGMATH_H
#define IGMATH_H

// The ratio of a circle's circumference to its diameter. 
#define M_PI 3.14159265358979323846f

// Only single-precision float math is included

// Computes arc cosine (arccos(x)).
extern float acosf(float __x);
// Computes arc sine (arcsin(x)).
extern float asinf(float __x);
// Computes arc tangent, using signs to determine quadrants.
extern float atan2f(float __y, float __x);
// Computes remainder of the floating-point division operation.
extern float fmodf(float __x, float __y);
// Computes a number raised to the given power (x^y).
extern float powf(float __x,float __y);
// Computes square root of x.
extern float sqrtf(float __x);
// Computes arc tangent (arctan(x)).
extern float atanf(float __x);
// Computes smallest integer not less than the given value.
extern float ceilf(float __x);
// Computes cosine (cos(x)).
extern float cosf(float __x);
// Computes absolute value of a floating-point value (|x|).
extern float fabsf(float __x);
// Computes largest integer not greater than the given value.
extern float floorf(float __x);
// Computes sine (sin(x)).
extern float sinf(float __x);
// computes tangent (tan(x)).
extern float tanf(float __x);
// Computes efficiently a number times FLT_RADIX (2) raised to a power.
extern float scalbnf(float __x, int __n);

#endif /* IGMATH_H */